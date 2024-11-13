#define CYE_IMPLEMENTATION
#include "cye.h"

#define TEMP "temp_data.size = %zu, &temp_data.buffer[0] = %p, &temp_data.buffer[temp_data.size] = %p", temp_data.size, &temp_data.buffer[0], &temp_data.buffer[temp_data.size]

void test_temporary_storage(void) {
    context = temp_context();

    int* a = context.alloc(size_of(int));

    if (temp_data.size == size_of(int)) {
        trace_info("Passed: " TEMP);
    } else {
        trace_info("Failed: " TEMP);
    }

    // Reloc on temp is the same as alloc so we lose the first
    // pointer `a` and all that is expected from relloc goes for temporary
    // realloc, can't use `a` anymore
    int* b = context.realloc(a, 2*size_of(int));
    if (temp_data.size == 3*size_of(int)) {
        trace_info("Passed: " TEMP);
    } else {
        trace_info("Failed: " TEMP);
    }

    assert(a != b);

    usz checkpoint = temp_save();
    // DArray(int) da = {0};
    struct {
        int* items;
        usz count;
        usz capacity;
    } da = {0};
    da_append(&da, 5);
    da_append(&da, 5);
    da_append(&da, 5);
    for (usz idx = 0; idx < da.count; idx += 1) {
        trace_info("numbers %zuth is da.items[idx]=%d", idx,  da.items[idx]);
    }

    temp_rewind(checkpoint);
    assert(temp_data.size == 3*size_of(int));

    if (temp_data.size == 3*size_of(int)) {
        trace_info("Passed: " TEMP);
    } else {
        trace_info("Failed: " TEMP);
    }
}

int main(void) {
    test_temporary_storage();
    return 0;
}
