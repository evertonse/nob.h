#define CYE_IMPLEMENTATION
#include "cye.h"
#include "shared.h"

// #define pattern_match(pattern, text, flags) cye_glob(pattern, text)
// #define pattern_match cye_glob_match_with_flags

#define go(pattern, zstr)                                                                                                                                                                                                                                                                                                                                                                                                          \
    match = zstr_match_pattern(pattern, zstr);                                                                                                                                                                                                                                                                                                                                                                                     \
    if (match) {                                                                                                                                                                                                                                                                                                                                                                                                                   \
        trace_okay("Match pattern = %s; zstr = %s", pattern, zstr);                                                                                                                                                                                                                                                                                                                                                                 \
    } else {                                                                                                                                                                                                                                                                                                                                                                                                                       \
        trace_info("Doesn't match pattern = %s; zstr = %s", pattern, zstr);                                                                                                                                                                                                                                                                                                                                                        \
    }


void test_dynamic_array(void) {
    bool match = false;
    go("*txt", "lol");
    go("*txt", "dasdasda dasdas dasd as.txt");
    go("*txt", "txt");
}


void test_pattern_match() {
    const char *files[] = {
      "data1.txt",
      "data2.txt",
      "image1.png",
      "image2.jpg",
      "report.pdf",
      "notes.docx",
      "data_backup_2023.zip",
      "data1.csv",
      "README.md"
    };

    // # Different patterns to match
    const char *
        patterns[] = {
        "*.txt",      // Match all .txt files
        "*.jpg",      // Match all .jpg files
        "data*.txt",  // Match files starting with "data" and ending with .txt
        "*.png",      // Match all .png files
        "data_?.*",   // Match files starting with "data_" followed by a single character
        "data_??.*",  // Match files starting with "data_" followed by two characters
        "*.*",        // Match all files with an extension
        "report.*",   // Match files starting with "report"
        "data[1-2].*" // Match files starting with "data" followed by 1 or 2
    };

    // Using fnmatch to filter files
    for (int idx = 0; idx < count_of(patterns); idx += 1) {
        ZString pattern = patterns[idx];
        for (int idx2 = 0; idx2 < count_of(files); idx2 += 1) {
            ZString file = files[idx2];
            if (pattern_match(pattern, file, 0)) {
                trace_info("Pattern: {%s} -> Matched files: {%s}", pattern, file);
            }
        }
    }
}


void test_string_comparison(void) {
    assert_true(pattern_match("", "", 0));
    assert_true(pattern_match("a", "a", 0));
    assert_true(pattern_match("abc", "abc", 0));
    assert_false(pattern_match("ab", "abc", 0));
    assert_false(pattern_match("a", "", 0));
}

void test_wildcard(void) {
    assert_true(pattern_match("*", "", 0));
    assert_true(pattern_match("*", "a", 0));
    assert_true(pattern_match("*", "abcdefgh", 0));
    assert_true(pattern_match("a*", "abcdefgh", 0));
    assert_true(pattern_match("*h", "abcdefgh", 0));
    assert_true(pattern_match("a*h", "abcdefgh", 0));
    assert_false(pattern_match("a*z", "abcdefgh", 0));
    assert_true(pattern_match("a*b*c", "aIIIbIIIc", 0));
    assert_false(pattern_match("a*b*c", "aIIIIIIc", 0));
}

void test_question_mark(void) {
    assert_false(pattern_match("?", "", 0));
    assert_true(pattern_match("?", "a", 0));
    assert_true(pattern_match("x?x", "xax", 0));
    assert_false(pattern_match("x?x", "xx", 0));
    assert_true(pattern_match("x???x???x", "x123x456x", 0));
    assert_false(pattern_match("x??x???x", "x123x456x", 0));
}

void test_character_classes(void) {
    assert_true(pattern_match("[zxc]", "z", 0));
    assert_true(pattern_match("[zxc]", "x", 0));
    assert_true(pattern_match("[zxc]", "c", 0));
    assert_false(pattern_match("[zxc]", "j", 0));
    assert_true(pattern_match("x[zxc]x", "xcx", 0));
    assert_false(pattern_match("x[zxc]x", "xjx", 0));
}

void test_character_classes_range(void) {
    assert_true(pattern_match("[a-c]", "a", 0));
    assert_true(pattern_match("[a-c]", "b", 0));
    assert_true(pattern_match("[a-c]", "c", 0));
    assert_false(pattern_match("[a-c]", "x", 0));
    assert_true(pattern_match("x[a-c]x", "xcx", 0));
    assert_false(pattern_match("x[a-c]x", "xdx", 0));
    assert_false(pattern_match("[a-cF-G]", "d", 0));
    assert_true(pattern_match("[a-cF-G]", "b", 0));
    assert_true(pattern_match("[a-cF-Z]", "H", 0));
    assert_true(pattern_match("[a-cF-Z]", "I", 0));
    assert_true(pattern_match("[a-cF-Z]", "c", 0));
    assert_false(pattern_match("[a-cF-Z]", "C", 0));
}

