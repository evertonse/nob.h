#define CYE_IMPLEMENTATION
#include "cye.h"
#include "shared.h"

#include <time.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char* argv[]) {
    ZString file = __FILE__;
    ZString program = shift(argv, argc);

    File_Stats stats;

    file_stats(program, &stats);
    printf("program=%s; stats="file_stats_fmt, program, file_stats_fmt_arg(stats));

    if (argc > 0) {
        file = argv[1];
    } else {
        printf("Usage: %s <file_path>\n", argv[0]);
        printf("Defaulting to `%s`", file);
    }

    if (!file_stats(file, &stats)) {
        printf("Failed to get file stats for %s\n", argv[1]);
        return 1;
    }

    printf("size of File stats for %zu:\n", sizeof(File_Stats));
    printf("File stats for %s:\n", argv[1]);
    printf("Created: %s", ctime(&stats.created_at));
    printf("Accessed: %s", ctime(&stats.accessed_at));
    printf("Modified: %s", ctime(&stats.modified_at));
    printf("Size: %zu bytes\n", stats.size_bytes);

    return 0;
}
