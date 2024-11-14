#ifndef _CYE_H_
#define _CYE_H_


// Ideias
//
// - Errors:
//      Must be gracefully handled, the default is if things already exist, it's ok.
//      If some action is not permitted, trace log an error and let the user handdle (don't crash).
//
//

/*..................................................................................
 .                                                                                 .
 .                                BASIC                                            .
 .                                                                                 .
 ...................................................................................
*/
//----------------------------------------------------------------------------------
//  Basic Includes
//----------------------------------------------------------------------------------

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stddef.h>
#include <stdint.h>
#include <time.h>
#include <stdio.h>


#ifdef _WIN32
#    define WIN32_LEAN_AND_MEAN
#    define _WINUSER_
#    define _WINGDI_ // Not protable to msvc i think need tro use NO_GDI stuff from windows.h
#    define _IMM_
#    define _WINCON_
#    include <windows.h>
#    include <direct.h>
#    include <shlobj.h>
#    include <shellapi.h>
#    include <io.h>
#    define stat _stat
#    define utimbuf _utimbuf
#    define utime _utime
#    define PATH_SEPARATOR "\\"
#    define PATH_SEPARATOR_CHAR '\\'
#    define PATH_MAX MAX_PATH
#else
#    include <sys/types.h>
#    include <sys/wait.h>
#    include <sys/stat.h>
#    include <unistd.h>
#    include <fcntl.h>
#    include <dirent.h>
#    include <pwd.h>
#    include <utime.h>
#    include <errno.h>
#    define PATH_SEPARATOR "/"
#    define PATH_SEPARATOR_CHAR '/'
#endif



//----------------------------------------------------------------------------------
//  Basic Definitions with No Prefix
//----------------------------------------------------------------------------------

#ifndef as
#   define as(Type) (Type)
#endif

// Why would a signed sizeof be more useful?
#ifndef size_of
#   define size_of(x) (isize)(sizeof(x))
#endif

#ifndef count_of
#define count_of(x)                                                            \
  ((size_of(x) / size_of(x[0])) / ((isize)(!(size_of(x) % size_of(x[0])))))
#endif

#ifndef offset_of
#   define offset_of(Type, element) ((isize) & (((Type *)0)->element))
#endif

#ifndef fn_unused
#   if defined(_MSC_VER)
#       define fn_unused(x) (__pragma(warning(suppress : 4100))(x))
#   elif defined(__GCC__)
#       define fn_unused(x) __attribute__((__unused__)) (x)
#   else
#       define fn_unused(x)
#   endif
#endif

#define unused(x) ((void)(x))


#ifndef kilobytes
#   define kilobytes(x) ((x) * (i64)(1024))
#   define megabytes(x) (kilobytes(x) * (i64)(1024))
#   define gigabytes(x) (megabytes(x) * (i64)(1024))
#   define terabytes(x) (gigabytes(x) * (i64)(1024))
#endif

#define local static
#define file_scope static

#if defined(__GNUC__) || defined(__GNUG__)
#   define force_inline   inline __attribute__((always_inline))
#   define force_noinline __attribute__((noinline))
#elif defined(_MSC_VER)
#   if _MSC_VER < 1300
#       define force_inline
#   else
#       define force_inline __forceinline
#       define force_noinline __declspec(noinline)
#   endif
#endif

#if !defined(__cplusplus)
#   if defined(_MSC_VER) && _MSC_VER <= 1800
#       define inline __inline
#   elif !defined(__STDC_VERSION__)
#       define inline __inline__
#   else
#       define inline
#   endif
#endif

#ifndef DEBUG_TRAP
#   if defined(_MSC_VER)
#      if _MSC_VER < 1300
#          define DEBUG_TRAP() __asm int 3
#      else
#          define DEBUG_TRAP() __debugbreak()
#      endif
#   else
#      define DEBUG_TRAP() __builtin_trap()
#   endif
#endif

#ifndef static_assert // From: Odin gb.h
#   define static_assert3(cond, msg) typedef char static_assertion_##msg[(!!(cond))*2-1]
#   define static_assert2(cond, line) static_assert3(cond, static_assertion_at_line_##line)
#   define static_assert1(cond, line) static_assert2(cond, line)
#   define static_assert(cond)        static_assert1(cond, __LINE__)
#endif


#if defined(__GNUC__) || defined(__GNUG__)
#   define force_restrict __restrict__
#elif defined(_MSC_VER)
#   define force_restrict __restrict
#endif

#if !defined(thread_local)
#   if defined(_MSC_VER) && _MSC_VER >= 1300
#       define thread_local __declspec(thread)
#   else
#       ifdef __cplusplus
#           define thread_local thread_local
#       else
#           define thread_local __thread // TODO: maybe check for GCC just to be sure
#       endif
#   endif
#endif

#ifndef null
#   if defined(__cplusplus)
#      if __cplusplus >= 201103L
#          define null nullptr
#      else
#          define null 0
#      endif
#   else
#      define null ((void *)0)
#   endif
#endif

#ifndef U8_MIN
#define U8_MIN 0u
#define U8_MAX 0xffu
#define I8_MIN (-0x7f - 1)
#define I8_MAX 0x7f

#define U16_MIN 0u
#define U16_MAX 0xffffu
#define I16_MIN (-0x7fff - 1)
#define I16_MAX 0x7fff

#define U32_MIN 0u
#define U32_MAX 0xffffffffu
#define I32_MIN (-0x7fffffff - 1)
#define I32_MAX 0x7fffffff

#define U64_MIN 0ull
#define U64_MAX 0xffffffffffffffffull
#define I64_MIN (-0x7fffffffffffffffll - 1)
#define I64_MAX 0x7fffffffffffffffll

#if defined(__i386__) || UINTPTR_MAX == 0xffFFffFF
#   define USIZE_MIX U32_MIN
#   define USIZE_MAX U32_MAX
#   define ISIZE_MIX I32_MIN
#   define ISIZE_MAX I32_MAX
#elif defined(__amd64__) || defined(__X86_64__) || UINTPTR_MAX == 0xffFFffFFffFFffFF
#   define USIZE_MIN  U64_MIN
#   define USIZE_MAX  U64_MAX
#   define ISIZE_MIN  I64_MIN
#   define ISIZE_MAX  I64_MAX
#else
#   //TODO: Portable warning is needed because of MSVC
#   warning "You might need to check for more CPU Architectures"
#endif

#define USZ_MIN  USIZE_MIN
#define USZ_MAX  USIZE_MAX
#define ISZ_MIX  ISIZE_MIN
#define ISZ_MAX  ISIZE_MAX

#define ESCAPE_CODE_HEADER    "\033[95m"
#define ESCAPE_CODE_OKBLUE    "\033[94m"
#define ESCAPE_CODE_OKCYAN    "\033[96m"
#define ESCAPE_CODE_OKGREEN   "\033[92m"
#define ESCAPE_CODE_WARNING   "\033[93m"
#define ESCAPE_CODE_FAIL      "\033[91m"
#define ESCAPE_CODE_RESET     "\033[0m"
#define ESCAPE_CODE_UNDERLINE "\033[4m"
#define ESCAPE_CODE_LOG       "\x1b[30;1m";
#define ESCAPE_CODE_WARN      "\x1b[1m\x1b[33m";
#define ESCAPE_CODE_ERROR     "\x1b[1m\x1b[31m";
#define ESCAPE_CODE_BOLD      "\x1b[37m";



#define F32_MIN 1.17549435e-38f
#define F32_MAX 3.40282347e+38f

#define F64_MIN 2.2250738585072014e-308
#define F64_MAX 1.7976931348623157e+308
#endif

// Adapted from Odin src code
#define set_bit(bitfield, pos)       ((bitfield)  |=  (1 << (pos)))
#define clear_bit(bitfield, pos)     ((bitfield)  &= ~(1 << (pos)))
#define toggle_bit(bitfield, pos)    ((bitfield)  ^=  (1 << (pos)))
#define read_bit(bitfield, pos)      (((bitfield) >>  (pos)) & 0x01)

#if !defined(PI)
#   define PI 3.14159265358979323846
#endif

#if !defined(EPSILON)
    #define EPSILON 0.000001f
#endif

#ifndef DEG2RAD
    #define DEG2RAD (PI/180.0f)
#endif

#ifndef RAD2DEG
    #define RAD2DEG (180.0f/PI)
#endif

//----------------------------------------------------------------------------------
//  Tweakable Constants
//----------------------------------------------------------------------------------

#ifdef _WIN32
#    define CYE_END_OF_LINE "\r\n"
#    define CYE_PATH_SEPARATOR "\\"
#else
#    define CYE_END_OF_LINE "\n"
#    define CYE_PATH_SEPARATOR "/"
#endif

#ifndef cye_malloc
#   define cye_malloc  malloc
#endif

#ifndef cye_calloc
#   define cye_calloc  calloc
#endif

#ifndef cye_realloc
#   define cye_realloc realloc
#endif

#ifndef cye_free
#   define cye_free    free
#endif

#if !defined(cliteral) && defined(__cplusplus)
#   define cliteral(Type)      Type
#else
#   define cliteral(Type)      (Type)
#endif


#ifndef CYE_DARRAY_INIT_CAP
#   define CYE_DARRAY_INIT_CAP 256
#endif

#ifndef CYE_DARRAY_CAP_MULTIPLIER
#   define CYE_DARRAY_CAP_MULTIPLIER 2
#endif


#ifndef CYE_TEMP_CAPACITY
#   define CYE_TEMP_CAPACITY megabytes(16)
#endif

#ifndef CYE_MAX_TRACE_LOG_MSG_LENGTH
#   define CYE_MAX_TRACE_LOG_MSG_LENGTH 1024
#endif

#ifndef CYE_PATH_MAX
#   define CYE_PATH_MAX (PATH_MAX*2)
#endif


/*..................................................................................
 .                                                                                 .
 .                                Types                                            .
 .                                                                                 .
 ...................................................................................
*/
//----------------------------------------------------------------------------------
//  Structures Definition without Prefix
//----------------------------------------------------------------------------------

// Boolean type
#if (defined(__STDC__) && __STDC_VERSION__ >= 199901L) || (defined(_MSC_VER) && _MSC_VER >= 1800)
#   include <stdbool.h>
#elif !defined(__cplusplus) && !defined(bool)
    typedef enum bool { false = 0, true = !false } bool;
#endif

// TODO: Do we need something like this  #ifndef CYE_NO_INT_TYPES ?
// I remember that linux kernel has some types like this maybe we need to prefix and optionally strip

// I saw this typing in rust and casey's stream, i really like it

// Floating Point
typedef float       f32;
typedef double      f64;

// Unsigned Integers
typedef __uint128_t u128;
typedef uint64_t    u64;
typedef uint32_t    u32;
typedef uint16_t    u16;
typedef uint8_t     u8;
typedef uint8_t     byte;

typedef void        u0;
typedef void*       rawptr;

//      Unsigned  Integers
typedef int64_t   i64;
typedef int32_t   i32;
typedef int16_t   i16;
typedef int8_t    i8;
typedef size_t    usz;
typedef ptrdiff_t isz;

typedef size_t    usize;
typedef ptrdiff_t isize;


typedef i32 rune;
typedef i8  b8;
typedef i16 b16;
typedef i32 b32;

#define RUNE_INVALID as(Rune)(0xfffd)
#define RUNE_MAX     as(Rune)(0x0010ffff)
#define RUNE_BOM     as(Rune)(0xfeff)
#define RUNE_EOF     as(Rune)(-1)


typedef const char* ZString; // Static Zero Terminated String
typedef       char* TString; // Temporary String
typedef       char* MutString; // Mutable String, might be temporary or not

//----------------------------------------------------------------------------------
//  Structures Definition with Prefix
//----------------------------------------------------------------------------------

// NOTE: Organized by priority level
typedef enum {
    CYE_LOG_ALL = 0,        // Display all logs
    CYE_LOG_TRACE,          // Trace logging, intended for internal use only
    CYE_LOG_DEBUG,          // Debug logging, used for internal debugging, it should be disabled on release builds
    CYE_LOG_INFO,           // Info logging, used for program execution info
    CYE_LOG_OKAY,             // Everthying Works, a bit more important and info but less important than error
    CYE_LOG_WARNING,        // Warning logging, used on recoverable failures
    CYE_TRACE_ERROR,          // Error logging, used on unrecoverable failures
    CYE_LOG_FATAL,          // Fatal logging, used to abort program: exit(EXIT_FAILURE)
    CYE_LOG_NONE            // Disable logging
} Cye_Log_Level;

#define Cye_DArray(Type) \
struct {                 \
    Type *items;         \
    usz count;           \
    usz capacity;        \
}

typedef struct {
    const char **items;
    usz count;
    usz capacity;
} Cye_Path_DArray;

typedef enum {
    CYE_FILE_TYPE_REGULAR = 0,
    CYE_FILE_TYPE_DIRECTORY,
    CYE_FILE_TYPE_SYMLINK,
    CYE_FILE_TYPE_OTHER,
} Cye_File_Type;

typedef struct {
    time_t created_at;
    time_t accessed_at;
    time_t modified_at;
    size_t size_bytes;
} Cye_File_Stats;


typedef struct {
    char* items;
    usz   count;
    usz   capacity;
} Cye_DString;


#ifdef _WIN32
    #define CYE_INVALID_PROCESS     (INVALID_HANDLE_VALUE)
    #define CYE_INVALID_FILE_HANDLE (INVALID_HANDLE_VALUE)
    typedef HANDLE Cye_Process;
    typedef HANDLE Cye_File_Handle;
#else
    #define CYE_INVALID_PROCESS     (-1)
    #define CYE_INVALID_FILE_HANDLE (-1)
    typedef int Cye_Process;
    typedef int Cye_File_Handle;
#endif // _WIN32

typedef struct {
    Cye_Process *items;
    usz count;
    usz capacity;
} Cye_Process_DArray;

typedef struct {
    const char **items;
    usz count;
    usz capacity;
} Cye_Command;

typedef struct {
    Cye_File_Handle *in;
    Cye_File_Handle *out;
    Cye_File_Handle *err;
} Cye_Command_Redirect;

typedef struct {
    usz count;
    const char *data;
} Cye_String_Slice;

typedef Cye_DArray(Cye_String_Slice) Cye_String_Slice_DArray;

typedef struct {
    void*  (*alloc)(usz size);
    void*  (*realloc) (void *ptr, usz size);
    void   (*free)(void* ptr);
    rawptr any;
} Cye_Context;


