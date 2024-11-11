// This is the code that is shared between nob.c and tests/*.c
#ifndef _SHARED_H_
#define _SHARED_H_

#define BUILD_FOLDER "build/"
#define TESTS_FOLDER "cye-tests/"
#define TOOLS_FOLDER "cye-tools/"

// Tests are allowed to build the tools they may need for their testing
// The tools are single C files residing in TOOLS_FOLDER
bool build_tool(Command *cmd, const char *tool_name) {
    const char *tool_src = path_create(TOOLS_FOLDER, tprintf("%s.c",tool_name));
    const char *tool_bin = path_create("%s%s", BUILD_FOLDER TOOLS_FOLDER, tool_name);
    cmd_append(cmd, "cc", "-Wall", "-Wextra", "-Wswitch-enum", "-I.", "-o", tool_bin, tool_src);

    if (!cmd_run_sync_and_reset(cmd)) {
        return false;
    }

    return true;
}

#endif // _SHARED_H_
