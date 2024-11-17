#define CYE_IMPLEMENTATION
#include "cye.h"
#include "shared.h"

int test_cmd_capture(void) {
    Command cmd = {0};
    Cye_Capture_Result capture = {0};
    
    if (!build_tool(&cmd, "echo")) {
        return 1;
    }
    
    cmd_append(&cmd, "ls", "/");
    
    if (!cmd_run_sync_capture_and_reset(&cmd, &capture)) {
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
    Pipe pipe_out = CYE_INVALID_PIPE;
    Pipe pipe_err = CYE_INVALID_PIPE;
    DString ds = {0};

    if (!build_tool(&cmd, "echo")) {
        result_defer(1);
    }

    const char *message = "Hello";
    pipe_out = pipe_open();
    if (!cye_is_pipe_valid(pipe_out)) {
        result_defer(1);
    }

    pipe_err = pipe_open();
    if (!cye_is_pipe_valid(pipe_err)) {
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
    cye_pipe_close_handle(&pipe_out.write);
    cye_pipe_close_handle(&pipe_err.write);

    // Read from the stderr pipe
    char buffer[1024];
    size_t bytes_read;
    while (cye_pipe_read(pipe_err.read, buffer, sizeof(buffer) - 1, &bytes_read) && bytes_read > 0) {
        buffer[bytes_read] = '\0';
        ds_write(&ds, buffer);
    }

    if (ds.count > 0) {
        trace_info("Got this from std err: %s", ds.items);
        ds.count = 0;
    }

    // Read from the stdout pipe
    while (cye_pipe_read(pipe_out.read, buffer, sizeof(buffer) - 1, &bytes_read) && bytes_read > 0) {
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

defer:
    cmd_free(cmd);
    ds_free(ds);
    if (cye_is_pipe_valid(pipe_out)) {
        cye_pipe_close(pipe_out);
    }
    if (cye_is_pipe_valid(pipe_err)) {
        cye_pipe_close(pipe_err);
    }
    return result;
}

int main(int argc, char *argv[]) {
    unused(pipe_write);

    test_cmd_capture();
    test_pipe_tool();
}