/*..................................................................................
 .                                                                                 .
 .                               Declarations                                      .
 .                                                                                 .
 ...................................................................................
*/

//------------------------------------------------------------------------------------
//  Process and File Declarations
//------------------------------------------------------------------------------------

Cye_File_Handle cye_file_open_for_read(const char *path);
Cye_File_Handle cye_file_open_for_write(const char *path);
void cye_file_close(Cye_File_Handle fh);
bool cye_process_wait_all(Cye_Process_DArray procs);
bool cye_process_wait_all_and_reset(Cye_Process_DArray *procs);
bool cye_process_wait(Cye_Process proc); // Wait until the process has finished

//------------------------------------------------------------------------------------
//  Commands Declarations
//------------------------------------------------------------------------------------
#define cye_cmd_append(cmd, ...)              \
    cye_da_append_many(                       \
        cmd, ((const char *[]){__VA_ARGS__}), \
        (sizeof((const char *[]){__VA_ARGS__}) / sizeof(const char *)))

#define cye_cmd_extend(cmd, other_cmd) \
    cye_da_append_many(cmd, (other_cmd)->items, (other_cmd)->count)

// Free all the memory allocated by command arguments
#define cye_cmd_free(cmd) cye_da_free(cmd)


// Render a string representation of a command into a dynamic string.
void cye_ds_write_cmd(Cye_DString *ds, Cye_Command cmd);

// Run redirected command asynchronously
Cye_Process cye_cmd_run_async_and_reset(Cye_Command *cmd);

// Run redirected command asynchronously and reset count
Cye_Process cye_cmd_run_async_redirect(Cye_Command cmd, Cye_Command_Redirect redirect);

// Run redirected command asynchronously and set cmd.count to 0 and close all the opened files
Cye_Process cye_cmd_run_async_redirect_and_reset(Cye_Command *cmd, Cye_Command_Redirect redirect);

// Run command asynchronously
#define cye_cmd_run_async(cmd) cye_cmd_run_async_redirect(cmd, (Cye_Command_Redirect) {0})

// Run command synchronously
bool cye_cmd_run_sync(Cye_Command cmd);

bool cye_cmd_run_sync_and_reset(Cye_Command *cmd);

// Run redirected command synchronously
bool cye_cmd_run_sync_redirect(Cye_Command cmd, Cye_Command_Redirect redirect);

// Run redirected command synchronously and set cmd.count to 0 and close all the opened files
bool cye_cmd_run_sync_redirect_and_reset(Cye_Command *cmd, Cye_Command_Redirect redirect);

#if !defined(cye_rebuild_command)
#  ifdef _WIN32
#    if defined(__GNUC__)
#       define cye_rebuild_command(binary_path, source_path) "gcc", "-o", binary_path, source_path, "-Wno-unused-parameter"
#    elif defined(__clang__)
#       define cye_rebuild_command(binary_path, source_path) "clang", "-o", binary_path, source_path
#    elif defined(_MSC_VER)
#       if defined(__clang__)
#           define cye_rebuild_command(binary_path, source_path) "clang-cl.exe", cye_tprintf("/Fe:%s", (binary_path)), source_path
#       else
#           define cye_rebuild_command(binary_path, source_path) "cl.exe", cye_tprintf("/Fe:%s", (binary_path)), source_path
#       endif
#    endif
#  else
#    define cye_rebuild_command(binary_path, source_path) "cc", "-o", binary_path, source_path
#  endif
#endif

// Sean Barret Style in-between `__`
// void cye__rebuild_ourselves(const char *source_path, int argc, char **argv);
void cye__rebuild_ourselves(ZString source_path, int argc, ZString *argv);
#define cye_rebuild_ourselves(argc, argv) cye__rebuild_ourselves(__FILE__, argc, argv)


//------------------------------------------------------------------------------------
//  Storage Declarations
//------------------------------------------------------------------------------------

Cye_Context cye_temp_context(void);
Cye_Context cye_default_context(void);

u0 cye_set_default_context(Cye_Context ctx);

char* cye_tstrdup(const char *cstr);
void* cye_talloc(usz size);
void* cye_trealloc(void *ptr, usz size);
void  cye_tfree(rawptr ptr);

TString cye_tprintf(ZString fmt, ...);

void cye_temp_reset(void);
usz  cye_temp_save(void);
void cye_temp_rewind(usz checkpoint);

//------------------------------------------------------------------------------------
//  Path Declarations
//------------------------------------------------------------------------------------

bool cye_make_dir_if_not_exists(const char *path);
bool cye_copy_file(const char *src_path, const char *dst_path);
bool cye_copy_dir(const char *src_path, const char *dst_path);
bool cye_read_entire_dir(const char *parent, Cye_Path_DArray *children);

// Write bytes to a file, creating if it doesnt exist
bool cye_write_entire_file(const char *path, const void *data, usz size);

// Read contents of file into a Dynamic String
bool cye_read_entire_file(const char *path, Cye_DString *ds);

// Get File Type
Cye_File_Type cye_path_file_type(const char *path);

// Normalize Path ex: ///oi/hello/././.txt -> /oi/hello/.txt
char* cye_path_temp_normalize(ZString path);

// Create from path parts and normalize
char* cye_path_create_from_array(ZString paths[], usz paths_count);

#define cye_path_create(...)                                            \
    cye_path_create_from_array(                                         \
        ((const char*[]){__VA_ARGS__}),                                 \
        (sizeof((const char *[]){__VA_ARGS__}) / sizeof(const char *)))

#define cye_path_temp_create(...)                                        \
({                                                                       \
    Cye_Context before = cye_context;                                    \
    cye_context = cye_temp_context();                                    \
    TString path = cye_path_create_from_array(                           \
        ((const char*[]){__VA_ARGS__}),                                  \
        (sizeof((const char *[]){__VA_ARGS__}) / sizeof(const char *))); \
    cye_context = before;                                                \
    path;                                                                \
})


ZString cye_path_base_name(const char *path);
ZString cye_path_expand_user(ZString path);  // Expand ~ and ~user to full home directory path
ZString cye_path_expand_vars(ZString path);  // Expand environment variables

int  cye_needs_rebuild_from_buf(const char *output_path, const char **input_paths, usz input_paths_count);

#define cye_needs_rebuild(output_path, ...)                    \
    cye_needs_rebuild_from_buf(                                \
        output_path, ((const char *[]){__VA_ARGS__}),          \
        (sizeof((const char *[]){__VA_ARGS__}) / sizeof(const char *)))



TString cye_path_temp_cwd(void);                                  // Get current working directory
bool cye_path_set_cwd(const char *path);                          // Change current working directory

b32  cye_file_exists(const char *file_path);
bool cye_file_stats(const char* path, Cye_File_Stats* stats);     // Get file stats, can use ctime() to get certain fields as strings
bool cye_is_absolute(ZString path);                               // Check if path  is absolute
bool cye_is_relative(ZString path);                               // Check if path  is relative
bool cye_is_file(ZString path);                                   // Check if path  is regular  file
bool cye_is_dir(ZString path);                                    // Check if path  is directory
bool cye_is_link(ZString path);                                   // Check if path  is symbolic link
bool cye_is_mount(ZString path);                                  // Check if path  is mount    point
bool cye_is_same_path(ZString path1, ZString path2);              // Check if paths reference same file (one can be absolute and another relative or on be a hard link)

Cye_DString cye_path_join(ZString path, ZString* paths);          // Join paths intelligently

usz cye_path_size(ZString path);                                  // Size  in bytes

ZString cye_path_real(ZString path);                              // Returns real path (resolve symlinks)
ZString cye_path_absolute(ZString path);                          // Returns absolute path
ZString cye_path_relative(ZString from, ZString target);          // Returns relative path

ZString cye_path_home(void);                                      //  Return home
ZString cye_path_cwd(void);                                       //  Return current directory
ZString cye_path_parent(ZString path);                            //  Returns parent directory
ZString cye_path_owner(ZString path);                             //  Returns parent directory
ZString cye_path_stem(ZString path);                              //  Return path without extension
ZString cye_path_dir_of(ZString file_path);                       //  Return directory where file is, if it's already an directory it return its self
ZString cye_path_ext(ZString path);                               //  Returns only the extension
bool    cye_path_touch(ZString path);                             //  Creates an empty file if not already exists

#define cye_make_dir  cye_make_dir_if_not_exists                  // Create directory
#define cye_make_dirs cye_make_dir_include_parents                // Create directory
bool cye_make_dir_include_parents(ZString path);                  // Create directories including parents as needed
bool cye_make_dir_include_parents_from_tstr(TString path);        // Create directories recursively

bool cye_remove_file(ZString path);                               // Remove file
bool cye_remove_dir(ZString path);                                // Remove directory
bool cye_remove_dirs(ZString path);                               // Remove directories recursively
bool cye_path_move(ZString src, ZString dst);                     // Move file or directory
bool cye_path_rename(ZString src, ZString dst);                   // Rename file or directory
bool cye_path_renames(ZString old_path, ZString new_path);        // Recursive directory or file renaming
bool cye_path_replace(ZString src, ZString dst);                  // Rename file or directory, replacing if exists
                                                                  // Paths valid for one func call much like TextFormat from Raylib
Cye_Path_DArray cye_path_scandir(ZString path);                   // Iterator of directory entries

// bool cye_path_walk                                              // Generate directory tree


//------------------------------------------------------------------------------------
//  Dynamic Array Declarations
//------------------------------------------------------------------------------------

#define cye_da_fmt         "{.count=%zu, .capacity=%zu}"
#define cye_da_fmt_arg(da) (da).count,   (da).capacity

// Append an item to a dynamic array using thread_local Cye_Context cye_context
#define cye_da_append(da, item)                                                            \
    do {                                                                                   \
        if ((da)->count >= (da)->capacity) {                                               \
            (da)->capacity = (da)->capacity == 0 ?                                         \
                CYE_DARRAY_INIT_CAP :                                                      \
                (da)->capacity*CYE_DARRAY_CAP_MULTIPLIER;                                  \
                                                                                           \
            (da)->items = cye_context.realloc(                                             \
                (da)->items, (da)->capacity*sizeof(((da)->items)[0])                       \
            );                                                                             \
            cye_assert((da)->items != NULL && "Dynamic Array: OOM");                       \
        }                                                                                  \
                                                                                           \
        (da)->items[(da)->count++] = (item);                                               \
    } while (0)

#define cye_da_free(da) cye_context.free((da).items)

#define cye_da_append_many(da, new_items, new_items_count)                                      \
    do {                                                                                        \
        if ((da)->count + (new_items_count) > (da)->capacity) {                                 \
            if ((da)->capacity == 0) {                                                          \
                (da)->capacity = CYE_DARRAY_INIT_CAP;                                           \
            }                                                                                   \
            while ((da)->count + (new_items_count) > (da)->capacity) {                          \
                (da)->capacity *= CYE_DARRAY_CAP_MULTIPLIER;                                    \
            }                                                                                   \
            (da)->items = cye_context.realloc((da)->items, (da)->capacity*sizeof(*(da)->items));\
            cye_assert((da)->items != NULL && "Dynamic Array: OOM");                            \
        }                                                                                       \
        memcpy((da)->items + (da)->count, (new_items), (new_items_count)*sizeof(*(da)->items)); \
        (da)->count += (new_items_count);                                                       \
    } while (0)


//------------------------------------------------------------------------------------
//  Slices Declarations
//------------------------------------------------------------------------------------


#define cye_slice_fmt "{.data=%p, .count=%zu}"
#define cye_slice_fmt_arg(slice)  slice.data, slice.count
// Generic slice structure
#define Cye_Slice(T) struct { T data; usz count; }

// Create a slice from an pointer and count
#define cye_slice_make(ptr, cnt) {.data = (ptr), .count = (cnt)}

// Create a slice from an array literal
#define cye_slice_from_arr(arr) cye_slice_make((arr), sizeof(arr)/sizeof((arr)[0]))

// Create an empty slice
#define cye_slice_empty(T) ((T)){.data = NULL, .count = 0}
#define CYE_STR_SLICE_EMPTY (const Cye_String_Slice){.data = NULL, .count = 0}

// Get subslice [start, end)
#define cye_slice_range(ptr, start, end) \
    cye_slice_make(ptr + (start), ((end) - (start)))

// Get first n elements
#define cye_slice_prefix(ptr, n) \
    cye_slice_make(ptr, (n))

// Get last n elements
#define cye_slice_suffix(slice, n) \
    cye_slice_make((slice).data + ((slice).count - (n)), (n))

// Compare two slices
#define cye_slice_equal(a, b) \
    (((a).count == (b).count) && \
     (memcmp((a).data, (b).data, (a).count * sizeof(*(a).data)) == 0))

// Check if slice contains element
#define cye_slice_contains(slice, elem) ({ \
    bool found = false; \
    for(usz i = 0; i < (slice).count; i++) { \
        if ((slice).data[i] == (elem)) { \
            found = true; \
            break; \
        } \
    } \
    found; \
})

// Check if slice is empty
#define cye_slice_is_empty(slice) ((slice).count == 0)

// Get element at index with bounds checking
#define cye_slice_at(slice, idx) \
    (((idx) < (slice).count) ? (slice).data[idx] : NULL)

// Copy slice to buffer
#define cye_slice_copy(dst, src) \
    memcpy((dst).data, (src).data, (src).count * sizeof(*(src).data))

// Find index of element
#define cye_slice_index_of(slice, elem) ({ \
    usz idx = (usz)-1; \
    for(usz i = 0; i < (slice).count; i++) { \
        if ((slice).data[i] == (elem)) { \
            idx = i; \
            break; \
        } \
    } \
    idx; \
})

//------------------------------------------------------------------------------------
//  String Slice Declarations
//------------------------------------------------------------------------------------

#define cye_ss_fmt "%.*s"
#define cye_ss_fmt_arg(sv) (int)(sv).count, (sv).data


Cye_String_Slice cye_str_slice_make(const char *str);

// Trim whitespace from both ends
Cye_String_Slice cye_str_slice_trim(Cye_String_Slice s);

// String slice to null-terminated string (requires buffer)
void cye_str_slice_to_zstr(Cye_String_Slice s, char *buf, usz buf_size);

// Strip left whitespace
Cye_String_Slice cye_str_slice_strip_left(Cye_String_Slice s);

// Strip right whitespace
Cye_String_Slice cye_str_slice_strip_right(Cye_String_Slice s);

// Create string slice from string and explicit length
Cye_String_Slice cye_str_slice_make_len(const char *str, usz len);

