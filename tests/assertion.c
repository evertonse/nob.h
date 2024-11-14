#define CYE_IMPLEMENTATION
#include "cye.h"

void test_assertion(void) {
    static_assert(false);
    cye_assert(3==3 && "True no problem");
    cye_assert_msg(4 == 5, "%s (%d)", "Nice formated Message", 420);
}

int main(void) {
    test_assertion();
    return 0;
}
