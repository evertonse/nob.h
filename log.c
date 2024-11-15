# 0 "./tests/making_files.c"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "./tests/making_files.c"

# 1 "./cye.h" 1
# 23 "./cye.h"
# 1 "/usr/include/stdlib.h" 1 3 4
# 26 "/usr/include/stdlib.h" 3 4
# 1 "/usr/include/bits/libc-header-start.h" 1 3 4
# 33 "/usr/include/bits/libc-header-start.h" 3 4
# 1 "/usr/include/features.h" 1 3 4
# 402 "/usr/include/features.h" 3 4
# 1 "/usr/include/features-time64.h" 1 3 4
# 20 "/usr/include/features-time64.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 21 "/usr/include/features-time64.h" 2 3 4
# 1 "/usr/include/bits/timesize.h" 1 3 4
# 19 "/usr/include/bits/timesize.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 20 "/usr/include/bits/timesize.h" 2 3 4
# 22 "/usr/include/features-time64.h" 2 3 4
# 403 "/usr/include/features.h" 2 3 4
# 511 "/usr/include/features.h" 3 4
# 1 "/usr/include/sys/cdefs.h" 1 3 4
# 730 "/usr/include/sys/cdefs.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 731 "/usr/include/sys/cdefs.h" 2 3 4
# 1 "/usr/include/bits/long-double.h" 1 3 4
# 732 "/usr/include/sys/cdefs.h" 2 3 4
# 512 "/usr/include/features.h" 2 3 4
# 535 "/usr/include/features.h" 3 4
# 1 "/usr/include/gnu/stubs.h" 1 3 4
# 10 "/usr/include/gnu/stubs.h" 3 4
# 1 "/usr/include/gnu/stubs-64.h" 1 3 4
# 11 "/usr/include/gnu/stubs.h" 2 3 4
# 536 "/usr/include/features.h" 2 3 4
# 34 "/usr/include/bits/libc-header-start.h" 2 3 4
# 27 "/usr/include/stdlib.h" 2 3 4





# 1 "/usr/lib/gcc/x86_64-pc-linux-gnu/14.2.1/include/stddef.h" 1 3 4
# 214 "/usr/lib/gcc/x86_64-pc-linux-gnu/14.2.1/include/stddef.h" 3 4

# 214 "/usr/lib/gcc/x86_64-pc-linux-gnu/14.2.1/include/stddef.h" 3 4
typedef long unsigned int size_t;
# 329 "/usr/lib/gcc/x86_64-pc-linux-gnu/14.2.1/include/stddef.h" 3 4
typedef int wchar_t;
# 33 "/usr/include/stdlib.h" 2 3 4







# 1 "/usr/include/bits/waitflags.h" 1 3 4
# 41 "/usr/include/stdlib.h" 2 3 4
# 1 "/usr/include/bits/waitstatus.h" 1 3 4
# 42 "/usr/include/stdlib.h" 2 3 4
# 56 "/usr/include/stdlib.h" 3 4
# 1 "/usr/include/bits/floatn.h" 1 3 4
# 119 "/usr/include/bits/floatn.h" 3 4
# 1 "/usr/include/bits/floatn-common.h" 1 3 4
# 24 "/usr/include/bits/floatn-common.h" 3 4
# 1 "/usr/include/bits/long-double.h" 1 3 4
# 25 "/usr/include/bits/floatn-common.h" 2 3 4
# 120 "/usr/include/bits/floatn.h" 2 3 4
# 57 "/usr/include/stdlib.h" 2 3 4


typedef struct
  {
    int quot;
    int rem;
  } div_t;



typedef struct
  {
    long int quot;
    long int rem;
  } ldiv_t;





__extension__ typedef struct
  {
    long long int quot;
    long long int rem;
  } lldiv_t;
# 98 "/usr/include/stdlib.h" 3 4
extern size_t __ctype_get_mb_cur_max (void) __attribute__ ((__nothrow__ , __leaf__)) ;



extern double atof (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;

extern int atoi (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;

extern long int atol (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;



__extension__ extern long long int atoll (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;



extern double strtod (const char *__restrict __nptr,
        char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));



extern float strtof (const char *__restrict __nptr,
       char **__restrict __endptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

extern long double strtold (const char *__restrict __nptr,
       char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 177 "/usr/include/stdlib.h" 3 4
extern long int strtol (const char *__restrict __nptr,
   char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

extern unsigned long int strtoul (const char *__restrict __nptr,
      char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));



__extension__
extern long long int strtoq (const char *__restrict __nptr,
        char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

__extension__
extern unsigned long long int strtouq (const char *__restrict __nptr,
           char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));




__extension__
extern long long int strtoll (const char *__restrict __nptr,
         char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

__extension__
extern unsigned long long int strtoull (const char *__restrict __nptr,
     char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 505 "/usr/include/stdlib.h" 3 4
extern char *l64a (long int __n) __attribute__ ((__nothrow__ , __leaf__)) ;


extern long int a64l (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;




# 1 "/usr/include/sys/types.h" 1 3 4
# 27 "/usr/include/sys/types.h" 3 4


# 1 "/usr/include/bits/types.h" 1 3 4
# 27 "/usr/include/bits/types.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 28 "/usr/include/bits/types.h" 2 3 4
# 1 "/usr/include/bits/timesize.h" 1 3 4
# 19 "/usr/include/bits/timesize.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 20 "/usr/include/bits/timesize.h" 2 3 4
# 29 "/usr/include/bits/types.h" 2 3 4


typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;


typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;

typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;






typedef __int8_t __int_least8_t;
typedef __uint8_t __uint_least8_t;
typedef __int16_t __int_least16_t;
typedef __uint16_t __uint_least16_t;
typedef __int32_t __int_least32_t;
typedef __uint32_t __uint_least32_t;
typedef __int64_t __int_least64_t;
typedef __uint64_t __uint_least64_t;



typedef long int __quad_t;
typedef unsigned long int __u_quad_t;







typedef long int __intmax_t;
typedef unsigned long int __uintmax_t;
# 141 "/usr/include/bits/types.h" 3 4
# 1 "/usr/include/bits/typesizes.h" 1 3 4
# 142 "/usr/include/bits/types.h" 2 3 4
# 1 "/usr/include/bits/time64.h" 1 3 4
# 143 "/usr/include/bits/types.h" 2 3 4


typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct { int __val[2]; } __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;
typedef long int __suseconds64_t;

typedef int __daddr_t;
typedef int __key_t;


typedef int __clockid_t;


typedef void * __timer_t;


typedef long int __blksize_t;




typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;


typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;


typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;


typedef long int __fsword_t;

typedef long int __ssize_t;


typedef long int __syscall_slong_t;

typedef unsigned long int __syscall_ulong_t;



typedef __off64_t __loff_t;
typedef char *__caddr_t;


typedef long int __intptr_t;


typedef unsigned int __socklen_t;




typedef int __sig_atomic_t;
# 30 "/usr/include/sys/types.h" 2 3 4



typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;


typedef __loff_t loff_t;




typedef __ino_t ino_t;
# 59 "/usr/include/sys/types.h" 3 4
typedef __dev_t dev_t;




typedef __gid_t gid_t;




typedef __mode_t mode_t;




typedef __nlink_t nlink_t;




typedef __uid_t uid_t;





typedef __off_t off_t;
# 97 "/usr/include/sys/types.h" 3 4
typedef __pid_t pid_t;





typedef __id_t id_t;




typedef __ssize_t ssize_t;





typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;





typedef __key_t key_t;




# 1 "/usr/include/bits/types/clock_t.h" 1 3 4






typedef __clock_t clock_t;
# 127 "/usr/include/sys/types.h" 2 3 4

# 1 "/usr/include/bits/types/clockid_t.h" 1 3 4






typedef __clockid_t clockid_t;
# 129 "/usr/include/sys/types.h" 2 3 4
# 1 "/usr/include/bits/types/time_t.h" 1 3 4
# 10 "/usr/include/bits/types/time_t.h" 3 4
typedef __time_t time_t;
# 130 "/usr/include/sys/types.h" 2 3 4
# 1 "/usr/include/bits/types/timer_t.h" 1 3 4






typedef __timer_t timer_t;
# 131 "/usr/include/sys/types.h" 2 3 4
# 144 "/usr/include/sys/types.h" 3 4
# 1 "/usr/lib/gcc/x86_64-pc-linux-gnu/14.2.1/include/stddef.h" 1 3 4
# 145 "/usr/include/sys/types.h" 2 3 4



typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;




# 1 "/usr/include/bits/stdint-intn.h" 1 3 4
# 24 "/usr/include/bits/stdint-intn.h" 3 4
typedef __int8_t int8_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;
typedef __int64_t int64_t;
# 156 "/usr/include/sys/types.h" 2 3 4


typedef __uint8_t u_int8_t;
typedef __uint16_t u_int16_t;
typedef __uint32_t u_int32_t;
typedef __uint64_t u_int64_t;


typedef int register_t __attribute__ ((__mode__ (__word__)));
# 176 "/usr/include/sys/types.h" 3 4
# 1 "/usr/include/endian.h" 1 3 4
# 24 "/usr/include/endian.h" 3 4
# 1 "/usr/include/bits/endian.h" 1 3 4
# 35 "/usr/include/bits/endian.h" 3 4
# 1 "/usr/include/bits/endianness.h" 1 3 4
# 36 "/usr/include/bits/endian.h" 2 3 4
# 25 "/usr/include/endian.h" 2 3 4
# 35 "/usr/include/endian.h" 3 4
# 1 "/usr/include/bits/byteswap.h" 1 3 4
# 33 "/usr/include/bits/byteswap.h" 3 4
static __inline __uint16_t
__bswap_16 (__uint16_t __bsx)
{

  return __builtin_bswap16 (__bsx);



}






static __inline __uint32_t
__bswap_32 (__uint32_t __bsx)
{

  return __builtin_bswap32 (__bsx);



}
# 69 "/usr/include/bits/byteswap.h" 3 4
__extension__ static __inline __uint64_t
__bswap_64 (__uint64_t __bsx)
{

  return __builtin_bswap64 (__bsx);



}
# 36 "/usr/include/endian.h" 2 3 4
# 1 "/usr/include/bits/uintn-identity.h" 1 3 4
# 32 "/usr/include/bits/uintn-identity.h" 3 4
static __inline __uint16_t
__uint16_identity (__uint16_t __x)
{
  return __x;
}

static __inline __uint32_t
__uint32_identity (__uint32_t __x)
{
  return __x;
}

static __inline __uint64_t
__uint64_identity (__uint64_t __x)
{
  return __x;
}
# 37 "/usr/include/endian.h" 2 3 4
# 177 "/usr/include/sys/types.h" 2 3 4


# 1 "/usr/include/sys/select.h" 1 3 4
# 30 "/usr/include/sys/select.h" 3 4
# 1 "/usr/include/bits/select.h" 1 3 4
# 31 "/usr/include/sys/select.h" 2 3 4


# 1 "/usr/include/bits/types/sigset_t.h" 1 3 4



# 1 "/usr/include/bits/types/__sigset_t.h" 1 3 4




typedef struct
{
  unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
} __sigset_t;
# 5 "/usr/include/bits/types/sigset_t.h" 2 3 4


typedef __sigset_t sigset_t;
# 34 "/usr/include/sys/select.h" 2 3 4



# 1 "/usr/include/bits/types/struct_timeval.h" 1 3 4







struct timeval
{




  __time_t tv_sec;
  __suseconds_t tv_usec;

};
# 38 "/usr/include/sys/select.h" 2 3 4

# 1 "/usr/include/bits/types/struct_timespec.h" 1 3 4
# 11 "/usr/include/bits/types/struct_timespec.h" 3 4
struct timespec
{



  __time_t tv_sec;




  __syscall_slong_t tv_nsec;
# 31 "/usr/include/bits/types/struct_timespec.h" 3 4
};
# 40 "/usr/include/sys/select.h" 2 3 4



typedef __suseconds_t suseconds_t;





typedef long int __fd_mask;
# 59 "/usr/include/sys/select.h" 3 4
typedef struct
  {






    __fd_mask __fds_bits[1024 / (8 * (int) sizeof (__fd_mask))];


  } fd_set;






typedef __fd_mask fd_mask;
# 91 "/usr/include/sys/select.h" 3 4

# 102 "/usr/include/sys/select.h" 3 4
extern int select (int __nfds, fd_set *__restrict __readfds,
     fd_set *__restrict __writefds,
     fd_set *__restrict __exceptfds,
     struct timeval *__restrict __timeout);
# 127 "/usr/include/sys/select.h" 3 4
extern int pselect (int __nfds, fd_set *__restrict __readfds,
      fd_set *__restrict __writefds,
      fd_set *__restrict __exceptfds,
      const struct timespec *__restrict __timeout,
      const __sigset_t *__restrict __sigmask);
# 153 "/usr/include/sys/select.h" 3 4

# 180 "/usr/include/sys/types.h" 2 3 4





typedef __blksize_t blksize_t;






typedef __blkcnt_t blkcnt_t;



typedef __fsblkcnt_t fsblkcnt_t;



typedef __fsfilcnt_t fsfilcnt_t;
# 227 "/usr/include/sys/types.h" 3 4
# 1 "/usr/include/bits/pthreadtypes.h" 1 3 4
# 23 "/usr/include/bits/pthreadtypes.h" 3 4
# 1 "/usr/include/bits/thread-shared-types.h" 1 3 4
# 44 "/usr/include/bits/thread-shared-types.h" 3 4
# 1 "/usr/include/bits/pthreadtypes-arch.h" 1 3 4
# 21 "/usr/include/bits/pthreadtypes-arch.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 22 "/usr/include/bits/pthreadtypes-arch.h" 2 3 4
# 45 "/usr/include/bits/thread-shared-types.h" 2 3 4

# 1 "/usr/include/bits/atomic_wide_counter.h" 1 3 4
# 25 "/usr/include/bits/atomic_wide_counter.h" 3 4
typedef union
{
  __extension__ unsigned long long int __value64;
  struct
  {
    unsigned int __low;
    unsigned int __high;
  } __value32;
} __atomic_wide_counter;
# 47 "/usr/include/bits/thread-shared-types.h" 2 3 4




typedef struct __pthread_internal_list
{
  struct __pthread_internal_list *__prev;
  struct __pthread_internal_list *__next;
} __pthread_list_t;

typedef struct __pthread_internal_slist
{
  struct __pthread_internal_slist *__next;
} __pthread_slist_t;
# 76 "/usr/include/bits/thread-shared-types.h" 3 4
# 1 "/usr/include/bits/struct_mutex.h" 1 3 4
# 22 "/usr/include/bits/struct_mutex.h" 3 4
struct __pthread_mutex_s
{
  int __lock;
  unsigned int __count;
  int __owner;

  unsigned int __nusers;



  int __kind;

  short __spins;
  short __elision;
  __pthread_list_t __list;
# 53 "/usr/include/bits/struct_mutex.h" 3 4
};
# 77 "/usr/include/bits/thread-shared-types.h" 2 3 4
# 89 "/usr/include/bits/thread-shared-types.h" 3 4
# 1 "/usr/include/bits/struct_rwlock.h" 1 3 4
# 23 "/usr/include/bits/struct_rwlock.h" 3 4
struct __pthread_rwlock_arch_t
{
  unsigned int __readers;
  unsigned int __writers;
  unsigned int __wrphase_futex;
  unsigned int __writers_futex;
  unsigned int __pad3;
  unsigned int __pad4;

  int __cur_writer;
  int __shared;
  signed char __rwelision;




  unsigned char __pad1[7];


  unsigned long int __pad2;


  unsigned int __flags;
# 55 "/usr/include/bits/struct_rwlock.h" 3 4
};
# 90 "/usr/include/bits/thread-shared-types.h" 2 3 4




struct __pthread_cond_s
{
  __atomic_wide_counter __wseq;
  __atomic_wide_counter __g1_start;
  unsigned int __g_refs[2] ;
  unsigned int __g_size[2];
  unsigned int __g1_orig_size;
  unsigned int __wrefs;
  unsigned int __g_signals[2];
};

typedef unsigned int __tss_t;
typedef unsigned long int __thrd_t;

typedef struct
{
  int __data ;
} __once_flag;
# 24 "/usr/include/bits/pthreadtypes.h" 2 3 4



typedef unsigned long int pthread_t;




typedef union
{
  char __size[4];
  int __align;
} pthread_mutexattr_t;




typedef union
{
  char __size[4];
  int __align;
} pthread_condattr_t;



typedef unsigned int pthread_key_t;



typedef int pthread_once_t;


union pthread_attr_t
{
  char __size[56];
  long int __align;
};

typedef union pthread_attr_t pthread_attr_t;




typedef union
{
  struct __pthread_mutex_s __data;
  char __size[40];
  long int __align;
} pthread_mutex_t;


typedef union
{
  struct __pthread_cond_s __data;
  char __size[48];
  __extension__ long long int __align;
} pthread_cond_t;





typedef union
{
  struct __pthread_rwlock_arch_t __data;
  char __size[56];
  long int __align;
} pthread_rwlock_t;

typedef union
{
  char __size[8];
  long int __align;
} pthread_rwlockattr_t;





typedef volatile int pthread_spinlock_t;




typedef union
{
  char __size[32];
  long int __align;
} pthread_barrier_t;

typedef union
{
  char __size[4];
  int __align;
} pthread_barrierattr_t;
# 228 "/usr/include/sys/types.h" 2 3 4



# 515 "/usr/include/stdlib.h" 2 3 4






extern long int random (void) __attribute__ ((__nothrow__ , __leaf__));


extern void srandom (unsigned int __seed) __attribute__ ((__nothrow__ , __leaf__));





extern char *initstate (unsigned int __seed, char *__statebuf,
   size_t __statelen) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));



extern char *setstate (char *__statebuf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));







struct random_data
  {
    int32_t *fptr;
    int32_t *rptr;
    int32_t *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    int32_t *end_ptr;
  };

extern int random_r (struct random_data *__restrict __buf,
       int32_t *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern int srandom_r (unsigned int __seed, struct random_data *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

extern int initstate_r (unsigned int __seed, char *__restrict __statebuf,
   size_t __statelen,
   struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)));

extern int setstate_r (char *__restrict __statebuf,
         struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));





extern int rand (void) __attribute__ ((__nothrow__ , __leaf__));

extern void srand (unsigned int __seed) __attribute__ ((__nothrow__ , __leaf__));



extern int rand_r (unsigned int *__seed) __attribute__ ((__nothrow__ , __leaf__));







extern double drand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern double erand48 (unsigned short int __xsubi[3]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern long int lrand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern long int nrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern long int mrand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern long int jrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern void srand48 (long int __seedval) __attribute__ ((__nothrow__ , __leaf__));
extern unsigned short int *seed48 (unsigned short int __seed16v[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void lcong48 (unsigned short int __param[7]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





struct drand48_data
  {
    unsigned short int __x[3];
    unsigned short int __old_x[3];
    unsigned short int __c;
    unsigned short int __init;
    __extension__ unsigned long long int __a;

  };


extern int drand48_r (struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int erand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int lrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int nrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int mrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int jrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int srand48_r (long int __seedval, struct drand48_data *__buffer)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

extern int seed48_r (unsigned short int __seed16v[3],
       struct drand48_data *__buffer) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern int lcong48_r (unsigned short int __param[7],
        struct drand48_data *__buffer)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern __uint32_t arc4random (void)
     __attribute__ ((__nothrow__ , __leaf__)) ;


extern void arc4random_buf (void *__buf, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));



extern __uint32_t arc4random_uniform (__uint32_t __upper_bound)
     __attribute__ ((__nothrow__ , __leaf__)) ;




extern void *malloc (size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__))
     __attribute__ ((__alloc_size__ (1))) ;

extern void *calloc (size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__alloc_size__ (1, 2))) ;






extern void *realloc (void *__ptr, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__)) __attribute__ ((__alloc_size__ (2)));


extern void free (void *__ptr) __attribute__ ((__nothrow__ , __leaf__));







extern void *reallocarray (void *__ptr, size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__))
     __attribute__ ((__alloc_size__ (2, 3)))
    __attribute__ ((__malloc__ (__builtin_free, 1)));


extern void *reallocarray (void *__ptr, size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__ (reallocarray, 1)));



# 1 "/usr/include/alloca.h" 1 3 4
# 24 "/usr/include/alloca.h" 3 4
# 1 "/usr/lib/gcc/x86_64-pc-linux-gnu/14.2.1/include/stddef.h" 1 3 4
# 25 "/usr/include/alloca.h" 2 3 4







extern void *alloca (size_t __size) __attribute__ ((__nothrow__ , __leaf__));






# 707 "/usr/include/stdlib.h" 2 3 4





extern void *valloc (size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__))
     __attribute__ ((__alloc_size__ (1))) ;




extern int posix_memalign (void **__memptr, size_t __alignment, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;




extern void *aligned_alloc (size_t __alignment, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__alloc_align__ (1)))
     __attribute__ ((__alloc_size__ (2))) ;



extern void abort (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));



extern int atexit (void (*__func) (void)) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));







extern int at_quick_exit (void (*__func) (void)) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));






extern int on_exit (void (*__func) (int __status, void *__arg), void *__arg)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





extern void exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));





extern void quick_exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));





extern void _Exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));




extern char *getenv (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
# 786 "/usr/include/stdlib.h" 3 4
extern int putenv (char *__string) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





extern int setenv (const char *__name, const char *__value, int __replace)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));


extern int unsetenv (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));






extern int clearenv (void) __attribute__ ((__nothrow__ , __leaf__));
# 814 "/usr/include/stdlib.h" 3 4
extern char *mktemp (char *__template) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 827 "/usr/include/stdlib.h" 3 4
extern int mkstemp (char *__template) __attribute__ ((__nonnull__ (1))) ;
# 849 "/usr/include/stdlib.h" 3 4
extern int mkstemps (char *__template, int __suffixlen) __attribute__ ((__nonnull__ (1))) ;
# 870 "/usr/include/stdlib.h" 3 4
extern char *mkdtemp (char *__template) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
# 923 "/usr/include/stdlib.h" 3 4
extern int system (const char *__command) ;
# 940 "/usr/include/stdlib.h" 3 4
extern char *realpath (const char *__restrict __name,
         char *__restrict __resolved) __attribute__ ((__nothrow__ , __leaf__)) ;






typedef int (*__compar_fn_t) (const void *, const void *);
# 960 "/usr/include/stdlib.h" 3 4
extern void *bsearch (const void *__key, const void *__base,
        size_t __nmemb, size_t __size, __compar_fn_t __compar)
     __attribute__ ((__nonnull__ (1, 2, 5))) ;







extern void qsort (void *__base, size_t __nmemb, size_t __size,
     __compar_fn_t __compar) __attribute__ ((__nonnull__ (1, 4)));
# 980 "/usr/include/stdlib.h" 3 4
extern int abs (int __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
extern long int labs (long int __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;


__extension__ extern long long int llabs (long long int __x)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;






extern div_t div (int __numer, int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
extern ldiv_t ldiv (long int __numer, long int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;


__extension__ extern lldiv_t lldiv (long long int __numer,
        long long int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
# 1012 "/usr/include/stdlib.h" 3 4
extern char *ecvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;




extern char *fcvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;




extern char *gcvt (double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3))) ;




extern char *qecvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qfcvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qgcvt (long double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3))) ;




extern int ecvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int fcvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));

extern int qecvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int qfcvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));





extern int mblen (const char *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));


extern int mbtowc (wchar_t *__restrict __pwc,
     const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));


extern int wctomb (char *__s, wchar_t __wchar) __attribute__ ((__nothrow__ , __leaf__));



extern size_t mbstowcs (wchar_t *__restrict __pwcs,
   const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__ , __leaf__))
    __attribute__ ((__access__ (__read_only__, 2)));

extern size_t wcstombs (char *__restrict __s,
   const wchar_t *__restrict __pwcs, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__access__ (__write_only__, 1, 3)))
  __attribute__ ((__access__ (__read_only__, 2)));






extern int rpmatch (const char *__response) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
# 1099 "/usr/include/stdlib.h" 3 4
extern int getsubopt (char **__restrict __optionp,
        char *const *__restrict __tokens,
        char **__restrict __valuep)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2, 3))) ;
# 1145 "/usr/include/stdlib.h" 3 4
extern int getloadavg (double __loadavg[], int __nelem)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 1155 "/usr/include/stdlib.h" 3 4
# 1 "/usr/include/bits/stdlib-float.h" 1 3 4
# 1156 "/usr/include/stdlib.h" 2 3 4
# 1167 "/usr/include/stdlib.h" 3 4

# 24 "./cye.h" 2
# 1 "/usr/lib/gcc/x86_64-pc-linux-gnu/14.2.1/include/stdarg.h" 1 3 4
# 40 "/usr/lib/gcc/x86_64-pc-linux-gnu/14.2.1/include/stdarg.h" 3 4
typedef __builtin_va_list __gnuc_va_list;
# 103 "/usr/lib/gcc/x86_64-pc-linux-gnu/14.2.1/include/stdarg.h" 3 4
typedef __gnuc_va_list va_list;
# 25 "./cye.h" 2
# 1 "/usr/include/string.h" 1 3 4
# 26 "/usr/include/string.h" 3 4
# 1 "/usr/include/bits/libc-header-start.h" 1 3 4
# 27 "/usr/include/string.h" 2 3 4






# 1 "/usr/lib/gcc/x86_64-pc-linux-gnu/14.2.1/include/stddef.h" 1 3 4
# 34 "/usr/include/string.h" 2 3 4
# 43 "/usr/include/string.h" 3 4
extern void *memcpy (void *__restrict __dest, const void *__restrict __src,
       size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern void *memmove (void *__dest, const void *__src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));





extern void *memccpy (void *__restrict __dest, const void *__restrict __src,
        int __c, size_t __n)
    __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__access__ (__write_only__, 1, 4)));




extern void *memset (void *__s, int __c, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int memcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 80 "/usr/include/string.h" 3 4
extern int __memcmpeq (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 107 "/usr/include/string.h" 3 4
extern void *memchr (const void *__s, int __c, size_t __n)
      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 141 "/usr/include/string.h" 3 4
extern char *strcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern char *strncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern char *strcat (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern char *strncat (char *__restrict __dest, const char *__restrict __src,
        size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strcmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

extern int strncmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strcoll (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

extern size_t strxfrm (char *__restrict __dest,
         const char *__restrict __src, size_t __n)
    __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) __attribute__ ((__access__ (__write_only__, 1, 3)));



# 1 "/usr/include/bits/types/locale_t.h" 1 3 4
# 22 "/usr/include/bits/types/locale_t.h" 3 4
# 1 "/usr/include/bits/types/__locale_t.h" 1 3 4
# 27 "/usr/include/bits/types/__locale_t.h" 3 4
struct __locale_struct
{

  struct __locale_data *__locales[13];


  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;


  const char *__names[13];
};

typedef struct __locale_struct *__locale_t;
# 23 "/usr/include/bits/types/locale_t.h" 2 3 4

typedef __locale_t locale_t;
# 173 "/usr/include/string.h" 2 3 4


extern int strcoll_l (const char *__s1, const char *__s2, locale_t __l)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));


extern size_t strxfrm_l (char *__dest, const char *__src, size_t __n,
    locale_t __l) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)))
     __attribute__ ((__access__ (__write_only__, 1, 3)));





extern char *strdup (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));






extern char *strndup (const char *__string, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));
# 246 "/usr/include/string.h" 3 4
extern char *strchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 273 "/usr/include/string.h" 3 4
extern char *strrchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 286 "/usr/include/string.h" 3 4
extern char *strchrnul (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));





extern size_t strcspn (const char *__s, const char *__reject)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern size_t strspn (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 323 "/usr/include/string.h" 3 4
extern char *strpbrk (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 350 "/usr/include/string.h" 3 4
extern char *strstr (const char *__haystack, const char *__needle)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));




extern char *strtok (char *__restrict __s, const char *__restrict __delim)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));



extern char *__strtok_r (char *__restrict __s,
    const char *__restrict __delim,
    char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));

extern char *strtok_r (char *__restrict __s, const char *__restrict __delim,
         char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
# 380 "/usr/include/string.h" 3 4
extern char *strcasestr (const char *__haystack, const char *__needle)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));







extern void *memmem (const void *__haystack, size_t __haystacklen,
       const void *__needle, size_t __needlelen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 3)))
    __attribute__ ((__access__ (__read_only__, 1, 2)))
    __attribute__ ((__access__ (__read_only__, 3, 4)));



extern void *__mempcpy (void *__restrict __dest,
   const void *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *mempcpy (void *__restrict __dest,
        const void *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));




extern size_t strlen (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));




extern size_t strnlen (const char *__string, size_t __maxlen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));




extern char *strerror (int __errnum) __attribute__ ((__nothrow__ , __leaf__));
# 432 "/usr/include/string.h" 3 4
extern int strerror_r (int __errnum, char *__buf, size_t __buflen) __asm__ ("" "__xpg_strerror_r") __attribute__ ((__nothrow__ , __leaf__))

                        __attribute__ ((__nonnull__ (2)))
    __attribute__ ((__access__ (__write_only__, 2, 3)));
# 458 "/usr/include/string.h" 3 4
extern char *strerror_l (int __errnum, locale_t __l) __attribute__ ((__nothrow__ , __leaf__));



# 1 "/usr/include/strings.h" 1 3 4
# 23 "/usr/include/strings.h" 3 4
# 1 "/usr/lib/gcc/x86_64-pc-linux-gnu/14.2.1/include/stddef.h" 1 3 4
# 24 "/usr/include/strings.h" 2 3 4










extern int bcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern void bcopy (const void *__src, void *__dest, size_t __n)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern void bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 68 "/usr/include/strings.h" 3 4
extern char *index (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 96 "/usr/include/strings.h" 3 4
extern char *rindex (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));






extern int ffs (int __i) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));





extern int ffsl (long int __l) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
__extension__ extern int ffsll (long long int __ll)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));



extern int strcasecmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strncasecmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));






extern int strcasecmp_l (const char *__s1, const char *__s2, locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));



extern int strncasecmp_l (const char *__s1, const char *__s2,
     size_t __n, locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 4)));



# 463 "/usr/include/string.h" 2 3 4



extern void explicit_bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)))
    __attribute__ ((__access__ (__write_only__, 1, 2)));



extern char *strsep (char **__restrict __stringp,
       const char *__restrict __delim)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));




extern char *strsignal (int __sig) __attribute__ ((__nothrow__ , __leaf__));
# 489 "/usr/include/string.h" 3 4
extern char *__stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));



extern char *__stpncpy (char *__restrict __dest,
   const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));




extern size_t strlcpy (char *__restrict __dest,
         const char *__restrict __src, size_t __n)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__access__ (__write_only__, 1, 3)));



extern size_t strlcat (char *__restrict __dest,
         const char *__restrict __src, size_t __n)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__access__ (__read_write__, 1, 3)));
# 552 "/usr/include/string.h" 3 4

# 26 "./cye.h" 2
# 1 "/usr/include/errno.h" 1 3 4
# 28 "/usr/include/errno.h" 3 4
# 1 "/usr/include/bits/errno.h" 1 3 4
# 26 "/usr/include/bits/errno.h" 3 4
# 1 "/usr/include/linux/errno.h" 1 3 4
# 1 "/usr/include/asm/errno.h" 1 3 4
# 1 "/usr/include/asm-generic/errno.h" 1 3 4




# 1 "/usr/include/asm-generic/errno-base.h" 1 3 4
# 6 "/usr/include/asm-generic/errno.h" 2 3 4
# 2 "/usr/include/asm/errno.h" 2 3 4
# 2 "/usr/include/linux/errno.h" 2 3 4
# 27 "/usr/include/bits/errno.h" 2 3 4
# 29 "/usr/include/errno.h" 2 3 4