// Compare two string slices
bool cye_str_slice_equals(Cye_String_Slice a, Cye_String_Slice b);

// Check if string slice contains substring
bool cye_str_slice_contains(Cye_String_Slice haystack, Cye_String_Slice needle);

// Split string slice by delimiter into a Dynamic Array
Cye_String_Slice_DArray cye_str_slice_split(Cye_String_Slice s, Cye_String_Slice delim);

// Split string slice at first occurrence of delimiter
void cye_str_slice_split_first(Cye_String_Slice s, char delim, Cye_String_Slice *before, Cye_String_Slice *after);

// Check if string slice starts with prefix
bool cye_str_slice_starts_with(Cye_String_Slice s, Cye_String_Slice prefix);

// Check if string slice ends with suffix
bool cye_str_slice_ends_with(Cye_String_Slice s, Cye_String_Slice suffix);

// Check if string slice ends with zero-terminated suffix
bool cye_str_slice_ends_with_zstr(Cye_String_Slice s, ZString suffix);

// Check if string slice starts with zero-terminated prefix
bool cye_str_slice_starts_with_zstr(Cye_String_Slice s, ZString prefix);

//------------------------------------------------------------------------------------
//  ZString Declarations
//------------------------------------------------------------------------------------

bool cye_zstr_ends_with(ZString src, ZString ending);
bool cye_zstr_starts_with(ZString src, ZString prefix);

// TODO: Add String Slices Functions as we need


//----------------------------------------------------------------------------------
//  Dynamic String Declarations
//----------------------------------------------------------------------------------

// Don't need to null terminate to see the dynamic string
#define cye_ds_fmt "{.items=%.*s(%p), .count=%zu, .capacity=%zu}"
#define cye_ds_fmt_arg(ds) (ds).count, (ds).items, (ds).items, (ds).count, (ds).capacity

#define cye_ds_write_buf(ds, buf, size) cye_da_append_many(ds, buf, size)

#define cye_ds_write_zstr(ds, zstr)   \
    do {                              \
        const char *s = (zstr);       \
        usz n = strlen(s);            \
        cye_da_append_many(ds, s, n); \
    } while (0)

#define cye_ds_write(ds, ...)                                               \
    do {                                                                    \
        const char *cye_tmp_strs[] = {__VA_ARGS__};                         \
        for (usz idx = 0;                                                   \
             idx < sizeof(cye_tmp_strs) / sizeof(cye_tmp_strs[0]);          \
             idx++)                                                         \
        {                                                                   \
            const char *s = cye_tmp_strs[idx];                              \
            usz n = strlen(s);                                              \
            cye_da_append_many(ds, s, n);                                   \
        }                                                                   \
    } while (0)

#define cye_ds_write_char(ds, ch) \
    cye_da_append(ds, ch)

// Write zero byte onto the Dynamic String
#define cye_ds_write_zero(ds) cye_ds_write_char(ds, '\0')

// Free the memory allocated by the Dynamic String
#define cye_ds_free(ds) cye_da_free(ds)

// Formated Print onto the Dynamic String
void cye_ds_printf(Cye_DString *ds, ZString fmt, ...);


//----------------------------------------------------------------------------------
//  Mathematics Declarations
//----------------------------------------------------------------------------------
#ifndef cye_max
#   define cye_max(value1, value2) ((value1) > (value2)) ? (value1) : (value2);
#endif

#ifndef cye_min
#   define cye_min(value1, value2) ((value1) < (value2)) ? (value1) : (value2);
#endif

// Clamp float value
f32 cye_clamp(f32 value, f32 min, f32 max);

// Calculate linear interpolation between two floats
f32 cye_lerp(f32 start, f32 end, f32 amount);

// Normalize input value within input range
f32 cye_normalize(f32 value, f32 start, f32 end);

// Remap input value within input range to output range
f32 cye_remap(f32 value, f32 inputStart, f32 inputEnd, f32 outputStart, f32 outputEnd);

// Wrap input value from min to max
f32 cye_wrap(f32 value, f32 min, f32 max);

// Check whether two given f32s are almost equal
int cye_float_equals(f32 x, f32 y);


//------------------------------------------------------------------------------------
//  Utils Declarations
//------------------------------------------------------------------------------------
void cye_set_trace_level(Cye_Log_Level level);
void cye_trace_log(Cye_Log_Level level, const char *fmt, ...);
#define cye_trace_info(...)  cye_trace_log(CYE_LOG_INFO,    __VA_ARGS__)
#define cye_trace_okay(...)  cye_trace_log(CYE_LOG_OKAY,    __VA_ARGS__)
#define cye_trace_error(...) cye_trace_log(CYE_TRACE_ERROR,   __VA_ARGS__)
#define cye_trace_warn(...)  cye_trace_log(CYE_LOG_WARNING, __VA_ARGS__)
#define cye_trace_fatal(...) cye_trace_log(CYE_LOG_FATAL,   __VA_ARGS__)

#define cye_return_defer(code) do { code; goto defer; } while(0)
#define cye_result_defer(value) do { result = (value); goto defer; } while(0)

// Consider using logging instead ? Maybe not
#define cye_todo(msg)        do { fprintf(stderr, "%s:%d: %s TODO: %s\n",       __FILE__, __LINE__,__PRETTY_FUNCTION__,  msg); abort(); } while(0)
#define cye_unreachable(msg) do { fprintf(stderr, "%s:%d: %s UNREACHABLE: %s\n",__FILE__, __LINE__,__PRETTY_FUNCTION__,  msg); abort(); } while(0)
#define cye_panic(msg)       do { fprintf(stderr, "%s:%d: %s PANIC: " msg "\n",__FILE__, __LINE__,__PRETTY_FUNCTION__); abort(); } while(0)

#define cye_not_implemented(msg)    cye_assert_msg(false, msg)

#define cye_shift(items, items_sz)  (cye_assert_msg(((items_sz) > 0), "%s", "Shift WAY TOO MUCH"), (items_sz) -= 1, *(items)++)

void cye__assert_handler(char const *prefix, char const *condition, char const *file, int line, char const *msg, ...);

