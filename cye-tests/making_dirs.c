#define CYE_IMPLEMENTATION
#include "cye.h"

int main(void) {
    bool result =  false;

    usz chk_point = cye_temp_save();
    result = mkdir("a");
    trace_log(LOG_INFO, "Current result: %s", result?"true":"false");

    result = mkdirs("./////1/2/3");
    trace_log(LOG_INFO, "Current result: %s", result?"true":"false");

    result = cye_mkdir_include_parents_from_tstr(strdup("////1/2/3/4/5/"));
    trace_log(LOG_INFO, "Current result: %s", result?"true":"false");

    if (chk_point == cye_temp_save()) {
        trace_log(LOG_INFO, "No temporary memory wasted, all good :)");
    } else {
        trace_log(LOG_ERROR, "Temporary memory has been WASTED");
    }
    return 0;
}
