#ifndef _CYE_H_
#define _CYE_H_

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
#else
#    include <sys/types.h>
#    include <sys/wait.h>
#    include <sys/stat.h>
#    include <unistd.h>
#    include <fcntl.h>
#endif



//----------------------------------------------------------------------------------
// Basic Definitions
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

#define cye_shift(items, items_sz)  (assert((items_sz) > 0), (items_sz)--, *(items)++)

#ifndef kilobytes
#   define kilobytes(x) ((x) * (i64)(1024))
#   define megabytes(x) (kilobytes(x) * (i64)(1024))
#   define gigabytes(x) (megabytes(x) * (i64)(1024))
#   define terabytes(x) (gigabytes(x) * (i64)(1024))
#endif

#define local static
#define filescope static
#define notimplemented(msg) assert(0 && msg "Not Implemented.")
#define todo(msg) assert(0 && msg "To Do ! ")

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
#       define thread_local thread_local
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
#   define USIZE_MIX U64_MIN
#   define USIZE_MAX U64_MAX
#   define ISIZE_MIX I64_MIN
#   define ISIZE_MAX I64_MAX
#else
#   //TODO: Portable warning is needed because of MSVC
#   warning "You might need to check for more CPU Architectures"
#endif


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

#ifdef _WIN32
#    define CYE_END_OF_LINE "\r\n"
#    define CYE_PATH_SEPARATOR "\\"
#else
#    define CYE_END_OF_LINE "\n"
#    define CYE_PATH_SEPARATOR "/"
#endif

#ifndef cye_malloc
#   define cye_malloc(sz)       malloc((sz))
#endif

#ifndef cye_calloc
#   define cye_calloc(n, sz)     calloc((n), (sz))
#endif

#ifndef cye_realloc
#   define cye_realloc(ptr, sz)  realloc((ptr), (sz))
#endif

#ifndef cye_free
#   define cye_free(ptr)        free((ptr))
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

#ifndef CYE_MAX_TRACELOG_MSG_LENGTH
#   define CYE_MAX_TRACELOG_MSG_LENGTH 256
#endif

/*..................................................................................
 .                                                                                 .
 .                                Types                                            .
 .                                                                                 .
 ...................................................................................
*/
//----------------------------------------------------------------------------------
// Structures Definition
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
typedef size_t      usize;
typedef ptrdiff_t   isize;

// Zero Terminated String
typedef const char* ZString; // Zero Terminated String
typedef char* TString; // Temporary String


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

typedef struct {
    const char **items;
    size_t count;
    size_t capacity;
} Cye_Path_DArray;

typedef enum {
    CYE_FILE_TYPE_REGULAR = 0,
    CYE_FILE_TYPE_DIRECTORY,
    CYE_FILE_TYPE_SYMLINK,
    CYE_FILE_TYPE_OTHER,
} Cye_File_Type;

typedef struct {
    char  *items;
    size_t count;
    size_t capacity;
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
    size_t count;
    size_t capacity;
} Cye_Process_DArray;

typedef struct {
    const char **items;
    size_t count;
    size_t capacity;
} Cye_Command;

typedef struct {
    Cye_File_Handle *in;
    Cye_File_Handle *out;
    Cye_File_Handle *err;
} Cye_Command_Redirect;

// TODO: Generic Slicing
typedef struct {
    size_t count;
    const char *data;
} Cye_String_Slice;

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
#define cye_cmd_append(cmd, ...) \
    cye_da_append_many(cmd, \
                       ((const char*[]){__VA_ARGS__}), \
                       (sizeof((const char*[]){__VA_ARGS__})/sizeof(const char*)))

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

