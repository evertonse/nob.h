#define CYE_IMPLEMENTATION
#include "cye.h"

typedef Slice(int*) Int_Slice;

static inline void int_slice_print(Int_Slice slice) {
    static DString ds = {0};
    ds.count = 0;
    ds_printf(&ds, "{.count=%zu", slice.count);
    if (ds.count > 0) {
        ds_write(&ds, ",");
    }

    for (usz idx = 0; idx < slice.count; idx += 1) {
        if (idx == slice.count - 1) {
            ds_printf(&ds, " %d", slice.data[idx]);
        } else {
            ds_printf(&ds, " %d,", slice.data[idx]);
        }
        // printf("%d\n", slice.data[idx]);
    }
    ds_write(&ds, " }");
    ds_write_zero(&ds);
    printf("%s\n", ds.items);
}


void example(void) {
    // Generic slice examples
    int nums[] = {1, 2, 3, 4, 5};
    Int_Slice slice = slice_from_arr(nums);
    int_slice_print(slice);


    // Get subslice [1,3)
    Int_Slice sub = slice_range(slice.data, 1, 3);  // {2, 3}
    int_slice_print(sub);

    // Get first 2 elements
    Int_Slice prefix = slice_prefix(slice.data, 2);  // {1, 2}
    int_slice_print(prefix);

    // Check if contains element
    bool has_three = slice_contains(slice, 3);  // true
    printf("slice has_three=%s\n", has_three ? "true" : "false");

    has_three = slice_contains(prefix, 3);  // false
    printf("prefix has_three=%s\n", has_three ? "true" : "false");

    int index = slice_index_of(prefix, 2);  // 1
    printf("prefix index=%d\n", index);

    index = slice_index_of(slice, 2);  // 1
    printf("slice index=%d\n", index);


    index = slice_index_of(sub, 2);  // 0
    printf("slice index=%d\n", index);

    // String slice examples
    const char *str = "  Hello, World!  ";
    String_Slice ss = str_slice_make(str);

    index = slice_index_of(ss, 'o');  // 6
    printf("ss index=%d\n", index);
    printf(ss_fmt"\n", ss_fmt_arg(ss));


    // Trim whitespace
    String_Slice trimmed = str_slice_trim(ss);  // "Hello, World!"
    printf("trimmed=\""ss_fmt"\"\n", ss_fmt_arg(trimmed));

    // Split at first comma
    String_Slice before, after;
    str_slice_split_first(trimmed, ',', &before, &after);
    // before: "Hello"
    // after: " World!"
    // Check if starts with
    String_Slice hello = str_slice_make("Hello");
    bool starts = str_slice_starts_with(trimmed, hello);  // true
    if (starts) {
        trace_okay("trimed="ss_fmt "does starts with ="ss_fmt, ss_fmt_arg(trimmed), ss_fmt_arg(hello));
    } else {
        trace_error("trimed="ss_fmt "does NOT starts with ="ss_fmt, ss_fmt_arg(trimmed), ss_fmt_arg(hello));
    }

    // Compare string slices
    
    char arr[] = {'h', 'e', 'l', 'l', 'o'};
    String_Slice a = slice_from_arr(arr);
    String_Slice b = str_slice_make("hello");
    bool equal = str_slice_equal(a, b);  // true
    if (equal) {
        trace_okay("a="ss_fmt "does equals b="ss_fmt, ss_fmt_arg(a), ss_fmt_arg(b));
    } else {
        trace_error("a="ss_fmt "does NOT equals b="ss_fmt, ss_fmt_arg(a), ss_fmt_arg(b));
    }
}

#include <assert.h>
#include <string.h>
#include <stdio.h>



typedef DArray(String_Slice) String_Slice_Array;

// New function: Split string by delimiter string, returns array of slices
static String_Slice_Array str_slice_split2(String_Slice s, String_Slice delim) {
    String_Slice_Array result = {0};
    usz capacity = 8;
    result.items = malloc(sizeof(String_Slice) * capacity);

    char *start   = (char*)s.data;
    char *end     = (char*)s.data + s.count;
    char *current = (char*)s.data;

    while (current <= end - delim.count) {
        if (memcmp(current, delim.data, delim.count) == 0) {
            if (result.count + 1 >= capacity) {
                capacity *= 2;
                result.items = realloc(result.items, sizeof(String_Slice) * capacity);
            }
            result.items[result.count++] = str_slice_make_len(start, current - start);
            current += delim.count;
            start = current;
        } else {
            current++;
        }
    }

    // Add the last part
    if (start < end) {
        if (result.count + 1 >= capacity) {
            capacity *= 2;
            // result.items = context.realloc(result.items, sizeof(String_Slice) * capacity);
            result.items = realloc(result.items, sizeof(String_Slice) * capacity);
        }
        result.items[result.count++] = str_slice_make_len(start, end - start);
    }

    return result;
}

void print_slice(String_Slice s) {
    printf("\"");
    for (usz i = 0; i < s.count; i++) {
        printf("%c", s.data[i]);
    }
    printf("\" (len=%zu)\n", s.count);
}