extern int *__errno_location (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
# 52 "/usr/include/errno.h" 3 4

# 27 "./cye.h" 2
# 1 "/usr/include/ctype.h" 1 3 4
# 28 "/usr/include/ctype.h" 3 4

# 46 "/usr/include/ctype.h" 3 4
enum
{
  _ISupper = ((0) < 8 ? ((1 << (0)) << 8) : ((1 << (0)) >> 8)),
  _ISlower = ((1) < 8 ? ((1 << (1)) << 8) : ((1 << (1)) >> 8)),
  _ISalpha = ((2) < 8 ? ((1 << (2)) << 8) : ((1 << (2)) >> 8)),
  _ISdigit = ((3) < 8 ? ((1 << (3)) << 8) : ((1 << (3)) >> 8)),
  _ISxdigit = ((4) < 8 ? ((1 << (4)) << 8) : ((1 << (4)) >> 8)),
  _ISspace = ((5) < 8 ? ((1 << (5)) << 8) : ((1 << (5)) >> 8)),
  _ISprint = ((6) < 8 ? ((1 << (6)) << 8) : ((1 << (6)) >> 8)),
  _ISgraph = ((7) < 8 ? ((1 << (7)) << 8) : ((1 << (7)) >> 8)),
  _ISblank = ((8) < 8 ? ((1 << (8)) << 8) : ((1 << (8)) >> 8)),
  _IScntrl = ((9) < 8 ? ((1 << (9)) << 8) : ((1 << (9)) >> 8)),
  _ISpunct = ((10) < 8 ? ((1 << (10)) << 8) : ((1 << (10)) >> 8)),
  _ISalnum = ((11) < 8 ? ((1 << (11)) << 8) : ((1 << (11)) >> 8))
};
# 79 "/usr/include/ctype.h" 3 4
extern const unsigned short int **__ctype_b_loc (void)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern const __int32_t **__ctype_tolower_loc (void)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern const __int32_t **__ctype_toupper_loc (void)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
# 108 "/usr/include/ctype.h" 3 4
extern int isalnum (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isalpha (int) __attribute__ ((__nothrow__ , __leaf__));
extern int iscntrl (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isdigit (int) __attribute__ ((__nothrow__ , __leaf__));
extern int islower (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isgraph (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isprint (int) __attribute__ ((__nothrow__ , __leaf__));
extern int ispunct (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isspace (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isupper (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isxdigit (int) __attribute__ ((__nothrow__ , __leaf__));



extern int tolower (int __c) __attribute__ ((__nothrow__ , __leaf__));


extern int toupper (int __c) __attribute__ ((__nothrow__ , __leaf__));




extern int isblank (int) __attribute__ ((__nothrow__ , __leaf__));
# 142 "/usr/include/ctype.h" 3 4
extern int isascii (int __c) __attribute__ ((__nothrow__ , __leaf__));



extern int toascii (int __c) __attribute__ ((__nothrow__ , __leaf__));



extern int _toupper (int) __attribute__ ((__nothrow__ , __leaf__));
extern int _tolower (int) __attribute__ ((__nothrow__ , __leaf__));
# 251 "/usr/include/ctype.h" 3 4
extern int isalnum_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isalpha_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int iscntrl_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isdigit_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int islower_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isgraph_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isprint_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int ispunct_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isspace_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isupper_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isxdigit_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));

extern int isblank_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));



extern int __tolower_l (int __c, locale_t __l) __attribute__ ((__nothrow__ , __leaf__));
extern int tolower_l (int __c, locale_t __l) __attribute__ ((__nothrow__ , __leaf__));


extern int __toupper_l (int __c, locale_t __l) __attribute__ ((__nothrow__ , __leaf__));
extern int toupper_l (int __c, locale_t __l) __attribute__ ((__nothrow__ , __leaf__));
# 327 "/usr/include/ctype.h" 3 4

# 28 "./cye.h" 2
# 1 "/usr/lib/gcc/x86_64-pc-linux-gnu/14.2.1/include/limits.h" 1 3 4
# 34 "/usr/lib/gcc/x86_64-pc-linux-gnu/14.2.1/include/limits.h" 3 4
# 1 "/usr/lib/gcc/x86_64-pc-linux-gnu/14.2.1/include/syslimits.h" 1 3 4






# 1 "/usr/lib/gcc/x86_64-pc-linux-gnu/14.2.1/include/limits.h" 1 3 4
# 210 "/usr/lib/gcc/x86_64-pc-linux-gnu/14.2.1/include/limits.h" 3 4
# 1 "/usr/include/limits.h" 1 3 4
# 26 "/usr/include/limits.h" 3 4
# 1 "/usr/include/bits/libc-header-start.h" 1 3 4
# 27 "/usr/include/limits.h" 2 3 4
# 195 "/usr/include/limits.h" 3 4
# 1 "/usr/include/bits/posix1_lim.h" 1 3 4
# 27 "/usr/include/bits/posix1_lim.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 28 "/usr/include/bits/posix1_lim.h" 2 3 4
# 161 "/usr/include/bits/posix1_lim.h" 3 4
# 1 "/usr/include/bits/local_lim.h" 1 3 4
# 38 "/usr/include/bits/local_lim.h" 3 4
# 1 "/usr/include/linux/limits.h" 1 3 4
# 39 "/usr/include/bits/local_lim.h" 2 3 4
# 81 "/usr/include/bits/local_lim.h" 3 4
# 1 "/usr/include/bits/pthread_stack_min-dynamic.h" 1 3 4
# 29 "/usr/include/bits/pthread_stack_min-dynamic.h" 3 4
# 1 "/usr/include/bits/pthread_stack_min.h" 1 3 4
# 30 "/usr/include/bits/pthread_stack_min-dynamic.h" 2 3 4
# 82 "/usr/include/bits/local_lim.h" 2 3 4
# 162 "/usr/include/bits/posix1_lim.h" 2 3 4
# 196 "/usr/include/limits.h" 2 3 4



# 1 "/usr/include/bits/posix2_lim.h" 1 3 4
# 200 "/usr/include/limits.h" 2 3 4
# 211 "/usr/lib/gcc/x86_64-pc-linux-gnu/14.2.1/include/limits.h" 2 3 4
# 8 "/usr/lib/gcc/x86_64-pc-linux-gnu/14.2.1/include/syslimits.h" 2 3 4
# 35 "/usr/lib/gcc/x86_64-pc-linux-gnu/14.2.1/include/limits.h" 2 3 4
# 29 "./cye.h" 2
# 1 "/usr/include/math.h" 1 3 4
# 27 "/usr/include/math.h" 3 4
# 1 "/usr/include/bits/libc-header-start.h" 1 3 4
# 28 "/usr/include/math.h" 2 3 4












# 1 "/usr/include/bits/math-vector.h" 1 3 4
# 25 "/usr/include/bits/math-vector.h" 3 4
# 1 "/usr/include/bits/libm-simd-decl-stubs.h" 1 3 4
# 26 "/usr/include/bits/math-vector.h" 2 3 4
# 41 "/usr/include/math.h" 2 3 4
# 152 "/usr/include/math.h" 3 4
# 1 "/usr/include/bits/flt-eval-method.h" 1 3 4
# 153 "/usr/include/math.h" 2 3 4
# 163 "/usr/include/math.h" 3 4
typedef float float_t;
typedef double double_t;
# 204 "/usr/include/math.h" 3 4
# 1 "/usr/include/bits/fp-logb.h" 1 3 4
# 205 "/usr/include/math.h" 2 3 4
# 247 "/usr/include/math.h" 3 4
# 1 "/usr/include/bits/fp-fast.h" 1 3 4
# 248 "/usr/include/math.h" 2 3 4
# 312 "/usr/include/math.h" 3 4
# 1 "/usr/include/bits/mathcalls-helper-functions.h" 1 3 4
# 20 "/usr/include/bits/mathcalls-helper-functions.h" 3 4
extern int __fpclassify (double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));


extern int __signbit (double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));



extern int __isinf (double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));


extern int __finite (double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));


extern int __isnan (double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));


extern int __iseqsig (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));


extern int __issignaling (double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
# 313 "/usr/include/math.h" 2 3 4
# 1 "/usr/include/bits/mathcalls.h" 1 3 4
# 53 "/usr/include/bits/mathcalls.h" 3 4
 extern double acos (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __acos (double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern double asin (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __asin (double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern double atan (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __atan (double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern double atan2 (double __y, double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __atan2 (double __y, double __x) __attribute__ ((__nothrow__ , __leaf__));


 extern double cos (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __cos (double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern double sin (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __sin (double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern double tan (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __tan (double __x) __attribute__ ((__nothrow__ , __leaf__));




 extern double cosh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __cosh (double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern double sinh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __sinh (double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern double tanh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __tanh (double __x) __attribute__ ((__nothrow__ , __leaf__));
# 85 "/usr/include/bits/mathcalls.h" 3 4
 extern double acosh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __acosh (double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern double asinh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __asinh (double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern double atanh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __atanh (double __x) __attribute__ ((__nothrow__ , __leaf__));





 extern double exp (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __exp (double __x) __attribute__ ((__nothrow__ , __leaf__));


extern double frexp (double __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__)); extern double __frexp (double __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__));


extern double ldexp (double __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__)); extern double __ldexp (double __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__));


 extern double log (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __log (double __x) __attribute__ ((__nothrow__ , __leaf__));


 extern double log10 (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __log10 (double __x) __attribute__ ((__nothrow__ , __leaf__));


extern double modf (double __x, double *__iptr) __attribute__ ((__nothrow__ , __leaf__)); extern double __modf (double __x, double *__iptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
# 134 "/usr/include/bits/mathcalls.h" 3 4
 extern double expm1 (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __expm1 (double __x) __attribute__ ((__nothrow__ , __leaf__));


 extern double log1p (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __log1p (double __x) __attribute__ ((__nothrow__ , __leaf__));


extern double logb (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __logb (double __x) __attribute__ ((__nothrow__ , __leaf__));




 extern double exp2 (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __exp2 (double __x) __attribute__ ((__nothrow__ , __leaf__));


 extern double log2 (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __log2 (double __x) __attribute__ ((__nothrow__ , __leaf__));






 extern double pow (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __pow (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));


extern double sqrt (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __sqrt (double __x) __attribute__ ((__nothrow__ , __leaf__));



 extern double hypot (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __hypot (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));




 extern double cbrt (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __cbrt (double __x) __attribute__ ((__nothrow__ , __leaf__));






extern double ceil (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __ceil (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern double fabs (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fabs (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern double floor (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __floor (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern double fmod (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __fmod (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
# 192 "/usr/include/bits/mathcalls.h" 3 4
extern int isinf (double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));




extern int finite (double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));


extern double drem (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __drem (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));



extern double significand (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __significand (double __x) __attribute__ ((__nothrow__ , __leaf__));






extern double copysign (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __copysign (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));




extern double nan (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)); extern double __nan (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__));
# 228 "/usr/include/bits/mathcalls.h" 3 4
extern int isnan (double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));





extern double j0 (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __j0 (double) __attribute__ ((__nothrow__ , __leaf__));
extern double j1 (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __j1 (double) __attribute__ ((__nothrow__ , __leaf__));
extern double jn (int, double) __attribute__ ((__nothrow__ , __leaf__)); extern double __jn (int, double) __attribute__ ((__nothrow__ , __leaf__));
extern double y0 (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __y0 (double) __attribute__ ((__nothrow__ , __leaf__));
extern double y1 (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __y1 (double) __attribute__ ((__nothrow__ , __leaf__));
extern double yn (int, double) __attribute__ ((__nothrow__ , __leaf__)); extern double __yn (int, double) __attribute__ ((__nothrow__ , __leaf__));





 extern double erf (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __erf (double) __attribute__ ((__nothrow__ , __leaf__));
 extern double erfc (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __erfc (double) __attribute__ ((__nothrow__ , __leaf__));
extern double lgamma (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __lgamma (double) __attribute__ ((__nothrow__ , __leaf__));




extern double tgamma (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __tgamma (double) __attribute__ ((__nothrow__ , __leaf__));





extern double gamma (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __gamma (double) __attribute__ ((__nothrow__ , __leaf__));







extern double lgamma_r (double, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__)); extern double __lgamma_r (double, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__));






extern double rint (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __rint (double __x) __attribute__ ((__nothrow__ , __leaf__));


extern double nextafter (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __nextafter (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));

extern double nexttoward (double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __nexttoward (double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
# 290 "/usr/include/bits/mathcalls.h" 3 4
extern double remainder (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __remainder (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));



extern double scalbn (double __x, int __n) __attribute__ ((__nothrow__ , __leaf__)); extern double __scalbn (double __x, int __n) __attribute__ ((__nothrow__ , __leaf__));



extern int ilogb (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern int __ilogb (double __x) __attribute__ ((__nothrow__ , __leaf__));
# 308 "/usr/include/bits/mathcalls.h" 3 4
extern double scalbln (double __x, long int __n) __attribute__ ((__nothrow__ , __leaf__)); extern double __scalbln (double __x, long int __n) __attribute__ ((__nothrow__ , __leaf__));



extern double nearbyint (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __nearbyint (double __x) __attribute__ ((__nothrow__ , __leaf__));



extern double round (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __round (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));



extern double trunc (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __trunc (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));




extern double remquo (double __x, double __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__)); extern double __remquo (double __x, double __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__));






extern long int lrint (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lrint (double __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llrint (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llrint (double __x) __attribute__ ((__nothrow__ , __leaf__));



extern long int lround (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lround (double __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llround (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llround (double __x) __attribute__ ((__nothrow__ , __leaf__));



extern double fdim (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __fdim (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));



extern double fmax (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fmax (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern double fmin (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fmin (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));



extern double fma (double __x, double __y, double __z) __attribute__ ((__nothrow__ , __leaf__)); extern double __fma (double __x, double __y, double __z) __attribute__ ((__nothrow__ , __leaf__));
# 450 "/usr/include/bits/mathcalls.h" 3 4
extern double scalb (double __x, double __n) __attribute__ ((__nothrow__ , __leaf__)); extern double __scalb (double __x, double __n) __attribute__ ((__nothrow__ , __leaf__));
# 314 "/usr/include/math.h" 2 3 4
# 329 "/usr/include/math.h" 3 4
# 1 "/usr/include/bits/mathcalls-helper-functions.h" 1 3 4
# 20 "/usr/include/bits/mathcalls-helper-functions.h" 3 4
extern int __fpclassifyf (float __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));


extern int __signbitf (float __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));



extern int __isinff (float __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));


extern int __finitef (float __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));


extern int __isnanf (float __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));


extern int __iseqsigf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));


extern int __issignalingf (float __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
# 330 "/usr/include/math.h" 2 3 4
# 1 "/usr/include/bits/mathcalls.h" 1 3 4
# 53 "/usr/include/bits/mathcalls.h" 3 4
 extern float acosf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __acosf (float __x) __attribute__ ((__nothrow__ , __leaf__));

 extern float asinf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __asinf (float __x) __attribute__ ((__nothrow__ , __leaf__));

 extern float atanf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __atanf (float __x) __attribute__ ((__nothrow__ , __leaf__));

 extern float atan2f (float __y, float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __atan2f (float __y, float __x) __attribute__ ((__nothrow__ , __leaf__));


 extern float cosf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __cosf (float __x) __attribute__ ((__nothrow__ , __leaf__));

 extern float sinf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __sinf (float __x) __attribute__ ((__nothrow__ , __leaf__));

 extern float tanf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __tanf (float __x) __attribute__ ((__nothrow__ , __leaf__));




 extern float coshf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __coshf (float __x) __attribute__ ((__nothrow__ , __leaf__));

 extern float sinhf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __sinhf (float __x) __attribute__ ((__nothrow__ , __leaf__));

 extern float tanhf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __tanhf (float __x) __attribute__ ((__nothrow__ , __leaf__));
# 85 "/usr/include/bits/mathcalls.h" 3 4
 extern float acoshf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __acoshf (float __x) __attribute__ ((__nothrow__ , __leaf__));

 extern float asinhf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __asinhf (float __x) __attribute__ ((__nothrow__ , __leaf__));

 extern float atanhf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __atanhf (float __x) __attribute__ ((__nothrow__ , __leaf__));





 extern float expf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __expf (float __x) __attribute__ ((__nothrow__ , __leaf__));


extern float frexpf (float __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__)); extern float __frexpf (float __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__));


extern float ldexpf (float __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__)); extern float __ldexpf (float __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__));


 extern float logf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __logf (float __x) __attribute__ ((__nothrow__ , __leaf__));


 extern float log10f (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __log10f (float __x) __attribute__ ((__nothrow__ , __leaf__));


extern float modff (float __x, float *__iptr) __attribute__ ((__nothrow__ , __leaf__)); extern float __modff (float __x, float *__iptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
# 134 "/usr/include/bits/mathcalls.h" 3 4
 extern float expm1f (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __expm1f (float __x) __attribute__ ((__nothrow__ , __leaf__));


 extern float log1pf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __log1pf (float __x) __attribute__ ((__nothrow__ , __leaf__));


extern float logbf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __logbf (float __x) __attribute__ ((__nothrow__ , __leaf__));




 extern float exp2f (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __exp2f (float __x) __attribute__ ((__nothrow__ , __leaf__));


 extern float log2f (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __log2f (float __x) __attribute__ ((__nothrow__ , __leaf__));






 extern float powf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __powf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));


extern float sqrtf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __sqrtf (float __x) __attribute__ ((__nothrow__ , __leaf__));



 extern float hypotf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __hypotf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));




 extern float cbrtf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __cbrtf (float __x) __attribute__ ((__nothrow__ , __leaf__));






extern float ceilf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __ceilf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern float fabsf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fabsf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern float floorf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __floorf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern float fmodf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __fmodf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));
# 192 "/usr/include/bits/mathcalls.h" 3 4
extern int isinff (float __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));




extern int finitef (float __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));


extern float dremf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __dremf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));



extern float significandf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __significandf (float __x) __attribute__ ((__nothrow__ , __leaf__));






extern float copysignf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __copysignf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));




extern float nanf (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)); extern float __nanf (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__));
# 228 "/usr/include/bits/mathcalls.h" 3 4
extern int isnanf (float __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));





extern float j0f (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __j0f (float) __attribute__ ((__nothrow__ , __leaf__));
extern float j1f (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __j1f (float) __attribute__ ((__nothrow__ , __leaf__));
extern float jnf (int, float) __attribute__ ((__nothrow__ , __leaf__)); extern float __jnf (int, float) __attribute__ ((__nothrow__ , __leaf__));
extern float y0f (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __y0f (float) __attribute__ ((__nothrow__ , __leaf__));
extern float y1f (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __y1f (float) __attribute__ ((__nothrow__ , __leaf__));
extern float ynf (int, float) __attribute__ ((__nothrow__ , __leaf__)); extern float __ynf (int, float) __attribute__ ((__nothrow__ , __leaf__));





 extern float erff (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __erff (float) __attribute__ ((__nothrow__ , __leaf__));
 extern float erfcf (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __erfcf (float) __attribute__ ((__nothrow__ , __leaf__));
extern float lgammaf (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __lgammaf (float) __attribute__ ((__nothrow__ , __leaf__));




extern float tgammaf (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __tgammaf (float) __attribute__ ((__nothrow__ , __leaf__));





extern float gammaf (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __gammaf (float) __attribute__ ((__nothrow__ , __leaf__));







extern float lgammaf_r (float, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__)); extern float __lgammaf_r (float, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__));






extern float rintf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __rintf (float __x) __attribute__ ((__nothrow__ , __leaf__));


extern float nextafterf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __nextafterf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));

extern float nexttowardf (float __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __nexttowardf (float __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
# 290 "/usr/include/bits/mathcalls.h" 3 4
extern float remainderf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __remainderf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));



extern float scalbnf (float __x, int __n) __attribute__ ((__nothrow__ , __leaf__)); extern float __scalbnf (float __x, int __n) __attribute__ ((__nothrow__ , __leaf__));



extern int ilogbf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern int __ilogbf (float __x) __attribute__ ((__nothrow__ , __leaf__));
# 308 "/usr/include/bits/mathcalls.h" 3 4
extern float scalblnf (float __x, long int __n) __attribute__ ((__nothrow__ , __leaf__)); extern float __scalblnf (float __x, long int __n) __attribute__ ((__nothrow__ , __leaf__));



extern float nearbyintf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __nearbyintf (float __x) __attribute__ ((__nothrow__ , __leaf__));



extern float roundf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __roundf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));



extern float truncf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __truncf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));




extern float remquof (float __x, float __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__)); extern float __remquof (float __x, float __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__));






extern long int lrintf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lrintf (float __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llrintf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llrintf (float __x) __attribute__ ((__nothrow__ , __leaf__));



extern long int lroundf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lroundf (float __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llroundf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llroundf (float __x) __attribute__ ((__nothrow__ , __leaf__));



extern float fdimf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __fdimf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));



extern float fmaxf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fmaxf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern float fminf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fminf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));



extern float fmaf (float __x, float __y, float __z) __attribute__ ((__nothrow__ , __leaf__)); extern float __fmaf (float __x, float __y, float __z) __attribute__ ((__nothrow__ , __leaf__));
# 450 "/usr/include/bits/mathcalls.h" 3 4
extern float scalbf (float __x, float __n) __attribute__ ((__nothrow__ , __leaf__)); extern float __scalbf (float __x, float __n) __attribute__ ((__nothrow__ , __leaf__));
# 331 "/usr/include/math.h" 2 3 4
# 398 "/usr/include/math.h" 3 4
# 1 "/usr/include/bits/mathcalls-helper-functions.h" 1 3 4
# 20 "/usr/include/bits/mathcalls-helper-functions.h" 3 4
extern int __fpclassifyl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));


extern int __signbitl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));



extern int __isinfl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));


extern int __finitel (long double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));


extern int __isnanl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));


extern int __iseqsigl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));


extern int __issignalingl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
# 399 "/usr/include/math.h" 2 3 4
# 1 "/usr/include/bits/mathcalls.h" 1 3 4
# 53 "/usr/include/bits/mathcalls.h" 3 4
 extern long double acosl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __acosl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern long double asinl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __asinl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern long double atanl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __atanl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern long double atan2l (long double __y, long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __atan2l (long double __y, long double __x) __attribute__ ((__nothrow__ , __leaf__));


 extern long double cosl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __cosl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern long double sinl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __sinl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern long double tanl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __tanl (long double __x) __attribute__ ((__nothrow__ , __leaf__));




 extern long double coshl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __coshl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern long double sinhl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __sinhl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern long double tanhl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __tanhl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
# 85 "/usr/include/bits/mathcalls.h" 3 4
 extern long double acoshl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __acoshl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern long double asinhl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __asinhl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern long double atanhl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __atanhl (long double __x) __attribute__ ((__nothrow__ , __leaf__));





 extern long double expl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __expl (long double __x) __attribute__ ((__nothrow__ , __leaf__));


extern long double frexpl (long double __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__)); extern long double __frexpl (long double __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__));


extern long double ldexpl (long double __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__)); extern long double __ldexpl (long double __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__));


 extern long double logl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __logl (long double __x) __attribute__ ((__nothrow__ , __leaf__));


 extern long double log10l (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __log10l (long double __x) __attribute__ ((__nothrow__ , __leaf__));


extern long double modfl (long double __x, long double *__iptr) __attribute__ ((__nothrow__ , __leaf__)); extern long double __modfl (long double __x, long double *__iptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
# 134 "/usr/include/bits/mathcalls.h" 3 4
 extern long double expm1l (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __expm1l (long double __x) __attribute__ ((__nothrow__ , __leaf__));


 extern long double log1pl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __log1pl (long double __x) __attribute__ ((__nothrow__ , __leaf__));


extern long double logbl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __logbl (long double __x) __attribute__ ((__nothrow__ , __leaf__));




 extern long double exp2l (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __exp2l (long double __x) __attribute__ ((__nothrow__ , __leaf__));


 extern long double log2l (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __log2l (long double __x) __attribute__ ((__nothrow__ , __leaf__));






 extern long double powl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __powl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));


extern long double sqrtl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __sqrtl (long double __x) __attribute__ ((__nothrow__ , __leaf__));



 extern long double hypotl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __hypotl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));




 extern long double cbrtl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __cbrtl (long double __x) __attribute__ ((__nothrow__ , __leaf__));






extern long double ceill (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __ceill (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern long double fabsl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fabsl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern long double floorl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __floorl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern long double fmodl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __fmodl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
# 192 "/usr/include/bits/mathcalls.h" 3 4
extern int isinfl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));




extern int finitel (long double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));


extern long double dreml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __dreml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));



extern long double significandl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __significandl (long double __x) __attribute__ ((__nothrow__ , __leaf__));






extern long double copysignl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __copysignl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));




extern long double nanl (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)); extern long double __nanl (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__));
# 228 "/usr/include/bits/mathcalls.h" 3 4
extern int isnanl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));





extern long double j0l (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __j0l (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double j1l (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __j1l (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double jnl (int, long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __jnl (int, long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double y0l (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __y0l (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double y1l (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __y1l (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double ynl (int, long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __ynl (int, long double) __attribute__ ((__nothrow__ , __leaf__));





 extern long double erfl (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __erfl (long double) __attribute__ ((__nothrow__ , __leaf__));
 extern long double erfcl (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __erfcl (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double lgammal (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __lgammal (long double) __attribute__ ((__nothrow__ , __leaf__));




extern long double tgammal (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __tgammal (long double) __attribute__ ((__nothrow__ , __leaf__));





extern long double gammal (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __gammal (long double) __attribute__ ((__nothrow__ , __leaf__));







extern long double lgammal_r (long double, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__)); extern long double __lgammal_r (long double, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__));






extern long double rintl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __rintl (long double __x) __attribute__ ((__nothrow__ , __leaf__));


extern long double nextafterl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __nextafterl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));

extern long double nexttowardl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __nexttowardl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
# 290 "/usr/include/bits/mathcalls.h" 3 4
extern long double remainderl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __remainderl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));



extern long double scalbnl (long double __x, int __n) __attribute__ ((__nothrow__ , __leaf__)); extern long double __scalbnl (long double __x, int __n) __attribute__ ((__nothrow__ , __leaf__));



extern int ilogbl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern int __ilogbl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
# 308 "/usr/include/bits/mathcalls.h" 3 4
extern long double scalblnl (long double __x, long int __n) __attribute__ ((__nothrow__ , __leaf__)); extern long double __scalblnl (long double __x, long int __n) __attribute__ ((__nothrow__ , __leaf__));



extern long double nearbyintl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __nearbyintl (long double __x) __attribute__ ((__nothrow__ , __leaf__));



extern long double roundl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __roundl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));



extern long double truncl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __truncl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));




extern long double remquol (long double __x, long double __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__)); extern long double __remquol (long double __x, long double __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__));






extern long int lrintl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lrintl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llrintl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llrintl (long double __x) __attribute__ ((__nothrow__ , __leaf__));



extern long int lroundl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lroundl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llroundl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llroundl (long double __x) __attribute__ ((__nothrow__ , __leaf__));



extern long double fdiml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __fdiml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));



extern long double fmaxl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fmaxl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern long double fminl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fminl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));



extern long double fmal (long double __x, long double __y, long double __z) __attribute__ ((__nothrow__ , __leaf__)); extern long double __fmal (long double __x, long double __y, long double __z) __attribute__ ((__nothrow__ , __leaf__));
# 450 "/usr/include/bits/mathcalls.h" 3 4
extern long double scalbl (long double __x, long double __n) __attribute__ ((__nothrow__ , __leaf__)); extern long double __scalbl (long double __x, long double __n) __attribute__ ((__nothrow__ , __leaf__));
# 400 "/usr/include/math.h" 2 3 4
# 481 "/usr/include/math.h" 3 4
# 1 "/usr/include/bits/mathcalls-helper-functions.h" 1 3 4
# 20 "/usr/include/bits/mathcalls-helper-functions.h" 3 4
extern int __fpclassifyf128 (_Float128 __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));


extern int __signbitf128 (_Float128 __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));



extern int __isinff128 (_Float128 __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));


extern int __finitef128 (_Float128 __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));


extern int __isnanf128 (_Float128 __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));


extern int __iseqsigf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));


extern int __issignalingf128 (_Float128 __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
# 482 "/usr/include/math.h" 2 3 4
# 854 "/usr/include/math.h" 3 4
extern int signgam;
# 934 "/usr/include/math.h" 3 4
enum
  {
    FP_NAN =

      0,
    FP_INFINITE =

      1,
    FP_ZERO =

      2,
    FP_SUBNORMAL =

      3,
    FP_NORMAL =

      4
  };
# 1472 "/usr/include/math.h" 3 4

# 30 "./cye.h" 2
# 1 "/usr/lib/gcc/x86_64-pc-linux-gnu/14.2.1/include/stddef.h" 1 3 4
# 145 "/usr/lib/gcc/x86_64-pc-linux-gnu/14.2.1/include/stddef.h" 3 4
typedef long int ptrdiff_t;
# 425 "/usr/lib/gcc/x86_64-pc-linux-gnu/14.2.1/include/stddef.h" 3 4
typedef struct {
  long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
  long double __max_align_ld __attribute__((__aligned__(__alignof__(long double))));
# 436 "/usr/lib/gcc/x86_64-pc-linux-gnu/14.2.1/include/stddef.h" 3 4
} max_align_t;
# 31 "./cye.h" 2
# 1 "/usr/lib/gcc/x86_64-pc-linux-gnu/14.2.1/include/stdint.h" 1 3 4
# 9 "/usr/lib/gcc/x86_64-pc-linux-gnu/14.2.1/include/stdint.h" 3 4
# 1 "/usr/include/stdint.h" 1 3 4
# 26 "/usr/include/stdint.h" 3 4
# 1 "/usr/include/bits/libc-header-start.h" 1 3 4
# 27 "/usr/include/stdint.h" 2 3 4

# 1 "/usr/include/bits/wchar.h" 1 3 4
# 29 "/usr/include/stdint.h" 2 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 30 "/usr/include/stdint.h" 2 3 4







# 1 "/usr/include/bits/stdint-uintn.h" 1 3 4
# 24 "/usr/include/bits/stdint-uintn.h" 3 4
typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;
typedef __uint64_t uint64_t;
# 38 "/usr/include/stdint.h" 2 3 4



# 1 "/usr/include/bits/stdint-least.h" 1 3 4
# 25 "/usr/include/bits/stdint-least.h" 3 4
typedef __int_least8_t int_least8_t;
typedef __int_least16_t int_least16_t;
typedef __int_least32_t int_least32_t;
typedef __int_least64_t int_least64_t;


typedef __uint_least8_t uint_least8_t;
typedef __uint_least16_t uint_least16_t;
typedef __uint_least32_t uint_least32_t;
typedef __uint_least64_t uint_least64_t;
# 42 "/usr/include/stdint.h" 2 3 4





typedef signed char int_fast8_t;

typedef long int int_fast16_t;
typedef long int int_fast32_t;
typedef long int int_fast64_t;
# 60 "/usr/include/stdint.h" 3 4
typedef unsigned char uint_fast8_t;

typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long int uint_fast64_t;
# 76 "/usr/include/stdint.h" 3 4
typedef long int intptr_t;


typedef unsigned long int uintptr_t;
# 90 "/usr/include/stdint.h" 3 4
typedef __intmax_t intmax_t;
typedef __uintmax_t uintmax_t;
# 10 "/usr/lib/gcc/x86_64-pc-linux-gnu/14.2.1/include/stdint.h" 2 3 4
# 32 "./cye.h" 2
# 1 "/usr/include/time.h" 1 3 4
# 29 "/usr/include/time.h" 3 4
# 1 "/usr/lib/gcc/x86_64-pc-linux-gnu/14.2.1/include/stddef.h" 1 3 4
# 30 "/usr/include/time.h" 2 3 4



# 1 "/usr/include/bits/time.h" 1 3 4
# 34 "/usr/include/time.h" 2 3 4





# 1 "/usr/include/bits/types/struct_tm.h" 1 3 4






struct tm
{
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;


  long int tm_gmtoff;
  const char *tm_zone;




};
# 40 "/usr/include/time.h" 2 3 4
# 48 "/usr/include/time.h" 3 4
# 1 "/usr/include/bits/types/struct_itimerspec.h" 1 3 4







struct itimerspec
  {
    struct timespec it_interval;
    struct timespec it_value;
  };
# 49 "/usr/include/time.h" 2 3 4
struct sigevent;
# 68 "/usr/include/time.h" 3 4




extern clock_t clock (void) __attribute__ ((__nothrow__ , __leaf__));



extern time_t time (time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));


extern double difftime (time_t __time1, time_t __time0);


extern time_t mktime (struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));
# 99 "/usr/include/time.h" 3 4
extern size_t strftime (char *__restrict __s, size_t __maxsize,
   const char *__restrict __format,
   const struct tm *__restrict __tp)
   __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3, 4)));
# 116 "/usr/include/time.h" 3 4
extern size_t strftime_l (char *__restrict __s, size_t __maxsize,
     const char *__restrict __format,
     const struct tm *__restrict __tp,
     locale_t __loc) __attribute__ ((__nothrow__ , __leaf__));
# 132 "/usr/include/time.h" 3 4
extern struct tm *gmtime (const time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));



extern struct tm *localtime (const time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));
# 154 "/usr/include/time.h" 3 4
extern struct tm *gmtime_r (const time_t *__restrict __timer,
       struct tm *__restrict __tp) __attribute__ ((__nothrow__ , __leaf__));



extern struct tm *localtime_r (const time_t *__restrict __timer,
          struct tm *__restrict __tp) __attribute__ ((__nothrow__ , __leaf__));
# 179 "/usr/include/time.h" 3 4
extern char *asctime (const struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));



extern char *ctime (const time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));
# 197 "/usr/include/time.h" 3 4
extern char *asctime_r (const struct tm *__restrict __tp,
   char *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__));



extern char *ctime_r (const time_t *__restrict __timer,
        char *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__));
# 217 "/usr/include/time.h" 3 4
extern char *__tzname[2];
extern int __daylight;
extern long int __timezone;




extern char *tzname[2];



extern void tzset (void) __attribute__ ((__nothrow__ , __leaf__));



extern int daylight;
extern long int timezone;
# 246 "/usr/include/time.h" 3 4
extern time_t timegm (struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));
# 263 "/usr/include/time.h" 3 4
extern time_t timelocal (struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));







extern int dysize (int __year) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
# 281 "/usr/include/time.h" 3 4
extern int nanosleep (const struct timespec *__requested_time,
        struct timespec *__remaining);


extern int clock_getres (clockid_t __clock_id, struct timespec *__res) __attribute__ ((__nothrow__ , __leaf__));


extern int clock_gettime (clockid_t __clock_id, struct timespec *__tp)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));


extern int clock_settime (clockid_t __clock_id, const struct timespec *__tp)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
# 323 "/usr/include/time.h" 3 4
extern int clock_nanosleep (clockid_t __clock_id, int __flags,
       const struct timespec *__req,
       struct timespec *__rem);
# 338 "/usr/include/time.h" 3 4
extern int clock_getcpuclockid (pid_t __pid, clockid_t *__clock_id) __attribute__ ((__nothrow__ , __leaf__));




extern int timer_create (clockid_t __clock_id,
    struct sigevent *__restrict __evp,
    timer_t *__restrict __timerid) __attribute__ ((__nothrow__ , __leaf__));


extern int timer_delete (timer_t __timerid) __attribute__ ((__nothrow__ , __leaf__));



extern int timer_settime (timer_t __timerid, int __flags,
     const struct itimerspec *__restrict __value,
     struct itimerspec *__restrict __ovalue) __attribute__ ((__nothrow__ , __leaf__));


extern int timer_gettime (timer_t __timerid, struct itimerspec *__value)
     __attribute__ ((__nothrow__ , __leaf__));
# 376 "/usr/include/time.h" 3 4
extern int timer_getoverrun (timer_t __timerid) __attribute__ ((__nothrow__ , __leaf__));






