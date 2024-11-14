#define CYE_IMPLEMENTATION
#include "cye.h"
#include <string.h>

#ifdef _WIN32
#include <windows.h>
static const char* EXECUTABLE_EXTENSIONS[] = {".exe", ".com", ".bat", ".cmd"};
#else
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#endif

#define ds_clear(ds) ds->count = 0

// Check if a path exists and is executable
static bool is_executable(const char* path) {
#ifdef _WIN32
    DWORD attr = GetFileAttributesA(path);
    if (attr == INVALID_FILE_ATTRIBUTES) return false;
    
    // Check if it's a directory
    if (attr & FILE_ATTRIBUTE_DIRECTORY) return false;
    
    return true;
#else
    struct stat st;
    if (stat(path, &st) != 0) return false;
    
    // Check if it's a regular file and has execute permission
    return S_ISREG(st.st_mode) && (st.st_mode & (S_IXUSR | S_IXGRP | S_IXOTH));
#endif
}

#ifdef _WIN32
// Windows-specific: check if string ends with any executable extension
static bool has_executable_extension(const char* path) {
    const char* ext = strrchr(path, '.');
    if (!ext) return false;
    
    for (size_t i = 0; i < sizeof(EXECUTABLE_EXTENSIONS)/sizeof(EXECUTABLE_EXTENSIONS[0]); i++) {
        if (_stricmp(ext, EXECUTABLE_EXTENSIONS[i]) == 0) {
            return true;
        }
    }
    return false;
}
#endif

// Find executable in PATH or current directory
static bool find_executable(const char* name, DString* out_path) {
    if (!name || !out_path) return false;
    
    // If name contains any path separator, check it directly
    const char* path_sep =
#ifdef _WIN32
        strpbrk(name, "\\/");
#else
        strchr(name, '/');
#endif
    
    if (path_sep) {
        out_path->count = 0;
        ds_write(out_path, name);
#ifdef _WIN32
        // On Windows, if no extension provided, try adding .exe
        if (!has_executable_extension(name)) {
            ds_write(out_path, ".exe");
        }
#endif
        return is_executable(out_path->items);
    }
    
    // Get PATH environment variable
    const char* path_env = getenv("PATH");
    // printf("$PATH=%s\n", path_env);
    if (!path_env) return false;
    
    DString path_copy = {0};
    ds_write(&path_copy, path_env);
    
    // PATH separator character
#ifdef _WIN32
    const char PATH_ENV_SEP = ';';
#else
    const char PATH_ENV_SEP = ':';
#endif
    
    // Try each directory in PATH
    char* dir = strtok(path_copy.items, &PATH_ENV_SEP);
    while (dir) {
        ds_clear(out_path);
        ds_write(out_path, dir);
        if (out_path->count > 0 && out_path->items[out_path->count-1] != PATH_SEPARATOR_CHAR) {
            ds_write(out_path, PATH_SEPARATOR);
        }

        ds_write(out_path, name);
        ds_write_zero(out_path);
        
#ifdef _WIN32
        // On Windows, try with and without .exe if no extension provided
        if (!has_executable_extension(name)) {
            // Try without extension first
            if (is_executable(out_path->items)) {
                ds_free(path_copy);
                return true;
            }
            // Try with .exe
            ds_write(out_path, ".exe");
        }
#endif
        
        if (is_executable(out_path->items)) {
            ds_free(path_copy);
            return true;
        }
        
        dir = strtok(NULL, &PATH_ENV_SEP);
    }
    
    ds_free(path_copy);
    return false;
}

int main() {
    DString path = {0};
    
    // Try to find some executables
    const char* executables[] = {
        "cmd",           // Windows built-in
        "sh",           // Unix built-in
        "gcc",          // Usually in PATH if installed
        "nonexistent",  // Should fail
        "./local.exe",  // Local path
        "../bin/tool"   // Relative path
    };
    
    for (size_t i = 0; i < sizeof(executables)/sizeof(executables[0]); i++) {
        if (find_executable(executables[i], &path)) {
            printf("Found %s at: %s\n", executables[i], path.items);
        } else {
            printf("Could not find %s\n", executables[i]);
        }
    }
    
    ds_free(path);
    return 0;
}