#if !defined(CYE_REBUILD_COMMAND)
#  ifdef _WIN32
#    if defined(__GNUC__)
#       define CYE_REBUILD_COMMAND(binary_path, source_path) "gcc", "-o", binary_path, source_path
#    elif defined(__clang__)
#       define CYE_REBUILD_COMMAND(binary_path, source_path) "clang", "-o", binary_path, source_path
#    elif defined(_MSC_VER)
#       if defined(__clang__)
#           define CYE_REBUILD_COMMAND(binary_path, source_path) "clang-cl.exe", cye_tprintf("/Fe:%s", (binary_path)), source_path
#       else
#           define CYE_REBUILD_COMMAND(binary_path, source_path) "cl.exe", cye_tprintf("/Fe:%s", (binary_path)), source_path
#       endif
#    endif
#  else
#    define CYE_REBUILD_COMMAND(binary_path, source_path) "cc", "-o", binary_path, source_path
#  endif
#endif

// Sean Barret Style in-between `__`
// void cye__rebuild_ourselves(const char *source_path, int argc, char **argv);
void cye__rebuild_ourselves(ZString source_path, int argc, ZString *argv);
#define cye_rebuild_ourselves(argc, argv) cye__rebuild_ourselves(__FILE__, argc, argv)


//------------------------------------------------------------------------------------
// Temporary Storage Functions
//------------------------------------------------------------------------------------
char  *cye_tstrdup(const char *cstr);
void  *cye_talloc(usize size);
TString cye_tprintf(ZString fmt, ...);

void  cye_temp_reset(void);
usize cye_temp_save(void);
void  cye_temp_rewind(usize checkpoint);

//------------------------------------------------------------------------------------
// Path Functions
//------------------------------------------------------------------------------------

bool cye_mkdir_if_not_exists(const char *path);
bool cye_copy_file(const char *src_path, const char *dst_path);
bool cye_copy_directory_recursively(const char *src_path, const char *dst_path);
bool cye_read_entire_dir(const char *parent, Cye_Path_DArray *children);
bool cye_write_entire_file(const char *path, const void *data, usize size);
Cye_File_Type cye_get_file_type(const char *path);

ZString cye_base_name(const char *path);
ZString cye_exists(const char *path); // TODO
ZString cye_expand_user(ZString path);  // Expand ~ and ~user
ZString cye_expand_vars(ZString path);  // Expand environment variables

bool cye_rename(const char *old_path, const char *new_path);
int  cye_needs_rebuild(const char *output_path, const char **input_paths, usize input_paths_count);
// TODO: cye_needs_rebuild like cmd_append
int  cye_needs_rebuild1(const char *output_path, const char *input_path);
int  cye_file_exists(const char *file_path);
ZString cye_get_current_dir_temp(void);
bool cye_set_current_dir(const char *path);

bool cye_getsize(ZString path);          // Size  in bytes
bool cye_is_abs(ZString path);           // Check if path  is absolute
bool cye_is_file(ZString path);          // Check if path  is regular  file
bool cye_is_dir(ZString path);           // Check if path  is directory
bool cye_is_link(ZString path);          // Check if path  is symbolic link
bool cye_is_mount(ZString path);         // Check if path  is mount    point

bool        cye_is_same_path(ZString path1, ZString path2);  // Check if paths reference same file (one can be absolute and another relative or on be a hard link)
Cye_DString cye_join(ZString path, ZString* paths);         // Join paths intelligently

ZString cye_realpath(ZString path);                     // Return real path (resolve symlinks)
ZString cye_relpath(ZString path, ZString path_start);  //  Return relative path

ZString cye_home(void);  //  Return home
ZString cye_cwd(void);  //  Return current directory
ZString cye_parent_dir(ZString path);
ZString cye_path_owner(ZString path);
ZString cye_dir_remove(ZString path);
ZString cye_file_remove(ZString path);
ZString cye_path_stem(ZString path);  // without extension
ZString cye_path_ext(ZString path);   // extension
ZString cye_path_touch(ZString path);  // extension

bool cye_chdir(ZString path);  // Change current working directory
bool cye_mkdir(ZString path);  // Create directory
bool cye_mkdirs(ZString path);  // Create directories recursively
bool cye_remove(ZString path);  //  Remove file
bool cye_remove_dir(ZString path);  //  Remove directory
bool cye_remove_dirs(ZString path);  //  Remove directories recursively
bool cye_path_rename(ZString src, ZString dst);  //  Rename file or directory
bool cye_path_renames(ZString old, ZString new);  //  Recursive directory or file renaming
bool cye_replace(ZString src, ZString dst);  //  Rename file or directory, replacing if exists
// Paths valid for one func call much like TextFormat from Raylib
Cye_Path_DArray cye_path_scandir(ZString path);  //  Iterator of directory entries
// bool cye_path_walk(funct)  //  Generate directory tree


