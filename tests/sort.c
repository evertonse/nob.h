#define CYE_IMPLEMENTATION
#include "cye.h"

#include <string.h> // for memcpy
#include <stddef.h> // for size_t



#define print_items(msg)   \
    {\
        printf(msg"\n");\
        for (int idx = 0; idx < count_of(items); idx += 1) {\
            printf("items[idx]={id=%d, value=%f}\n", items[idx].id, items[idx].value);\
        }\
    }

#define print_nums(msg)   \
    {\
        printf(msg"\n");\
        for (int idx = 0; idx < count_of(nums); idx += 1) {\
            printf("nums[idx]=%d\n", nums[idx]);\
        }\
    }

#define print_strs(msg)   \
    {\
        printf(msg"\n");\
        for (int idx = 0; idx < count_of(strs); idx += 1) {\
            printf("strs[idx]=%s\n", strs[idx]);\
        }\
    }

int main(void) {
    // Sort integers
    int nums[] = {5, 2, 8, 1, 9, 3};


    print_nums("Before");
    sort(int, nums, count_of(nums), a > b);  // ascending order
    print_nums("After");
    // nums is now {1, 2, 3, 5, 8, 9}

    // Sort in descending order
    sort_reverse(int, nums, 6, a < b);
    print_nums("After");
    // nums is now {9, 8, 5, 3, 2, 1}

    // Sort strings (array of pointers)
    const char *strs[] = {"1", "22", "333", "4444"};
    print_strs("Before");

    cye_sort_reverse(const char*, strs, count_of(strs), strlen(a) > strlen(b));
    print_strs("After");

    // strs is now {"apple", "banana", "orange", "zebra"}

    // Sort custom struct
    typedef struct {
        int id;
        float value;
    } Item;

    Item items[] = {
        {9, 5.5f},
        {2, 3.3f},
        {3, 7.7f},
    };
    print_items("Before");

    cye_sort(Item, items, count_of(items), a.value < b.value);
    print_items("After");
    
    cye_sort(Item, items, count_of(items), a.id < b.id);
    print_items("After");

    // Sort by id in descending order
    return 0;
}