void test_character_classes_complement() {
    assert_true(pattern_match("[!zxc]", "j", 0));
    assert_false(pattern_match("[!zxc]", "z", 0));
    assert_false(pattern_match("[!zxc]", "x", 0));
    assert_false(pattern_match("[!zxc]", "c", 0));
    assert_false(pattern_match("x[!zxc]x", "xcx", 0));
    assert_true(pattern_match("x[!zxc]x", "xjx", 0));
}

void test_character_classes_ranges_complement(void) {
    assert_false(pattern_match("[!a-c]", "a", 0));
    assert_false(pattern_match("[!a-c]", "b", 0));
    assert_false(pattern_match("[!a-c]", "c", 0));
    assert_true(pattern_match("[!a-c]", "x", 0));
    assert_false(pattern_match("x[!a-c]x", "xcx", 0));
    assert_true(pattern_match("x[!a-c]x", "xdx", 0));
    assert_true(pattern_match("[!a-cF-G]", "d", 0));
    assert_false(pattern_match("[!a-cF-G]", "b", 0));
    assert_false(pattern_match("[!a-cF-Z]", "H", 0));
    assert_false(pattern_match("[!a-cF-Z]", "I", 0));
    assert_false(pattern_match("[!a-cF-Z]", "c", 0));
    assert_true(pattern_match("[!a-cF-Z]", "C", 0));
}

void test_character_classes_range_with_regular_character(void) {
    assert_true(pattern_match("[fa-cF-Zg]", "a", 0));
    assert_true(pattern_match("[fa-cF-Zg]", "b", 0));
    assert_true(pattern_match("[fa-cF-Zg]", "H", 0));
    assert_true(pattern_match("[fa-cF-Zg]", "Z", 0));
    assert_true(pattern_match("[fa-cF-Zg]", "f", 0));
    assert_true(pattern_match("[fa-cF-Zg]", "g", 0));
    assert_false(pattern_match("[fa-cF-Zg]", "j", 0));
    
}

void test_character_classes_first_character_no_meaning(void) {
    assert_true(pattern_match("x[]]x", "x]x", 0));
    assert_true(pattern_match("x[]a]x", "xax", 0));
    assert_true(pattern_match("x[]a]x", "x]x", 0));
    assert_false(pattern_match("x[]a]x", "x[x", 0));
    assert_true(pattern_match("[][!]", "[", 0));
    assert_true(pattern_match("[][!]", "!", 0));
    assert_true(pattern_match("[][!]", "]", 0));
}

void test_character_classes_hypen(void) {
    assert_true(pattern_match("[-]", "-", 0));
    assert_false(pattern_match("[-]", "a", 0));
    assert_true(pattern_match("[-a]", "a", 0));
    assert_true(pattern_match("[a-]", "a", 0));
    assert_true(pattern_match("[-a]", "-", 0));
    assert_true(pattern_match("[a-]", "-", 0));
    assert_true(pattern_match("[a-c-]", "b", 0));
    assert_true(pattern_match("[a-c-]", "-", 0));
    assert_true(pattern_match("[-a-c]", "b", 0));
    assert_true(pattern_match("[-a-c]", "-", 0));
}

void test_character_classes_hypen_and_square_bracket(void) {
    assert_true(pattern_match("[]-]", "-", 0));
    assert_true(pattern_match("[]-]", "]", 0));
    assert_false(pattern_match("[]-]", "x", 0));
    
}

void test_character_classes_error_no_closing_square_bracket(void) {
    assert_false(pattern_match("[", "", 0));
    assert_false(pattern_match("[[", "", 0));
    assert_false(pattern_match("[]", "", 0));
    // cr_assert_neq(pattern_match("[]]", "", 0), CYE_FNM_ERROR_MISSING_CLOSING);
    assert_false(pattern_match("[\0]", "", 0));
    assert_false(pattern_match("[a\0]", "", 0));
    assert_false(pattern_match("[abcd\0]", "", 0));
}

void test_flag_pathname(void) {
    assert_true(pattern_match("/*a*b*/*c*d*", "/a.b/c.d", CYE_PATTERN_PATH));
    assert_true(pattern_match("", "", CYE_PATTERN_PATH));
    assert_true(pattern_match("/", "/", CYE_PATTERN_PATH));
    assert_false(pattern_match("*", "/", CYE_PATTERN_PATH));
    assert_true(pattern_match("/*", "/etc", CYE_PATTERN_PATH));
    assert_false(pattern_match("/*", "/e/tc", CYE_PATTERN_PATH));
    assert_true(pattern_match("/*/*", "/etc/foo", CYE_PATTERN_PATH));
    assert_false(pattern_match("/*/*", "/etc/foo/", CYE_PATTERN_PATH));
    assert_true(pattern_match("/*/*/", "/etc/foo/", CYE_PATTERN_PATH));
    assert_true(pattern_match("/*/*/*.c", "/etc/foo/bar.c", CYE_PATTERN_PATH));
    assert_false(pattern_match("/*/*/*.c", "/etc/foo/ba/r.c", CYE_PATTERN_PATH));
    assert_false(pattern_match("?", "/", CYE_PATTERN_PATH));
    assert_true(pattern_match("?/?", "a/x", CYE_PATTERN_PATH));
    assert_false(pattern_match("???", "a/x", CYE_PATTERN_PATH));
    assert_false(pattern_match("[abc/]", "/", CYE_PATTERN_PATH));
    assert_true(pattern_match("[abc/]/x", "a/x", CYE_PATTERN_PATH));
}

