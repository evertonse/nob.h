#define CYE_IMPLEMENTATION
#include "cye.h"

// Filter to only include files with a specific extension
bool filter_by_extension(const char *path, void *user_data)
{
    const char *extension = (const char *)user_data;
    const char *file_ext = strrchr(path, '.');
    return file_ext != NULL && strcmp(file_ext, extension) == 0;
}

// Filter to only include files that starts with user_data
bool filter_starts_with(const char *path, void *user_data)
{
    const char *section        = (const char *)user_data;

    const size_t section_count = strlen(section);
    const size_t path_count    = strlen(path);
    if (path_count < section_count) {
        return false;
    } else {
        return memcmp(path, section, section_count) == 0;
    }
}

// Filter to only include files that its base_name starts with user_data
bool filter_base_name_starts_with(const char *path, void *user_data)
{
    const char *section        = (const char *)user_data;

    const size_t section_count = strlen(section);
    const size_t path_count    = strlen(path);
    if (path_count < section_count) {
        return false;
    } else {
        return memcmp(path_base_name(path), section, section_count) == 0;
    }
}


#define print_paths() \
    for (usz idx = 0; idx < paths.count; idx += 1) { \
        printf("paths.items[idx]=%s\n", paths.items[idx]); \
    }

int main(void) {
    Path_DArray paths = {0};

    {
        read_dir("./build/", &paths);
        print_paths();
    }

    printf("--------------------------\n");
    paths.count = 0;

    {
        read_dir_filtered("./", &paths, false, filter_by_extension, ".c");
        print_paths();
    }

    exit(1);
    return 0;
}