#ifndef cye_assert_msg
#define cye_assert_msg(cond, msg, ...) \
    ((void)((cond) || \
        (cye__assert_handler("Assertion Failure", #cond, __FILE__, \
                          (int)__LINE__, msg, ##__VA_ARGS__), \
         DEBUG_TRAP(), \
         0)))
#endif

#ifndef cye_assert
#   define cye_assert(cond) cye_assert_msg(cond, NULL)
#endif

#define cye_file_fmt "%s:%d:%s"
#define cye_file_fmt_arg __FILE__, __LINE__,__PRETTY_FUNCTION__

#define cye_file_stats_fmt "{.created_at=%s (%zu), .accessed_at=%s (%zu), .modified_at=%s (%zu), .size=%zu (bytes)}"
#define cye_file_stats_fmt_arg(stats)                \
    strtok(ctime(&(stats).created_at), "\n"),  (stats).created_at, \
    strtok(ctime(&(stats).accessed_at), "\n"), (stats).accessed_at,\
    strtok(ctime(&(stats).modified_at), "\n"), (stats).modified_at,\
    (stats).size_bytes



const char *cye_cpu_architecture(void);

#endif // _CYE_H_



/*..................................................................................
 .                                                                                 .
 .                                IMPLEMENETATION                                  .
 .                                                                                 .
 ...................................................................................
*/
#if defined(CYE_IMPLEMENTATION)

//------------------------------------------------------------------------------------
//  Global Variables Implementation
//------------------------------------------------------------------------------------

static struct {
    usz size;
    rawptr last;  // Last pointer of a successful allocation, used in `trealloc`
    byte buffer[CYE_TEMP_CAPACITY];
} cye_temp_data = {0};

static Cye_Log_Level cye_threshold_log_level = CYE_LOG_INFO;

thread_local Cye_Context cye_context = {.alloc = cye_malloc, .realloc = cye_realloc, .free = cye_free, .any=null};

//------------------------------------------------------------------------------------
//  Process and File Implementation
//------------------------------------------------------------------------------------

#ifdef _WIN32
#   define CYE_GET_ERROR_STRING (cye__win32_error_message(GetLastError()))
#else
#   define CYE_GET_ERROR_STRING (strerror(errno))
#endif


Cye_File_Handle cye_file_open_for_write(ZString path) {
#ifndef _WIN32
    Cye_File_Handle result = open(path,
        O_WRONLY | O_CREAT | O_TRUNC,
        S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH
    );

    if (result < 0) {
        cye_trace_log(CYE_TRACE_ERROR, "Could not open file %s: %s", path, CYE_GET_ERROR_STRING);
        return CYE_INVALID_FILE_HANDLE;
    }
    return result;

#else
    SECURITY_ATTRIBUTES saAttr = {0};
    saAttr.nLength = sizeof(SECURITY_ATTRIBUTES);
    saAttr.bInheritHandle = TRUE;

    Cye_File_Handle result = CreateFile(
        path,                            // name of the write
        GENERIC_WRITE,                   // open for writing
        0,                               // do not share
        &saAttr,                         // default security
        OPEN_ALWAYS,                     // open always
        FILE_ATTRIBUTE_NORMAL,           // normal file
        NULL                             // no attr. template
    );

    if (result == INVALID_HANDLE_VALUE) {
        cye_trace_log(CYE_TRACE_ERROR, "Could not open file %s: %s", path, CYE_GET_ERROR_STRING);
        return CYE_INVALID_FILE_HANDLE;
    }

    return result;
#endif // _WIN32
}
void cye_file_close(Cye_File_Handle handle) {
#ifndef _WIN32
    close(handle);
#else
    CloseHandle(handle);
#endif // _WIN32
}

bool cye_process_wait_all(Cye_Process_DArray procs) {
    bool success = true;
    // TODO: Maybe sucess && fn() instead of fu() && sucess?
    for (usz i = 0; i < procs.count; ++i) {
        success = cye_process_wait(procs.items[i]) && success;
    }
    return success;
}

bool cye_process_wait_all_and_reset(Cye_Process_DArray *procs) {
    bool success = cye_process_wait_all(*procs);
    procs->count = 0;
    return success;
}

// Wait until the process has finished
bool cye_process_wait(Cye_Process proc) {

    if (proc == CYE_INVALID_PROCESS)  {
        return false;
    }

#ifndef _WIN32
    for (;;) {
        int wstatus = 0;
        if (waitpid(proc, &wstatus, 0) < 0) {
            cye_trace_log(CYE_TRACE_ERROR, "Could not wait on command (pid %d): %s", proc, CYE_GET_ERROR_STRING);
            return false;
        }

        if (WIFEXITED(wstatus)) {
            int exit_status = WEXITSTATUS(wstatus);
            if (exit_status != 0) {
                cye_trace_log(CYE_TRACE_ERROR, "Command exited with exit code %d", exit_status);
                return false;
            }
            break;
        }

        if (WIFSIGNALED(wstatus)) {
            cye_trace_log(CYE_TRACE_ERROR, "Command process was terminated by %s", strsignal(WTERMSIG(wstatus)));
            return false;
        }
    }
    return true;
#else
    DWORD result = WaitForSingleObject(
        proc,    // HANDLE hHandle,
        INFINITE // DWORD  dwMilliseconds
    );

    if (result == WAIT_FAILED) {
        cye_trace_log(CYE_TRACE_ERROR, "Could not wait on child process: %s", nob_win32_error_message(GetLastError()));
        return false;
    }

    DWORD exit_status;
    if (!GetExitCodeProcess(proc, &exit_status)) {
        cye_trace_log(CYE_TRACE_ERROR, "Could not get process exit code: %s", nob_win32_error_message(GetLastError()));
        return false;
    }

    if (exit_status != 0) {
        cye_trace_log(CYE_TRACE_ERROR, "Command exited with exit code %lu", exit_status);
        return false;
    }

    CloseHandle(proc);

    return true;
#endif
}

//------------------------------------------------------------------------------------
//  Commands Functions Implementation
//------------------------------------------------------------------------------------
void cye_ds_write_cmd(Cye_DString *ds, Cye_Command cmd) {
    for (usz i = 0; i < cmd.count; ++i) {
        const char *arg = cmd.items[i];
        if (arg == NULL) break;
        if (i > 0) cye_ds_write_zstr(ds, " ");
        if (!strchr(arg, ' ')) {
            cye_ds_write_zstr(ds, arg);
        } else {
            cye_da_append(ds, '\'');
            cye_ds_write_zstr(ds, arg);
            cye_da_append(ds, '\'');
        }
    }
}

// Run redirected command asynchronously
Cye_Process cye_cmd_run_async_and_reset(Cye_Command *cmd) {
    Cye_Process proc = cye_cmd_run_async(*cmd);
    cmd->count = 0;
    return proc;
}


// Run redirected command asynchronously and reset count
Cye_Process cye_cmd_run_async_redirect(Cye_Command cmd, Cye_Command_Redirect redirect) {
    if (cmd.count < 1) {
        cye_trace_error("Could not run empty command");
        return CYE_INVALID_PROCESS;
    }

    Cye_DString sb = {0};
    cye_ds_write_cmd(&sb, cmd);
    cye_ds_write_zero(&sb);
    cye_trace_info("CMD: %s", sb.items);
    cye_ds_free(sb);
    memset(&sb, 0, sizeof(sb));

#if !defined(_WIN32) // Unix
    pid_t cpid = fork();
    if (cpid < 0) {
        cye_trace_error("Could not fork child process: %s", CYE_GET_ERROR_STRING);
        return CYE_INVALID_PROCESS;
    }

    if (cpid == 0) {
        if (redirect.in) {
            if (dup2(*redirect.in, STDIN_FILENO) < 0) {
                cye_trace_error("Could not setup stdin for child process: %s", CYE_GET_ERROR_STRING);
                exit(1);
            }
        }

        if (redirect.out) {
            if (dup2(*redirect.out, STDOUT_FILENO) < 0) {
                cye_trace_error("Could not setup stdout for child process: %s", CYE_GET_ERROR_STRING);
                exit(1);
            }
        }

        if (redirect.err) {
            if (dup2(*redirect.err, STDERR_FILENO) < 0) {
                cye_trace_error("Could not setup stderr for child process: %s", CYE_GET_ERROR_STRING);
                exit(1);
            }
        }

        // NOTE: This leaks a bit of memory in the child process.
        // But do we actually care? It's a one off leak anyway...
        Cye_Command cmd_null = {0};
        cye_da_append_many(&cmd_null, cmd.items, cmd.count);
        cye_cmd_append(&cmd_null, NULL);

        if (execvp(cmd.items[0], (char * const*) cmd_null.items) < 0) {
            cye_trace_error("Could not exec child process: %s", CYE_GET_ERROR_STRING);
            exit(1);
        }
        cye_unreachable("nob_cmd_run_async_redirect");
    }

    return cpid;
#else
    // https://docs.microsoft.com/en-us/windows/win32/procthread/creating-a-child-process-with-redirected-input-and-output

    STARTUPINFO siStartInfo;
    ZeroMemory(&siStartInfo, sizeof(siStartInfo));
    siStartInfo.cb = sizeof(STARTUPINFO);
    // NOTE: theoretically setting NULL to std handles should not be a problem
    // https://docs.microsoft.com/en-us/windows/console/getstdhandle?redirectedfrom=MSDN#attachdetach-behavior
    // TODO: check for errors in GetStdHandle
    siStartInfo.hStdError = redirect.err ? *redirect.err : GetStdHandle(STD_ERROR_HANDLE);
    siStartInfo.hStdOutput = redirect.out ? *redirect.out : GetStdHandle(STD_OUTPUT_HANDLE);
    siStartInfo.hStdInput = redirect.in ? *redirect.in : GetStdHandle(STD_INPUT_HANDLE);
    siStartInfo.dwFlags |= STARTF_USESTDHANDLES;

    PROCESS_INFORMATION piProcInfo;
    ZeroMemory(&piProcInfo, sizeof(PROCESS_INFORMATION));

    // TODO: use a more reliable rendering of the command instead of cmd_render
    // cmd_render is for logging primarily
    cye_ds_write_cmd(&sb, cmd);
    cye_ds_write_zero(&sb);
    BOOL bSuccess = CreateProcessA(NULL, sb.items, NULL, NULL, TRUE, 0, NULL, NULL, &siStartInfo, &piProcInfo);
    cye_ds_free(sb);

    if (!bSuccess) {
        cye_trace_error("Could not create child process: %s", nob_win32_error_message(GetLastError()));
        return CYE_INVALID_PROCESS;
    }

    CloseHandle(piProcInfo.hThread);

    return piProcInfo.hProcess;
#endif
}

// Run redirected command asynchronously and set cmd.count to 0 and close all the opened files
Cye_Process cye_cmd_run_async_redirect_and_reset(Cye_Command *cmd, Cye_Command_Redirect redirect) {
    Cye_Process proc = cye_cmd_run_async_redirect(*cmd, redirect);
    cmd->count = 0;
    if (redirect.in) {
        cye_file_close(*redirect.in);
        *redirect.in = CYE_INVALID_FILE_HANDLE;
    }
    if (redirect.out) {
        cye_file_close(*redirect.out);
        *redirect.out = CYE_INVALID_FILE_HANDLE;
    }
    if (redirect.err) {
        cye_file_close(*redirect.err);
        *redirect.err = CYE_INVALID_FILE_HANDLE;
    }
    return proc;
}

// Run command synchronously
bool cye_cmd_run_sync(Cye_Command cmd) {
    Cye_Process proc = cye_cmd_run_async(cmd);
    if (proc == CYE_INVALID_PROCESS) {
        return false;
    }
    return cye_process_wait(proc);
}

bool cye_cmd_run_sync_and_reset(Cye_Command *cmd) {
    bool ok = cye_cmd_run_sync(*cmd);
    cmd->count = 0;
    return ok;
}

// Run redirected command synchronously
bool cye_cmd_run_sync_redirect(Cye_Command cmd, Cye_Command_Redirect redirect);

// Run redirected command synchronously and set cmd.count to 0 and close all the opened files
bool cye_cmd_run_sync_redirect_and_reset(Cye_Command *cmd, Cye_Command_Redirect redirect);


// The implementation idea is stolen from https://github.com/zhiayang/nabs
void cye__rebuild_ourselves(ZString source_path, int argc, ZString *argv) {
    const char *binary_path = cye_shift(argv, argc);
#ifdef _WIN32
    // On Windows executables almost always invoked without extension, so
    // it's ./nob, not ./nob.exe. For renaming the extension is a must.
    if (!cye_zstr_ends_with(binary_path, ".exe")) {
        binary_path = cye_tprintf("%s.exe", binary_path);
    }
#endif

    int rebuild_is_needed = cye_needs_rebuild(binary_path, source_path, __FILE__);
    if (rebuild_is_needed < 0) {
        exit(1);
    }
    if (!rebuild_is_needed) {
        return;
    }

    Cye_Command cmd = {0};

    const char *old_binary_path = cye_tprintf("%s.old", binary_path);

    if (!cye_path_rename(binary_path, old_binary_path)) {
        exit(1);
    }

    cye_cmd_append(&cmd, cye_rebuild_command(binary_path, source_path));
    if (!cye_cmd_run_sync_and_reset(&cmd)) {
        cye_path_rename(old_binary_path, binary_path);
        exit(1);
    }

    cye_cmd_append(&cmd, binary_path);
    cye_da_append_many(&cmd, argv, argc);
    if (!cye_cmd_run_sync_and_reset(&cmd)) {
        exit(1);
    }

    exit(0);
}



//------------------------------------------------------------------------------------
//  Storage Functions Implementation
//------------------------------------------------------------------------------------

Cye_Context cye_temp_context(void) {
    // Gets whatever was in the cye_context.any
    return cliteral(Cye_Context){.alloc = cye_talloc, .realloc = cye_trealloc, .free = cye_tfree, cye_context.any};
}

Cye_Context cye_default_context(void) {
    return cliteral(Cye_Context){.alloc = cye_malloc, .realloc = cye_realloc, .free = cye_free, .any=null};
}

u0 cye_set_default_context(Cye_Context ctx) {
    unused(ctx);
    cye_panic("YAY");
}

TString cye_tstrdup(const char *cstr) {
    usz n = strlen(cstr);
    TString result = (TString)cye_talloc(n + 1);
    cye_assert(result != NULL && "Please increase CYE_TEMP_CAPACITY");
    memcpy(result, cstr, n);
    result[n] = '\0';
    return result;
}


// TODO: Check out arena allocator
rawptr cye_talloc(usz size) {

    if (cye_temp_data.size + size > CYE_TEMP_CAPACITY) return NULL;
    rawptr result = &cye_temp_data.buffer[cye_temp_data.size];
    cye_temp_data.last  = result;
    cye_temp_data.size += size;
    return result;
}

void *cye_trealloc(void *ptr, usz size) {
    if (ptr == null) {
        // `talloc` already sets the last pointer
        return cye_talloc(size);
    }

    if (size == 0) {
        return null;
    }
    // If ptr is NULL or it's not from our temp buffer, just do a new allocation
    if ((byte*)ptr <   cye_temp_data.buffer
     || (byte*)ptr >= (cye_temp_data.buffer + CYE_TEMP_CAPACITY))
    {
        cye_trace_fatal(
            "Trying to realloc investigate this behaviour"
            "You might have allocate with one context than changed the context and reallocated with something else"
            "This might indicate that you need to either note realloc instead to the memcpy your self since you probably already"
            "know how much data the pointer points to. (temporary allocator does not)"
        );
        cye_unreachable("FATAL"); // Maybe it shouldn't be? But good for me to find bugs

        // `talloc` already sets the last pointer
        return cye_talloc(size);;
    }

    // Check if ptr is the last allocation by seeing if it points to
    // the position right after our previous allocations
    if (ptr == cye_temp_data.last) {
        cye_trace_log(CYE_LOG_TRACE, "Reallocation done on pointer from last allocation");
        // Make sure we don't exceed buffer capacity
        if ((byte*)ptr + size > cye_temp_data.buffer + CYE_TEMP_CAPACITY) {
            cye_trace_log(CYE_LOG_WARNING, "Reallocation returns exceeds CYE_TEMP_CAPACITY=%zu", CYE_TEMP_CAPACITY);
            return NULL;
        }

        // Adjust total size
        cye_temp_data.size = ((byte*)ptr - cye_temp_data.buffer) + size;
        return ptr;
    }

    // Otherwise, allocate new space. `talloc` already sets the last pointer
    void *new_ptr = cye_talloc(size);
    cye_trace_log(CYE_LOG_TRACE, "Reallocation done from different pointer from last allocation. (pointer=%p != last_pointer=%p)(new_ptr=%p)", ptr, cye_temp_data.last, new_ptr);
    if (new_ptr) {
        // Calculate how much data we can safely copy, techinacally should be all of it
        // Because talloc doesn't let us allocate partially, but whatever
        usz remaining_space = cye_temp_data.buffer + CYE_TEMP_CAPACITY - (byte*)ptr;
        usz copy_size = size;
        if (size > remaining_space) {
            copy_size = remaining_space;
            cye_trace_warn("Wanted %zu bytes but can only give %zu to not exceed %d CYE_TEMP_CAPACITY", size, remaining_space, CYE_TEMP_CAPACITY);
        }
        memcpy(new_ptr, ptr, copy_size);
    }

    return new_ptr;
}

void cye_tfree(rawptr ptr) {
    cye_trace_log(CYE_LOG_TRACE, "Temporary allocator freed");
}

// TODO: Function to generate default Wanings for each compiler maybe, and output binary path?
TString cye_tprintf(ZString fmt, ...) {
    va_list args;
    va_start(args, fmt);
    int n = vsnprintf(NULL, 0, fmt, args);
    va_end(args);


    cye_assert(n >= 0);
    char *result = cye_talloc(n + 1);

    cye_assert(result != NULL && "Extend the size of the temporary allocator");

    // TODO: use proper arenas for the temporary allocator;
    va_start(args, fmt);
    vsnprintf(result, n + 1, fmt, args);
    va_end(args);

    return result;
}

void  cye_temp_reset(void) {
    cye_temp_data.size = 0;
}

usz cye_temp_save(void) {
    return cye_temp_data.size;
}

void cye_temp_rewind(usz checkpoint) {
    cye_temp_data.size = checkpoint;
}


//------------------------------------------------------------------------------------
//  Path Functions Implementation
//------------------------------------------------------------------------------------

bool cye_make_dir_if_not_exists(const char *path) {
#ifdef _WIN32
    int result = mkdir(path);
#else
    int result = mkdir(path, 0755);
#endif
    if (result < 0) {
        if (errno == EEXIST) {
            cye_trace_info("directory `%s` already exists", path);
            return true;
        }
        cye_trace_error("could not create directory `%s`: %s", path, CYE_GET_ERROR_STRING);
        return false;
    }

    cye_trace_info("created directory `%s`", path);
    return true;
}

bool cye_copy_file(const char *src_path, const char *dst_path) {
    cye_todo("VAI TRABALHAR VAGABUNDO");
}

bool cye_copy_dir(const char *src_path, const char *dst_path) {
    bool result = true;
    Cye_Path_DArray children = {0};
    Cye_DString src_ds = {0};
    Cye_DString dst_ds = {0};
    usz temp_checkpoint = cye_temp_save();

    Cye_File_Type type = cye_path_file_type(src_path);
    if (type < 0) return false;

    switch (type) {
        case CYE_FILE_TYPE_DIRECTORY: {
            if (!cye_make_dir(dst_path)) cye_result_defer(false);
            if (!cye_read_entire_dir(src_path, &children)) cye_result_defer(false);

            for (usz i = 0; i < children.count; ++i) {
                if (strcmp(children.items[i], ".") == 0) continue;
                if (strcmp(children.items[i], "..") == 0) continue;

                src_ds.count = 0;
                cye_ds_write(&src_ds, src_path, "/", children.items[i]);
                cye_ds_write_zero(&src_ds);

                dst_ds.count = 0;
                cye_ds_write(&dst_ds, dst_path);
                cye_ds_write(&dst_ds, "/");
                cye_ds_write(&dst_ds, children.items[i]);
                cye_ds_write_zero(&dst_ds);

                if (!cye_copy_dir(src_ds.items, dst_ds.items)) {
                    cye_result_defer(false);
                }
            }
        } break;

        case CYE_FILE_TYPE_REGULAR: {
            if (!cye_copy_file(src_path, dst_path)) {
                cye_result_defer(false);
            }
        } break;

        case CYE_FILE_TYPE_SYMLINK: {
            cye_trace_warn("TODO: Copying symlinks is not supported yet");
        } break;

        case CYE_FILE_TYPE_OTHER: {
            cye_trace_error("Unsupported type of file %s", src_path);
            cye_result_defer(false);
        } break;

        default: cye_unreachable("nob_copy_directory_recursively");
    }

defer:
    cye_temp_rewind(temp_checkpoint);
    cye_da_free(src_ds);
    cye_da_free(dst_ds);
    cye_da_free(children);
    return result;
}

bool cye_read_entire_dir(const char *parent, Cye_Path_DArray *children) {
    cye_todo("VAI TRABALHAR VAGABUNDO");
}


// TODO: Check this for windows
bool cye_write_entire_file(const char *path, const void *data, usz size) {
    bool result = true;

    FILE *f = fopen(path, "wb");
    if (f == NULL) {
        cye_trace_error("Could not open file %s for writing: %s\n", path, strerror(errno));
        cye_result_defer(false);
    }

    //           len
    //           v
    // aaaaaaaaaa
    //     ^
    //     data

    const char *buf = data;
    while (size > 0) {
        size_t n = fwrite(buf, 1, size, f);
        if (ferror(f)) {
            cye_trace_error("Could not write into file %s: %s\n", path, strerror(errno));
            cye_result_defer(false);
        }
        size -= n;
        buf  += n;
    }

defer:
    if (f) fclose(f);
    return result;
}

// TODO: Check this for windows
bool cye_read_entire_file(const char *path, Cye_DString *ds) {
    bool result = true;

    FILE *f = fopen(path, "rb");
    if (f == NULL)                 cye_result_defer(false);
    if (fseek(f, 0, SEEK_END) < 0) cye_result_defer(false);
    long m = ftell(f);
    if (m < 0)                     cye_result_defer(false);
    if (fseek(f, 0, SEEK_SET) < 0) cye_result_defer(false);

    usz new_count = ds->count + m;
    if (new_count > ds->capacity) {
        ds->items = cye_context.realloc(ds->items, new_count);
        cye_assert(ds->items != NULL && "Please, you'll need to acquire more random access memory ");
        ds->capacity = new_count;
    }

    fread(ds->items + ds->count, m, 1, f);
    // If no error has occurred on stream, ferror return 0
    int error_value = ferror(f);
    if (error_value != 0) {
        cye_trace_error("Could not read file %s: ferror error value is %d", path, error_value);
        result = false;
        goto close;
    }
    ds->count = new_count;

defer:
    if (!result) cye_trace_error("Could not read file %s: %s", path, strerror(errno));
close:
    if (f) fclose(f);
    return result;
}

Cye_File_Type cye_path_file_type(const char *path) {
#ifndef _WIN32
    struct stat statbuf;
    if (stat(path, &statbuf) < 0) {
        cye_trace_error("Could not get stat of %s: %s", path, strerror(errno));
        return -1;
    }

    switch (statbuf.st_mode & S_IFMT) {
        case S_IFDIR:  return CYE_FILE_TYPE_DIRECTORY;
        case S_IFREG:  return CYE_FILE_TYPE_REGULAR;
        case S_IFLNK:  return CYE_FILE_TYPE_SYMLINK;
        default:       return CYE_FILE_TYPE_OTHER;
    }
#else // _WIN32
    DWORD attr = GetFileAttributesA(path);
    if (attr == INVALID_FILE_ATTRIBUTES) {
        cye_trace_error("Could not get file attributes of %s: %lu", path, GetLastError());
        return -1;
    }

    if (attr & FILE_ATTRIBUTE_DIRECTORY) return CYE_FILE_TYPE_DIRECTORY;
    // TODO: detect symlinks on Windows (whatever that means on Windows anyway)
    return CYE_FILE_TYPE_REGULAR;
#endif // _WIN32
}

char* cye_path_temp_normalize(ZString path) {
    // 1 extra for the path separator in the end and another 1 byte for null terminator
    usz path_count  = strlen(path);
    usz total_count = path_count + 1 + 1;

    // Allocate memory for the final path
    Cye_DString ds = {
        .items = cye_talloc(total_count),
        .count = 0,
        .capacity = total_count
    };

    // Removing repeated separators
    for (usz idx = 0; idx < path_count; ++idx) {

        bool is_next_end = (idx + 1) == (path_count);
        bool is_prev_sep = ds.count > 0 && (ds.items[ds.count-1] == PATH_SEPARATOR_CHAR);
        bool is_next_sep = ((idx + 1) < path_count) && (path[idx + 1] == PATH_SEPARATOR_CHAR);
        bool is_curr_dot = path[idx] ==  '.';

        if (is_prev_sep && (is_next_end || is_next_sep) && is_curr_dot) {
            idx += 1;
            continue;
        }

        bool is_curr_sep = path[idx] == PATH_SEPARATOR_CHAR;
        if (!(is_curr_sep && is_prev_sep)) {
            cye_ds_write_char(&ds, path[idx]);
        }
    }

    // Special .. must end with trailing PATH_SEP, we must have
    if (ds.count >= 2
        && ('.' == ds.items[ds.count-1])
        && ('.' == ds.items[ds.count-2]))
    {
        // 2th case: Don't need to check for >= 3 and it fails in ds.count == 2
        if (ds.count == 2 || PATH_SEPARATOR_CHAR == ds.items[ds.count-3]) {
            cye_ds_write(&ds, PATH_SEPARATOR);
        }
    } else if (ds.count == 1 && '.' == ds.items[ds.count-1]) {
        cye_ds_write(&ds, PATH_SEPARATOR);
    }

    cye_ds_write_zero(&ds);

    // Should have been an upperbound on allocated memory, it should never have grown
    if (ds.capacity > total_count) {
        cye_trace_error(
            "Allocating memory for the dynamic string is an error path=%s total_count=%zu ds="cye_ds_fmt".\n"
            "All memory should have been talloc",
            path,
            total_count,
            cye_ds_fmt_arg(ds)
        );
        cye_panic();
    }

    return ds.items;
}

char* cye_path_create_from_array(ZString paths[], usz paths_count) {
    Cye_Context ctx = cye_context;

    usz total_count = 0;
    usz traling_empty_count = 0;
    for (usz i = 0; i < paths_count; i++) {
        usz len = strlen(paths[i]);
        total_count += len;
        if (len == 0) {
            traling_empty_count += 1;
        } else {
            traling_empty_count = 0;
        }
        cye_trace_log(CYE_LOG_TRACE, "path[%d/%d] = %s", i, paths_count-1, paths[i]);
    }

    paths_count = paths_count - traling_empty_count;

    // Allocate memory for the final path with context, so user can decide where to allocate this
    Cye_DString ds = {
        .items = ctx.alloc(total_count + paths_count + 1),
        .count = 0,
        .capacity = total_count + paths_count + 1
    };

    // Concatenate the paths
    for (usz i = 0; i < paths_count; i++) {
        cye_ds_write(&ds, paths[i]);
        if (i < (paths_count-1) && ds.count > 0 && (ds.items[ds.count-1] != PATH_SEPARATOR_CHAR)) {
            cye_ds_write(&ds, PATH_SEPARATOR);
        }
    }
    cye_ds_write_zero(&ds);

    {
        usz chk_point = cye_temp_save();
        TString tpath = cye_path_temp_normalize(ds.items);
        // `strncpy` doesn't consider '\0'. It'd be nice to consider both `n` and char `'\0'`.
        strcpy(ds.items, tpath);
        cye_temp_rewind(chk_point);
    }

    return ds.items;
}

ZString cye_path_base_name(ZString path) {
#ifndef _WIN32
    ZString p = strrchr(path, '/');
    return p ? p + 1 : path;
#else
    ZString p1 = strrchr(path, '/');
    ZString p2 = strrchr(path, '\\');
    ZString p =
        (p1 > p2) ? p1
                  : p2;  // NULL is ignored if the other search is successful
    return p ? p + 1 : path;
#endif  // _WIN32
}

// Expand ~ and ~user to full home directory path
// @Leak: maybe make temp? or provide the DString to write to
// @Check: Sanity check every thing
ZString cye_path_expand_user(ZString path) {
    if (!path || path[0] != '~') return path;

    Cye_DString result = {0};
    usz path_len = strlen(path);

#ifdef _WIN32
    // On Windows, we'll only handle plain ~ (no ~user support)
    if (path[1] != '\0' && path[1] != '/' && path[1] != '\\') {
        return path;
    }

    char home_path[MAX_PATH];
    if (SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_PROFILE, NULL, 0, home_path))) {
        cye_ds_write(&result, home_path);

        // Add the rest of the path (skip the ~)
        if (path[1] != '\0') {
            // If path uses forward slashes, convert home_path backslashes to forward slashes
            if (strchr(path, '/')) {
                for (char* p = result.items; *p; p++) {
                    if (*p == '\\') *p = '/';
                }
            }
            cye_ds_write(&result, path + 1);
        }

        return result.items;
    }

    // Fallback to USERPROFILE environment variable
    const char* user_profile = getenv("USERPROFILE");
    if (user_profile) {
        cye_ds_write(&result, user_profile);
        if (path[1] != '\0') {
            cye_ds_write(&result, path + 1);
        }
        return result.items;
    }
