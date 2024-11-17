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


int main(void) {
    Cye_Path_DArray matches = {0};

    const char *patterns[] = {
        "",

        "/*", // TODO, make it work with absolute

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
    };

    printf("---------------------------------------------\n\n");
    for (int idx = 0; idx < count_of(patterns); idx += 1) {
        trace_info("Before cye_temp_data.size = %zu bytes",  cye_temp_data.size);
        ZString pattern = patterns[idx];
        trace_info("pattern  %s ",  pattern);
        matches.count = 0;
        usz chk_point = temp_save();

        matches = cye_path_tglob(pattern);
        qsort(matches.paths, matches.count, sizeof(char *), str_cmp);
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

    exit(1);
    return 0;
}


