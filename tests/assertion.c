#define CYE_IMPLEMENTATION
#include "cye.h"

void test_assertion(void) {
    cye_assert(3==3 && "True no problem");
    cye_assert_msg(4 == 5, "%s (%d)", "Nice formated Message", 420);

    // Terrible message but is static it won't compile,
    // pretty good cuz of that
    static_assert(true);
}

int main(void) {
    test_assertion();
    return 0;
}