#else
    // Find the end of the username or ~ if no username
    const char* path_separator = strchr(path, '/');
    usz username_len = path_separator ? (size_t)(path_separator - path - 1) :
                         (path_len > 1 ? path_len - 1 : 0);

    const char* home_dir = NULL;

    if (username_len == 0) {
        // Plain ~ - use current user's home
        home_dir = getenv("HOME");
        if (!home_dir) {
            // Fallback to password database
            struct passwd* pw = getpwuid(getuid());
            if (pw) {
                home_dir = pw->pw_dir;
            }
        }
    } else {
        // ~user - look up user in password database
        char username[256];  // Reasonable max username length
        if (username_len >= sizeof(username)) {
            return path;  // Username too long
        }
        memcpy(username, path + 1, username_len);
        username[username_len] = '\0';

        struct passwd* pw = getpwnam(username);
        if (pw) {
            home_dir = pw->pw_dir;
        }
    }

    if (home_dir) {
        cye_ds_write(&result, home_dir);
        if (path_separator) {
            cye_ds_write(&result, path_separator);
        }
        return result.items;
    }
#endif

    // If all expansion attempts failed, return original path
    return path;
}

ZString cye_path_expand_vars(ZString path) { cye_panic("TODO");}

int cye_needs_rebuild_from_buf(const char *output_path, const char **input_paths, usz input_paths_count) {
#ifndef _WIN32
    struct stat statbuf = {0};

    if (stat(output_path, &statbuf) < 0) {
        // NOTE: if output does not exist it 100% must be rebuilt
        if (errno == ENOENT) return 1;
        cye_trace_log(CYE_TRACE_ERROR, "could not stat %s: %s", output_path, CYE_GET_ERROR_STRING);
        return -1;
    }
    int output_path_time = statbuf.st_mtime;

    for (usz i = 0; i < input_paths_count; ++i) {
        const char *input_path = input_paths[i];
        if (stat(input_path, &statbuf) < 0) {
            // NOTE: non-existing input is an error cause it is needed for building in the first place
            cye_trace_log(CYE_TRACE_ERROR, "could not stat %s: %s", input_path, CYE_GET_ERROR_STRING);
            return -1;
        }
        int input_path_time = statbuf.st_mtime;
        // NOTE: if even a single input_path is fresher than output_path that's 100% rebuild
        if (input_path_time > output_path_time) return 1;
    }

    return 0;
#else

    BOOL bSuccess;
    HANDLE output_path_fd = CreateFile(output_path, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_READONLY, NULL);
    if (output_path_fd == INVALID_HANDLE_VALUE) {
        // NOTE: if output does not exist it 100% must be rebuilt
        if (GetLastError() == ERROR_FILE_NOT_FOUND) return 1;
        cye_trace_log(CYE_TRACE_ERROR, "Could not open file %s: %s", output_path, nob_win32_error_message(GetLastError()));
        return -1;
    }
    FILETIME output_path_time;
    bSuccess = GetFileTime(output_path_fd, NULL, NULL, &output_path_time);
    CloseHandle(output_path_fd);
    if (!bSuccess) {
        cye_trace_log(CYE_TRACE_ERROR, "Could not get time of %s: %s", output_path, nob_win32_error_message(GetLastError()));
        return -1;
    }

    for (usz i = 0; i < input_paths_count; ++i) {
        const char *input_path = input_paths[i];
        HANDLE input_path_fd = CreateFile(input_path, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_READONLY, NULL);
        if (input_path_fd == INVALID_HANDLE_VALUE) {
            // NOTE: non-existing input is an error cause it is needed for building in the first place
            cye_trace_log(CYE_TRACE_ERROR, "Could not open file %s: %s", input_path, nob_win32_error_message(GetLastError()));
            return -1;
        }
        FILETIME input_path_time;
        bSuccess = GetFileTime(input_path_fd, NULL, NULL, &input_path_time);
        CloseHandle(input_path_fd);
        if (!bSuccess) {
            cye_trace_log(CYE_TRACE_ERROR, "Could not get time of %s: %s", input_path, nob_win32_error_message(GetLastError()));
            return -1;
        }

        // NOTE: if even a single input_path is fresher than output_path that's 100% rebuild
        if (CompareFileTime(&input_path_time, &output_path_time) == 1) return 1;
    }

    return 0;
#endif
}


TString cye_path_temp_cwd(void) {
#ifndef _WIN32
    char *buffer = (char*) cye_talloc(PATH_MAX);
    if (getcwd(buffer, PATH_MAX) == NULL) {
        cye_trace_error("could not get current directory: %s", CYE_GET_ERROR_STRING);
        return NULL;
    }
    return buffer;
#else
    DWORD nBufferLength = GetCurrentDirectory(0, NULL);
    if (nBufferLength == 0) {
        cye_trace_error("could not get current directory: %s", nob_win32_error_message(GetLastError()));
        return NULL;
    }

    char *buffer = (char*) nob_temp_alloc(nBufferLength);
    if (GetCurrentDirectory(nBufferLength, buffer) == 0) {
        cye_trace_error("could not get current directory: %s", nob_win32_error_message(GetLastError()));
        return NULL;
    }

    return buffer;
#endif // _WIN32
}

bool cye_path_set_cwd(const char *path) {
#ifndef _WIN32
    if (chdir(path) < 0) {
        cye_trace_error("could not set current directory to %s: %s", path, CYE_GET_ERROR_STRING);
        return false;
    }
    return true;
#else
    if (!SetCurrentDirectory(path)) {
        cye_trace_error("could not set current directory to %s: %s", path, nob_win32_error_message(GetLastError()));
        return false;
    }
    return true;
#endif // _WIN32
}


b32 cye_file_exists(const char *file_path) {
#ifndef _WIN32
    struct stat statbuf;
    if (stat(file_path, &statbuf) < 0) {
        if (errno == ENOENT) return 0;
        cye_trace_error("Could not check if file %s exists: %s", file_path, strerror(errno));
        return -1;
    }
    return 1;
#else
    // TODO: distinguish between "does not exists" and other errors
    DWORD dwAttrib = GetFileAttributesA(file_path);
    return dwAttrib != INVALID_FILE_ATTRIBUTES;
#endif
}


