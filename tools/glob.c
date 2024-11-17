#define CYE_IMPLEMENTATION
#include "cye.h"
#include "shared.h"
#include <dirent.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>


static int str_cmp(const void *p1, const void *p2)
{
    char *const *s1_ptr = p1;
    char *const *s2_ptr = p2;
    return strcmp(*s1_ptr, *s2_ptr);
}


int main(int argc, char *argv[]) {
    ZString program = shift(argv, argc);
    unused(program);

    if (argc < 1) {
        trace_info("usage <pattern>");
        return 1;
    }

    set_trace_level(LOG_DEBUG);

    ZString pattern = shift(argv, argc);
    Cye_Path_DArray matches = {0};
    usz chk_point = temp_save();

    matches = cye_path_tglob(pattern);
    qsort(matches.paths, matches.count, sizeof(char *), str_cmp);

    usz bytes = 0;
    for (usz i = 0; i < matches.count; i++) {
        bytes += (strlen(matches.paths[i]) + 1);
    }
    bytes += matches.capacity * size_of(matches.items[0]);

    // NOTE: This assert is wrong if we're using `realloc` with temporary allocator.
    // Because `trealloc` fragments memory, but the rewind amends this behaviour.
    // I'll leave here in case we do a more elaborate way of `trealloc`, effectively
    // making this assert be correct.
    if (false) {
        assert_msg(bytes == cye_temp_data.size, "bytes (%zu) != cye_temp_data.size (%zu)", bytes, cye_temp_data.size );
    }
    temp_rewind(chk_point);

    return 0;
}