//------------------------------------------------------------------------------------
// Dynamic Array
//------------------------------------------------------------------------------------

// Append an item to a dynamic array
#define cye_da_append(da, item)                                                            \
    do {                                                                                   \
        if ((da)->count >= (da)->capacity) {                                               \
            (da)->capacity = (da)->capacity == 0 ?                                         \
                CYE_DARRAY_INIT_CAP :                                                      \
                (da)->capacity*CYE_DARRAY_CAP_MULTIPLIER;                                  \
            (da)->items = cye_realloc((da)->items, (da)->capacity*sizeof(*(da)->items));   \
            assert((da)->items != NULL && "Buy more RAM lol");                             \
        }                                                                                  \
                                                                                           \
        (da)->items[(da)->count++] = (item);                                               \
    } while (0)

#define cye_da_free(da) cye_free((da).items)

#define cye_da_append_many(da, new_items, new_items_count)                                      \
    do {                                                                                        \
        if ((da)->count + (new_items_count) > (da)->capacity) {                                 \
            if ((da)->capacity == 0) {                                                          \
                (da)->capacity = CYE_DARRAY_INIT_CAP;                                           \
            }                                                                                   \
            while ((da)->count + (new_items_count) > (da)->capacity) {                          \
                (da)->capacity *= 2;                                                            \
            }                                                                                   \
            (da)->items = cye_realloc((da)->items, (da)->capacity*sizeof(*(da)->items));        \
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
#define cye_ds_write(ds, buf, size) cye_da_append_many(ds, buf, size)

// TODO make write_zstr the default and  write -> write_char
#define cye_ds_write_zstr(ds, zstr)   \
    do {                              \
        const char *s = (zstr);       \
        size_t n = strlen(s);         \
        cye_da_append_many(ds, s, n); \
    } while (0)

#define cye_ds_write_zero(ds) cye_da_append_many(ds, "", 1)

// Free the memory allocated by a string builder
#define cye_dstring_free(ds) CYE_FREE((ds).items)

#define cye_dstring_printf(ds, fmt, ...) CYE_TODO("LOOL");


//----------------------------------------------------------------------------------
// Mathematics Functions
//----------------------------------------------------------------------------------
#ifndef max
#   define max(value1, value2) ((value1) > (value2)) ? (value1) : (value2);
#endif

#ifndef min
#   define min(value1, value2) ((value1) < (value2)) ? (value1) : (value2);
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

filescope struct {
    usize size;
    byte buffer[CYE_TEMP_CAPACITY];
} temp_data = {0};

filescope Cye_Log_Level threshold_log_level = CYE_LOG_INFO;

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
        return NOB_INVALID_FD;
    }

    return result;
#endif // _WIN32
}
void cye_file_close(Cye_File_Handle handle) {
#ifdef _WIN32
    CloseHandle(handle);
#else
    close(handle);
#endif // _WIN32
}

