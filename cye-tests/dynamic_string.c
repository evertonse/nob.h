#define CYE_IMPLEMENTATION
#include "cye.h"

void test_dynamic_string(void) {
    usz chk_point = temp_save();
    DString ds = {0};

    ds_printf(&ds, "%d workers are fighting the end of %dx%d shift\n", 123, 6, 1);
    ds_printf(&ds,
        "Stop doing %s!\n"
        "%s were not supposed to %s."
        "Years of %s yet NO REAL-WORLD USE FOUND for %s."
        "\"Yes, PLEASE %s\" - Statements dreamed up by the utterly DERANGED",
        "Wanted to %s ? We had a tool for that: it was called \"%s\".",
        "Look at what %s have been demanding your RESPECT for all this time.",
        "They have played us for absolute fools",
        // ARGS //
        "Math","Numbers", "be given names"
        "Counting", "higher dimensions"
        "Zero of something, infintesinal of that"
        "go higher anyway, just for the kicks", "GUESSING"
        "Mathematicians"
    );

    ds_write_zero(&ds);
    

    if (chk_point == temp_save()) {
        trace_info("Passed: %s", ds.items);
    } else {
        trace_info("Failed: %s", ds.items);
    }
}

int main(void) {
    test_dynamic_string();
    return 0;
}
