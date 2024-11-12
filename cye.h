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
// Basic Includes
//----------------------------------------------------------------------------------

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stddef.h>
#include <stdint.h>

#ifdef _WIN32
#    define WIN32_LEAN_AND_MEAN
#    define _WINUSER_
#    define _WINGDI_ // Not protable to msvc i think need tro use NO_GDI stuff from windows.h
#    define _IMM_
#    define _WINCON_
#    include <windows.h>
#    include <direct.h>
#    include <shellapi.h>
#    define PATH_SEPARATOR "\\"
#    define PATH_SEPARATOR_CHAR '\\'
#else
#    include <sys/types.h>
#    include <sys/wait.h>
#    include <sys/stat.h>
#    include <unistd.h>
#    include <fcntl.h>
#    define PATH_SEPARATOR "/"
#    define PATH_SEPARATOR_CHAR '/'
#endif



//----------------------------------------------------------------------------------
// Basic Definitions with No Prefix
//----------------------------------------------------------------------------------

// #define cye_return_defer(value) do { result = (value); goto defer; } while(0)
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

#ifndef unused
#   if defined(_MSC_VER)
#       define unused(x) (__pragma(warning(suppress : 4100))(x))
#   elif defined(__GCC__)
#       define unused(x) __attribute__((__unused__)) (x)
#   else
#       define unused(x) ((void)(size_of(x)))
#   endif
#endif


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
// Tweakable Constants
//----------------------------------------------------------------------------------

// Consider using logging instead ? Maybe not
#define cye_todo(msg)        do { fprintf(stderr, "%s:%d: %s TODO: %s\n",       __FILE__, __LINE__,__PRETTY_FUNCTION__,  msg); abort(); } while(0)
#define cye_unreachable(msg) do { fprintf(stderr, "%s:%d: %s UNREACHABLE: %s\n",__FILE__, __LINE__,__PRETTY_FUNCTION__,  msg); abort(); } while(0)
#define cye_panic(msg)       do { fprintf(stderr, "%s:%d: %s PANIC: " msg "\n",__FILE__, __LINE__,__PRETTY_FUNCTION__); abort(); } while(0)
#define cye_not_implemented(msg) assert(0 && msg "Not Implemented.")
#define cye_shift(items, items_sz)  (assert((items_sz) > 0), (items_sz)--, *(items)++)

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

/*..................................................................................
 .                                                                                 .
 .                                Types                                            .
 .                                                                                 .
 ...................................................................................
*/
//----------------------------------------------------------------------------------
// Structures Definition without Prefix
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

// Unsigned Integers
typedef int64_t     i64;
typedef int32_t     i32;
typedef int16_t     i16;
typedef int8_t      i8;
typedef size_t      usz;
typedef ptrdiff_t   isz;

typedef size_t      usize;
typedef ptrdiff_t   isize;

typedef const char* ZString; // Static Zero Terminated String
typedef       char* TString; // Temporary String
typedef       char* MutString; // Mutable String, might be temporary or not

//----------------------------------------------------------------------------------
// Structures Definition with Prefix
//----------------------------------------------------------------------------------