extern int timespec_get (struct timespec *__ts, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 452 "/usr/include/time.h" 3 4

# 33 "./cye.h" 2
# 1 "/usr/include/stdio.h" 1 3 4
# 28 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/bits/libc-header-start.h" 1 3 4
# 29 "/usr/include/stdio.h" 2 3 4





# 1 "/usr/lib/gcc/x86_64-pc-linux-gnu/14.2.1/include/stddef.h" 1 3 4
# 35 "/usr/include/stdio.h" 2 3 4





# 1 "/usr/include/bits/types/__fpos_t.h" 1 3 4




# 1 "/usr/include/bits/types/__mbstate_t.h" 1 3 4
# 13 "/usr/include/bits/types/__mbstate_t.h" 3 4
typedef struct
{
  int __count;
  union
  {
    unsigned int __wch;
    char __wchb[4];
  } __value;
} __mbstate_t;
# 6 "/usr/include/bits/types/__fpos_t.h" 2 3 4




typedef struct _G_fpos_t
{
  __off_t __pos;
  __mbstate_t __state;
} __fpos_t;
# 41 "/usr/include/stdio.h" 2 3 4
# 1 "/usr/include/bits/types/__fpos64_t.h" 1 3 4
# 10 "/usr/include/bits/types/__fpos64_t.h" 3 4
typedef struct _G_fpos64_t
{
  __off64_t __pos;
  __mbstate_t __state;
} __fpos64_t;
# 42 "/usr/include/stdio.h" 2 3 4
# 1 "/usr/include/bits/types/__FILE.h" 1 3 4



struct _IO_FILE;
typedef struct _IO_FILE __FILE;
# 43 "/usr/include/stdio.h" 2 3 4
# 1 "/usr/include/bits/types/FILE.h" 1 3 4



struct _IO_FILE;


typedef struct _IO_FILE FILE;
# 44 "/usr/include/stdio.h" 2 3 4
# 1 "/usr/include/bits/types/struct_FILE.h" 1 3 4
# 35 "/usr/include/bits/types/struct_FILE.h" 3 4
struct _IO_FILE;
struct _IO_marker;
struct _IO_codecvt;
struct _IO_wide_data;




typedef void _IO_lock_t;





struct _IO_FILE
{
  int _flags;


  char *_IO_read_ptr;
  char *_IO_read_end;
  char *_IO_read_base;
  char *_IO_write_base;
  char *_IO_write_ptr;
  char *_IO_write_end;
  char *_IO_buf_base;
  char *_IO_buf_end;


  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;

  struct _IO_marker *_markers;

  struct _IO_FILE *_chain;

  int _fileno;
  int _flags2;
  __off_t _old_offset;


  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];

  _IO_lock_t *_lock;







  __off64_t _offset;

  struct _IO_codecvt *_codecvt;
  struct _IO_wide_data *_wide_data;
  struct _IO_FILE *_freeres_list;
  void *_freeres_buf;
  struct _IO_FILE **_prevchain;
  int _mode;

  char _unused2[15 * sizeof (int) - 5 * sizeof (void *)];
};
# 45 "/usr/include/stdio.h" 2 3 4


# 1 "/usr/include/bits/types/cookie_io_functions_t.h" 1 3 4
# 27 "/usr/include/bits/types/cookie_io_functions_t.h" 3 4
typedef __ssize_t cookie_read_function_t (void *__cookie, char *__buf,
                                          size_t __nbytes);







typedef __ssize_t cookie_write_function_t (void *__cookie, const char *__buf,
                                           size_t __nbytes);







typedef int cookie_seek_function_t (void *__cookie, __off64_t *__pos, int __w);


typedef int cookie_close_function_t (void *__cookie);






typedef struct _IO_cookie_io_functions_t
{
  cookie_read_function_t *read;
  cookie_write_function_t *write;
  cookie_seek_function_t *seek;
  cookie_close_function_t *close;
} cookie_io_functions_t;
# 48 "/usr/include/stdio.h" 2 3 4
# 85 "/usr/include/stdio.h" 3 4
typedef __fpos_t fpos_t;
# 129 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/bits/stdio_lim.h" 1 3 4
# 130 "/usr/include/stdio.h" 2 3 4
# 149 "/usr/include/stdio.h" 3 4
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;






extern int remove (const char *__filename) __attribute__ ((__nothrow__ , __leaf__));

extern int rename (const char *__old, const char *__new) __attribute__ ((__nothrow__ , __leaf__));



extern int renameat (int __oldfd, const char *__old, int __newfd,
       const char *__new) __attribute__ ((__nothrow__ , __leaf__));
# 184 "/usr/include/stdio.h" 3 4
extern int fclose (FILE *__stream) __attribute__ ((__nonnull__ (1)));
# 194 "/usr/include/stdio.h" 3 4
extern FILE *tmpfile (void)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
# 211 "/usr/include/stdio.h" 3 4
extern char *tmpnam (char[20]) __attribute__ ((__nothrow__ , __leaf__)) ;




extern char *tmpnam_r (char __s[20]) __attribute__ ((__nothrow__ , __leaf__)) ;
# 228 "/usr/include/stdio.h" 3 4
extern char *tempnam (const char *__dir, const char *__pfx)
   __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (__builtin_free, 1)));






extern int fflush (FILE *__stream);
# 245 "/usr/include/stdio.h" 3 4
extern int fflush_unlocked (FILE *__stream);
# 264 "/usr/include/stdio.h" 3 4
extern FILE *fopen (const char *__restrict __filename,
      const char *__restrict __modes)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;




extern FILE *freopen (const char *__restrict __filename,
        const char *__restrict __modes,
        FILE *__restrict __stream) __attribute__ ((__nonnull__ (3)));
# 299 "/usr/include/stdio.h" 3 4
extern FILE *fdopen (int __fd, const char *__modes) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;





extern FILE *fopencookie (void *__restrict __magic_cookie,
     const char *__restrict __modes,
     cookie_io_functions_t __io_funcs) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;




extern FILE *fmemopen (void *__s, size_t __len, const char *__modes)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;




extern FILE *open_memstream (char **__bufloc, size_t *__sizeloc) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
# 334 "/usr/include/stdio.h" 3 4
extern void setbuf (FILE *__restrict __stream, char *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__nonnull__ (1)));



extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
      int __modes, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));




extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf,
         size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern void setlinebuf (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));







extern int fprintf (FILE *__restrict __stream,
      const char *__restrict __format, ...) __attribute__ ((__nonnull__ (1)));




extern int printf (const char *__restrict __format, ...);

extern int sprintf (char *__restrict __s,
      const char *__restrict __format, ...) __attribute__ ((__nothrow__));





extern int vfprintf (FILE *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg) __attribute__ ((__nonnull__ (1)));




extern int vprintf (const char *__restrict __format, __gnuc_va_list __arg);

extern int vsprintf (char *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg) __attribute__ ((__nothrow__));



extern int snprintf (char *__restrict __s, size_t __maxlen,
       const char *__restrict __format, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 4)));

extern int vsnprintf (char *__restrict __s, size_t __maxlen,
        const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 0)));





extern int vasprintf (char **__restrict __ptr, const char *__restrict __f,
        __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 2, 0))) ;
extern int __asprintf (char **__restrict __ptr,
         const char *__restrict __fmt, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 2, 3))) ;
extern int asprintf (char **__restrict __ptr,
       const char *__restrict __fmt, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 2, 3))) ;




extern int vdprintf (int __fd, const char *__restrict __fmt,
       __gnuc_va_list __arg)
     __attribute__ ((__format__ (__printf__, 2, 0)));
extern int dprintf (int __fd, const char *__restrict __fmt, ...)
     __attribute__ ((__format__ (__printf__, 2, 3)));







extern int fscanf (FILE *__restrict __stream,
     const char *__restrict __format, ...) __attribute__ ((__nonnull__ (1)));




extern int scanf (const char *__restrict __format, ...) ;

extern int sscanf (const char *__restrict __s,
     const char *__restrict __format, ...) __attribute__ ((__nothrow__ , __leaf__));
# 463 "/usr/include/stdio.h" 3 4
extern int fscanf (FILE *__restrict __stream, const char *__restrict __format, ...) __asm__ ("" "__isoc99_fscanf")

                                __attribute__ ((__nonnull__ (1)));
extern int scanf (const char *__restrict __format, ...) __asm__ ("" "__isoc99_scanf")
                              ;
extern int sscanf (const char *__restrict __s, const char *__restrict __format, ...) __asm__ ("" "__isoc99_sscanf") __attribute__ ((__nothrow__ , __leaf__))

                      ;
# 490 "/usr/include/stdio.h" 3 4
extern int vfscanf (FILE *__restrict __s, const char *__restrict __format,
      __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 2, 0))) __attribute__ ((__nonnull__ (1)));





extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 1, 0))) ;


extern int vsscanf (const char *__restrict __s,
      const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__format__ (__scanf__, 2, 0)));
# 540 "/usr/include/stdio.h" 3 4
extern int vfscanf (FILE *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vfscanf")



     __attribute__ ((__format__ (__scanf__, 2, 0))) __attribute__ ((__nonnull__ (1)));
extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vscanf")

     __attribute__ ((__format__ (__scanf__, 1, 0))) ;
extern int vsscanf (const char *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vsscanf") __attribute__ ((__nothrow__ , __leaf__))



     __attribute__ ((__format__ (__scanf__, 2, 0)));
# 575 "/usr/include/stdio.h" 3 4
extern int fgetc (FILE *__stream) __attribute__ ((__nonnull__ (1)));
extern int getc (FILE *__stream) __attribute__ ((__nonnull__ (1)));





extern int getchar (void);






extern int getc_unlocked (FILE *__stream) __attribute__ ((__nonnull__ (1)));
extern int getchar_unlocked (void);
# 600 "/usr/include/stdio.h" 3 4
extern int fgetc_unlocked (FILE *__stream) __attribute__ ((__nonnull__ (1)));
# 611 "/usr/include/stdio.h" 3 4
extern int fputc (int __c, FILE *__stream) __attribute__ ((__nonnull__ (2)));
extern int putc (int __c, FILE *__stream) __attribute__ ((__nonnull__ (2)));





extern int putchar (int __c);
# 627 "/usr/include/stdio.h" 3 4
extern int fputc_unlocked (int __c, FILE *__stream) __attribute__ ((__nonnull__ (2)));







extern int putc_unlocked (int __c, FILE *__stream) __attribute__ ((__nonnull__ (2)));
extern int putchar_unlocked (int __c);






extern int getw (FILE *__stream) __attribute__ ((__nonnull__ (1)));


extern int putw (int __w, FILE *__stream) __attribute__ ((__nonnull__ (2)));







extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
     __attribute__ ((__access__ (__write_only__, 1, 2))) __attribute__ ((__nonnull__ (3)));
# 689 "/usr/include/stdio.h" 3 4
extern __ssize_t __getdelim (char **__restrict __lineptr,
                             size_t *__restrict __n, int __delimiter,
                             FILE *__restrict __stream) __attribute__ ((__nonnull__ (4)));
extern __ssize_t getdelim (char **__restrict __lineptr,
                           size_t *__restrict __n, int __delimiter,
                           FILE *__restrict __stream) __attribute__ ((__nonnull__ (4)));


extern __ssize_t getline (char **__restrict __lineptr,
                          size_t *__restrict __n,
                          FILE *__restrict __stream) __attribute__ ((__nonnull__ (3)));







extern int fputs (const char *__restrict __s, FILE *__restrict __stream)
  __attribute__ ((__nonnull__ (2)));





extern int puts (const char *__s);






extern int ungetc (int __c, FILE *__stream) __attribute__ ((__nonnull__ (2)));






extern size_t fread (void *__restrict __ptr, size_t __size,
       size_t __n, FILE *__restrict __stream)
  __attribute__ ((__nonnull__ (4)));




extern size_t fwrite (const void *__restrict __ptr, size_t __size,
        size_t __n, FILE *__restrict __s) __attribute__ ((__nonnull__ (4)));
# 756 "/usr/include/stdio.h" 3 4
extern size_t fread_unlocked (void *__restrict __ptr, size_t __size,
         size_t __n, FILE *__restrict __stream)
  __attribute__ ((__nonnull__ (4)));
extern size_t fwrite_unlocked (const void *__restrict __ptr, size_t __size,
          size_t __n, FILE *__restrict __stream)
  __attribute__ ((__nonnull__ (4)));







extern int fseek (FILE *__stream, long int __off, int __whence)
  __attribute__ ((__nonnull__ (1)));




extern long int ftell (FILE *__stream) __attribute__ ((__nonnull__ (1)));




extern void rewind (FILE *__stream) __attribute__ ((__nonnull__ (1)));
# 793 "/usr/include/stdio.h" 3 4
extern int fseeko (FILE *__stream, __off_t __off, int __whence)
  __attribute__ ((__nonnull__ (1)));




extern __off_t ftello (FILE *__stream) __attribute__ ((__nonnull__ (1)));
# 819 "/usr/include/stdio.h" 3 4
extern int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos)
  __attribute__ ((__nonnull__ (1)));




extern int fsetpos (FILE *__stream, const fpos_t *__pos) __attribute__ ((__nonnull__ (1)));
# 850 "/usr/include/stdio.h" 3 4
extern void clearerr (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

extern int feof (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

extern int ferror (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));



extern void clearerr_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int feof_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int ferror_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));







extern void perror (const char *__s) __attribute__ ((__cold__));




extern int fileno (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));




extern int fileno_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 887 "/usr/include/stdio.h" 3 4
extern int pclose (FILE *__stream) __attribute__ ((__nonnull__ (1)));





extern FILE *popen (const char *__command, const char *__modes)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (pclose, 1))) ;






extern char *ctermid (char *__s) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__access__ (__write_only__, 1)));
# 931 "/usr/include/stdio.h" 3 4
extern void flockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));



extern int ftrylockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern void funlockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 949 "/usr/include/stdio.h" 3 4
extern int __uflow (FILE *);
extern int __overflow (FILE *, int);
# 973 "/usr/include/stdio.h" 3 4

# 34 "./cye.h" 2
# 55 "./cye.h"
# 1 "/usr/include/sys/wait.h" 1 3 4
# 27 "/usr/include/sys/wait.h" 3 4

# 36 "/usr/include/sys/wait.h" 3 4
# 1 "/usr/include/signal.h" 1 3 4
# 27 "/usr/include/signal.h" 3 4



# 1 "/usr/include/bits/signum-generic.h" 1 3 4
# 76 "/usr/include/bits/signum-generic.h" 3 4
# 1 "/usr/include/bits/signum-arch.h" 1 3 4
# 77 "/usr/include/bits/signum-generic.h" 2 3 4
# 31 "/usr/include/signal.h" 2 3 4

# 1 "/usr/include/bits/types/sig_atomic_t.h" 1 3 4







typedef __sig_atomic_t sig_atomic_t;
# 33 "/usr/include/signal.h" 2 3 4
# 57 "/usr/include/signal.h" 3 4
# 1 "/usr/include/bits/types/siginfo_t.h" 1 3 4



# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 5 "/usr/include/bits/types/siginfo_t.h" 2 3 4

# 1 "/usr/include/bits/types/__sigval_t.h" 1 3 4
# 24 "/usr/include/bits/types/__sigval_t.h" 3 4
union sigval
{
  int sival_int;
  void *sival_ptr;
};

typedef union sigval __sigval_t;
# 7 "/usr/include/bits/types/siginfo_t.h" 2 3 4
# 16 "/usr/include/bits/types/siginfo_t.h" 3 4
# 1 "/usr/include/bits/siginfo-arch.h" 1 3 4
# 17 "/usr/include/bits/types/siginfo_t.h" 2 3 4
# 36 "/usr/include/bits/types/siginfo_t.h" 3 4
typedef struct
  {
    int si_signo;

    int si_errno;

    int si_code;





    int __pad0;


    union
      {
 int _pad[((128 / sizeof (int)) - 4)];


 struct
   {
     __pid_t si_pid;
     __uid_t si_uid;
   } _kill;


 struct
   {
     int si_tid;
     int si_overrun;
     __sigval_t si_sigval;
   } _timer;


 struct
   {
     __pid_t si_pid;
     __uid_t si_uid;
     __sigval_t si_sigval;
   } _rt;


 struct
   {
     __pid_t si_pid;
     __uid_t si_uid;
     int si_status;
     __clock_t si_utime;
     __clock_t si_stime;
   } _sigchld;


 struct
   {
     void *si_addr;
    
     short int si_addr_lsb;
     union
       {

  struct
    {
      void *_lower;
      void *_upper;
    } _addr_bnd;

  __uint32_t _pkey;
       } _bounds;
   } _sigfault;


 struct
   {
     long int si_band;
     int si_fd;
   } _sigpoll;



 struct
   {
     void *_call_addr;
     int _syscall;
     unsigned int _arch;
   } _sigsys;

      } _sifields;
  } siginfo_t ;
# 58 "/usr/include/signal.h" 2 3 4
# 1 "/usr/include/bits/siginfo-consts.h" 1 3 4
# 35 "/usr/include/bits/siginfo-consts.h" 3 4
enum
{
  SI_ASYNCNL = -60,
  SI_DETHREAD = -7,

  SI_TKILL,
  SI_SIGIO,

  SI_ASYNCIO,
  SI_MESGQ,
  SI_TIMER,





  SI_QUEUE,
  SI_USER,
  SI_KERNEL = 0x80
# 66 "/usr/include/bits/siginfo-consts.h" 3 4
};




enum
{
  ILL_ILLOPC = 1,

  ILL_ILLOPN,

  ILL_ILLADR,

  ILL_ILLTRP,

  ILL_PRVOPC,

  ILL_PRVREG,

  ILL_COPROC,

  ILL_BADSTK,

  ILL_BADIADDR

};


enum
{
  FPE_INTDIV = 1,

  FPE_INTOVF,

  FPE_FLTDIV,

  FPE_FLTOVF,

  FPE_FLTUND,

  FPE_FLTRES,

  FPE_FLTINV,

  FPE_FLTSUB,

  FPE_FLTUNK = 14,

  FPE_CONDTRAP

};


enum
{
  SEGV_MAPERR = 1,

  SEGV_ACCERR,

  SEGV_BNDERR,

  SEGV_PKUERR,

  SEGV_ACCADI,

  SEGV_ADIDERR,

  SEGV_ADIPERR,

  SEGV_MTEAERR,

  SEGV_MTESERR,

  SEGV_CPERR

};


enum
{
  BUS_ADRALN = 1,

  BUS_ADRERR,

  BUS_OBJERR,

  BUS_MCEERR_AR,

  BUS_MCEERR_AO

};
# 178 "/usr/include/bits/siginfo-consts.h" 3 4
enum
{
  CLD_EXITED = 1,

  CLD_KILLED,

  CLD_DUMPED,

  CLD_TRAPPED,

  CLD_STOPPED,

  CLD_CONTINUED

};


enum
{
  POLL_IN = 1,

  POLL_OUT,

  POLL_MSG,

  POLL_ERR,

  POLL_PRI,

  POLL_HUP

};
# 59 "/usr/include/signal.h" 2 3 4



# 1 "/usr/include/bits/types/sigval_t.h" 1 3 4
# 16 "/usr/include/bits/types/sigval_t.h" 3 4
typedef __sigval_t sigval_t;
# 63 "/usr/include/signal.h" 2 3 4



# 1 "/usr/include/bits/types/sigevent_t.h" 1 3 4



# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 5 "/usr/include/bits/types/sigevent_t.h" 2 3 4
# 22 "/usr/include/bits/types/sigevent_t.h" 3 4
typedef struct sigevent
  {
    __sigval_t sigev_value;
    int sigev_signo;
    int sigev_notify;

    union
      {
 int _pad[((64 / sizeof (int)) - 4)];



 __pid_t _tid;

 struct
   {
     void (*_function) (__sigval_t);
     pthread_attr_t *_attribute;
   } _sigev_thread;
      } _sigev_un;
  } sigevent_t;
# 67 "/usr/include/signal.h" 2 3 4
# 1 "/usr/include/bits/sigevent-consts.h" 1 3 4
# 27 "/usr/include/bits/sigevent-consts.h" 3 4
enum
{
  SIGEV_SIGNAL = 0,

  SIGEV_NONE,

  SIGEV_THREAD,


  SIGEV_THREAD_ID = 4


};
# 68 "/usr/include/signal.h" 2 3 4




typedef void (*__sighandler_t) (int);




extern __sighandler_t __sysv_signal (int __sig, __sighandler_t __handler)
     __attribute__ ((__nothrow__ , __leaf__));
# 88 "/usr/include/signal.h" 3 4
extern __sighandler_t signal (int __sig, __sighandler_t __handler)
     __attribute__ ((__nothrow__ , __leaf__));
# 112 "/usr/include/signal.h" 3 4
extern int kill (__pid_t __pid, int __sig) __attribute__ ((__nothrow__ , __leaf__));






extern int killpg (__pid_t __pgrp, int __sig) __attribute__ ((__nothrow__ , __leaf__));



extern int raise (int __sig) __attribute__ ((__nothrow__ , __leaf__));



extern __sighandler_t ssignal (int __sig, __sighandler_t __handler)
     __attribute__ ((__nothrow__ , __leaf__));
extern int gsignal (int __sig) __attribute__ ((__nothrow__ , __leaf__));




extern void psignal (int __sig, const char *__s);


extern void psiginfo (const siginfo_t *__pinfo, const char *__s);
# 173 "/usr/include/signal.h" 3 4
extern int sigblock (int __mask) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__deprecated__));


extern int sigsetmask (int __mask) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__deprecated__));


extern int siggetmask (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__deprecated__));
# 193 "/usr/include/signal.h" 3 4
typedef __sighandler_t sig_t;





extern int sigemptyset (sigset_t *__set) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int sigfillset (sigset_t *__set) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int sigaddset (sigset_t *__set, int __signo) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int sigdelset (sigset_t *__set, int __signo) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int sigismember (const sigset_t *__set, int __signo)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 229 "/usr/include/signal.h" 3 4
# 1 "/usr/include/bits/sigaction.h" 1 3 4
# 27 "/usr/include/bits/sigaction.h" 3 4
struct sigaction
  {


    union
      {

 __sighandler_t sa_handler;

 void (*sa_sigaction) (int, siginfo_t *, void *);
      }
    __sigaction_handler;







    __sigset_t sa_mask;


    int sa_flags;


    void (*sa_restorer) (void);
  };
# 230 "/usr/include/signal.h" 2 3 4


extern int sigprocmask (int __how, const sigset_t *__restrict __set,
   sigset_t *__restrict __oset) __attribute__ ((__nothrow__ , __leaf__));






extern int sigsuspend (const sigset_t *__set) __attribute__ ((__nonnull__ (1)));


extern int sigaction (int __sig, const struct sigaction *__restrict __act,
        struct sigaction *__restrict __oact) __attribute__ ((__nothrow__ , __leaf__));


extern int sigpending (sigset_t *__set) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));







extern int sigwait (const sigset_t *__restrict __set, int *__restrict __sig)
     __attribute__ ((__nonnull__ (1, 2)));







extern int sigwaitinfo (const sigset_t *__restrict __set,
   siginfo_t *__restrict __info) __attribute__ ((__nonnull__ (1)));







extern int sigtimedwait (const sigset_t *__restrict __set,
    siginfo_t *__restrict __info,
    const struct timespec *__restrict __timeout)
     __attribute__ ((__nonnull__ (1)));
# 292 "/usr/include/signal.h" 3 4
extern int sigqueue (__pid_t __pid, int __sig, const union sigval __val)
     __attribute__ ((__nothrow__ , __leaf__));







# 1 "/usr/include/bits/sigcontext.h" 1 3 4
# 31 "/usr/include/bits/sigcontext.h" 3 4
struct _fpx_sw_bytes
{
  __uint32_t magic1;
  __uint32_t extended_size;
  __uint64_t xstate_bv;
  __uint32_t xstate_size;
  __uint32_t __glibc_reserved1[7];
};

struct _fpreg
{
  unsigned short significand[4];
  unsigned short exponent;
};

struct _fpxreg
{
  unsigned short significand[4];
  unsigned short exponent;
  unsigned short __glibc_reserved1[3];
};

struct _xmmreg
{
  __uint32_t element[4];
};
# 123 "/usr/include/bits/sigcontext.h" 3 4
struct _fpstate
{

  __uint16_t cwd;
  __uint16_t swd;
  __uint16_t ftw;
  __uint16_t fop;
  __uint64_t rip;
  __uint64_t rdp;
  __uint32_t mxcsr;
  __uint32_t mxcr_mask;
  struct _fpxreg _st[8];
  struct _xmmreg _xmm[16];
  __uint32_t __glibc_reserved1[24];
};

struct sigcontext
{
  __uint64_t r8;
  __uint64_t r9;
  __uint64_t r10;
  __uint64_t r11;
  __uint64_t r12;
  __uint64_t r13;
  __uint64_t r14;
  __uint64_t r15;
  __uint64_t rdi;
  __uint64_t rsi;
  __uint64_t rbp;
  __uint64_t rbx;
  __uint64_t rdx;
  __uint64_t rax;
  __uint64_t rcx;
  __uint64_t rsp;
  __uint64_t rip;
  __uint64_t eflags;
  unsigned short cs;
  unsigned short gs;
  unsigned short fs;
  unsigned short __pad0;
  __uint64_t err;
  __uint64_t trapno;
  __uint64_t oldmask;
  __uint64_t cr2;
  __extension__ union
    {
      struct _fpstate * fpstate;
      __uint64_t __fpstate_word;
    };
  __uint64_t __reserved1 [8];
};



struct _xsave_hdr
{
  __uint64_t xstate_bv;
  __uint64_t __glibc_reserved1[2];
  __uint64_t __glibc_reserved2[5];
};

struct _ymmh_state
{
  __uint32_t ymmh_space[64];
};

struct _xstate
{
  struct _fpstate fpstate;
  struct _xsave_hdr xstate_hdr;
  struct _ymmh_state ymmh;
};
# 302 "/usr/include/signal.h" 2 3 4


extern int sigreturn (struct sigcontext *__scp) __attribute__ ((__nothrow__ , __leaf__));






# 1 "/usr/lib/gcc/x86_64-pc-linux-gnu/14.2.1/include/stddef.h" 1 3 4
# 312 "/usr/include/signal.h" 2 3 4

# 1 "/usr/include/bits/types/stack_t.h" 1 3 4
# 23 "/usr/include/bits/types/stack_t.h" 3 4
# 1 "/usr/lib/gcc/x86_64-pc-linux-gnu/14.2.1/include/stddef.h" 1 3 4
# 24 "/usr/include/bits/types/stack_t.h" 2 3 4


typedef struct
  {
    void *ss_sp;
    int ss_flags;
    size_t ss_size;
  } stack_t;
# 314 "/usr/include/signal.h" 2 3 4


# 1 "/usr/include/sys/ucontext.h" 1 3 4
# 37 "/usr/include/sys/ucontext.h" 3 4
__extension__ typedef long long int greg_t;
# 46 "/usr/include/sys/ucontext.h" 3 4
typedef greg_t gregset_t[23];
# 101 "/usr/include/sys/ucontext.h" 3 4
struct _libc_fpxreg
{
  unsigned short int significand[4];
  unsigned short int exponent;
  unsigned short int __glibc_reserved1[3];
};

struct _libc_xmmreg
{
  __uint32_t element[4];
};

struct _libc_fpstate
{

  __uint16_t cwd;
  __uint16_t swd;
  __uint16_t ftw;
  __uint16_t fop;
  __uint64_t rip;
  __uint64_t rdp;
  __uint32_t mxcsr;
  __uint32_t mxcr_mask;
  struct _libc_fpxreg _st[8];
  struct _libc_xmmreg _xmm[16];
  __uint32_t __glibc_reserved1[24];
};


typedef struct _libc_fpstate *fpregset_t;


typedef struct
  {
    gregset_t gregs;

    fpregset_t fpregs;
    __extension__ unsigned long long __reserved1 [8];
} mcontext_t;


typedef struct ucontext_t
  {
    unsigned long int uc_flags;
    struct ucontext_t *uc_link;
    stack_t uc_stack;
    mcontext_t uc_mcontext;
    sigset_t uc_sigmask;
    struct _libc_fpstate __fpregs_mem;
    __extension__ unsigned long long int __ssp[4];
  } ucontext_t;
# 317 "/usr/include/signal.h" 2 3 4







extern int siginterrupt (int __sig, int __interrupt) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__deprecated__ ("Use sigaction with SA_RESTART instead")));

# 1 "/usr/include/bits/sigstack.h" 1 3 4
# 328 "/usr/include/signal.h" 2 3 4
# 1 "/usr/include/bits/sigstksz.h" 1 3 4
# 329 "/usr/include/signal.h" 2 3 4
# 1 "/usr/include/bits/ss_flags.h" 1 3 4
# 27 "/usr/include/bits/ss_flags.h" 3 4
enum
{
  SS_ONSTACK = 1,

  SS_DISABLE

};
# 330 "/usr/include/signal.h" 2 3 4



extern int sigaltstack (const stack_t *__restrict __ss,
   stack_t *__restrict __oss) __attribute__ ((__nothrow__ , __leaf__));




# 1 "/usr/include/bits/types/struct_sigstack.h" 1 3 4
# 23 "/usr/include/bits/types/struct_sigstack.h" 3 4
struct sigstack
  {
    void *ss_sp;
    int ss_onstack;
  };
# 340 "/usr/include/signal.h" 2 3 4







extern int sigstack (struct sigstack *__ss, struct sigstack *__oss)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__deprecated__));
# 376 "/usr/include/signal.h" 3 4
# 1 "/usr/include/bits/sigthread.h" 1 3 4
# 31 "/usr/include/bits/sigthread.h" 3 4
extern int pthread_sigmask (int __how,
       const __sigset_t *__restrict __newmask,
       __sigset_t *__restrict __oldmask)__attribute__ ((__nothrow__ , __leaf__));


extern int pthread_kill (pthread_t __threadid, int __signo) __attribute__ ((__nothrow__ , __leaf__));
# 377 "/usr/include/signal.h" 2 3 4






extern int __libc_current_sigrtmin (void) __attribute__ ((__nothrow__ , __leaf__));

extern int __libc_current_sigrtmax (void) __attribute__ ((__nothrow__ , __leaf__));





# 1 "/usr/include/bits/signal_ext.h" 1 3 4
# 392 "/usr/include/signal.h" 2 3 4


# 37 "/usr/include/sys/wait.h" 2 3 4
# 74 "/usr/include/sys/wait.h" 3 4
# 1 "/usr/include/bits/types/idtype_t.h" 1 3 4




typedef enum
{
  P_ALL,
  P_PID,
  P_PGID,
  P_PIDFD,

} idtype_t;
# 75 "/usr/include/sys/wait.h" 2 3 4
# 83 "/usr/include/sys/wait.h" 3 4
extern __pid_t wait (int *__stat_loc);
# 106 "/usr/include/sys/wait.h" 3 4
extern __pid_t waitpid (__pid_t __pid, int *__stat_loc, int __options);
# 127 "/usr/include/sys/wait.h" 3 4
extern int waitid (idtype_t __idtype, __id_t __id, siginfo_t *__infop,
     int __options);






struct rusage;







extern __pid_t wait3 (int *__stat_loc, int __options,
        struct rusage * __usage) __attribute__ ((__nothrow__));
# 159 "/usr/include/sys/wait.h" 3 4
extern __pid_t wait4 (__pid_t __pid, int *__stat_loc, int __options,
        struct rusage *__usage) __attribute__ ((__nothrow__));
# 173 "/usr/include/sys/wait.h" 3 4

# 56 "./cye.h" 2
# 1 "/usr/include/sys/stat.h" 1 3 4
# 99 "/usr/include/sys/stat.h" 3 4


# 1 "/usr/include/bits/stat.h" 1 3 4
# 25 "/usr/include/bits/stat.h" 3 4
# 1 "/usr/include/bits/struct_stat.h" 1 3 4
# 26 "/usr/include/bits/struct_stat.h" 3 4
struct stat
  {



    __dev_t st_dev;




    __ino_t st_ino;







    __nlink_t st_nlink;
    __mode_t st_mode;

    __uid_t st_uid;
    __gid_t st_gid;

    int __pad0;

    __dev_t st_rdev;




    __off_t st_size;



    __blksize_t st_blksize;

    __blkcnt_t st_blocks;
# 74 "/usr/include/bits/struct_stat.h" 3 4
    struct timespec st_atim;
    struct timespec st_mtim;
    struct timespec st_ctim;
# 89 "/usr/include/bits/struct_stat.h" 3 4
    __syscall_slong_t __glibc_reserved[3];
# 99 "/usr/include/bits/struct_stat.h" 3 4
  };
# 26 "/usr/include/bits/stat.h" 2 3 4
# 102 "/usr/include/sys/stat.h" 2 3 4
# 205 "/usr/include/sys/stat.h" 3 4
extern int stat (const char *__restrict __file,
   struct stat *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));



extern int fstat (int __fd, struct stat *__buf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
# 264 "/usr/include/sys/stat.h" 3 4
extern int fstatat (int __fd, const char *__restrict __file,
      struct stat *__restrict __buf, int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
# 313 "/usr/include/sys/stat.h" 3 4
extern int lstat (const char *__restrict __file,
    struct stat *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
# 352 "/usr/include/sys/stat.h" 3 4
extern int chmod (const char *__file, __mode_t __mode)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





extern int lchmod (const char *__file, __mode_t __mode)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));




extern int fchmod (int __fd, __mode_t __mode) __attribute__ ((__nothrow__ , __leaf__));





extern int fchmodat (int __fd, const char *__file, __mode_t __mode,
       int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) ;






extern __mode_t umask (__mode_t __mask) __attribute__ ((__nothrow__ , __leaf__));
# 389 "/usr/include/sys/stat.h" 3 4
extern int mkdir (const char *__path, __mode_t __mode)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





extern int mkdirat (int __fd, const char *__path, __mode_t __mode)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));






extern int mknod (const char *__path, __mode_t __mode, __dev_t __dev)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





extern int mknodat (int __fd, const char *__path, __mode_t __mode,
      __dev_t __dev) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));





extern int mkfifo (const char *__path, __mode_t __mode)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





extern int mkfifoat (int __fd, const char *__path, __mode_t __mode)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));






extern int utimensat (int __fd, const char *__path,
        const struct timespec __times[2],
        int __flags)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
# 452 "/usr/include/sys/stat.h" 3 4
extern int futimens (int __fd, const struct timespec __times[2]) __attribute__ ((__nothrow__ , __leaf__));
# 468 "/usr/include/sys/stat.h" 3 4

# 57 "./cye.h" 2
# 1 "/usr/include/unistd.h" 1 3 4
# 27 "/usr/include/unistd.h" 3 4

# 202 "/usr/include/unistd.h" 3 4
# 1 "/usr/include/bits/posix_opt.h" 1 3 4
# 203 "/usr/include/unistd.h" 2 3 4



