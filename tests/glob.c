#define CYE_IMPLEMENTATION
#include "cye.h"
#include "shared.h"
#include <dirent.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>

static int str_cmp(const void *p1, const void *p2)
{
    char *const *s1_ptr = p1;
    char *const *s2_ptr = p2;
    return strcmp(*s1_ptr, *s2_ptr);
}

void test_tool(ZString pattern) {
    Command cmd = {0};
    build_tool(&cmd, "glob");
    cmd_append(&cmd, path_temp_create(BUILD_FOLDER, TOOLS_FOLDER, "glob"), pattern);
    Capture_Result cr = {0};
    cmd_run_sync_capture_and_reset(&cmd, &cr);
    trace_info("stdout: %s", cr.stdout.items);
}

void test_with_echo_pattern(ZString pattern, Cye_Path_DArray matches) {
#if !defined(_WIN32)

    Command cmd = {0};

    ZString dir  = ".";
    ZString flag = "-name";
    if (0 == strcmp(pattern, "")) {
        return;

    }
    // ALL these cases are too slow
    if (strchr(pattern, PATH_SEPARATOR_CHAR) != NULL) {
        return;
        flag = "-wholename";

        if (pattern[0] == PATH_SEPARATOR_CHAR) {
            dir = PATH_SEPARATOR;
            trace_info("Absolute path pattern, skipping.");
            return;
        }
    }
    
    cmd_append(&cmd, "find", dir, flag, pattern);

    Capture_Result cr = {0};
    // cmd_run_sync_and_reset(&cmd);
    cmd_run_sync_capture_and_reset(&cmd, &cr);
    ZString stdout_result = cr.stdout.items;
    ZString stderr_result = cr.stderr.items;
    String_Slice out = str_slice_make(stdout_result);
    String_Slice delim = str_slice_make("\n");

    String_Slice_DArray parts = str_slice_split_zstr(out, "\n");

    cye_sort(String_Slice, parts.items, parts.count,  memcmp(&a, &b, a.count));

    for (usz idx = 0; idx < parts.count; idx += 1) {
        printf("%zu%s capture="ss_fmt"\n", idx, zstr_ordinal(idx), ss_fmt_arg(parts.items[idx]));
    }
    da_free(parts);
    ds_free(cr.stdout);
    ds_free(cr.stderr);
#endif
}



int main(void) {
    Cye_Path_DArray matches = {0};

    const char *patterns[] = {
        "*.h",

        "*/*/*.c",
        "*/*/*.h",
        "*/*/*.md",

        "*/*/*/*.c",
        "*/*/*/*.h",
        "*/*/*/*.md",

        "*/*/*/*/*.c",
        "*/*/*/*/*.h",
        "*/*/*/*/*.md",

        "*/*/*/*/*/*.c",
        "*/*/*/*/*/*.h",
        "*/*/*/*/*/*.md",
        //------------//
        "",
        "/*", // TODO, make it work with absolute
        "/bin/*", // TODO, make it work with absolute
    };

    printf("---------------------------------------------\n\n");
    for (int idx = 0; idx < count_of(patterns); idx += 1) {
        trace_info("Before cye_temp_data.size = %zu bytes",  cye_temp_data.size);
        ZString pattern = patterns[idx];
        trace_info("pattern  %s ",  pattern);
        matches.count = 0;
        usz chk_point = temp_save();

        matches = cye_path_tglob(pattern);
        {
            qsort(matches.paths, matches.count, sizeof(char *), str_cmp);
            test_with_echo_pattern(pattern, matches);
            test_tool(pattern);
        }

        usz bytes = 0;
        for (usz i = 0; i < matches.count; i++) {
            printf("%2zu: %s\n", i, matches.paths[i]);
            bytes += (strlen(matches.paths[i]) + 1);
        }
        bytes += matches.capacity * size_of(matches.items[0]);

        trace_info("matches = "da_fmt, da_fmt_arg(matches));
        trace_info("cye_temp_data.size = %zu bytes", cye_temp_data.size);
        trace_info("Manual byte count  = %zu bytes", bytes);
        printf("---------------------------------------------\n\n");

        temp_rewind(chk_point);
    }

    return 0;
}


