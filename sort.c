#ifndef CYE_SORT_H
#define CYE_SORT_H

#include <string.h> // for memcpy
#include <stddef.h> // for size_t

#define CYE_SWAP(T, a, b) do { \
    T tmp = (a);               \
    (a) = (b);                 \
    (b) = tmp;                 \
} while (0)

// Sort in reverse order
#define CYE_SORT_REVERSE(T, ptr, count, compare) \
    CYE_SORT(T, ptr, count, !(compare))

// Sort array maintaining stable order for equal elements
#define CYE_SORT(T, ptr, count, compare) do {                            \
    T *_arr = (ptr);                                                     \
    size_t _count = (count);                                             \
    for (size_t _i = 1; _i < _count; _i++) {                             \
        T _key = _arr[_i];                                               \
        size_t _j = _i;                                                  \
        while (_j > 0) {                                                 \
            T *_a = &_key;                                               \
            T *_b = &_arr[_j - 1];                                       \
            if (!(compare)) break;                                       \
            _arr[_j] = _arr[_j - 1];                                     \
            _j--;                                                        \
        }                                                                \
        _arr[_j] = _key;                                                 \
    }                                                                    \
} while (0)


#endif // CYE_SORT_H
void main(void) {
    // Sort integers
    int nums[] = {5, 2, 8, 1, 9, 3};
    CYE_SORT(int, nums, 6, _a > _b);  // ascending order
    // nums is now {1, 2, 3, 5, 8, 9}

    // Sort in descending order
    CYE_SORT(int, nums, 6, _a < _b);
    // nums is now {9, 8, 5, 3, 2, 1}

    // Sort strings (array of pointers)
    const char *strs[] = {"zebra", "apple", "orange", "banana"};
    CYE_SORT(const char*, strs, 4, strcmp(*_a, *_b) > 0);
    for (int idx = 0; idx < 4; idx += 1) {
        
    }
    // strs is now {"apple", "banana", "orange", "zebra"}

    // Sort custom struct
    typedef struct {
        int id;
        float value;
    } Item;

    Item items[] = {
        {1, 5.5f},
        {2, 3.3f},
        {3, 7.7f},
    };

    // Sort by value
    CYE_SORT(Item, items, 3, _a->value > _b->value);
    
    CYE_SORT(Item, items, 3, _a->id < _b->id);
    // Sort by id in descending order
}

