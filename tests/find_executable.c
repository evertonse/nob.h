#define CYE_IMPLEMENTATION
#include "cye.h"
#include <string.h>

int main() {
    DString path = {0};
    
    // Try to find some executables
    const char* executables[] = {
        "cmd",           // Windows built-in
        "sh",           // Unix built-in
        "gcc",          // Usually in PATH if installed
        "dmenu",
        "nonexistent",  // Should fail
        "./local.exe",  // Local path
        "../bin/tool"   // Relative path
    };
    
    for (usz i = 0; i < sizeof(executables)/sizeof(executables[0]); i++) {
        if (find_executable(executables[i], &path)) {
            printf("Found %s at: %s\n", executables[i], path.items);
        } else {
            printf("Could not find %s\n", executables[i]);
        }
    }
    
    ds_free(path);
    return 0;
}
