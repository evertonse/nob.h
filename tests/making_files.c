#define CYE_IMPLEMENTATION
#include "cye.h"

int main(void) {
    bool result =  false;
    ZString path = NULL;
    usz chk_point = cye_temp_save();

    {
        path = path_temp_create("./build///", "tmp", "file.txt");
        trace_log(LOG_INFO, "Current path `%s`", path);

        result = write_entire_file(path, NULL, 0);
        trace_log(LOG_INFO, "Current write_entire_file result: %s", result?"true":"false");

        result = remove_file("path");
        trace_log(LOG_INFO, "Current remove_dir result: %s", result?"true":"false");
    }

    return 0;
}
