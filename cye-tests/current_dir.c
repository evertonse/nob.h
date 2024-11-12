#define CYE_IMPLEMENTATION
#include "cye.h"

int main(void) {
    const char *test_current_dir = "/";
    const char *current_dir = path_temp_cwd();
    if (current_dir == null) return 1;
    trace_log(LOG_INFO, "Current Dir: %s", current_dir);

    trace_log(LOG_INFO, "Setting Current Dir to %s", test_current_dir);
    if (!path_set_cwd(test_current_dir)) return 1;
    
    current_dir = path_temp_cwd();
    if (current_dir == null) return 1;
    trace_log(LOG_FATAL, "Current Dir: %s", path_temp_cwd());
    return 0;
}
