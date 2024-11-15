
#define CYE_IMPLEMENTATION
#include "cye.h"

typedef DArray(int) Int_DArray;


#define print_ints(da, msg)   \
    {\
        printf("%s\n", msg);\
        for (usz idx = 0; idx < (da).count; idx += 1) {\
            printf("da.items[%zu]=%d\n", idx, (da).items[idx]);\
        }\
    }

void test_dynamic_array(void) {
    Int_DArray da = {0};

    da_append(&da, 3);
    da_append(&da, 4);
    da_append(&da, 5);
    da_append(&da, 8);
    da_append(&da, 21);
    int arr[] = {32, 49, 56};

    da_append_buf(&da, arr, count_of(arr));
    print_ints(da, "Before");

    da_remove(&da, 0);
    print_ints(da, "After deleting index 0");

    da_remove(&da, da.count-1);
    print_ints(da, "After deleting index da.count-1");

    da_remove(&da, 3);
    print_ints(da, "After deleting index 3");

    da_remove(&da, (da.count-1)/2);
    print_ints(da, "After deleting index (da.count-1)/2");

    int lval = 4;
    da_remove_item(&da, lval);
    print_ints(da, tprintf("After deleting lvalue %d", lval));

    lval = 32;
    da_remove_item(&da, lval);
    print_ints(da, tprintf("After deleting lvalue %d", lval));
}

int main(void) {
    test_dynamic_array();
    return 0;
}