bool cye_file_stats(const char* path, Cye_File_Stats* stats) {
#ifndef _WIN32
    struct stat st;
    if (stat(path, &st) != 0) {
        return false;
    }

    stats->created_at = st.st_ctime;
    stats->accessed_at = st.st_atime;
    stats->modified_at = st.st_mtime;
    stats->size_bytes = (size_t)st.st_size;

    return true;
#else
    HANDLE file_handle = CreateFileA(path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (file_handle == INVALID_HANDLE_VALUE) {
        return false;
    }

    FILETIME created, accessed, modified;
    if (!GetFileTime(file_handle, &created, &accessed, &modified)) {
        CloseHandle(file_handle);
        return false;
    }

    LARGE_INTEGER size;
    if (!GetFileSizeEx(file_handle, &size)) {
        CloseHandle(file_handle);
        return false;
    }

    CloseHandle(file_handle);

    stats->created_at = ((ULARGE_INTEGER*)&created)->QuadPart / 10000000ULL - 11644473600ULL;
    stats->accessed_at = ((ULARGE_INTEGER*)&accessed)->QuadPart / 10000000ULL - 11644473600ULL;
    stats->modified_at = ((ULARGE_INTEGER*)&modified)->QuadPart / 10000000ULL - 11644473600ULL;
    stats->size_bytes = (size_t)size.QuadPart;

    return true;
#endif
}

// Check if path is absolute
bool cye_is_absolute(ZString path) {
    cye_todo("VAI TRABALHAR VAGABUNDO");
}

// Check if path is relative
bool cye_is_relative(ZString path) {
    cye_todo("VAI TRABALHAR VAGABUNDO");
}

// Check if path  is regular  file
bool cye_is_file(ZString path) {
    cye_todo("VAI TRABALHAR VAGABUNDO");
}

// Check if path  is directory
bool cye_is_dir(ZString path) {
    cye_todo("VAI TRABALHAR VAGABUNDO");
}

// Check if path  is symbolic link
bool cye_is_link(ZString path) {
    cye_todo("VAI TRABALHAR VAGABUNDO");
}

// Check if path  is symbolic link
bool cye_is_mount(ZString path) {
    cye_todo("VAI TRABALHAR VAGABUNDO");
}

// Check if paths reference same file (one can be absolute and another relative or on be a hard link)
bool cye_is_same_path(ZString path1, ZString path2) {
    cye_todo("New Functions to Work on");
}

// Join paths intelligently
Cye_DString cye_path_join(ZString path, ZString* paths) {
    cye_todo("New Functions to Work on");
}

// Size  in bytes
usz cye_path_size(ZString path) {
    cye_todo("New Functions to Work on");
}

// Return real path (resolve symlinks)
ZString cye_path_real(ZString path) {
    cye_todo("New Functions to Work on");
}

// Convert a normalized path to absolute path
// Returns a newly allocated string containing the absolute path
// Returns NULL on error
// The returned string must be freed by the caller
// TODO: For these Path functions we really should go the
// Raylib TextFormat round of having 5~ buffers that cicles each time a functions is called
// so the it endures 5~ times and if the user really wants to live long, it should make a copy.
ZString cye_path_absolute(ZString path) {
    if (!path) return NULL;

    Cye_DString result = {0};

#ifdef _WIN32
    // Handle Windows UNC paths specially
    if (path[0] == '\\' && path[1] == '\\') {
        ds_write(&result, path);
        return result.items;
    }

    char abs_path[MAX_PATH];
    DWORD len = GetFullPathNameA(path, MAX_PATH, abs_path, NULL);

    if (len == 0 || len >= MAX_PATH) {
        ds_free(&result);
        return NULL;
    }

    // Convert backslashes to forward slashes if the input used them
    if (strchr(path, '/')) {
        for (DWORD i = 0; i < len; i++) {
            if (abs_path[i] == '\\') abs_path[i] = '/';
        }
    }

    cye_ds_write(&result, abs_path);

#else
    char abs_path[PATH_MAX];

    if (path[0] == '/') {
        // Path is already absolute
        cye_ds_write(&result, path);
    } else {
        // Get current working directory first
        if (!getcwd(abs_path, sizeof(abs_path))) {
            return NULL;
        }

        cye_ds_write(&result, abs_path);

        // Add separator if needed
        if (result.count > 0 && result.items[result.count - 1] != '/') {
            cye_ds_write(&result, "/");
        }

        cye_ds_write(&result, path);
    }

    // Clean up any . or .. in the path
    char real_path[PATH_MAX];
    if (realpath(result.items, real_path)) {
        result.count = 0;
        cye_ds_write(&result, real_path);
    } else if (errno != ENOENT) {
        // If error is not "file not exists", return error
        // We allow non-existent paths as long as parent exists
        cye_ds_free(result);
        return NULL;
    }
#endif

    return result.items;
}

//  Return relative path
ZString cye_path_relative(ZString from, ZString target) {
    cye_todo("New Functions to Work on");
}

//  Return home
ZString cye_path_home(void) {
    cye_todo("New Functions to Work on");
}

//  Return current directory
ZString cye_path_cwd(void) {
    cye_todo("New Functions to Work on");
}

ZString cye_path_parent(ZString path) {
    cye_todo("New Functions to Work on");
}

ZString cye_path_owner(ZString path) {
    cye_todo("New Functions to Work on");
}

// Path without extension
ZString cye_path_stem(ZString path) {
    cye_todo("New Functions to Work on");
}


//  NOTE: Its not just lexical dir_of, if a folder exists then we consider that
// But maybe we just want lexical?
// Return directory where file is, if it's already an directory it return its self
ZString cye_path_dir_of(ZString file_path) {
    if (!file_path) return NULL;

    // If it's already a directory, return thyself
    cye_threshold_log_level = CYE_LOG_NONE;
    if (cye_path_file_type(file_path) == CYE_FILE_TYPE_DIRECTORY) {
        return file_path;
    }
    cye_threshold_log_level = CYE_LOG_INFO;

    // Get last separator position
    ZString last_sep = NULL;
    for (const char* p = file_path; *p; p++) {
#ifdef _WIN32
        if (*p == '\\' || *p == '/') {
#else
        if (*p == '/') {
#endif
            last_sep = (ZString)p;
        }
    }

    if (!last_sep) {
        // No separator found, return "." for current directory
        return ".";
    }

    // Handle root directory cases
#ifdef _WIN32
    // Handle "C:\" case
    if (last_sep == file_path + 2 && file_path[1] == ':') {
        return file_path; // Return full path including root
    }
    // Handle "\\server\share\" case
    if (file_path[0] == '\\' && file_path[1] == '\\') {
        ZString p = file_path + 2;
        int separators = 0;
        while (*p) {
            if (*p == '\\' || *p == '/') {
                separators++;
                if (separators == 2 && p == last_sep) {
                    return file_path; // Return full UNC path
                }
            }
            p++;
        }
    }
#else
    // Handle "/" case
    if (last_sep == file_path) {
        return "/";
    }
#endif

    // Create a static buffer for the result
    static char dir_buffer[CYE_PATH_MAX];
    size_t len = last_sep - file_path;

    // Handle the case where the separator is the last character
    if (last_sep[1] == '\0') {
        // Copy the path up to and including the last separator
        if (len >= CYE_PATH_MAX) len = CYE_PATH_MAX - 1;
        memcpy(dir_buffer, file_path, len);
        dir_buffer[len] = '\0';
        return dir_buffer;
    }

    // Copy the path up to (but not including) the last separator
    if (len >= CYE_PATH_MAX) len = CYE_PATH_MAX - 1;
    memcpy(dir_buffer, file_path, len);
    dir_buffer[len] = '\0';
    return dir_buffer;
}


// Get only extension
ZString cye_path_ext(ZString path) {
    cye_todo("New Functions to Work on");
}

// Get only extension
bool cye_path_touch(ZString path) {
    // First check if file exists
    struct stat st;
    bool file_exists = (stat(path, &st) == 0);

    if (!file_exists) {
        // Create the file if it doesn't exist
#ifdef _WIN32
        HANDLE h = CreateFileA(
            path,
            GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, 
            NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL
        );
        if (h == INVALID_HANDLE_VALUE) {
            // Check if file was created by another process
            if (GetLastError() != ERROR_FILE_EXISTS) {
                return false;
            }
            file_exists = true;
        } else {
            CloseHandle(h);
        }
#else
        int fd = open(path, O_WRONLY | O_CREAT | O_NOCTTY | O_NONBLOCK, 0666);
        if (fd < 0) {
            // Check if file was created by another process
            if (errno != EEXIST) {
                return false;
            }
            file_exists = true;
        } else {
            close(fd);
        }
#endif
    }

    // Update the timestamps
    time_t current_time = time(NULL);
    struct utimbuf new_times = {
        .actime = current_time,   // Access time
        .modtime = current_time   // Modification time
    };

    return (utime(path, &new_times) == 0);
}

bool cye_make_dir_include_parents_from_tstr(TString path) {
    if (path == NULL || *path == '\0') {
        return false;
    }

    cye_threshold_log_level = CYE_LOG_NONE;
    bool created = false;

    // Remove trailing slashes
    usz len = strlen(path);
    while (len > 0 && (path[len - 1] == '/' || path[len - 1] == '\\')) {
        path[--len] = '\0';
    }

    // Handle absolute paths on Windows (e.g., "C:\foo")
#ifdef _WIN32
    if (len >= 2 && path[1] == ':') {
        if (len == 2) {  // Just a drive letter
            cye_threshold_log_level = CYE_LOG_INFO;
            return true;
        }
        // Skip drive letter and first slash if present
        char *p = path + 3;
        if (*p == '/' || *p == '\\') p++;
        for (; *p; p++) {
            if (*p == '/' || *p == '\\') {
                *p = '\0';
                created |= cye_make_dir(path);
                *p = '\\';
            }
        }
        created |= cye_make_dir(path);
    }
#endif

    // Handle absolute paths on Unix and relative paths on both systems
    for (char *p = path + 1; *p; p++) {
        if (*p == '/' || *p == '\\') {
            *p = '\0';
            created |= cye_make_dir(path);
            *p = '/';
        }
    }
    created |= cye_make_dir(path);

    cye_threshold_log_level = CYE_LOG_INFO;
    if (!created) {
        cye_trace_error("could not create directories recursively `%s`: %s", path, CYE_GET_ERROR_STRING);
    } else {
        cye_trace_info("created all directories `%s`", path);
    }

    return created;
}

// Create directories recursively
bool cye_make_dir_include_parents(ZString path) {
    bool created  = false;
    usz chk_point = cye_temp_save();
    cye_context   = cye_temp_context();

    TString tpath = cye_path_create(path);
    created = cye_make_dir_include_parents_from_tstr(tpath);

    cye_context  = cye_default_context();
    cye_temp_rewind(chk_point);
    return created;
}

//  Remove file
bool cye_remove_file(ZString path) {
    if (!cye_file_exists(path)) {
        cye_trace_info("file `%s` does not exist", path);
        return true;
    }

    Cye_File_Type type = cye_path_file_type(path);

    if (type != CYE_FILE_TYPE_REGULAR) {
        cye_trace_error("`%s` exists but is not a regular file", path);
        return false;
    }

    if (type == CYE_FILE_TYPE_DIRECTORY) {
        cye_trace_error("`%s` exists but is a directory, should we make a recursive remove function?", path);
        return false;
    }

#ifdef _WIN32
    int result = remove(path);
#else
    // https://www.man7.org/linux/man-pages/man2/unlink.2.html
    int result = unlink(path);
#endif

    if (result < 0) {
        cye_trace_error("could not remove file `%s`: %s", path, strerror(errno));
        return false;
    }

    cye_trace_info("Removed file `%s`", path);
    return true;

}


// Helper function to join paths
static void path_join(char *dest, const char *dir, const char *file) {
    size_t dir_len = strlen(dir);
    strcpy(dest, dir);

    #ifdef _WIN32
        if (dir_len > 0 && dir[dir_len - 1] != '\\') {
            strcat(dest, "\\");
        }
    #else
        if (dir_len > 0 && dir[dir_len - 1] != '/') {
            strcat(dest, "/");
        }
    #endif

    strcat(dest, file);
}

// Remove directory recursively
bool cye_remove_dir(const char *path) {
    char full_path[PATH_MAX];
    bool success = true;

#ifndef _WIN32
    DIR *dir = opendir(path);
    if (!dir) {
        if (errno == ENOENT) {
            // Directory doesn't exist
            return true;
        }
        cye_trace_error("could not open directory `%s`: %s", path, strerror(errno));
        return false;
    }

    struct dirent *entry;
    while ((entry = readdir(dir))) {
        // Skip "." and ".." directories
        if (strcmp(entry->d_name, ".") == 0 ||
            strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        path_join(full_path, path, entry->d_name);

        struct stat statbuf;
        if (stat(full_path, &statbuf) != 0) {
            cye_trace_error("could not stat `%s`: %s", full_path, strerror(errno));
            success = false;
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            // Recursively remove subdirectory
            if (!cye_remove_dir(full_path)) {
                success = false;
            }
        } else {
            // Remove file
            if (unlink(full_path) != 0) {
                cye_trace_error("could not delete file `%s`: %s", full_path, strerror(errno));
                success = false;
            } else {
                cye_trace_info("deleted file `%s`", full_path);
            }
        }
    }

    closedir(dir);

    // Remove the empty directory
    if (success && rmdir(path) != 0) {
        cye_trace_error("could not remove directory `%s`: %s", path, strerror(errno));
        success = false;
    } else if (success) {
        cye_trace_info("Removed directory `%s`", path);
    }
#else
    WIN32_FIND_DATA find_data;
    char search_path[PATH_MAX];

    // Prepare search path
    snprintf(search_path, sizeof(search_path), "%s\\*", path);

    HANDLE find_handle = FindFirstFile(search_path, &find_data);
    if (find_handle == INVALID_HANDLE_VALUE) {
        if (GetLastError() == ERROR_FILE_NOT_FOUND) {
            // Directory is empty
            return RemoveDirectory(path);
        }
        cye_trace_error("could not open directory `%s`: %lu", path, GetLastError());
        return false;
    }

    do {
        // Skip "." and ".." directories
        if (strcmp(find_data.cFileName, ".") == 0 ||
            strcmp(find_data.cFileName, "..") == 0) {
            continue;
        }

        path_join(full_path, path, find_data.cFileName);

        if (find_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            // Recursively remove subdirectory
            if (!cye_remove_directory(full_path)) {
                success = false;
            }
        } else {
            // Remove file
            if (!DeleteFile(full_path)) {
                cye_trace_error("could not delete file `%s`: %lu", full_path, GetLastError());
                success = false;
            } else {
                cye_trace_info("deleted file `%s`", full_path);
            }
        }
    } while (FindNextFile(find_handle, &find_data));

    FindClose(find_handle);

    // Remove the empty directory
    if (success && !RemoveDirectory(path)) {
        cye_trace_error("could not remove directory `%s`: %lu", path, GetLastError());
        success = false;
    } else if (success) {
        cye_trace_info("Removed directory `%s`", path);
    }

#endif

    return success;
}

//  Remove directories recursively
bool cye_remove_dirs(ZString path) {
    cye_todo("New Functions to Work on");
}

//  Move file or directory
bool cye_path_move(ZString src, ZString dst) {

    cye_trace_info("Moving %s -> %s", src, dst);
#ifndef _WIN32 // Unix
    // On Unix-like systems, rename() can move files across directories
    if (rename(src, dst) < 0) {
        cye_trace_error("Could not move %s to %s: %s", src, dst, CYE_GET_ERROR_STRING);
        return false;
    }
#else
    if (!MoveFileEx(src, dst, MOVEFILE_REPLACE_EXISTING)) {
        cye_trace_error("Could not move %s to %s: %s", src, dst, cye_win32_error_message(GetLastError()));
        return false;
    }
#endif // _WIN32
    return true;
}

//  Rename file or directory
bool cye_path_rename(ZString src, ZString dst) {
    // TODO: use dir of to check they are on the same directory
    return cye_path_move(src, dst);
}

//  Recursive directory or file renaming
bool cye_path_renames(ZString old_path, ZString new_path) {
    cye_todo("New Functions to Work on");
}

//  Rename file or directory, replacing
bool cye_path_replace(ZString src, ZString dst) {
    cye_todo("New Functions to Work on");
}

// Paths valid for one func call much like TextFormat from Raylib
//  Iterator of directory entries
Cye_Path_DArray cye_path_scandir(ZString path) {
    cye_todo("New Functions to Work on");
}


//------------------------------------------------------------------------------------
//  Dynamic Array Implementation
//------------------------------------------------------------------------------------

// All macros xD

//------------------------------------------------------------------------------------
//  Slices Implementation
//------------------------------------------------------------------------------------

// All macros xD



//------------------------------------------------------------------------------------
//  String Slice Implementation
//------------------------------------------------------------------------------------

Cye_String_Slice cye_str_slice_make(const char *str) {
    return (Cye_String_Slice)cye_slice_make(str, strlen(str));
}

// Trim whitespace from both ends
Cye_String_Slice cye_str_slice_trim(Cye_String_Slice s) {
    while (s.count > 0 && isspace(s.data[0])) {
        s.data++;
        s.count--;
    }
    while (s.count > 0 && isspace(s.data[s.count - 1])) {
        s.count--;
    }
    return s;
}

// String slice to null-terminated string (requires buffer)
void cye_str_slice_to_zstr(Cye_String_Slice s, char *buf, usz buf_size) {
    usz to_copy = s.count < buf_size - 1 ? s.count : buf_size - 1;
    memcpy(buf, s.data, to_copy);
    buf[to_copy] = '\0';
}


// New function: Strip left whitespace
Cye_String_Slice cye_str_slice_strip_left(Cye_String_Slice s) {
    while (s.count > 0 && isspace(s.data[0])) {
        s.data++;
        s.count--;
    }
    return s;
}

// New function: Strip right whitespace
Cye_String_Slice cye_str_slice_strip_right(Cye_String_Slice s) {
    while (s.count > 0 && isspace(s.data[s.count - 1])) {
        s.count--;
    }
    return s;
}
// Create string slice from string and explicit length
Cye_String_Slice cye_str_slice_make_len(const char *str, usz len) {
    return (Cye_String_Slice)cye_slice_make((char*)str, len);
}

// Compare two string slices
bool cye_str_slice_equals(Cye_String_Slice a, Cye_String_Slice b) {
    if (a.count != b.count) return false;
    return memcmp(a.data, b.data, a.count) == 0;
}

// Check if string slice contains substring
bool cye_str_slice_contains(Cye_String_Slice haystack, Cye_String_Slice needle) {
    if (needle.count > haystack.count) return false;

    for (usz i = 0; i <= haystack.count - needle.count; i++) {
        if (memcmp(haystack.data + i, needle.data, needle.count) == 0) {
            return true;
        }
    }
    return false;
}


// Split string slice by delimiter into a Dynamic Array
Cye_String_Slice_DArray cye_str_slice_split(Cye_String_Slice s, Cye_String_Slice delim) {
    Cye_String_Slice_DArray result = {0};

    char *start   = (char*)s.data;
    char *end     = (char*)s.data + s.count;
    char *current = (char*)s.data;

    while (current <= end - delim.count) {
        if (memcmp(current, delim.data, delim.count) == 0) {
            cye_da_append(&result, cye_str_slice_make_len(start, current - start));
            current += delim.count;
            start = current;
        } else {
            current++;
        }
    }

    // Add the last part
    if (start < end) {
        cye_da_append(&result, cye_str_slice_make_len(start, end - start));
    }

    return result;
}

// Split string slice at first occurrence of delimiter
void cye_str_slice_split_first(Cye_String_Slice s, char delim, Cye_String_Slice *before, Cye_String_Slice *after) {
    for (usz i = 0; i < s.count; i++) {
        if (s.data[i] == delim) {
            if (before) *before = (Cye_String_Slice)cye_slice_make(s.data, i);
            if (after) *after = (Cye_String_Slice)cye_slice_make(s.data + i + 1, s.count - i - 1);
            return;
        }
    }
    if (before) *before = s;
    if (after) *after = CYE_STR_SLICE_EMPTY;
}

// Check if string slice starts with prefix
bool cye_str_slice_starts_with(Cye_String_Slice s, Cye_String_Slice prefix) {
    if (prefix.count > s.count) return false;
    return memcmp(s.data, prefix.data, prefix.count) == 0;
}

// Check if string slice ends with suffix
bool cye_str_slice_ends_with(Cye_String_Slice s, Cye_String_Slice suffix) {
    if (suffix.count > s.count) return false;
    return memcmp(s.data + s.count - suffix.count, suffix.data, suffix.count) == 0;
}

// Check if string slice starts with zero-terminated prefix
bool cye_str_slice_starts_with_zstr(Cye_String_Slice s, ZString prefix) {
    usz prefix_len = strlen(prefix);
    if (prefix_len > s.count) return false;
    return memcmp(s.data, prefix, prefix_len) == 0;
}

// Check if string slice ends with zero-terminated suffix
bool cye_str_slice_ends_with_zstr(Cye_String_Slice s, ZString suffix) {
    usz suffix_len = strlen(suffix);
    if (suffix_len > s.count) return false;
    return memcmp(s.data + s.count - suffix_len, suffix, suffix_len) == 0;
}

//------------------------------------------------------------------------------------
//  ZString Implementation
//------------------------------------------------------------------------------------

bool cye_zstr_ends_with(ZString src, ZString ending) {
    if (!src || !ending) return false;  // NULL check

    usz src_len    = strlen(src);
    usz ending_len = strlen(ending);

    // If ending is longer than src, it can't be a suffix
    if (ending_len > src_len) return false;

    // Compare the end of src with ending
    return memcmp(src + (src_len - ending_len), ending, ending_len) == 0;
}

bool cye_zstr_starts_with(ZString src, ZString prefix) {
    if (src == NULL || prefix == NULL) return false;
    if (!*prefix)               return true;  // Empty prefix always matches
    if (!*src)                  return false;    // Empty string only matches empty prefix

    usz prefix_len = strlen(prefix);
    usz src_len    = strlen(src);

    if (prefix_len > src_len) return false;

    return memcmp(src, prefix, prefix_len) == 0;
}

//----------------------------------------------------------------------------------
//  Dynamic String Implementation
//----------------------------------------------------------------------------------


// NOTE: Don't use this yet
// TODO: Improve and use this to sanity check ds_printf and printlike functions
static int cye_count_non_scaped_percent(ZString s) {
    int count = 0;
    int i = 0;

    while (s[i] != '\0') {
        if (s[i] == '%') {
            // Check if the '%' is escaped
            // WARN: This only check one level of escaped
            // actual it fails with "\\%s" for examples it'l think its
            // escaped when it's not. This function is to be taken not as exact
            // but a lower bound of %'s but still need to check, basically don't use this yet
            if (i == 0 || s[i - 1] != '\\') {
                count++;
            }
        }
        i++;
    }
    return count;
}

void cye_ds_printf(Cye_DString *ds, ZString fmt, ...) {

    unused(cye_count_non_scaped_percent);
    va_list args;
    va_start(args, fmt);
    int n = vsnprintf(NULL, 0, fmt, args);
    va_end(args);

    cye_assert(n >= 0);
    usz chk_point = cye_temp_save();
    char *result = cye_talloc(n + 1);

    cye_assert(result != NULL && "Extend the size of the temporary allocator");

    va_start(args, fmt);
    vsnprintf(result, n + 1, fmt, args);
    va_end(args);
    cye_ds_write_buf(ds, result, n); // Don't write the null terminator
    cye_temp_rewind(chk_point);
}

//----------------------------------------------------------------------------------
//  Utils Math Implemenetation
//----------------------------------------------------------------------------------

// Clamp float value
f32 cye_clamp(f32 value, f32 min, f32 max) {
    f32 result = (value < min)? min : value;
    if (result > max) result = max;
    return result;
}

// Calculate linear interpolation between two floats
f32 cye_lerp(f32 start, f32 end, f32 amount) {
    f32 result = start + amount*(end - start);
    return result;
}

// Normalize input value within input range
f32 cye_normalize(f32 value, f32 start, f32 end) {
    f32 result = (value - start)/(end - start);
    return result;
}

// remap input value within input range to output range
f32 cye_remap(f32 value, f32 inputStart, f32 inputEnd, f32 outputStart, f32 outputEnd) {
    f32 result = (value - inputStart)/(inputEnd - inputStart)*(outputEnd - outputStart) + outputStart;
    return result;
}

// Floor function implementation without math.h
f32 cye_floorf(f32 x) {
    int32_t i = (int32_t)x;
    return (x < 0.0f && x != i) ? i - 1.0f : (f32)i;
}

// Absolute value for float
f32 cye_fabsf(f32 x) {
    union {
        f32 f;
        uint32_t i;
    } u = { .f = x };
    u.i &= 0x7FFFFFFF;  // Clear sign bit
    return u.f;
}

// Maximum of two floats
f32 cye_fmaxf(f32 x, f32 y) {
    // Handle NaN cases first
    if (x != x) return y;
    if (y != y) return x;
    // Normal comparison
    return x > y ? x : y;
}

// Wrap input value from min to max
f32 cye_wrap(f32 value, f32 min, f32 max) {
    f32 result = value - (max - min)*cye_floorf((value - min)/(max - min));
    return result;
}

// Check whether two given f32s are almost equal
int cye_float_equals(f32 x, f32 y) {
    int result = (cye_fabsf(x - y)) <= (EPSILON*cye_fmaxf(1.0f, cye_fmaxf(cye_fabsf(x), cye_fabsf(y))));
    return result;
}

//------------------------------------------------------------------------------------
//  Utils Implemenetation
//------------------------------------------------------------------------------------

void cye_set_trace_level(Cye_Log_Level level) {
    cye_threshold_log_level = level;
}

// TODO: Add colors from nabs.h
void cye_trace_log(Cye_Log_Level level, const char *fmt, ...) {
    // Level below current threshold, don't log anythin
    if (level < cye_threshold_log_level) return;

    va_list args;
    va_start(args, fmt);
    char buffer[CYE_MAX_TRACE_LOG_MSG_LENGTH] = { 0 };

    const char *color = "";
    const char *reset = "";
    const char *bold = "";


    switch (level) {
        case CYE_LOG_TRACE:   break;
        case CYE_LOG_DEBUG:   color = ESCAPE_CODE_OKCYAN;  reset = ESCAPE_CODE_RESET; break;
        case CYE_LOG_INFO:    color = ESCAPE_CODE_LOG;     reset = ESCAPE_CODE_RESET; break;
        case CYE_LOG_OKAY:    color = ESCAPE_CODE_OKGREEN; reset = ESCAPE_CODE_RESET; break;
        case CYE_LOG_WARNING: color = ESCAPE_CODE_WARNING; reset = ESCAPE_CODE_RESET; break;
        case CYE_TRACE_ERROR:   color = ESCAPE_CODE_ERROR;   reset = ESCAPE_CODE_RESET; break;
        case CYE_LOG_FATAL:   color = ESCAPE_CODE_ERROR;   reset = ESCAPE_CODE_RESET; bold = ESCAPE_CODE_BOLD; break;
        case CYE_LOG_ALL:     break;
        case CYE_LOG_NONE:    break;
        default: cye_unreachable("cye_trace_log"); break;
    }

#if !defined(_WIN32)
    if (!isatty(STDOUT_FILENO)) {
        color = ""; reset = ""; bold = "";
    }
#else
    if (GetFileType(GetStdHandle(STD_OUTPUT_HANDLE)) != FILE_TYPE_CHAR) {
        color = ""; reset = ""; bold = "";
    }
#endif

    const usz max_len = CYE_MAX_TRACE_LOG_MSG_LENGTH;
    usz written = 0 ;
    switch (level) {
        case CYE_LOG_TRACE:   written = snprintf(buffer, max_len, "%sTRACE%s%s: ", color, reset, bold); break;
        case CYE_LOG_DEBUG:   written = snprintf(buffer, max_len, "%sDEBUG%s%s: ", color, reset, bold); break;
        case CYE_LOG_INFO:    written = snprintf(buffer, max_len, "%sINFO%s%s:  ", color, reset, bold); break;
        case CYE_LOG_OKAY:    written = snprintf(buffer, max_len, "%sOKAY%s%s:  ", color, reset, bold); break;
        case CYE_LOG_WARNING: written = snprintf(buffer, max_len, "%sWARN%s%s:  ", color, reset, bold); break;
        case CYE_TRACE_ERROR: written = snprintf(buffer, max_len, "%sERROR%s%s: ", color, reset, bold); break;
        case CYE_LOG_FATAL:   written = snprintf(buffer, max_len, "%sFATAL%s%s: ", color, reset, bold); break;
        case CYE_LOG_ALL:     written = snprintf(buffer, max_len, "%sALL%s%s:   ", color, reset, bold); break;
        case CYE_LOG_NONE:    return;
        default: cye_unreachable("cye_trace_log");         break;
    }


    //TODO: Better name
    usz fmt_size = (usz)strlen(fmt);
    memcpy(
        buffer + strlen(buffer),
        fmt,
        (fmt_size < (max_len - written))
          ? fmt_size
          : (max_len - written)
    );

    strcat(buffer, "\n");
    vprintf(buffer, args);
    snprintf(buffer, max_len, "%s", reset);
    fflush(stdout);
    va_end(args);

    // Ensure death if fatal
    if (CYE_LOG_FATAL == level) {
        exit(EXIT_FAILURE);
    }
}

void cye__assert_handler(char const *prefix, char const *condition, char const *file, int line, char const *msg, ...) {
    fprintf(stderr, "%s:%d: %s: ", file, line, prefix);
    if (condition) {
        fprintf(stderr, "`%s` ", condition);
    }
    if (msg) {
        va_list va;
        va_start(va, msg);
        vfprintf(stderr, msg, va);
        va_end(va);
    }
    fprintf(stderr, "\n");
}

const char *cye_cpu_architecture() {
#if defined(__x86_64__) || defined(_M_X64)
  return "x86_64";
#elif defined(i386) || defined(__i386__) || defined(__i386) || defined(_M_IX86)
  return "x86_32";
#elif defined(__ARM_ARCH_2__)
  return "ARM2";
#elif defined(__ARM_ARCH_3__) || defined(__ARM_ARCH_3M__)
  return "ARM3";
#elif defined(__ARM_ARCH_4T__) || defined(__TARGET_ARM_4T)
  return "ARM4T";
#elif defined(__ARM_ARCH_5_) || defined(__ARM_ARCH_5E_)
  return "ARM5"
#elif defined(__ARM_ARCH_6T2_) || defined(__ARM_ARCH_6T2_)
  return "ARM6T2";
#elif defined(__ARM_ARCH_6__) || defined(__ARM_ARCH_6J__) || defined(__ARM_ARCH_6K__) || defined(__ARM_ARCH_6Z__) || defined(__ARM_ARCH_6ZK__)
  return "ARM6";
#elif defined(__ARM_ARCH_7__) || defined(__ARM_ARCH_7A__) || defined(__ARM_ARCH_7R__) || defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7S__)
  return "ARM7";
#elif defined(__ARM_ARCH_7A__) || defined(__ARM_ARCH_7R__) || defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7S__)
  return "ARM7A";
#elif defined(__ARM_ARCH_7R__) || defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7S__)
  return "ARM7R";
#elif defined(__ARM_ARCH_7M__)
  return "ARM7M";
#elif defined(__ARM_ARCH_7S__)
  return "ARM7S";
#elif defined(__aarch64__) || defined(_M_ARM64)
  return "ARM64";
#elif defined(mips) || defined(__mips__) || defined(__mips)
  return "MIPS";
#elif defined(__sh__)
  return "SUPERH";
#elif defined(__powerpc) || defined(__powerpc__) || defined(__powerpc64__) || defined(__POWERPC__) || defined(__ppc__) || defined(__PPC__) || defined(_ARCH_PPC)
  return "POWERPC";
#elif defined(__PPC64__) || defined(__ppc64__) || defined(_ARCH_PPC64)
  return "POWERPC64";
#elif defined(__sparc__) || defined(__sparc)
  return "SPARC";
#elif defined(__m68k__)
  return "M68K";
#else
  return "UNKNOWN";
#endif
}

// Base on https://stackoverflow.com/a/75644008
// > .NET Core uses 4096 * sizeof(WCHAR) buffer on stack for FormatMessageW call. And...thats it.
// >
// > https://github.com/dotnet/runtime/blob/3b63eb1346f1ddbc921374a5108d025662fb5ffd/src/coreclr/utilcode/posterror.cpp#L264-L265
#ifndef CYE_WIN32_ERR_MSG_SIZE
#   define CYE_WIN32_ERR_MSG_SIZE (4096 * sizeof(WCHAR))
#endif // CYE_WIN32_ERR_MSG_SIZE

#ifdef _WIN32
char *nob_win32_error_message(DWORD err) {
    static char win32ErrMsg[CYE_WIN32_ERR_MSG_SIZE] = {0};
    DWORD errMsgSize = FormatMessageA(
        FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, NULL, err,
        LANG_USER_DEFAULT, win32ErrMsg, CYE_WIN32_ERR_MSG_SIZE, NULL
    );

    if (errMsgSize == 0) {
        if (GetLastError() != ERROR_MR_MID_NOT_FOUND) {
            if (sprintf(win32ErrMsg, "Could not get error message for 0x%lX", err) > 0) {
                return (char *)&win32ErrMsg;
            } else {
                return NULL;
            }
        } else {
            if (sprintf(win32ErrMsg, "Invalid Windows Error code (0x%lX)", err) > 0) {
                return (char *)&win32ErrMsg;
            } else {
                return NULL;
            }
        }
    }

    while (errMsgSize > 1 && isspace(win32ErrMsg[errMsgSize - 1])) {
        win32ErrMsg[--errMsgSize] = '\0';
    }

    return win32ErrMsg;
}
#endif // _WIN32

#endif // CYE_IMPLEMENTATION


/*..................................................................................
 .                                                                                 .
 .                                SHORT NAMES                                      .
 .                                                                                 .
 ...................................................................................
*/
#ifndef _CYE_NO_SHORT_NAMES_GUARD_
#define _CYE_NO_SHORT_NAMES_GUARD_
#if !defined(CYE_NO_SHORT_NAMES)

//----------------------------------------------------------------------------------
//  Tweakable Constants Short Names
//----------------------------------------------------------------------------------

// NOTE: Does it make sense to shorten these?

//----------------------------------------------------------------------------------
//  Structures Definition with Prefix Short Names
//----------------------------------------------------------------------------------

#define LOG_ALL     CYE_LOG_ALL
#define LOG_TRACE   CYE_LOG_TRACE
#define LOG_DEBUG   CYE_LOG_DEBUG
#define LOG_INFO    CYE_LOG_INFO
#define LOG_OKAY    CYE_LOG_OKAY
#define LOG_WARNING CYE_LOG_WARNING
#define LOG_ERROR   CYE_TRACE_ERROR
#define LOG_FATAL   CYE_LOG_FATAL
#define LOG_NONE    CYE_LOG_NONE

#define Log_Level           Cye_Log_Level
#define DArray              Cye_DArray
#define Path_DArray         Cye_Path_DArray
#define File_Type           Cye_File_Type
#define File_Stats          Cye_File_Stats
#define DString             Cye_DString

#define INVALID_PROCESS     CYE_INVALID_PROCESS
#define INVALID_FILE_HANDLE CYE_INVALID_FILE_HANDLE
#define Process             Cye_Process
#define File_Handle         Cye_File_Handle

#define Process_DArray      Cye_Process_DArray
#define Command             Cye_Command
#define Command_Redirect    Cye_Command_Redirect
#define String_Slice        Cye_String_Slice
#define String_Slice_DArray Cye_String_Slice_DArray
#define Context             Cye_Context

//------------------------------------------------------------------------------------
//  Global Variables Short Names
//------------------------------------------------------------------------------------

#define temp_data           cye_temp_data
#define threshold_log_level cye_threshold_log_level
#define context             cye_context


//------------------------------------------------------------------------------------
//  Process and File Short Names
//------------------------------------------------------------------------------------
#define file_open_for_read  cye_file_open_for_read
#define file_open_for_write cye_file_open_for_write
#define file_close          cye_file_close

#define process_wait_all           cye_process_wait_all
#define process_wait_all_and_reset cye_process_wait_all_and_reset
#define process_wait               cye_process_wait


//------------------------------------------------------------------------------------
//  Commands Short Names
//------------------------------------------------------------------------------------
#define cmd_append                       cye_cmd_append

#define cmd_extend                       cye_cmd_extend
#define cmd_free                         cye_cmd_free

#define ds_write_cmd                     cye_ds_write_cmd

#define cmd_run_async                    cye_cmd_run_async
#define cmd_run_async_and_reset          cye_cmd_run_async_and_reset
#define cmd_run_async_redirect           cye_cmd_run_async_redirect
#define cmd_run_async_redirect_and_reset cye_cmd_run_async_redirect_and_reset

#define cmd_run_sync                     cye_cmd_run_sync
#define cmd_run_sync_and_reset           cye_cmd_run_sync_and_reset
#define cmd_run_sync_redirect            cye_cmd_run_sync_redirect
#define cmd_run_sync_redirect_and_reset  cye_cmd_run_sync_redirect_and_reset


//------------------------------------------------------------------------------------
//  Storage Short Names
//------------------------------------------------------------------------------------


#define temp_context        cye_temp_context
#define default_context     cye_default_context
#define set_default_context cye_set_default_context

#define tstrdup     cye_tstrdup
#define talloc      cye_talloc
#define trealloc    cye_trealloc
#define tprintf     cye_tprintf

#define temp_reset  cye_temp_reset
#define temp_save   cye_temp_save
#define temp_rewind cye_temp_rewind

//------------------------------------------------------------------------------------
//  Path Short Names
//------------------------------------------------------------------------------------

#define make_dir_if_not_exists          cye_make_dir_if_not_exists
#define copy_file                       cye_copy_file
#define copy_dir                        cye_copy_dir
#define read_entire_dir                 cye_read_entire_dir
#define write_entire_file               cye_write_entire_file
#define read_entire_file                cye_read_entire_file
#define path_file_type                  cye_path_file_type
#define path_temp_normalize             cye_path_temp_normalize
#define path_create_from_array          cye_path_create_from_array

#define path_create                     cye_path_create
#define path_temp_create                cye_path_temp_create


#define path_base_name                  cye_path_base_name
#define path_expand_user                cye_path_expand_user
#define path_expand_vars                cye_path_expand_vars

#define needs_rebuild_from_buf          cye_needs_rebuild_from_buf
#define needs_rebuild                   cye_needs_rebuild

#define path_temp_cwd                   cye_path_temp_cwd
#define path_set_cwd                    cye_path_set_cwd

#define file_exists                     cye_file_exists
#define file_stats                      cye_file_stats
#define is_absolute                     cye_is_absolute
#define is_relative                     cye_is_relative
#define is_file                         cye_is_file
#define is_dir                          cye_is_dir
#define is_link                         cye_is_link
#define is_mount                        cye_is_mount
#define is_same_path                    cye_is_same_path

#define path_join                       cye_path_join
#define path_size                       cye_path_size
#define path_real                       cye_path_real
#define path_absolute                   cye_path_absolute
#define path_relative                   cye_path_relative

#define path_home                       cye_path_home
#define path_cwd                        cye_path_cwd
#define path_parent                     cye_path_parent
#define path_owner                      cye_path_owner
#define path_stem                       cye_path_stem
#define path_dir_of                     cye_path_dir_of
#define path_ext                        cye_path_ext
#define path_touch                      cye_path_touch

#define make_dir                           cye_make_dir
#define make_dirs                          cye_make_dirs
#define make_dir_include_parents           cye_make_dir_include_parents
#define make_dir_include_parents_from_tstr cye_make_dir_include_parents_from_tstr
#define remove_file                        cye_remove_file
#define remove_dir                         cye_remove_dir
#define remove_dirs                        cye_remove_dirs
#define path_move                          cye_path_move
#define path_rename                        cye_path_rename
#define path_renames                       cye_path_renames
#define path_replace                       cye_path_replace
#define path_scandir                       cye_path_scandir

//------------------------------------------------------------------------------------
//  Dynamic Array Short Names
//------------------------------------------------------------------------------------
#define da_fmt         cye_da_fmt
#define da_fmt_arg     cye_da_fmt_arg
#define da_append      cye_da_append
#define da_free        cye_da_free
#define da_append_many cye_da_append_many


//------------------------------------------------------------------------------------
//  Slices Short Names
//------------------------------------------------------------------------------------

#define slice_fmt     cye_slice_fmt
#define slice_fmt_arg cye_slice_fmt_arg

#define Slice Cye_Slice

#define slice_make     cye_slice_make
#define slice_from_arr cye_slice_from_arr

#define slice_empty     cye_slice_empty
#define STR_SLICE_EMPTY CYE_STR_SLICE_EMPTY

#define slice_range    cye_slice_range
#define slice_prefix   cye_slice_prefix
#define slice_suffix   cye_slice_suffix
#define slice_equal    cye_slice_equal
#define slice_contains cye_slice_contains
#define slice_is_empty cye_slice_is_empty
#define slice_at       cye_slice_at
#define slice_copy     cye_slice_copy
#define slice_index_of cye_slice_index_of


//------------------------------------------------------------------------------------
//  String Slice Short Names
//------------------------------------------------------------------------------------


#define ss_fmt     cye_ss_fmt
#define ss_fmt_arg cye_ss_fmt_arg

#define str_slice_make             cye_str_slice_make
#define str_slice_trim             cye_str_slice_trim
#define str_slice_to_zstr          cye_str_slice_to_zstr
#define str_slice_strip_left       cye_str_slice_strip_left
#define str_slice_strip_right      cye_str_slice_strip_right
#define str_slice_make_len         cye_str_slice_make_len
#define str_slice_equals           cye_str_slice_equals
#define str_slice_contains         cye_str_slice_contains
#define str_slice_split            cye_str_slice_split
#define str_slice_split_first      cye_str_slice_split_first
#define str_slice_starts_with      cye_str_slice_starts_with
#define str_slice_ends_with        cye_str_slice_ends_with
#define str_slice_ends_with_zstr   cye_str_slice_ends_with_zstr
#define str_slice_starts_with_zstr cye_str_slice_starts_with_zstr
//------------------------------------------------------------------------------------
//  ZString Short Names
//------------------------------------------------------------------------------------
#define zstr_ends_with   cye_zstr_ends_with
#define zstr_starts_with cye_zstr_starts_with


//----------------------------------------------------------------------------------
//  Dynamic String Short Names
//----------------------------------------------------------------------------------

#define ds_fmt     cye_ds_fmt
#define ds_fmt_arg cye_ds_fmt_arg

#define ds_write_buf  cye_ds_write_buf
#define ds_write_zstr cye_ds_write_zstr
#define ds_write_zero cye_ds_write_zero
#define ds_write      cye_ds_write
#define ds_write_char cye_ds_write_char

// Free the memory allocated by a string builder
#define ds_free   cye_ds_free
#define ds_printf cye_ds_printf


//----------------------------------------------------------------------------------
//  Mathematics Short Names
//----------------------------------------------------------------------------------
#define min          cye_min
#define max          cye_max
#define clamp        cye_clamp
#define lerp         cye_lerp
#define normalize    cye_normalize
#define remap        cye_remap
#define wrap         cye_wrap
#define float_equals cye_float_equals

//------------------------------------------------------------------------------------
//  Utils Short Names
//------------------------------------------------------------------------------------

#define set_trace_level cye_set_trace_level
#define trace_log       cye_trace_log
#define trace_info      cye_trace_info
#define trace_okay      cye_trace_okay
#define trace_error     cye_trace_error
#define trace_warn      cye_trace_warn
#define trace_fatal     cye_trace_fatal

#define return_defer cye_return_defer
#define result_defer cye_result_defer

// Consider using logging instead ? Maybe not
#define todo            cye_todo
#define unreachable     cye_unreachable
#define panic           cye_panic
#define not_implemented cye_not_implemented
#define shift           cye_shift

#define assert_msg cye_assert_msg
#define assert cye_assert

#define file_fmt     cye_file_fmt
#define file_fmt_arg cye_file_fmt_arg

#define file_stats_fmt     cye_file_stats_fmt
#define file_stats_fmt_arg cye_file_stats_fmt_arg

#define cpu_architecture *cye_cpu_architecture


#endif // CYE_NO_SHORT_NAMES

#endif // _CYE_NO_SHORT_NAMES_GUARD_

//TODO: Make a localized space for common undef to helpout when undefs are needed
// make in a way that it doesnt trigger any warning from the compiler ok?

// EOF
