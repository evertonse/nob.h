#include "cye.h"
// Forward declaration of the stats structure to ensure it's known

// Define the format strings
#define FILE_LOC_FMT        "%s:%d:%s"
#define FILE_STATS_FMT      "{.created_at=%s(%zu), .accessed_at=%s(%zu), .modified_at=%s(%zu), .size=%zu(bytes)}"

// Helper macro to create compound literal for file location
typedef struct {
    const char* file;
    int line;
    const char* func;
} File_Location;

#define MAKE_FILE_LOC() ((File_Location){__FILE__, __LINE__, __PRETTY_FUNCTION__})

// Generic format string selector
#define fmt _Generic((_dummy), \
    File_Location: FILE_LOC_FMT, \
    File_Stats: FILE_STATS_FMT, \
    default: "" \
)

// Generic format arguments selector
#define fmt_arg(_dummy) _Generic((_dummy), \
    File_Location: (_dummy).file, (_dummy).line, (_dummy).func, \
    File_Stats: \
        ctime(&(_dummy).created_at),  (_dummy).created_at, \
        ctime(&(_dummy).accessed_at), (_dummy).accessed_at, \
        ctime(&(_dummy).modified_at), (_dummy).modified_at, \
        (_dummy).size_bytes, \
    default: "" \
)

// Usage example:
void example(void) {
    // For file location
    File_Location loc = MAKE_FILE_LOC();
    printf(fmt(loc), fmt_arg(loc));
    
    // For file stats
    File_Stats stats = {
        .created_at = time(NULL),
        .accessed_at = time(NULL),
        .modified_at = time(NULL),
        .size_bytes = 1234
    };
    printf(fmt(stats), fmt_arg(stats));
}
