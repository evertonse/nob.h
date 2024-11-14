#define CYE_IMPLEMENTATION
#include "cye.h"
#include "shared.h"

#ifdef _WIN32
#include <windows.h>
typedef HANDLE Pipe_Handle;
#define INVALID_PIPE_HANDLE INVALID_HANDLE_VALUE
#else
typedef int Pipe_Handle;
#define INVALID_PIPE_HANDLE (-1)
#endif

typedef struct {
    Pipe_Handle read;
    Pipe_Handle write;
} Pipe;

#ifdef _WIN32
#define INVALID_PIPE ((Pipe){INVALID_HANDLE_VALUE, INVALID_HANDLE_VALUE})
#else
#define INVALID_PIPE ((Pipe){-1, -1})
#endif

static Pipe pipe_open(void) {
#ifdef _WIN32
    SECURITY_ATTRIBUTES sa = {
        .nLength = sizeof(SECURITY_ATTRIBUTES),
        .bInheritHandle = TRUE,
        .lpSecurityDescriptor = NULL
    };
    
    HANDLE read_handle, write_handle;
    if (!CreatePipe(&read_handle, &write_handle, &sa, 0)) {
        return INVALID_PIPE;
    }
    return (Pipe){
        .read = read_handle,
        .write = write_handle
    };
#else
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        return INVALID_PIPE;
    }
    return (Pipe){
        .read = pipefd[0],
        .write = pipefd[1]
    };
#endif
}

static void pipe_close(Pipe handle) {
#ifdef _WIN32
    if (handle.read != INVALID_PIPE_HANDLE) CloseHandle(handle.read);
    if (handle.write != INVALID_PIPE_HANDLE) CloseHandle(handle.write);
#else
    if (handle.read != INVALID_PIPE_HANDLE) close(handle.read);
    if (handle.write != INVALID_PIPE_HANDLE) close(handle.write);
#endif
}

static bool pipe_valid(Pipe handle) {
    return handle.read != INVALID_PIPE_HANDLE &&
           handle.write != INVALID_PIPE_HANDLE;
}

static bool pipe_read(Pipe_Handle pipe, char* buffer, size_t buffer_size, size_t* bytes_read) {
#ifdef _WIN32
    DWORD bytes_read_win;
    if (!ReadFile(pipe, buffer, (DWORD)buffer_size, &bytes_read_win, NULL)) {
        *bytes_read = 0;
        return false;
    }
    *bytes_read = bytes_read_win;
    return true;
#else
    ssize_t result = read(pipe, buffer, buffer_size);
    if (result < 0) {
        *bytes_read = 0;
        return false;
    }
    *bytes_read = (size_t)result;
    return true;
#endif
}

static bool pipe_write(Pipe_Handle pipe, const char* buffer, size_t buffer_size, size_t* bytes_written) {
#ifdef _WIN32
    DWORD bytes_written_win;
    if (!WriteFile(pipe, buffer, (DWORD)buffer_size, &bytes_written_win, NULL)) {
        *bytes_written = 0;
        return false;
    }
    *bytes_written = bytes_written_win;
    return true;
#else
    ssize_t result = write(pipe, buffer, buffer_size);
    if (result < 0) {
        *bytes_written = 0;
        return false;
    }
    *bytes_written = (size_t)result;
    return true;
#endif
}

static void pipe_close_handle(Pipe_Handle* pipe) {
    if (*pipe == INVALID_PIPE_HANDLE) return;
#ifdef _WIN32
    CloseHandle(*pipe);
#else
    close(*pipe);
#endif
    *pipe = INVALID_PIPE_HANDLE;
}

typedef struct {
    DString stdout;
    DString stderr;
} Command_Capture_Result;

