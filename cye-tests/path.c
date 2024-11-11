#define CYE_IMPLEMENTATION
#include "cye.h"

void test_path_create(void) {
    static ZString *test_names[] = {
        "/lol//",
        "nob_sv_end_with",
        "set_get_current_dir",
        "cmd_redirect",
    };
}

int main(void) {
    threshold_log_level = LOG_ALL;
    test_messages();
    
    threshold_log_level = LOG_TRACE;
    test_messages();
    
    threshold_log_level = LOG_DEBUG;
    test_messages();
    
    threshold_log_level = LOG_INFO;
    test_messages();
    
    threshold_log_level = LOG_WARNING;
    test_messages();
    
    threshold_log_level = LOG_ERROR;
    test_messages();
    
    threshold_log_level = LOG_FATAL;
    test_messages();
    
    threshold_log_level = LOG_NONE;
    test_messages();

    trace_log(LOG_FATAL, "It's fatal Danm We're fucked");
    return 0;
}