// NOTE: Organized by priority level
typedef enum {
    CYE_LOG_ALL = 0,        // Display all logs
    CYE_LOG_TRACE,          // Trace logging, intended for internal use only
    CYE_LOG_DEBUG,          // Debug logging, used for internal debugging, it should be disabled on release builds
    CYE_LOG_INFO,           // Info logging, used for program execution info
    CYE_LOG_WARNING,        // Warning logging, used on recoverable failures
    CYE_LOG_ERROR,          // Error logging, used on unrecoverable failures
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

// TODO: Generic Slicing
typedef struct {
    usz count;
    const char *data;
} Cye_String_Slice;

typedef struct {
    void* (*alloc)(usz size);
    void* (*realloc) (void *ptr, usz size);
    void  (*free)(void* ptr);
} Cye_Context;


/*..................................................................................
 .                                                                                 .
 .                                Functions                                        .
 .                                                                                 .
 ...................................................................................
*/

//------------------------------------------------------------------------------------
// Process and File Functions
//------------------------------------------------------------------------------------
Cye_File_Handle cye_open_for_write(const char *path);
void cye_file_close(Cye_File_Handle handle);
bool cye_process_wait_all(Cye_Process_DArray procs);
bool cye_process_wait_all_and_reset(Cye_Process_DArray *procs);
bool cye_process_wait(Cye_Process proc); // Wait until the process has finished

//------------------------------------------------------------------------------------
// Commands Functions
//------------------------------------------------------------------------------------
#define cye_cmd_append(cmd, ...)              \
    cye_da_append_many(                       \
        cmd, ((const char *[]){__VA_ARGS__}), \
        (sizeof((const char *[]){__VA_ARGS__}) / sizeof(const char *)))

#define cye_cmd_extend(cmd, other_cmd) \
    cye_da_append_many(cmd, (other_cmd)->items, (other_cmd)->count)

// Free all the memory allocated by command arguments
#define cye_cmd_free(cmd) CYE_FREE(cmd.items)


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
// Storage Functions
//------------------------------------------------------------------------------------

Cye_Context cye_temp_context(void);
Cye_Context cye_default_context(void);

char* cye_tstrdup(const char *cstr);
void* cye_talloc(usz size);
void* cye_trealloc(void *ptr, usz size);
void  cye_tfree(rawptr ptr);

TString cye_tprintf(ZString fmt, ...);

void cye_temp_reset(void);
usz  cye_temp_save(void);
void cye_temp_rewind(usz checkpoint);

//------------------------------------------------------------------------------------
// Path Functions
//------------------------------------------------------------------------------------

bool cye_mkdir_if_not_exists(const char *path);
bool cye_copy_file(const char *src_path, const char *dst_path);
bool cye_copy_dir_recursively(const char *src_path, const char *dst_path);
bool cye_read_entire_dir(const char *parent, Cye_Path_DArray *children);
bool cye_write_entire_file(const char *path, const void *data, usz size);
Cye_File_Type cye_path_file_type(const char *path);

char* cye_path_temp_normalize(ZString path);
char* cye_path_create_from_array(ZString paths[], usz paths_count);

#define cye_path_create(...)                                            \
    cye_path_create_from_array(                                         \
        ((const char*[]){__VA_ARGS__}),                                 \
        (sizeof((const char *[]){__VA_ARGS__}) / sizeof(const char *)))

ZString cye_base_name(const char *path);
ZString cye_exists(const char *path); // TODO
ZString cye_expand_user(ZString path);  // Expand ~ and ~user
ZString cye_expand_vars(ZString path);  // Expand environment variables

int  cye_needs_rebuild(const char *output_path, const char **input_paths, usz input_paths_count);

#define cye_needs_rebuild_spread(output_path, ...)    \
    cye_needs_rebuild(                                \
        output_path, ((const char *[]){__VA_ARGS__}), \
        (sizeof((const char *[]){__VA_ARGS__}) / sizeof(const char *)))

#define cye_needs_rebuild1(out, in) cye_needs_rebuild_spread(out, in)

TString cye_path_temp_cwd(void);
bool    cye_path_set_cwd(const char *path);

bool cye_file_exists(const char *file_path);
bool cye_is_absolute(ZString path);                           // Check if path  is absolute
bool cye_is_relative(ZString path);                           // Check if path  is relative
bool cye_is_file(ZString path);                               // Check if path  is regular  file
bool cye_is_dir(ZString path);                                // Check if path  is directory
bool cye_is_link(ZString path);                               // Check if path  is symbolic link
bool cye_is_mount(ZString path);                              // Check if path  is mount    point
bool cye_is_same_path(ZString path1, ZString path2);          // Check if paths reference same file (one can be absolute and another relative or on be a hard link)

Cye_DString cye_path_join(ZString path, ZString* paths);             // Join paths intelligently
usz         cye_path_size(ZString path);                             // Size  in bytes
ZString     cye_path_real(ZString path);                             // Returns real path (resolve symlinks)
ZString     cye_path_absolute(ZString path);                         // Returns absolute path
ZString     cye_path_relative(ZString from, ZString target);         // Returns relative path

ZString cye_path_home(void);           //  Return home
ZString cye_path_cwd(void);            //  Return current directory
ZString cye_path_parent(ZString path); //  Returns parent directory
ZString cye_path_owner(ZString path);  //  Returns parent directory
ZString cye_path_stem(ZString path);   //  Return path without extension
ZString cye_path_ext(ZString path);    //  Returns only the extension
ZString cye_path_touch(ZString path);  //  Creates an empty file if not already exists

bool cye_dir_change(ZString path);                          // Change current working directory
#define cye_mkdir cye_mkdir_if_not_exists                   // Create directory
bool cye_mkdir_include_parents(ZString path);               // Create directories including parents as needed
bool cye_mkdir_include_parents_from_tstr(TString path);     // Create directories recursively
#define cye_mkdirs cye_mkdir_include_parents

bool cye_remove_file(ZString path);                         // Remove file
bool cye_remove_dir(ZString path);                          // Remove directory
bool cye_remove_dirs(ZString path);                         // Remove directories recursively
bool cye_path_move(ZString src, ZString dst);               // Move file or directory
bool cye_path_rename(ZString src, ZString dst);             // Rename file or directory
bool cye_path_renames(ZString old_path, ZString new_path);  // Recursive directory or file renaming
bool cye_path_replace(ZString src, ZString dst);            // Rename file or directory, replacing if exists
                                                            // Paths valid for one func call much like TextFormat from Raylib
Cye_Path_DArray cye_path_scandir(ZString path);             // Iterator of directory entries

// bool cye_path_walk(funct)                                //  Generate directory tree


//------------------------------------------------------------------------------------
// Dynamic Array
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
            assert((da)->items != NULL && "Dynamic Array: OOM");                           \
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
            assert((da)->items != NULL && "Dynamic Array: OOM");                                \
        }                                                                                       \
        memcpy((da)->items + (da)->count, (new_items), (new_items_count)*sizeof(*(da)->items)); \
        (da)->count += (new_items_count);                                                       \
    } while (0)


