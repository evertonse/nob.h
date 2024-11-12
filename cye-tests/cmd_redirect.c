#define cye_IMPLEMENTATION
#include "nob.h"
#include "shared.h"

int main(void) {
    int result = 0;
    Command cmd = {0};
    File_Handle fhout = INVALID_FILE_HANDLE;
    DString sb = {0};

    if (!build_tool(&cmd, "echo")) return_defer(1);

    // WIN32 Poops here
    // const char *message = "Hello, World";
    const char *message = "Hello";
    const char *message_file_path = BUILD_FOLDER"echo_message.txt";

    fdout = fd_open_for_write(message_file_path);
    if (fdout == INVALID_FD) return_defer(1);

    cmd_append(&cmd, BUILD_FOLDER TOOLS_FOLDER "echo", message);
    Proc p = cmd_run_async_redirect_and_reset(&cmd, (Cmd_Redirect) {.fdout = &fdout});
    if (p == INVALID_PROC) return_defer(1);
    if (!process_wait(p)) return_defer(1);

    if (!read_entire_file(message_file_path, &sb)) return_defer(1);
    String_View actual_message = sb_to_sv(sb);
    if (!sv_eq(sv_trim(actual_message), sv_from_cstr(message))) {
        cye_log(ERROR, "Unexpected message");
        cye_log(ERROR, "Expected: %s", message);
        cye_log(ERROR, "Actual:   "SV_Fmt, SV_Arg(actual_message));
        return_defer(1);
    }

    cye_log(INFO, "OK");

defer:
    free(cmd.items);
    free(sb.items);
    if (fdout != INVALID_FD) fd_close(fdout);
    return result;
}