# 1 "/usr/include/bits/environments.h" 1 3 4
# 22 "/usr/include/bits/environments.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 23 "/usr/include/bits/environments.h" 2 3 4
# 207 "/usr/include/unistd.h" 2 3 4
# 226 "/usr/include/unistd.h" 3 4
# 1 "/usr/lib/gcc/x86_64-pc-linux-gnu/14.2.1/include/stddef.h" 1 3 4
# 227 "/usr/include/unistd.h" 2 3 4
# 255 "/usr/include/unistd.h" 3 4
typedef __useconds_t useconds_t;
# 274 "/usr/include/unistd.h" 3 4
typedef __socklen_t socklen_t;
# 287 "/usr/include/unistd.h" 3 4
extern int access (const char *__name, int __type) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 309 "/usr/include/unistd.h" 3 4
extern int faccessat (int __fd, const char *__file, int __type, int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) ;
# 339 "/usr/include/unistd.h" 3 4
extern __off_t lseek (int __fd, __off_t __offset, int __whence) __attribute__ ((__nothrow__ , __leaf__));
# 358 "/usr/include/unistd.h" 3 4
extern int close (int __fd);




extern void closefrom (int __lowfd) __attribute__ ((__nothrow__ , __leaf__));







extern ssize_t read (int __fd, void *__buf, size_t __nbytes)
    __attribute__ ((__access__ (__write_only__, 2, 3)));





extern ssize_t write (int __fd, const void *__buf, size_t __n)
    __attribute__ ((__access__ (__read_only__, 2, 3)));
# 389 "/usr/include/unistd.h" 3 4
extern ssize_t pread (int __fd, void *__buf, size_t __nbytes,
        __off_t __offset)
    __attribute__ ((__access__ (__write_only__, 2, 3)));






extern ssize_t pwrite (int __fd, const void *__buf, size_t __n,
         __off_t __offset)
    __attribute__ ((__access__ (__read_only__, 2, 3)));
# 437 "/usr/include/unistd.h" 3 4
extern int pipe (int __pipedes[2]) __attribute__ ((__nothrow__ , __leaf__)) ;
# 452 "/usr/include/unistd.h" 3 4
extern unsigned int alarm (unsigned int __seconds) __attribute__ ((__nothrow__ , __leaf__));
# 464 "/usr/include/unistd.h" 3 4
extern unsigned int sleep (unsigned int __seconds);







extern __useconds_t ualarm (__useconds_t __value, __useconds_t __interval)
     __attribute__ ((__nothrow__ , __leaf__));






extern int usleep (__useconds_t __useconds);
# 489 "/usr/include/unistd.h" 3 4
extern int pause (void);



extern int chown (const char *__file, __uid_t __owner, __gid_t __group)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;



extern int fchown (int __fd, __uid_t __owner, __gid_t __group) __attribute__ ((__nothrow__ , __leaf__)) ;




extern int lchown (const char *__file, __uid_t __owner, __gid_t __group)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;






extern int fchownat (int __fd, const char *__file, __uid_t __owner,
       __gid_t __group, int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) ;



extern int chdir (const char *__path) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;



extern int fchdir (int __fd) __attribute__ ((__nothrow__ , __leaf__)) ;
# 531 "/usr/include/unistd.h" 3 4
extern char *getcwd (char *__buf, size_t __size) __attribute__ ((__nothrow__ , __leaf__)) ;
# 545 "/usr/include/unistd.h" 3 4
extern char *getwd (char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__deprecated__))
    __attribute__ ((__access__ (__write_only__, 1)));




extern int dup (int __fd) __attribute__ ((__nothrow__ , __leaf__)) ;


extern int dup2 (int __fd, int __fd2) __attribute__ ((__nothrow__ , __leaf__));
# 564 "/usr/include/unistd.h" 3 4
extern char **__environ;







extern int execve (const char *__path, char *const __argv[],
     char *const __envp[]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));




extern int fexecve (int __fd, char *const __argv[], char *const __envp[])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));




extern int execv (const char *__path, char *const __argv[])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));



extern int execle (const char *__path, const char *__arg, ...)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));



extern int execl (const char *__path, const char *__arg, ...)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));



extern int execvp (const char *__file, char *const __argv[])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));




extern int execlp (const char *__file, const char *__arg, ...)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
# 619 "/usr/include/unistd.h" 3 4
extern int nice (int __inc) __attribute__ ((__nothrow__ , __leaf__)) ;




extern void _exit (int __status) __attribute__ ((__noreturn__));





# 1 "/usr/include/bits/confname.h" 1 3 4
# 24 "/usr/include/bits/confname.h" 3 4
enum
  {
    _PC_LINK_MAX,

    _PC_MAX_CANON,

    _PC_MAX_INPUT,

    _PC_NAME_MAX,

    _PC_PATH_MAX,

    _PC_PIPE_BUF,

    _PC_CHOWN_RESTRICTED,

    _PC_NO_TRUNC,

    _PC_VDISABLE,

    _PC_SYNC_IO,

    _PC_ASYNC_IO,

    _PC_PRIO_IO,

    _PC_SOCK_MAXBUF,

    _PC_FILESIZEBITS,

    _PC_REC_INCR_XFER_SIZE,

    _PC_REC_MAX_XFER_SIZE,

    _PC_REC_MIN_XFER_SIZE,

    _PC_REC_XFER_ALIGN,

    _PC_ALLOC_SIZE_MIN,

    _PC_SYMLINK_MAX,

    _PC_2_SYMLINKS

  };


enum
  {
    _SC_ARG_MAX,

    _SC_CHILD_MAX,

    _SC_CLK_TCK,

    _SC_NGROUPS_MAX,

    _SC_OPEN_MAX,

    _SC_STREAM_MAX,

    _SC_TZNAME_MAX,

    _SC_JOB_CONTROL,

    _SC_SAVED_IDS,

    _SC_REALTIME_SIGNALS,

    _SC_PRIORITY_SCHEDULING,

    _SC_TIMERS,

    _SC_ASYNCHRONOUS_IO,

    _SC_PRIORITIZED_IO,

    _SC_SYNCHRONIZED_IO,

    _SC_FSYNC,

    _SC_MAPPED_FILES,

    _SC_MEMLOCK,

    _SC_MEMLOCK_RANGE,

    _SC_MEMORY_PROTECTION,

    _SC_MESSAGE_PASSING,

    _SC_SEMAPHORES,

    _SC_SHARED_MEMORY_OBJECTS,

    _SC_AIO_LISTIO_MAX,

    _SC_AIO_MAX,

    _SC_AIO_PRIO_DELTA_MAX,

    _SC_DELAYTIMER_MAX,

    _SC_MQ_OPEN_MAX,

    _SC_MQ_PRIO_MAX,

    _SC_VERSION,

    _SC_PAGESIZE,


    _SC_RTSIG_MAX,

    _SC_SEM_NSEMS_MAX,

    _SC_SEM_VALUE_MAX,

    _SC_SIGQUEUE_MAX,

    _SC_TIMER_MAX,




    _SC_BC_BASE_MAX,

    _SC_BC_DIM_MAX,

    _SC_BC_SCALE_MAX,

    _SC_BC_STRING_MAX,

    _SC_COLL_WEIGHTS_MAX,

    _SC_EQUIV_CLASS_MAX,

    _SC_EXPR_NEST_MAX,

    _SC_LINE_MAX,

    _SC_RE_DUP_MAX,

    _SC_CHARCLASS_NAME_MAX,


    _SC_2_VERSION,

    _SC_2_C_BIND,

    _SC_2_C_DEV,

    _SC_2_FORT_DEV,

    _SC_2_FORT_RUN,

    _SC_2_SW_DEV,

    _SC_2_LOCALEDEF,


    _SC_PII,

    _SC_PII_XTI,

    _SC_PII_SOCKET,

    _SC_PII_INTERNET,

    _SC_PII_OSI,

    _SC_POLL,

    _SC_SELECT,

    _SC_UIO_MAXIOV,

    _SC_IOV_MAX = _SC_UIO_MAXIOV,

    _SC_PII_INTERNET_STREAM,

    _SC_PII_INTERNET_DGRAM,

    _SC_PII_OSI_COTS,

    _SC_PII_OSI_CLTS,

    _SC_PII_OSI_M,

    _SC_T_IOV_MAX,



    _SC_THREADS,

    _SC_THREAD_SAFE_FUNCTIONS,

    _SC_GETGR_R_SIZE_MAX,

    _SC_GETPW_R_SIZE_MAX,

    _SC_LOGIN_NAME_MAX,

    _SC_TTY_NAME_MAX,

    _SC_THREAD_DESTRUCTOR_ITERATIONS,

    _SC_THREAD_KEYS_MAX,

    _SC_THREAD_STACK_MIN,

    _SC_THREAD_THREADS_MAX,

    _SC_THREAD_ATTR_STACKADDR,

    _SC_THREAD_ATTR_STACKSIZE,

    _SC_THREAD_PRIORITY_SCHEDULING,

    _SC_THREAD_PRIO_INHERIT,

    _SC_THREAD_PRIO_PROTECT,

    _SC_THREAD_PROCESS_SHARED,


    _SC_NPROCESSORS_CONF,

    _SC_NPROCESSORS_ONLN,

    _SC_PHYS_PAGES,

    _SC_AVPHYS_PAGES,

    _SC_ATEXIT_MAX,

    _SC_PASS_MAX,


    _SC_XOPEN_VERSION,

    _SC_XOPEN_XCU_VERSION,

    _SC_XOPEN_UNIX,

    _SC_XOPEN_CRYPT,

    _SC_XOPEN_ENH_I18N,

    _SC_XOPEN_SHM,


    _SC_2_CHAR_TERM,

    _SC_2_C_VERSION,

    _SC_2_UPE,


    _SC_XOPEN_XPG2,

    _SC_XOPEN_XPG3,

    _SC_XOPEN_XPG4,


    _SC_CHAR_BIT,

    _SC_CHAR_MAX,

    _SC_CHAR_MIN,

    _SC_INT_MAX,

    _SC_INT_MIN,

    _SC_LONG_BIT,

    _SC_WORD_BIT,

    _SC_MB_LEN_MAX,

    _SC_NZERO,

    _SC_SSIZE_MAX,

    _SC_SCHAR_MAX,

    _SC_SCHAR_MIN,

    _SC_SHRT_MAX,

    _SC_SHRT_MIN,

    _SC_UCHAR_MAX,

    _SC_UINT_MAX,

    _SC_ULONG_MAX,

    _SC_USHRT_MAX,


    _SC_NL_ARGMAX,

    _SC_NL_LANGMAX,

    _SC_NL_MSGMAX,

    _SC_NL_NMAX,

    _SC_NL_SETMAX,

    _SC_NL_TEXTMAX,


    _SC_XBS5_ILP32_OFF32,

    _SC_XBS5_ILP32_OFFBIG,

    _SC_XBS5_LP64_OFF64,

    _SC_XBS5_LPBIG_OFFBIG,


    _SC_XOPEN_LEGACY,

    _SC_XOPEN_REALTIME,

    _SC_XOPEN_REALTIME_THREADS,


    _SC_ADVISORY_INFO,

    _SC_BARRIERS,

    _SC_BASE,

    _SC_C_LANG_SUPPORT,

    _SC_C_LANG_SUPPORT_R,

    _SC_CLOCK_SELECTION,

    _SC_CPUTIME,

    _SC_THREAD_CPUTIME,

    _SC_DEVICE_IO,

    _SC_DEVICE_SPECIFIC,

    _SC_DEVICE_SPECIFIC_R,

    _SC_FD_MGMT,

    _SC_FIFO,

    _SC_PIPE,

    _SC_FILE_ATTRIBUTES,

    _SC_FILE_LOCKING,

    _SC_FILE_SYSTEM,

    _SC_MONOTONIC_CLOCK,

    _SC_MULTI_PROCESS,

    _SC_SINGLE_PROCESS,

    _SC_NETWORKING,

    _SC_READER_WRITER_LOCKS,

    _SC_SPIN_LOCKS,

    _SC_REGEXP,

    _SC_REGEX_VERSION,

    _SC_SHELL,

    _SC_SIGNALS,

    _SC_SPAWN,

    _SC_SPORADIC_SERVER,

    _SC_THREAD_SPORADIC_SERVER,

    _SC_SYSTEM_DATABASE,

    _SC_SYSTEM_DATABASE_R,

    _SC_TIMEOUTS,

    _SC_TYPED_MEMORY_OBJECTS,

    _SC_USER_GROUPS,

    _SC_USER_GROUPS_R,

    _SC_2_PBS,

    _SC_2_PBS_ACCOUNTING,

    _SC_2_PBS_LOCATE,

    _SC_2_PBS_MESSAGE,

    _SC_2_PBS_TRACK,

    _SC_SYMLOOP_MAX,

    _SC_STREAMS,

    _SC_2_PBS_CHECKPOINT,


    _SC_V6_ILP32_OFF32,

    _SC_V6_ILP32_OFFBIG,

    _SC_V6_LP64_OFF64,

    _SC_V6_LPBIG_OFFBIG,


    _SC_HOST_NAME_MAX,

    _SC_TRACE,

    _SC_TRACE_EVENT_FILTER,

    _SC_TRACE_INHERIT,

    _SC_TRACE_LOG,


    _SC_LEVEL1_ICACHE_SIZE,

    _SC_LEVEL1_ICACHE_ASSOC,

    _SC_LEVEL1_ICACHE_LINESIZE,

    _SC_LEVEL1_DCACHE_SIZE,

    _SC_LEVEL1_DCACHE_ASSOC,

    _SC_LEVEL1_DCACHE_LINESIZE,

    _SC_LEVEL2_CACHE_SIZE,

    _SC_LEVEL2_CACHE_ASSOC,

    _SC_LEVEL2_CACHE_LINESIZE,

    _SC_LEVEL3_CACHE_SIZE,

    _SC_LEVEL3_CACHE_ASSOC,

    _SC_LEVEL3_CACHE_LINESIZE,

    _SC_LEVEL4_CACHE_SIZE,

    _SC_LEVEL4_CACHE_ASSOC,

    _SC_LEVEL4_CACHE_LINESIZE,



    _SC_IPV6 = _SC_LEVEL1_ICACHE_SIZE + 50,

    _SC_RAW_SOCKETS,


    _SC_V7_ILP32_OFF32,

    _SC_V7_ILP32_OFFBIG,

    _SC_V7_LP64_OFF64,

    _SC_V7_LPBIG_OFFBIG,


    _SC_SS_REPL_MAX,


    _SC_TRACE_EVENT_NAME_MAX,

    _SC_TRACE_NAME_MAX,

    _SC_TRACE_SYS_MAX,

    _SC_TRACE_USER_EVENT_MAX,


    _SC_XOPEN_STREAMS,


    _SC_THREAD_ROBUST_PRIO_INHERIT,

    _SC_THREAD_ROBUST_PRIO_PROTECT,


    _SC_MINSIGSTKSZ,


    _SC_SIGSTKSZ

  };


enum
  {
    _CS_PATH,


    _CS_V6_WIDTH_RESTRICTED_ENVS,



    _CS_GNU_LIBC_VERSION,

    _CS_GNU_LIBPTHREAD_VERSION,


    _CS_V5_WIDTH_RESTRICTED_ENVS,



    _CS_V7_WIDTH_RESTRICTED_ENVS,



    _CS_LFS_CFLAGS = 1000,

    _CS_LFS_LDFLAGS,

    _CS_LFS_LIBS,

    _CS_LFS_LINTFLAGS,

    _CS_LFS64_CFLAGS,

    _CS_LFS64_LDFLAGS,

    _CS_LFS64_LIBS,

    _CS_LFS64_LINTFLAGS,


    _CS_XBS5_ILP32_OFF32_CFLAGS = 1100,

    _CS_XBS5_ILP32_OFF32_LDFLAGS,

    _CS_XBS5_ILP32_OFF32_LIBS,

    _CS_XBS5_ILP32_OFF32_LINTFLAGS,

    _CS_XBS5_ILP32_OFFBIG_CFLAGS,

    _CS_XBS5_ILP32_OFFBIG_LDFLAGS,

    _CS_XBS5_ILP32_OFFBIG_LIBS,

    _CS_XBS5_ILP32_OFFBIG_LINTFLAGS,

    _CS_XBS5_LP64_OFF64_CFLAGS,

    _CS_XBS5_LP64_OFF64_LDFLAGS,

    _CS_XBS5_LP64_OFF64_LIBS,

    _CS_XBS5_LP64_OFF64_LINTFLAGS,

    _CS_XBS5_LPBIG_OFFBIG_CFLAGS,

    _CS_XBS5_LPBIG_OFFBIG_LDFLAGS,

    _CS_XBS5_LPBIG_OFFBIG_LIBS,

    _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS,


    _CS_POSIX_V6_ILP32_OFF32_CFLAGS,

    _CS_POSIX_V6_ILP32_OFF32_LDFLAGS,

    _CS_POSIX_V6_ILP32_OFF32_LIBS,

    _CS_POSIX_V6_ILP32_OFF32_LINTFLAGS,

    _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS,

    _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS,

    _CS_POSIX_V6_ILP32_OFFBIG_LIBS,

    _CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS,

    _CS_POSIX_V6_LP64_OFF64_CFLAGS,

    _CS_POSIX_V6_LP64_OFF64_LDFLAGS,

    _CS_POSIX_V6_LP64_OFF64_LIBS,

    _CS_POSIX_V6_LP64_OFF64_LINTFLAGS,

    _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS,

    _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS,

    _CS_POSIX_V6_LPBIG_OFFBIG_LIBS,

    _CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS,


    _CS_POSIX_V7_ILP32_OFF32_CFLAGS,

    _CS_POSIX_V7_ILP32_OFF32_LDFLAGS,

    _CS_POSIX_V7_ILP32_OFF32_LIBS,

    _CS_POSIX_V7_ILP32_OFF32_LINTFLAGS,

    _CS_POSIX_V7_ILP32_OFFBIG_CFLAGS,

    _CS_POSIX_V7_ILP32_OFFBIG_LDFLAGS,

    _CS_POSIX_V7_ILP32_OFFBIG_LIBS,

    _CS_POSIX_V7_ILP32_OFFBIG_LINTFLAGS,

    _CS_POSIX_V7_LP64_OFF64_CFLAGS,

    _CS_POSIX_V7_LP64_OFF64_LDFLAGS,

    _CS_POSIX_V7_LP64_OFF64_LIBS,

    _CS_POSIX_V7_LP64_OFF64_LINTFLAGS,

    _CS_POSIX_V7_LPBIG_OFFBIG_CFLAGS,

    _CS_POSIX_V7_LPBIG_OFFBIG_LDFLAGS,

    _CS_POSIX_V7_LPBIG_OFFBIG_LIBS,

    _CS_POSIX_V7_LPBIG_OFFBIG_LINTFLAGS,


    _CS_V6_ENV,

    _CS_V7_ENV

  };
# 631 "/usr/include/unistd.h" 2 3 4


extern long int pathconf (const char *__path, int __name)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern long int fpathconf (int __fd, int __name) __attribute__ ((__nothrow__ , __leaf__));


extern long int sysconf (int __name) __attribute__ ((__nothrow__ , __leaf__));



extern size_t confstr (int __name, char *__buf, size_t __len) __attribute__ ((__nothrow__ , __leaf__))
    __attribute__ ((__access__ (__write_only__, 2, 3)));




extern __pid_t getpid (void) __attribute__ ((__nothrow__ , __leaf__));


extern __pid_t getppid (void) __attribute__ ((__nothrow__ , __leaf__));


extern __pid_t getpgrp (void) __attribute__ ((__nothrow__ , __leaf__));


extern __pid_t __getpgid (__pid_t __pid) __attribute__ ((__nothrow__ , __leaf__));

extern __pid_t getpgid (__pid_t __pid) __attribute__ ((__nothrow__ , __leaf__));






extern int setpgid (__pid_t __pid, __pid_t __pgid) __attribute__ ((__nothrow__ , __leaf__));
# 682 "/usr/include/unistd.h" 3 4
extern int setpgrp (void) __attribute__ ((__nothrow__ , __leaf__));






extern __pid_t setsid (void) __attribute__ ((__nothrow__ , __leaf__));



extern __pid_t getsid (__pid_t __pid) __attribute__ ((__nothrow__ , __leaf__));



extern __uid_t getuid (void) __attribute__ ((__nothrow__ , __leaf__));


extern __uid_t geteuid (void) __attribute__ ((__nothrow__ , __leaf__));


extern __gid_t getgid (void) __attribute__ ((__nothrow__ , __leaf__));


extern __gid_t getegid (void) __attribute__ ((__nothrow__ , __leaf__));




extern int getgroups (int __size, __gid_t __list[]) __attribute__ ((__nothrow__ , __leaf__))
    __attribute__ ((__access__ (__write_only__, 2, 1)));
# 722 "/usr/include/unistd.h" 3 4
extern int setuid (__uid_t __uid) __attribute__ ((__nothrow__ , __leaf__)) ;




extern int setreuid (__uid_t __ruid, __uid_t __euid) __attribute__ ((__nothrow__ , __leaf__)) ;




extern int seteuid (__uid_t __uid) __attribute__ ((__nothrow__ , __leaf__)) ;






extern int setgid (__gid_t __gid) __attribute__ ((__nothrow__ , __leaf__)) ;




extern int setregid (__gid_t __rgid, __gid_t __egid) __attribute__ ((__nothrow__ , __leaf__)) ;




extern int setegid (__gid_t __gid) __attribute__ ((__nothrow__ , __leaf__)) ;
# 778 "/usr/include/unistd.h" 3 4
extern __pid_t fork (void) __attribute__ ((__nothrow__));







extern __pid_t vfork (void) __attribute__ ((__nothrow__ , __leaf__));
# 799 "/usr/include/unistd.h" 3 4
extern char *ttyname (int __fd) __attribute__ ((__nothrow__ , __leaf__));



extern int ttyname_r (int __fd, char *__buf, size_t __buflen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)))
     __attribute__ ((__access__ (__write_only__, 2, 3)));



extern int isatty (int __fd) __attribute__ ((__nothrow__ , __leaf__));




extern int ttyslot (void) __attribute__ ((__nothrow__ , __leaf__));




extern int link (const char *__from, const char *__to)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) ;




extern int linkat (int __fromfd, const char *__from, int __tofd,
     const char *__to, int __flags)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4))) ;




extern int symlink (const char *__from, const char *__to)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) ;




extern ssize_t readlink (const char *__restrict __path,
    char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)))
     __attribute__ ((__access__ (__write_only__, 2, 3)));





extern int symlinkat (const char *__from, int __tofd,
        const char *__to) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3))) ;


extern ssize_t readlinkat (int __fd, const char *__restrict __path,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)))
     __attribute__ ((__access__ (__write_only__, 3, 4)));



extern int unlink (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));



extern int unlinkat (int __fd, const char *__name, int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));



extern int rmdir (const char *__path) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));



extern __pid_t tcgetpgrp (int __fd) __attribute__ ((__nothrow__ , __leaf__));


extern int tcsetpgrp (int __fd, __pid_t __pgrp_id) __attribute__ ((__nothrow__ , __leaf__));






extern char *getlogin (void);







extern int getlogin_r (char *__name, size_t __name_len) __attribute__ ((__nonnull__ (1)))
    __attribute__ ((__access__ (__write_only__, 1, 2)));




extern int setlogin (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));







# 1 "/usr/include/bits/getopt_posix.h" 1 3 4
# 27 "/usr/include/bits/getopt_posix.h" 3 4
# 1 "/usr/include/bits/getopt_core.h" 1 3 4
# 28 "/usr/include/bits/getopt_core.h" 3 4








extern char *optarg;
# 50 "/usr/include/bits/getopt_core.h" 3 4
extern int optind;




extern int opterr;



extern int optopt;
# 91 "/usr/include/bits/getopt_core.h" 3 4
extern int getopt (int ___argc, char *const *___argv, const char *__shortopts)
       __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));


# 28 "/usr/include/bits/getopt_posix.h" 2 3 4


# 49 "/usr/include/bits/getopt_posix.h" 3 4

# 904 "/usr/include/unistd.h" 2 3 4







extern int gethostname (char *__name, size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)))
    __attribute__ ((__access__ (__write_only__, 1, 2)));






extern int sethostname (const char *__name, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__access__ (__read_only__, 1, 2)));



extern int sethostid (long int __id) __attribute__ ((__nothrow__ , __leaf__)) ;





extern int getdomainname (char *__name, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)))
     __attribute__ ((__access__ (__write_only__, 1, 2)));
extern int setdomainname (const char *__name, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__access__ (__read_only__, 1, 2)));




extern int vhangup (void) __attribute__ ((__nothrow__ , __leaf__));


extern int revoke (const char *__file) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;







extern int profil (unsigned short int *__sample_buffer, size_t __size,
     size_t __offset, unsigned int __scale)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





extern int acct (const char *__name) __attribute__ ((__nothrow__ , __leaf__));



extern char *getusershell (void) __attribute__ ((__nothrow__ , __leaf__));
extern void endusershell (void) __attribute__ ((__nothrow__ , __leaf__));
extern void setusershell (void) __attribute__ ((__nothrow__ , __leaf__));





extern int daemon (int __nochdir, int __noclose) __attribute__ ((__nothrow__ , __leaf__)) ;






extern int chroot (const char *__path) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;



extern char *getpass (const char *__prompt) __attribute__ ((__nonnull__ (1)));







extern int fsync (int __fd);
# 1002 "/usr/include/unistd.h" 3 4
extern long int gethostid (void);


extern void sync (void) __attribute__ ((__nothrow__ , __leaf__));





extern int getpagesize (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));




extern int getdtablesize (void) __attribute__ ((__nothrow__ , __leaf__));
# 1026 "/usr/include/unistd.h" 3 4
extern int truncate (const char *__file, __off_t __length)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
# 1049 "/usr/include/unistd.h" 3 4
extern int ftruncate (int __fd, __off_t __length) __attribute__ ((__nothrow__ , __leaf__)) ;
# 1070 "/usr/include/unistd.h" 3 4
extern int brk (void *__addr) __attribute__ ((__nothrow__ , __leaf__)) ;





extern void *sbrk (intptr_t __delta) __attribute__ ((__nothrow__ , __leaf__));
# 1091 "/usr/include/unistd.h" 3 4
extern long int syscall (long int __sysno, ...) __attribute__ ((__nothrow__ , __leaf__));
# 1114 "/usr/include/unistd.h" 3 4
extern int lockf (int __fd, int __cmd, __off_t __len) ;
# 1150 "/usr/include/unistd.h" 3 4
extern int fdatasync (int __fildes);
# 1162 "/usr/include/unistd.h" 3 4
extern char *crypt (const char *__key, const char *__salt)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
# 1201 "/usr/include/unistd.h" 3 4
int getentropy (void *__buffer, size_t __length)
    __attribute__ ((__access__ (__write_only__, 1, 2)));
# 1221 "/usr/include/unistd.h" 3 4
# 1 "/usr/include/bits/unistd_ext.h" 1 3 4
# 1222 "/usr/include/unistd.h" 2 3 4


# 58 "./cye.h" 2
# 1 "/usr/include/fcntl.h" 1 3 4
# 28 "/usr/include/fcntl.h" 3 4







# 1 "/usr/include/bits/fcntl.h" 1 3 4
# 35 "/usr/include/bits/fcntl.h" 3 4
struct flock
  {
    short int l_type;
    short int l_whence;

    __off_t l_start;
    __off_t l_len;




    __pid_t l_pid;
  };
# 61 "/usr/include/bits/fcntl.h" 3 4
# 1 "/usr/include/bits/fcntl-linux.h" 1 3 4
# 382 "/usr/include/bits/fcntl-linux.h" 3 4

# 456 "/usr/include/bits/fcntl-linux.h" 3 4

# 62 "/usr/include/bits/fcntl.h" 2 3 4
# 36 "/usr/include/fcntl.h" 2 3 4
# 78 "/usr/include/fcntl.h" 3 4
# 1 "/usr/include/bits/stat.h" 1 3 4
# 79 "/usr/include/fcntl.h" 2 3 4
# 177 "/usr/include/fcntl.h" 3 4
extern int fcntl (int __fd, int __cmd, ...);
# 209 "/usr/include/fcntl.h" 3 4
extern int open (const char *__file, int __oflag, ...) __attribute__ ((__nonnull__ (1)));
# 233 "/usr/include/fcntl.h" 3 4
extern int openat (int __fd, const char *__file, int __oflag, ...)
     __attribute__ ((__nonnull__ (2)));
# 255 "/usr/include/fcntl.h" 3 4
extern int creat (const char *__file, mode_t __mode) __attribute__ ((__nonnull__ (1)));
# 301 "/usr/include/fcntl.h" 3 4
extern int posix_fadvise (int __fd, off_t __offset, off_t __len,
     int __advise) __attribute__ ((__nothrow__ , __leaf__));
# 323 "/usr/include/fcntl.h" 3 4
extern int posix_fallocate (int __fd, off_t __offset, off_t __len);
# 344 "/usr/include/fcntl.h" 3 4

# 59 "./cye.h" 2
# 1 "/usr/include/dirent.h" 1 3 4
# 27 "/usr/include/dirent.h" 3 4

# 61 "/usr/include/dirent.h" 3 4
# 1 "/usr/include/bits/dirent.h" 1 3 4
# 22 "/usr/include/bits/dirent.h" 3 4
struct dirent
  {

    __ino_t d_ino;
    __off_t d_off;




    unsigned short int d_reclen;
    unsigned char d_type;
    char d_name[256];
  };
# 62 "/usr/include/dirent.h" 2 3 4
# 97 "/usr/include/dirent.h" 3 4
enum
  {
    DT_UNKNOWN = 0,

    DT_FIFO = 1,

    DT_CHR = 2,

    DT_DIR = 4,

    DT_BLK = 6,

    DT_REG = 8,

    DT_LNK = 10,

    DT_SOCK = 12,

    DT_WHT = 14

  };
# 127 "/usr/include/dirent.h" 3 4
typedef struct __dirstream DIR;






extern int closedir (DIR *__dirp) __attribute__ ((__nonnull__ (1)));






extern DIR *opendir (const char *__name) __attribute__ ((__nonnull__ (1)))
 __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (closedir, 1)));






extern DIR *fdopendir (int __fd)
 __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (closedir, 1)));
# 164 "/usr/include/dirent.h" 3 4
extern struct dirent *readdir (DIR *__dirp) __attribute__ ((__nonnull__ (1)));
# 185 "/usr/include/dirent.h" 3 4
extern int readdir_r (DIR *__restrict __dirp,
        struct dirent *__restrict __entry,
        struct dirent **__restrict __result)
     __attribute__ ((__nonnull__ (1, 2, 3))) __attribute__ ((__deprecated__));
# 211 "/usr/include/dirent.h" 3 4
extern void rewinddir (DIR *__dirp) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





extern void seekdir (DIR *__dirp, long int __pos) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern long int telldir (DIR *__dirp) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





extern int dirfd (DIR *__dirp) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 247 "/usr/include/dirent.h" 3 4
# 1 "/usr/lib/gcc/x86_64-pc-linux-gnu/14.2.1/include/stddef.h" 1 3 4
# 248 "/usr/include/dirent.h" 2 3 4
# 257 "/usr/include/dirent.h" 3 4
extern int scandir (const char *__restrict __dir,
      struct dirent ***__restrict __namelist,
      int (*__selector) (const struct dirent *),
      int (*__cmp) (const struct dirent **,
      const struct dirent **))
     __attribute__ ((__nonnull__ (1, 2)));
# 327 "/usr/include/dirent.h" 3 4
extern int alphasort (const struct dirent **__e1,
        const struct dirent **__e2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 355 "/usr/include/dirent.h" 3 4
extern __ssize_t getdirentries (int __fd, char *__restrict __buf,
    size_t __nbytes,
    __off_t *__restrict __basep)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)));
# 404 "/usr/include/dirent.h" 3 4


# 1 "/usr/include/bits/dirent_ext.h" 1 3 4
# 23 "/usr/include/bits/dirent_ext.h" 3 4

# 33 "/usr/include/bits/dirent_ext.h" 3 4

# 407 "/usr/include/dirent.h" 2 3 4
# 60 "./cye.h" 2
# 1 "/usr/include/pwd.h" 1 3 4
# 27 "/usr/include/pwd.h" 3 4





# 1 "/usr/lib/gcc/x86_64-pc-linux-gnu/14.2.1/include/stddef.h" 1 3 4
# 33 "/usr/include/pwd.h" 2 3 4
# 49 "/usr/include/pwd.h" 3 4
struct passwd
{
  char *pw_name;
  char *pw_passwd;

  __uid_t pw_uid;
  __gid_t pw_gid;
  char *pw_gecos;
  char *pw_dir;
  char *pw_shell;
};
# 72 "/usr/include/pwd.h" 3 4
extern void setpwent (void);





extern void endpwent (void);





extern struct passwd *getpwent (void);
# 94 "/usr/include/pwd.h" 3 4
extern struct passwd *fgetpwent (FILE *__stream) __attribute__ ((__nonnull__ (1)));







extern int putpwent (const struct passwd *__restrict __p,
       FILE *__restrict __f);






extern struct passwd *getpwuid (__uid_t __uid);





extern struct passwd *getpwnam (const char *__name) __attribute__ ((__nonnull__ (1)));
# 139 "/usr/include/pwd.h" 3 4
extern int getpwent_r (struct passwd *__restrict __resultbuf,
         char *__restrict __buffer, size_t __buflen,
         struct passwd **__restrict __result)
    __attribute__ ((__nonnull__ (1, 2, 4)))
    __attribute__ ((__access__ (__write_only__, 2, 3)));


extern int getpwuid_r (__uid_t __uid,
         struct passwd *__restrict __resultbuf,
         char *__restrict __buffer, size_t __buflen,
         struct passwd **__restrict __result)
    __attribute__ ((__nonnull__ (2, 3, 5)))
    __attribute__ ((__access__ (__write_only__, 3, 4)));

extern int getpwnam_r (const char *__restrict __name,
         struct passwd *__restrict __resultbuf,
         char *__restrict __buffer, size_t __buflen,
         struct passwd **__restrict __result)
    __attribute__ ((__nonnull__ (1, 2, 3, 5)))
    __attribute__ ((__access__ (__write_only__, 3, 4)));