//------------------------------------------------------------------------------------
// String Functions
//------------------------------------------------------------------------------------

// printf macros for String_View
#ifndef SV_FMT
#   define SV_FMT "%.*s"
#endif // SV_Fmt
#ifndef SV_ARG
#   define SV_ARG(sv) (int) (sv).count, (sv).data
#endif // SV_Arg


// ZString nob_temp_sv_to_zstr(Cye_String_Slice sv);
bool cye_zstr_ends_with(ZString src, ZString ending);

// TODO: Add String Slices Functions as we need


//----------------------------------------------------------------------------------
// Dynamic String Functions
//----------------------------------------------------------------------------------

#define cye_ds_fmt "{.items=%s, .count=%zu, .capacity=%zu}"
#define cye_ds_fmt_arg(ds) (ds).items, (ds).count, (ds).capacity

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
#define cye_ds_free(ds) cye_context.free((ds).items)

// Formated Print onto the Dynamic String
void cye_ds_printf(Cye_DString *ds, ZString fmt, ...);


//----------------------------------------------------------------------------------
// Mathematics Functions
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
// Process and File Functions
//------------------------------------------------------------------------------------
Cye_File_Handle cye_open_for_read(const char *path);
Cye_File_Handle cye_open_for_write(const char *path);
void cye_file_close(Cye_File_Handle fh);

//------------------------------------------------------------------------------------
// Utils Functions
//------------------------------------------------------------------------------------
void cye_trace_log(Cye_Log_Level level, const char *fmt, ...);
#define cye_trace_info(...)  cye_trace_log(CYE_LOG_INFO, __VA_ARGS__)
#define cye_trace_error(...) cye_trace_log(CYE_LOG_ERROR, __VA_ARGS__)



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
// Global Variables Definition
//------------------------------------------------------------------------------------

static struct {
    usz size;
    byte buffer[CYE_TEMP_CAPACITY];
} cye_temp_data = {0};

static Cye_Log_Level cye_threshold_log_level = CYE_LOG_INFO;

thread_local Cye_Context cye_context = {.alloc = cye_malloc, .realloc = cye_realloc, .free = cye_free};

//------------------------------------------------------------------------------------
// Process and File Functions Definitions
//------------------------------------------------------------------------------------

#ifdef _WIN32
#   define CYE_GET_ERROR_STRING (cye__win32_error_message(GetLastError()))
#else
#   define CYE_GET_ERROR_STRING (strerror(errno))
#endif


