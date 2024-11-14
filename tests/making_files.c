#define CYE_IMPLEMENTATION
#include "cye.h"

int main(void) {
    bool result = false;
    bool exists = false;

    ZString path = NULL;

    path = path_temp_create("build/lmao.txt");

    if (!file_exists(path)) {
        assert(make_dirs(path_dir_of(path)));
        trace_info("Touching `%s` because it doesn't exist yet", path);
        path_touch(path);
    } else {
        // Make the dirs required for it
        File_Stats stats = {0};
        trace_info("Touching `%s` anyways, even though it already exists", path);
        {
            file_stats(path, &stats);
            trace_info("Stats BEFORE" file_stats_fmt, file_stats_fmt_arg(stats));

            path_touch(path);

            file_stats(path, &stats);
            trace_info("Stats AFTER" file_stats_fmt, file_stats_fmt_arg(stats));
        }
    }

    {
        path = path_temp_create("./build///", "tmp", "file.txt");
        make_dirs(path_dir_of(path));
        trace_log(LOG_INFO, "Current path `%s`", path);

        result = write_entire_file(path, NULL, 0);
        trace_log(LOG_INFO, "Current write_entire_file result: %s", result ? "true" : "false");

        exists = file_exists(path);
        trace_log(LOG_INFO, "`%s` %s exists", path, exists ? "does" : "does NOT");

        result = remove_file(path);
        trace_log(LOG_INFO, "Current remove_file result: %s", result ? "true" : "false");

        exists = file_exists(path);
        trace_log(LOG_INFO, "`%s` %s exists", path, exists ? "does" : "does NOT");

        remove_dir(path_dir_of(path));
    }

    return 0;
}