# 169 "/usr/include/pwd.h" 3 4
extern int fgetpwent_r (FILE *__restrict __stream,
   struct passwd *__restrict __resultbuf,
   char *__restrict __buffer, size_t __buflen,
   struct passwd **__restrict __result)
    __attribute__ ((__nonnull__ (1, 2, 3, 5)))
    __attribute__ ((__access__ (__write_only__, 3, 4)));
# 191 "/usr/include/pwd.h" 3 4

# 61 "./cye.h" 2
# 1 "/usr/include/utime.h" 1 3 4
# 27 "/usr/include/utime.h" 3 4

# 36 "/usr/include/utime.h" 3 4
struct utimbuf
  {




    __time_t actime;
    __time_t modtime;

  };




extern int utime (const char *__file,
    const struct utimbuf *__file_times)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 64 "/usr/include/utime.h" 3 4

# 62 "./cye.h" 2
# 347 "./cye.h"
# 1 "/usr/lib/gcc/x86_64-pc-linux-gnu/14.2.1/include/stdbool.h" 1 3 4
# 348 "./cye.h" 2
# 358 "./cye.h"

# 358 "./cye.h"
typedef float f32;
typedef double f64;


typedef __uint128_t u128;
typedef uint64_t u64;
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;
typedef uint8_t byte;

typedef void u0;
typedef void* rawptr;


typedef int64_t i64;
typedef int32_t i32;
typedef int16_t i16;
typedef int8_t i8;
typedef size_t usz;
typedef ptrdiff_t isz;

typedef size_t usize;
typedef ptrdiff_t isize;


typedef i32 rune;
typedef i8 b8;
typedef i16 b16;
typedef i32 b32;







typedef const char* ZString;
typedef char* TString;
typedef char* MutString;






typedef enum {
    CYE_LOG_ALL = 0,
    CYE_LOG_TRACE,
    CYE_LOG_DEBUG,
    CYE_LOG_INFO,
    CYE_LOG_OKAY,
    CYE_LOG_WARNING,
    CYE_TRACE_ERROR,
    CYE_LOG_FATAL,
    CYE_LOG_NONE
} Cye_Log_Level;
# 423 "./cye.h"
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
    usz count;
    usz capacity;
} Cye_DString;
# 459 "./cye.h"
    typedef int Cye_Process;
    typedef int Cye_File_Handle;


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

typedef struct { Cye_String_Slice *items; usz count; usz capacity; } Cye_String_Slice_DArray;

typedef struct {
    void* (*alloc)(usz size);
    void* (*realloc) (void *ptr, usz size);
    void (*free)(void* ptr);
    rawptr any;
} Cye_Context;
# 507 "./cye.h"
Cye_File_Handle cye_file_open_for_read(const char *path);
Cye_File_Handle cye_file_open_for_write(const char *path);
void cye_file_close(Cye_File_Handle fh);

# 510 "./cye.h" 3 4
_Bool 
# 510 "./cye.h"
    cye_process_wait_all(Cye_Process_DArray procs);

# 511 "./cye.h" 3 4
_Bool 
# 511 "./cye.h"
    cye_process_wait_all_and_reset(Cye_Process_DArray *procs);

# 512 "./cye.h" 3 4
_Bool 
# 512 "./cye.h"
    cye_process_wait(Cye_Process proc);
# 530 "./cye.h"
void cye_ds_write_cmd(Cye_DString *ds, Cye_Command cmd);


Cye_Process cye_cmd_run_async_and_reset(Cye_Command *cmd);


Cye_Process cye_cmd_run_async_redirect(Cye_Command cmd, Cye_Command_Redirect redirect);


Cye_Process cye_cmd_run_async_redirect_and_reset(Cye_Command *cmd, Cye_Command_Redirect redirect);






# 545 "./cye.h" 3 4
_Bool 
# 545 "./cye.h"
    cye_cmd_run_sync(Cye_Command cmd);


# 547 "./cye.h" 3 4
_Bool 
# 547 "./cye.h"
    cye_cmd_run_sync_and_reset(Cye_Command *cmd);



# 550 "./cye.h" 3 4
_Bool 
# 550 "./cye.h"
    cye_cmd_run_sync_redirect(Cye_Command cmd, Cye_Command_Redirect redirect);



# 553 "./cye.h" 3 4
_Bool 
# 553 "./cye.h"
    cye_cmd_run_sync_redirect_and_reset(Cye_Command *cmd, Cye_Command_Redirect redirect);
# 575 "./cye.h"
void cye__rebuild_ourselves(ZString source_path, int argc, ZString *argv);
# 585 "./cye.h"
Cye_Context cye_temp_context(void);
Cye_Context cye_default_context(void);

u0 cye_set_default_context(Cye_Context ctx);

char* cye_tstrdup(const char *cstr);
void* cye_talloc(usz size);
void* cye_trealloc(void *ptr, usz size);
void cye_tfree(rawptr ptr);

TString cye_tprintf(ZString fmt, ...);

void cye_temp_reset(void);
usz cye_temp_save(void);
void cye_temp_rewind(usz checkpoint);






# 605 "./cye.h" 3 4
_Bool 
# 605 "./cye.h"
    cye_make_dir_if_not_exists(const char *path);

# 606 "./cye.h" 3 4
_Bool 
# 606 "./cye.h"
    cye_copy_file(const char *src_path, const char *dst_path);

# 607 "./cye.h" 3 4
_Bool 
# 607 "./cye.h"
    cye_copy_dir(const char *src_path, const char *dst_path);

# 608 "./cye.h" 3 4
_Bool 
# 608 "./cye.h"
    cye_read_entire_dir(const char *parent, Cye_Path_DArray *children);




# 612 "./cye.h" 3 4
_Bool 
# 612 "./cye.h"
    cye_file_append(const char* path, const void* data, size_t count);



# 615 "./cye.h" 3 4
_Bool 
# 615 "./cye.h"
    cye_file_append_zstr(const char* path, const char* str);



# 618 "./cye.h" 3 4
_Bool 
# 618 "./cye.h"
    cye_file_write_all(const char *path, const void *data, usz size);




# 622 "./cye.h" 3 4
_Bool 
# 622 "./cye.h"
    cye_file_read_all(const char *path, Cye_DString *ds);


Cye_File_Type cye_path_file_type(const char *path);


char* cye_path_temp_normalize(ZString path);


char* cye_path_create_from_array(ZString paths[], usz paths_count);
# 650 "./cye.h"
ZString cye_path_base_name(const char *path);
ZString cye_path_expand_user(ZString path);
ZString cye_path_expand_vars(ZString path);

int cye_needs_rebuild_from_buf(const char *output_path, const char **input_paths, usz input_paths_count);
# 663 "./cye.h"
TString cye_path_temp_cwd(void);

# 664 "./cye.h" 3 4
_Bool 
# 664 "./cye.h"
    cye_path_set_cwd(const char *path);

b32 cye_file_exists(const char *file_path);

# 667 "./cye.h" 3 4
_Bool 
# 667 "./cye.h"
    cye_file_stats(const char* path, Cye_File_Stats* stats);

# 668 "./cye.h" 3 4
_Bool 
# 668 "./cye.h"
    cye_is_absolute(ZString path);

# 669 "./cye.h" 3 4
_Bool 
# 669 "./cye.h"
    cye_is_relative(ZString path);

# 670 "./cye.h" 3 4
_Bool 
# 670 "./cye.h"
    cye_is_file(ZString path);

# 671 "./cye.h" 3 4
_Bool 
# 671 "./cye.h"
    cye_is_dir(ZString path);

# 672 "./cye.h" 3 4
_Bool 
# 672 "./cye.h"
    cye_is_link(ZString path);

# 673 "./cye.h" 3 4
_Bool 
# 673 "./cye.h"
    cye_is_mount(ZString path);

# 674 "./cye.h" 3 4
_Bool 
# 674 "./cye.h"
    cye_is_same_path(ZString path1, ZString path2);

Cye_DString cye_path_join(ZString path, ZString* paths);

usz cye_path_size(ZString path);

ZString cye_path_real(ZString path);
ZString cye_path_absolute(ZString path);
ZString cye_path_relative(ZString from, ZString target);

ZString cye_path_home(void);
ZString cye_path_cwd(void);
ZString cye_path_parent(ZString path);
ZString cye_path_owner(ZString path);
ZString cye_path_stem(ZString path);
ZString cye_path_dir_of(ZString file_path);
ZString cye_path_ext(ZString path);

# 691 "./cye.h" 3 4
_Bool 
# 691 "./cye.h"
       cye_path_touch(ZString path);




# 695 "./cye.h" 3 4
_Bool 
# 695 "./cye.h"
    cye_make_dir_include_parents(ZString path);

# 696 "./cye.h" 3 4
_Bool 
# 696 "./cye.h"
    cye_make_dir_include_parents_from_tstr(TString path);


# 698 "./cye.h" 3 4
_Bool 
# 698 "./cye.h"
    cye_remove_file(ZString path);

# 699 "./cye.h" 3 4
_Bool 
# 699 "./cye.h"
    cye_remove_dir(ZString path);

# 700 "./cye.h" 3 4
_Bool 
# 700 "./cye.h"
    cye_remove_dirs(ZString path);

# 701 "./cye.h" 3 4
_Bool 
# 701 "./cye.h"
    cye_path_move(ZString src, ZString dst);

# 702 "./cye.h" 3 4
_Bool 
# 702 "./cye.h"
    cye_path_rename(ZString src, ZString dst);

# 703 "./cye.h" 3 4
_Bool 
# 703 "./cye.h"
    cye_path_renames(ZString old_path, ZString new_path);

# 704 "./cye.h" 3 4
_Bool 
# 704 "./cye.h"
    cye_path_replace(ZString src, ZString dst);

Cye_Path_DArray cye_path_scandir(ZString path);
# 838 "./cye.h"
Cye_String_Slice cye_str_slice_make(const char *str);


Cye_String_Slice cye_str_slice_trim(Cye_String_Slice s);


void cye_str_slice_to_zstr(Cye_String_Slice s, char *buf, usz buf_size);


Cye_String_Slice cye_str_slice_strip_left(Cye_String_Slice s);


Cye_String_Slice cye_str_slice_strip_right(Cye_String_Slice s);


Cye_String_Slice cye_str_slice_make_len(const char *str, usz len);



# 856 "./cye.h" 3 4
_Bool 
# 856 "./cye.h"
    cye_str_slice_equals(Cye_String_Slice a, Cye_String_Slice b);



# 859 "./cye.h" 3 4
_Bool 
# 859 "./cye.h"
    cye_str_slice_contains(Cye_String_Slice haystack, Cye_String_Slice needle);


Cye_String_Slice_DArray cye_str_slice_split(Cye_String_Slice s, Cye_String_Slice delim);


void cye_str_slice_split_first(Cye_String_Slice s, char delim, Cye_String_Slice *before, Cye_String_Slice *after);



# 868 "./cye.h" 3 4
_Bool 
# 868 "./cye.h"
    cye_str_slice_starts_with(Cye_String_Slice s, Cye_String_Slice prefix);



# 871 "./cye.h" 3 4
_Bool 
# 871 "./cye.h"
    cye_str_slice_ends_with(Cye_String_Slice s, Cye_String_Slice suffix);



# 874 "./cye.h" 3 4
_Bool 
# 874 "./cye.h"
    cye_str_slice_ends_with_zstr(Cye_String_Slice s, ZString suffix);



# 877 "./cye.h" 3 4
_Bool 
# 877 "./cye.h"
    cye_str_slice_starts_with_zstr(Cye_String_Slice s, ZString prefix);






# 883 "./cye.h" 3 4
_Bool 
# 883 "./cye.h"
    cye_zstr_ends_with(ZString src, ZString ending);

# 884 "./cye.h" 3 4
_Bool 
# 884 "./cye.h"
    cye_zstr_starts_with(ZString src, ZString prefix);
# 929 "./cye.h"
void cye_ds_printf(Cye_DString *ds, ZString fmt, ...);
# 946 "./cye.h"
f32 cye_clamp(f32 value, f32 min, f32 max);


f32 cye_lerp(f32 start, f32 end, f32 amount);


f32 cye_normalize(f32 value, f32 start, f32 end);


f32 cye_remap(f32 value, f32 inputStart, f32 inputEnd, f32 outputStart, f32 outputEnd);


f32 cye_wrap(f32 value, f32 min, f32 max);


int cye_float_equals(f32 x, f32 y);





void cye_set_trace_level(Cye_Log_Level level);
void cye_trace_log(Cye_Log_Level level, const char *fmt, ...);
# 987 "./cye.h"
void cye__assert_handler(char const *prefix, char const *condition, char const *file, int line, char const *msg, ...);
# 1058 "./cye.h"
TString cye_file_stats_tstring(Cye_File_Stats stats);
TString cye_str_slice_tstring(Cye_String_Slice ss);
TString cye_ds_tstring(Cye_DString ds);
# 1072 "./cye.h"
const char *cye_cpu_architecture(void);
# 1090 "./cye.h"
static struct {
    usz size;
    rawptr last;
    byte buffer[(((16) * (i64)(1024)) * (i64)(1024))];
} cye_temp_data = {0};

static Cye_Log_Level cye_threshold_log_level = CYE_LOG_INFO;

__thread Cye_Context cye_context = {.alloc = malloc, .realloc = realloc, .free = free, .any=((void *)0)};
# 1111 "./cye.h"
Cye_File_Handle cye_file_open_for_write(ZString path) {

    Cye_File_Handle result = open(path,
        
# 1114 "./cye.h" 3 4
       01 
# 1114 "./cye.h"
                | 
# 1114 "./cye.h" 3 4
                  0100 
# 1114 "./cye.h"
                          | 
# 1114 "./cye.h" 3 4
                            01000
# 1114 "./cye.h"
                                   ,
        
# 1115 "./cye.h" 3 4
       0400 
# 1115 "./cye.h"
               | 
# 1115 "./cye.h" 3 4
                 0200 
# 1115 "./cye.h"
                         | 
# 1115 "./cye.h" 3 4
                           (0400 >> 3) 
# 1115 "./cye.h"
                                   | 
# 1115 "./cye.h" 3 4
                                     ((0400 >> 3) >> 3)
    
# 1116 "./cye.h"
   );

    if (result < 0) {
        cye_trace_log(CYE_TRACE_ERROR, "Could not open file %s: %s", path, (strerror(
# 1119 "./cye.h" 3 4
                                                                          (*__errno_location ())
# 1119 "./cye.h"
                                                                          )));
        return (-1);
    }
    return result;
# 1146 "./cye.h"
}
void cye_file_close(Cye_File_Handle handle) {

    close(handle);



}


# 1155 "./cye.h" 3 4
_Bool 
# 1155 "./cye.h"
    cye_process_wait_all(Cye_Process_DArray procs) {
    
# 1156 "./cye.h" 3 4
   _Bool 
# 1156 "./cye.h"
        success = 
# 1156 "./cye.h" 3 4
                  1
# 1156 "./cye.h"
                      ;

    for (usz i = 0; i < procs.count; ++i) {
        success = cye_process_wait(procs.items[i]) && success;
    }
    return success;
}


# 1164 "./cye.h" 3 4
_Bool 
# 1164 "./cye.h"
    cye_process_wait_all_and_reset(Cye_Process_DArray *procs) {
    
# 1165 "./cye.h" 3 4
   _Bool 
# 1165 "./cye.h"
        success = cye_process_wait_all(*procs);
    procs->count = 0;
    return success;
}



# 1171 "./cye.h" 3 4
_Bool 
# 1171 "./cye.h"
    cye_process_wait(Cye_Process proc) {

    if (proc == (-1)) {
        return 
# 1174 "./cye.h" 3 4
              0
# 1174 "./cye.h"
                   ;
    }


    for (;;) {
        int wstatus = 0;
        if (waitpid(proc, &wstatus, 0) < 0) {
            cye_trace_log(CYE_TRACE_ERROR, "Could not wait on command (pid %d): %s", proc, (strerror(
# 1181 "./cye.h" 3 4
                                                                                          (*__errno_location ())
# 1181 "./cye.h"
                                                                                          )));
            return 
# 1182 "./cye.h" 3 4
                  0
# 1182 "./cye.h"
                       ;
        }

        if (
# 1185 "./cye.h" 3 4
           (((
# 1185 "./cye.h"
           wstatus
# 1185 "./cye.h" 3 4
           ) & 0x7f) == 0)
# 1185 "./cye.h"
                             ) {
            int exit_status = 
# 1186 "./cye.h" 3 4
                             (((
# 1186 "./cye.h"
                             wstatus
# 1186 "./cye.h" 3 4
                             ) & 0xff00) >> 8)
# 1186 "./cye.h"
                                                 ;
            if (exit_status != 0) {
                cye_trace_log(CYE_TRACE_ERROR, "Command exited with exit code %d", exit_status);
                return 
# 1189 "./cye.h" 3 4
                      0
# 1189 "./cye.h"
                           ;
            }
            break;
        }

        if (
# 1194 "./cye.h" 3 4
           (((signed char) (((
# 1194 "./cye.h"
           wstatus
# 1194 "./cye.h" 3 4
           ) & 0x7f) + 1) >> 1) > 0)
# 1194 "./cye.h"
                               ) {
            cye_trace_log(CYE_TRACE_ERROR, "Command process was terminated by %s", strsignal(
# 1195 "./cye.h" 3 4
                                                                                            ((
# 1195 "./cye.h"
                                                                                            wstatus
# 1195 "./cye.h" 3 4
                                                                                            ) & 0x7f)
# 1195 "./cye.h"
                                                                                                             ));
            return 
# 1196 "./cye.h" 3 4
                  0
# 1196 "./cye.h"
                       ;
        }
    }
    return 
# 1199 "./cye.h" 3 4
          1
# 1199 "./cye.h"
              ;
# 1226 "./cye.h"
}




void cye_ds_write_cmd(Cye_DString *ds, Cye_Command cmd) {
    for (usz i = 0; i < cmd.count; ++i) {
        const char *arg = cmd.items[i];
        if (arg == 
# 1234 "./cye.h" 3 4
                  ((void *)0)
# 1234 "./cye.h"
                      ) break;
        if (i > 0) do { const char *s = (" "); usz n = strlen(s); do { if ((ds)->count + (n) > (ds)->capacity) { if ((ds)->capacity == 0) { (ds)->capacity = 256; } while ((ds)->count + (n) > (ds)->capacity) { (ds)->capacity *= 2; } (ds)->items = cye_context.realloc((ds)->items, (ds)->capacity*sizeof(*(ds)->items)); ((void)(((ds)->items != 
# 1235 "./cye.h" 3 4
                  ((void *)0) 
# 1235 "./cye.h"
                  && "Dynamic Array: OOM") || (cye__assert_handler("Assertion Failure", "(ds)->items != ((void *)0) && \"Dynamic Array: OOM\"", "./cye.h", (int)1235, 
# 1235 "./cye.h" 3 4
                  ((void *)0)
# 1235 "./cye.h"
                  ), __builtin_trap(), 0))); } memcpy((ds)->items + (ds)->count, (s), (n)*sizeof(*(ds)->items)); (ds)->count += (n); } while (0); } while (0);
        if (!strchr(arg, ' ')) {
            do { const char *s = (arg); usz n = strlen(s); do { if ((ds)->count + (n) > (ds)->capacity) { if ((ds)->capacity == 0) { (ds)->capacity = 256; } while ((ds)->count + (n) > (ds)->capacity) { (ds)->capacity *= 2; } (ds)->items = cye_context.realloc((ds)->items, (ds)->capacity*sizeof(*(ds)->items)); ((void)(((ds)->items != 
# 1237 "./cye.h" 3 4
           ((void *)0) 
# 1237 "./cye.h"
           && "Dynamic Array: OOM") || (cye__assert_handler("Assertion Failure", "(ds)->items != ((void *)0) && \"Dynamic Array: OOM\"", "./cye.h", (int)1237, 
# 1237 "./cye.h" 3 4
           ((void *)0)
# 1237 "./cye.h"
           ), __builtin_trap(), 0))); } memcpy((ds)->items + (ds)->count, (s), (n)*sizeof(*(ds)->items)); (ds)->count += (n); } while (0); } while (0);
        } else {
            do { if ((ds)->count >= (ds)->capacity) { (ds)->capacity = (ds)->capacity == 0 ? 256 : (ds)->capacity*2; (ds)->items = cye_context.realloc( (ds)->items, (ds)->capacity*sizeof(((ds)->items)[0]) ); ((void)(((ds)->items != 
# 1239 "./cye.h" 3 4
           ((void *)0) 
# 1239 "./cye.h"
           && "Dynamic Array: OOM") || (cye__assert_handler("Assertion Failure", "(ds)->items != ((void *)0) && \"Dynamic Array: OOM\"", "./cye.h", (int)1239, 
# 1239 "./cye.h" 3 4
           ((void *)0)
# 1239 "./cye.h"
           ), __builtin_trap(), 0))); } (ds)->items[(ds)->count++] = ('\''); } while (0);
            do { const char *s = (arg); usz n = strlen(s); do { if ((ds)->count + (n) > (ds)->capacity) { if ((ds)->capacity == 0) { (ds)->capacity = 256; } while ((ds)->count + (n) > (ds)->capacity) { (ds)->capacity *= 2; } (ds)->items = cye_context.realloc((ds)->items, (ds)->capacity*sizeof(*(ds)->items)); ((void)(((ds)->items != 
# 1240 "./cye.h" 3 4
           ((void *)0) 
# 1240 "./cye.h"
           && "Dynamic Array: OOM") || (cye__assert_handler("Assertion Failure", "(ds)->items != ((void *)0) && \"Dynamic Array: OOM\"", "./cye.h", (int)1240, 
# 1240 "./cye.h" 3 4
           ((void *)0)
# 1240 "./cye.h"
           ), __builtin_trap(), 0))); } memcpy((ds)->items + (ds)->count, (s), (n)*sizeof(*(ds)->items)); (ds)->count += (n); } while (0); } while (0);
            do { if ((ds)->count >= (ds)->capacity) { (ds)->capacity = (ds)->capacity == 0 ? 256 : (ds)->capacity*2; (ds)->items = cye_context.realloc( (ds)->items, (ds)->capacity*sizeof(((ds)->items)[0]) ); ((void)(((ds)->items != 
# 1241 "./cye.h" 3 4
           ((void *)0) 
# 1241 "./cye.h"
           && "Dynamic Array: OOM") || (cye__assert_handler("Assertion Failure", "(ds)->items != ((void *)0) && \"Dynamic Array: OOM\"", "./cye.h", (int)1241, 
# 1241 "./cye.h" 3 4
           ((void *)0)
# 1241 "./cye.h"
           ), __builtin_trap(), 0))); } (ds)->items[(ds)->count++] = ('\''); } while (0);
        }
    }
}


Cye_Process cye_cmd_run_async_and_reset(Cye_Command *cmd) {
    Cye_Process proc = cye_cmd_run_async_redirect(*cmd, (Cye_Command_Redirect) {0});
    cmd->count = 0;
    return proc;
}



Cye_Process cye_cmd_run_async_redirect(Cye_Command cmd, Cye_Command_Redirect redirect) {
    if (cmd.count < 1) {
        cye_trace_log(CYE_TRACE_ERROR, "Could not run empty command");
        return (-1);
    }

    Cye_DString sb = {0};
    cye_ds_write_cmd(&sb, cmd);
    do { if ((&sb)->count >= (&sb)->capacity) { (&sb)->capacity = (&sb)->capacity == 0 ? 256 : (&sb)->capacity*2; (&sb)->items = cye_context.realloc( (&sb)->items, (&sb)->capacity*sizeof(((&sb)->items)[0]) ); ((void)(((&sb)->items != 
# 1263 "./cye.h" 3 4
   ((void *)0) 
# 1263 "./cye.h"
   && "Dynamic Array: OOM") || (cye__assert_handler("Assertion Failure", "(&sb)->items != ((void *)0) && \"Dynamic Array: OOM\"", "./cye.h", (int)1263, 
# 1263 "./cye.h" 3 4
   ((void *)0)
# 1263 "./cye.h"
   ), __builtin_trap(), 0))); } (&sb)->items[(&sb)->count++] = ('\0'); } while (0);
    cye_trace_log(CYE_LOG_INFO, "CMD: %s", sb.items);
    cye_context.free((sb).items);
    memset(&sb, 0, sizeof(sb));


    pid_t cpid = fork();
    if (cpid < 0) {
        cye_trace_log(CYE_TRACE_ERROR, "Could not fork child process: %s", (strerror(
# 1271 "./cye.h" 3 4
       (*__errno_location ())
# 1271 "./cye.h"
       )));
        return (-1);
    }

    if (cpid == 0) {
        if (redirect.in) {
            if (dup2(*redirect.in, 
# 1277 "./cye.h" 3 4
                                  0
# 1277 "./cye.h"
                                              ) < 0) {
                cye_trace_log(CYE_TRACE_ERROR, "Could not setup stdin for child process: %s", (strerror(
# 1278 "./cye.h" 3 4
               (*__errno_location ())
# 1278 "./cye.h"
               )));
                exit(1);
            }
        }

        if (redirect.out) {
            if (dup2(*redirect.out, 
# 1284 "./cye.h" 3 4
                                   1
# 1284 "./cye.h"
                                                ) < 0) {
                cye_trace_log(CYE_TRACE_ERROR, "Could not setup stdout for child process: %s", (strerror(
# 1285 "./cye.h" 3 4
               (*__errno_location ())
# 1285 "./cye.h"
               )));
                exit(1);
            }
        }

        if (redirect.err) {
            if (dup2(*redirect.err, 
# 1291 "./cye.h" 3 4
                                   2
# 1291 "./cye.h"
                                                ) < 0) {
                cye_trace_log(CYE_TRACE_ERROR, "Could not setup stderr for child process: %s", (strerror(
# 1292 "./cye.h" 3 4
               (*__errno_location ())
# 1292 "./cye.h"
               )));
                exit(1);
            }
        }



        Cye_Command cmd_null = {0};
        do { if ((&cmd_null)->count + (cmd.count) > (&cmd_null)->capacity) { if ((&cmd_null)->capacity == 0) { (&cmd_null)->capacity = 256; } while ((&cmd_null)->count + (cmd.count) > (&cmd_null)->capacity) { (&cmd_null)->capacity *= 2; } (&cmd_null)->items = cye_context.realloc((&cmd_null)->items, (&cmd_null)->capacity*sizeof(*(&cmd_null)->items)); ((void)(((&cmd_null)->items != 
# 1300 "./cye.h" 3 4
       ((void *)0) 
# 1300 "./cye.h"
       && "Dynamic Array: OOM") || (cye__assert_handler("Assertion Failure", "(&cmd_null)->items != ((void *)0) && \"Dynamic Array: OOM\"", "./cye.h", (int)1300, 
# 1300 "./cye.h" 3 4
       ((void *)0)
# 1300 "./cye.h"
       ), __builtin_trap(), 0))); } memcpy((&cmd_null)->items + (&cmd_null)->count, (cmd.items), (cmd.count)*sizeof(*(&cmd_null)->items)); (&cmd_null)->count += (cmd.count); } while (0);
        do { if ((&cmd_null)->count + ((sizeof((const char *[]){
# 1301 "./cye.h" 3 4
       ((void *)0)
# 1301 "./cye.h"
       }) / sizeof(const char *))) > (&cmd_null)->capacity) { if ((&cmd_null)->capacity == 0) { (&cmd_null)->capacity = 256; } while ((&cmd_null)->count + ((sizeof((const char *[]){
# 1301 "./cye.h" 3 4
       ((void *)0)
# 1301 "./cye.h"
       }) / sizeof(const char *))) > (&cmd_null)->capacity) { (&cmd_null)->capacity *= 2; } (&cmd_null)->items = cye_context.realloc((&cmd_null)->items, (&cmd_null)->capacity*sizeof(*(&cmd_null)->items)); ((void)(((&cmd_null)->items != 
# 1301 "./cye.h" 3 4
       ((void *)0) 
# 1301 "./cye.h"
       && "Dynamic Array: OOM") || (cye__assert_handler("Assertion Failure", "(&cmd_null)->items != ((void *)0) && \"Dynamic Array: OOM\"", "./cye.h", (int)1301, 
# 1301 "./cye.h" 3 4
       ((void *)0)
# 1301 "./cye.h"
       ), __builtin_trap(), 0))); } memcpy((&cmd_null)->items + (&cmd_null)->count, (((const char *[]){
# 1301 "./cye.h" 3 4
       ((void *)0)
# 1301 "./cye.h"
       })), ((sizeof((const char *[]){
# 1301 "./cye.h" 3 4
       ((void *)0)
# 1301 "./cye.h"
       }) / sizeof(const char *)))*sizeof(*(&cmd_null)->items)); (&cmd_null)->count += ((sizeof((const char *[]){
# 1301 "./cye.h" 3 4
       ((void *)0)
# 1301 "./cye.h"
       }) / sizeof(const char *))); } while (0);

        if (execvp(cmd.items[0], (char * const*) cmd_null.items) < 0) {
            cye_trace_log(CYE_TRACE_ERROR, "Could not exec child process: %s", (strerror(
# 1304 "./cye.h" 3 4
           (*__errno_location ())
# 1304 "./cye.h"
           )));
            exit(1);
        }
        do { fprintf(
# 1307 "./cye.h" 3 4
       stderr
# 1307 "./cye.h"
       , "%s:%d: %s UNREACHABLE: %s\n","./cye.h", 1307,__PRETTY_FUNCTION__, "nob_cmd_run_async_redirect"); abort(); } while(0);
    }

    return cpid;
# 1344 "./cye.h"
}


Cye_Process cye_cmd_run_async_redirect_and_reset(Cye_Command *cmd, Cye_Command_Redirect redirect) {
    Cye_Process proc = cye_cmd_run_async_redirect(*cmd, redirect);
    cmd->count = 0;
    if (redirect.in) {
        cye_file_close(*redirect.in);
        *redirect.in = (-1);
    }
    if (redirect.out) {
        cye_file_close(*redirect.out);
        *redirect.out = (-1);
    }
    if (redirect.err) {
        cye_file_close(*redirect.err);
        *redirect.err = (-1);
    }
    return proc;
}



# 1366 "./cye.h" 3 4
_Bool 
# 1366 "./cye.h"
    cye_cmd_run_sync(Cye_Command cmd) {
    Cye_Process proc = cye_cmd_run_async_redirect(cmd, (Cye_Command_Redirect) {0});
    if (proc == (-1)) {
        return 
# 1369 "./cye.h" 3 4
              0
# 1369 "./cye.h"
                   ;
    }
    return cye_process_wait(proc);
}


# 1374 "./cye.h" 3 4
_Bool 
# 1374 "./cye.h"
    cye_cmd_run_sync_and_reset(Cye_Command *cmd) {
    
# 1375 "./cye.h" 3 4
   _Bool 
# 1375 "./cye.h"
        ok = cye_cmd_run_sync(*cmd);
    cmd->count = 0;
    return ok;
}



# 1381 "./cye.h" 3 4
_Bool 
# 1381 "./cye.h"
    cye_cmd_run_sync_redirect(Cye_Command cmd, Cye_Command_Redirect redirect);



# 1384 "./cye.h" 3 4
_Bool 
# 1384 "./cye.h"
    cye_cmd_run_sync_redirect_and_reset(Cye_Command *cmd, Cye_Command_Redirect redirect);



void cye__rebuild_ourselves(ZString source_path, int argc, ZString *argv) {
    const char *binary_path = (((void)((((argc) > 0)) || (cye__assert_handler("Assertion Failure", "((argc) > 0)", "./cye.h", (int)1389, "%s", "Shift WAY TOO MUCH"), __builtin_trap(), 0))), (argc) -= 1, *(argv)++);
# 1398 "./cye.h"
    int rebuild_is_needed = cye_needs_rebuild_from_buf( binary_path, ((const char *[]){source_path, "./cye.h"}), (sizeof((const char *[]){source_path, "./cye.h"}) / sizeof(const char *)));
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

    do { if ((&cmd)->count + ((sizeof((const char *[]){"cc", "-o", binary_path, source_path}) / sizeof(const char *))) > (&cmd)->capacity) { if ((&cmd)->capacity == 0) { (&cmd)->capacity = 256; } while ((&cmd)->count + ((sizeof((const char *[]){"cc", "-o", binary_path, source_path}) / sizeof(const char *))) > (&cmd)->capacity) { (&cmd)->capacity *= 2; } (&cmd)->items = cye_context.realloc((&cmd)->items, (&cmd)->capacity*sizeof(*(&cmd)->items)); ((void)(((&cmd)->items != 
# 1414 "./cye.h" 3 4
   ((void *)0) 
# 1414 "./cye.h"
   && "Dynamic Array: OOM") || (cye__assert_handler("Assertion Failure", "(&cmd)->items != ((void *)0) && \"Dynamic Array: OOM\"", "./cye.h", (int)1414, 
# 1414 "./cye.h" 3 4
   ((void *)0)
# 1414 "./cye.h"
   ), __builtin_trap(), 0))); } memcpy((&cmd)->items + (&cmd)->count, (((const char *[]){"cc", "-o", binary_path, source_path})), ((sizeof((const char *[]){"cc", "-o", binary_path, source_path}) / sizeof(const char *)))*sizeof(*(&cmd)->items)); (&cmd)->count += ((sizeof((const char *[]){"cc", "-o", binary_path, source_path}) / sizeof(const char *))); } while (0);
    if (!cye_cmd_run_sync_and_reset(&cmd)) {
        cye_path_rename(old_binary_path, binary_path);
        exit(1);
    }

    do { if ((&cmd)->count + ((sizeof((const char *[]){binary_path}) / sizeof(const char *))) > (&cmd)->capacity) { if ((&cmd)->capacity == 0) { (&cmd)->capacity = 256; } while ((&cmd)->count + ((sizeof((const char *[]){binary_path}) / sizeof(const char *))) > (&cmd)->capacity) { (&cmd)->capacity *= 2; } (&cmd)->items = cye_context.realloc((&cmd)->items, (&cmd)->capacity*sizeof(*(&cmd)->items)); ((void)(((&cmd)->items != 
# 1420 "./cye.h" 3 4
   ((void *)0) 
# 1420 "./cye.h"
   && "Dynamic Array: OOM") || (cye__assert_handler("Assertion Failure", "(&cmd)->items != ((void *)0) && \"Dynamic Array: OOM\"", "./cye.h", (int)1420, 
# 1420 "./cye.h" 3 4
   ((void *)0)
# 1420 "./cye.h"
   ), __builtin_trap(), 0))); } memcpy((&cmd)->items + (&cmd)->count, (((const char *[]){binary_path})), ((sizeof((const char *[]){binary_path}) / sizeof(const char *)))*sizeof(*(&cmd)->items)); (&cmd)->count += ((sizeof((const char *[]){binary_path}) / sizeof(const char *))); } while (0);
    do { if ((&cmd)->count + (argc) > (&cmd)->capacity) { if ((&cmd)->capacity == 0) { (&cmd)->capacity = 256; } while ((&cmd)->count + (argc) > (&cmd)->capacity) { (&cmd)->capacity *= 2; } (&cmd)->items = cye_context.realloc((&cmd)->items, (&cmd)->capacity*sizeof(*(&cmd)->items)); ((void)(((&cmd)->items != 
# 1421 "./cye.h" 3 4
   ((void *)0) 
# 1421 "./cye.h"
   && "Dynamic Array: OOM") || (cye__assert_handler("Assertion Failure", "(&cmd)->items != ((void *)0) && \"Dynamic Array: OOM\"", "./cye.h", (int)1421, 
# 1421 "./cye.h" 3 4
   ((void *)0)
# 1421 "./cye.h"
   ), __builtin_trap(), 0))); } memcpy((&cmd)->items + (&cmd)->count, (argv), (argc)*sizeof(*(&cmd)->items)); (&cmd)->count += (argc); } while (0);
    if (!cye_cmd_run_sync_and_reset(&cmd)) {
        exit(1);
    }

    exit(0);
}