Cye_File_Handle cye_open_for_write(ZString path) {

#ifndef _WIN32
    Cye_File_Handle result = open(path,
        O_WRONLY | O_CREAT | O_TRUNC,
        S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH
    );

    if (result < 0) {
        cye_trace_log(CYE_LOG_ERROR, "Could not open file %s: %s", path, CYE_GET_ERROR_STRING);
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
        cye_trace_log(CYE_LOG_ERROR, "Could not open file %s: %s", path, CYE_GET_ERROR_STRING);
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
            cye_trace_log(CYE_LOG_ERROR, "Could not wait on command (pid %d): %s", proc, CYE_GET_ERROR_STRING);
            return false;
        }

        if (WIFEXITED(wstatus)) {
            int exit_status = WEXITSTATUS(wstatus);
            if (exit_status != 0) {
                cye_trace_log(CYE_LOG_ERROR, "Command exited with exit code %d", exit_status);
                return false;
            }
            break;
        }

        if (WIFSIGNALED(wstatus)) {
            cye_trace_log(CYE_LOG_ERROR, "Command process was terminated by %s", strsignal(WTERMSIG(wstatus)));
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
        cye_trace_log(CYE_LOG_ERROR, "Could not wait on child process: %s", nob_win32_error_message(GetLastError()));
        return false;
    }

    DWORD exit_status;
    if (!GetExitCodeProcess(proc, &exit_status)) {
        cye_trace_log(CYE_LOG_ERROR, "Could not get process exit code: %s", nob_win32_error_message(GetLastError()));
        return false;
    }

    if (exit_status != 0) {
        cye_trace_log(CYE_LOG_ERROR, "Command exited with exit code %lu", exit_status);
        return false;
    }

    CloseHandle(proc);

    return true;
#endif
}

//------------------------------------------------------------------------------------
// Commands Functions Implementation
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

    int rebuild_is_needed = cye_needs_rebuild1(binary_path, source_path);
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
// Storage Functions Implementation
//------------------------------------------------------------------------------------

Cye_Context cye_temp_context(void) {
    return cliteral(Cye_Context){.alloc = cye_talloc, .realloc = cye_trealloc, .free = cye_tfree};
}

Cye_Context cye_default_context(void) {
    return cliteral(Cye_Context){.alloc = cye_malloc, .realloc = cye_realloc, .free = cye_free};
}

TString cye_tstrdup(const char *cstr) {
    usz n = strlen(cstr);
    TString result = (TString)cye_talloc(n + 1);
    assert(result != NULL && "Please increase CYE_TEMP_CAPACITY");
    memcpy(result, cstr, n);
    result[n] = '\0';
    return result;
}


// TODO: Check out arena allocator
rawptr cye_talloc(usz size) {

    if (cye_temp_data.size + size > CYE_TEMP_CAPACITY) return NULL;
    rawptr result = &cye_temp_data.buffer[cye_temp_data.size];
    cye_temp_data.size += size;
    return result;
}

