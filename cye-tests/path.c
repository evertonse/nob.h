#define CYE_IMPLEMENTATION
#include "cye.h"

void test_path_create(void) {
    const char *test_cases[][4] = {
        // Each row contains: {path1, path2, expected_result}
        {"//bin////lol",  "",                "/dsadas/",       "/bin/lol/dsadas/"         },
        {"./dir",         "file",            ".txt",           "./dir/file/.txt"          },
        {"./dir/",        "",                "/normal.txt",    "./dir/normal.txt"         },
        {"/usr///local/", "",                "//bin/",         "/usr/local/bin/"          },
        {"/home/",        "",                "/user//",        "/home/user/"              },
        {"",              "//log////",                "",      "/log/"                    },
        {"/tmp",          "space in beteen", "",               "/tmp/space in beteen"     },
        {"local",         " space-around ",  "dir/",           "local/ space-around /dir/"},
        {"//etc//",       "",                "///config//",    "/etc/config/"             },
        {".dotfiles",     "",                "..//downloads/", ".dotfiles/../downloads/"  },
        {"..",            "double-dot",      "..",             "../double-dot/../"        }, // Double dot has to end in path separator, same for one dot
        {".",             "...",             "",               "./..."                    }, // Thress dots are not special
        // TODO: Make this slurping /./ work
        {".///",          ".",               "/.",             "."                        }, // We should supress /./ in the middle and it sould end with /
    };

    const usz num_tests = count_of(test_cases);
    assert( num_tests == (sizeof(test_cases) / sizeof(test_cases[0])) && "We Should be balling but we're not");
    usz tests_passed = 0;

    {
        context         = temp_context();
        usz checkpoint  = temp_save();

        for (usz i = 0; i < num_tests; i++) {
            const char *path1 = test_cases[i][0];
            const char *path2 = test_cases[i][1];
            const char *path3 = test_cases[i][2];
            const char *expected = test_cases[i][3];

            char *result = path_create(path1, path2, path3);
            
            if (result == NULL) {
                trace_log(LOG_ERROR, "Test %zu failed, path_create returned NULL for inputs `%s`, `%s` and `%s`", i, path1, path2, path3);
                continue;
            }

            if (0 == strcmp(result, expected)) {
                trace_log(LOG_INFO, "Test %zu passed, '%s' + '%s' + '%s' -> '%s'", i, path1, path2, path3, result);
                tests_passed++;
            } else {
                trace_log(LOG_ERROR, "Test %zu failed, expected '%s' but got '%s' for inputs `%s`, `%s` and `%s`", i, expected, result, path1, path2, path3);
            }

        }

        context = default_context();
        temp_rewind(checkpoint);
    }

    trace_log(LOG_INFO, "Path creation tests complete: %zu/%zu passed",
            tests_passed, num_tests);

    // Optional: make the test suite fail if not all tests passed
    if (tests_passed != num_tests) {
        trace_log(LOG_ERROR, "Some path creation tests failed!");
        exit(1);
    }
}

int main(void) {
    test_path_create();
    return 0;
}
