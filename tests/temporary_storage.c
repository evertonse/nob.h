#define CYE_IMPLEMENTATION
#define CYE_TEMP_CAPACITY kilobytes(4)
#define CYE_DARRAY_INIT_CAP 256
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

#define print_ds(ds) cye_trace_info(ds_fmt, ds_fmt_arg((ds)))
void test_reallocation_with_dstring(void) {
    set_trace_level(LOG_TRACE);
    temp_reset();

    char* ptr = null;
    usz size = 20;
    ptr = talloc(size);
    DString ds = {.items = (char*)ptr, .count=0, .capacity=size};
    ds_write(&ds, "hello");
    print_data(ptr);
    print_ds(ds);
    byte* one_ptr = talloc(1);

    size *= 2; // new size
    char* old_ptr = (char*)ptr;
    ptr = trealloc(ptr, size);

    assert_true(ptr != old_ptr);

    {
        *one_ptr = 0;
        *old_ptr = 'k';
        assert_true(0 == strcmp("kello",  old_ptr));
        assert_false(0 == strcmp("hello", old_ptr));
    }

    assert_true(0 == strcmp("hello", ptr));
    print_data(ptr);
    print_ds(ds);

}

void test_temporary_storage(void) {
    temp_reset();
    context = temp_context();
    trace_info("temp_data.size=%zu", temp_data.size);

    int* a = context.alloc(size_of(int));
    trace_info("temp_data.size=%zu", temp_data.size);

    if (temp_data.size == size_of(int)) {
        trace_info("Passed: " TEMP);
    } else {
        trace_info("Failed: " TEMP);
    }

    // Temporary Realloc uses the same ptr if it can prove it was the last pointer
    // allocated, and in this case it is
    int* b = context.realloc(a, 2*size_of(int));
    trace_info("temp_data.size=%zu", temp_data.size);
    if (temp_data.size == 2*size_of(int)) {
        trace_info("Passed: " TEMP);
    } else {
        trace_info("Failed: " TEMP);
    }
    assert(a == b);

    usz checkpoint = temp_save();
    {
        // DArray(int) da = {0};
        struct {
            int* items;
            usz count;
            usz capacity;
        } da = {0};

        da_append(&da, 6);
        da_append(&da, 7);
        da_append(&da, 8);
        trace_info("da.capacity + 2*size_of(int))=%zu; temp_data.size=%zu", da.capacity + 2*size_of(int), temp_data.size);
        // assert(temp_data.size == da.capacity + 2*size_of(int)); // Because of good case of realloc

        for (usz idx = 0; idx < da.count; idx += 1) {
            trace_info("numbers %zuth is da.items[idx]=%d", idx,  da.items[idx]);
        }
    }
    temp_rewind(checkpoint);

    // Because of good case of realloc and rewind
    assert(temp_data.size == 2*size_of(int)); 

    if (temp_data.size == 2*size_of(int)) {
        trace_info("Passed: " TEMP);
    } else {
        trace_info("Failed: " TEMP);
    }
}

int main(void) {
    test_reallocation_with_dstring();
    test_temporary_storage();
    return 0;
}
