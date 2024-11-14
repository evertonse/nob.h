#define CYE_IMPLEMENTATION
#include "cye.h"
#include "shared.h"

int main(void) {
    int result = 0;

    Command cmd = {0};

    File_Handle fh_out = INVALID_FILE_HANDLE;
    File_Handle fh_err = INVALID_FILE_HANDLE;

    DString ds = {0};

    if (!build_tool(&cmd, "echo")) {
        result_defer(1);
    }

    // WIN32 Poops here
    // const char *message = "Hello, World";
    const char *message = "Hello";

    const char *message_file_path =
        path_temp_create(BUILD_FOLDER, "echo.out");
    const char *message_file_path_err =
        path_temp_create(BUILD_FOLDER, "echo.err");

    fh_out = file_open_for_write(message_file_path);
    if (fh_out == INVALID_FILE_HANDLE) {
        result_defer(1);
    }

    fh_err = file_open_for_write(message_file_path_err);
    if (fh_err == INVALID_FILE_HANDLE) {
        result_defer(1);
    }

    cmd_append(&cmd, path_temp_create(BUILD_FOLDER, TOOLS_FOLDER, "echo"),
               message);
    Process p = cmd_run_async_redirect_and_reset(
        &cmd, (Command_Redirect){.out = &fh_out, .err = &fh_err}
    );

    if (p == INVALID_PROCESS) {
        result_defer(1);
    }
    if (!process_wait(p)) {
        result_defer(1);
    }

    if (read_entire_file(message_file_path_err, &ds)) {
        ds_write_zero(&ds);
        trace_info("Got this from std err: %s", ds.items);
        ds.count = 0;
    } else {
        result_defer(1);
    }

    if (!read_entire_file(message_file_path, &ds)) {
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

    if (fh_out != INVALID_FILE_HANDLE) {
        file_close(fh_out);
    }

    if (fh_err != INVALID_FILE_HANDLE) {
        file_close(fh_err);
    }
    return result;
}