void test_no_flag_pathname(void) {
    assert_true(pattern_match("", "", 0));
    assert_true(pattern_match("/", "/", 0));
    assert_true(pattern_match("*", "/", 0));
    assert_true(pattern_match("/*", "/etc", 0));
    assert_true(pattern_match("/*", "/e/tc", 0));
    assert_true(pattern_match("/*/*", "/etc/foo", 0));
    assert_true(pattern_match("/*/*", "/etc/foo/", 0));
    assert_true(pattern_match("/*/*/", "/etc/foo/", 0));
    assert_true(pattern_match("/*/*/*.c", "/etc/foo/bar.c", 0));
    assert_true(pattern_match("/*/*/*.c", "/etc/foo/ba/r.c", 0));
    assert_true(pattern_match("?", "/", 0));
    assert_true(pattern_match("?/?", "a/x", 0));
    assert_true(pattern_match("???", "a/x", 0));
    assert_true(pattern_match("[abc/]", "/", 0));
    assert_true(pattern_match("[abc/]/x", "a/x", 0));
}


void test_flag_period(void) {
    assert_true(pattern_match(".hello", ".hello", CYE_PATTERN_PERIOD));
    assert_false(pattern_match("*hello", ".hello", CYE_PATTERN_PERIOD));
    assert_true(pattern_match(".he*", ".hello", CYE_PATTERN_PERIOD));
    assert_false(pattern_match("he*o", "hel.lo", CYE_PATTERN_PERIOD));
    
}

void test_no_flag_period(void) {
    assert_true(pattern_match(".hello", ".hello", 0));
    assert_true(pattern_match("*hello", ".hello", 0));
    assert_true(pattern_match(".he*", ".hello", 0));
    assert_true(pattern_match("he*o", "hel.lo", 0));
}

void test_flag_period_and_flag_pathname(void) {
    int flags = CYE_PATTERN_PERIOD | CYE_PATTERN_PATH;
    assert_true(pattern_match("/.hello", "/.hello", flags));
    assert_true(pattern_match("/.hel/.lo", "/.hel/.lo", flags));
    assert_false(pattern_match("/*hel/.lo", "/.hel/.lo", flags));

    assert_true(pattern_match("/*a*b*/*c*d*", "/ab/cd", flags));

    assert_true(pattern_match("*a*b*/*c*d*", "ab/cd", flags));

    assert_true(pattern_match("a*/", "a/", flags));
    assert_true(pattern_match("a*****/", "a/", flags));
    assert_true(pattern_match("a?/", "a/", flags));
    assert_true(pattern_match("??????/", "a/", flags));

    assert_false(pattern_match("/*a*b*/*c*d*", "/a.b/c.d", flags));
    assert_true(pattern_match("/*.*/*.*", "/a.b/c.d", flags));
    assert_false(pattern_match("/.hel/*lo", "/.hel/.lo", flags));
    assert_true(pattern_match("/.hel/.*", "/.hel/.lo", flags));
    assert_true(pattern_match("/.*/.lo", "/.hel/.lo", flags));
    assert_false(pattern_match("/he*o", "/hel.lo", flags));
    assert_true(pattern_match("/he*o", "/hel;lo", flags));
}

void test_no_flag_period_and_flag_pathname(void) {
    assert_true(pattern_match("/.hello", "/.hello", 0));
    assert_true(pattern_match("/.hel/.lo", "/.hel/.lo", 0));
    assert_true(pattern_match("/*hel/.lo", "/.hel/.lo", 0));
    assert_true(pattern_match("/.hel/*lo", "/.hel/.lo", 0));
    assert_true(pattern_match("/.hel/.*", "/.hel/.lo", 0));
    assert_true(pattern_match("/.*/.lo", "/.hel/.lo", 0));
}

int main(int argc, char *argv[]) {
    test_pattern_match();
    test_dynamic_array();
    test_character_classes();
    test_character_classes_complement();
    test_no_flag_period_and_flag_pathname();
    test_flag_period_and_flag_pathname();
    test_no_flag_period();
    test_flag_period();
    test_no_flag_pathname();
    test_flag_pathname();
    test_character_classes_error_no_closing_square_bracket();
    test_character_classes_hypen_and_square_bracket();
    test_character_classes_hypen();
    test_character_classes_first_character_no_meaning();
    test_character_classes_range_with_regular_character();
    test_character_classes_ranges_complement();
    test_character_classes_range();
    test_question_mark();
    test_wildcard();
    test_string_comparison();
    error_count_log_and_reset();
}
