#define CYE_IMPLEMENTATION
#define CYE_TEMP_CAPACITY 3
#include "cye.h"
#include "shared.h"

#define TEMP "temp_data.size = %zu, &temp_data.buffer[0] = %p, &temp_data.buffer[temp_data.size] = %p", temp_data.size, &temp_data.buffer[0], &temp_data.buffer[temp_data.size]

#define print_data(ptr)                                                \
cye_trace_info(                                                        \
     #ptr"=%p\ncye_temp_data={.buffer=%p, .size=%zu, .buffer+size=%p, .&buffer[size-1]=%p}\n"\
     "%d CYE_TEMP_CAPACITY\n",                                                                     \
     ptr, cye_temp_data.buffer, cye_temp_data.size, (cye_temp_data.buffer + cye_temp_data.size), &(cye_temp_data.buffer[cye_temp_data.size-1]), \
     CYE_TEMP_CAPACITY                                                                           \
);

void test_reallocation(void) {
    set_trace_level(LOG_TRACE);
    temp_reset();
    usz size  = 1;

    char* ptr = talloc(size);
    print_data(ptr);

    byte* leak_1_bytes = NULL;
    print_data(leak_1_bytes);

    leak_1_bytes = trealloc(leak_1_bytes, 1);
    print_data(leak_1_bytes);


    leak_1_bytes = trealloc(leak_1_bytes, 1);
    print_data(leak_1_bytes);

    assert((leak_1_bytes - cye_temp_data.buffer) == 1);
    assert((byte*)ptr + 1 == leak_1_bytes);

    leak_1_bytes = trealloc(leak_1_bytes, 2);
    print_data(leak_1_bytes);

    leak_1_bytes = trealloc(leak_1_bytes, 3); // Should give a WARNING and return null
    print_data(leak_1_bytes);
}

void test_reallocation_exceeds(void) {
    set_trace_level(LOG_TRACE);
    temp_reset();
    print_data(null);

    usz size  = 1;
    assert(size*3 == CYE_TEMP_CAPACITY);

    char* ptr = talloc(size);
    *ptr = 'y';
    print_data(ptr);

    char* leak = talloc(size);
    unused(leak);
    print_data(leak);

    {
        char* old = ptr;
        // If not the last pointer anymore, because of that we can only realloc 1 bytes instead of 2( instead of (1+1) -> (1+2) when realloced we get (1+1+1) == 3)
        ptr = trealloc(ptr, size);
        assert_true(old != ptr);
        assert_true(*old == *ptr && *ptr == 'y');
        *ptr = '2';
        assert_true(*old == 'y' && *ptr == '2');
    }

    print_data(ptr);
}


int main(void) {
    test_reallocation_exceeds();
    test_reallocation();
    return 0;
}
