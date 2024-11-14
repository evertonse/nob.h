#define CYE_IMPLEMENTATION
#include "cye.h"
#include "shared.h"

typedef struct {
    int read_fd;
    int write_fd;
} Pipe_Handle;

#define INVALID_PIPE_HANDLE ((Pipe_Handle){-1, -1})

static Pipe_Handle pipe_open(void) {
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        return INVALID_PIPE_HANDLE;
    }
    return (Pipe_Handle){
        .read_fd = pipefd[0],
        .write_fd = pipefd[1]
    };
}

static void pipe_close(Pipe_Handle handle) {
    if (handle.read_fd != -1) close(handle.read_fd);
    if (handle.write_fd != -1) close(handle.write_fd);
}

static bool pipe_valid(Pipe_Handle handle) {
    return handle.read_fd != -1 && handle.write_fd != -1;
}

int main(void) {
    int result = 0;
    Command cmd = {0};
    Pipe_Handle pipe_out = INVALID_PIPE_HANDLE;
    Pipe_Handle pipe_err = INVALID_PIPE_HANDLE;
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

    cmd_append(&cmd, path_temp_create(BUILD_FOLDER, TOOLS_FOLDER, "echo"),
               message);

    // Create a Command_Redirect structure using pipe write ends
    Process p = cmd_run_async_redirect_and_reset(
        &cmd,
        (Command_Redirect){
            .out = &pipe_out.write_fd,
            .err = &pipe_err.write_fd
        }
    );

    if (p == INVALID_PROCESS) {
        result_defer(1);
    }

    // Close write ends after starting the process
    close(pipe_out.write_fd);
    pipe_out.write_fd = -1;
    close(pipe_err.write_fd);
    pipe_err.write_fd = -1;

    // Read from the stderr pipe
    char buffer[1024];
    ssize_t bytes_read;
    while ((bytes_read = read(pipe_err.read_fd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_read] = '\0';
        ds_write(&ds, buffer);
    }

    if (ds.count > 0) {
        trace_info("Got this from std err: %s", ds.items);
        ds.count = 0;
    }

    // Read from the stdout pipe
    while ((bytes_read = read(pipe_out.read_fd, buffer, sizeof(buffer) - 1)) > 0) {
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