void *cye_trealloc(void *ptr, usz size) {
    unused(ptr);
    // Fragmentation, but who cares
    return cye_talloc(size);
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


    assert(n >= 0);
    char *result = cye_talloc(n + 1);

    assert(result != NULL && "Extend the size of the temporary allocator");

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
// Path Functions Implementation
//------------------------------------------------------------------------------------

bool cye_mkdir_if_not_exists(const char *path) {
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

bool cye_copy_dir_recursively(const char *src_path,
                                    const char *dst_path) {
    cye_todo("VAI TRABALHAR VAGABUNDO");
}

bool cye_read_entire_dir(const char *parent, Cye_Path_DArray *children) {
    cye_todo("VAI TRABALHAR VAGABUNDO");
}

bool cye_write_entire_file(const char *path, const void *data, usz size) {
    cye_todo("VAI TRABALHAR VAGABUNDO");
}

Cye_File_Type cye_path_file_type(const char *path) {
    cye_todo("VAI TRABALHAR VAGABUNDO");
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
    cye_trace_log(CYE_LOG_INFO,"Path normalizing `%s`", path);

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

    // Allocate memory for the final path with context, so user can decide
    // where to allocate this
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
        ds.items = strncpy(ds.items, tpath, total_count);
        cye_temp_rewind(chk_point);
    }

    return ds.items;
}

ZString cye_base_name(const char *path) { cye_todo("VAI TRABALHAR VAGABUNDO"); }

ZString cye_exists(const char *path) {
    cye_todo("VAI TRABALHAR VAGABUNDO");
}  // TODO

// Expand ~ and ~user
ZString cye_expand_user(ZString path) {
    cye_todo("VAI TRABALHAR VAGABUNDO");
}

// Expand environment variables
ZString cye_expand_vars(ZString path) {
    cye_todo("VAI TRABALHAR VAGABUNDO");
}

int cye_needs_rebuild(const char *output_path, const char **input_paths, usz input_paths_count) {
#ifndef _WIN32
    struct stat statbuf = {0};

    if (stat(output_path, &statbuf) < 0) {
        // NOTE: if output does not exist it 100% must be rebuilt
        if (errno == ENOENT) return 1;
        cye_trace_log(CYE_LOG_ERROR, "could not stat %s: %s", output_path, CYE_GET_ERROR_STRING);
        return -1;
    }
    int output_path_time = statbuf.st_mtime;

    for (usz i = 0; i < input_paths_count; ++i) {
        const char *input_path = input_paths[i];
        if (stat(input_path, &statbuf) < 0) {
            // NOTE: non-existing input is an error cause it is needed for building in the first place
            cye_trace_log(CYE_LOG_ERROR, "could not stat %s: %s", input_path, CYE_GET_ERROR_STRING);
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
        cye_trace_log(CYE_LOG_ERROR, "Could not open file %s: %s", output_path, nob_win32_error_message(GetLastError()));
        return -1;
    }
    FILETIME output_path_time;
    bSuccess = GetFileTime(output_path_fd, NULL, NULL, &output_path_time);
    CloseHandle(output_path_fd);
    if (!bSuccess) {
        cye_trace_log(CYE_LOG_ERROR, "Could not get time of %s: %s", output_path, nob_win32_error_message(GetLastError()));
        return -1;
    }

    for (usz i = 0; i < input_paths_count; ++i) {
        const char *input_path = input_paths[i];
        HANDLE input_path_fd = CreateFile(input_path, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_READONLY, NULL);
        if (input_path_fd == INVALID_HANDLE_VALUE) {
            // NOTE: non-existing input is an error cause it is needed for building in the first place
            cye_trace_log(CYE_LOG_ERROR, "Could not open file %s: %s", input_path, nob_win32_error_message(GetLastError()));
            return -1;
        }
        FILETIME input_path_time;
        bSuccess = GetFileTime(input_path_fd, NULL, NULL, &input_path_time);
        CloseHandle(input_path_fd);
        if (!bSuccess) {
            cye_trace_log(CYE_LOG_ERROR, "Could not get time of %s: %s", input_path, nob_win32_error_message(GetLastError()));
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


bool cye_file_exists(const char *file_path) {
    cye_todo("VAI TRABALHAR VAGABUNDO");
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

ZString cye_path_absolute(ZString path) {
    cye_todo("New Functions to Work on");
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

// Get only extension
ZString cye_path_ext(ZString path) {
    cye_todo("New Functions to Work on");
}

// Get only extension
ZString cye_path_touch(ZString path) {
    cye_todo("New Functions to Work on");
}

// Change current working directory
bool cye_dir_change(ZString path) {
    cye_todo("New Functions to Work on");
}

bool cye_mkdir_include_parents_from_tstr(TString path) {
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
                created |= cye_mkdir(path);
                *p = '\\';
            }
        }
        created |= cye_mkdir(path);
    }
#endif

    // Handle absolute paths on Unix and relative paths on both systems
    for (char *p = path + 1; *p; p++) {
        if (*p == '/' || *p == '\\') {
            *p = '\0';
            created |= cye_mkdir(path);
            *p = '/';
        }
    }
    created |= cye_mkdir(path);

    cye_threshold_log_level = CYE_LOG_INFO;
    if (!created) {
        cye_trace_error("could not create directories recursively `%s`: %s", path, CYE_GET_ERROR_STRING);
    } else {
        cye_trace_info("created all directories `%s`", path);
    }

    return created;
}

// Create directories recursively
bool cye_mkdir_include_parents(ZString path) {
    bool created  = false;
    usz chk_point = cye_temp_save();
    cye_context   = cye_temp_context();

    TString tpath = cye_path_create(path);
    created = cye_mkdir_include_parents_from_tstr(tpath);

    cye_context  = cye_default_context();
    cye_temp_rewind(chk_point);
    return created;
}

//  Remove file
bool cye_remove_file(ZString path) {
    cye_todo("New Functions to Work on");
}

//  Remove directory
bool cye_remove_dir(ZString path) {
    cye_todo("New Functions to Work on");
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
// Dynamic Array Implementation
//------------------------------------------------------------------------------------

// All are macros xD

//----------------------------------------------------------------------------------
// Dynamic String Implementation
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

    assert(n >= 0);
    usz chk_point = cye_temp_save();
    char *result = cye_talloc(n + 1);

    assert(result != NULL && "Extend the size of the temporary allocator");

    va_start(args, fmt);
    vsnprintf(result, n + 1, fmt, args);
    va_end(args);
    cye_ds_write_buf(ds, result, n + 1);
    cye_temp_rewind(chk_point);
}

//------------------------------------------------------------------------------------
// String Functions Implementation
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
// Utils Math Implemenetation
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
// Utils Functions Implemenetation
//------------------------------------------------------------------------------------

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
        case CYE_LOG_WARNING: color = ESCAPE_CODE_WARNING; reset = ESCAPE_CODE_RESET; break;
        case CYE_LOG_ERROR:   color = ESCAPE_CODE_ERROR;   reset = ESCAPE_CODE_RESET; break;
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
        case CYE_LOG_TRACE:   written = snprintf(buffer, max_len, "%sTRACE%s%s: ", color, bold, reset); break;
        case CYE_LOG_DEBUG:   written = snprintf(buffer, max_len, "%sDEBUG%s%s: ", color, bold, reset); break;
        case CYE_LOG_INFO:    written = snprintf(buffer, max_len, "%sINFO%s%s:  ", color, bold, reset); break;
        case CYE_LOG_WARNING: written = snprintf(buffer, max_len, "%sWARN%s%s:  ", color, bold, reset); break;
        case CYE_LOG_ERROR:   written = snprintf(buffer, max_len, "%sERROR%s%s: ", color, bold, reset); break;
        case CYE_LOG_FATAL:   written = snprintf(buffer, max_len, "%sFATAL%s%s: ", color, bold, reset); break;
        case CYE_LOG_ALL:     written = snprintf(buffer, max_len, "%sALL%s%s:   ", color, bold, reset); break;
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
    fflush(stdout);
    va_end(args);

    // Ensure death if fatal
    if (CYE_LOG_FATAL == level) {
        exit(EXIT_FAILURE);
    }
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
#ifndef NOB_WIN32_ERR_MSG_SIZE
#define NOB_WIN32_ERR_MSG_SIZE (4096 * 4)
#endif // NOB_WIN32_ERR_MSG_SIZE

#ifdef _WIN32
char *nob_win32_error_message(DWORD err) {
    static char win32ErrMsg[NOB_WIN32_ERR_MSG_SIZE] = {0};
    DWORD errMsgSize = FormatMessageA(
        FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, NULL, err,
        LANG_USER_DEFAULT, win32ErrMsg, NOB_WIN32_ERR_MSG_SIZE, NULL
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
#define _CYE_NO_SHORT_NAMES_
#if !defined(CYE_NO_SHORT_NAMES)

//----------------------------------------------------------------------------------
// Tweakable Constants
//----------------------------------------------------------------------------------

// Consider using logging instead ? Maybe not
#define todo cye_todo
#define unreachable cye_unreachable
#define not_implemented cye_not_implemented
#define shift cye_shift

//----------------------------------------------------------------------------------
// Structures Definition with Prefix
//----------------------------------------------------------------------------------

#define LOG_ALL     CYE_LOG_ALL
#define LOG_TRACE   CYE_LOG_TRACE
#define LOG_DEBUG   CYE_LOG_DEBUG
#define LOG_INFO    CYE_LOG_INFO
#define LOG_WARNING CYE_LOG_WARNING
#define LOG_ERROR   CYE_LOG_ERROR
#define LOG_FATAL   CYE_LOG_FATAL
#define LOG_NONE    CYE_LOG_NONE

#define Log_Level        Cye_Log_Level
#define DArray           Cye_DArray
#define Path_DArray      Cye_Path_DArray
#define File_Type        Cye_File_Type
#define DString          Cye_DString
#define Process          Cye_Process
#define File_Handle      Cye_File_Handle
#define Process_DArray   Cye_Process_DArray
#define Command          Cye_Command
#define Command_Redirect Cye_Command_Redirect
#define String_Slice     Cye_String_Slice
#define Context          Cye_Context

//------------------------------------------------------------------------------------
// Global Variables Definition
//------------------------------------------------------------------------------------

#define temp_data           cye_temp_data
#define threshold_log_level cye_threshold_log_level
#define context             cye_context


//------------------------------------------------------------------------------------
// Process and File Short Names
//------------------------------------------------------------------------------------
#define open_for_write             cye_open_for_write
#define file_close                 cye_file_close
#define process_wait_all           cye_process_wait_all
#define process_wait_all_and_reset cye_process_wait_all_and_reset
#define process_wait               cye_process_wait

//------------------------------------------------------------------------------------
// Commands Short Names
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
// Storage Functions
//------------------------------------------------------------------------------------


#define temp_context    cye_temp_context
#define default_context cye_default_context

#define tstrdup     cye_tstrdup
#define talloc      cye_talloc
#define tprintf     cye_tprintf

#define temp_reset  cye_temp_reset
#define temp_save   cye_temp_save
#define temp_rewind cye_temp_rewind

//------------------------------------------------------------------------------------
// Path Functions
//------------------------------------------------------------------------------------

#define mkdir_if_not_exists             cye_mkdir_if_not_exists
#define copy_file                       cye_copy_file
#define copy_dir_recursively            cye_copy_dir_recursively
#define read_entire_dir                 cye_read_entire_dir
#define write_entire_file               cye_write_entire_file
#define path_file_type                  cye_path_file_type
#define path_temp_normalize             cye_path_temp_normalize
#define path_create_from_array          cye_path_create_from_array

#define path_create                     cye_path_create


#define base_name                       cye_base_name
#define exists                          cye_exists
#define expand_user                     cye_expand_user
#define expand_vars                     cye_expand_vars

#define needs_rebuild                   cye_needs_rebuild
#define needs_rebuild_spread            cye_needs_rebuild_spread
#define needs_rebuild1                  cye_needs_rebuild1

#define path_temp_cwd                   cye_path_temp_cwd
#define path_set_cwd                    cye_path_set_cwd

#define file_exists                     cye_file_exists
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
#define path_ext                        cye_path_ext
#define path_touch                      cye_path_touch

#define dir_change                      cye_dir_change
#define mkdir                           cye_mkdir
#define mkdirs                          cye_mkdirs
#define mkdir_include_parents           cye_mkdir_include_parents
#define mkdir_include_parents_from_tstr cye_mkdir_include_parents_from_tstr
#define remove_file                     cye_remove_file
#define remove_dir                      cye_remove_dir
#define remove_dirs                     cye_remove_dirs
#define path_move                       cye_path_move
#define path_rename                     cye_path_rename
#define path_renames                    cye_path_renames
#define path_replace                    cye_path_replace
#define path_scandir                    cye_path_scandir

//------------------------------------------------------------------------------------
// Dynamic Array
//------------------------------------------------------------------------------------
#define da_fmt         cye_da_fmt
#define da_fmt_arg     cye_da_fmt_arg
#define da_append      cye_da_append
#define da_free        cye_da_free
#define da_append_many cye_da_append_many

//------------------------------------------------------------------------------------
// String Functions
//------------------------------------------------------------------------------------
#define zstr_ends_with cye_zstr_ends_with


//----------------------------------------------------------------------------------
// Dynamic String Functions
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
// Mathematics Functions
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
// Process and File Functions
//------------------------------------------------------------------------------------
#define open_for_read  cye_open_for_read
#define open_for_write cye_open_for_write
#define file_close     cye_file_close

//------------------------------------------------------------------------------------
// Utils Functions
//------------------------------------------------------------------------------------
#define trace_log   cye_trace_log
#define trace_info  cye_trace_info
#define trace_error cye_trace_error

#define cpu_architecture *cye_cpu_architecture


#endif // CYE_NO_SHORT_NAMES

#endif // _CYE_NO_SHORT_NAMES_GUARD_

//TODO: Make a localized space for common undef to helpout when undefs are needed
// make in a way that it doesnt trigger any warning from the compiler ok?

// EOF
