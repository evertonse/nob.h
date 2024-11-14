#define CYE_IMPLEMENTATION
#include "cye.h"

int main(void) {
    bool result = false;
    ZString path = NULL;
    bool exists = false;

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
    exit(1);

    return 0;
}
