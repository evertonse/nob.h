#define CYE_IMPLEMENTATION
#include "cye.h"

void test_dynamic_string(void) {
    usz chk_point = temp_save();
    DString ds = {0};

    ds_printf(&ds, "%d workers are fighting the end of %dx%d shift\n", 123, 6, 1);
    ds_write_zero(&ds);
    trace_info("Passed: %s", ds.items);
    ds.count = 0;
    ds_printf(&ds,
        "Stop doing %s!\n"
        "%s were not supposed to %s.\n"
        "Years of %s yet NO REAL-WORLD USE FOUND for %s.\n"
        "\"Yes, PLEASE %s\" - Statements dreamed up by the utterly DERANGED\n"
        "Wanted to %s ? We had a tool for that: it was called \"%s\".\n"
        "Look at what %s have been demanding your RESPECT for all this time.\n"
        "They have played us for absolute fools\n",
        // ARGS //
        "Math",
        "Numbers", "be given names",
        "Counting", "higher dimensions",
        "Zero of something, infintesinal of that",
        "go higher anyway, just for the kicks", "GUESSING",
        "Mathematicians"
    );

    ds_write_zero(&ds);
    

    if (chk_point == temp_save()) {
        trace_log(LOG_OKAY, "Passed: %s", ds.items);
    } else {
        trace_error("Failed: %s", ds.items);
    }
}

int main(void) {
    test_dynamic_string();
    return 0;
}
