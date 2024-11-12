
#define CYE_IMPLEMENTATION
#include "cye.h"
#include "cye_shared.h"

const char *test_names[] = {
    "minimal_log_level",
    "temporary_storage",
    "path",
//     "nob_sv_end_with",
//     "set_get_current_dir",
//     "cmd_redirect",
// #ifdef _WIN32
//     "win32_error",
// #endif //_WIN32
};

#define test_names_count count_of(test_names)

bool build_and_run_test(Command *cmd, const char *test_name) {
    const char *bin_path = path_create(BUILD_FOLDER, TESTS_FOLDER, test_name);
    const char *src_path = path_create(TESTS_FOLDER, tprintf("%s.c", test_name));

    trace_info("bin = %s" ,bin_path);
    trace_info("src = %s" ,src_path);

    cmd_append(cmd, "cc", "-Wall", "-Wextra", "-Wno-unused-parameter", "-Wswitch-enum", "-I.", "-o", bin_path, src_path);

    if (!cmd_run_sync_and_reset(cmd)) {
        return false;
    }
    cmd_append(cmd, bin_path);
    if (!cmd_run_sync_and_reset(cmd)) {
        return false;
    }

    trace_info("--- %s finished ---", bin_path);
    return true;
}

int main(int argc, const char **argv) {
    cye_rebuild_ourselves(argc, argv);

    Command cmd = {0};

    const char *program_name = shift(argv, argc);
    const char *command_name = "test";
    if (argc > 0) command_name = shift(argv, argc);

    if (!mkdir_if_not_exists(BUILD_FOLDER)) return 1;
    if (!mkdir_if_not_exists(BUILD_FOLDER TESTS_FOLDER)) return 1;
    if (!mkdir_if_not_exists(BUILD_FOLDER TOOLS_FOLDER)) return 1;

    if (0 == strcmp(command_name, "test")) {
        if (argc <= 0) {
            for (usize i = 0; i < test_names_count; ++i) {
                if (!build_and_run_test(&cmd, test_names[i])) return 1;
            }
            return 0;
        }

        while (argc > 0) {
            const char *test_name = shift(argv, argc);
            if (!build_and_run_test(&cmd, test_name)) return 1;
        }
        return 0;
    }

    if (strcmp(command_name, "list") == 0) {
        trace_info("Tests:");
        for (usize i = 0; i < test_names_count; ++i) {
            trace_info("    %s", test_names[i]);
        }
        trace_info("Use %s test <names...> to run individual tests", program_name);
        return 0;
    }

    trace_error("Unknown command %s", command_name);
    return 1;
}