// Run a command synchronously and capture its stdout and stderr output
// Returns true on success, false on failure
static bool cmd_run_sync_capture(Command* cmd, Command_Capture_Result* result) {
    bool success = false;
    Pipe pipe_out = INVALID_PIPE;
    Pipe pipe_err = INVALID_PIPE;
    
    // Create pipes for stdout and stderr
    pipe_out = pipe_open();
    if (!pipe_valid(pipe_out)) {
        goto cleanup;
    }
    
    pipe_err = pipe_open();
    if (!pipe_valid(pipe_err)) {
        goto cleanup;
    }
    
    // Run the command with redirected output
    Process p = cmd_run_async_redirect_and_reset(
        cmd,
        (Command_Redirect){
            .out = &pipe_out.write,
            .err = &pipe_err.write
        }
    );
    
    if (p == INVALID_PROCESS) {
        goto cleanup;
    }
    
    // Close write ends after starting the process
    pipe_close_handle(&pipe_out.write);
    pipe_close_handle(&pipe_err.write);
    
    // Read from both pipes
    char buffer[1024];
    size_t bytes_read;
    
    // Read from stderr
    while (pipe_read(pipe_err.read, buffer, sizeof(buffer) - 1, &bytes_read) && bytes_read > 0) {
        ds_write_buf(&result->stderr, buffer, bytes_read);
    }
    ds_write_zero(&result->stderr);
    
    // Read from stdout
    while (pipe_read(pipe_out.read, buffer, sizeof(buffer) - 1, &bytes_read) && bytes_read > 0) {
        ds_write_buf(&result->stdout, buffer, bytes_read);
    }
    ds_write_zero(&result->stdout);
    
    // Wait for process completion
    success = process_wait(p);
    
cleanup:
    if (pipe_valid(pipe_out)) {
        pipe_close(pipe_out);
    }
    if (pipe_valid(pipe_err)) {
        pipe_close(pipe_err);
    }
    
    return success;
}

int test_cmd_capture(void) {
    Command cmd = {0};
    Command_Capture_Result capture = {0};
    
    if (!build_tool(&cmd, "echo")) {
        return 1;
    }
    
    cmd_append(&cmd, "ls", ".");
    
    if (!cmd_run_sync_capture(&cmd, &capture)) {
        trace_error("Failed to run command");
        goto cleanup;
    }
    
    trace_info("stdout: %.*s", (int)capture.stdout.count, capture.stdout.items);
    
    if (capture.stderr.count > 0) {
        trace_info("stderr: %.*s", (int)capture.stderr.count, capture.stderr.items);
    }
    
cleanup:
    cmd_free(cmd);
    ds_free(capture.stdout);
    ds_free(capture.stderr);
    return 0;
}


int test_pipe_tool(void) {
    int result = 0;
    Command cmd = {0};
    Pipe pipe_out = INVALID_PIPE;
    Pipe pipe_err = INVALID_PIPE;
    DString ds = {0};

    if (!build_tool(&cmd, "echo")) {
        result_defer(1);
    }

    const char *message = "Hello";
    pipe_out = pipe_open();
    if (!pipe_valid(pipe_out)) {
        result_defer(1);
    }

    pipe_err = pipe_open();
    if (!pipe_valid(pipe_err)) {
        result_defer(1);
    }

    cmd_append(&cmd, path_temp_create(BUILD_FOLDER, TOOLS_FOLDER, "echo"), message);

    // Create a Command_Redirect structure using pipe write handles
    Process p = cmd_run_async_redirect_and_reset(
        &cmd,
        (Command_Redirect){
            .out = &pipe_out.write,
            .err = &pipe_err.write
        }
    );

    if (p == INVALID_PROCESS) {
        result_defer(1);
    }

    // Close write ends after starting the process
    pipe_close_handle(&pipe_out.write);
    pipe_close_handle(&pipe_err.write);

    // Read from the stderr pipe
    char buffer[1024];
    size_t bytes_read;
    while (pipe_read(pipe_err.read, buffer, sizeof(buffer) - 1, &bytes_read) && bytes_read > 0) {
        buffer[bytes_read] = '\0';
        ds_write(&ds, buffer);
    }

    if (ds.count > 0) {
        trace_info("Got this from std err: %s", ds.items);
        ds.count = 0;
    }

    // Read from the stdout pipe
    while (pipe_read(pipe_out.read, buffer, sizeof(buffer) - 1, &bytes_read) && bytes_read > 0) {
        buffer[bytes_read] = '\0';
        ds_write(&ds, buffer);
    }

    if (!process_wait(p)) {
        result_defer(1);
    }

    String_Slice actual_message = str_slice_make_len(ds.items, ds.count);
    if (!str_slice_equals(str_slice_trim(actual_message), str_slice_make(message))) {
        trace_error("Unexpected message");
        trace_error("Expected: %s", message);
        trace_error("Actual:   " ss_fmt, ss_fmt_arg(actual_message));
        result_defer(1);
    }

    trace_info("OK");
    exit(1);

defer:
    cmd_free(cmd);
    ds_free(ds);
    if (pipe_valid(pipe_out)) {
        pipe_close(pipe_out);
    }
    if (pipe_valid(pipe_err)) {
        pipe_close(pipe_err);
    }
    return result;
}

int main(int argc, char *argv[]) {
    test_cmd_capture();
    test_pipe_tool();
    exit(1);
}