Cye_Context cye_temp_context(void) {

    return (Cye_Context){.alloc = cye_talloc, .realloc = cye_trealloc, .free = cye_tfree, cye_context.any};
}

Cye_Context cye_default_context(void) {
    return (Cye_Context){.alloc = malloc, .realloc = realloc, .free = free, .any=((void *)0)};
}

u0 cye_set_default_context(Cye_Context ctx) {
    ((void)(ctx));
    do { fprintf(
# 1446 "./cye.h" 3 4
   stderr
# 1446 "./cye.h"
   , "%s:%d: %s PANIC: " "YAY" "\n","./cye.h", 1446,__PRETTY_FUNCTION__); abort(); } while(0);
}

TString cye_tstrdup(const char *cstr) {
    usz n = strlen(cstr);
    TString result = (TString)cye_talloc(n + 1);
    ((void)((result != 
# 1452 "./cye.h" 3 4
   ((void *)0) 
# 1452 "./cye.h"
   && "Please increase CYE_TEMP_CAPACITY") || (cye__assert_handler("Assertion Failure", "result != ((void *)0) && \"Please increase CYE_TEMP_CAPACITY\"", "./cye.h", (int)1452, 
# 1452 "./cye.h" 3 4
   ((void *)0)
# 1452 "./cye.h"
   ), __builtin_trap(), 0)));
    memcpy(result, cstr, n);
    result[n] = '\0';
    return result;
}



rawptr cye_talloc(usz size) {

    if (cye_temp_data.size + size > (((16) * (i64)(1024)) * (i64)(1024))) return 
# 1462 "./cye.h" 3 4
                                                             ((void *)0)
# 1462 "./cye.h"
                                                                 ;
    rawptr result = &cye_temp_data.buffer[cye_temp_data.size];
    cye_temp_data.last = result;
    cye_temp_data.size += size;
    return result;
}

void *cye_trealloc(void *ptr, usz size) {
    if (ptr == ((void *)0)) {

        return cye_talloc(size);
    }

    if (size == 0) {
        return ((void *)0);
    }

    if ((byte*)ptr < cye_temp_data.buffer
     || (byte*)ptr >= (cye_temp_data.buffer + (((16) * (i64)(1024)) * (i64)(1024))))
    {
        cye_trace_log(CYE_LOG_FATAL, "Trying to realloc investigate this behaviour" "You might have allocate with one context than changed the context and reallocated with something else" "This might indicate that you need to either note realloc instead to the memcpy your self since you probably already" "know how much data the pointer points to. (temporary allocator does not)")




         ;
        do { fprintf(
# 1488 "./cye.h" 3 4
       stderr
# 1488 "./cye.h"
       , "%s:%d: %s UNREACHABLE: %s\n","./cye.h", 1488,__PRETTY_FUNCTION__, "FATAL"); abort(); } while(0);


        return cye_talloc(size);;
    }



    if (ptr == cye_temp_data.last) {
        cye_trace_log(CYE_LOG_TRACE, "Reallocation done on pointer from last allocation");

        if ((byte*)ptr + size > cye_temp_data.buffer + (((16) * (i64)(1024)) * (i64)(1024))) {
            cye_trace_log(CYE_LOG_WARNING, "Reallocation returns exceeds CYE_TEMP_CAPACITY=%zu", (((16) * (i64)(1024)) * (i64)(1024)));
            return 
# 1501 "./cye.h" 3 4
                  ((void *)0)
# 1501 "./cye.h"
                      ;
        }


        cye_temp_data.size = ((byte*)ptr - cye_temp_data.buffer) + size;
        return ptr;
    }


    void *new_ptr = cye_talloc(size);
    cye_trace_log(CYE_LOG_TRACE, "Reallocation done from different pointer from last allocation. (pointer=%p != last_pointer=%p)(new_ptr=%p)", ptr, cye_temp_data.last, new_ptr);
    if (new_ptr) {


        usz remaining_space = cye_temp_data.buffer + (((16) * (i64)(1024)) * (i64)(1024)) - (byte*)ptr;
        usz copy_size = size;
        if (size > remaining_space) {
            copy_size = remaining_space;
            cye_trace_log(CYE_LOG_WARNING, "Wanted %zu bytes but can only give %zu to not exceed %d CYE_TEMP_CAPACITY", size, remaining_space, (((16) * (i64)(1024)) * (i64)(1024)));
        }
        memcpy(new_ptr, ptr, copy_size);
    }

    return new_ptr;
}

void cye_tfree(rawptr ptr) {
    cye_trace_log(CYE_LOG_TRACE, "Temporary allocator freed");
}


TString cye_tprintf(ZString fmt, ...) {
    va_list args;
    
# 1534 "./cye.h" 3 4
   __builtin_va_start(
# 1534 "./cye.h"
   args
# 1534 "./cye.h" 3 4
   ,
# 1534 "./cye.h"
   fmt
# 1534 "./cye.h" 3 4
   )
# 1534 "./cye.h"
                      ;
    int n = vsnprintf(
# 1535 "./cye.h" 3 4
                     ((void *)0)
# 1535 "./cye.h"
                         , 0, fmt, args);
    
# 1536 "./cye.h" 3 4
   __builtin_va_end(
# 1536 "./cye.h"
   args
# 1536 "./cye.h" 3 4
   )
# 1536 "./cye.h"
               ;


    ((void)((n >= 0) || (cye__assert_handler("Assertion Failure", "n >= 0", "./cye.h", (int)1539, 
# 1539 "./cye.h" 3 4
   ((void *)0)
# 1539 "./cye.h"
   ), __builtin_trap(), 0)));
    char *result = cye_talloc(n + 1);

    ((void)((result != 
# 1542 "./cye.h" 3 4
   ((void *)0) 
# 1542 "./cye.h"
   && "Extend the size of the temporary allocator") || (cye__assert_handler("Assertion Failure", "result != ((void *)0) && \"Extend the size of the temporary allocator\"", "./cye.h", (int)1542, 
# 1542 "./cye.h" 3 4
   ((void *)0)
# 1542 "./cye.h"
   ), __builtin_trap(), 0)));


    
# 1545 "./cye.h" 3 4
   __builtin_va_start(
# 1545 "./cye.h"
   args
# 1545 "./cye.h" 3 4
   ,
# 1545 "./cye.h"
   fmt
# 1545 "./cye.h" 3 4
   )
# 1545 "./cye.h"
                      ;
    vsnprintf(result, n + 1, fmt, args);
    
# 1547 "./cye.h" 3 4
   __builtin_va_end(
# 1547 "./cye.h"
   args
# 1547 "./cye.h" 3 4
   )
# 1547 "./cye.h"
               ;

    return result;
}

void cye_temp_reset(void) {
    cye_temp_data.size = 0;
}

usz cye_temp_save(void) {
    return cye_temp_data.size;
}

void cye_temp_rewind(usz checkpoint) {
    cye_temp_data.size = checkpoint;
}







# 1569 "./cye.h" 3 4
_Bool 
# 1569 "./cye.h"
    cye_make_dir_if_not_exists(const char *path) {



    int result = mkdir(path, 0755);

    if (result < 0) {
        if (
# 1576 "./cye.h" 3 4
           (*__errno_location ()) 
# 1576 "./cye.h"
                 == 
# 1576 "./cye.h" 3 4
                    17
# 1576 "./cye.h"
                          ) {
            cye_trace_log(CYE_LOG_INFO, "directory `%s` already exists", path);
            return 
# 1578 "./cye.h" 3 4
                  1
# 1578 "./cye.h"
                      ;
        }
        cye_trace_log(CYE_TRACE_ERROR, "could not create directory `%s`: %s", path, (strerror(
# 1580 "./cye.h" 3 4
       (*__errno_location ())
# 1580 "./cye.h"
       )));
        return 
# 1581 "./cye.h" 3 4
              0
# 1581 "./cye.h"
                   ;
    }

    cye_trace_log(CYE_LOG_INFO, "created directory `%s`", path);
    return 
# 1585 "./cye.h" 3 4
          1
# 1585 "./cye.h"
              ;
}


# 1588 "./cye.h" 3 4
_Bool 
# 1588 "./cye.h"
    cye_copy_file(const char *src_path, const char *dst_path) {
    cye_trace_log(CYE_LOG_INFO, "Copying %s -> %s", src_path, dst_path);

    int src_fd = -1;
    int dst_fd = -1;
    size_t buf_size = 32*1024;
    char *buf = cye_context.realloc(
# 1594 "./cye.h" 3 4
                                   ((void *)0)
# 1594 "./cye.h"
                                       , buf_size);
    ((void)((buf != 
# 1595 "./cye.h" 3 4
   ((void *)0) 
# 1595 "./cye.h"
   && "RAM not enough") || (cye__assert_handler("Assertion Failure", "buf != ((void *)0) && \"RAM not enough\"", "./cye.h", (int)1595, 
# 1595 "./cye.h" 3 4
   ((void *)0)
# 1595 "./cye.h"
   ), __builtin_trap(), 0)));
    
# 1596 "./cye.h" 3 4
   _Bool 
# 1596 "./cye.h"
        result = 
# 1596 "./cye.h" 3 4
                 1
# 1596 "./cye.h"
                     ;

    src_fd = open(src_path, 
# 1598 "./cye.h" 3 4
                           00
# 1598 "./cye.h"
                                   );
    if (src_fd < 0) {
        cye_trace_log(CYE_TRACE_ERROR, "Could not open file %s: %s", src_path, strerror(
# 1600 "./cye.h" 3 4
       (*__errno_location ())
# 1600 "./cye.h"
       ));
        do { result = (
# 1601 "./cye.h" 3 4
       0
# 1601 "./cye.h"
       ); goto defer; } while(0);
    }

    struct stat src_stat;
    if (fstat(src_fd, &src_stat) < 0) {
        cye_trace_log(CYE_TRACE_ERROR, "Could not get mode of file %s: %s", src_path, strerror(
# 1606 "./cye.h" 3 4
       (*__errno_location ())
# 1606 "./cye.h"
       ));
        do { result = (
# 1607 "./cye.h" 3 4
       0
# 1607 "./cye.h"
       ); goto defer; } while(0);
    }

    dst_fd = open(dst_path, 
# 1610 "./cye.h" 3 4
                           0100 
# 1610 "./cye.h"
                                   | 
# 1610 "./cye.h" 3 4
                                     01000 
# 1610 "./cye.h"
                                             | 
# 1610 "./cye.h" 3 4
                                               01
# 1610 "./cye.h"
                                                       , src_stat.st_mode);
    if (dst_fd < 0) {
        cye_trace_log(CYE_TRACE_ERROR, "Could not create file %s: %s", dst_path, strerror(
# 1612 "./cye.h" 3 4
       (*__errno_location ())
# 1612 "./cye.h"
       ));
        do { result = (
# 1613 "./cye.h" 3 4
       0
# 1613 "./cye.h"
       ); goto defer; } while(0);
    }

    for (;;) {
        isz n = read(src_fd, buf, buf_size);
        if (n == 0) break;
        if (n < 0) {
            cye_trace_log(CYE_TRACE_ERROR, "Could not read from file %s: %s", src_path, strerror(
# 1620 "./cye.h" 3 4
           (*__errno_location ())
# 1620 "./cye.h"
           ));
            do { result = (
# 1621 "./cye.h" 3 4
           0
# 1621 "./cye.h"
           ); goto defer; } while(0);
        }
        char *buf2 = buf;
        while (n > 0) {
            isz m = write(dst_fd, buf2, n);
            if (m < 0) {
                cye_trace_log(CYE_TRACE_ERROR, "Could not write to file %s: %s", dst_path, strerror(
# 1627 "./cye.h" 3 4
               (*__errno_location ())
# 1627 "./cye.h"
               ));
                do { result = (
# 1628 "./cye.h" 3 4
               0
# 1628 "./cye.h"
               ); goto defer; } while(0);
            }
            n -= m;
            buf2 += m;
        }
    }

defer:
    free(buf);
    close(src_fd);
    close(dst_fd);
    return result;
# 1648 "./cye.h"
}



# 1651 "./cye.h" 3 4
_Bool 
# 1651 "./cye.h"
    cye_copy_dir(const char *src_path, const char *dst_path) {
    static int depth = 0;

    depth += 1;

    
# 1656 "./cye.h" 3 4
   _Bool 
# 1656 "./cye.h"
        result = 
# 1656 "./cye.h" 3 4
                 1
# 1656 "./cye.h"
                     ;
    Cye_Path_DArray children = {0};
    Cye_DString src_ds = {0};
    Cye_DString dst_ds = {0};
    usz temp_checkpoint = cye_temp_save();

    Cye_File_Type type = cye_path_file_type(src_path);
    if (type < 0) {
        depth -= 1;
        return 
# 1665 "./cye.h" 3 4
              0
# 1665 "./cye.h"
                   ;
    }

    switch (type) {
        case CYE_FILE_TYPE_DIRECTORY: {
            if (!cye_make_dir_include_parents(dst_path)) do { result = (
# 1670 "./cye.h" 3 4
                                         0
# 1670 "./cye.h"
                                         ); goto defer; } while(0);
            if (!cye_read_entire_dir(src_path, &children)) do { result = (
# 1671 "./cye.h" 3 4
                                                          0
# 1671 "./cye.h"
                                                          ); goto defer; } while(0);

            for (usz i = 0; i < children.count; ++i) {
                if (strcmp(children.items[i], ".") == 0) continue;
                if (strcmp(children.items[i], "..") == 0) continue;

                src_ds.count = 0;
                do { const char *cye_tmp_strs[] = {src_path, "/", children.items[i]}; for (usz idx = 0; idx < sizeof(cye_tmp_strs) / sizeof(cye_tmp_strs[0]); idx++) { const char *s = cye_tmp_strs[idx]; usz n = strlen(s); do { if ((&src_ds)->count + (n) > (&src_ds)->capacity) { if ((&src_ds)->capacity == 0) { (&src_ds)->capacity = 256; } while ((&src_ds)->count + (n) > (&src_ds)->capacity) { (&src_ds)->capacity *= 2; } (&src_ds)->items = cye_context.realloc((&src_ds)->items, (&src_ds)->capacity*sizeof(*(&src_ds)->items)); ((void)(((&src_ds)->items != 
# 1678 "./cye.h" 3 4
               ((void *)0) 
# 1678 "./cye.h"
               && "Dynamic Array: OOM") || (cye__assert_handler("Assertion Failure", "(&src_ds)->items != ((void *)0) && \"Dynamic Array: OOM\"", "./cye.h", (int)1678, 
# 1678 "./cye.h" 3 4
               ((void *)0)
# 1678 "./cye.h"
               ), __builtin_trap(), 0))); } memcpy((&src_ds)->items + (&src_ds)->count, (s), (n)*sizeof(*(&src_ds)->items)); (&src_ds)->count += (n); } while (0); } } while (0);
                do { if ((&src_ds)->count >= (&src_ds)->capacity) { (&src_ds)->capacity = (&src_ds)->capacity == 0 ? 256 : (&src_ds)->capacity*2; (&src_ds)->items = cye_context.realloc( (&src_ds)->items, (&src_ds)->capacity*sizeof(((&src_ds)->items)[0]) ); ((void)(((&src_ds)->items != 
# 1679 "./cye.h" 3 4
               ((void *)0) 
# 1679 "./cye.h"
               && "Dynamic Array: OOM") || (cye__assert_handler("Assertion Failure", "(&src_ds)->items != ((void *)0) && \"Dynamic Array: OOM\"", "./cye.h", (int)1679, 
# 1679 "./cye.h" 3 4
               ((void *)0)
# 1679 "./cye.h"
               ), __builtin_trap(), 0))); } (&src_ds)->items[(&src_ds)->count++] = ('\0'); } while (0);

                dst_ds.count = 0;
                do { const char *cye_tmp_strs[] = {dst_path, "/", children.items[i]}; for (usz idx = 0; idx < sizeof(cye_tmp_strs) / sizeof(cye_tmp_strs[0]); idx++) { const char *s = cye_tmp_strs[idx]; usz n = strlen(s); do { if ((&dst_ds)->count + (n) > (&dst_ds)->capacity) { if ((&dst_ds)->capacity == 0) { (&dst_ds)->capacity = 256; } while ((&dst_ds)->count + (n) > (&dst_ds)->capacity) { (&dst_ds)->capacity *= 2; } (&dst_ds)->items = cye_context.realloc((&dst_ds)->items, (&dst_ds)->capacity*sizeof(*(&dst_ds)->items)); ((void)(((&dst_ds)->items != 
# 1682 "./cye.h" 3 4
               ((void *)0) 
# 1682 "./cye.h"
               && "Dynamic Array: OOM") || (cye__assert_handler("Assertion Failure", "(&dst_ds)->items != ((void *)0) && \"Dynamic Array: OOM\"", "./cye.h", (int)1682, 
# 1682 "./cye.h" 3 4
               ((void *)0)
# 1682 "./cye.h"
               ), __builtin_trap(), 0))); } memcpy((&dst_ds)->items + (&dst_ds)->count, (s), (n)*sizeof(*(&dst_ds)->items)); (&dst_ds)->count += (n); } while (0); } } while (0);
                do { if ((&dst_ds)->count >= (&dst_ds)->capacity) { (&dst_ds)->capacity = (&dst_ds)->capacity == 0 ? 256 : (&dst_ds)->capacity*2; (&dst_ds)->items = cye_context.realloc( (&dst_ds)->items, (&dst_ds)->capacity*sizeof(((&dst_ds)->items)[0]) ); ((void)(((&dst_ds)->items != 
# 1683 "./cye.h" 3 4
               ((void *)0) 
# 1683 "./cye.h"
               && "Dynamic Array: OOM") || (cye__assert_handler("Assertion Failure", "(&dst_ds)->items != ((void *)0) && \"Dynamic Array: OOM\"", "./cye.h", (int)1683, 
# 1683 "./cye.h" 3 4
               ((void *)0)
# 1683 "./cye.h"
               ), __builtin_trap(), 0))); } (&dst_ds)->items[(&dst_ds)->count++] = ('\0'); } while (0);
                if (!cye_copy_dir(src_ds.items, dst_ds.items)) {
                    do { result = (
# 1685 "./cye.h" 3 4
                   0
# 1685 "./cye.h"
                   ); goto defer; } while(0);
                }
            }
        } break;

        case CYE_FILE_TYPE_REGULAR: {
            Cye_Log_Level old_level = cye_threshold_log_level;
            cye_set_trace_level(CYE_LOG_TRACE);
            
# 1693 "./cye.h" 3 4
           _Bool 
# 1693 "./cye.h"
                copy_result = cye_copy_file(src_path, dst_path);
            cye_set_trace_level(old_level);

            if (!copy_result) {
                cye_set_trace_level(old_level);
                do { result = (
# 1698 "./cye.h" 3 4
               0
# 1698 "./cye.h"
               ); goto defer; } while(0);
            }
        } break;

        case CYE_FILE_TYPE_SYMLINK: {
            cye_trace_log(CYE_LOG_WARNING, "TODO: Copying symlinks is not supported yet");
        } break;

        case CYE_FILE_TYPE_OTHER: {
            cye_trace_log(CYE_TRACE_ERROR, "Unsupported type of file %s", src_path);
            do { result = (
# 1708 "./cye.h" 3 4
           0
# 1708 "./cye.h"
           ); goto defer; } while(0);
        } break;

        default: do { fprintf(
# 1711 "./cye.h" 3 4
                stderr
# 1711 "./cye.h"
                , "%s:%d: %s UNREACHABLE: %s\n","./cye.h", 1711,__PRETTY_FUNCTION__, "nob_copy_directory_recursively"); abort(); } while(0);
    }

defer:
    cye_temp_rewind(temp_checkpoint);
    cye_context.free((src_ds).items);
    cye_context.free((dst_ds).items);
    cye_context.free((children).items);
    depth -= 1;

    cye_trace_log(CYE_LOG_TRACE, "%s, depth=%d", __FUNCTION__, depth);
    if (depth == 0) {
        if (result) {
            cye_trace_log(CYE_LOG_INFO, "Copied directory `%s` into `%s` successfully.", src_path, dst_path);
        } else {
            cye_trace_log(CYE_LOG_INFO, "Failed to copied directory `%s` into `%s`.", src_path, dst_path);
        }
    }
    return result;
}



# 1733 "./cye.h" 3 4
_Bool 
# 1733 "./cye.h"
    cye_read_entire_dir(const char *parent, Cye_Path_DArray *children) {
    ((void)((parent) || (cye__assert_handler("Assertion Failure", "parent", "./cye.h", (int)1734, 
# 1734 "./cye.h" 3 4
   ((void *)0)
# 1734 "./cye.h"
   ), __builtin_trap(), 0)));
    
# 1735 "./cye.h" 3 4
   _Bool 
# 1735 "./cye.h"
        result = 
# 1735 "./cye.h" 3 4
                 1
# 1735 "./cye.h"
                     ;


    DIR *dir = 
# 1738 "./cye.h" 3 4
              ((void *)0)
# 1738 "./cye.h"
                  ;

    dir = opendir(parent);
    if (dir == 
# 1741 "./cye.h" 3 4
              ((void *)0)
# 1741 "./cye.h"
                  ) {
        do { result = (
# 1742 "./cye.h" 3 4
       0
# 1742 "./cye.h"
       ); goto defer; } while(0);
        cye_trace_log(CYE_TRACE_ERROR, "Could not open directory %s: %s", parent, (strerror(
# 1743 "./cye.h" 3 4
       (*__errno_location ())
# 1743 "./cye.h"
       )));
    }

    
# 1746 "./cye.h" 3 4
   (*__errno_location ()) 
# 1746 "./cye.h"
         = 0;
    struct dirent *ent = readdir(dir);
    while (ent != 
# 1748 "./cye.h" 3 4
                 ((void *)0)
# 1748 "./cye.h"
                     ) {
        do { if ((children)->count >= (children)->capacity) { (children)->capacity = (children)->capacity == 0 ? 256 : (children)->capacity*2; (children)->items = cye_context.realloc( (children)->items, (children)->capacity*sizeof(((children)->items)[0]) ); ((void)(((children)->items != 
# 1749 "./cye.h" 3 4
       ((void *)0) 
# 1749 "./cye.h"
       && "Dynamic Array: OOM") || (cye__assert_handler("Assertion Failure", "(children)->items != ((void *)0) && \"Dynamic Array: OOM\"", "./cye.h", (int)1749, 
# 1749 "./cye.h" 3 4
       ((void *)0)
# 1749 "./cye.h"
       ), __builtin_trap(), 0))); } (children)->items[(children)->count++] = (cye_tstrdup(ent->d_name)); } while (0);
        ent = readdir(dir);
    }

    if (
# 1753 "./cye.h" 3 4
       (*__errno_location ()) 
# 1753 "./cye.h"
             != 0) {
        cye_trace_log(CYE_TRACE_ERROR, "Could not read directory %s: %s", parent, (strerror(
# 1754 "./cye.h" 3 4
       (*__errno_location ())
# 1754 "./cye.h"
       )));
        do { result = (
# 1755 "./cye.h" 3 4
       0
# 1755 "./cye.h"
       ); goto defer; } while(0);
    }

defer:
    if (dir) {
        closedir(dir);
    }
    return result;
# 1800 "./cye.h"
}




# 1804 "./cye.h" 3 4
_Bool 
# 1804 "./cye.h"
    cye_file_append(const char* path, const void* data, usz count) {
    
# 1805 "./cye.h" 3 4
   _Bool 
# 1805 "./cye.h"
        result = 
# 1805 "./cye.h" 3 4
                 1
# 1805 "./cye.h"
                     ;


    int fd = -1;
    isz bytes_written = 0;


    fd = open(path, 
# 1812 "./cye.h" 3 4
                   01 
# 1812 "./cye.h"
                            | 
# 1812 "./cye.h" 3 4
                              02000 
# 1812 "./cye.h"
                                       | 
# 1812 "./cye.h" 3 4
                                         0100
# 1812 "./cye.h"
                                                , 0644);
    if (fd == -1) {
        cye_trace_log(CYE_TRACE_ERROR, "Could not open file %s for append: %s", path, (strerror(
# 1814 "./cye.h" 3 4
       (*__errno_location ())
# 1814 "./cye.h"
       )));
        do { result = (
# 1815 "./cye.h" 3 4
       0
# 1815 "./cye.h"
       ); goto defer; } while(0);
    }


    bytes_written = write(fd, data, count);
    if (bytes_written == -1 || (usz)bytes_written != count) {
        cye_trace_log(CYE_TRACE_ERROR, "Could not write to file %s: %s", path, (strerror(
# 1821 "./cye.h" 3 4
       (*__errno_location ())
# 1821 "./cye.h"
       )));
        do { result = (
# 1822 "./cye.h" 3 4
       0
# 1822 "./cye.h"
       ); goto defer; } while(0);
    }
# 1859 "./cye.h"
defer:


    if (fd != -1) {
        close(fd);
    }






    return result;
}



# 1875 "./cye.h" 3 4
_Bool 
# 1875 "./cye.h"
    cye_file_append_zstr(const char* path, const char* str) {
    return cye_file_append(path, str, strlen(str));
}





# 1882 "./cye.h" 3 4
_Bool 
# 1882 "./cye.h"
    cye_file_write_all(const char *path, const void *data, usz size) {
    
# 1883 "./cye.h" 3 4
   _Bool 
# 1883 "./cye.h"
        result = 
# 1883 "./cye.h" 3 4
                 1
# 1883 "./cye.h"
                     ;

    FILE *f = fopen(path, "wb");
    if (f == 
# 1886 "./cye.h" 3 4
            ((void *)0)
# 1886 "./cye.h"
                ) {
        cye_trace_log(CYE_TRACE_ERROR, "Could not open file %s for writing: %s\n", path, strerror(
# 1887 "./cye.h" 3 4
       (*__errno_location ())
# 1887 "./cye.h"
       ));
        do { result = (
# 1888 "./cye.h" 3 4
       0
# 1888 "./cye.h"
       ); goto defer; } while(0);
    }







    const char *buf = data;
    while (size > 0) {
        size_t n = fwrite(buf, 1, size, f);
        if (ferror(f)) {
            cye_trace_log(CYE_TRACE_ERROR, "Could not write into file %s: %s\n", path, strerror(
# 1901 "./cye.h" 3 4
           (*__errno_location ())
# 1901 "./cye.h"
           ));
            do { result = (
# 1902 "./cye.h" 3 4
           0
# 1902 "./cye.h"
           ); goto defer; } while(0);
        }
        size -= n;
        buf += n;
    }

defer:
    if (f) fclose(f);
    return result;
}



# 1914 "./cye.h" 3 4
_Bool 
# 1914 "./cye.h"
    cye_file_read_all(const char *path, Cye_DString *ds) {
    
# 1915 "./cye.h" 3 4
   _Bool 
# 1915 "./cye.h"
        result = 
# 1915 "./cye.h" 3 4
                 1
# 1915 "./cye.h"
                     ;

    FILE *f = fopen(path, "rb");
    if (f == 
# 1918 "./cye.h" 3 4
            ((void *)0)
# 1918 "./cye.h"
                ) do { result = (
# 1918 "./cye.h" 3 4
                                  0
# 1918 "./cye.h"
                                  ); goto defer; } while(0);
    if (fseek(f, 0, 
# 1919 "./cye.h" 3 4
                   2
# 1919 "./cye.h"
                           ) < 0) do { result = (
# 1919 "./cye.h" 3 4
                                  0
# 1919 "./cye.h"
                                  ); goto defer; } while(0);
    long m = ftell(f);
    if (m < 0) do { result = (
# 1921 "./cye.h" 3 4
                                  0
# 1921 "./cye.h"
                                  ); goto defer; } while(0);
    if (fseek(f, 0, 
# 1922 "./cye.h" 3 4
                   0
# 1922 "./cye.h"
                           ) < 0) do { result = (
# 1922 "./cye.h" 3 4
                                  0
# 1922 "./cye.h"
                                  ); goto defer; } while(0);

    usz new_count = ds->count + m;
    if (new_count > ds->capacity) {
        ds->items = cye_context.realloc(ds->items, new_count);
        ((void)((ds->items != 
# 1927 "./cye.h" 3 4
       ((void *)0) 
# 1927 "./cye.h"
       && "Please, you'll need to acquire more random access memory ") || (cye__assert_handler("Assertion Failure", "ds->items != ((void *)0) && \"Please, you'll need to acquire more random access memory \"", "./cye.h", (int)1927, 
# 1927 "./cye.h" 3 4
       ((void *)0)
# 1927 "./cye.h"
       ), __builtin_trap(), 0)));
        ds->capacity = new_count;
    }

    fread(ds->items + ds->count, m, 1, f);

    int error_value = ferror(f);
    if (error_value != 0) {
        cye_trace_log(CYE_TRACE_ERROR, "Could not read file %s: ferror error value is %d", path, error_value);
        result = 
# 1936 "./cye.h" 3 4
                0
# 1936 "./cye.h"
                     ;
        goto close;
    }
    ds->count = new_count;

defer:
    if (!result) cye_trace_log(CYE_TRACE_ERROR, "Could not read file %s: %s", path, strerror(
# 1942 "./cye.h" 3 4
                (*__errno_location ())
# 1942 "./cye.h"
                ));
close:
    if (f) fclose(f);
    return result;
}

Cye_File_Type cye_path_file_type(const char *path) {

    struct stat statbuf;
    if (stat(path, &statbuf) < 0) {
        cye_trace_log(CYE_TRACE_ERROR, "Could not get stat of %s: %s", path, strerror(
# 1952 "./cye.h" 3 4
       (*__errno_location ())
# 1952 "./cye.h"
       ));
        return -1;
    }

    switch (statbuf.st_mode & 
# 1956 "./cye.h" 3 4
                             0170000
# 1956 "./cye.h"
                                   ) {
        case 
# 1957 "./cye.h" 3 4
            0040000
# 1957 "./cye.h"
                   : return CYE_FILE_TYPE_DIRECTORY;
        case 
# 1958 "./cye.h" 3 4
            0100000
# 1958 "./cye.h"
                   : return CYE_FILE_TYPE_REGULAR;
        case 
# 1959 "./cye.h" 3 4
            0120000
# 1959 "./cye.h"
                   : return CYE_FILE_TYPE_SYMLINK;
        default: return CYE_FILE_TYPE_OTHER;
    }
# 1973 "./cye.h"
}

