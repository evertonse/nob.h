// This is the code that is shared between nob.c and tests/*.c
#ifndef _SHARED_H_
#define _SHARED_H_

#define BUILD_FOLDER "build/"
#define TESTS_FOLDER "tests/"
#define TOOLS_FOLDER "tools/"

typedef DArray(ZString) String_DArray;

static String_DArray errors = {0};

#define assert_true(result)                                                     \
{                                                                               \
    if ((result)) {                                                             \
        trace_okay(" [SUCCESS] %s\n\t"file_fmt, #result, file_fmt_arg);         \
    } else {                                                                    \
        da_append(&errors, tprintf("%s\n\t"file_fmt, #result, file_fmt_arg));   \
        trace_error(" [FAIL] %s\n\t"file_fmt, #result, file_fmt_arg);           \
    }                                                                           \
}

#define assert_false(result) assert_true(!(result))

const char* ds_join(String_DArray da, ZString join);

#define error_count_log_and_reset() error_log_and_reset(__FUNCTION__)

void error_log_and_reset(ZString msg) {
    if (errors.count == 0) {
        trace_okay("NO ERRORS `%s`\n", msg);
    } else {
        trace_error("%d ERRORS `%s`\n%s", errors.count, msg, ds_join(errors, "\n\t"));
    }
    errors.count = 0;
}

const char* ds_join(String_DArray da, ZString join) {
    DString ds = {0};
    for (usz idx = 0; idx < da.count; idx += 1) {
        if (idx > 0) {
            ds_write(&ds, join);
        }
        ds_write(&ds, da.items[idx]);
    }
    ds_write_zero(&ds);
    return ds.items;
}

// Tests are allowed to build the tools they may need for their testing
// The tools are single C files residing in TOOLS_FOLDER
bool build_tool(Command *cmd, const char *tool_name) {
    const char *tool_src = path_create(TOOLS_FOLDER, tprintf("%s.c",tool_name));
    const char *tool_bin = path_create(BUILD_FOLDER, TOOLS_FOLDER, tool_name);
    cmd_append(cmd, "cc", "-Wall", "-Wextra", "-Wno-unused-parameter", "-Wswitch-enum", "-I.", "-o", tool_bin, tool_src);

    if (!cmd_run_sync_and_reset(cmd)) {
        return false;
    }

    return true;
}

#endif // _SHARED_H_
