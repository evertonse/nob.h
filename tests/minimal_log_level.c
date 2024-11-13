#define CYE_IMPLEMENTATION
#include "cye.h"

void test_messages(void) {
    trace_log(LOG_ALL, "YOU SHOULD ALWAYS SEE THIS");
    trace_log(LOG_TRACE, "Trace Test Message");
    trace_log(LOG_INFO, "Info Test Message");
    trace_log(LOG_WARNING, "Warning Test Message");
    trace_log(LOG_ERROR, "Error Test Message");
    trace_log(LOG_NONE, "YOU SHOULD NEVER SEE THIS");
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