char* cye_path_temp_normalize(ZString path) {

    usz path_count = strlen(path);
    usz total_count = path_count + 1 + 1;


    Cye_DString ds = {
        .items = cye_talloc(total_count),
        .count = 0,
        .capacity = total_count
    };


    for (usz idx = 0; idx < path_count; ++idx) {

        
# 1990 "./cye.h" 3 4
       _Bool 
# 1990 "./cye.h"
            is_next_end = (idx + 1) == (path_count);
        
# 1991 "./cye.h" 3 4
       _Bool 
# 1991 "./cye.h"
            is_prev_sep = ds.count > 0 && (ds.items[ds.count-1] == '/');
        
# 1992 "./cye.h" 3 4
       _Bool 
# 1992 "./cye.h"
            is_next_sep = ((idx + 1) < path_count) && (path[idx + 1] == '/');
        
# 1993 "./cye.h" 3 4
       _Bool 
# 1993 "./cye.h"
            is_curr_dot = path[idx] == '.';

        if (is_prev_sep && (is_next_end || is_next_sep) && is_curr_dot) {
            idx += 1;
            continue;
        }

        
# 2000 "./cye.h" 3 4
       _Bool 
# 2000 "./cye.h"
            is_curr_sep = path[idx] == '/';
        if (!(is_curr_sep && is_prev_sep)) {
            do { if ((&ds)->count >= (&ds)->capacity) { (&ds)->capacity = (&ds)->capacity == 0 ? 256 : (&ds)->capacity*2; (&ds)->items = cye_context.realloc( (&ds)->items, (&ds)->capacity*sizeof(((&ds)->items)[0]) ); ((void)(((&ds)->items != 
# 2002 "./cye.h" 3 4
           ((void *)0) 
# 2002 "./cye.h"
           && "Dynamic Array: OOM") || (cye__assert_handler("Assertion Failure", "(&ds)->items != ((void *)0) && \"Dynamic Array: OOM\"", "./cye.h", (int)2002, 
# 2002 "./cye.h" 3 4
           ((void *)0)
# 2002 "./cye.h"
           ), __builtin_trap(), 0))); } (&ds)->items[(&ds)->count++] = (path[idx]); } while (0);
        }
    }


    if (ds.count >= 2
        && ('.' == ds.items[ds.count-1])
        && ('.' == ds.items[ds.count-2]))
    {

        if (ds.count == 2 || '/' == ds.items[ds.count-3]) {
            do { const char *cye_tmp_strs[] = {"/"}; for (usz idx = 0; idx < sizeof(cye_tmp_strs) / sizeof(cye_tmp_strs[0]); idx++) { const char *s = cye_tmp_strs[idx]; usz n = strlen(s); do { if ((&ds)->count + (n) > (&ds)->capacity) { if ((&ds)->capacity == 0) { (&ds)->capacity = 256; } while ((&ds)->count + (n) > (&ds)->capacity) { (&ds)->capacity *= 2; } (&ds)->items = cye_context.realloc((&ds)->items, (&ds)->capacity*sizeof(*(&ds)->items)); ((void)(((&ds)->items != 
# 2013 "./cye.h" 3 4
           ((void *)0) 
# 2013 "./cye.h"
           && "Dynamic Array: OOM") || (cye__assert_handler("Assertion Failure", "(&ds)->items != ((void *)0) && \"Dynamic Array: OOM\"", "./cye.h", (int)2013, 
# 2013 "./cye.h" 3 4
           ((void *)0)
# 2013 "./cye.h"
           ), __builtin_trap(), 0))); } memcpy((&ds)->items + (&ds)->count, (s), (n)*sizeof(*(&ds)->items)); (&ds)->count += (n); } while (0); } } while (0);
        }
    } else if (ds.count == 1 && '.' == ds.items[ds.count-1]) {
        do { const char *cye_tmp_strs[] = {"/"}; for (usz idx = 0; idx < sizeof(cye_tmp_strs) / sizeof(cye_tmp_strs[0]); idx++) { const char *s = cye_tmp_strs[idx]; usz n = strlen(s); do { if ((&ds)->count + (n) > (&ds)->capacity) { if ((&ds)->capacity == 0) { (&ds)->capacity = 256; } while ((&ds)->count + (n) > (&ds)->capacity) { (&ds)->capacity *= 2; } (&ds)->items = cye_context.realloc((&ds)->items, (&ds)->capacity*sizeof(*(&ds)->items)); ((void)(((&ds)->items != 
# 2016 "./cye.h" 3 4
       ((void *)0) 
# 2016 "./cye.h"
       && "Dynamic Array: OOM") || (cye__assert_handler("Assertion Failure", "(&ds)->items != ((void *)0) && \"Dynamic Array: OOM\"", "./cye.h", (int)2016, 
# 2016 "./cye.h" 3 4
       ((void *)0)
# 2016 "./cye.h"
       ), __builtin_trap(), 0))); } memcpy((&ds)->items + (&ds)->count, (s), (n)*sizeof(*(&ds)->items)); (&ds)->count += (n); } while (0); } } while (0);
    }

    do { if ((&ds)->count >= (&ds)->capacity) { (&ds)->capacity = (&ds)->capacity == 0 ? 256 : (&ds)->capacity*2; (&ds)->items = cye_context.realloc( (&ds)->items, (&ds)->capacity*sizeof(((&ds)->items)[0]) ); ((void)(((&ds)->items != 
# 2019 "./cye.h" 3 4
   ((void *)0) 
# 2019 "./cye.h"
   && "Dynamic Array: OOM") || (cye__assert_handler("Assertion Failure", "(&ds)->items != ((void *)0) && \"Dynamic Array: OOM\"", "./cye.h", (int)2019, 
# 2019 "./cye.h" 3 4
   ((void *)0)
# 2019 "./cye.h"
   ), __builtin_trap(), 0))); } (&ds)->items[(&ds)->count++] = ('\0'); } while (0);


    if (ds.capacity > total_count) {
        cye_trace_log(CYE_TRACE_ERROR, "Allocating memory for the dynamic string is an error path=%s total_count=%zu ds=""{.items=%.*s(%p), .count=%zu, .capacity=%zu}"".\n" "All memory should have been talloc", path, total_count, (ds).count, (ds).items, (ds).items, (ds).count, (ds).capacity)





         ;
        do { fprintf(
# 2030 "./cye.h" 3 4
       stderr
# 2030 "./cye.h"
       , "%s:%d: %s PANIC: " "\n","./cye.h", 2030,__PRETTY_FUNCTION__); abort(); } while(0);
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


    Cye_DString ds = {
        .items = ctx.alloc(total_count + paths_count + 1),
        .count = 0,
        .capacity = total_count + paths_count + 1
    };


    for (usz i = 0; i < paths_count; i++) {
        do { const char *cye_tmp_strs[] = {paths[i]}; for (usz idx = 0; idx < sizeof(cye_tmp_strs) / sizeof(cye_tmp_strs[0]); idx++) { const char *s = cye_tmp_strs[idx]; usz n = strlen(s); do { if ((&ds)->count + (n) > (&ds)->capacity) { if ((&ds)->capacity == 0) { (&ds)->capacity = 256; } while ((&ds)->count + (n) > (&ds)->capacity) { (&ds)->capacity *= 2; } (&ds)->items = cye_context.realloc((&ds)->items, (&ds)->capacity*sizeof(*(&ds)->items)); ((void)(((&ds)->items != 
# 2063 "./cye.h" 3 4
       ((void *)0) 
# 2063 "./cye.h"
       && "Dynamic Array: OOM") || (cye__assert_handler("Assertion Failure", "(&ds)->items != ((void *)0) && \"Dynamic Array: OOM\"", "./cye.h", (int)2063, 
# 2063 "./cye.h" 3 4
       ((void *)0)
# 2063 "./cye.h"
       ), __builtin_trap(), 0))); } memcpy((&ds)->items + (&ds)->count, (s), (n)*sizeof(*(&ds)->items)); (&ds)->count += (n); } while (0); } } while (0);
        if (i < (paths_count-1) && ds.count > 0 && (ds.items[ds.count-1] != '/')) {
            do { const char *cye_tmp_strs[] = {"/"}; for (usz idx = 0; idx < sizeof(cye_tmp_strs) / sizeof(cye_tmp_strs[0]); idx++) { const char *s = cye_tmp_strs[idx]; usz n = strlen(s); do { if ((&ds)->count + (n) > (&ds)->capacity) { if ((&ds)->capacity == 0) { (&ds)->capacity = 256; } while ((&ds)->count + (n) > (&ds)->capacity) { (&ds)->capacity *= 2; } (&ds)->items = cye_context.realloc((&ds)->items, (&ds)->capacity*sizeof(*(&ds)->items)); ((void)(((&ds)->items != 
# 2065 "./cye.h" 3 4
           ((void *)0) 
# 2065 "./cye.h"
           && "Dynamic Array: OOM") || (cye__assert_handler("Assertion Failure", "(&ds)->items != ((void *)0) && \"Dynamic Array: OOM\"", "./cye.h", (int)2065, 
# 2065 "./cye.h" 3 4
           ((void *)0)
# 2065 "./cye.h"
           ), __builtin_trap(), 0))); } memcpy((&ds)->items + (&ds)->count, (s), (n)*sizeof(*(&ds)->items)); (&ds)->count += (n); } while (0); } } while (0);
        }
    }
    do { if ((&ds)->count >= (&ds)->capacity) { (&ds)->capacity = (&ds)->capacity == 0 ? 256 : (&ds)->capacity*2; (&ds)->items = cye_context.realloc( (&ds)->items, (&ds)->capacity*sizeof(((&ds)->items)[0]) ); ((void)(((&ds)->items != 
# 2068 "./cye.h" 3 4
   ((void *)0) 
# 2068 "./cye.h"
   && "Dynamic Array: OOM") || (cye__assert_handler("Assertion Failure", "(&ds)->items != ((void *)0) && \"Dynamic Array: OOM\"", "./cye.h", (int)2068, 
# 2068 "./cye.h" 3 4
   ((void *)0)
# 2068 "./cye.h"
   ), __builtin_trap(), 0))); } (&ds)->items[(&ds)->count++] = ('\0'); } while (0);

    {
        usz chk_point = cye_temp_save();
        TString tpath = cye_path_temp_normalize(ds.items);

        strcpy(ds.items, tpath);
        cye_temp_rewind(chk_point);
    }

    return ds.items;
}

ZString cye_path_base_name(ZString path) {

    ZString p = strrchr(path, '/');
    return p ? p + 1 : path;
# 2093 "./cye.h"
}




ZString cye_path_expand_user(ZString path) {
    if (!path || path[0] != '~') return path;

    Cye_DString result = {0};
    usz path_len = strlen(path);
# 2139 "./cye.h"
    const char* path_separator = strchr(path, '/');
    usz username_len = path_separator ? (size_t)(path_separator - path - 1) :
                         (path_len > 1 ? path_len - 1 : 0);

    const char* home_dir = 
# 2143 "./cye.h" 3 4
                          ((void *)0)
# 2143 "./cye.h"
                              ;

    if (username_len == 0) {

        home_dir = getenv("HOME");
        if (!home_dir) {

            struct passwd* pw = getpwuid(getuid());
            if (pw) {
                home_dir = pw->pw_dir;
            }
        }
    } else {

        char username[256];
        if (username_len >= sizeof(username)) {
            return path;
        }
        memcpy(username, path + 1, username_len);
        username[username_len] = '\0';

        struct passwd* pw = getpwnam(username);
        if (pw) {
            home_dir = pw->pw_dir;
        }
    }

    if (home_dir) {
        do { const char *cye_tmp_strs[] = {home_dir}; for (usz idx = 0; idx < sizeof(cye_tmp_strs) / sizeof(cye_tmp_strs[0]); idx++) { const char *s = cye_tmp_strs[idx]; usz n = strlen(s); do { if ((&result)->count + (n) > (&result)->capacity) { if ((&result)->capacity == 0) { (&result)->capacity = 256; } while ((&result)->count + (n) > (&result)->capacity) { (&result)->capacity *= 2; } (&result)->items = cye_context.realloc((&result)->items, (&result)->capacity*sizeof(*(&result)->items)); ((void)(((&result)->items != 
# 2171 "./cye.h" 3 4
       ((void *)0) 
# 2171 "./cye.h"
       && "Dynamic Array: OOM") || (cye__assert_handler("Assertion Failure", "(&result)->items != ((void *)0) && \"Dynamic Array: OOM\"", "./cye.h", (int)2171, 
# 2171 "./cye.h" 3 4
       ((void *)0)
# 2171 "./cye.h"
       ), __builtin_trap(), 0))); } memcpy((&result)->items + (&result)->count, (s), (n)*sizeof(*(&result)->items)); (&result)->count += (n); } while (0); } } while (0);
        if (path_separator) {
            do { const char *cye_tmp_strs[] = {path_separator}; for (usz idx = 0; idx < sizeof(cye_tmp_strs) / sizeof(cye_tmp_strs[0]); idx++) { const char *s = cye_tmp_strs[idx]; usz n = strlen(s); do { if ((&result)->count + (n) > (&result)->capacity) { if ((&result)->capacity == 0) { (&result)->capacity = 256; } while ((&result)->count + (n) > (&result)->capacity) { (&result)->capacity *= 2; } (&result)->items = cye_context.realloc((&result)->items, (&result)->capacity*sizeof(*(&result)->items)); ((void)(((&result)->items != 
# 2173 "./cye.h" 3 4
           ((void *)0) 
# 2173 "./cye.h"
           && "Dynamic Array: OOM") || (cye__assert_handler("Assertion Failure", "(&result)->items != ((void *)0) && \"Dynamic Array: OOM\"", "./cye.h", (int)2173, 
# 2173 "./cye.h" 3 4
           ((void *)0)
# 2173 "./cye.h"
           ), __builtin_trap(), 0))); } memcpy((&result)->items + (&result)->count, (s), (n)*sizeof(*(&result)->items)); (&result)->count += (n); } while (0); } } while (0);
        }
        return result.items;
    }



    return path;
}

ZString cye_path_expand_vars(ZString path) { do { fprintf(
# 2183 "./cye.h" 3 4
                                            stderr
# 2183 "./cye.h"
                                            , "%s:%d: %s PANIC: " "TODO" "\n","./cye.h", 2183,__PRETTY_FUNCTION__); abort(); } while(0);}

int cye_needs_rebuild_from_buf(const char *output_path, const char **input_paths, usz input_paths_count) {

    struct stat statbuf = {0};

    if (stat(output_path, &statbuf) < 0) {

        if (
# 2191 "./cye.h" 3 4
           (*__errno_location ()) 
# 2191 "./cye.h"
                 == 
# 2191 "./cye.h" 3 4
                    2
# 2191 "./cye.h"
                          ) return 1;
        cye_trace_log(CYE_TRACE_ERROR, "could not stat %s: %s", output_path, (strerror(
# 2192 "./cye.h" 3 4
                                                                            (*__errno_location ())
# 2192 "./cye.h"
                                                                            )));
        return -1;
    }
    int output_path_time = statbuf.
# 2195 "./cye.h" 3 4
                                  st_mtim.tv_sec
# 2195 "./cye.h"
                                          ;

    for (usz i = 0; i < input_paths_count; ++i) {
        const char *input_path = input_paths[i];
        if (stat(input_path, &statbuf) < 0) {

            cye_trace_log(CYE_TRACE_ERROR, "could not stat %s: %s", input_path, (strerror(
# 2201 "./cye.h" 3 4
                                                                               (*__errno_location ())
# 2201 "./cye.h"
                                                                               )));
            return -1;
        }
        int input_path_time = statbuf.
# 2204 "./cye.h" 3 4
                                     st_mtim.tv_sec
# 2204 "./cye.h"
                                             ;

        if (input_path_time > output_path_time) return 1;
    }

    return 0;
# 2250 "./cye.h"
}


TString cye_path_temp_cwd(void) {

    char *buffer = (char*) cye_talloc(
# 2255 "./cye.h" 3 4
                                     4096
# 2255 "./cye.h"
                                             );
    if (getcwd(buffer, 
# 2256 "./cye.h" 3 4
                      4096
# 2256 "./cye.h"
                              ) == 
# 2256 "./cye.h" 3 4
                                   ((void *)0)
# 2256 "./cye.h"
                                       ) {
        cye_trace_log(CYE_TRACE_ERROR, "could not get current directory: %s", (strerror(
# 2257 "./cye.h" 3 4
       (*__errno_location ())
# 2257 "./cye.h"
       )));
        return 
# 2258 "./cye.h" 3 4
              ((void *)0)
# 2258 "./cye.h"
                  ;
    }
    return buffer;
# 2276 "./cye.h"
}


# 2278 "./cye.h" 3 4
_Bool 
# 2278 "./cye.h"
    cye_path_set_cwd(const char *path) {

    if (chdir(path) < 0) {
        cye_trace_log(CYE_TRACE_ERROR, "could not set current directory to %s: %s", path, (strerror(
# 2281 "./cye.h" 3 4
       (*__errno_location ())
# 2281 "./cye.h"
       )));
        return 
# 2282 "./cye.h" 3 4
              0
# 2282 "./cye.h"
                   ;
    }
    return 
# 2284 "./cye.h" 3 4
          1
# 2284 "./cye.h"
              ;







}


b32 cye_file_exists(const char *file_path) {

    struct stat statbuf;
    if (stat(file_path, &statbuf) < 0) {
        if (
# 2299 "./cye.h" 3 4
           (*__errno_location ()) 
# 2299 "./cye.h"
                 == 
# 2299 "./cye.h" 3 4
                    2
# 2299 "./cye.h"
                          ) return 0;
        cye_trace_log(CYE_TRACE_ERROR, "Could not check if file %s exists: %s", file_path, strerror(
# 2300 "./cye.h" 3 4
       (*__errno_location ())
# 2300 "./cye.h"
       ));
        return -1;
    }
    return 1;





}



# 2312 "./cye.h" 3 4
_Bool 
# 2312 "./cye.h"
    cye_file_stats(const char* path, Cye_File_Stats* stats) {

    struct stat st;
    if (stat(path, &st) != 0) {
        return 
# 2316 "./cye.h" 3 4
              0
# 2316 "./cye.h"
                   ;
    }

    stats->created_at = st.
# 2319 "./cye.h" 3 4
                          st_ctim.tv_sec
# 2319 "./cye.h"
                                  ;
    stats->accessed_at = st.
# 2320 "./cye.h" 3 4
                           st_atim.tv_sec
# 2320 "./cye.h"
                                   ;
    stats->modified_at = st.
# 2321 "./cye.h" 3 4
                           st_mtim.tv_sec
# 2321 "./cye.h"
                                   ;
    stats->size_bytes = (size_t)st.st_size;

    return 
# 2324 "./cye.h" 3 4
          1
# 2324 "./cye.h"
              ;
# 2352 "./cye.h"
}



# 2355 "./cye.h" 3 4
_Bool 
# 2355 "./cye.h"
    cye_is_absolute(ZString path) {
    do { fprintf(
# 2356 "./cye.h" 3 4
   stderr
# 2356 "./cye.h"
   , "%s:%d: %s TODO: %s\n", "./cye.h", 2356,__PRETTY_FUNCTION__, "VAI TRABALHAR VAGABUNDO"); abort(); } while(0);
}



# 2360 "./cye.h" 3 4
_Bool 
# 2360 "./cye.h"
    cye_is_relative(ZString path) {
    do { fprintf(
# 2361 "./cye.h" 3 4
   stderr
# 2361 "./cye.h"
   , "%s:%d: %s TODO: %s\n", "./cye.h", 2361,__PRETTY_FUNCTION__, "VAI TRABALHAR VAGABUNDO"); abort(); } while(0);
}



# 2365 "./cye.h" 3 4
_Bool 
# 2365 "./cye.h"
    cye_is_file(ZString path) {
    do { fprintf(
# 2366 "./cye.h" 3 4
   stderr
# 2366 "./cye.h"
   , "%s:%d: %s TODO: %s\n", "./cye.h", 2366,__PRETTY_FUNCTION__, "VAI TRABALHAR VAGABUNDO"); abort(); } while(0);
}



# 2370 "./cye.h" 3 4
_Bool 
# 2370 "./cye.h"
    cye_is_dir(ZString path) {
    do { fprintf(
# 2371 "./cye.h" 3 4
   stderr
# 2371 "./cye.h"
   , "%s:%d: %s TODO: %s\n", "./cye.h", 2371,__PRETTY_FUNCTION__, "VAI TRABALHAR VAGABUNDO"); abort(); } while(0);
}



# 2375 "./cye.h" 3 4
_Bool 
# 2375 "./cye.h"
    cye_is_link(ZString path) {
    do { fprintf(
# 2376 "./cye.h" 3 4
   stderr
# 2376 "./cye.h"
   , "%s:%d: %s TODO: %s\n", "./cye.h", 2376,__PRETTY_FUNCTION__, "VAI TRABALHAR VAGABUNDO"); abort(); } while(0);
}



# 2380 "./cye.h" 3 4
_Bool 
# 2380 "./cye.h"
    cye_is_mount(ZString path) {
    do { fprintf(
# 2381 "./cye.h" 3 4
   stderr
# 2381 "./cye.h"
   , "%s:%d: %s TODO: %s\n", "./cye.h", 2381,__PRETTY_FUNCTION__, "VAI TRABALHAR VAGABUNDO"); abort(); } while(0);
}



# 2385 "./cye.h" 3 4
_Bool 
# 2385 "./cye.h"
    cye_is_same_path(ZString path1, ZString path2) {
    do { fprintf(
# 2386 "./cye.h" 3 4
   stderr
# 2386 "./cye.h"
   , "%s:%d: %s TODO: %s\n", "./cye.h", 2386,__PRETTY_FUNCTION__, "New Functions to Work on"); abort(); } while(0);
}


Cye_DString cye_path_join(ZString path, ZString* paths) {
    do { fprintf(
# 2391 "./cye.h" 3 4
   stderr
# 2391 "./cye.h"
   , "%s:%d: %s TODO: %s\n", "./cye.h", 2391,__PRETTY_FUNCTION__, "New Functions to Work on"); abort(); } while(0);
}


usz cye_path_size(ZString path) {
    do { fprintf(
# 2396 "./cye.h" 3 4
   stderr
# 2396 "./cye.h"
   , "%s:%d: %s TODO: %s\n", "./cye.h", 2396,__PRETTY_FUNCTION__, "New Functions to Work on"); abort(); } while(0);
}


ZString cye_path_real(ZString path) {
    do { fprintf(
# 2401 "./cye.h" 3 4
   stderr
# 2401 "./cye.h"
   , "%s:%d: %s TODO: %s\n", "./cye.h", 2401,__PRETTY_FUNCTION__, "New Functions to Work on"); abort(); } while(0);
}
# 2411 "./cye.h"
ZString cye_path_absolute(ZString path) {
    if (!path) return 
# 2412 "./cye.h" 3 4
                     ((void *)0)
# 2412 "./cye.h"
                         ;

    Cye_DString result = {0};
# 2441 "./cye.h"
    char abs_path[
# 2441 "./cye.h" 3 4
                 4096
# 2441 "./cye.h"
                         ];

    if (path[0] == '/') {

        do { const char *cye_tmp_strs[] = {path}; for (usz idx = 0; idx < sizeof(cye_tmp_strs) / sizeof(cye_tmp_strs[0]); idx++) { const char *s = cye_tmp_strs[idx]; usz n = strlen(s); do { if ((&result)->count + (n) > (&result)->capacity) { if ((&result)->capacity == 0) { (&result)->capacity = 256; } while ((&result)->count + (n) > (&result)->capacity) { (&result)->capacity *= 2; } (&result)->items = cye_context.realloc((&result)->items, (&result)->capacity*sizeof(*(&result)->items)); ((void)(((&result)->items != 
# 2445 "./cye.h" 3 4
       ((void *)0) 
# 2445 "./cye.h"
       && "Dynamic Array: OOM") || (cye__assert_handler("Assertion Failure", "(&result)->items != ((void *)0) && \"Dynamic Array: OOM\"", "./cye.h", (int)2445, 
# 2445 "./cye.h" 3 4
       ((void *)0)
# 2445 "./cye.h"
       ), __builtin_trap(), 0))); } memcpy((&result)->items + (&result)->count, (s), (n)*sizeof(*(&result)->items)); (&result)->count += (n); } while (0); } } while (0);
    } else {

        if (!getcwd(abs_path, sizeof(abs_path))) {
            return 
# 2449 "./cye.h" 3 4
                  ((void *)0)
# 2449 "./cye.h"
                      ;
        }

        do { const char *cye_tmp_strs[] = {abs_path}; for (usz idx = 0; idx < sizeof(cye_tmp_strs) / sizeof(cye_tmp_strs[0]); idx++) { const char *s = cye_tmp_strs[idx]; usz n = strlen(s); do { if ((&result)->count + (n) > (&result)->capacity) { if ((&result)->capacity == 0) { (&result)->capacity = 256; } while ((&result)->count + (n) > (&result)->capacity) { (&result)->capacity *= 2; } (&result)->items = cye_context.realloc((&result)->items, (&result)->capacity*sizeof(*(&result)->items)); ((void)(((&result)->items != 
# 2452 "./cye.h" 3 4
       ((void *)0) 
# 2452 "./cye.h"
       && "Dynamic Array: OOM") || (cye__assert_handler("Assertion Failure", "(&result)->items != ((void *)0) && \"Dynamic Array: OOM\"", "./cye.h", (int)2452, 
# 2452 "./cye.h" 3 4
       ((void *)0)
# 2452 "./cye.h"
       ), __builtin_trap(), 0))); } memcpy((&result)->items + (&result)->count, (s), (n)*sizeof(*(&result)->items)); (&result)->count += (n); } while (0); } } while (0);


        if (result.count > 0 && result.items[result.count - 1] != '/') {
            do { const char *cye_tmp_strs[] = {"/"}; for (usz idx = 0; idx < sizeof(cye_tmp_strs) / sizeof(cye_tmp_strs[0]); idx++) { const char *s = cye_tmp_strs[idx]; usz n = strlen(s); do { if ((&result)->count + (n) > (&result)->capacity) { if ((&result)->capacity == 0) { (&result)->capacity = 256; } while ((&result)->count + (n) > (&result)->capacity) { (&result)->capacity *= 2; } (&result)->items = cye_context.realloc((&result)->items, (&result)->capacity*sizeof(*(&result)->items)); ((void)(((&result)->items != 
# 2456 "./cye.h" 3 4
           ((void *)0) 
# 2456 "./cye.h"
           && "Dynamic Array: OOM") || (cye__assert_handler("Assertion Failure", "(&result)->items != ((void *)0) && \"Dynamic Array: OOM\"", "./cye.h", (int)2456, 
# 2456 "./cye.h" 3 4
           ((void *)0)
# 2456 "./cye.h"
           ), __builtin_trap(), 0))); } memcpy((&result)->items + (&result)->count, (s), (n)*sizeof(*(&result)->items)); (&result)->count += (n); } while (0); } } while (0);
        }

        do { const char *cye_tmp_strs[] = {path}; for (usz idx = 0; idx < sizeof(cye_tmp_strs) / sizeof(cye_tmp_strs[0]); idx++) { const char *s = cye_tmp_strs[idx]; usz n = strlen(s); do { if ((&result)->count + (n) > (&result)->capacity) { if ((&result)->capacity == 0) { (&result)->capacity = 256; } while ((&result)->count + (n) > (&result)->capacity) { (&result)->capacity *= 2; } (&result)->items = cye_context.realloc((&result)->items, (&result)->capacity*sizeof(*(&result)->items)); ((void)(((&result)->items != 
# 2459 "./cye.h" 3 4
       ((void *)0) 
# 2459 "./cye.h"
       && "Dynamic Array: OOM") || (cye__assert_handler("Assertion Failure", "(&result)->items != ((void *)0) && \"Dynamic Array: OOM\"", "./cye.h", (int)2459, 
# 2459 "./cye.h" 3 4
       ((void *)0)
# 2459 "./cye.h"
       ), __builtin_trap(), 0))); } memcpy((&result)->items + (&result)->count, (s), (n)*sizeof(*(&result)->items)); (&result)->count += (n); } while (0); } } while (0);
    }


    char real_path[
# 2463 "./cye.h" 3 4
                  4096
# 2463 "./cye.h"
                          ];
    if (realpath(result.items, real_path)) {
        result.count = 0;
        do { const char *cye_tmp_strs[] = {real_path}; for (usz idx = 0; idx < sizeof(cye_tmp_strs) / sizeof(cye_tmp_strs[0]); idx++) { const char *s = cye_tmp_strs[idx]; usz n = strlen(s); do { if ((&result)->count + (n) > (&result)->capacity) { if ((&result)->capacity == 0) { (&result)->capacity = 256; } while ((&result)->count + (n) > (&result)->capacity) { (&result)->capacity *= 2; } (&result)->items = cye_context.realloc((&result)->items, (&result)->capacity*sizeof(*(&result)->items)); ((void)(((&result)->items != 
# 2466 "./cye.h" 3 4
       ((void *)0) 
# 2466 "./cye.h"
       && "Dynamic Array: OOM") || (cye__assert_handler("Assertion Failure", "(&result)->items != ((void *)0) && \"Dynamic Array: OOM\"", "./cye.h", (int)2466, 
# 2466 "./cye.h" 3 4
       ((void *)0)
# 2466 "./cye.h"
       ), __builtin_trap(), 0))); } memcpy((&result)->items + (&result)->count, (s), (n)*sizeof(*(&result)->items)); (&result)->count += (n); } while (0); } } while (0);
    } else if (
# 2467 "./cye.h" 3 4
              (*__errno_location ()) 
# 2467 "./cye.h"
                    != 
# 2467 "./cye.h" 3 4
                       2
# 2467 "./cye.h"
                             ) {


        cye_context.free((result).items);
        return 
# 2471 "./cye.h" 3 4
              ((void *)0)
# 2471 "./cye.h"
                  ;
    }


    return result.items;
}


ZString cye_path_relative(ZString from, ZString target) {
    do { fprintf(
# 2480 "./cye.h" 3 4
   stderr
# 2480 "./cye.h"
   , "%s:%d: %s TODO: %s\n", "./cye.h", 2480,__PRETTY_FUNCTION__, "New Functions to Work on"); abort(); } while(0);
}


ZString cye_path_home(void) {
    do { fprintf(
# 2485 "./cye.h" 3 4
   stderr
# 2485 "./cye.h"
   , "%s:%d: %s TODO: %s\n", "./cye.h", 2485,__PRETTY_FUNCTION__, "New Functions to Work on"); abort(); } while(0);
}


ZString cye_path_cwd(void) {
    do { fprintf(
# 2490 "./cye.h" 3 4
   stderr
# 2490 "./cye.h"
   , "%s:%d: %s TODO: %s\n", "./cye.h", 2490,__PRETTY_FUNCTION__, "New Functions to Work on"); abort(); } while(0);
}

ZString cye_path_parent(ZString path) {
    do { fprintf(
# 2494 "./cye.h" 3 4
   stderr
# 2494 "./cye.h"
   , "%s:%d: %s TODO: %s\n", "./cye.h", 2494,__PRETTY_FUNCTION__, "New Functions to Work on"); abort(); } while(0);
}

ZString cye_path_owner(ZString path) {
    do { fprintf(
# 2498 "./cye.h" 3 4
   stderr
# 2498 "./cye.h"
   , "%s:%d: %s TODO: %s\n", "./cye.h", 2498,__PRETTY_FUNCTION__, "New Functions to Work on"); abort(); } while(0);
}


ZString cye_path_stem(ZString path) {
    do { fprintf(
# 2503 "./cye.h" 3 4
   stderr
# 2503 "./cye.h"
   , "%s:%d: %s TODO: %s\n", "./cye.h", 2503,__PRETTY_FUNCTION__, "New Functions to Work on"); abort(); } while(0);
}





ZString cye_path_dir_of(ZString file_path) {
    if (!file_path) return 
# 2511 "./cye.h" 3 4
                          ((void *)0)
# 2511 "./cye.h"
                              ;


    Cye_Log_Level old_level = cye_threshold_log_level;
    cye_set_trace_level(CYE_LOG_NONE);
    if (cye_path_file_type(file_path) == CYE_FILE_TYPE_DIRECTORY) {
        return file_path;
    }
    cye_set_trace_level(old_level);


    ZString last_sep = 
# 2522 "./cye.h" 3 4
                      ((void *)0)
# 2522 "./cye.h"
                          ;
    for (const char* p = file_path; *p; p++) {



        if (*p == '/') {

            last_sep = (ZString)p;
        }
    }

    if (!last_sep) {

        return ".";
    }
# 2560 "./cye.h"
    if (last_sep == file_path) {
        return "/";
    }



    static char dir_buffer[(
# 2566 "./cye.h" 3 4
                          4096
# 2566 "./cye.h"
                          *2)];
    size_t len = last_sep - file_path;


    if (last_sep[1] == '\0') {

        if (len >= (
# 2572 "./cye.h" 3 4
                  4096
# 2572 "./cye.h"
                  *2)) len = (
# 2572 "./cye.h" 3 4
                                      4096
# 2572 "./cye.h"
                                      *2) - 1;
        memcpy(dir_buffer, file_path, len);
        dir_buffer[len] = '\0';
        return dir_buffer;
    }


    if (len >= (
# 2579 "./cye.h" 3 4
              4096
# 2579 "./cye.h"
              *2)) len = (
# 2579 "./cye.h" 3 4
                                  4096
# 2579 "./cye.h"
                                  *2) - 1;
    memcpy(dir_buffer, file_path, len);
    dir_buffer[len] = '\0';
    return dir_buffer;
}



ZString cye_path_ext(ZString path) {
    do { fprintf(
# 2588 "./cye.h" 3 4
   stderr
# 2588 "./cye.h"
   , "%s:%d: %s TODO: %s\n", "./cye.h", 2588,__PRETTY_FUNCTION__, "New Functions to Work on"); abort(); } while(0);
}



# 2592 "./cye.h" 3 4
_Bool 
# 2592 "./cye.h"
    cye_path_touch(ZString path) {

    struct stat st;
    
# 2595 "./cye.h" 3 4
   _Bool 
# 2595 "./cye.h"
        file_exists = (stat(path, &st) == 0);

    if (!file_exists) {
# 2615 "./cye.h"
        int fd = open(path, 
# 2615 "./cye.h" 3 4
                           01 
# 2615 "./cye.h"
                                    | 
# 2615 "./cye.h" 3 4
                                      0100 
# 2615 "./cye.h"
                                              | 
# 2615 "./cye.h" 3 4
                                                0400 
# 2615 "./cye.h"
                                                         | 
# 2615 "./cye.h" 3 4
                                                           04000
# 2615 "./cye.h"
                                                                     , 0666);
        if (fd < 0) {

            if (
# 2618 "./cye.h" 3 4
               (*__errno_location ()) 
# 2618 "./cye.h"
                     != 
# 2618 "./cye.h" 3 4
                        17
# 2618 "./cye.h"
                              ) {
                return 
# 2619 "./cye.h" 3 4
                      0
# 2619 "./cye.h"
                           ;
            }
            file_exists = 
# 2621 "./cye.h" 3 4
                         1
# 2621 "./cye.h"
                             ;
        } else {
            close(fd);
        }

    }


    time_t current_time = time(
# 2629 "./cye.h" 3 4
                              ((void *)0)
# 2629 "./cye.h"
                                  );
    struct utimbuf new_times = {
        .actime = current_time,
        .modtime = current_time
    };

    return (utime(path, &new_times) == 0);
}


# 2638 "./cye.h" 3 4
_Bool 
# 2638 "./cye.h"
    cye_make_dir_include_parents_from_tstr(TString path) {
    if (path == 
# 2639 "./cye.h" 3 4
               ((void *)0) 
# 2639 "./cye.h"
                    || *path == '\0') {
        return 
# 2640 "./cye.h" 3 4
              0
# 2640 "./cye.h"
                   ;
    }

    Cye_Log_Level old_level = cye_threshold_log_level;
    cye_set_trace_level(CYE_LOG_NONE);
    
# 2645 "./cye.h" 3 4
   _Bool 
# 2645 "./cye.h"
        created = 
# 2645 "./cye.h" 3 4
                  0
# 2645 "./cye.h"
                       ;


    usz len = strlen(path);
    while (len > 0 && (path[len - 1] == '/' || path[len - 1] == '\\')) {
        path[--len] = '\0';
    }
# 2675 "./cye.h"
    for (char *p = path + 1; *p; p++) {
        if (*p == '/' || *p == '\\') {
            *p = '\0';
            created |= cye_make_dir_if_not_exists(path);
            *p = '/';
        }
    }
    created |= cye_make_dir_if_not_exists(path);

    cye_set_trace_level(old_level);
    if (!created) {
        cye_trace_log(CYE_TRACE_ERROR, "could not create directories recursively `%s`: %s", path, (strerror(
# 2686 "./cye.h" 3 4
       (*__errno_location ())
# 2686 "./cye.h"
       )));
    } else {
        cye_trace_log(CYE_LOG_INFO, "created all directories `%s`", path);
    }

    return created;
}



# 2695 "./cye.h" 3 4
_Bool 
# 2695 "./cye.h"
    cye_make_dir_include_parents(ZString path) {
    
# 2696 "./cye.h" 3 4
   _Bool 
# 2696 "./cye.h"
        created = 
# 2696 "./cye.h" 3 4
                   0
# 2696 "./cye.h"
                        ;
    usz chk_point = cye_temp_save();
    cye_context = cye_temp_context();

    TString tpath = cye_path_create_from_array( ((const char*[]){path}), (sizeof((const char *[]){path}) / sizeof(const char *)));
    created = cye_make_dir_include_parents_from_tstr(tpath);

    cye_context = cye_default_context();
    cye_temp_rewind(chk_point);
    return created;
}



# 2709 "./cye.h" 3 4
_Bool 
# 2709 "./cye.h"
    cye_remove_file(ZString path) {
    if (!cye_file_exists(path)) {
        cye_trace_log(CYE_LOG_INFO, "file `%s` does not exist", path);
        return 
# 2712 "./cye.h" 3 4
              1
# 2712 "./cye.h"
                  ;
    }

    Cye_File_Type type = cye_path_file_type(path);

    if (type != CYE_FILE_TYPE_REGULAR) {
        cye_trace_log(CYE_TRACE_ERROR, "`%s` exists but is not a regular file", path);
        return 
# 2719 "./cye.h" 3 4
              0
# 2719 "./cye.h"
                   ;
    }

    if (type == CYE_FILE_TYPE_DIRECTORY) {
        cye_trace_log(CYE_TRACE_ERROR, "`%s` exists but is a directory, should we make a recursive remove function?", path);
        return 
# 2724 "./cye.h" 3 4
              0
# 2724 "./cye.h"
                   ;
    }





    int result = unlink(path);


    if (result < 0) {
        cye_trace_log(CYE_TRACE_ERROR, "could not remove file `%s`: %s", path, strerror(
# 2735 "./cye.h" 3 4
       (*__errno_location ())
# 2735 "./cye.h"
       ));
        return 
# 2736 "./cye.h" 3 4
              0
# 2736 "./cye.h"
                   ;
    }

    cye_trace_log(CYE_LOG_INFO, "Removed file `%s`", path);
    return 
# 2740 "./cye.h" 3 4
          1
# 2740 "./cye.h"
              ;

}



static void path_join(char *dest, const char *dir, const char *file) {
    size_t dir_len = strlen(dir);
    strcpy(dest, dir);






        if (dir_len > 0 && dir[dir_len - 1] != '/') {
            strcat(dest, "/");
        }


    strcat(dest, file);
}



# 2764 "./cye.h" 3 4
_Bool 
# 2764 "./cye.h"
    cye_remove_dir(const char *path) {
    char full_path[
# 2765 "./cye.h" 3 4
                  4096
# 2765 "./cye.h"
                          ];
    
# 2766 "./cye.h" 3 4
   _Bool 
# 2766 "./cye.h"
        success = 
# 2766 "./cye.h" 3 4
                  1
# 2766 "./cye.h"
                      ;


    DIR *dir = opendir(path);
    if (!dir) {
        if (
# 2771 "./cye.h" 3 4
           (*__errno_location ()) 
# 2771 "./cye.h"
                 == 
# 2771 "./cye.h" 3 4
                    2
# 2771 "./cye.h"
                          ) {

            return 
# 2773 "./cye.h" 3 4
                  1
# 2773 "./cye.h"
                      ;
        }
        cye_trace_log(CYE_TRACE_ERROR, "could not open directory `%s`: %s", path, strerror(
# 2775 "./cye.h" 3 4
       (*__errno_location ())
# 2775 "./cye.h"
       ));
        return 
# 2776 "./cye.h" 3 4
              0
# 2776 "./cye.h"
                   ;
    }

    struct dirent *entry;
    while ((entry = readdir(dir))) {

        if (strcmp(entry->d_name, ".") == 0 ||
            strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        path_join(full_path, path, entry->d_name);

        struct stat statbuf;
        if (stat(full_path, &statbuf) != 0) {
            cye_trace_log(CYE_TRACE_ERROR, "could not stat `%s`: %s", full_path, strerror(
# 2791 "./cye.h" 3 4
           (*__errno_location ())
# 2791 "./cye.h"
           ));
            success = 
# 2792 "./cye.h" 3 4
                     0
# 2792 "./cye.h"
                          ;
            continue;
        }

        if (
# 2796 "./cye.h" 3 4
           ((((
# 2796 "./cye.h"
           statbuf.st_mode
# 2796 "./cye.h" 3 4
           )) & 0170000) == (0040000))
# 2796 "./cye.h"
                                   ) {

            if (!cye_remove_dir(full_path)) {
                success = 
# 2799 "./cye.h" 3 4
                         0
# 2799 "./cye.h"
                              ;
            }
        } else {

            if (unlink(full_path) != 0) {
                cye_trace_log(CYE_TRACE_ERROR, "could not delete file `%s`: %s", full_path, strerror(
# 2804 "./cye.h" 3 4
               (*__errno_location ())
# 2804 "./cye.h"
               ));
                success = 
# 2805 "./cye.h" 3 4
                         0
# 2805 "./cye.h"
                              ;
            } else {
                cye_trace_log(CYE_LOG_INFO, "deleted file `%s`", full_path);
            }
        }
    }

    closedir(dir);


    if (success && rmdir(path) != 0) {
        cye_trace_log(CYE_TRACE_ERROR, "could not remove directory `%s`: %s", path, strerror(
# 2816 "./cye.h" 3 4
       (*__errno_location ())
# 2816 "./cye.h"
       ));
        success = 
# 2817 "./cye.h" 3 4
                 0
# 2817 "./cye.h"
                      ;
    } else if (success) {
        cye_trace_log(CYE_LOG_INFO, "Removed directory `%s`", path);
    }
# 2875 "./cye.h"
    return success;
}



# 2879 "./cye.h" 3 4
_Bool 
# 2879 "./cye.h"
    cye_remove_dirs(ZString path) {
    do { fprintf(
# 2880 "./cye.h" 3 4
   stderr
# 2880 "./cye.h"
   , "%s:%d: %s TODO: %s\n", "./cye.h", 2880,__PRETTY_FUNCTION__, "New Functions to Work on"); abort(); } while(0);
}



# 2884 "./cye.h" 3 4
_Bool 
# 2884 "./cye.h"
    cye_path_move(ZString src, ZString dst) {

    cye_trace_log(CYE_LOG_INFO, "Moving %s -> %s", src, dst);


    if (rename(src, dst) < 0) {
        cye_trace_log(CYE_TRACE_ERROR, "Could not move %s to %s: %s", src, dst, (strerror(
# 2890 "./cye.h" 3 4
       (*__errno_location ())
# 2890 "./cye.h"
       )));
        return 
# 2891 "./cye.h" 3 4
              0
# 2891 "./cye.h"
                   ;
    }






    return 
# 2899 "./cye.h" 3 4
          1
# 2899 "./cye.h"
              ;
}



# 2903 "./cye.h" 3 4
_Bool 
# 2903 "./cye.h"
    cye_path_rename(ZString src, ZString dst) {

    return cye_path_move(src, dst);
}



# 2909 "./cye.h" 3 4
_Bool 
# 2909 "./cye.h"
    cye_path_renames(ZString old_path, ZString new_path) {
    do { fprintf(
# 2910 "./cye.h" 3 4
   stderr
# 2910 "./cye.h"
   , "%s:%d: %s TODO: %s\n", "./cye.h", 2910,__PRETTY_FUNCTION__, "New Functions to Work on"); abort(); } while(0);
}



# 2914 "./cye.h" 3 4
_Bool 
# 2914 "./cye.h"
    cye_path_replace(ZString src, ZString dst) {
    do { fprintf(
# 2915 "./cye.h" 3 4
   stderr
# 2915 "./cye.h"
   , "%s:%d: %s TODO: %s\n", "./cye.h", 2915,__PRETTY_FUNCTION__, "New Functions to Work on"); abort(); } while(0);
}



Cye_Path_DArray cye_path_scandir(ZString path) {
    do { fprintf(
# 2921 "./cye.h" 3 4
   stderr
# 2921 "./cye.h"
   , "%s:%d: %s TODO: %s\n", "./cye.h", 2921,__PRETTY_FUNCTION__, "New Functions to Work on"); abort(); } while(0);
}
# 2943 "./cye.h"
Cye_String_Slice cye_str_slice_make(const char *str) {
    return (Cye_String_Slice){.data = (str), .count = (strlen(str))};
}


Cye_String_Slice cye_str_slice_trim(Cye_String_Slice s) {
    while (s.count > 0 && 
# 2949 "./cye.h" 3 4
                         ((*__ctype_b_loc ())[(int) ((
# 2949 "./cye.h"
                         s.data[0]
# 2949 "./cye.h" 3 4
                         ))] & (unsigned short int) _ISspace)
# 2949 "./cye.h"
                                           ) {
        s.data++;
        s.count--;
    }
    while (s.count > 0 && 
# 2953 "./cye.h" 3 4
                         ((*__ctype_b_loc ())[(int) ((
# 2953 "./cye.h"
                         s.data[s.count - 1]
# 2953 "./cye.h" 3 4
                         ))] & (unsigned short int) _ISspace)
# 2953 "./cye.h"
                                                     ) {
        s.count--;
    }
    return s;
}


void cye_str_slice_to_zstr(Cye_String_Slice s, char *buf, usz buf_size) {
    usz to_copy = s.count < buf_size - 1 ? s.count : buf_size - 1;
    memcpy(buf, s.data, to_copy);
    buf[to_copy] = '\0';
}



Cye_String_Slice cye_str_slice_strip_left(Cye_String_Slice s) {
    while (s.count > 0 && 
# 2969 "./cye.h" 3 4
                         ((*__ctype_b_loc ())[(int) ((
# 2969 "./cye.h"
                         s.data[0]
# 2969 "./cye.h" 3 4
                         ))] & (unsigned short int) _ISspace)
# 2969 "./cye.h"
                                           ) {
        s.data++;
        s.count--;
    }
    return s;
}


Cye_String_Slice cye_str_slice_strip_right(Cye_String_Slice s) {
    while (s.count > 0 && 
# 2978 "./cye.h" 3 4
                         ((*__ctype_b_loc ())[(int) ((
# 2978 "./cye.h"
                         s.data[s.count - 1]
# 2978 "./cye.h" 3 4
                         ))] & (unsigned short int) _ISspace)
# 2978 "./cye.h"
                                                     ) {
        s.count--;
    }
    return s;
}

Cye_String_Slice cye_str_slice_make_len(const char *str, usz len) {
    return (Cye_String_Slice){.data = ((char*)str), .count = (len)};
}



# 2989 "./cye.h" 3 4
_Bool 
# 2989 "./cye.h"
    cye_str_slice_equals(Cye_String_Slice a, Cye_String_Slice b) {
    if (a.count != b.count) return 
# 2990 "./cye.h" 3 4
                                  0
# 2990 "./cye.h"
                                       ;
    return memcmp(a.data, b.data, a.count) == 0;
}



# 2995 "./cye.h" 3 4
_Bool 
# 2995 "./cye.h"
    cye_str_slice_contains(Cye_String_Slice haystack, Cye_String_Slice needle) {
    if (needle.count > haystack.count) return 
# 2996 "./cye.h" 3 4
                                             0
# 2996 "./cye.h"
                                                  ;

    for (usz i = 0; i <= haystack.count - needle.count; i++) {
        if (memcmp(haystack.data + i, needle.data, needle.count) == 0) {
            return 
# 3000 "./cye.h" 3 4
                  1
# 3000 "./cye.h"
                      ;
        }
    }
    return 
# 3003 "./cye.h" 3 4
          0
# 3003 "./cye.h"
               ;
}



Cye_String_Slice_DArray cye_str_slice_split(Cye_String_Slice s, Cye_String_Slice delim) {
    Cye_String_Slice_DArray result = {0};

    char *start = (char*)s.data;
    char *end = (char*)s.data + s.count;
    char *current = (char*)s.data;

    while (current <= end - delim.count) {
        if (memcmp(current, delim.data, delim.count) == 0) {
            do { if ((&result)->count >= (&result)->capacity) { (&result)->capacity = (&result)->capacity == 0 ? 256 : (&result)->capacity*2; (&result)->items = cye_context.realloc( (&result)->items, (&result)->capacity*sizeof(((&result)->items)[0]) ); ((void)(((&result)->items != 
# 3017 "./cye.h" 3 4
           ((void *)0) 
# 3017 "./cye.h"
           && "Dynamic Array: OOM") || (cye__assert_handler("Assertion Failure", "(&result)->items != ((void *)0) && \"Dynamic Array: OOM\"", "./cye.h", (int)3017, 
# 3017 "./cye.h" 3 4
           ((void *)0)
# 3017 "./cye.h"
           ), __builtin_trap(), 0))); } (&result)->items[(&result)->count++] = (cye_str_slice_make_len(start, current - start)); } while (0);
            current += delim.count;
            start = current;
        } else {
            current++;
        }
    }


    if (start < end) {
        do { if ((&result)->count >= (&result)->capacity) { (&result)->capacity = (&result)->capacity == 0 ? 256 : (&result)->capacity*2; (&result)->items = cye_context.realloc( (&result)->items, (&result)->capacity*sizeof(((&result)->items)[0]) ); ((void)(((&result)->items != 
# 3027 "./cye.h" 3 4
       ((void *)0) 
# 3027 "./cye.h"
       && "Dynamic Array: OOM") || (cye__assert_handler("Assertion Failure", "(&result)->items != ((void *)0) && \"Dynamic Array: OOM\"", "./cye.h", (int)3027, 
# 3027 "./cye.h" 3 4
       ((void *)0)
# 3027 "./cye.h"
       ), __builtin_trap(), 0))); } (&result)->items[(&result)->count++] = (cye_str_slice_make_len(start, end - start)); } while (0);
    }

    return result;
}


void cye_str_slice_split_first(Cye_String_Slice s, char delim, Cye_String_Slice *before, Cye_String_Slice *after) {
    for (usz i = 0; i < s.count; i++) {
        if (s.data[i] == delim) {
            if (before) *before = (Cye_String_Slice){.data = (s.data), .count = (i)};
            if (after) *after = (Cye_String_Slice){.data = (s.data + i + 1), .count = (s.count - i - 1)};
            return;
        }
    }
    if (before) *before = s;
    if (after) *after = (const Cye_String_Slice){.data = 
# 3043 "./cye.h" 3 4
                       ((void *)0)
# 3043 "./cye.h"
                       , .count = 0};
}



# 3047 "./cye.h" 3 4
_Bool 
# 3047 "./cye.h"
    cye_str_slice_starts_with(Cye_String_Slice s, Cye_String_Slice prefix) {
    if (prefix.count > s.count) return 
# 3048 "./cye.h" 3 4
                                      0
# 3048 "./cye.h"
                                           ;
    return memcmp(s.data, prefix.data, prefix.count) == 0;
}



# 3053 "./cye.h" 3 4
_Bool 
# 3053 "./cye.h"
    cye_str_slice_ends_with(Cye_String_Slice s, Cye_String_Slice suffix) {
    if (suffix.count > s.count) return 
# 3054 "./cye.h" 3 4
                                      0
# 3054 "./cye.h"
                                           ;
    return memcmp(s.data + s.count - suffix.count, suffix.data, suffix.count) == 0;
}



# 3059 "./cye.h" 3 4
_Bool 
# 3059 "./cye.h"
    cye_str_slice_starts_with_zstr(Cye_String_Slice s, ZString prefix) {
    usz prefix_len = strlen(prefix);
    if (prefix_len > s.count) return 
# 3061 "./cye.h" 3 4
                                    0
# 3061 "./cye.h"
                                         ;
    return memcmp(s.data, prefix, prefix_len) == 0;
}



# 3066 "./cye.h" 3 4
_Bool 
# 3066 "./cye.h"
    cye_str_slice_ends_with_zstr(Cye_String_Slice s, ZString suffix) {
    usz suffix_len = strlen(suffix);
    if (suffix_len > s.count) return 
# 3068 "./cye.h" 3 4
                                    0
# 3068 "./cye.h"
                                         ;
    return memcmp(s.data + s.count - suffix_len, suffix, suffix_len) == 0;
}






# 3076 "./cye.h" 3 4
_Bool 
# 3076 "./cye.h"
    cye_zstr_ends_with(ZString src, ZString ending) {
    if (!src || !ending) return 
# 3077 "./cye.h" 3 4
                               0
# 3077 "./cye.h"
                                    ;

    usz src_len = strlen(src);
    usz ending_len = strlen(ending);


    if (ending_len > src_len) return 
# 3083 "./cye.h" 3 4
                                    0
# 3083 "./cye.h"
                                         ;


    return memcmp(src + (src_len - ending_len), ending, ending_len) == 0;
}


# 3089 "./cye.h" 3 4
_Bool 
# 3089 "./cye.h"
    cye_zstr_starts_with(ZString src, ZString prefix) {
    if (src == 
# 3090 "./cye.h" 3 4
              ((void *)0) 
# 3090 "./cye.h"
                   || prefix == 
# 3090 "./cye.h" 3 4
                                ((void *)0)
# 3090 "./cye.h"
                                    ) return 
# 3090 "./cye.h" 3 4
                                             0
# 3090 "./cye.h"
                                                  ;
    if (!*prefix) return 
# 3091 "./cye.h" 3 4
                                      1
# 3091 "./cye.h"
                                          ;
    if (!*src) return 
# 3092 "./cye.h" 3 4
                                      0
# 3092 "./cye.h"
                                           ;

    usz prefix_len = strlen(prefix);
    usz src_len = strlen(src);

    if (prefix_len > src_len) return 
# 3097 "./cye.h" 3 4
                                    0
# 3097 "./cye.h"
                                         ;

    return memcmp(src, prefix, prefix_len) == 0;
}
# 3109 "./cye.h"
static int cye_count_non_scaped_percent(ZString s) {
    int count = 0;
    int i = 0;

    while (s[i] != '\0') {
        if (s[i] == '%') {





            if (i == 0 || s[i - 1] != '\\') {
                count++;
            }
        }
        i++;
    }
    return count;
}

void cye_ds_printf(Cye_DString *ds, ZString fmt, ...) {

    ((void)(cye_count_non_scaped_percent));
    va_list args;
    
# 3133 "./cye.h" 3 4
   __builtin_va_start(
# 3133 "./cye.h"
   args
# 3133 "./cye.h" 3 4
   ,
# 3133 "./cye.h"
   fmt
# 3133 "./cye.h" 3 4
   )
# 3133 "./cye.h"
                      ;
    int n = vsnprintf(
# 3134 "./cye.h" 3 4
                     ((void *)0)
# 3134 "./cye.h"
                         , 0, fmt, args);
    
# 3135 "./cye.h" 3 4
   __builtin_va_end(
# 3135 "./cye.h"
   args
# 3135 "./cye.h" 3 4
   )
# 3135 "./cye.h"
               ;

    ((void)((n >= 0) || (cye__assert_handler("Assertion Failure", "n >= 0", "./cye.h", (int)3137, 
# 3137 "./cye.h" 3 4
   ((void *)0)
# 3137 "./cye.h"
   ), __builtin_trap(), 0)));
    usz chk_point = cye_temp_save();
    char *result = cye_talloc(n + 1);

    ((void)((result != 
# 3141 "./cye.h" 3 4
   ((void *)0) 
# 3141 "./cye.h"
   && "Extend the size of the temporary allocator") || (cye__assert_handler("Assertion Failure", "result != ((void *)0) && \"Extend the size of the temporary allocator\"", "./cye.h", (int)3141, 
# 3141 "./cye.h" 3 4
   ((void *)0)
# 3141 "./cye.h"
   ), __builtin_trap(), 0)));

    
# 3143 "./cye.h" 3 4
   __builtin_va_start(
# 3143 "./cye.h"
   args
# 3143 "./cye.h" 3 4
   ,
# 3143 "./cye.h"
   fmt
# 3143 "./cye.h" 3 4
   )
# 3143 "./cye.h"
                      ;
    vsnprintf(result, n + 1, fmt, args);
    
# 3145 "./cye.h" 3 4
   __builtin_va_end(
# 3145 "./cye.h"
   args
# 3145 "./cye.h" 3 4
   )
# 3145 "./cye.h"
               ;
    do { if ((ds)->count + (n) > (ds)->capacity) { if ((ds)->capacity == 0) { (ds)->capacity = 256; } while ((ds)->count + (n) > (ds)->capacity) { (ds)->capacity *= 2; } (ds)->items = cye_context.realloc((ds)->items, (ds)->capacity*sizeof(*(ds)->items)); ((void)(((ds)->items != 
# 3146 "./cye.h" 3 4
   ((void *)0) 
# 3146 "./cye.h"
   && "Dynamic Array: OOM") || (cye__assert_handler("Assertion Failure", "(ds)->items != ((void *)0) && \"Dynamic Array: OOM\"", "./cye.h", (int)3146, 
# 3146 "./cye.h" 3 4
   ((void *)0)
# 3146 "./cye.h"
   ), __builtin_trap(), 0))); } memcpy((ds)->items + (ds)->count, (result), (n)*sizeof(*(ds)->items)); (ds)->count += (n); } while (0);
    cye_temp_rewind(chk_point);
}






f32 cye_clamp(f32 value, f32 min, f32 max) {
    f32 result = (value < min)? min : value;
    if (result > max) result = max;
    return result;
}


f32 cye_lerp(f32 start, f32 end, f32 amount) {
    f32 result = start + amount*(end - start);
    return result;
}


f32 cye_normalize(f32 value, f32 start, f32 end) {
    f32 result = (value - start)/(end - start);
    return result;
}


f32 cye_remap(f32 value, f32 inputStart, f32 inputEnd, f32 outputStart, f32 outputEnd) {
    f32 result = (value - inputStart)/(inputEnd - inputStart)*(outputEnd - outputStart) + outputStart;
    return result;
}


f32 cye_floorf(f32 x) {
    int32_t i = (int32_t)x;
    return (x < 0.0f && x != i) ? i - 1.0f : (f32)i;
}


f32 cye_fabsf(f32 x) {
    union {
        f32 f;
        uint32_t i;
    } u = { .f = x };
    u.i &= 0x7FFFFFFF;
    return u.f;
}


f32 cye_fmaxf(f32 x, f32 y) {

    if (x != x) return y;
    if (y != y) return x;

    return x > y ? x : y;
}


f32 cye_wrap(f32 value, f32 min, f32 max) {
    f32 result = value - (max - min)*cye_floorf((value - min)/(max - min));
    return result;
}


int cye_float_equals(f32 x, f32 y) {
    int result = (cye_fabsf(x - y)) <= (0.000001f*cye_fmaxf(1.0f, cye_fmaxf(cye_fabsf(x), cye_fabsf(y))));
    return result;
}





void cye_set_trace_level(Cye_Log_Level level) {
    cye_threshold_log_level = level;
}


void cye_trace_log(Cye_Log_Level level, const char *fmt, ...) {

    if (level < cye_threshold_log_level) return;

    va_list args;
    
# 3230 "./cye.h" 3 4
   __builtin_va_start(
# 3230 "./cye.h"
   args
# 3230 "./cye.h" 3 4
   ,
# 3230 "./cye.h"
   fmt
# 3230 "./cye.h" 3 4
   )
# 3230 "./cye.h"
                      ;
    char buffer[1024] = { 0 };

    const char *color = "";
    const char *reset = "";
    const char *bold = "";


    switch (level) {
        case CYE_LOG_TRACE: break;
        case CYE_LOG_DEBUG: color = "\033[96m"; reset = "\033[0m"; break;
        case CYE_LOG_INFO: color = "\x1b[30;1m";; reset = "\033[0m"; break;
        case CYE_LOG_OKAY: color = "\033[92m"; reset = "\033[0m"; break;
        case CYE_LOG_WARNING: color = "\033[93m"; reset = "\033[0m"; break;
        case CYE_TRACE_ERROR: color = "\x1b[1m\x1b[31m";; reset = "\033[0m"; break;
        case CYE_LOG_FATAL: color = "\x1b[1m\x1b[31m";; reset = "\033[0m"; bold = "\x1b[37m";; break;
        case CYE_LOG_ALL: break;
        case CYE_LOG_NONE: break;
        default: do { fprintf(
# 3248 "./cye.h" 3 4
                stderr
# 3248 "./cye.h"
                , "%s:%d: %s UNREACHABLE: %s\n","./cye.h", 3248,__PRETTY_FUNCTION__, "cye_trace_log"); abort(); } while(0); break;
    }


    if (!isatty(
# 3252 "./cye.h" 3 4
               1
# 3252 "./cye.h"
                            )) {
        color = ""; reset = ""; bold = "";
    }






    const usz max_len = 1024;
    usz written = 0 ;
    switch (level) {
        case CYE_LOG_TRACE: written = snprintf(buffer, max_len, "%sTRACE%s%s: ", color, reset, bold); break;
        case CYE_LOG_DEBUG: written = snprintf(buffer, max_len, "%sDEBUG%s%s: ", color, reset, bold); break;
        case CYE_LOG_INFO: written = snprintf(buffer, max_len, "%sINFO%s%s:  ", color, reset, bold); break;
        case CYE_LOG_OKAY: written = snprintf(buffer, max_len, "%sOKAY%s%s:  ", color, reset, bold); break;
        case CYE_LOG_WARNING: written = snprintf(buffer, max_len, "%sWARN%s%s:  ", color, reset, bold); break;
        case CYE_TRACE_ERROR: written = snprintf(buffer, max_len, "%sERROR%s%s: ", color, reset, bold); break;
        case CYE_LOG_FATAL: written = snprintf(buffer, max_len, "%sFATAL%s%s: ", color, reset, bold); break;
        case CYE_LOG_ALL: written = snprintf(buffer, max_len, "%sALL%s%s:   ", color, reset, bold); break;
        case CYE_LOG_NONE: return;
        default: do { fprintf(
# 3273 "./cye.h" 3 4
                stderr
# 3273 "./cye.h"
                , "%s:%d: %s UNREACHABLE: %s\n","./cye.h", 3273,__PRETTY_FUNCTION__, "cye_trace_log"); abort(); } while(0); break;
    }



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
    fflush(
# 3290 "./cye.h" 3 4
          stdout
# 3290 "./cye.h"
                );
    
# 3291 "./cye.h" 3 4
   __builtin_va_end(
# 3291 "./cye.h"
   args
# 3291 "./cye.h" 3 4
   )
# 3291 "./cye.h"
               ;


    if (CYE_LOG_FATAL == level) {
        exit(
# 3295 "./cye.h" 3 4
            1
# 3295 "./cye.h"
                        );
    }
}

void cye__assert_handler(char const *prefix, char const *condition, char const *file, int line, char const *msg, ...) {
    fprintf(
# 3300 "./cye.h" 3 4
           stderr
# 3300 "./cye.h"
                 , "%s:%d: %s: ", file, line, prefix);
    if (condition) {
        fprintf(
# 3302 "./cye.h" 3 4
               stderr
# 3302 "./cye.h"
                     , "`%s` ", condition);
    }
    if (msg) {
        va_list va;
        
# 3306 "./cye.h" 3 4
       __builtin_va_start(
# 3306 "./cye.h"
       va
# 3306 "./cye.h" 3 4
       ,
# 3306 "./cye.h"
       msg
# 3306 "./cye.h" 3 4
       )
# 3306 "./cye.h"
                        ;
        vfprintf(
# 3307 "./cye.h" 3 4
                stderr
# 3307 "./cye.h"
                      , msg, va);
        
# 3308 "./cye.h" 3 4
       __builtin_va_end(
# 3308 "./cye.h"
       va
# 3308 "./cye.h" 3 4
       )
# 3308 "./cye.h"
                 ;
    }
    fprintf(
# 3310 "./cye.h" 3 4
           stderr
# 3310 "./cye.h"
                 , "\n");
}

TString cye_file_stats_tstring(Cye_File_Stats stats) {
    return cye_tprintf("{.created_at=%s (%zu), .accessed_at=%s (%zu), .modified_at=%s (%zu), .size=%zu (bytes)}", strtok(ctime(&(stats).created_at), "\n"), (stats).created_at, strtok(ctime(&(stats).accessed_at), "\n"), (stats).accessed_at, strtok(ctime(&(stats).modified_at), "\n"), (stats).modified_at, (stats).size_bytes);
}

TString cye_str_slice_tstring(Cye_String_Slice ss) {
    return cye_tprintf("%.*s", (int)(ss).count, (ss).data);
}

TString cye_ds_tstring(Cye_DString ds) {
    return cye_tprintf("{.items=%.*s(%p), .count=%zu, .capacity=%zu}", (ds).count, (ds).items, (ds).items, (ds).count, (ds).capacity);
}

const char *cye_cpu_architecture() {

  return "x86_64";
# 3369 "./cye.h"
}
# 3 "./tests/making_files.c" 2

int main(void) {
    
# 5 "./tests/making_files.c" 3 4
   _Bool 
# 5 "./tests/making_files.c"
        result = 
# 5 "./tests/making_files.c" 3 4
                 0
# 5 "./tests/making_files.c"
                      ;
    
# 6 "./tests/making_files.c" 3 4
   _Bool 
# 6 "./tests/making_files.c"
        exists = 
# 6 "./tests/making_files.c" 3 4
                 0
# 6 "./tests/making_files.c"
                      ;

    ZString path = 
# 8 "./tests/making_files.c" 3 4
                  ((void *)0)
# 8 "./tests/making_files.c"
                      ;

    path = ({ Cye_Context before = cye_context; cye_context = cye_temp_context(); TString path = cye_path_create_from_array( ((const char*[]){"build/lmao.txt"}), (sizeof((const char *[]){"build/lmao.txt"}) / sizeof(const char *))); cye_context = before; path; });

    if (!cye_file_exists(path)) {
        ((void)((cye_make_dir_include_parents(cye_path_dir_of(path))) || (cye__assert_handler("Assertion Failure", "cye_make_dir_include_parents(cye_path_dir_of(path))", "./tests/making_files.c", (int)13, 
# 13 "./tests/making_files.c" 3 4
       ((void *)0)
# 13 "./tests/making_files.c"
       ), __builtin_trap(), 0)));
        cye_trace_log(CYE_LOG_INFO, "Touching `%s` because it doesn't exist yet", path);
        cye_path_touch(path);
    } else {

        Cye_File_Stats stats = {0};
        cye_trace_log(CYE_LOG_INFO, "Touching `%s` anyways, even though it already exists", path);
        {
            cye_file_stats(path, &stats);
            cye_trace_log(CYE_LOG_INFO, "Stats BEFORE" "{.created_at=%s (%zu), .accessed_at=%s (%zu), .modified_at=%s (%zu), .size=%zu (bytes)}", strtok(ctime(&(stats).created_at), "\n"), (stats).created_at, strtok(ctime(&(stats).accessed_at), "\n"), (stats).accessed_at, strtok(ctime(&(stats).modified_at), "\n"), (stats).modified_at, (stats).size_bytes);

            cye_path_touch(path);

            cye_file_stats(path, &stats);
            cye_trace_log(CYE_LOG_INFO, "Stats AFTER" "{.created_at=%s (%zu), .accessed_at=%s (%zu), .modified_at=%s (%zu), .size=%zu (bytes)}", strtok(ctime(&(stats).created_at), "\n"), (stats).created_at, strtok(ctime(&(stats).accessed_at), "\n"), (stats).accessed_at, strtok(ctime(&(stats).modified_at), "\n"), (stats).modified_at, (stats).size_bytes);
        }
    }

    {
        path = ({
            Cye_Context before = cye_context;
            cye_context = cye_temp_context();
            TString path = cye_path_create_from_array(((const char *[]){"build/appenditure.txt"}), (sizeof((const char *[]){"build/appenditure.txt"}) / sizeof(const char *)));
            cye_context = before;
            path;
        });
        cye_file_write_all(path, "LOOOOL", strlen("LOOOOL"));
        Cye_DString ds = {0};
        cye_file_read_all(path, &ds);
        cye_trace_log(CYE_LOG_INFO, _Generic ds, Cye_DString: "%.*s" "path=%s and its contents=", (ds).count, (ds).items, (ds).items, (ds).count, (ds).capacity);

        cye_file_append_zstr(path, " time to append");
        ds.count = 0;
        cye_file_read_all(path, &ds);

        exit(1);
    }

    {
        path = ({ Cye_Context before = cye_context; cye_context = cye_temp_context(); TString path = cye_path_create_from_array( ((const char*[]){"./build///", "tmp", "file.txt"}), (sizeof((const char *[]){"./build///", "tmp", "file.txt"}) / sizeof(const char *))); cye_context = before; path; });
        cye_make_dir_include_parents(cye_path_dir_of(path));
        cye_trace_log(CYE_LOG_INFO, "Current path `%s`", path);

        result = cye_file_write_all(path, 
# 50 "./tests/making_files.c" 3 4
                                     ((void *)0)
# 50 "./tests/making_files.c"
                                         , 0);
        cye_trace_log(CYE_LOG_INFO, "Current file_write_all result: %s", result ? "true" : "false");

        exists = cye_file_exists(path);
        cye_trace_log(CYE_LOG_INFO, "`%s` %s exists", path, exists ? "does" : "does NOT");

        result = cye_remove_file(path);
        cye_trace_log(CYE_LOG_INFO, "Current remove_file result: %s", result ? "true" : "false");

        exists = cye_file_exists(path);
        cye_trace_log(CYE_LOG_INFO, "`%s` %s exists", path, exists ? "does" : "does NOT");

        cye_remove_dir(cye_path_dir_of(path));
    }

    return 0;
}