bool cye_process_wait_all(Cye_Process_DArray procs) {
    bool success = true;
    // TODO: Maybe sucess && fn() instead of fu() && sucess?
    for (usize i = 0; i < procs.count; ++i) {
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
            cye_trace_log(CYE_LOG_ERROR, "Could not wait on command (pid %d): %s", proc, strerror(errno));
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
    for (size_t i = 0; i < cmd.count; ++i) {
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

    if (!cye_rename(binary_path, old_binary_path)) {
        exit(1);
    }
    cye_unreachable("dsadsa");
    // cye_cmd_append(&cmd, cye_rebuild_ourselves(binary_path, source_path));
    if (!cye_cmd_run_sync_and_reset(&cmd)) {
        cye_rename(old_binary_path, binary_path);
        exit(1);
    }

    cye_cmd_append(&cmd, binary_path);
    cye_da_append_many(&cmd, argv, argc);
    if (!cye_cmd_run_sync_and_reset(&cmd)) exit(1);
    exit(0);
}



//------------------------------------------------------------------------------------
// Temporary Storage Functions Implementation
//------------------------------------------------------------------------------------


TString cye_tstrdup(const char *cstr) {
    usize n = strlen(cstr);
    TString result = (TString)cye_talloc(n + 1);
    assert(result != NULL && "Please increase CYE_TEMP_CAPACITY");
    memcpy(result, cstr, n);
    result[n] = '\0';
    return result;
}

rawptr cye_talloc(usize size) {

    if (temp_data.size + size > CYE_TEMP_CAPACITY) return NULL;
    rawptr result = &temp_data.buffer[temp_data.size];
    temp_data.size += size;
    return result;
}

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
    temp_data.size = 0;
}

usize cye_temp_save(void) {
    return temp_data.size;
}

void cye_temp_rewind(usize checkpoint) {
    temp_data.size = checkpoint;
}


//------------------------------------------------------------------------------------
// Path Functions Implementation
//------------------------------------------------------------------------------------

bool cye_mkdir_if_not_exists(const char *path) {
    cye_todo("VAI TRABALHAR VAGABUNDO");
}

bool cye_copy_file(const char *src_path, const char *dst_path) {
    cye_todo("VAI TRABALHAR VAGABUNDO");
}

bool cye_copy_directory_recursively(const char *src_path,
                                    const char *dst_path) {
    cye_todo("VAI TRABALHAR VAGABUNDO");
}

bool cye_read_entire_dir(const char *parent, Cye_Path_DArray *children) {
    cye_todo("VAI TRABALHAR VAGABUNDO");
}

bool cye_write_entire_file(const char *path, const void *data, usize size) {
    cye_todo("VAI TRABALHAR VAGABUNDO");
}

Cye_File_Type cye_get_file_type(const char *path) {
    cye_todo("VAI TRABALHAR VAGABUNDO");
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

bool cye_rename(const char *old_path, const char *new_path) {
    cye_todo("VAI TRABALHAR VAGABUNDO");
}

int cye_needs_rebuild(const char *output_path, const char **input_paths, usize input_paths_count) {
#ifndef _WIN32
    struct stat statbuf = {0};

    if (stat(output_path, &statbuf) < 0) {
        // NOTE: if output does not exist it 100% must be rebuilt
        if (errno == ENOENT) return 1;
        cye_trace_log(CYE_LOG_ERROR, "could not stat %s: %s", output_path, strerror(errno));
        return -1;
    }
    int output_path_time = statbuf.st_mtime;

    for (usize i = 0; i < input_paths_count; ++i) {
        const char *input_path = input_paths[i];
        if (stat(input_path, &statbuf) < 0) {
            // NOTE: non-existing input is an error cause it is needed for building in the first place
            cye_trace_log(CYE_LOG_ERROR, "could not stat %s: %s", input_path, strerror(errno));
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

    for (size_t i = 0; i < input_paths_count; ++i) {
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

// TODO: cye_needs_rebuild like cmd_append
int cye_needs_rebuild1(const char *output_path, const char *input_path) {
    cye_todo("VAI TRABALHAR VAGABUNDO");
}
int cye_file_exists(const char *file_path) {
    cye_todo("VAI TRABALHAR VAGABUNDO");
}
ZString cye_get_current_dir_temp(void) { cye_todo("VAI TRABALHAR VAGABUNDO"); }
bool cye_set_current_dir(const char *path) {
    cye_todo("VAI TRABALHAR VAGABUNDO");
}

bool cye_getsize(ZString path) {
    cye_todo("VAI TRABALHAR VAGABUNDO");
}  // Size  in bytes
bool cye_is_abs(ZString path) {
    cye_todo("VAI TRABALHAR VAGABUNDO");
}  // Check if path  is absolute
bool cye_is_file(ZString path) {
    cye_todo("VAI TRABALHAR VAGABUNDO");
}  // Check if path  is regular  file
bool cye_is_dir(ZString path) {
    cye_todo("VAI TRABALHAR VAGABUNDO");
}  // Check if path  is directory
bool cye_is_link(ZString path) {
    cye_todo("VAI TRABALHAR VAGABUNDO");
}  // Check if path  is symbolic link
bool cye_is_mount(ZString path) {
    cye_todo("VAI TRABALHAR VAGABUNDO");
}  // Check if path  is mount    point

//------------------------------------------------------------------------------------
// Dynamic Array Implementation
//------------------------------------------------------------------------------------

// All are macros xD

//------------------------------------------------------------------------------------
// String Functions Implementation
//------------------------------------------------------------------------------------

bool cye_zstr_ends_with(ZString src, ZString ending) {
    if (!src || !ending) return false;  // NULL check

    usize src_len    = strlen(src);
    usize ending_len = strlen(ending);
    
    // If ending is longer than src, it can't be a suffix
    if (ending_len > src_len) return false;
    
    // Compare the end of src with ending
    return memcmp(src + (src_len - ending_len), ending, ending_len) == 0;
}

bool cye_zstr_starts_with(ZString src, ZString prefix) {
    if (src == NULL || prefix == NULL) return false;
    if (!*prefix)               return true;  // Empty prefix always matches
    if (!*src)                  return false;    // Empty string only matches empty prefix

    usize prefix_len = strlen(prefix);
    usize src_len    = strlen(src);

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

void cye_trace_log(Cye_Log_Level level, const char *fmt, ...) {
    // Level below current threshold, don't log anythin
    if (level < threshold_log_level) return;

    va_list args;
    va_start(args, fmt);
    char buffer[CYE_MAX_TRACELOG_MSG_LENGTH] = { 0 };

    switch (level) {
        case  CYE_LOG_TRACE:   strcpy(buffer, "TRACE: "  ); break;
        case  CYE_LOG_DEBUG:   strcpy(buffer, "DEBUG: "  ); break;
        case  CYE_LOG_INFO:    strcpy(buffer, "INFO: "   ); break;
        case  CYE_LOG_WARNING: strcpy(buffer, "WARNING: "); break;
        case  CYE_LOG_ERROR:   strcpy(buffer, "ERROR: "  ); break;
        case  CYE_LOG_FATAL:   strcpy(buffer, "FATAL: "  ); break;
        default: break;
    }

    unsigned int fmt_size = (unsigned int)strlen(fmt);
    memcpy(
        buffer + strlen(buffer),
        fmt,
        (fmt_size < (CYE_MAX_TRACELOG_MSG_LENGTH - 12))
          ? fmt_size
          : (CYE_MAX_TRACELOG_MSG_LENGTH - 12)
    );

    strcat(buffer, "\n");
    vprintf(buffer, args);
    fflush(stdout);
    va_end(args);

    // If fatal logging, exit program
    if (level == CYE_LOG_FATAL) {
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
#ifndef _CYE_NO_SHORT_NAMES_
#define _CYE_NO_SHORT_NAMES_
#if !defined(CYE_NO_SHORT_NAMES)

//------------------------------------------------------------------------------------
// Process and File Short Names
//------------------------------------------------------------------------------------
#define open_for_write cye_open_for_write
#define file_close cye_file_close
#define process_wait_all cye_process_wait_all
#define process_wait_all_and_reset cye_process_wait_all_and_reset
#define process_wait cye_process_wait

//------------------------------------------------------------------------------------
// Commands Functions
//------------------------------------------------------------------------------------
#define cmd_append cye_cmd_append

#define cmd_extend cye_cmd_extend
#define cmd_free cye_cmd_free

#define ds_write_cmd cye_ds_write_cmd

#define cmd_run_async cye_cmd_run_async
#define cmd_run_async_and_reset cye_cmd_run_async_and_reset
#define cmd_run_async_redirect cye_cmd_run_async_redirect
#define cmd_run_async_redirect_and_reset cye_cmd_run_async_redirect_and_reset

#define cmd_run_sync cye_cmd_run_sync
#define cmd_run_sync_and_reset cye_cmd_run_sync_and_reset
#define cmd_run_sync_redirect cye_cmd_run_sync_redirect
#define cmd_run_sync_redirect_and_reset cye_cmd_run_sync_redirect_and_reset


//------------------------------------------------------------------------------------
// Temporary Storage Functions
//------------------------------------------------------------------------------------
#define tstrdup cye_tstrdup
#define talloc  cye_talloc
#define tprintf cye_tprintf

#define temp_reset cye_temp_reset
#define temp_save cye_temp_save
#define temp_rewind cye_temp_rewind

//------------------------------------------------------------------------------------
// Path Functions
//------------------------------------------------------------------------------------

#define mkdir_if_not_exists cye_mkdir_if_not_exists
#define copy_file cye_copy_file
#define copy_directory_recursively cye_copy_directory_recursively
#define read_entire_dir cye_read_entire_dir
#define write_entire_file cye_write_entire_file
#define get_file_type cye_get_file_type

#define base_name cye_base_name
#define exists cye_exists
#define expand_user cye_expand_user
#define expand_vars cye_expand_vars

#define rename cye_rename
#define needs_rebuild cye_needs_rebuild
// TODO: cye_needs_rebuild like cmd_append
#define needs_rebuild1 cye_needs_rebuild1
#define file_exists cye_file_exists
#define get_current_dir_temp cye_get_current_dir_temp
#define set_current_dir cye_set_current_dir

#define getsize cye_getsize
#define is_abs cye_is_abs
#define is_file cye_is_file
#define is_dir cye_is_dir
#define is_link cye_is_link
#define is_mount cye_is_mount

#define is_same_path cye_is_same_path
#define join cye_join

#define realpath cye_realpath
#define relpath cye_relpath

#define home cye_home
#define cwd cye_cwd
#define parent_dir cye_parent_dir
#define path_owner cye_path_owner
#define dir_remove cye_dir_remove
#define file_remove cye_file_remove
#define path_stem cye_path_stem
#define path_ext cye_path_ext
#define path_touch cye_path_touch

#define chdir cye_chdir
#define mkdir cye_mkdir
#define mkdirs cye_mkdirs
#define remove cye_remove
#define remove_dir cye_remove_dir
#define remove_dirs cye_remove_dirs
#define path_rename cye_path_rename
#define path_renames cye_path_renames
#define replace cye_replace
#define path_scandir cye_path_scandir


//------------------------------------------------------------------------------------
// Dynamic Array
//------------------------------------------------------------------------------------

#define da_append cye_da_append
#define da_free cye_da_free
#define da_append_many cye_da_append_many

//------------------------------------------------------------------------------------
// String Functions
//------------------------------------------------------------------------------------
#define zstr_ends_with cye_zstr_ends_with


//----------------------------------------------------------------------------------
// Dynamic String Functions
//----------------------------------------------------------------------------------
#define ds_write cye_ds_write

// TODO make write_zstr the default and  write -> write_char
#define ds_write_zstr cye_ds_write_zstr
#define ds_write_zero cye_ds_write_zero

// Free the memory allocated by a string builder
#define dstring_free cye_dstring_free

#define dstring_printf cye_dstring_printf


//----------------------------------------------------------------------------------
// Mathematics Functions
//----------------------------------------------------------------------------------
#define min cye_min
#define max cye_max
#define clamp cye_clamp
#define lerp cye_lerp
#define normalize cye_normalize
#define remap cye_remap
#define wrap cye_wrap
#define float_equals cye_float_equals

//------------------------------------------------------------------------------------
// Process and File Functions
//------------------------------------------------------------------------------------
#define open_for_read cye_open_for_read
#define open_for_write cye_open_for_write
#define file_close cye_file_close

//------------------------------------------------------------------------------------
// Utils Functions
//------------------------------------------------------------------------------------
#define trace_log cye_trace_log
#define cpu_architecture *cye_cpu_architecture


#endif // CYE_NO_SHORT_NAMES

#endif // _CYE_NO_SHORT_NAMES_

// EOF
