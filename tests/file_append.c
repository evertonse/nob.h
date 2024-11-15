#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#endif

bool cye_file_append(const char* path, const void* data, size_t count) {
    bool result = true;

#ifndef _WIN32
    int fd = -1;
    ssize_t bytes_written = 0;
    
    // Open file for append
    fd = open(path, O_WRONLY | O_APPEND | O_CREAT, 0644);
    if (fd == -1) {
        cye_trace_error("Could not open file %s for append: %s", path, CYE_GET_ERROR_STRING);
        cye_result_defer(false);
    }
    
    // Write the data
    bytes_written = write(fd, data, count);
    if (bytes_written == -1 || (size_t)bytes_written != count) {
        cye_trace_error("Could not write to file %s: %s", path, CYE_GET_ERROR_STRING);
        cye_result_defer(false);
    }
#else
    HANDLE file_handle = INVALID_HANDLE_VALUE;
    DWORD bytes_written = 0;
    
    // Open file for append
    file_handle = CreateFileA(
        path,                     // path
        FILE_APPEND_DATA,         // access mode (append only)
        FILE_SHARE_READ,          // share mode
        NULL,                     // security attributes
        OPEN_ALWAYS,             // create if not exists
        FILE_ATTRIBUTE_NORMAL,    // file attributes
        NULL                      // template file
    );
    
    if (file_handle == INVALID_HANDLE_VALUE) {
        cye_trace_error("Could not open file %s for append: %s", path, CYE_GET_ERROR_STRING);
        cye_result_defer(false);
    }
    
    // Move file pointer to end (should be redundant with FILE_APPEND_DATA, but being thorough)
    if (SetFilePointer(file_handle, 0, NULL, FILE_END) == INVALID_SET_FILE_POINTER) {
        cye_trace_error("Could not seek to end of file %s: %s", path, CYE_GET_ERROR_STRING);
        cye_result_defer(false);
    }
    
    // Write the data
    if (!WriteFile(file_handle, data, (DWORD)count, &bytes_written, NULL) || bytes_written != count) {
        cye_trace_error("Could not write to file %s: %s", path, CYE_GET_ERROR_STRING);
        cye_result_defer(false);
    }
#endif

defer:
#ifndef _WIN32
    if (fd != -1) {
        close(fd);
    }
#else
    if (file_handle != INVALID_HANDLE_VALUE) {
        CloseHandle(file_handle);
    }
#endif
    return result;
}

// Optional: convenience function for appending strings
bool cye_file_append_str(const char* path, const char* str) {
    return cye_file_append(path, str, strlen(str));
}

// Example usage:
#if 0
int main() {
    const char* text = "Hello, World!\n";
    if (!cye_file_append("test.txt", text, strlen(text))) {
        return 1;
    }
    
    // Or using the string helper
    if (!cye_file_append_str("test.txt", "Another line\n")) {
        return 1;
    }
    
    return 0;
}
#endif