void run_tests(void) {
    // Test trim
    {
        char test[] = "  hello world  ";
        String_Slice s = slice_make(test, strlen(test));
        String_Slice trimmed = str_slice_trim(s);
        assert(trimmed.count == 11);
        assert(memcmp(trimmed.data, "hello world", 11) == 0);
        trace_log(LOG_OKAY, "Trim test passed");
    }

    // Test str_slice_to_zstr
    {
        char test[] = "hello world";
        String_Slice s = slice_make(test, strlen(test));
        char buf[20];
        str_slice_to_zstr(s, buf, sizeof(buf));
        assert(strcmp(buf, "hello world") == 0);
        trace_log(LOG_OKAY, "To C string test passed");
    }

    // Test equal
    {
        char test1[] = "hello";
        char test2[] = "hello";
        char test3[] = "world";
        String_Slice s1 = slice_make(test1, strlen(test1));
        String_Slice s2 = slice_make(test2, strlen(test2));
        String_Slice s3 = slice_make(test3, strlen(test3));
        assert(str_slice_equal(s1, s2));
        assert(!str_slice_equal(s1, s3));
        trace_log(LOG_OKAY, "Equal test passed");
    }

    // Test contains
    {
        char haystack[] = "hello world";
        char needle[] = "world";
        String_Slice h = slice_make(haystack, strlen(haystack));
        String_Slice n = slice_make(needle, strlen(needle));
        assert(str_slice_contains(h, n));
        trace_log(LOG_OKAY, "Contains test passed");
    }

    // Test split_first
    {
        char test[] = "hello,world";
        String_Slice s = slice_make(test, strlen(test));
        String_Slice before, after;
        str_slice_split_first(s, ',', &before, &after);
        assert(before.count == 5);
        assert(after.count == 5);
        assert(memcmp(before.data, "hello", 5) == 0);
        assert(memcmp(after.data, "world", 5) == 0);
        trace_log(LOG_OKAY, "Split first test passed");
    }

    // Test starts_with and ends_with
    {
        char test[] = "hello world";
        String_Slice s = slice_make(test, strlen(test));
        String_Slice prefix = slice_make(test, 5);  // "hello"
        String_Slice suffix = slice_make(test + 6, 5);  // "world"
        assert(str_slice_starts_with(s, prefix));
        assert(str_slice_ends_with(s, suffix));
        trace_log(LOG_OKAY, "Starts/ends with tests passed");
    }

    // Test new split function
    {
        char test[] = "one||two||three";
        String_Slice s = slice_make(test, strlen(test));
        String_Slice delim = slice_make("||", 2);

        context   = temp_context();
        usz chk_point = temp_save();

        String_Slice_DArray result = str_slice_split(s, delim);

        assert(result.count == 3);
        assert(memcmp(result.items[0].data, "one", 3) == 0);
        assert(memcmp(result.items[1].data, "two", 3) == 0);
        assert(memcmp(result.items[2].data, "three", 5) == 0);

        context = default_context();
        temp_rewind(chk_point);

        trace_log(LOG_OKAY, "Split by string test passed");
    }

    // Test strip_left and strip_right
    {
        char test[] = "  hello  ";
        String_Slice s = slice_make(test, strlen(test));

        String_Slice left_stripped = str_slice_strip_left(s);
        assert(left_stripped.count == 7);
        assert(memcmp(left_stripped.data, "hello  ", 7) == 0);

        String_Slice right_stripped = str_slice_strip_right(s);
        assert(right_stripped.count == 7);
        assert(memcmp(right_stripped.data, "  hello", 7) == 0);

        trace_log(LOG_OKAY, "Strip left/right tests passed");
    }
}

#define assert_true(test_case, result)               \
{                                                    \
    if (result) {                                    \
        trace_okay("[SUCCESS] %s", test_case);\
    } else {                                         \
        trace_error("[FAIL] %s", test_case);  \
    }                                                \
}

#define assert_false(test_case, result) assert_true(test_case, !result)

u0 another(void) {
    String_Slice ss1 = str_slice_make("./example.exe");
    String_Slice ss2 = str_slice_make("");

    assert_true("str_slice_ends_with(ss1,  \"./example.exe\")",        str_slice_ends_with_zstr(ss1, "./example.exe"));
    assert_true("str_slice_ends_with(ss1,  \".exe\")",                 str_slice_ends_with_zstr(ss1, ".exe"));
    assert_true("str_slice_ends_with(ss1,  \"e\")",                    str_slice_ends_with_zstr(ss1, "e"));
    assert_true("str_slice_ends_with(ss1,  \"\")",                     str_slice_ends_with_zstr(ss1, ""));
    assert_true("str_slice_ends_with(ss2,  \"\")",                     str_slice_ends_with_zstr(ss2, ""));

    assert_false("str_slice_ends_with(ss1, \".png\")",                 str_slice_ends_with_zstr(ss1, ".png"));
    assert_false("str_slice_ends_with(ss1, \"/path/to/example.exe\")", str_slice_ends_with_zstr(ss1, "/path/to/example.exe"));
    assert_false("str_slice_ends_with(ss2, \".obj\")",                 str_slice_ends_with_zstr(ss2, ".obj"));

}



int main(int argc, char *argv[]) {
    int val  = ({
        argc = 123;
        argc;
    });

    printf("val=%d\n", val);

    run_tests();
    example();
    another();
    printf("All tests passed!\n");
    return 0;
}
