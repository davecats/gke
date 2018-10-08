/**/

#define _GNU_SOURCE
#define _FILE_OFFSET_BITS 64
#define _LARGE_FILES
#define printERR fprintf(stderr,"\r%s: PROGRAM HALTED  \n",errormessage);fflush(stderr)




#include <unistd.h>

#include <stdlib.h>
/*** typedef _Complex float __cfloat128 __attribute__ ((__mode__ (__TC__))); ununderstood ***/
/*** typedef __float128 _Float128; ununderstood ***/
/*** extern _Float128 strtof128 (const char *restrict __nptr,
			 char **restrict __endptr) ununderstood ***/
/*** extern _Float128 strtof128_l (const char *restrict __nptr,
			 char **restrict __endptr,
			 locale_t __loc) ununderstood ***/

#include <stdio.h>

#include <fcntl.h>

#include <math.h>
/*** enum ununderstood ***/
/*** {
 FP_INT_UPWARD =
0,
 FP_INT_DOWNWARD =
1,
 FP_INT_TOWARDZERO =
2,
 FP_INT_TONEARESTFROMZERO =
3,
 FP_INT_TONEAREST =
4,
 }; ununderstood ***/
/*** __DECL_SIMD_ cos     extern double  cos      (double __x) ;  extern double  __cos      (double __x) ; ununderstood ***/
/*** __DECL_SIMD_ sin     extern double  sin      (double __x) ;  extern double  __sin      (double __x) ; ununderstood ***/
/*** __DECL_SIMD_ sincos    extern void   sincos    ununderstood ***/
/*** (double __x, double *__sinx, double *__cosx) ;  extern void  __ sincos    ununderstood ***/
/*** (double __x, double *__sinx, double *__cosx) ; ununderstood ***/
/*** __DECL_SIMD_ exp     extern double  exp      (double __x) ;  extern double  __exp      (double __x) ; ununderstood ***/
/*** __DECL_SIMD_ log     extern double  log      (double __x) ;  extern double  __log      (double __x) ; ununderstood ***/
/*** __DECL_SIMD_ pow     extern double  pow      (double __x, double __y) ;  extern double  __pow      (double __x, double __y) ; ununderstood ***/
/*** && !0 ununderstood ***/
/*** && !0 ununderstood ***/
/*** __DECL_SIMD_ cosf     extern float  cosf      (float __x) ;  extern float  __cosf      (float __x) ; ununderstood ***/
/*** __DECL_SIMD_ sinf     extern float  sinf      (float __x) ;  extern float  __sinf      (float __x) ; ununderstood ***/
/*** __DECL_SIMD_ sincosf    extern void   sincosf    ununderstood ***/
/*** (float __x, float *__sinx, float *__cosx) ;  extern void  __ sincosf    ununderstood ***/
/*** (float __x, float *__sinx, float *__cosx) ; ununderstood ***/
/*** __DECL_SIMD_ expf     extern float  expf      (float __x) ;  extern float  __expf      (float __x) ; ununderstood ***/
/*** __DECL_SIMD_ logf     extern float  logf      (float __x) ;  extern float  __logf      (float __x) ; ununderstood ***/
/*** __DECL_SIMD_ powf     extern float  powf      (float __x, float __y) ;  extern float  __powf      (float __x, float __y) ; ununderstood ***/
/*** && !0 ununderstood ***/
/*** && !0 ununderstood ***/
/*** __DECL_SIMD_ cosl     extern long double  cosl      (long double __x) ;  extern long double  __cosl      (long double __x) ; ununderstood ***/
/*** __DECL_SIMD_ sinl     extern long double  sinl      (long double __x) ;  extern long double  __sinl      (long double __x) ; ununderstood ***/
/*** __DECL_SIMD_ sincosl    extern void   sincosl    ununderstood ***/
/*** (long double __x, long double *__sinx, long double *__cosx) ;  extern void  __ sincosl    ununderstood ***/
/*** (long double __x, long double *__sinx, long double *__cosx) ; ununderstood ***/
/*** __DECL_SIMD_ expl     extern long double  expl      (long double __x) ;  extern long double  __expl      (long double __x) ; ununderstood ***/
/*** __DECL_SIMD_ logl     extern long double  logl      (long double __x) ;  extern long double  __logl      (long double __x) ; ununderstood ***/
/*** __DECL_SIMD_ powl     extern long double  powl      (long double __x, long double __y) ;  extern long double  __powl      (long double __x, long double __y) ; ununderstood ***/
/*** && !0 ununderstood ***/
/*** && !0 ununderstood ***/
/*** __DECL_SIMD_ cosf32     extern _Float32  cosf32      (_Float32 __x) ;  extern _Float32  __cosf32      (_Float32 __x) ; ununderstood ***/
/*** __DECL_SIMD_ sinf32     extern _Float32  sinf32      (_Float32 __x) ;  extern _Float32  __sinf32      (_Float32 __x) ; ununderstood ***/
/*** __DECL_SIMD_ sincosf32    extern void   sincosf32    ununderstood ***/
/*** (_Float32 __x, _Float32 *__sinx, _Float32 *__cosx) ;  extern void  __ sincosf32    ununderstood ***/
/*** (_Float32 __x, _Float32 *__sinx, _Float32 *__cosx) ; ununderstood ***/
/*** __DECL_SIMD_ expf32     extern _Float32  expf32      (_Float32 __x) ;  extern _Float32  __expf32      (_Float32 __x) ; ununderstood ***/
/*** __DECL_SIMD_ logf32     extern _Float32  logf32      (_Float32 __x) ;  extern _Float32  __logf32      (_Float32 __x) ; ununderstood ***/
/*** __DECL_SIMD_ powf32     extern _Float32  powf32      (_Float32 __x, _Float32 __y) ;  extern _Float32  __powf32      (_Float32 __x, _Float32 __y) ; ununderstood ***/
/*** && !1 ununderstood ***/
/*** && !1 ununderstood ***/
/*** __DECL_SIMD_ cosf64     extern _Float64  cosf64      (_Float64 __x) ;  extern _Float64  __cosf64      (_Float64 __x) ; ununderstood ***/
/*** __DECL_SIMD_ sinf64     extern _Float64  sinf64      (_Float64 __x) ;  extern _Float64  __sinf64      (_Float64 __x) ; ununderstood ***/
/*** __DECL_SIMD_ sincosf64    extern void   sincosf64    ununderstood ***/
/*** (_Float64 __x, _Float64 *__sinx, _Float64 *__cosx) ;  extern void  __ sincosf64    ununderstood ***/
/*** (_Float64 __x, _Float64 *__sinx, _Float64 *__cosx) ; ununderstood ***/
/*** __DECL_SIMD_ expf64     extern _Float64  expf64      (_Float64 __x) ;  extern _Float64  __expf64      (_Float64 __x) ; ununderstood ***/
/*** __DECL_SIMD_ logf64     extern _Float64  logf64      (_Float64 __x) ;  extern _Float64  __logf64      (_Float64 __x) ; ununderstood ***/
/*** __DECL_SIMD_ powf64     extern _Float64  powf64      (_Float64 __x, _Float64 __y) ;  extern _Float64  __powf64      (_Float64 __x, _Float64 __y) ; ununderstood ***/
/*** && !1 ununderstood ***/
/*** && !1 ununderstood ***/
/*** extern _Float128  acosf128    (_Float128 __x) ;  extern _Float128  __acosf128    (_Float128 __x) ; ununderstood ***/
/*** extern _Float128  asinf128    (_Float128 __x) ;  extern _Float128  __asinf128    (_Float128 __x) ; ununderstood ***/
/*** extern _Float128  atanf128    (_Float128 __x) ;  extern _Float128  __atanf128    (_Float128 __x) ; ununderstood ***/
/*** extern _Float128  atan2f128    (_Float128 __y, _Float128 __x) ;  extern _Float128  __atan2f128    (_Float128 __y, _Float128 __x) ; ununderstood ***/
/*** __DECL_SIMD_ cosf128     extern _Float128  cosf128      (_Float128 __x) ;  extern _Float128  __cosf128      (_Float128 __x) ; ununderstood ***/
/*** __DECL_SIMD_ sinf128     extern _Float128  sinf128      (_Float128 __x) ;  extern _Float128  __sinf128      (_Float128 __x) ; ununderstood ***/
/*** extern _Float128  tanf128    (_Float128 __x) ;  extern _Float128  __tanf128    (_Float128 __x) ; ununderstood ***/
/*** extern _Float128  coshf128    (_Float128 __x) ;  extern _Float128  __coshf128    (_Float128 __x) ; ununderstood ***/
/*** extern _Float128  sinhf128    (_Float128 __x) ;  extern _Float128  __sinhf128    (_Float128 __x) ; ununderstood ***/
/*** extern _Float128  tanhf128    (_Float128 __x) ;  extern _Float128  __tanhf128    (_Float128 __x) ; ununderstood ***/
/*** __DECL_SIMD_ sincosf128    extern void   sincosf128    ununderstood ***/
/*** (_Float128 __x, _Float128 *__sinx, _Float128 *__cosx) ;  extern void  __ sincosf128    ununderstood ***/
/*** (_Float128 __x, _Float128 *__sinx, _Float128 *__cosx) ; ununderstood ***/
/*** extern _Float128  acoshf128    (_Float128 __x) ;  extern _Float128  __acoshf128    (_Float128 __x) ; ununderstood ***/
/*** extern _Float128  asinhf128    (_Float128 __x) ;  extern _Float128  __asinhf128    (_Float128 __x) ; ununderstood ***/
/*** extern _Float128  atanhf128    (_Float128 __x) ;  extern _Float128  __atanhf128    (_Float128 __x) ; ununderstood ***/
/*** __DECL_SIMD_ expf128     extern _Float128  expf128      (_Float128 __x) ;  extern _Float128  __expf128      (_Float128 __x) ; ununderstood ***/
/*** extern _Float128  frexpf128    (_Float128 __x, int *__exponent) ;  extern _Float128  __frexpf128    (_Float128 __x, int *__exponent) ; ununderstood ***/
/*** extern _Float128  ldexpf128    (_Float128 __x, int __exponent) ;  extern _Float128  __ldexpf128    (_Float128 __x, int __exponent) ; ununderstood ***/
/*** __DECL_SIMD_ logf128     extern _Float128  logf128      (_Float128 __x) ;  extern _Float128  __logf128      (_Float128 __x) ; ununderstood ***/
/*** extern _Float128  log10f128    (_Float128 __x) ;  extern _Float128  __log10f128    (_Float128 __x) ; ununderstood ***/
/*** extern _Float128  modff128    (_Float128 __x, _Float128 *__iptr) ;  extern _Float128  __modff128    (_Float128 __x, _Float128 *__iptr)  ; ununderstood ***/
/*** extern _Float128  exp10f128    (_Float128 __x) ;  extern _Float128  __exp10f128    (_Float128 __x) ; ununderstood ***/
/*** extern _Float128  expm1f128    (_Float128 __x) ;  extern _Float128  __expm1f128    (_Float128 __x) ; ununderstood ***/
/*** extern _Float128  log1pf128    (_Float128 __x) ;  extern _Float128  __log1pf128    (_Float128 __x) ; ununderstood ***/
/*** extern _Float128  logbf128    (_Float128 __x) ;  extern _Float128  __logbf128    (_Float128 __x) ; ununderstood ***/
/*** extern _Float128  exp2f128    (_Float128 __x) ;  extern _Float128  __exp2f128    (_Float128 __x) ; ununderstood ***/
/*** extern _Float128  log2f128    (_Float128 __x) ;  extern _Float128  __log2f128    (_Float128 __x) ; ununderstood ***/
/*** __DECL_SIMD_ powf128     extern _Float128  powf128      (_Float128 __x, _Float128 __y) ;  extern _Float128  __powf128      (_Float128 __x, _Float128 __y) ; ununderstood ***/
/*** extern _Float128  sqrtf128    (_Float128 __x) ;  extern _Float128  __sqrtf128    (_Float128 __x) ; ununderstood ***/
/*** extern _Float128  hypotf128    (_Float128 __x, _Float128 __y) ;  extern _Float128  __hypotf128    (_Float128 __x, _Float128 __y) ; ununderstood ***/
/*** extern _Float128  cbrtf128    (_Float128 __x) ;  extern _Float128  __cbrtf128    (_Float128 __x) ; ununderstood ***/
/*** extern _Float128  ceilf128    (_Float128 __x)  __attribute__ (  (__const__));  extern _Float128  __ceilf128    (_Float128 __x)  __attribute__ (  (__const__)); ununderstood ***/
/*** extern _Float128  fabsf128    (_Float128 __x)  __attribute__ (  (__const__));  extern _Float128  __fabsf128    (_Float128 __x)  __attribute__ (  (__const__)); ununderstood ***/
/*** extern _Float128  floorf128    (_Float128 __x)  __attribute__ (  (__const__));  extern _Float128  __floorf128    (_Float128 __x)  __attribute__ (  (__const__)); ununderstood ***/
/*** extern _Float128  fmodf128    (_Float128 __x, _Float128 __y) ;  extern _Float128  __fmodf128    (_Float128 __x, _Float128 __y) ; ununderstood ***/
/*** && !1 ununderstood ***/
/*** extern _Float128  copysignf128    (_Float128 __x, _Float128 __y)  __attribute__ (  (__const__));  extern _Float128  __copysignf128    (_Float128 __x, _Float128 __y)  __attribute__ (  (__const__)); ununderstood ***/
/*** extern _Float128  nanf128    (const char *__tagb) ;  extern _Float128  __nanf128    (const char *__tagb) ; ununderstood ***/
/*** && !1 ununderstood ***/
/*** extern _Float128  j0f128    (_Float128) ;  extern _Float128  __j0f128    (_Float128) ; ununderstood ***/
/*** extern _Float128  j1f128    (_Float128) ;  extern _Float128  __j1f128    (_Float128) ; ununderstood ***/
/*** extern _Float128  jnf128    (int, _Float128) ;  extern _Float128  __jnf128    (int, _Float128) ; ununderstood ***/
/*** extern _Float128  y0f128    (_Float128) ;  extern _Float128  __y0f128    (_Float128) ; ununderstood ***/
/*** extern _Float128  y1f128    (_Float128) ;  extern _Float128  __y1f128    (_Float128) ; ununderstood ***/
/*** extern _Float128  ynf128    (int, _Float128) ;  extern _Float128  __ynf128    (int, _Float128) ; ununderstood ***/
/*** extern _Float128  erff128    (_Float128) ;  extern _Float128  __erff128    (_Float128) ; ununderstood ***/
/*** extern _Float128  erfcf128    (_Float128) ;  extern _Float128  __erfcf128    (_Float128) ; ununderstood ***/
/*** extern _Float128  lgammaf128    (_Float128) ;  extern _Float128  __lgammaf128    (_Float128) ; ununderstood ***/
/*** extern _Float128  tgammaf128    (_Float128) ;  extern _Float128  __tgammaf128    (_Float128) ; ununderstood ***/
/*** extern _Float128  lgammaf128_r    (_Float128, int *__signgamp) ;  extern _Float128  __lgammaf128_r    (_Float128, int *__signgamp) ; ununderstood ***/
/*** extern _Float128  rintf128    (_Float128 __x) ;  extern _Float128  __rintf128    (_Float128 __x) ; ununderstood ***/
/*** extern _Float128  nextafterf128    (_Float128 __x, _Float128 __y) ;  extern _Float128  __nextafterf128    (_Float128 __x, _Float128 __y) ; ununderstood ***/
/*** extern _Float128  nextdownf128    (_Float128 __x) ;  extern _Float128  __nextdownf128    (_Float128 __x) ; ununderstood ***/
/*** extern _Float128  nextupf128    (_Float128 __x) ;  extern _Float128  __nextupf128    (_Float128 __x) ; ununderstood ***/
/*** extern _Float128  remainderf128    (_Float128 __x, _Float128 __y) ;  extern _Float128  __remainderf128    (_Float128 __x, _Float128 __y) ; ununderstood ***/
/*** extern _Float128  scalbnf128    (_Float128 __x, int __n) ;  extern _Float128  __scalbnf128    (_Float128 __x, int __n) ; ununderstood ***/
/*** extern _Float128  scalblnf128    (_Float128 __x, long int __n) ;  extern _Float128  __scalblnf128    (_Float128 __x, long int __n) ; ununderstood ***/
/*** extern _Float128  nearbyintf128    (_Float128 __x) ;  extern _Float128  __nearbyintf128    (_Float128 __x) ; ununderstood ***/
/*** extern _Float128  roundf128    (_Float128 __x)  __attribute__ (  (__const__));  extern _Float128  __roundf128    (_Float128 __x)  __attribute__ (  (__const__)); ununderstood ***/
/*** extern _Float128  truncf128    (_Float128 __x)  __attribute__ (  (__const__));  extern _Float128  __truncf128    (_Float128 __x)  __attribute__ (  (__const__)); ununderstood ***/
/*** extern _Float128  remquof128    (_Float128 __x, _Float128 __y, int *__quo) ;  extern _Float128  __remquof128    (_Float128 __x, _Float128 __y, int *__quo) ; ununderstood ***/
/*** extern _Float128  fdimf128    (_Float128 __x, _Float128 __y) ;  extern _Float128  __fdimf128    (_Float128 __x, _Float128 __y) ; ununderstood ***/
/*** extern _Float128  fmaxf128    (_Float128 __x, _Float128 __y)  __attribute__ (  (__const__));  extern _Float128  __fmaxf128    (_Float128 __x, _Float128 __y)  __attribute__ (  (__const__)); ununderstood ***/
/*** extern _Float128  fminf128    (_Float128 __x, _Float128 __y)  __attribute__ (  (__const__));  extern _Float128  __fminf128    (_Float128 __x, _Float128 __y)  __attribute__ (  (__const__)); ununderstood ***/
/*** extern _Float128  fmaf128    (_Float128 __x, _Float128 __y, _Float128 __z) ;  extern _Float128  __fmaf128    (_Float128 __x, _Float128 __y, _Float128 __z) ; ununderstood ***/
/*** extern _Float128  roundevenf128    (_Float128 __x)  __attribute__ (  (__const__));  extern _Float128  __roundevenf128    (_Float128 __x)  __attribute__ (  (__const__)); ununderstood ***/
/*** extern _Float128  fmaxmagf128    (_Float128 __x, _Float128 __y)  __attribute__ (  (__const__));  extern _Float128  __fmaxmagf128    (_Float128 __x, _Float128 __y)  __attribute__ (  (__const__)); ununderstood ***/
/*** extern _Float128  fminmagf128    (_Float128 __x, _Float128 __y)  __attribute__ (  (__const__));  extern _Float128  __fminmagf128    (_Float128 __x, _Float128 __y)  __attribute__ (  (__const__)); ununderstood ***/
/*** extern _Float128  getpayloadf128    (const _Float128 *__x) ;  extern _Float128  __getpayloadf128    (const _Float128 *__x) ; ununderstood ***/
/*** extern _Float128  scalbf128    (_Float128 __x, _Float128 __n) ;  extern _Float128  __scalbf128    (_Float128 __x, _Float128 __n) ; ununderstood ***/
/*** __DECL_SIMD_ cosf32x     extern _Float32x  cosf32x      (_Float32x __x) ;  extern _Float32x  __cosf32x      (_Float32x __x) ; ununderstood ***/
/*** __DECL_SIMD_ sinf32x     extern _Float32x  sinf32x      (_Float32x __x) ;  extern _Float32x  __sinf32x      (_Float32x __x) ; ununderstood ***/
/*** __DECL_SIMD_ sincosf32x    extern void   sincosf32x    ununderstood ***/
/*** (_Float32x __x, _Float32x *__sinx, _Float32x *__cosx) ;  extern void  __ sincosf32x    ununderstood ***/
/*** (_Float32x __x, _Float32x *__sinx, _Float32x *__cosx) ; ununderstood ***/
/*** __DECL_SIMD_ expf32x     extern _Float32x  expf32x      (_Float32x __x) ;  extern _Float32x  __expf32x      (_Float32x __x) ; ununderstood ***/
/*** __DECL_SIMD_ logf32x     extern _Float32x  logf32x      (_Float32x __x) ;  extern _Float32x  __logf32x      (_Float32x __x) ; ununderstood ***/
/*** __DECL_SIMD_ powf32x     extern _Float32x  powf32x      (_Float32x __x, _Float32x __y) ;  extern _Float32x  __powf32x      (_Float32x __x, _Float32x __y) ; ununderstood ***/
/*** && !1 ununderstood ***/
/*** && !1 ununderstood ***/
/*** __DECL_SIMD_ cosf64x     extern _Float64x  cosf64x      (_Float64x __x) ;  extern _Float64x  __cosf64x      (_Float64x __x) ; ununderstood ***/
/*** __DECL_SIMD_ sinf64x     extern _Float64x  sinf64x      (_Float64x __x) ;  extern _Float64x  __sinf64x      (_Float64x __x) ; ununderstood ***/
/*** __DECL_SIMD_ sincosf64x    extern void   sincosf64x    ununderstood ***/
/*** (_Float64x __x, _Float64x *__sinx, _Float64x *__cosx) ;  extern void  __ sincosf64x    ununderstood ***/
/*** (_Float64x __x, _Float64x *__sinx, _Float64x *__cosx) ; ununderstood ***/
/*** __DECL_SIMD_ expf64x     extern _Float64x  expf64x      (_Float64x __x) ;  extern _Float64x  __expf64x      (_Float64x __x) ; ununderstood ***/
/*** __DECL_SIMD_ logf64x     extern _Float64x  logf64x      (_Float64x __x) ;  extern _Float64x  __logf64x      (_Float64x __x) ; ununderstood ***/
/*** __DECL_SIMD_ powf64x     extern _Float64x  powf64x      (_Float64x __x, _Float64x __y) ;  extern _Float64x  __powf64x      (_Float64x __x, _Float64x __y) ; ununderstood ***/
/*** && !1 ununderstood ***/
/*** && !1 ununderstood ***/

#include <limits.h>

#include <float.h>

#include <string.h>


#include <sys/time.h>
/*** typedef struct timezone *restrict __timezone_ptr_t; ununderstood ***/

#include <sys/types.h>

#include <setjmp.h>

#include <errno.h>

#include <signal.h>
#if defined nofenv
  #define feenableexcept(fpe)
  #define feclearexcept(fpe)
#else
  #include <fenv.h>
  #define fpe FE_INVALID | FE_OVERFLOW | FE_DIVBYZERO
#endif

char errortemp_[(80+1)];


struct arrptr{int l,h; ssize_t i; char *a;};
struct dynptr{void* p; int t;};
char INTERRUPT=0;
void (*traphandler)(const char *);
struct freefunc{struct freefunc *next; void (*f)(void *); void *ptr;};
struct freefunc *freestack;
#define freemem(upto) while(freestack!=upto){freestack->f(freestack->ptr); freestack=freestack->next;}
#define atblockexit(name,func,p) name.f=func;name.ptr=p;name.next=freestack;freestack=&name
void traprestore(void *ptr){traphandler=ptr;}
void condfree(void *ptr){if(ptr)free(ptr);}
int dynptrerr(int type){
  snprintf(errortemp_,sizeof(errortemp_),"Argument of incompatible TYPE %d",type);
  traphandler(errortemp_);
}
void *errmalloc(){
  traphandler("Not enough memory");
}
void ioerr(FILE *fil){
  char where[11];
  off_t cn;
  int fn;
  fn=fileno(fil);
  cn=ftello(fil);
  if(ferror(fil)){
    snprintf(errortemp_,sizeof(errortemp_),"%s in fd %d char %ld",strerror(errno),fn,(long)cn);
  } else if(feof(fil)){
    snprintf(errortemp_,sizeof(errortemp_),"End of file in fd %d char %ld",fn,(long)cn);
  } else {
    if(cn>=0) fscanf(fil,"%10s",where); else where[0]=0;
    snprintf(errortemp_,sizeof(errortemp_),"Unrecognized input \"%s\" from fd %d char %ld",where,fn,(long)cn);
  }
  traphandler(errortemp_);
}
void errfclose(void *voidf){
  FILE **f=(FILE **)voidf;
  int fn;
  if(*f==NULL)return;
  fn=fileno(*f);
  if(fn>=0 && ftell(*f)>=0 && fclose(*f)!=0){
    snprintf(errortemp_,sizeof(errortemp_),"Error in closing fd %d: %s",fn,strerror(errno));
    traphandler(errortemp_);
    }
  *f=NULL;
}
void errfopen(FILE **f, const char *name, int mode){
  int fd;
  if(*f)errfclose(f);
  fd=open(name,mode,0666);
  if(fd>0 || mode==O_RDONLY){
    *f=fdopen(fd,mode==O_RDONLY?"r":"r+");
    if(*f!=NULL || mode==O_RDONLY)return;
    } 
  snprintf(errortemp_,sizeof(errortemp_),"Error in opening %s: %s",name,strerror(errno));
  traphandler(errortemp_);
}
int scanrec(FILE *f, const char *format, void *var) {
  off_t pos; int res;
  register int c;
  pos=ftello(f);
  while(!feof(f)&&(c=getc(f))<=' '&&(c!='\n')){};
  if(c!='\n')ungetc(c,f);
  while((c=getc(f))=='!') {while(!feof(f)&&getc(f)!='\n'){};};
  ungetc(c,f);
  res=fscanf(f,format,var);
  if (res<=0) fseeko(f,pos,SEEK_SET);
  return res;
}
int myfgets(char *name, char *var, char *varend, FILE *f) {
  off_t pos;
  register int c;
  pos=ftello(f);
  while(*name!=0){
    if(*name==' '){while((c=getc(f))<=' '){};ungetc(c,f);} else
    if(*name!=getc(f)){fseeko(f,pos,SEEK_SET);return 0;};
    name++;
  };
  if(var<varend){
    do{c=getc(f); *var=c;}while(c!=EOF && c!='\n' && ++var < varend);
    *var=0;
  }
  return 1;
}
int mygetline(char *name, char **var, FILE *f) {
  off_t pos;
  int c,oldc;
  pos=ftello(f);
  while(*name!=0){
    if(*name==' '){while((c=getc(f))<=' '){};ungetc(c,f);} else
    if(*name!=getc(f)){fseeko(f,pos,SEEK_SET);return 0;};
    name++;
  };
  c=32; oldc=0;
  while(1){
  *var=realloc(*var,c);
  if (fgets(*var+oldc,c,f)==NULL) {fseeko(f,pos,SEEK_SET);return 0;};
  {char* c1=strchr(*var,'\n'); if(c1) {*c1=0; return 1;}}
  oldc=c; c=2*c;
  }
  /*
  c=0;
  getline(var,&c,f);
  {char* c1=strchr(*var,'\n'); if(c1) *c1=0;}
  return 1;
  */
}
void trapsignal(int signum){
  if(signum==SIGINT) traphandler(&INTERRUPT); else {
    feclearexcept(fpe);
/* #if defined __linux__ */
    traphandler(strsignal(signum));
/*
#else
    snprintf(errortemp_,sizeof(errortemp_),"SIGNAL %d",signum);
    traphandler(errortemp_);
#endif
*/
  }
}
#if (defined __i386__ || defined __x86_64__)
#define mmovefrom(var,buf,type) *(type *)(buf)=*var
#define mmoveto(var,buf,type) *var=*(type *)(buf)
#else
#define mmovefrom(var,buf,type) memmove(buf,var,sizeof(type))
#define mmoveto(var,buf,type) memmove(var,buf,sizeof(type))
#endif
#define mainstart \
void default_traphandler(const char *errormessage){ \
  freemem(NULL); \
  if(errormessage[0]){ \
    printERR; \
    exit(EXIT_FAILURE); \
  }else exit(EXIT_SUCCESS); \
} \
int main(int argc, char **argv){ \
struct freefunc* es; \
{void (*sig)(int); \
if((sig=signal(SIGSEGV,trapsignal))!=SIG_DFL)signal(SIGSEGV,sig); \
if((sig=signal(SIGFPE,trapsignal))!=SIG_DFL)signal(SIGFPE,sig); \
if((sig=signal(SIGILL,trapsignal))!=SIG_DFL)signal(SIGILL,sig); \
if((sig=signal(SIGINT,trapsignal))!=SIG_DFL)signal(SIGINT,sig); \
else {traphandler=default_traphandler; \
      freestack=NULL; \
      feenableexcept(fpe); \
     }; \
} \
es=freestack;







/*! INTEGER LIBRARY FUNCTION INTEGER[(int)rint](REAL x)*/
/*! INTEGER LIBRARY FUNCTION int[(int)](REAL x)*/





/*!( to-do list
1) modificare STRUCTURED ARRAY in modo da evitare malloc quando possibile
2) separare il #define CPL da quello C
!)*/
/*! */
/*! This program computes and stores the single-point budgets of the Reynolds */
/*! stress tensor. Some terms are used to compute the Generalized Kolmogorov Equation (GKE)*/
/*!*/
/*! Copyright (C) 2018  Dr. Davide Gatti*/
/*!*/
/*! This program is free software: you can redistribute it and/or modify*/
/*! it under the terms of the GNU General Public License as published by*/
/*! the Free Software Foundation, either version 3 of the License, or*/
/*! any later version.*/
/*!*/
/*! This program is distributed in the hope that it will be useful,*/
/*! but WITHOUT ANY WARRANTY; without even the implied warranty of*/
/*! MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the*/
/*! GNU General Public License for more details.*/
/*!*/
/*! You should have received a copy of the GNU General Public License*/
/*! along with this program.  If not, see <https://www.gnu.org/licenses/>.*/
/*!*/
/*! Contacts:*/
/*!*/
/*! Dr. Davide Gatti  */
/*! davide.gatti [at] kit.edu*/
/*! msc.davide.gatti [at] gmail.com*/
/*! */
/*! Karlsruhe Institute of Technology*/
/*! Institute of Fluid Dynamics*/
/*! KaiserstraCe 10*/
/*! 76131 Karlsruhe */
/*! */

/*! */
/*! Data structures for the parallel computation */
/*! of the Generalized Kolmogorov Equation (GKE)*/
/*!*/
/*! Copyright (C) 2018  Dr. Davide Gatti*/
/*!*/
/*! This program is free software: you can redistribute it and/or modify*/
/*! it under the terms of the GNU General Public License as published by*/
/*! the Free Software Foundation, either version 3 of the License, or*/
/*! any later version.*/
/*!*/
/*! This program is distributed in the hope that it will be useful,*/
/*! but WITHOUT ANY WARRANTY; without even the implied warranty of*/
/*! MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the*/
/*! GNU General Public License for more details.*/
/*!*/
/*! You should have received a copy of the GNU General Public License*/
/*! along with this program.  If not, see <https://www.gnu.org/licenses/>.*/
/*!*/
/*! Contacts:*/
/*!*/
/*! Dr. Davide Gatti  */
/*! davide.gatti [at] kit.edu*/
/*! msc.davide.gatti [at] gmail.com*/
/*! */
/*! Karlsruhe Institute of Technology*/
/*! Institute of Fluid Dynamics*/
/*! KaiserstraCe 10*/
/*! 76131 Karlsruhe */
/*! */

struct COMPLEX_{double REAL_;double IMAG_;};void complex_1INV(struct COMPLEX_ *RESULT_,double x_REAL,double x_IMAG);
void complex_2EXP(struct COMPLEX_ *RESULT_,double x_REAL,double x_IMAG);
void complex_3SINH(struct COMPLEX_ *RESULT_,double x_REAL,double x_IMAG);
void complex_4COSH(struct COMPLEX_ *RESULT_,double x_REAL,double x_IMAG);
void complex_5TANH(struct COMPLEX_ *RESULT_,double x_REAL,double x_IMAG);
void complex_6COTH(struct COMPLEX_ *RESULT_,double x_REAL,double x_IMAG);
void complex_7LOG(struct COMPLEX_ *RESULT_,double x_REAL,double x_IMAG);
void complex_8POWER(struct COMPLEX_ *RESULT_,double x_REAL,double x_IMAG,double y_REAL,double y_IMAG);
void complex_9SQRT(struct COMPLEX_ *RESULT_,double x_REAL,double x_IMAG);
void complex_10ACOS(struct COMPLEX_ *RESULT_,double x_REAL,double x_IMAG);
void complex_11CRAND(struct COMPLEX_ *RESULT_);
void complex_12CGAUSS(struct COMPLEX_ *RESULT_);


void fft_1IFT(const int Rin_l,const int Rin_h,const ssize_t Rin_i,char *Rin__,const int Rout_l,const int Rout_h,const ssize_t Rout_i,char *Rout__);
void fft_2FFT(const int Rin_l,const int Rin_h,const ssize_t Rin_i,char *Rin__,const int Rout_l,const int Rout_h,const ssize_t Rout_i,char *Rout__);
void fft_3RFT(const int Rin_l,const int Rin_h,const ssize_t Rin_i,char *Rin__,const int Rout_l,const int Rout_h,const ssize_t Rout_i,char *Rout__);
void fft_4HFT(const int Rin_l,const int Rin_h,const ssize_t Rin_i,char *Rin__,const int Rout_l,const int Rout_h,const ssize_t Rout_i,char *Rout__);
void fft_5IFTU(const int Rin_l,const int Rin_h,const ssize_t Rin_i,char *Rin__,const int Rout_l,const int Rout_h,const ssize_t Rout_i,char *Rout__);
void fft_6FFTU(const int Rin_l,const int Rin_h,const ssize_t Rin_i,char *Rin__,const int Rout_l,const int Rout_h,const ssize_t Rout_i,char *Rout__);
void fft_7RFTU(const int Rin_l,const int Rin_h,const ssize_t Rin_i,char *Rin__,const int Rout_l,const int Rout_h,const ssize_t Rout_i,char *Rout__);
void fft_8HFTU(const int Rin_l,const int Rin_h,const ssize_t Rin_i,char *Rin__,const int Rout_l,const int Rout_h,const ssize_t Rout_i,char *Rout__);

int fft_9FFTfit(int N_);
void fft_fft_10ReverseInc(int *K_,int N_);
extern int fft_fft_LASTN;
extern struct arrptr fft_fft_CEXP;
extern struct arrptr fft_fft_tempVEC;
extern struct arrptr fft_fft_RI;
extern char *fft_fft_RI2;
extern char *fft_fft_RI3;
void fft_fft_11SETUP(int N_);
extern double fft_fft_12C3;
/*C3=fft_fft_12C3*/
void fft_fft_13BTFLY(int N_,int M_);
void fft_fft_14BTFLYI(int N_);
void fft_1IFT(const int Rin_l,const int Rin_h,const ssize_t Rin_i,char *Rin__,const int Rout_l,const int Rout_h,const ssize_t Rout_i,char *Rout__);
void fft_2FFT(const int Rin_l,const int Rin_h,const ssize_t Rin_i,char *Rin__,const int Rout_l,const int Rout_h,const ssize_t Rout_i,char *Rout__);
void fft_3RFT(const int Rin_l,const int Rin_h,const ssize_t Rin_i,char *Rin__,const int Rout_l,const int Rout_h,const ssize_t Rout_i,char *Rout__);
void fft_4HFT(const int Rin_l,const int Rin_h,const ssize_t Rin_i,char *Rin__,const int Rout_l,const int Rout_h,const ssize_t Rout_i,char *Rout__);
void fft_5IFTU(const int Rin_l,const int Rin_h,const ssize_t Rin_i,char *Rin__,const int Rout_l,const int Rout_h,const ssize_t Rout_i,char *Rout__);
void fft_6FFTU(const int Rin_l,const int Rin_h,const ssize_t Rin_i,char *Rin__,const int Rout_l,const int Rout_h,const ssize_t Rout_i,char *Rout__);
void fft_7RFTU(const int Rin_l,const int Rin_h,const ssize_t Rin_i,char *Rin__,const int Rout_l,const int Rout_h,const ssize_t Rout_i,char *Rout__);
void fft_8HFTU(const int Rin_l,const int Rin_h,const ssize_t Rin_i,char *Rin__,const int Rout_l,const int Rout_h,const ssize_t Rout_i,char *Rout__);
double *fft_15REALIFIED(const int x_l,const int x_h,const ssize_t x_i,char *x__,int y_);

double DotProduct(const int a_l,const int a_h,const ssize_t a_i,char *a__,const int b_l,const int b_h,const ssize_t b_i,char *b__);
void rbmat_1LeftMult(const int c_l,const int c_h,const ssize_t c_i,char *c__,const int A_l,const int A_h,const ssize_t A_i,const int A__l,const int A__h,const ssize_t A__i,char *A___,const int b_l,const int b_h,const ssize_t b_i,char *b__);
void RightMult(const int c_l,const int c_h,const ssize_t c_i,char *c__,const int a_l,const int a_h,const ssize_t a_i,char *a__,const int B_l,const int B_h,const ssize_t B_i,const int B__l,const int B__h,const ssize_t B__i,char *B___);
struct REALINVMAT_{int lo_;int hi_;};void rbmat_2MatEqu(const int c_l,const int c_h,const ssize_t c_i,const int c__l,const int c__h,const ssize_t c__i,char *c___,double a_);
void rbmat_3MatEqu(FILE *c_f,const int c_l,const int c_h,const ssize_t c_i,const int c__l,const int c__h,const ssize_t c__i,off_t c___,double a_);
void rbmat_4LeftMult(const int c_l,const int c_h,const ssize_t c_i,char *c__,FILE *A_f,const int A_l,const int A_h,const ssize_t A_i,const int A__l,const int A__h,const ssize_t A__i,off_t A___,const int b_l,const int b_h,const ssize_t b_i,char *b__);
void rbmat_5RightMult(const int c_l,const int c_h,const ssize_t c_i,char *c__,const int a_l,const int a_h,const ssize_t a_i,char *a__,FILE *B_f,const int B_l,const int B_h,const ssize_t B_i,const int B__l,const int B__h,const ssize_t B__i,off_t B___);
void rbmat_6LUdecomp(const int AA_l,const int AA_h,const ssize_t AA_i,const int AA__l,const int AA__h,const ssize_t AA__i,char *AA___);
void rbmat_7LUdecomp(FILE *A_f,const int A_l,const int A_h,const ssize_t A_i,const int A__l,const int A__h,const ssize_t A__i,off_t A___);
void rbmat_8LeftLDiv(const int x_l,const int x_h,const ssize_t x_i,char *x__,const int A_l,const int A_h,const ssize_t A_i,const int A__l,const int A__h,const ssize_t A__i,char *A___,const int t_l,const int t_h,const ssize_t t_i,char *t__);
void rbmat_9LeftUDiv(const int x_l,const int x_h,const ssize_t x_i,char *x__,const int A_l,const int A_h,const ssize_t A_i,const int A__l,const int A__h,const ssize_t A__i,char *A___,const int t_l,const int t_h,const ssize_t t_i,char *t__);
void rbmat_10LeftLUDiv(const int x_l,const int x_h,const ssize_t x_i,char *x__,FILE *A_f,const int A_l,const int A_h,const ssize_t A_i,const int A__l,const int A__h,const ssize_t A__i,off_t A___,const int t_l,const int t_h,const ssize_t t_i,char *t__);
void rbmat_11RightLUDiv(const int x_l,const int x_h,const ssize_t x_i,char *x__,const int t_l,const int t_h,const ssize_t t_i,char *t__,const int A_l,const int A_h,const ssize_t A_i,const int A__l,const int A__h,const ssize_t A__i,char *A___);
void rbmat_12RightLUDiv(const int x_l,const int x_h,const ssize_t x_i,char *x__,const int t_l,const int t_h,const ssize_t t_i,char *t__,FILE *A_f,const int A_l,const int A_h,const ssize_t A_i,const int A__l,const int A__h,const ssize_t A__i,off_t A___);
extern double Lanczos_norm_;
void rbmat_13Lanczos(const int x_l,const int x_h,const ssize_t x_i,char *x__,void (*A_)(const int v2_l,const int v2_h,const ssize_t v2_i,char *v2__,const int v1_l,const int v1_h,const ssize_t v1_i,char *v1__),void (*AT_)(const int v2_l,const int v2_h,const ssize_t v2_i,char *v2__,const int v1_l,const int v1_h,const ssize_t v1_i,char *v1__),const int y1_l,const int y1_h,const ssize_t y1_i,char *y1__,double eps_);
void rbmat_14PLU(const int m_l,const int m_h,const ssize_t m_i,const int m__l,const int m__h,const ssize_t m__i,char *m___,struct REALINVMAT_ *RESULT_);
void rbmat_15LeftLUDiv(const int x_l,const int x_h,const ssize_t x_i,char *x__,struct REALINVMAT_ *m_,const int t_l,const int t_h,const ssize_t t_i,char *t__);
void rbmat_16RightLUDiv(const int x_l,const int x_h,const ssize_t x_i,char *x__,const int t_l,const int t_h,const ssize_t t_i,char *t__,struct REALINVMAT_ *m_);
void rbmat_17INV(const int mat_l,const int mat_h,const ssize_t mat_i,const int mat__l,const int mat__h,const ssize_t mat__i,char *mat___,const int RESULT_l,const int RESULT_h,const ssize_t RESULT_i,const int RESULT__l,const int RESULT__h,const ssize_t RESULT__i,char *RESULT___);
double rbmat_18DET(const int mat_l,const int mat_h,const ssize_t mat_i,const int mat__l,const int mat__h,const ssize_t mat__i,char *mat___);
void rbmat_19Lanczos(const int x_l,const int x_h,const ssize_t x_i,char *x__,const int mat_l,const int mat_h,const ssize_t mat_i,const int mat__l,const int mat__h,const ssize_t mat__i,char *mat___,const int y_l,const int y_h,const ssize_t y_i,char *y__,double eps_);

struct rbmat_Lanczos_R_s20 {int l,h; ssize_t i;struct arrptr a;};
extern struct rbmat_Lanczos_R_s20 rbmat_Lanczos_R_Lanczos_mat;
void rbmat_Lanczos_R_21A(const int v2_l,const int v2_h,const ssize_t v2_i,char *v2__,const int v1_l,const int v1_h,const ssize_t v1_i,char *v1__);
void rbmat_Lanczos_R_22AT(const int v2_l,const int v2_h,const ssize_t v2_i,char *v2__,const int v1_l,const int v1_h,const ssize_t v1_i,char *v1__);
void rbmat_19Lanczos(const int x_l,const int x_h,const ssize_t x_i,char *x__,const int mat_l,const int mat_h,const ssize_t mat_i,const int mat__l,const int mat__h,const ssize_t mat__i,char *mat___,const int y_l,const int y_h,const ssize_t y_i,char *y__,double eps_);


#include <sys/mman.h>

#include <sys/wait.h>

#include <sys/shm.h>


#define SHMPAGE 4194304
extern size_t shmavail;extern char *shmaddr;extern void *shmalloc(size_t size);extern sigset_t oldmask;extern void donothing(int signum);extern void setup_signal_USR1();


#include <sys/socket.h>

#include <netinet/in.h>

#include <netinet/tcp.h>

#include <netdb.h>
extern int tcpserver(uint16_t port)
;extern int tcpclient(const char *hostname, uint16_t port) 
;extern int udpsocket(uint16_t myport, const char *hostname, uint16_t hostport) 
;

void barrier_free(void * ptr);
extern struct freefunc barrier_f;extern volatile int *barrier_;


/*! Parameters*/
/*! -----------------------------*/
/*nsmp=32*/
/*nfmin=20*/
/*nfmax=36*/
/*dn=2*/
char* path_;
extern double gkedata_1uLx1;
/*uLx1=gkedata_1uLx1*/
/*uLx2=0.5*/
/*uLz1=gkedata_1uLx1*/
/*uLz2=0.5*/
extern int nftot_;
extern int ismp_;
extern int iproc_;
extern int nproc_;
/*bufsize=800*/
/*baseport=(IPPORT_USERRESERVED+111)*/
extern struct freefunc prev_f;extern FILE *prev_;
extern struct freefunc next_f;extern FILE *next_;
extern int ny_;
extern int nx_;
extern int nz_;
extern double alfa0_;
extern double beta0_;
extern double a_;
extern double ymin_;
extern double ymax_;
extern double t_max_;
extern double dt_field_;
extern double dt_save_;
extern double u_conv_;
extern double u0_;
extern double un_;
extern double w_conv_;
extern double w0_;
extern double wn_;
extern double t0_;
extern double tn_;
extern double ni_;
extern double pr_;
extern double gr_;
extern double meanpx_;
extern double meanpz_;
extern double meanflowx_;
extern double meanflowz_;
extern double px_;
extern double corrpx_;
extern double pz_;
extern double corrpz_;
extern double flowx_;
extern double flowz_;
extern double deltat_;
extern double cflmax_;
extern double time_;
extern int time_from_restart_;
extern struct freefunc restart_file_f;extern char *restart_file_;
extern struct freefunc in_data_f;extern FILE *in_data_;
char c;
extern int gkedata_2h;
extern ssize_t gkedata_3i;
extern ssize_t gkedata_4st;
extern struct freefunc y_f;extern char *y_;
extern ssize_t gkedata_6st;
struct gkedata_s5{char d1_[(ssize_t)sizeof(double)*(2-(-2)+1)];char d2_[(ssize_t)sizeof(double)*(2-(-2)+1)];};extern int gkedata_7h;
extern ssize_t gkedata_8i;
extern ssize_t gkedata_9st;
extern struct freefunc derivs_f;extern char *derivs_;
extern int gkedata_12nyl;
/*nyl=gkedata_12nyl*/
extern int gkedata_13nyh;
/*nyh=gkedata_13nyh*/
extern int nxd_;
extern int nzd_;
extern int gkedata_14l;
extern int gkedata_15h;
extern ssize_t gkedata_16i;
extern ssize_t gkedata_17st;
extern struct freefunc izdV_f;extern char *izdV_;
extern int gkedata_18nxc;
/*nxc=gkedata_18nxc*/
extern int gkedata_19nzc;
/*nzc=gkedata_19nzc*/
extern double gkedata_20dx;
/*dx=gkedata_20dx*/
extern double gkedata_21dz;
/*dz=gkedata_21dz*/
struct GKETERMS_{char phiR_[(ssize_t)sizeof(double)*3];double phiC_;double scaleENER_;double scalePROD_;};struct MEANTERMS_{double U_;double W_;double Uy_;double Wy_;double Uyy_;double Wyy_;double P_;};struct MKETERMS_{double pump_;double produv_;double prodvw_;double ttrsp_;double vdiff_;double dissU_;double dissW_;double PHIttrsp_;double PHIvdiff_;};struct BALANCE_{char var_[(ssize_t)sizeof(double)*6];char prod_[(ssize_t)sizeof(double)*6];char psdiss_[(ssize_t)sizeof(double)*6];char ttrsp_[(ssize_t)sizeof(double)*6];char vdiff_[(ssize_t)sizeof(double)*6];char pstrain_[(ssize_t)sizeof(double)*6];char ptrsp_[(ssize_t)sizeof(double)*6];char PHIttrsp_[(ssize_t)sizeof(double)*6];char PHIvdiff_[(ssize_t)sizeof(double)*6];char PHIptrsp_[(ssize_t)sizeof(double)*6];};void mean_free(void * ptr);
extern struct freefunc mean_f;extern char *mean_;
void uiuj_free(void * ptr);
extern struct freefunc uiuj_f;extern char *uiuj_;
extern int gkedata_24h;
extern int gkedata_25l;
extern int gkedata_26h;
extern ssize_t gkedata_27i;
extern ssize_t gkedata_28i;
extern ssize_t gkedata_29st;
void p_free(void * ptr);
extern struct freefunc p_f;extern char *p_;
extern int gkedata_30h;
extern int gkedata_31l;
extern int gkedata_32h;
extern ssize_t gkedata_33i;
extern ssize_t gkedata_34i;
extern ssize_t gkedata_35st;
void V_free(void * ptr);
extern struct freefunc V_f;extern char *V_;
extern int gkedata_36h;
extern int gkedata_37h;
extern int gkedata_38l;
extern int gkedata_39h;
extern ssize_t gkedata_40i;
extern ssize_t gkedata_41i;
extern ssize_t gkedata_42i;
extern ssize_t gkedata_43st;
extern ssize_t gkedata_44st;
void Vtot_free(void * ptr);
extern struct freefunc Vtot_f;extern char *Vtot_;
extern int gkedata_45h;
extern int gkedata_46h;
extern int gkedata_47l;
extern int gkedata_48h;
extern ssize_t gkedata_49i;
extern ssize_t gkedata_50i;
extern ssize_t gkedata_51i;
extern ssize_t gkedata_52st;
extern ssize_t gkedata_53st;
void ptot_free(void * ptr);
extern struct freefunc ptot_f;extern char *ptot_;
extern int gkedata_54h;
extern int gkedata_55h;
extern ssize_t gkedata_56i;
extern ssize_t gkedata_57i;
void Vd_free(void * ptr);
extern struct freefunc Vd_f;extern char *Vd_;
extern int gkedata_58h;
extern int gkedata_59h;
extern ssize_t gkedata_60i;
extern ssize_t gkedata_61i;
void VVd_free(void * ptr);
extern struct freefunc VVd_f;extern char *VVd_;
extern int gkedata_62h;
extern int gkedata_63l;
extern int gkedata_64h;
extern ssize_t gkedata_65i;
extern ssize_t gkedata_66i;
extern ssize_t gkedata_67st;
void bufV_free(void * ptr);
extern struct freefunc bufV_f;extern char *bufV_;
extern int gkedata_68h;
extern int gkedata_69l;
extern int gkedata_70h;
extern ssize_t gkedata_71i;
extern ssize_t gkedata_72i;
extern ssize_t gkedata_73st;
void bufp_free(void * ptr);
extern struct freefunc bufp_f;extern char *bufp_;
extern int gkedata_74h;
extern int gkedata_75h;
extern int gkedata_76l;
extern int gkedata_77h;
extern off_t gkedata_78i;
extern off_t gkedata_79i;
extern off_t gkedata_81i;
extern off_t gkedata_82i;
extern off_t gkedata_83i;
extern off_t gkedata_84st;
extern off_t gkedata_85st;
struct gkedata_s80{char header_[(1023+1)];};extern struct freefunc diskimage_f;extern FILE *diskimage_;
extern int gkedata_86h;
extern int gkedata_87h;
extern int gkedata_88l;
extern int gkedata_89h;
extern off_t gkedata_90i;
extern off_t gkedata_91i;
extern struct freefunc pressuredata_f;extern FILE *pressuredata_; 
extern int gkedata_92h;
extern int gkedata_93h;
extern int gkedata_94h;
extern off_t gkedata_96i;
extern off_t gkedata_97st;
extern off_t gkedata_98i;
extern off_t gkedata_99st;
extern off_t gkedata_100i;
extern off_t gkedata_101st;
extern struct freefunc uiujimage_f;extern FILE *uiujimage_;
extern int mx_;
extern ssize_t gkedata_102i;
extern struct freefunc imx_f;extern char *imx_;
extern int mz_;
extern ssize_t gkedata_103i;
extern struct freefunc imz_f;extern char *imz_;
extern int gkedata_106h;
extern ssize_t gkedata_107i;
extern ssize_t gkedata_108st;
extern struct freefunc startpos_f;extern char *startpos_;
extern int gkedata_109h;
extern int gkedata_110h;
extern int gkedata_111h;
extern off_t gkedata_112i;
extern off_t gkedata_113i;
extern struct freefunc gkedata_f;extern FILE *gkedata_;
void gkedata_128convolutions(const int Vplane_l,const int Vplane_h,const ssize_t Vplane_i,const int Vplane__l,const int Vplane__h,const ssize_t Vplane__i,char *Vplane___,const int VVplane_l,const int VVplane_h,const ssize_t VVplane_i,const int VVplane__l,const int VVplane__h,const ssize_t VVplane__i,char *VVplane___);
void gkedata_129deriv2(const int f0_l,const int f0_h,const ssize_t f0_i,char *f0__,const int f2_l,const int f2_h,const ssize_t f2_i,char *f2__);
void gkedata_130deriv(const int f0_l,const int f0_h,const ssize_t f0_i,char *f0__,const int f1_l,const int f1_h,const ssize_t f1_i,char *f1__);
struct DERIVS_{struct COMPLEX_ ux_;struct COMPLEX_ uy_;struct COMPLEX_ uz_;struct COMPLEX_ vx_;struct COMPLEX_ vy_;struct COMPLEX_ vz_;struct COMPLEX_ wx_;struct COMPLEX_ wy_;struct COMPLEX_ wz_;};void gkedata_131velocity_gradient(const int Vder_l,const int Vder_h,const ssize_t Vder_i,const int Vder__l,const int Vder__h,const ssize_t Vder__i,const int Vder___l,const int Vder___h,const ssize_t Vder___i,char *Vder____);



int step0B_uiuj_1h;
int step0B_uiuj_2l;
int step0B_uiuj_3h;
int step0B_uiuj_4h;
ssize_t step0B_uiuj_5i;
ssize_t step0B_uiuj_6i;
ssize_t step0B_uiuj_7i;
ssize_t step0B_uiuj_8st;
ssize_t step0B_uiuj_9st;
void Vder_free(void * ptr){munmap((char*)ptr+step0B_uiuj_9st,step0B_uiuj_7i);}struct freefunc Vder_f;char *Vder_;


struct DERPRODSEXT_{struct COMPLEX_ ux2_;struct COMPLEX_ vx2_;struct COMPLEX_ wx2_;struct COMPLEX_ uy2_;struct COMPLEX_ vy2_;struct COMPLEX_ wy2_;struct COMPLEX_ uz2_;struct COMPLEX_ vz2_;struct COMPLEX_ wz2_;struct COMPLEX_ uxvx_;struct COMPLEX_ uyvy_;struct COMPLEX_ uzvz_;struct COMPLEX_ uxwx_;struct COMPLEX_ uywy_;struct COMPLEX_ uzwz_;struct COMPLEX_ vxwx_;struct COMPLEX_ vywy_;struct COMPLEX_ vzwz_;};
int step0B_uiuj_10h;
int step0B_uiuj_11h;
ssize_t step0B_uiuj_12i;
ssize_t step0B_uiuj_13i;
void Vderd_free(void * ptr){munmap((char*)ptr,step0B_uiuj_13i);}struct freefunc Vderd_f;char *Vderd_;

int step0B_uiuj_14h;
int step0B_uiuj_15h;
ssize_t step0B_uiuj_16i;
ssize_t step0B_uiuj_17i;
void VVderd_free(void * ptr){munmap((char*)ptr,step0B_uiuj_17i);}struct freefunc VVderd_f;char *VVderd_;

int step0B_uiuj_18h;
int step0B_uiuj_19h;
ssize_t step0B_uiuj_20i;
ssize_t step0B_uiuj_21i;
void PHIttrspd_free(void * ptr){munmap((char*)ptr+(ssize_t)sizeof(struct COMPLEX_),step0B_uiuj_21i);}struct freefunc PHIttrspd_f;char *PHIttrspd_;


int step0B_uiuj_22h;
ssize_t step0B_uiuj_23i;
void meantot_free(void * ptr){munmap((char*)ptr+gkedata_97st,step0B_uiuj_23i);}struct freefunc meantot_f;char *meantot_;

int step0B_uiuj_24h;
ssize_t step0B_uiuj_25i;
void uiujtot_free(void * ptr){munmap((char*)ptr+gkedata_101st,step0B_uiuj_25i);}struct freefunc uiujtot_f;char *uiujtot_;

int step0B_uiuj_26h;
ssize_t step0B_uiuj_27i;
void mketot_free(void * ptr){munmap((char*)ptr+gkedata_99st,step0B_uiuj_27i);}struct freefunc mketot_f;char *mketot_;


/*! Compute the average field*/
/*! ------------------------------------*/

    int step0B_uiuj_144h;
int step0B_uiuj_145h;
int step0B_uiuj_147h;
int step0B_uiuj_148h;
int step0B_uiuj_150h;
int step0B_uiuj_151h;
mainstart



fft: 

fft_fft_LASTN=1;fft_fft_12C3=sin(3.14159265358979323846/3.);
fft_exit:;





Lanczos_norm_=0.;

Lanczos_R: 
Lanczos_R_exit:;


setup_signal_USR1();


barrier_=mmap(NULL,(ssize_t)sizeof(volatile int),PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANON,-1,0);if(barrier_==MAP_FAILED)errmalloc();atblockexit(barrier_f,barrier_free,(void*)barrier_);(*barrier_)=0;gkedata_1uLx1=200.0/1000.0;
nftot_=(((36-20) / 2))+1;ismp_=0;if( (argc-1)<1 ){ iproc_=1; nproc_=1 ;}else{
iproc_=atoi((void *)((*(char**)((ssize_t)sizeof(char*)+(char*)argv))));  nproc_=atoi((void *)((*(char**)(2*(ssize_t)sizeof(char*)+(char*)argv))));  };
prev_=NULL;atblockexit(prev_f,errfclose,&prev_);next_=NULL;atblockexit(next_f,errfclose,&next_);meanpx_=-99.;meanpz_=-99.;meanflowx_=-99.;meanflowz_=-99.;px_=0.;corrpx_=0.;pz_=0.;corrpz_=0.;flowx_=0.;flowz_=0.;deltat_=0.;cflmax_=0.;time_=0.;restart_file_=0;atblockexit(restart_file_f,condfree,restart_file_);in_data_=NULL;atblockexit(in_data_f,errfclose,&in_data_);errfopen(&in_data_,"dns.in",O_RDWR|O_CREAT);   if(!(scanrec( in_data_ ," ny = %d",&ny_)>0&&scanrec( in_data_ ," nx = %d",&nx_)>0&&scanrec( in_data_ ," nz = %d",&nz_)>0&&scanrec( in_data_ ," alfa0 = %lg",&alfa0_)>0&&scanrec( in_data_ ," beta0 = %lg",&beta0_)>0&&scanrec( in_data_ ," ymin = %lg",&ymin_)>0&&scanrec( in_data_ ," ymax = %lg",&ymax_)>0&&scanrec( in_data_ ," a = %lg",&a_)>0&&scanrec( in_data_ ," ni = %lg",&ni_)>0&&scanrec( in_data_ ," pr = %lg",&pr_)>0&&scanrec( in_data_ ," gr = %lg",&gr_)>0))ioerr( in_data_ );  ni_=1./ni_;  pr_=1./pr_; 
{do{  }while(   (scanrec( in_data_ ," meanpx = %lg",&meanpx_ )>0 ||scanrec( in_data_ ," meanflowx = %lg",&meanflowx_)>0));}
{do{  }while(   (scanrec( in_data_ ," meanpz = %lg",&meanpz_ )>0 ||scanrec( in_data_ ," meanflowz = %lg",&meanflowz_)>0));}
   if(!(scanrec( in_data_ ," u_conv = %lg",&u_conv_)>0 &&scanrec( in_data_ ," w_conv = %lg",&w_conv_)>0))ioerr( in_data_ );
   if(!(scanrec( in_data_ ," u0 = %lg",&u0_)>0 &&scanrec( in_data_ ," un = %lg",&un_)>0 &&scanrec( in_data_ ," w0 = %lg",&w0_)>0 &&scanrec( in_data_ ," wn = %lg",&wn_)>0 &&scanrec( in_data_ ," t0 = %lg",&t0_)>0 &&scanrec( in_data_ ," tn = %lg",&tn_)>0))ioerr( in_data_ );
{do{  }while(   (scanrec( in_data_ ," deltat = %lg",&deltat_ )>0 ||scanrec( in_data_ ," cflmax = %lg",&cflmax_)>0));}
   if(!(scanrec( in_data_ ," t_max = %lg",&t_max_)>0 &&(scanrec( in_data_ ," time_from_restart = %c%*4[A-Za-z] ",&c)&&((time_from_restart_=(c=='T')||(c=='Y')||(c=='t')||(c=='y'))||(c=='F')||(c=='N')||(c=='f')||(c=='n'))) &&scanrec( in_data_ ," dt_field = %lg",&dt_field_)>0 &&scanrec( in_data_ ," dt_save = %lg",&dt_save_)>0))ioerr( in_data_ );
if( !   (mygetline(" restart_file =",&restart_file_ , in_data_ ))){ if(restart_file_)free(restart_file_);restart_file_=strndup("",(int)(strlen("")-1)+1);};
errfclose(&in_data_);
if( (iproc_==nproc_) ){
     fprintf(stdout,"""nproc=""");fprintf(stdout,"%d",nproc_);fprintf(stdout,"\t");fprintf(stdout,"""nsmp=""");fprintf(stdout,"%d",32);putc('\n',stdout);
     fprintf(stdout,"""nx=""");fprintf(stdout,"%d",nx_);fprintf(stdout,"\t" );fprintf(stdout,"""nz=""");fprintf(stdout,"%d",nz_);fprintf(stdout,"\t" );fprintf(stdout,"""ny=""");fprintf(stdout,"%d",ny_);fprintf(stdout,"\t" );fprintf(stdout,"""time=""");fprintf(stdout,"%g",time_);putc('\n',stdout);
     fprintf(stdout,"""meanflowx=""");fprintf(stdout,"%g",meanflowx_);fprintf(stdout,"\t" );fprintf(stdout,"""meanpx=""");fprintf(stdout,"%g",meanpx_);fprintf(stdout,"\t" );fprintf(stdout,"""meanflowz=""");fprintf(stdout,"%g",meanflowz_);fprintf(stdout,"\t" );fprintf(stdout,"""meanpz=""");fprintf(stdout,"%g",meanpz_);putc('\n',stdout);
     fprintf(stdout,"""ymin=""");fprintf(stdout,"%g",ymin_);fprintf(stdout,"\t" );fprintf(stdout,"""ymax=""");fprintf(stdout,"%g",ymax_);fprintf(stdout,"\t" );fprintf(stdout,"""a=""");fprintf(stdout,"%g",a_);fprintf(stdout,"\t" );fprintf(stdout,"""alfa0=""");fprintf(stdout,"%g",alfa0_);fprintf(stdout,"\t" );fprintf(stdout,"""beta0=""");fprintf(stdout,"%g",beta0_);fprintf(stdout,"\t" );fprintf(stdout,"""1/ni=""");fprintf(stdout,"%g",1./ni_);fprintf(stdout,"\t" );fprintf(stdout,"""1/pr=""");fprintf(stdout,"%g",1./pr_);putc('\n',stdout);
     fprintf(stdout,"""u_conv=""");fprintf(stdout,"%g",u_conv_);fprintf(stdout,"\t" );fprintf(stdout,"""u0=""");fprintf(stdout,"%g",u0_);fprintf(stdout,"\t" );fprintf(stdout,"""un=""");fprintf(stdout,"%g",un_);fprintf(stdout,"\t" );fprintf(stdout,"""w_conv=""");fprintf(stdout,"%g",w_conv_);fprintf(stdout,"\t" );fprintf(stdout,"""w0=""");fprintf(stdout,"%g",w0_);fprintf(stdout,"\t" );fprintf(stdout,"""wn=""");fprintf(stdout,"%g",wn_);fprintf(stdout,"\t" );fprintf(stdout,"""t0=""");fprintf(stdout,"%g",t0_);fprintf(stdout,"\t" );fprintf(stdout,"""tn=""");fprintf(stdout,"%g",tn_);putc('\n',stdout);
     fprintf(stdout,"""deltat=""");fprintf(stdout,"%g",deltat_);fprintf(stdout,"\t" );fprintf(stdout,"""cflmax=""");fprintf(stdout,"%g",cflmax_);fprintf(stdout,"\t" );fprintf(stdout,"""t_max=""");fprintf(stdout,"%g",t_max_);fprintf(stdout,"\t" );fprintf(stdout,"""dt_save=""");fprintf(stdout,"%g",dt_save_);fprintf(stdout,"\t" );fprintf(stdout,"""dt_field=""");fprintf(stdout,"%g",dt_field_);putc('\n',stdout);
};

/*! Grid in y direction and finite differences operators*/
/*! -------------------------------------------*/
gkedata_2h=ny_+1;
gkedata_3i=(ssize_t)sizeof(double)*(gkedata_2h-(-1)+1);
gkedata_4st=(-1)*(ssize_t)sizeof(double);

y_=malloc(gkedata_3i);if(y_==NULL)errmalloc();y_-=gkedata_4st;atblockexit(y_f,free,y_+gkedata_4st);  {int i_=(-1);do{ /*!Channel*/{ (*(double *)(i_*(ssize_t)sizeof(double)+y_))=ymin_+0.5*(ymax_-ymin_)*(tanh(a_*((double)(2*i_)/(double)(ny_)-1.))/tanh(a_)+0.5*(ymax_-ymin_)) ;}i_++;}while(i_<=gkedata_2h);}
gkedata_6st=(-2)*(ssize_t)sizeof(double);
gkedata_7h=ny_+1;
gkedata_8i=(ssize_t)sizeof(struct gkedata_s5)*(gkedata_7h-(-1)+1);
gkedata_9st=(-1)*(ssize_t)sizeof(struct gkedata_s5);

derivs_=malloc(gkedata_8i);if(derivs_==NULL)errmalloc();derivs_-=gkedata_9st;atblockexit(derivs_f,free,derivs_+gkedata_9st); {int iy_= - 1  ;while(iy_<=ny_+1 ){{
  struct gkedata_s5 *gkedata_10w;
char matder_[(ssize_t)sizeof(double)*(4+1)*(4+1)];

  char tnder_[(ssize_t)sizeof(double)*(4+1)];

  int gkedata_11shift;
/*shift=gkedata_11shift*/

  gkedata_10w=(struct gkedata_s5 *)(iy_*(ssize_t)sizeof(struct gkedata_s5)+derivs_);
memset(matder_,0,(ssize_t)sizeof(double)*(4+1)*(4+1));memset(tnder_,0,(ssize_t)sizeof(double)*(4+1));gkedata_11shift=((iy_<1))*( - iy_+1) - ((iy_>(ny_-1)))*(iy_-ny_+1);
 {int ic_=0  ;do{ {int ir_=0  ;do{{  (*(double *)(ic_*(ssize_t)sizeof(double)+ir_*(ssize_t)sizeof(double)*(4+1)+matder_) )= pow(((*(double *)((iy_-2+ic_+gkedata_11shift)*(ssize_t)sizeof(double)+y_))-(*(double *)(iy_*(ssize_t)sizeof(double)+y_))),(4-ir_) );}ir_+=1;}while(ir_<=4);}ic_+=1;}while(ic_<=4 );}
  rbmat_6LUdecomp(0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),matder_);
  memset(gkedata_6st+(*gkedata_10w).d1_-gkedata_6st,0,(ssize_t)sizeof(double)*(2-(-2)+1));  memset(tnder_,0,(ssize_t)sizeof(double)*(4+1));   (*(double *)(3*(ssize_t)sizeof(double)+tnder_) )= 1.;
   {{rbmat_8LeftLDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+(*gkedata_10w).d1_-gkedata_6st ),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(matder_),0,4,(ssize_t)sizeof(double),(tnder_)); rbmat_9LeftUDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+(*gkedata_10w).d1_-gkedata_6st ),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(matder_),(1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+(*gkedata_10w).d1_-gkedata_6st ));};}
  memset(gkedata_6st+(*gkedata_10w).d2_-gkedata_6st,0,(ssize_t)sizeof(double)*(2-(-2)+1));  memset(tnder_,0,(ssize_t)sizeof(double)*(4+1));   (*(double *)(2*(ssize_t)sizeof(double)+tnder_) )= 2.;
   {{rbmat_8LeftLDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+(*gkedata_10w).d2_-gkedata_6st ),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(matder_),0,4,(ssize_t)sizeof(double),(tnder_)); rbmat_9LeftUDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+(*gkedata_10w).d2_-gkedata_6st ),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(matder_),(1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+(*gkedata_10w).d2_-gkedata_6st ));};}
}iy_+=1;};}
gkedata_12nyl= - 1+((iproc_-1)*((ny_ / 2 )+2) / nproc_);
gkedata_13nyh=(iproc_*((ny_ / 2 )+2) / nproc_ )-2;
nxd_=(3*nx_ / 2 )- 1;{do{  nxd_ +=1;}while(!(fft_9FFTfit(nxd_)));}
nzd_=3*nz_ - 1;{do{  nzd_ +=1;}while(!(fft_9FFTfit(nzd_)));}
gkedata_14l= - nz_;
gkedata_15h=nz_;
gkedata_16i=(ssize_t)sizeof(int)*(gkedata_15h-gkedata_14l+1);
gkedata_17st=gkedata_14l*(ssize_t)sizeof(int);

izdV_=malloc(gkedata_16i);if(izdV_==NULL)errmalloc();izdV_-=gkedata_17st;atblockexit(izdV_f,free,izdV_+gkedata_17st);memset(gkedata_17st+izdV_,0,gkedata_16i); {int iz_= - nz_  ;do{{ (*(int *)(iz_*(ssize_t)sizeof(int)+izdV_))=( iz_>=0  ?iz_  :nzd_+iz_ );}iz_+=1;}while(iz_<=nz_);}
gkedata_18nxc=(2*nxd_);
gkedata_19nzc=nzd_;
gkedata_20dx=3.14159265358979323846/alfa0_/(double)(nxd_);
gkedata_21dz=2.*3.14159265358979323846/beta0_/(double)(nzd_);
if( (iproc_==nproc_) ){    fprintf(stdout,"""nxc=""");fprintf(stdout,"%d",gkedata_18nxc);fprintf(stdout,"\t");fprintf(stdout,"""nzc=""");fprintf(stdout,"%d",gkedata_19nzc);putc('\n',stdout);};

/*! Types*/
/*! -------------------------------------------*/

mean_=mmap(NULL,(ssize_t)sizeof(struct MEANTERMS_)*2,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANON,-1,0);if(mean_==MAP_FAILED)errmalloc();mean_-=(ssize_t)sizeof(struct MEANTERMS_);atblockexit(mean_f,mean_free,(void*)mean_);
uiuj_=mmap(NULL,(ssize_t)sizeof(struct BALANCE_)*2,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANON,-1,0);if(uiuj_==MAP_FAILED)errmalloc();uiuj_-=(ssize_t)sizeof(struct BALANCE_);atblockexit(uiuj_f,uiuj_free,(void*)uiuj_);gkedata_24h=nx_;
gkedata_25l= - nz_;
gkedata_26h=nz_;
gkedata_27i=(ssize_t)sizeof(struct COMPLEX_)*2*(gkedata_26h-gkedata_25l+1);
gkedata_28i=gkedata_27i*(gkedata_24h+1);
gkedata_29st=gkedata_25l*(ssize_t)sizeof(struct COMPLEX_)*2+(ssize_t)sizeof(struct COMPLEX_);

p_=mmap(NULL,gkedata_28i,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANON,-1,0);if(p_==MAP_FAILED)errmalloc();p_-=gkedata_29st;atblockexit(p_f,p_free,(void*)p_);memset(gkedata_29st+p_,0,gkedata_28i);gkedata_30h=nx_;
gkedata_31l= - nz_;
gkedata_32h=nz_;
gkedata_33i=(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1)*2*(gkedata_32h-gkedata_31l+1);
gkedata_34i=gkedata_33i*(gkedata_30h+1);
gkedata_35st=gkedata_31l*(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1)*2+(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1);

V_=mmap(NULL,gkedata_34i,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANON,-1,0);if(V_==MAP_FAILED)errmalloc();V_-=gkedata_35st;atblockexit(V_f,V_free,(void*)V_);memset(gkedata_35st+V_,0,gkedata_34i);gkedata_36h=ny_+1;
gkedata_37h=nx_;
gkedata_38l= - nz_;
gkedata_39h=nz_;
gkedata_40i=(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1)*(gkedata_39h-gkedata_38l+1);
gkedata_41i=gkedata_40i*(gkedata_37h+1);
gkedata_42i=gkedata_41i*(gkedata_36h-(-1)+1);
gkedata_43st=gkedata_38l*(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1);
gkedata_44st=(-1)*gkedata_41i+gkedata_43st;

Vtot_=mmap(NULL,gkedata_42i,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANON,-1,0);if(Vtot_==MAP_FAILED)errmalloc();Vtot_-=gkedata_44st;atblockexit(Vtot_f,Vtot_free,(void*)Vtot_);memset(gkedata_44st+Vtot_,0,gkedata_42i);gkedata_45h=ny_+1;
gkedata_46h=nx_;
gkedata_47l= - nz_;
gkedata_48h=nz_;
gkedata_49i=(ssize_t)sizeof(struct COMPLEX_)*(gkedata_48h-gkedata_47l+1);
gkedata_50i=gkedata_49i*(gkedata_46h+1);
gkedata_51i=gkedata_50i*(gkedata_45h-(-1)+1);
gkedata_52st=gkedata_47l*(ssize_t)sizeof(struct COMPLEX_);
gkedata_53st=(-1)*gkedata_50i+gkedata_52st;

ptot_=mmap(NULL,gkedata_51i,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANON,-1,0);if(ptot_==MAP_FAILED)errmalloc();ptot_-=gkedata_53st;atblockexit(ptot_f,ptot_free,(void*)ptot_);memset(gkedata_53st+ptot_,0,gkedata_51i);gkedata_54h=nxd_-1;
gkedata_55h=nzd_-1;
gkedata_56i=(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1)*(gkedata_55h+1);
gkedata_57i=gkedata_56i*(gkedata_54h+1);

Vd_=mmap(NULL,gkedata_57i,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANON,-1,0);if(Vd_==MAP_FAILED)errmalloc();atblockexit(Vd_f,Vd_free,(void*)Vd_);memset(Vd_,0,gkedata_57i);gkedata_58h=nxd_-1;
gkedata_59h=nzd_-1;
gkedata_60i=(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA23*/+1)*2*(gkedata_59h+1);
gkedata_61i=gkedata_60i*(gkedata_58h+1);

VVd_=mmap(NULL,gkedata_61i,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANON,-1,0);if(VVd_==MAP_FAILED)errmalloc();VVd_-=(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA23*/+1);atblockexit(VVd_f,VVd_free,(void*)VVd_);memset((ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA23*/+1)+VVd_,0,gkedata_61i);gkedata_62h=nx_;
gkedata_63l= - nz_;
gkedata_64h=nz_;
gkedata_65i=(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1)*(gkedata_64h-gkedata_63l+1);
gkedata_66i=gkedata_65i*(gkedata_62h+1);
gkedata_67st=gkedata_63l*(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1);

bufV_=mmap(NULL,gkedata_66i,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANON,-1,0);if(bufV_==MAP_FAILED)errmalloc();bufV_-=gkedata_67st;atblockexit(bufV_f,bufV_free,(void*)bufV_);memset(gkedata_67st+bufV_,0,gkedata_66i);gkedata_68h=nx_;
gkedata_69l= - nz_;
gkedata_70h=nz_;
gkedata_71i=(ssize_t)sizeof(struct COMPLEX_)*(gkedata_70h-gkedata_69l+1);
gkedata_72i=gkedata_71i*(gkedata_68h+1);
gkedata_73st=gkedata_69l*(ssize_t)sizeof(struct COMPLEX_);

bufp_=mmap(NULL,gkedata_72i,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANON,-1,0);if(bufp_==MAP_FAILED)errmalloc();bufp_-=gkedata_73st;atblockexit(bufp_f,bufp_free,(void*)bufp_);memset(gkedata_73st+bufp_,0,gkedata_72i);gkedata_74h=ny_+1;
gkedata_75h=nx_;
gkedata_76l= - nz_;
gkedata_77h=nz_;
gkedata_78i=(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1)*(gkedata_77h-gkedata_76l+1);
gkedata_79i=gkedata_78i*(gkedata_75h+1);
gkedata_81i=(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1)*(gkedata_77h-gkedata_76l+1);
gkedata_82i=gkedata_81i*(gkedata_75h+1);
gkedata_83i=gkedata_82i*(gkedata_74h-(-1)+1);
gkedata_84st=gkedata_76l*(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1);
gkedata_85st=(-1)*gkedata_79i+gkedata_84st;
diskimage_=NULL;atblockexit(diskimage_f,errfclose,&diskimage_);gkedata_86h=ny_+1;
gkedata_87h=nx_;
gkedata_88l= - nz_;
gkedata_89h=nz_;
gkedata_90i=(ssize_t)sizeof(struct COMPLEX_)*(gkedata_89h-gkedata_88l+1);
gkedata_91i=gkedata_90i*(gkedata_87h+1);
pressuredata_=NULL;atblockexit(pressuredata_f,errfclose,&pressuredata_);gkedata_92h=ny_+1;
gkedata_93h=ny_+1;
gkedata_94h=ny_+1;
gkedata_96i=(ssize_t)sizeof(struct MEANTERMS_)*(gkedata_92h-(-1)+1);
gkedata_97st=(-1)*(ssize_t)sizeof(struct MEANTERMS_);
gkedata_98i=(ssize_t)sizeof(struct MKETERMS_)*(gkedata_93h-(-1)+1);
gkedata_99st=(-1)*(ssize_t)sizeof(struct MKETERMS_);
gkedata_100i=(ssize_t)sizeof(struct BALANCE_)*(gkedata_94h-(-1)+1);
gkedata_101st=(-1)*(ssize_t)sizeof(struct BALANCE_);
uiujimage_=NULL;atblockexit(uiujimage_f,errfclose,&uiujimage_);mx_=0;gkedata_102i=(ssize_t)sizeof(int)*(gkedata_18nxc+1);

imx_=malloc(gkedata_102i);if(imx_==NULL)errmalloc();atblockexit(imx_f,free,imx_);memset(imx_,0,gkedata_102i);mz_=0;gkedata_103i=(ssize_t)sizeof(int)*(gkedata_19nzc+1);

imz_=malloc(gkedata_103i);if(imz_==NULL)errmalloc();atblockexit(imz_f,free,imz_);memset(imz_,0,gkedata_103i);{
  int ix_;

  int iz_;

  ix_=0;while( ix_<(gkedata_18nxc / 2)){
    (*(int *)(mx_*(ssize_t)sizeof(int)+imx_))=ix_;  mx_+=1;  ix_+=(( (double)(ix_)*gkedata_20dx<=gkedata_1uLx1  ?1  :(( (double)(ix_)*gkedata_20dx<=0.5  ?4  :8))));
  }
  if( (*(int *)((mx_-1)*(ssize_t)sizeof(int)+imx_))<(gkedata_18nxc / 2 )){ (*(int *)(mx_*(ssize_t)sizeof(int)+imx_))=(gkedata_18nxc / 2); mx_+=1;};
   {int i_=1  ;do{{ register int md104;
(*(int *)((mx_+i_-1)*(ssize_t)sizeof(int)+imx_))=(md104=(2*nxd_-(*(int *)((mx_-i_-1)*(ssize_t)sizeof(int)+imx_))) % (2*nxd_)  ,md104>=0?md104:md104+(2*nxd_)  );}i_+=1;}while(i_<=mx_-2);}   mx_ = 2*mx_ -2;
  iz_=0;while( iz_<(gkedata_19nzc / 2)){
    (*(int *)(mz_*(ssize_t)sizeof(int)+imz_))=iz_;  mz_+=1;  iz_+=(( (double)(iz_)*gkedata_21dz<=gkedata_1uLx1  ?1  :(( (double)(iz_)*gkedata_21dz<=0.5  ?4  :8))));
  }
  if( (*(int *)((mz_-1)*(ssize_t)sizeof(int)+imz_))<(gkedata_19nzc / 2 )){ (*(int *)(mz_*(ssize_t)sizeof(int)+imz_))=(gkedata_19nzc / 2); mz_+=1;};
   {int i_=1  ;do{{ register int md105;
(*(int *)((mz_+i_-1)*(ssize_t)sizeof(int)+imz_))=(md105=(nzd_-(*(int *)((mz_-i_-1)*(ssize_t)sizeof(int)+imz_))) % (*(&nzd_)  ),md105>=0?md105:md105+(*(&nzd_)  ));}i_+=1;}while(i_<=mz_-2);}   mz_ = 2*mz_ -2;
}
   fprintf(stdout,"""mx=""");fprintf(stdout,"%d",mx_);fprintf(stdout,"\t");fprintf(stdout,"""mz=""");fprintf(stdout,"%d",mz_);putc('\n',stdout);

/*! Definitions*/
/*! -----------------------------*/
gkedata_106h=(ny_ / 2 )+1;
gkedata_107i=(ssize_t)sizeof(int)*(gkedata_106h-(-1)+1);
gkedata_108st=(-1)*(ssize_t)sizeof(int);

startpos_=malloc(gkedata_107i);if(startpos_==NULL)errmalloc();startpos_-=gkedata_108st;atblockexit(startpos_f,free,startpos_+gkedata_108st);memset(gkedata_108st+startpos_,0,gkedata_107i); {int iy_= - 1  ;do{{ (*(int *)((iy_+1)*(ssize_t)sizeof(int)+startpos_))=(*(int *)(iy_*(ssize_t)sizeof(int)+startpos_))+(ny_-2*iy_+1) ;}iy_+=1;}while(iy_<=(ny_ / 2));}
gkedata_109h=(*(int *)(((ny_/2)+1)*(ssize_t)sizeof(int)+startpos_))-1;
gkedata_110h=mx_-1;
gkedata_111h=mz_-1;
gkedata_112i=(ssize_t)sizeof(struct GKETERMS_)*(gkedata_111h+1);
gkedata_113i=gkedata_112i*(gkedata_110h+1);
gkedata_=NULL;atblockexit(gkedata_f,errfclose,&gkedata_);errfopen(&uiujimage_,"uiuj.bin",O_RDWR|O_CREAT);  { if((ssize_t)sizeof(struct MEANTERMS_)==(ssize_t)sizeof(struct MEANTERMS_)&&(ssize_t)sizeof(struct MEANTERMS_)==(ssize_t)sizeof(struct MEANTERMS_)){if(!(fseeko(uiujimage_,(off_t)(-gkedata_97st+(ssize_t)(char*)(void*)(0))+(ssize_t)sizeof(struct MEANTERMS_),SEEK_SET)==0&&fread(mean_+(ssize_t)sizeof(struct MEANTERMS_),(ssize_t)sizeof(struct MEANTERMS_),2-1+1,uiujimage_)==2-1+1))ioerr(uiujimage_);}else{  {int _114i_=1;do{{if(!(fseeko(uiujimage_,_114i_*(off_t)(ssize_t)sizeof(struct MEANTERMS_)+(off_t)(-gkedata_97st+(ssize_t)(char*)(void*)(0)) ,SEEK_SET)==0&&fread((struct MEANTERMS_ *)(_114i_*(ssize_t)sizeof(struct MEANTERMS_)+mean_),(ssize_t)sizeof(struct MEANTERMS_),1,uiujimage_)==1))ioerr(uiujimage_);}_114i_++;}while(_114i_<=2);}}; if((ssize_t)sizeof(struct BALANCE_)==(ssize_t)sizeof(struct BALANCE_)&&(ssize_t)sizeof(struct BALANCE_)==(ssize_t)sizeof(struct BALANCE_)){if(!(fseeko(uiujimage_,(off_t)((gkedata_96i+gkedata_98i)-gkedata_101st+(ssize_t)(char*)(void*)(0))+(ssize_t)sizeof(struct BALANCE_),SEEK_SET)==0&&fread(uiuj_+(ssize_t)sizeof(struct BALANCE_),(ssize_t)sizeof(struct BALANCE_),2-1+1,uiujimage_)==2-1+1))ioerr(uiujimage_);}else{  {int _115i_=1;do{{if(!(fseeko(uiujimage_,_115i_*(off_t)(ssize_t)sizeof(struct BALANCE_)+(off_t)((gkedata_96i+gkedata_98i)-gkedata_101st+(ssize_t)(char*)(void*)(0)) ,SEEK_SET)==0&&fread((struct BALANCE_ *)(_115i_*(ssize_t)sizeof(struct BALANCE_)+uiuj_),(ssize_t)sizeof(struct BALANCE_),1,uiujimage_)==1))ioerr(uiujimage_);}_115i_++;}while(_115i_<=2);}};}

/*! Open data for output and set everything to zero*/
/*! ------------------------------*/
errfopen(&gkedata_,path_,O_RDWR|O_CREAT);
if( (iproc_==nproc_) ){ int gkedata_116h;
int gkedata_117h;
int gkedata_118h;
ssize_t gkedata_119i;
ssize_t gkedata_120i;
ssize_t gkedata_121i;
int gkedata_122h;
int gkedata_123h;
int gkedata_124h;
ssize_t gkedata_125i;
ssize_t gkedata_126i;
ssize_t gkedata_127i;
gkedata_116h=(*(int *)(((ny_/2)+1)*(ssize_t)sizeof(int)+startpos_))-1;
gkedata_117h=mx_-1;
gkedata_118h=mz_-1;
gkedata_119i=(ssize_t)sizeof(struct GKETERMS_)*(gkedata_118h+1);
gkedata_120i=gkedata_119i*(gkedata_117h+1);
gkedata_121i=gkedata_120i*(gkedata_116h+1);
gkedata_122h=(*(int *)(((ny_/2)+1)*(ssize_t)sizeof(int)+startpos_))-1;
gkedata_123h=mx_-1;
gkedata_124h=mz_-1;
gkedata_125i=(ssize_t)sizeof(struct GKETERMS_)*(gkedata_124h+1);
gkedata_126i=gkedata_125i*(gkedata_123h+1);
gkedata_127i=gkedata_126i*(gkedata_122h+1);
 fprintf(stdout,"""Will require " "%g"" GiB on disk...""",(double)(gkedata_127i)/(pow(1024.0,3)) );putc('\n',stdout);};
if( (iproc_==nproc_) ){  fprintf(stdout,"""Computing Kolmogorov Equation...""");putc('\n',stdout);};

/*! Pseudo-spectral convolutions*/
/*! ------------------------------*/


/*! Definitions*/
/*! ------------------------------------*/
step0B_uiuj_1h=nx_;
step0B_uiuj_2l= - nz_;
step0B_uiuj_3h=nz_;
step0B_uiuj_4h=ny_+1;
step0B_uiuj_5i=(ssize_t)sizeof(struct DERIVS_)*(step0B_uiuj_4h-(-1)+1);
step0B_uiuj_6i=step0B_uiuj_5i*(step0B_uiuj_3h-step0B_uiuj_2l+1);
step0B_uiuj_7i=step0B_uiuj_6i*(step0B_uiuj_1h+1);
step0B_uiuj_8st=(-1)*(ssize_t)sizeof(struct DERIVS_);
step0B_uiuj_9st=step0B_uiuj_2l*step0B_uiuj_5i+step0B_uiuj_8st;

Vder_=mmap(NULL,step0B_uiuj_7i,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANON,-1,0);if(Vder_==MAP_FAILED)errmalloc();Vder_-=step0B_uiuj_9st;atblockexit(Vder_f,Vder_free,(void*)Vder_);memset(step0B_uiuj_9st+Vder_,0,step0B_uiuj_7i);step0B_uiuj_10h=nxd_-1;
step0B_uiuj_11h=nzd_-1;
step0B_uiuj_12i=(ssize_t)sizeof(struct DERIVS_)*(step0B_uiuj_11h+1);
step0B_uiuj_13i=step0B_uiuj_12i*(step0B_uiuj_10h+1);

Vderd_=mmap(NULL,step0B_uiuj_13i,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANON,-1,0);if(Vderd_==MAP_FAILED)errmalloc();atblockexit(Vderd_f,Vderd_free,(void*)Vderd_);memset(Vderd_,0,step0B_uiuj_13i);step0B_uiuj_14h=nxd_-1;
step0B_uiuj_15h=nzd_-1;
step0B_uiuj_16i=(ssize_t)sizeof(struct DERPRODSEXT_)*(step0B_uiuj_15h+1);
step0B_uiuj_17i=step0B_uiuj_16i*(step0B_uiuj_14h+1);

VVderd_=mmap(NULL,step0B_uiuj_17i,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANON,-1,0);if(VVderd_==MAP_FAILED)errmalloc();atblockexit(VVderd_f,VVderd_free,(void*)VVderd_);memset(VVderd_,0,step0B_uiuj_17i);step0B_uiuj_18h=nxd_-1;
step0B_uiuj_19h=nzd_-1;
step0B_uiuj_20i=(ssize_t)sizeof(struct COMPLEX_)*6*(step0B_uiuj_19h+1);
step0B_uiuj_21i=step0B_uiuj_20i*(step0B_uiuj_18h+1);

PHIttrspd_=mmap(NULL,step0B_uiuj_21i,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANON,-1,0);if(PHIttrspd_==MAP_FAILED)errmalloc();PHIttrspd_-=(ssize_t)sizeof(struct COMPLEX_);atblockexit(PHIttrspd_f,PHIttrspd_free,(void*)PHIttrspd_);memset((ssize_t)sizeof(struct COMPLEX_)+PHIttrspd_,0,step0B_uiuj_21i);step0B_uiuj_22h=ny_+1;
step0B_uiuj_23i=(ssize_t)sizeof(struct MEANTERMS_)*(step0B_uiuj_22h-(-1)+1);

meantot_=mmap(NULL,step0B_uiuj_23i,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANON,-1,0);if(meantot_==MAP_FAILED)errmalloc();meantot_-=gkedata_97st;atblockexit(meantot_f,meantot_free,(void*)meantot_);memset(gkedata_97st+meantot_,0,step0B_uiuj_23i);step0B_uiuj_24h=ny_+1;
step0B_uiuj_25i=(ssize_t)sizeof(struct BALANCE_)*(step0B_uiuj_24h-(-1)+1);

uiujtot_=mmap(NULL,step0B_uiuj_25i,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANON,-1,0);if(uiujtot_==MAP_FAILED)errmalloc();uiujtot_-=gkedata_101st;atblockexit(uiujtot_f,uiujtot_free,(void*)uiujtot_);memset(gkedata_101st+uiujtot_,0,step0B_uiuj_25i);step0B_uiuj_26h=ny_+1;
step0B_uiuj_27i=(ssize_t)sizeof(struct MKETERMS_)*(step0B_uiuj_26h-(-1)+1);

mketot_=mmap(NULL,step0B_uiuj_27i,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANON,-1,0);if(mketot_==MAP_FAILED)errmalloc();mketot_-=gkedata_99st;atblockexit(mketot_f,mketot_free,(void*)mketot_);memset(gkedata_99st+mketot_,0,step0B_uiuj_27i);files:;  {int n_=20  ;while(n_<=36 ){
  struct freefunc field_name_f;char *field_name_; 
  struct freefunc pressure_name_f;char *pressure_name_; 
   int step0B_uiuj_28h;
field_name_=0;atblockexit(field_name_f,condfree,field_name_); {char *tmp; tmp=malloc(snprintf(NULL,0,"""Dati.cart.""%d"".fld""",n_)+1); sprintf(tmp,"""Dati.cart.""%d"".fld""",n_); if(field_name_)free(field_name_);field_name_=tmp;} errfopen(&diskimage_ ,field_name_,O_RDWR|O_CREAT);
  pressure_name_=0;atblockexit(pressure_name_f,condfree,pressure_name_); {char *tmp; tmp=malloc(snprintf(NULL,0,"""pField""%d"".fld""",n_)+1); sprintf(tmp,"""pField""%d"".fld""",n_); if(pressure_name_)free(pressure_name_);pressure_name_=tmp;}errfopen(&pressuredata_,pressure_name_,O_RDWR|O_CREAT);
  step0B_uiuj_28h=ny_+1;
{
    off_t step0B_uiuj_29w;
ssize_t step0B_uiuj_31i;
ssize_t step0B_uiuj_32st;
struct freefunc step0B_uiuj_30f;char *step0B_uiuj_30;
ssize_t step0B_uiuj_39i;
ssize_t step0B_uiuj_40st;
struct freefunc step0B_uiuj_38f;char *step0B_uiuj_38;
ssize_t step0B_uiuj_47i;
ssize_t step0B_uiuj_48st;
struct freefunc step0B_uiuj_46f;char *step0B_uiuj_46;
off_t step0B_uiuj_51st;
off_t step0B_uiuj_52st;
int step0B_uiuj_53h;
step0B_uiuj_29w=(off_t)((ssize_t)sizeof(struct gkedata_s80)-gkedata_85st+(ssize_t)(char*)(struct gkedata_s80*)(0));
step0B_uiuj_31i=(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1)*(step0B_uiuj_28h-(-1)+1);
step0B_uiuj_32st=(-1)*(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1);

step0B_uiuj_30=malloc(step0B_uiuj_31i);if(step0B_uiuj_30==NULL)errmalloc();step0B_uiuj_30-=step0B_uiuj_32st;atblockexit(step0B_uiuj_30f,free,step0B_uiuj_30+step0B_uiuj_32st);if((ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1)==(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1)&&gkedata_79i==(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1)){if(!(fseeko(diskimage_,step0B_uiuj_29w+step0B_uiuj_32st,SEEK_SET)==0&&fread(step0B_uiuj_30+step0B_uiuj_32st,(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1),step0B_uiuj_28h-(-1)+1,diskimage_)==step0B_uiuj_28h-(-1)+1))ioerr(diskimage_);}else{  {int _33i_=(-1);do{{if((ssize_t)sizeof(struct COMPLEX_)==(ssize_t)sizeof(struct COMPLEX_)&&(ssize_t)sizeof(struct COMPLEX_)==(ssize_t)sizeof(struct COMPLEX_)){if(!(fseeko(diskimage_,_33i_*(off_t)gkedata_79i+step0B_uiuj_29w,SEEK_SET)==0&&fread(_33i_*(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1)+step0B_uiuj_30,(ssize_t)sizeof(struct COMPLEX_),(((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1,diskimage_)==(((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1))ioerr(diskimage_);}else{  {int _34i_=((0+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/;do{{if(!(fseeko(diskimage_,_34i_*(off_t)(ssize_t)sizeof(struct COMPLEX_)+_33i_*(off_t)gkedata_79i+step0B_uiuj_29w ,SEEK_SET)==0&&fread((struct COMPLEX_ *)(_34i_*(ssize_t)sizeof(struct COMPLEX_)+_33i_*(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1)+step0B_uiuj_30),(ssize_t)sizeof(struct COMPLEX_),1,diskimage_)==1))ioerr(diskimage_);}_34i_--;}while(_34i_>=0);}};}_33i_++;}while(_33i_<=step0B_uiuj_28h);}};{  {int _35i_=(-1);do{{double step0B_uiuj_37;
if(!(fseeko(diskimage_,_35i_*(off_t)gkedata_79i+(off_t)(step0B_uiuj_29w)+(ssize_t)&(*(struct COMPLEX_*)(0)).REAL_ ,SEEK_SET)==0&&fread(&step0B_uiuj_37,(ssize_t)sizeof(double),1,diskimage_)==1))ioerr(diskimage_);(*(double *)(_35i_*(ssize_t)sizeof(struct MEANTERMS_)+(char*)&(*(struct MEANTERMS_*)(meantot_)).U_))+=step0B_uiuj_37;}_35i_++;}while(_35i_<=step0B_uiuj_22h);}}  step0B_uiuj_39i=(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1)*(step0B_uiuj_28h-(-1)+1);
step0B_uiuj_40st=(-1)*(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1);

step0B_uiuj_38=malloc(step0B_uiuj_39i);if(step0B_uiuj_38==NULL)errmalloc();step0B_uiuj_38-=step0B_uiuj_40st;atblockexit(step0B_uiuj_38f,free,step0B_uiuj_38+step0B_uiuj_40st);if((ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1)==(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1)&&gkedata_79i==(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1)){if(!(fseeko(diskimage_,step0B_uiuj_29w+step0B_uiuj_40st,SEEK_SET)==0&&fread(step0B_uiuj_38+step0B_uiuj_40st,(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1),step0B_uiuj_28h-(-1)+1,diskimage_)==step0B_uiuj_28h-(-1)+1))ioerr(diskimage_);}else{  {int _41i_=(-1);do{{if((ssize_t)sizeof(struct COMPLEX_)==(ssize_t)sizeof(struct COMPLEX_)&&(ssize_t)sizeof(struct COMPLEX_)==(ssize_t)sizeof(struct COMPLEX_)){if(!(fseeko(diskimage_,_41i_*(off_t)gkedata_79i+step0B_uiuj_29w,SEEK_SET)==0&&fread(_41i_*(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1)+step0B_uiuj_38,(ssize_t)sizeof(struct COMPLEX_),(((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1,diskimage_)==(((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1))ioerr(diskimage_);}else{  {int _42i_=((0+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/;do{{if(!(fseeko(diskimage_,_42i_*(off_t)(ssize_t)sizeof(struct COMPLEX_)+_41i_*(off_t)gkedata_79i+step0B_uiuj_29w ,SEEK_SET)==0&&fread((struct COMPLEX_ *)(_42i_*(ssize_t)sizeof(struct COMPLEX_)+_41i_*(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1)+step0B_uiuj_38),(ssize_t)sizeof(struct COMPLEX_),1,diskimage_)==1))ioerr(diskimage_);}_42i_--;}while(_42i_>=0);}};}_41i_++;}while(_41i_<=step0B_uiuj_28h);}};{  {int _43i_=(-1);do{{double step0B_uiuj_45;
if(!(fseeko(diskimage_,_43i_*(off_t)gkedata_79i+(off_t)((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_29w)+(ssize_t)&(*(struct COMPLEX_*)(0)).REAL_ ,SEEK_SET)==0&&fread(&step0B_uiuj_45,(ssize_t)sizeof(double),1,diskimage_)==1))ioerr(diskimage_);(*(double *)(_43i_*(ssize_t)sizeof(struct MEANTERMS_)+(char*)&(*(struct MEANTERMS_*)(meantot_)).W_))+=step0B_uiuj_45;}_43i_++;}while(_43i_<=step0B_uiuj_22h);}}  step0B_uiuj_47i=(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1)*(step0B_uiuj_28h-(-1)+1);
step0B_uiuj_48st=(-1)*(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1);

step0B_uiuj_46=malloc(step0B_uiuj_47i);if(step0B_uiuj_46==NULL)errmalloc();step0B_uiuj_46-=step0B_uiuj_48st;atblockexit(step0B_uiuj_46f,free,step0B_uiuj_46+step0B_uiuj_48st);if((ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1)==(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1)&&gkedata_79i==(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1)){if(!(fseeko(diskimage_,step0B_uiuj_29w+step0B_uiuj_48st,SEEK_SET)==0&&fread(step0B_uiuj_46+step0B_uiuj_48st,(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1),step0B_uiuj_28h-(-1)+1,diskimage_)==step0B_uiuj_28h-(-1)+1))ioerr(diskimage_);}else{  {int _49i_=(-1);do{{if((ssize_t)sizeof(struct COMPLEX_)==(ssize_t)sizeof(struct COMPLEX_)&&(ssize_t)sizeof(struct COMPLEX_)==(ssize_t)sizeof(struct COMPLEX_)){if(!(fseeko(diskimage_,_49i_*(off_t)gkedata_79i+step0B_uiuj_29w,SEEK_SET)==0&&fread(_49i_*(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1)+step0B_uiuj_46,(ssize_t)sizeof(struct COMPLEX_),(((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1,diskimage_)==(((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1))ioerr(diskimage_);}else{  {int _50i_=((0+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/;do{{if(!(fseeko(diskimage_,_50i_*(off_t)(ssize_t)sizeof(struct COMPLEX_)+_49i_*(off_t)gkedata_79i+step0B_uiuj_29w ,SEEK_SET)==0&&fread((struct COMPLEX_ *)(_50i_*(ssize_t)sizeof(struct COMPLEX_)+_49i_*(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1)+step0B_uiuj_46),(ssize_t)sizeof(struct COMPLEX_),1,diskimage_)==1))ioerr(diskimage_);}_50i_--;}while(_50i_>=0);}};}_49i_++;}while(_49i_<=step0B_uiuj_28h);}};step0B_uiuj_51st=gkedata_88l*(ssize_t)sizeof(struct COMPLEX_);
step0B_uiuj_52st=(-1)*gkedata_91i+step0B_uiuj_51st;
step0B_uiuj_53h=ny_+1;
{  {int _54i_=(-1);do{{double step0B_uiuj_56;
if(!(fseeko(pressuredata_,_54i_*(off_t)gkedata_91i+(-step0B_uiuj_52st)+(ssize_t)&(*(struct COMPLEX_*)(0)).REAL_ ,SEEK_SET)==0&&fread(&step0B_uiuj_56,(ssize_t)sizeof(double),1,pressuredata_)==1))ioerr(pressuredata_);(*(double *)(_54i_*(ssize_t)sizeof(struct MEANTERMS_)+(char*)&(*(struct MEANTERMS_*)(meantot_)).P_))+=step0B_uiuj_56;}_54i_++;}while(_54i_<=step0B_uiuj_22h);}}
  errfclose(&diskimage_);  errfclose(&pressuredata_);
freemem(&pressure_name_f);}freemem(&mketot_f);n_+= 2;};}files_exit:;
{ double step0B_uiuj_57m;
double step0B_uiuj_59m;
double step0B_uiuj_61m;
step0B_uiuj_57m=1./(double)(nftot_);
{  {int _58i_=(-1);do{{(*(double *)(_58i_*(ssize_t)sizeof(struct MEANTERMS_)+(char*)&(*(struct MEANTERMS_*)(meantot_)).U_))*=step0B_uiuj_57m ;}_58i_++;}while(_58i_<=step0B_uiuj_22h);}} step0B_uiuj_59m=1./(double)(nftot_);
{  {int _60i_=(-1);do{{(*(double *)(_60i_*(ssize_t)sizeof(struct MEANTERMS_)+(char*)&(*(struct MEANTERMS_*)(meantot_)).W_))*=step0B_uiuj_59m ;}_60i_++;}while(_60i_<=step0B_uiuj_22h);}} step0B_uiuj_61m=1./(double)(nftot_);
{  {int _62i_=(-1);do{{(*(double *)(_62i_*(ssize_t)sizeof(struct MEANTERMS_)+(char*)&(*(struct MEANTERMS_*)(meantot_)).P_))*=step0B_uiuj_61m ;}_62i_++;}while(_62i_<=step0B_uiuj_22h);}}}
{  gkedata_130deriv((-1),step0B_uiuj_22h,(ssize_t)sizeof(struct MEANTERMS_),(char*)&(*(struct MEANTERMS_ *)(meantot_)).U_ ,(-1),step0B_uiuj_22h,(ssize_t)sizeof(struct MEANTERMS_),(char*)&(*(struct MEANTERMS_ *)(meantot_)).Uy_);  gkedata_130deriv((-1),step0B_uiuj_22h,(ssize_t)sizeof(struct MEANTERMS_),(char*)&(*(struct MEANTERMS_ *)(meantot_)).W_ ,(-1),step0B_uiuj_22h,(ssize_t)sizeof(struct MEANTERMS_),(char*)&(*(struct MEANTERMS_ *)(meantot_)).Wy_);   }
{ gkedata_129deriv2((-1),step0B_uiuj_22h,(ssize_t)sizeof(struct MEANTERMS_),(char*)&(*(struct MEANTERMS_ *)(meantot_)).U_ ,(-1),step0B_uiuj_22h,(ssize_t)sizeof(struct MEANTERMS_),(char*)&(*(struct MEANTERMS_ *)(meantot_)).Uyy_); gkedata_129deriv2((-1),step0B_uiuj_22h,(ssize_t)sizeof(struct MEANTERMS_),(char*)&(*(struct MEANTERMS_ *)(meantot_)).W_ ,(-1),step0B_uiuj_22h,(ssize_t)sizeof(struct MEANTERMS_),(char*)&(*(struct MEANTERMS_ *)(meantot_)).Wyy_); }

/*! Compute the TKE budget*/
/*! ------------------------------------*/
fields:;  {int n_=20  ;while(n_<=36 ){
  /*! Read field*/
  struct freefunc field_name_f;char *field_name_; 
  struct freefunc pressure_name_f;char *pressure_name_; 
   off_t step0B_uiuj_67st;
off_t step0B_uiuj_68st;
field_name_=0;atblockexit(field_name_f,condfree,field_name_); {char *tmp; tmp=malloc(snprintf(NULL,0,"""Dati.cart.""%d"".fld""",n_)+1); sprintf(tmp,"""Dati.cart.""%d"".fld""",n_); if(field_name_)free(field_name_);field_name_=tmp;} errfopen(&diskimage_ ,field_name_,O_RDWR|O_CREAT);    {int _63i_=(-1);do{{  {int _64i_=gkedata_37h;do{{if((ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1)==(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1)&&(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1)==(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1)){if(!(fseeko(diskimage_,_64i_*(off_t)gkedata_78i+_63i_*(off_t)gkedata_79i+(off_t)((ssize_t)sizeof(struct gkedata_s80)-gkedata_85st+(ssize_t)(char*)(struct gkedata_s80*)(0))+gkedata_43st,SEEK_SET)==0&&fread(_64i_*gkedata_40i+_63i_*gkedata_41i+Vtot_+gkedata_43st,(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1),gkedata_39h-gkedata_38l+1,diskimage_)==gkedata_39h-gkedata_38l+1))ioerr(diskimage_);}else{  {int _65i_=gkedata_38l;do{{if((ssize_t)sizeof(struct COMPLEX_)==(ssize_t)sizeof(struct COMPLEX_)&&(ssize_t)sizeof(struct COMPLEX_)==(ssize_t)sizeof(struct COMPLEX_)){if(!(fseeko(diskimage_,_65i_*(off_t)(ssize_t)sizeof(struct COMPLEX_)*(off_t)((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1)+_64i_*(off_t)gkedata_78i+_63i_*(off_t)gkedata_79i+(off_t)((ssize_t)sizeof(struct gkedata_s80)-gkedata_85st+(ssize_t)(char*)(struct gkedata_s80*)(0)),SEEK_SET)==0&&fread(_65i_*(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1)+_64i_*gkedata_40i+_63i_*gkedata_41i+Vtot_,(ssize_t)sizeof(struct COMPLEX_),(((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1,diskimage_)==(((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1))ioerr(diskimage_);}else{  {int _66i_=((0+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/;do{{if(!(fseeko(diskimage_,_66i_*(off_t)(ssize_t)sizeof(struct COMPLEX_)+_65i_*(off_t)(ssize_t)sizeof(struct COMPLEX_)*(off_t)((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1)+_64i_*(off_t)gkedata_78i+_63i_*(off_t)gkedata_79i+(off_t)((ssize_t)sizeof(struct gkedata_s80)-gkedata_85st+(ssize_t)(char*)(struct gkedata_s80*)(0)) ,SEEK_SET)==0&&fread((struct COMPLEX_ *)(_66i_*(ssize_t)sizeof(struct COMPLEX_)+_65i_*(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1)+_64i_*gkedata_40i+_63i_*gkedata_41i+Vtot_),(ssize_t)sizeof(struct COMPLEX_),1,diskimage_)==1))ioerr(diskimage_);}_66i_--;}while(_66i_>=0);}};}_65i_++;}while(_65i_<=gkedata_39h);}};}_64i_--;}while(_64i_>=0);}}_63i_++;}while(_63i_<=gkedata_36h);}  errfclose(&diskimage_);
  pressure_name_=0;atblockexit(pressure_name_f,condfree,pressure_name_); {char *tmp; tmp=malloc(snprintf(NULL,0,"""pField""%d"".fld""",n_)+1); sprintf(tmp,"""pField""%d"".fld""",n_); if(pressure_name_)free(pressure_name_);pressure_name_=tmp;}errfopen(&pressuredata_,pressure_name_,O_RDWR|O_CREAT);  step0B_uiuj_67st=gkedata_88l*(ssize_t)sizeof(struct COMPLEX_);
step0B_uiuj_68st=(-1)*gkedata_91i+step0B_uiuj_67st;
  {int _69i_=(-1);do{{  {int _70i_=gkedata_46h;do{{if((ssize_t)sizeof(struct COMPLEX_)==(ssize_t)sizeof(struct COMPLEX_)&&(ssize_t)sizeof(struct COMPLEX_)==(ssize_t)sizeof(struct COMPLEX_)){if(!(fseeko(pressuredata_,_70i_*(off_t)gkedata_90i+_69i_*(off_t)gkedata_91i+(-step0B_uiuj_68st)+gkedata_52st,SEEK_SET)==0&&fread(_70i_*gkedata_49i+_69i_*gkedata_50i+ptot_+gkedata_52st,(ssize_t)sizeof(struct COMPLEX_),gkedata_48h-gkedata_47l+1,pressuredata_)==gkedata_48h-gkedata_47l+1))ioerr(pressuredata_);}else{  {int _71i_=gkedata_47l;do{{if(!(fseeko(pressuredata_,_71i_*(off_t)(ssize_t)sizeof(struct COMPLEX_)+_70i_*(off_t)gkedata_90i+_69i_*(off_t)gkedata_91i+(-step0B_uiuj_68st) ,SEEK_SET)==0&&fread((struct COMPLEX_ *)(_71i_*(ssize_t)sizeof(struct COMPLEX_)+_70i_*gkedata_49i+_69i_*gkedata_50i+ptot_),(ssize_t)sizeof(struct COMPLEX_),1,pressuredata_)==1))ioerr(pressuredata_);}_71i_++;}while(_71i_<=gkedata_48h);}};}_70i_--;}while(_70i_>=0);}}_69i_++;}while(_69i_<=gkedata_45h);}  errfclose(&pressuredata_);
  /*! Compute fluctuating field*/
  { {  {int _72i_=(-1);do{{(*(double *)(_72i_*gkedata_41i+(char*)&(*(struct COMPLEX_*)(Vtot_)).REAL_))-=(*(double *)(_72i_*(ssize_t)sizeof(struct MEANTERMS_)+(char*)&(*(struct MEANTERMS_*)(meantot_)).U_)) ;}_72i_++;}while(_72i_<=gkedata_36h);}} {  {int _74i_=(-1);do{{(*(double *)(_74i_*gkedata_41i+(char*)&(*(struct COMPLEX_*)((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+Vtot_)).REAL_))-=(*(double *)(_74i_*(ssize_t)sizeof(struct MEANTERMS_)+(char*)&(*(struct MEANTERMS_*)(meantot_)).W_)) ;}_74i_++;}while(_74i_<=gkedata_36h);}} {  {int _76i_=(-1);do{{{register double temp=(*(struct COMPLEX_*)(_76i_*gkedata_50i+ptot_)).REAL_-(*(double*)(_76i_*(ssize_t)sizeof(struct MEANTERMS_)+(char*)&(*(struct MEANTERMS_*)(meantot_)).P_));(*(struct COMPLEX_ *)(_76i_*gkedata_50i+ptot_)).IMAG_=(*(struct COMPLEX_*)(_76i_*gkedata_50i+ptot_)).IMAG_;(*(struct COMPLEX_ *)(_76i_*gkedata_50i+ptot_)).REAL_=temp;};}_76i_++;}while(_76i_<=gkedata_45h);}}}
  /*! Compute derivatives*/
  gkedata_131velocity_gradient(0,step0B_uiuj_1h,step0B_uiuj_6i,step0B_uiuj_2l,step0B_uiuj_3h,step0B_uiuj_5i,(-1),step0B_uiuj_4h,(ssize_t)sizeof(struct DERIVS_),Vder_);
  /*! Parseval theorem method for var and pstrain*/
   {int iy_= - 1  ;while(iy_<=ny_+1 ){{
    struct BALANCE_ *step0B_uiuj_78w;
step0B_uiuj_78w=(struct BALANCE_ *)(iy_*(ssize_t)sizeof(struct BALANCE_)+uiujtot_);
  {int ix_=gkedata_37h;do{{int iz_=gkedata_38l;do{ {
      char *step0B_uiuj_79w;
struct DERIVS_ *step0B_uiuj_80w;

      int step0B_uiuj_81c;
/*c=step0B_uiuj_81c*/

      step0B_uiuj_79w=iz_*(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1)+ix_*gkedata_40i+iy_*gkedata_41i+Vtot_;
step0B_uiuj_80w=(struct DERIVS_ *)(iy_*(ssize_t)sizeof(struct DERIVS_)+iz_*step0B_uiuj_5i+ix_*step0B_uiuj_6i+Vder_);
step0B_uiuj_81c=( ix_==0  ?1  :2);
 (*(double *)((ssize_t)sizeof(double)+(*step0B_uiuj_78w).var_-((ssize_t)sizeof(double))) )= (*(double *)((ssize_t)sizeof(double)+(*step0B_uiuj_78w).var_-((ssize_t)sizeof(double)))  )+ (double)(step0B_uiuj_81c)*((((*(struct COMPLEX_*)(step0B_uiuj_79w)).REAL_*(*(struct COMPLEX_*)(step0B_uiuj_79w)).REAL_+(*(struct COMPLEX_*)(step0B_uiuj_79w)).IMAG_*(*(struct COMPLEX_*)(step0B_uiuj_79w)).IMAG_)));   (*(double *)(2*(ssize_t)sizeof(double)+(*step0B_uiuj_78w).var_-((ssize_t)sizeof(double))) )= (*(double *)(2*(ssize_t)sizeof(double)+(*step0B_uiuj_78w).var_-((ssize_t)sizeof(double)))  )+ (double)(step0B_uiuj_81c)*((((*(struct COMPLEX_*)((ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_79w)).REAL_*(*(struct COMPLEX_*)((ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_79w)).REAL_+(*(struct COMPLEX_*)((ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_79w)).IMAG_*(*(struct COMPLEX_*)((ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_79w)).IMAG_)));   (*(double *)(3*(ssize_t)sizeof(double)+(*step0B_uiuj_78w).var_-((ssize_t)sizeof(double))) )= (*(double *)(3*(ssize_t)sizeof(double)+(*step0B_uiuj_78w).var_-((ssize_t)sizeof(double)))  )+ (double)(step0B_uiuj_81c)*((((*(struct COMPLEX_*)((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_79w)).REAL_*(*(struct COMPLEX_*)((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_79w)).REAL_+(*(struct COMPLEX_*)((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_79w)).IMAG_*(*(struct COMPLEX_*)((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_79w)).IMAG_)));
       (*(double *)(4*(ssize_t)sizeof(double)+(*step0B_uiuj_78w).var_-((ssize_t)sizeof(double))) )= (*(double *)(4*(ssize_t)sizeof(double)+(*step0B_uiuj_78w).var_-((ssize_t)sizeof(double)))  )+ (double)(step0B_uiuj_81c)*((((*(struct COMPLEX_*)(step0B_uiuj_79w)).REAL_*(*(struct COMPLEX_*)((ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_79w)).REAL_+(*(struct COMPLEX_*)(step0B_uiuj_79w)).IMAG_*(*(struct COMPLEX_*)((ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_79w)).IMAG_)));   (*(double *)(5*(ssize_t)sizeof(double)+(*step0B_uiuj_78w).var_-((ssize_t)sizeof(double))) )= (*(double *)(5*(ssize_t)sizeof(double)+(*step0B_uiuj_78w).var_-((ssize_t)sizeof(double)))  )+ (double)(step0B_uiuj_81c)*((((*(struct COMPLEX_*)(step0B_uiuj_79w)).REAL_*(*(struct COMPLEX_*)((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_79w)).REAL_+(*(struct COMPLEX_*)(step0B_uiuj_79w)).IMAG_*(*(struct COMPLEX_*)((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_79w)).IMAG_)));   (*(double *)(6*(ssize_t)sizeof(double)+(*step0B_uiuj_78w).var_-((ssize_t)sizeof(double))) )= (*(double *)(6*(ssize_t)sizeof(double)+(*step0B_uiuj_78w).var_-((ssize_t)sizeof(double)))  )+ (double)(step0B_uiuj_81c)*((((*(struct COMPLEX_*)((ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_79w)).REAL_*(*(struct COMPLEX_*)((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_79w)).REAL_+(*(struct COMPLEX_*)((ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_79w)).IMAG_*(*(struct COMPLEX_*)((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_79w)).IMAG_)));
       (*(double *)(2*(ssize_t)sizeof(double)+(*step0B_uiuj_78w).PHIptrsp_-((ssize_t)sizeof(double))) )= (*(double *)(2*(ssize_t)sizeof(double)+(*step0B_uiuj_78w).PHIptrsp_-((ssize_t)sizeof(double)))  )- (double)(2*step0B_uiuj_81c)*((((*(struct COMPLEX_*)((ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_79w)).REAL_*(*(struct COMPLEX_*)(iz_*(ssize_t)sizeof(struct COMPLEX_)+ix_*gkedata_49i+iy_*gkedata_50i+ptot_)).REAL_+(*(struct COMPLEX_*)((ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_79w)).IMAG_*(*(struct COMPLEX_*)(iz_*(ssize_t)sizeof(struct COMPLEX_)+ix_*gkedata_49i+iy_*gkedata_50i+ptot_)).IMAG_)));   (*(double *)(4*(ssize_t)sizeof(double)+(*step0B_uiuj_78w).PHIptrsp_-((ssize_t)sizeof(double))) )= (*(double *)(4*(ssize_t)sizeof(double)+(*step0B_uiuj_78w).PHIptrsp_-((ssize_t)sizeof(double)))  )- (double)(step0B_uiuj_81c)*((((*(struct COMPLEX_*)(step0B_uiuj_79w)).REAL_*(*(struct COMPLEX_*)(iz_*(ssize_t)sizeof(struct COMPLEX_)+ix_*gkedata_49i+iy_*gkedata_50i+ptot_)).REAL_+(*(struct COMPLEX_*)(step0B_uiuj_79w)).IMAG_*(*(struct COMPLEX_*)(iz_*(ssize_t)sizeof(struct COMPLEX_)+ix_*gkedata_49i+iy_*gkedata_50i+ptot_)).IMAG_)));    (*(double *)(6*(ssize_t)sizeof(double)+(*step0B_uiuj_78w).PHIptrsp_-((ssize_t)sizeof(double))) )= (*(double *)(6*(ssize_t)sizeof(double)+(*step0B_uiuj_78w).PHIptrsp_-((ssize_t)sizeof(double)))  )- (double)(step0B_uiuj_81c)*((((*(struct COMPLEX_*)((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_79w)).REAL_*(*(struct COMPLEX_*)(iz_*(ssize_t)sizeof(struct COMPLEX_)+ix_*gkedata_49i+iy_*gkedata_50i+ptot_)).REAL_+(*(struct COMPLEX_*)((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_79w)).IMAG_*(*(struct COMPLEX_*)(iz_*(ssize_t)sizeof(struct COMPLEX_)+ix_*gkedata_49i+iy_*gkedata_50i+ptot_)).IMAG_)));
       (*(double *)((ssize_t)sizeof(double)+(*step0B_uiuj_78w).pstrain_-((ssize_t)sizeof(double))) )= (*(double *)((ssize_t)sizeof(double)+(*step0B_uiuj_78w).pstrain_-((ssize_t)sizeof(double)))  )+ (double)(2*step0B_uiuj_81c)*((((*step0B_uiuj_80w).ux_.REAL_*(*(struct COMPLEX_*)(iz_*(ssize_t)sizeof(struct COMPLEX_)+ix_*gkedata_49i+iy_*gkedata_50i+ptot_)).REAL_+(*step0B_uiuj_80w).ux_.IMAG_*(*(struct COMPLEX_*)(iz_*(ssize_t)sizeof(struct COMPLEX_)+ix_*gkedata_49i+iy_*gkedata_50i+ptot_)).IMAG_)));   (*(double *)(4*(ssize_t)sizeof(double)+(*step0B_uiuj_78w).pstrain_-((ssize_t)sizeof(double))) )= (*(double *)(4*(ssize_t)sizeof(double)+(*step0B_uiuj_78w).pstrain_-((ssize_t)sizeof(double)))  )+ (double)(step0B_uiuj_81c)*((((*step0B_uiuj_80w).uy_.REAL_*(*(struct COMPLEX_*)(iz_*(ssize_t)sizeof(struct COMPLEX_)+ix_*gkedata_49i+iy_*gkedata_50i+ptot_)).REAL_+(*step0B_uiuj_80w).uy_.IMAG_*(*(struct COMPLEX_*)(iz_*(ssize_t)sizeof(struct COMPLEX_)+ix_*gkedata_49i+iy_*gkedata_50i+ptot_)).IMAG_)+((*step0B_uiuj_80w).vx_.REAL_*(*(struct COMPLEX_*)(iz_*(ssize_t)sizeof(struct COMPLEX_)+ix_*gkedata_49i+iy_*gkedata_50i+ptot_)).REAL_+(*step0B_uiuj_80w).vx_.IMAG_*(*(struct COMPLEX_*)(iz_*(ssize_t)sizeof(struct COMPLEX_)+ix_*gkedata_49i+iy_*gkedata_50i+ptot_)).IMAG_)));
       (*(double *)(2*(ssize_t)sizeof(double)+(*step0B_uiuj_78w).pstrain_-((ssize_t)sizeof(double))) )= (*(double *)(2*(ssize_t)sizeof(double)+(*step0B_uiuj_78w).pstrain_-((ssize_t)sizeof(double)))  )+ (double)(2*step0B_uiuj_81c)*((((*step0B_uiuj_80w).vy_.REAL_*(*(struct COMPLEX_*)(iz_*(ssize_t)sizeof(struct COMPLEX_)+ix_*gkedata_49i+iy_*gkedata_50i+ptot_)).REAL_+(*step0B_uiuj_80w).vy_.IMAG_*(*(struct COMPLEX_*)(iz_*(ssize_t)sizeof(struct COMPLEX_)+ix_*gkedata_49i+iy_*gkedata_50i+ptot_)).IMAG_)));   (*(double *)(5*(ssize_t)sizeof(double)+(*step0B_uiuj_78w).pstrain_-((ssize_t)sizeof(double))) )= (*(double *)(5*(ssize_t)sizeof(double)+(*step0B_uiuj_78w).pstrain_-((ssize_t)sizeof(double)))  )+ (double)(step0B_uiuj_81c)*((((*step0B_uiuj_80w).uz_.REAL_*(*(struct COMPLEX_*)(iz_*(ssize_t)sizeof(struct COMPLEX_)+ix_*gkedata_49i+iy_*gkedata_50i+ptot_)).REAL_+(*step0B_uiuj_80w).uz_.IMAG_*(*(struct COMPLEX_*)(iz_*(ssize_t)sizeof(struct COMPLEX_)+ix_*gkedata_49i+iy_*gkedata_50i+ptot_)).IMAG_)+((*step0B_uiuj_80w).wx_.REAL_*(*(struct COMPLEX_*)(iz_*(ssize_t)sizeof(struct COMPLEX_)+ix_*gkedata_49i+iy_*gkedata_50i+ptot_)).REAL_+(*step0B_uiuj_80w).wx_.IMAG_*(*(struct COMPLEX_*)(iz_*(ssize_t)sizeof(struct COMPLEX_)+ix_*gkedata_49i+iy_*gkedata_50i+ptot_)).IMAG_)));
       (*(double *)(3*(ssize_t)sizeof(double)+(*step0B_uiuj_78w).pstrain_-((ssize_t)sizeof(double))) )= (*(double *)(3*(ssize_t)sizeof(double)+(*step0B_uiuj_78w).pstrain_-((ssize_t)sizeof(double)))  )+ (double)(2*step0B_uiuj_81c)*((((*step0B_uiuj_80w).wz_.REAL_*(*(struct COMPLEX_*)(iz_*(ssize_t)sizeof(struct COMPLEX_)+ix_*gkedata_49i+iy_*gkedata_50i+ptot_)).REAL_+(*step0B_uiuj_80w).wz_.IMAG_*(*(struct COMPLEX_*)(iz_*(ssize_t)sizeof(struct COMPLEX_)+ix_*gkedata_49i+iy_*gkedata_50i+ptot_)).IMAG_)));   (*(double *)(6*(ssize_t)sizeof(double)+(*step0B_uiuj_78w).pstrain_-((ssize_t)sizeof(double))) )= (*(double *)(6*(ssize_t)sizeof(double)+(*step0B_uiuj_78w).pstrain_-((ssize_t)sizeof(double)))  )+ (double)(step0B_uiuj_81c)*((((*step0B_uiuj_80w).vz_.REAL_*(*(struct COMPLEX_*)(iz_*(ssize_t)sizeof(struct COMPLEX_)+ix_*gkedata_49i+iy_*gkedata_50i+ptot_)).REAL_+(*step0B_uiuj_80w).vz_.IMAG_*(*(struct COMPLEX_*)(iz_*(ssize_t)sizeof(struct COMPLEX_)+ix_*gkedata_49i+iy_*gkedata_50i+ptot_)).IMAG_)+((*step0B_uiuj_80w).wy_.REAL_*(*(struct COMPLEX_*)(iz_*(ssize_t)sizeof(struct COMPLEX_)+ix_*gkedata_49i+iy_*gkedata_50i+ptot_)).REAL_+(*step0B_uiuj_80w).wy_.IMAG_*(*(struct COMPLEX_*)(iz_*(ssize_t)sizeof(struct COMPLEX_)+ix_*gkedata_49i+iy_*gkedata_50i+ptot_)).IMAG_)));
    }iz_++;}while(iz_<=gkedata_39h);}ix_--;}while(ix_>=0);}
  }iy_+=1;};}
  /*! Pseudo-spectral method for psdiss and PHIttrsp*/
  fflush(NULL); ismp_=0  ;while(ismp_<32-1&&fork()){ismp_+=1;;};{

   {int iy_= - 1  ;while(iy_<=ny_+1){
     {int ix_=(ismp_*(nx_+1) / 32 ) ;while(ix_<=((ismp_+1)*(nx_+1) / 32 )-1){
      int step0B_uiuj_82h;
int step0B_uiuj_83h;
  int step0B_uiuj_86l;
int step0B_uiuj_87h;
ssize_t step0B_uiuj_88st;
ssize_t step0B_uiuj_89i;
int step0B_uiuj_90l;
int step0B_uiuj_91l;

      int step0B_uiuj_94h;
int step0B_uiuj_95h;
ssize_t step0B_uiuj_96i;
int step0B_uiuj_97l;
int step0B_uiuj_98h;
ssize_t step0B_uiuj_99st;
ssize_t step0B_uiuj_100i;
int step0B_uiuj_101l;
int step0B_uiuj_102l;
ssize_t step0B_uiuj_103st;
ssize_t step0B_uiuj_104st;
ssize_t step0B_uiuj_105i;
step0B_uiuj_82h=nz_;
step0B_uiuj_83h=nz_;
{char *step0B_uiuj_85_;

step0B_uiuj_85_=iy_*(ssize_t)sizeof(struct DERIVS_)+ix_*step0B_uiuj_6i+Vder_; {char *step0B_uiuj_84_=ix_*step0B_uiuj_12i+Vderd_;int step0B_uiuj_84_1=step0B_uiuj_82h; do{{ (*(struct DERIVS_ *)(step0B_uiuj_84_))=(*(struct DERIVS_ *)(step0B_uiuj_85_)); step0B_uiuj_85_ =step0B_uiuj_5i+step0B_uiuj_85_;}step0B_uiuj_84_+=(ssize_t)sizeof(struct DERIVS_);step0B_uiuj_84_1--;}while(step0B_uiuj_84_1>=0);}}step0B_uiuj_86l=nz_+1;
step0B_uiuj_87h=nzd_-nz_-1;
step0B_uiuj_88st=step0B_uiuj_86l*(ssize_t)sizeof(struct DERIVS_);
step0B_uiuj_89i=(ssize_t)sizeof(struct DERIVS_)*(step0B_uiuj_87h-step0B_uiuj_86l+1);
memset(step0B_uiuj_88st+ix_*step0B_uiuj_12i+Vderd_,0,step0B_uiuj_89i);  step0B_uiuj_90l= - nz_;
step0B_uiuj_91l= - nz_;
{char *step0B_uiuj_93_;

step0B_uiuj_93_=step0B_uiuj_90l*step0B_uiuj_5i+iy_*(ssize_t)sizeof(struct DERIVS_)+ix_*step0B_uiuj_6i+Vder_; {char *step0B_uiuj_92_=step0B_uiuj_90l*(ssize_t)sizeof(struct DERIVS_)+nzd_*(ssize_t)sizeof(struct DERIVS_)+ix_*step0B_uiuj_12i+Vderd_;int step0B_uiuj_92_1=(-1)-step0B_uiuj_90l; do{{ (*(struct DERIVS_ *)(step0B_uiuj_92_))=(*(struct DERIVS_ *)(step0B_uiuj_93_)); step0B_uiuj_93_ =step0B_uiuj_5i+step0B_uiuj_93_;}step0B_uiuj_92_+=(ssize_t)sizeof(struct DERIVS_);step0B_uiuj_92_1--;}while(step0B_uiuj_92_1>=0);}}step0B_uiuj_94h=nz_;
step0B_uiuj_95h=nz_;
step0B_uiuj_96i=(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1)*(step0B_uiuj_94h+1);
memcpy(ix_*gkedata_56i+Vd_,ix_*gkedata_40i+iy_*gkedata_41i+Vtot_,step0B_uiuj_96i);     step0B_uiuj_97l=nz_+1;
step0B_uiuj_98h=nzd_-nz_-1;
step0B_uiuj_99st=step0B_uiuj_97l*(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1);
step0B_uiuj_100i=(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1)*(step0B_uiuj_98h-step0B_uiuj_97l+1);
memset(step0B_uiuj_99st+ix_*gkedata_56i+Vd_,0,step0B_uiuj_100i);     step0B_uiuj_101l= - nz_;
step0B_uiuj_102l= - nz_;
step0B_uiuj_103st=step0B_uiuj_101l*(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1);
step0B_uiuj_104st=step0B_uiuj_102l*(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1);
step0B_uiuj_105i=(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1)*((-1)-step0B_uiuj_101l+1);
memcpy(step0B_uiuj_103st+nzd_*(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1)+ix_*gkedata_56i+Vd_,step0B_uiuj_104st+ix_*gkedata_40i+iy_*gkedata_41i+Vtot_,step0B_uiuj_105i);
      { char *step0B_uiuj_106w;
step0B_uiuj_106w=ix_*step0B_uiuj_12i+Vderd_;
{  {fft_1IFT(0,step0B_uiuj_11h,(ssize_t)sizeof(struct DERIVS_),((char*)&(*(struct DERIVS_ *)(step0B_uiuj_106w)).ux_),0,step0B_uiuj_11h,(ssize_t)sizeof(struct DERIVS_),((char*)&(*(struct DERIVS_ *)(step0B_uiuj_106w)).ux_));};  }{  {fft_1IFT(0,step0B_uiuj_11h,(ssize_t)sizeof(struct DERIVS_),((char*)&(*(struct DERIVS_ *)(step0B_uiuj_106w)).vx_),0,step0B_uiuj_11h,(ssize_t)sizeof(struct DERIVS_),((char*)&(*(struct DERIVS_ *)(step0B_uiuj_106w)).vx_));};  }{  {fft_1IFT(0,step0B_uiuj_11h,(ssize_t)sizeof(struct DERIVS_),((char*)&(*(struct DERIVS_ *)(step0B_uiuj_106w)).wx_),0,step0B_uiuj_11h,(ssize_t)sizeof(struct DERIVS_),((char*)&(*(struct DERIVS_ *)(step0B_uiuj_106w)).wx_));};  }{  {fft_1IFT(0,step0B_uiuj_11h,(ssize_t)sizeof(struct DERIVS_),((char*)&(*(struct DERIVS_ *)(step0B_uiuj_106w)).uy_),0,step0B_uiuj_11h,(ssize_t)sizeof(struct DERIVS_),((char*)&(*(struct DERIVS_ *)(step0B_uiuj_106w)).uy_));};  }{  {fft_1IFT(0,step0B_uiuj_11h,(ssize_t)sizeof(struct DERIVS_),((char*)&(*(struct DERIVS_ *)(step0B_uiuj_106w)).vy_),0,step0B_uiuj_11h,(ssize_t)sizeof(struct DERIVS_),((char*)&(*(struct DERIVS_ *)(step0B_uiuj_106w)).vy_));};  }{  {fft_1IFT(0,step0B_uiuj_11h,(ssize_t)sizeof(struct DERIVS_),((char*)&(*(struct DERIVS_ *)(step0B_uiuj_106w)).wy_),0,step0B_uiuj_11h,(ssize_t)sizeof(struct DERIVS_),((char*)&(*(struct DERIVS_ *)(step0B_uiuj_106w)).wy_));};  }{  {fft_1IFT(0,step0B_uiuj_11h,(ssize_t)sizeof(struct DERIVS_),((char*)&(*(struct DERIVS_ *)(step0B_uiuj_106w)).uz_),0,step0B_uiuj_11h,(ssize_t)sizeof(struct DERIVS_),((char*)&(*(struct DERIVS_ *)(step0B_uiuj_106w)).uz_));};  }{  {fft_1IFT(0,step0B_uiuj_11h,(ssize_t)sizeof(struct DERIVS_),((char*)&(*(struct DERIVS_ *)(step0B_uiuj_106w)).vz_),0,step0B_uiuj_11h,(ssize_t)sizeof(struct DERIVS_),((char*)&(*(struct DERIVS_ *)(step0B_uiuj_106w)).vz_));};  }{  {fft_1IFT(0,step0B_uiuj_11h,(ssize_t)sizeof(struct DERIVS_),((char*)&(*(struct DERIVS_ *)(step0B_uiuj_106w)).wz_),0,step0B_uiuj_11h,(ssize_t)sizeof(struct DERIVS_),((char*)&(*(struct DERIVS_ *)(step0B_uiuj_106w)).wz_));};  }}
      {    char *step0B_uiuj_107w;
step0B_uiuj_107w=ix_*gkedata_56i+Vd_;
{  {fft_1IFT(0,gkedata_55h,(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1),(0+step0B_uiuj_107w),0,gkedata_55h,(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1),(0+step0B_uiuj_107w));};  }{  {fft_1IFT(0,gkedata_55h,(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1),(0+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_107w),0,gkedata_55h,(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1),(0+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_107w));};  }{  {fft_1IFT(0,gkedata_55h,(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1),(0+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_107w),0,gkedata_55h,(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1),(0+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_107w));};  }}
    ix_+=1;};}
    if( ismp_==0 ){ int step0B_uiuj_108l;
int step0B_uiuj_109h;
ssize_t step0B_uiuj_110st;
ssize_t step0B_uiuj_111i;
int step0B_uiuj_112l;
int step0B_uiuj_113h;
ssize_t step0B_uiuj_114st;
ssize_t step0B_uiuj_115i;
step0B_uiuj_108l=nx_+1;
step0B_uiuj_109h=nxd_-1;
step0B_uiuj_110st=step0B_uiuj_108l*gkedata_56i;
step0B_uiuj_111i=gkedata_56i*(step0B_uiuj_109h-step0B_uiuj_108l+1);
memset(step0B_uiuj_110st+Vd_,0,step0B_uiuj_111i); step0B_uiuj_112l=nx_+1;
step0B_uiuj_113h=nxd_-1;
step0B_uiuj_114st=step0B_uiuj_112l*step0B_uiuj_12i;
step0B_uiuj_115i=step0B_uiuj_12i*(step0B_uiuj_113h-step0B_uiuj_112l+1);
memset(step0B_uiuj_114st+Vderd_,0,step0B_uiuj_115i);};
    {
  register int md116;
while(!((*barrier_)==(ismp_)))sigsuspend(&oldmask);
  (*barrier_)=(md116=((ismp_)+1) % (32),md116>=0?md116:md116+(32));  kill(0,SIGUSR1);
  while(!((*barrier_)<=(ismp_)))sigsuspend(&oldmask);
};
     {int iz_=(ismp_*(step0B_uiuj_11h+1) / 32 ) ;do{{
      { char *step0B_uiuj_117w;
step0B_uiuj_117w=iz_*(ssize_t)sizeof(struct DERIVS_)+Vderd_;
{  {fft_3RFT(0,step0B_uiuj_10h,step0B_uiuj_12i,((char*)&(*(struct DERIVS_ *)(step0B_uiuj_117w)).ux_),0,step0B_uiuj_10h,step0B_uiuj_12i,((char*)&(*(struct DERIVS_ *)(step0B_uiuj_117w)).ux_));};  }{  {fft_3RFT(0,step0B_uiuj_10h,step0B_uiuj_12i,((char*)&(*(struct DERIVS_ *)(step0B_uiuj_117w)).vx_),0,step0B_uiuj_10h,step0B_uiuj_12i,((char*)&(*(struct DERIVS_ *)(step0B_uiuj_117w)).vx_));};  }{  {fft_3RFT(0,step0B_uiuj_10h,step0B_uiuj_12i,((char*)&(*(struct DERIVS_ *)(step0B_uiuj_117w)).wx_),0,step0B_uiuj_10h,step0B_uiuj_12i,((char*)&(*(struct DERIVS_ *)(step0B_uiuj_117w)).wx_));};  }{  {fft_3RFT(0,step0B_uiuj_10h,step0B_uiuj_12i,((char*)&(*(struct DERIVS_ *)(step0B_uiuj_117w)).uy_),0,step0B_uiuj_10h,step0B_uiuj_12i,((char*)&(*(struct DERIVS_ *)(step0B_uiuj_117w)).uy_));};  }{  {fft_3RFT(0,step0B_uiuj_10h,step0B_uiuj_12i,((char*)&(*(struct DERIVS_ *)(step0B_uiuj_117w)).vy_),0,step0B_uiuj_10h,step0B_uiuj_12i,((char*)&(*(struct DERIVS_ *)(step0B_uiuj_117w)).vy_));};  }{  {fft_3RFT(0,step0B_uiuj_10h,step0B_uiuj_12i,((char*)&(*(struct DERIVS_ *)(step0B_uiuj_117w)).wy_),0,step0B_uiuj_10h,step0B_uiuj_12i,((char*)&(*(struct DERIVS_ *)(step0B_uiuj_117w)).wy_));};  }{  {fft_3RFT(0,step0B_uiuj_10h,step0B_uiuj_12i,((char*)&(*(struct DERIVS_ *)(step0B_uiuj_117w)).uz_),0,step0B_uiuj_10h,step0B_uiuj_12i,((char*)&(*(struct DERIVS_ *)(step0B_uiuj_117w)).uz_));};  }{  {fft_3RFT(0,step0B_uiuj_10h,step0B_uiuj_12i,((char*)&(*(struct DERIVS_ *)(step0B_uiuj_117w)).vz_),0,step0B_uiuj_10h,step0B_uiuj_12i,((char*)&(*(struct DERIVS_ *)(step0B_uiuj_117w)).vz_));};  }{  {fft_3RFT(0,step0B_uiuj_10h,step0B_uiuj_12i,((char*)&(*(struct DERIVS_ *)(step0B_uiuj_117w)).wz_),0,step0B_uiuj_10h,step0B_uiuj_12i,((char*)&(*(struct DERIVS_ *)(step0B_uiuj_117w)).wz_));};  }}
      {    char *step0B_uiuj_118w;
step0B_uiuj_118w=iz_*(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1)+Vd_;
{  {fft_3RFT(0,gkedata_54h,gkedata_56i,(0+step0B_uiuj_118w),0,gkedata_54h,gkedata_56i,(0+step0B_uiuj_118w));};  }{  {fft_3RFT(0,gkedata_54h,gkedata_56i,(0+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_118w),0,gkedata_54h,gkedata_56i,(0+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_118w));};  }{  {fft_3RFT(0,gkedata_54h,gkedata_56i,(0+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_118w),0,gkedata_54h,gkedata_56i,(0+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_118w));};  }}
        {int ix_=step0B_uiuj_10h;do{{ {
          struct DERIVS_ *step0B_uiuj_119w;
struct DERPRODSEXT_ *step0B_uiuj_120w;
char *step0B_uiuj_121w;
step0B_uiuj_119w=(struct DERIVS_ *)(iz_*(ssize_t)sizeof(struct DERIVS_)+ix_*step0B_uiuj_12i+Vderd_);
step0B_uiuj_120w=(struct DERPRODSEXT_ *)(iz_*(ssize_t)sizeof(struct DERPRODSEXT_)+ix_*step0B_uiuj_16i+VVderd_);
step0B_uiuj_121w=iz_*(ssize_t)sizeof(struct COMPLEX_)*((((ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_))/((ssize_t)sizeof(struct COMPLEX_))-1)/*SA22*/+1)+ix_*gkedata_56i+Vd_;
(*step0B_uiuj_120w).ux2_.REAL_=(*step0B_uiuj_119w).ux_.REAL_*(*step0B_uiuj_119w).ux_.REAL_;  (*step0B_uiuj_120w).ux2_.IMAG_=(*step0B_uiuj_119w).ux_.IMAG_*(*step0B_uiuj_119w).ux_.IMAG_;   (*step0B_uiuj_120w).uy2_.REAL_=(*step0B_uiuj_119w).uy_.REAL_*(*step0B_uiuj_119w).uy_.REAL_;  (*step0B_uiuj_120w).uy2_.IMAG_=(*step0B_uiuj_119w).uy_.IMAG_*(*step0B_uiuj_119w).uy_.IMAG_;   (*step0B_uiuj_120w).uz2_.REAL_=(*step0B_uiuj_119w).uz_.REAL_*(*step0B_uiuj_119w).uz_.REAL_;  (*step0B_uiuj_120w).uz2_.IMAG_=(*step0B_uiuj_119w).uz_.IMAG_*(*step0B_uiuj_119w).uz_.IMAG_;   (*step0B_uiuj_120w).vx2_.REAL_=(*step0B_uiuj_119w).vx_.REAL_*(*step0B_uiuj_119w).vx_.REAL_;  (*step0B_uiuj_120w).vx2_.IMAG_=(*step0B_uiuj_119w).vx_.IMAG_*(*step0B_uiuj_119w).vx_.IMAG_;   (*step0B_uiuj_120w).vy2_.REAL_=(*step0B_uiuj_119w).vy_.REAL_*(*step0B_uiuj_119w).vy_.REAL_;  (*step0B_uiuj_120w).vy2_.IMAG_=(*step0B_uiuj_119w).vy_.IMAG_*(*step0B_uiuj_119w).vy_.IMAG_;   (*step0B_uiuj_120w).vz2_.REAL_=(*step0B_uiuj_119w).vz_.REAL_*(*step0B_uiuj_119w).vz_.REAL_;  (*step0B_uiuj_120w).vz2_.IMAG_=(*step0B_uiuj_119w).vz_.IMAG_*(*step0B_uiuj_119w).vz_.IMAG_;
          (*step0B_uiuj_120w).wx2_.REAL_=(*step0B_uiuj_119w).wx_.REAL_*(*step0B_uiuj_119w).wx_.REAL_;  (*step0B_uiuj_120w).wx2_.IMAG_=(*step0B_uiuj_119w).wx_.IMAG_*(*step0B_uiuj_119w).wx_.IMAG_;   (*step0B_uiuj_120w).wy2_.REAL_=(*step0B_uiuj_119w).wy_.REAL_*(*step0B_uiuj_119w).wy_.REAL_;  (*step0B_uiuj_120w).wy2_.IMAG_=(*step0B_uiuj_119w).wy_.IMAG_*(*step0B_uiuj_119w).wy_.IMAG_;   (*step0B_uiuj_120w).wz2_.REAL_=(*step0B_uiuj_119w).wz_.REAL_*(*step0B_uiuj_119w).wz_.REAL_;  (*step0B_uiuj_120w).wz2_.IMAG_=(*step0B_uiuj_119w).wz_.IMAG_*(*step0B_uiuj_119w).wz_.IMAG_;   (*step0B_uiuj_120w).uxvx_.REAL_=(*step0B_uiuj_119w).ux_.REAL_*(*step0B_uiuj_119w).vx_.REAL_;  (*step0B_uiuj_120w).uxvx_.IMAG_=(*step0B_uiuj_119w).ux_.IMAG_*(*step0B_uiuj_119w).vx_.IMAG_;  (*step0B_uiuj_120w).uyvy_.REAL_=(*step0B_uiuj_119w).uy_.REAL_*(*step0B_uiuj_119w).vy_.REAL_;  (*step0B_uiuj_120w).uyvy_.IMAG_=(*step0B_uiuj_119w).uy_.IMAG_*(*step0B_uiuj_119w).vy_.IMAG_;  (*step0B_uiuj_120w).uzvz_.REAL_=(*step0B_uiuj_119w).uz_.REAL_*(*step0B_uiuj_119w).vz_.REAL_;  (*step0B_uiuj_120w).uzvz_.IMAG_=(*step0B_uiuj_119w).uz_.IMAG_*(*step0B_uiuj_119w).vz_.IMAG_;
          (*step0B_uiuj_120w).uxwx_.REAL_=(*step0B_uiuj_119w).ux_.REAL_*(*step0B_uiuj_119w).wx_.REAL_;  (*step0B_uiuj_120w).uxwx_.IMAG_=(*step0B_uiuj_119w).ux_.IMAG_*(*step0B_uiuj_119w).wx_.IMAG_;  (*step0B_uiuj_120w).uywy_.REAL_=(*step0B_uiuj_119w).uy_.REAL_*(*step0B_uiuj_119w).wy_.REAL_;  (*step0B_uiuj_120w).uywy_.IMAG_=(*step0B_uiuj_119w).uy_.IMAG_*(*step0B_uiuj_119w).wy_.IMAG_;  (*step0B_uiuj_120w).uzwz_.REAL_=(*step0B_uiuj_119w).uz_.REAL_*(*step0B_uiuj_119w).wz_.REAL_;  (*step0B_uiuj_120w).uzwz_.IMAG_=(*step0B_uiuj_119w).uz_.IMAG_*(*step0B_uiuj_119w).wz_.IMAG_;  (*step0B_uiuj_120w).vxwx_.REAL_=(*step0B_uiuj_119w).vx_.REAL_*(*step0B_uiuj_119w).wx_.REAL_;  (*step0B_uiuj_120w).vxwx_.IMAG_=(*step0B_uiuj_119w).vx_.IMAG_*(*step0B_uiuj_119w).wx_.IMAG_;  (*step0B_uiuj_120w).vywy_.REAL_=(*step0B_uiuj_119w).vy_.REAL_*(*step0B_uiuj_119w).wy_.REAL_;  (*step0B_uiuj_120w).vywy_.IMAG_=(*step0B_uiuj_119w).vy_.IMAG_*(*step0B_uiuj_119w).wy_.IMAG_;  (*step0B_uiuj_120w).vzwz_.REAL_=(*step0B_uiuj_119w).vz_.REAL_*(*step0B_uiuj_119w).wz_.REAL_;  (*step0B_uiuj_120w).vzwz_.IMAG_=(*step0B_uiuj_119w).vz_.IMAG_*(*step0B_uiuj_119w).wz_.IMAG_;
          (*(struct COMPLEX_ *)((ssize_t)sizeof(struct COMPLEX_)+iz_*(ssize_t)sizeof(struct COMPLEX_)*6+ix_*step0B_uiuj_20i+PHIttrspd_)).REAL_=(*(struct COMPLEX_ *)(0+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_121w)).REAL_*(*(struct COMPLEX_ *)(0+step0B_uiuj_121w)).REAL_*(*(struct COMPLEX_ *)(0+step0B_uiuj_121w)).REAL_;  (*(struct COMPLEX_ *)((ssize_t)sizeof(struct COMPLEX_)+iz_*(ssize_t)sizeof(struct COMPLEX_)*6+ix_*step0B_uiuj_20i+PHIttrspd_)).IMAG_=(*(struct COMPLEX_ *)(0+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_121w)).IMAG_*(*(struct COMPLEX_ *)(0+step0B_uiuj_121w)).IMAG_*(*(struct COMPLEX_ *)(0+step0B_uiuj_121w)).IMAG_;    (*(struct COMPLEX_ *)(2*(ssize_t)sizeof(struct COMPLEX_)+iz_*(ssize_t)sizeof(struct COMPLEX_)*6+ix_*step0B_uiuj_20i+PHIttrspd_)).REAL_=(*(struct COMPLEX_ *)(0+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_121w)).REAL_*(*(struct COMPLEX_ *)(0+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_121w)).REAL_*(*(struct COMPLEX_ *)(0+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_121w)).REAL_;  (*(struct COMPLEX_ *)(2*(ssize_t)sizeof(struct COMPLEX_)+iz_*(ssize_t)sizeof(struct COMPLEX_)*6+ix_*step0B_uiuj_20i+PHIttrspd_)).IMAG_=(*(struct COMPLEX_ *)(0+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_121w)).IMAG_*(*(struct COMPLEX_ *)(0+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_121w)).IMAG_*(*(struct COMPLEX_ *)(0+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_121w)).IMAG_;     (*(struct COMPLEX_ *)(3*(ssize_t)sizeof(struct COMPLEX_)+iz_*(ssize_t)sizeof(struct COMPLEX_)*6+ix_*step0B_uiuj_20i+PHIttrspd_)).REAL_=(*(struct COMPLEX_ *)(0+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_121w)).REAL_*(*(struct COMPLEX_ *)(0+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_121w)).REAL_*(*(struct COMPLEX_ *)(0+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_121w)).REAL_;  (*(struct COMPLEX_ *)(3*(ssize_t)sizeof(struct COMPLEX_)+iz_*(ssize_t)sizeof(struct COMPLEX_)*6+ix_*step0B_uiuj_20i+PHIttrspd_)).IMAG_=(*(struct COMPLEX_ *)(0+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_121w)).IMAG_*(*(struct COMPLEX_ *)(0+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_121w)).IMAG_*(*(struct COMPLEX_ *)(0+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_121w)).IMAG_;
          (*(struct COMPLEX_ *)(4*(ssize_t)sizeof(struct COMPLEX_)+iz_*(ssize_t)sizeof(struct COMPLEX_)*6+ix_*step0B_uiuj_20i+PHIttrspd_)).REAL_=(*(struct COMPLEX_ *)(0+step0B_uiuj_121w)).REAL_*(*(struct COMPLEX_ *)(0+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_121w)).REAL_*(*(struct COMPLEX_ *)(0+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_121w)).REAL_;  (*(struct COMPLEX_ *)(4*(ssize_t)sizeof(struct COMPLEX_)+iz_*(ssize_t)sizeof(struct COMPLEX_)*6+ix_*step0B_uiuj_20i+PHIttrspd_)).IMAG_=(*(struct COMPLEX_ *)(0+step0B_uiuj_121w)).IMAG_*(*(struct COMPLEX_ *)(0+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_121w)).IMAG_*(*(struct COMPLEX_ *)(0+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_121w)).IMAG_;    (*(struct COMPLEX_ *)(5*(ssize_t)sizeof(struct COMPLEX_)+iz_*(ssize_t)sizeof(struct COMPLEX_)*6+ix_*step0B_uiuj_20i+PHIttrspd_)).REAL_=(*(struct COMPLEX_ *)(0+step0B_uiuj_121w)).REAL_*(*(struct COMPLEX_ *)(0+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_121w)).REAL_*(*(struct COMPLEX_ *)(0+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_121w)).REAL_;  (*(struct COMPLEX_ *)(5*(ssize_t)sizeof(struct COMPLEX_)+iz_*(ssize_t)sizeof(struct COMPLEX_)*6+ix_*step0B_uiuj_20i+PHIttrspd_)).IMAG_=(*(struct COMPLEX_ *)(0+step0B_uiuj_121w)).IMAG_*(*(struct COMPLEX_ *)(0+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_121w)).IMAG_*(*(struct COMPLEX_ *)(0+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_121w)).IMAG_;     (*(struct COMPLEX_ *)(6*(ssize_t)sizeof(struct COMPLEX_)+iz_*(ssize_t)sizeof(struct COMPLEX_)*6+ix_*step0B_uiuj_20i+PHIttrspd_)).REAL_=(*(struct COMPLEX_ *)(0+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_121w)).REAL_*(*(struct COMPLEX_ *)(0+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_121w)).REAL_*(*(struct COMPLEX_ *)(0+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_121w)).REAL_;  (*(struct COMPLEX_ *)(6*(ssize_t)sizeof(struct COMPLEX_)+iz_*(ssize_t)sizeof(struct COMPLEX_)*6+ix_*step0B_uiuj_20i+PHIttrspd_)).IMAG_=(*(struct COMPLEX_ *)(0+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_121w)).IMAG_*(*(struct COMPLEX_ *)(0+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_121w)).IMAG_*(*(struct COMPLEX_ *)(0+(ssize_t)sizeof(struct COMPLEX_)+(ssize_t)sizeof(struct COMPLEX_)+step0B_uiuj_121w)).IMAG_; 
      }}ix_--;}while(ix_>=0);}
      { char *step0B_uiuj_122w;
step0B_uiuj_122w=iz_*(ssize_t)sizeof(struct DERPRODSEXT_)+VVderd_;
{  {fft_4HFT(0,step0B_uiuj_14h,step0B_uiuj_16i,((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_122w)).ux2_),0,step0B_uiuj_14h,step0B_uiuj_16i,((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_122w)).ux2_));};  }{  {fft_4HFT(0,step0B_uiuj_14h,step0B_uiuj_16i,((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_122w)).vx2_),0,step0B_uiuj_14h,step0B_uiuj_16i,((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_122w)).vx2_));};  }{  {fft_4HFT(0,step0B_uiuj_14h,step0B_uiuj_16i,((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_122w)).wx2_),0,step0B_uiuj_14h,step0B_uiuj_16i,((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_122w)).wx2_));};  }{  {fft_4HFT(0,step0B_uiuj_14h,step0B_uiuj_16i,((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_122w)).uy2_),0,step0B_uiuj_14h,step0B_uiuj_16i,((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_122w)).uy2_));};  }{  {fft_4HFT(0,step0B_uiuj_14h,step0B_uiuj_16i,((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_122w)).vy2_),0,step0B_uiuj_14h,step0B_uiuj_16i,((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_122w)).vy2_));};  }{  {fft_4HFT(0,step0B_uiuj_14h,step0B_uiuj_16i,((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_122w)).wy2_),0,step0B_uiuj_14h,step0B_uiuj_16i,((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_122w)).wy2_));};  }{  {fft_4HFT(0,step0B_uiuj_14h,step0B_uiuj_16i,((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_122w)).uz2_),0,step0B_uiuj_14h,step0B_uiuj_16i,((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_122w)).uz2_));};  }{  {fft_4HFT(0,step0B_uiuj_14h,step0B_uiuj_16i,((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_122w)).vz2_),0,step0B_uiuj_14h,step0B_uiuj_16i,((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_122w)).vz2_));};  }{  {fft_4HFT(0,step0B_uiuj_14h,step0B_uiuj_16i,((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_122w)).wz2_),0,step0B_uiuj_14h,step0B_uiuj_16i,((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_122w)).wz2_));};  }{  {fft_4HFT(0,step0B_uiuj_14h,step0B_uiuj_16i,((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_122w)).uxvx_),0,step0B_uiuj_14h,step0B_uiuj_16i,((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_122w)).uxvx_));};  }{  {fft_4HFT(0,step0B_uiuj_14h,step0B_uiuj_16i,((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_122w)).uyvy_),0,step0B_uiuj_14h,step0B_uiuj_16i,((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_122w)).uyvy_));};  }{  {fft_4HFT(0,step0B_uiuj_14h,step0B_uiuj_16i,((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_122w)).uzvz_),0,step0B_uiuj_14h,step0B_uiuj_16i,((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_122w)).uzvz_));};  }{  {fft_4HFT(0,step0B_uiuj_14h,step0B_uiuj_16i,((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_122w)).uxwx_),0,step0B_uiuj_14h,step0B_uiuj_16i,((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_122w)).uxwx_));};  }{  {fft_4HFT(0,step0B_uiuj_14h,step0B_uiuj_16i,((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_122w)).uywy_),0,step0B_uiuj_14h,step0B_uiuj_16i,((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_122w)).uywy_));};  }{  {fft_4HFT(0,step0B_uiuj_14h,step0B_uiuj_16i,((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_122w)).uzwz_),0,step0B_uiuj_14h,step0B_uiuj_16i,((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_122w)).uzwz_));};  }{  {fft_4HFT(0,step0B_uiuj_14h,step0B_uiuj_16i,((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_122w)).vxwx_),0,step0B_uiuj_14h,step0B_uiuj_16i,((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_122w)).vxwx_));};  }{  {fft_4HFT(0,step0B_uiuj_14h,step0B_uiuj_16i,((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_122w)).vywy_),0,step0B_uiuj_14h,step0B_uiuj_16i,((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_122w)).vywy_));};  }{  {fft_4HFT(0,step0B_uiuj_14h,step0B_uiuj_16i,((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_122w)).vzwz_),0,step0B_uiuj_14h,step0B_uiuj_16i,((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_122w)).vzwz_));};  }}
        {int i_=1;do{{ {fft_4HFT(0,step0B_uiuj_18h,step0B_uiuj_20i,(i_*(ssize_t)sizeof(struct COMPLEX_)+iz_*(ssize_t)sizeof(struct COMPLEX_)*6+PHIttrspd_),0,step0B_uiuj_18h,step0B_uiuj_20i,(i_*(ssize_t)sizeof(struct COMPLEX_)+iz_*(ssize_t)sizeof(struct COMPLEX_)*6+PHIttrspd_));} ;}i_++;}while(i_<=6);}
    }iz_+=1;}while(iz_<=((ismp_+1)*(step0B_uiuj_11h+1) / 32 )-1);}
    {
  register int md123;
while(!((*barrier_)==(ismp_)))sigsuspend(&oldmask);
  (*barrier_)=(md123=((ismp_)+1) % (32),md123>=0?md123:md123+(32));  kill(0,SIGUSR1);
  while(!((*barrier_)<=(ismp_)))sigsuspend(&oldmask);
};
     {int ix_=(ismp_*(nx_+1) / 32 ) ;do{{ {
      char *step0B_uiuj_124w;
step0B_uiuj_124w=ix_*step0B_uiuj_16i+VVderd_;
{  {fft_2FFT(0,step0B_uiuj_15h,(ssize_t)sizeof(struct DERPRODSEXT_),((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_124w)).ux2_),0,step0B_uiuj_15h,(ssize_t)sizeof(struct DERPRODSEXT_),((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_124w)).ux2_));};  }{  {fft_2FFT(0,step0B_uiuj_15h,(ssize_t)sizeof(struct DERPRODSEXT_),((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_124w)).vx2_),0,step0B_uiuj_15h,(ssize_t)sizeof(struct DERPRODSEXT_),((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_124w)).vx2_));};  }{  {fft_2FFT(0,step0B_uiuj_15h,(ssize_t)sizeof(struct DERPRODSEXT_),((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_124w)).wx2_),0,step0B_uiuj_15h,(ssize_t)sizeof(struct DERPRODSEXT_),((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_124w)).wx2_));};  }{  {fft_2FFT(0,step0B_uiuj_15h,(ssize_t)sizeof(struct DERPRODSEXT_),((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_124w)).uy2_),0,step0B_uiuj_15h,(ssize_t)sizeof(struct DERPRODSEXT_),((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_124w)).uy2_));};  }{  {fft_2FFT(0,step0B_uiuj_15h,(ssize_t)sizeof(struct DERPRODSEXT_),((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_124w)).vy2_),0,step0B_uiuj_15h,(ssize_t)sizeof(struct DERPRODSEXT_),((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_124w)).vy2_));};  }{  {fft_2FFT(0,step0B_uiuj_15h,(ssize_t)sizeof(struct DERPRODSEXT_),((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_124w)).wy2_),0,step0B_uiuj_15h,(ssize_t)sizeof(struct DERPRODSEXT_),((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_124w)).wy2_));};  }{  {fft_2FFT(0,step0B_uiuj_15h,(ssize_t)sizeof(struct DERPRODSEXT_),((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_124w)).uz2_),0,step0B_uiuj_15h,(ssize_t)sizeof(struct DERPRODSEXT_),((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_124w)).uz2_));};  }{  {fft_2FFT(0,step0B_uiuj_15h,(ssize_t)sizeof(struct DERPRODSEXT_),((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_124w)).vz2_),0,step0B_uiuj_15h,(ssize_t)sizeof(struct DERPRODSEXT_),((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_124w)).vz2_));};  }{  {fft_2FFT(0,step0B_uiuj_15h,(ssize_t)sizeof(struct DERPRODSEXT_),((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_124w)).wz2_),0,step0B_uiuj_15h,(ssize_t)sizeof(struct DERPRODSEXT_),((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_124w)).wz2_));};  }{  {fft_2FFT(0,step0B_uiuj_15h,(ssize_t)sizeof(struct DERPRODSEXT_),((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_124w)).uxvx_),0,step0B_uiuj_15h,(ssize_t)sizeof(struct DERPRODSEXT_),((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_124w)).uxvx_));};  }{  {fft_2FFT(0,step0B_uiuj_15h,(ssize_t)sizeof(struct DERPRODSEXT_),((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_124w)).uyvy_),0,step0B_uiuj_15h,(ssize_t)sizeof(struct DERPRODSEXT_),((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_124w)).uyvy_));};  }{  {fft_2FFT(0,step0B_uiuj_15h,(ssize_t)sizeof(struct DERPRODSEXT_),((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_124w)).uzvz_),0,step0B_uiuj_15h,(ssize_t)sizeof(struct DERPRODSEXT_),((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_124w)).uzvz_));};  }{  {fft_2FFT(0,step0B_uiuj_15h,(ssize_t)sizeof(struct DERPRODSEXT_),((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_124w)).uxwx_),0,step0B_uiuj_15h,(ssize_t)sizeof(struct DERPRODSEXT_),((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_124w)).uxwx_));};  }{  {fft_2FFT(0,step0B_uiuj_15h,(ssize_t)sizeof(struct DERPRODSEXT_),((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_124w)).uywy_),0,step0B_uiuj_15h,(ssize_t)sizeof(struct DERPRODSEXT_),((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_124w)).uywy_));};  }{  {fft_2FFT(0,step0B_uiuj_15h,(ssize_t)sizeof(struct DERPRODSEXT_),((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_124w)).uzwz_),0,step0B_uiuj_15h,(ssize_t)sizeof(struct DERPRODSEXT_),((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_124w)).uzwz_));};  }{  {fft_2FFT(0,step0B_uiuj_15h,(ssize_t)sizeof(struct DERPRODSEXT_),((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_124w)).vxwx_),0,step0B_uiuj_15h,(ssize_t)sizeof(struct DERPRODSEXT_),((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_124w)).vxwx_));};  }{  {fft_2FFT(0,step0B_uiuj_15h,(ssize_t)sizeof(struct DERPRODSEXT_),((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_124w)).vywy_),0,step0B_uiuj_15h,(ssize_t)sizeof(struct DERPRODSEXT_),((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_124w)).vywy_));};  }{  {fft_2FFT(0,step0B_uiuj_15h,(ssize_t)sizeof(struct DERPRODSEXT_),((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_124w)).vzwz_),0,step0B_uiuj_15h,(ssize_t)sizeof(struct DERPRODSEXT_),((char*)&(*(struct DERPRODSEXT_ *)(step0B_uiuj_124w)).vzwz_));};  }
        {int i_=1;do{{ {fft_2FFT(0,step0B_uiuj_19h,(ssize_t)sizeof(struct COMPLEX_)*6,(i_*(ssize_t)sizeof(struct COMPLEX_)+ix_*step0B_uiuj_20i+PHIttrspd_),0,step0B_uiuj_19h,(ssize_t)sizeof(struct COMPLEX_)*6,(i_*(ssize_t)sizeof(struct COMPLEX_)+ix_*step0B_uiuj_20i+PHIttrspd_));};  }i_++;}while(i_<=6);}
    }}ix_+=1;}while(ix_<=((ismp_+1)*(nx_+1) / 32 )-1);}
    {
  register int md125;
while(!((*barrier_)==(ismp_)))sigsuspend(&oldmask);
  (*barrier_)=(md125=((ismp_)+1) % (32),md125>=0?md125:md125+(32));  kill(0,SIGUSR1);
  while(!((*barrier_)<=(ismp_)))sigsuspend(&oldmask);
};
    if( ismp_==0 ){ {
      struct BALANCE_ *step0B_uiuj_126w;
step0B_uiuj_126w=(struct BALANCE_ *)(iy_*(ssize_t)sizeof(struct BALANCE_)+uiujtot_);
(*(double *)((ssize_t)sizeof(double)+(*step0B_uiuj_126w).psdiss_-((ssize_t)sizeof(double))))+=2.*ni_*((*(struct DERPRODSEXT_*)(VVderd_)).ux2_.REAL_+(*(struct DERPRODSEXT_*)(VVderd_)).uy2_.REAL_+(*(struct DERPRODSEXT_*)(VVderd_)).uz2_.REAL_);  (*(double *)(4*(ssize_t)sizeof(double)+(*step0B_uiuj_126w).psdiss_-((ssize_t)sizeof(double))))+=2.*ni_*((*(struct DERPRODSEXT_*)(VVderd_)).uxvx_.REAL_+(*(struct DERPRODSEXT_*)(VVderd_)).uyvy_.REAL_+(*(struct DERPRODSEXT_*)(VVderd_)).uzvz_.REAL_);  (*(double *)((ssize_t)sizeof(double)+(*step0B_uiuj_126w).PHIttrsp_-((ssize_t)sizeof(double))))-=(*(struct COMPLEX_ *)((ssize_t)sizeof(struct COMPLEX_)+PHIttrspd_)).REAL_;  (*(double *)(4*(ssize_t)sizeof(double)+(*step0B_uiuj_126w).PHIttrsp_-((ssize_t)sizeof(double))))-=(*(struct COMPLEX_ *)(4*(ssize_t)sizeof(struct COMPLEX_)+PHIttrspd_)).REAL_;
      (*(double *)(2*(ssize_t)sizeof(double)+(*step0B_uiuj_126w).psdiss_-((ssize_t)sizeof(double))))+=2.*ni_*((*(struct DERPRODSEXT_*)(VVderd_)).vx2_.REAL_+(*(struct DERPRODSEXT_*)(VVderd_)).vy2_.REAL_+(*(struct DERPRODSEXT_*)(VVderd_)).vz2_.REAL_);  (*(double *)(5*(ssize_t)sizeof(double)+(*step0B_uiuj_126w).psdiss_-((ssize_t)sizeof(double))))+=2.*ni_*((*(struct DERPRODSEXT_*)(VVderd_)).uxwx_.REAL_+(*(struct DERPRODSEXT_*)(VVderd_)).uywy_.REAL_+(*(struct DERPRODSEXT_*)(VVderd_)).uzwz_.REAL_);  (*(double *)(2*(ssize_t)sizeof(double)+(*step0B_uiuj_126w).PHIttrsp_-((ssize_t)sizeof(double))))-=(*(struct COMPLEX_ *)(2*(ssize_t)sizeof(struct COMPLEX_)+PHIttrspd_)).REAL_;  (*(double *)(4*(ssize_t)sizeof(double)+(*step0B_uiuj_126w).PHIttrsp_-((ssize_t)sizeof(double))))-=(*(struct COMPLEX_ *)(5*(ssize_t)sizeof(struct COMPLEX_)+PHIttrspd_)).REAL_;
      (*(double *)(3*(ssize_t)sizeof(double)+(*step0B_uiuj_126w).psdiss_-((ssize_t)sizeof(double))))+=2.*ni_*((*(struct DERPRODSEXT_*)(VVderd_)).wx2_.REAL_+(*(struct DERPRODSEXT_*)(VVderd_)).wy2_.REAL_+(*(struct DERPRODSEXT_*)(VVderd_)).wz2_.REAL_);  (*(double *)(6*(ssize_t)sizeof(double)+(*step0B_uiuj_126w).psdiss_-((ssize_t)sizeof(double))))+=2.*ni_*((*(struct DERPRODSEXT_*)(VVderd_)).vxwx_.REAL_+(*(struct DERPRODSEXT_*)(VVderd_)).vywy_.REAL_+(*(struct DERPRODSEXT_*)(VVderd_)).vzwz_.REAL_);  (*(double *)(3*(ssize_t)sizeof(double)+(*step0B_uiuj_126w).PHIttrsp_-((ssize_t)sizeof(double))))-=(*(struct COMPLEX_ *)(3*(ssize_t)sizeof(struct COMPLEX_)+PHIttrspd_)).REAL_;  (*(double *)(4*(ssize_t)sizeof(double)+(*step0B_uiuj_126w).PHIttrsp_-((ssize_t)sizeof(double))))-=(*(struct COMPLEX_ *)(6*(ssize_t)sizeof(struct COMPLEX_)+PHIttrspd_)).REAL_;
    }};
  iy_+=1;};}
  } if(ismp_<32-1)exit(0);;
 ismp_=0  ;while(ismp_<32-1){if(wait(NULL)<0)traphandler("wait");ismp_+=1;;};
freemem(&mketot_f);n_+= 2;};}fields_exit:;

/*! var,PHIttrsp,psdiss,pstrain*/
  {int i_=1;do{{int iy_=(-1);do{{ { struct BALANCE_ *step0B_uiuj_127w;
step0B_uiuj_127w=(struct BALANCE_ *)(iy_*(ssize_t)sizeof(struct BALANCE_)+uiujtot_);
(*(double *)(i_*(ssize_t)sizeof(double)+(*step0B_uiuj_127w).var_-((ssize_t)sizeof(double))))/=(double)(nftot_); (*(double *)(i_*(ssize_t)sizeof(double)+(*step0B_uiuj_127w).PHIptrsp_-((ssize_t)sizeof(double))))/=(double)(nftot_); (*(double *)(i_*(ssize_t)sizeof(double)+(*step0B_uiuj_127w).PHIttrsp_-((ssize_t)sizeof(double))))/=(double)(nftot_); (*(double *)(i_*(ssize_t)sizeof(double)+(*step0B_uiuj_127w).psdiss_-((ssize_t)sizeof(double))))/=(double)(nftot_); (*(double *)(i_*(ssize_t)sizeof(double)+(*step0B_uiuj_127w).pstrain_-((ssize_t)sizeof(double))))/=(double)(nftot_);}}iy_++;}while(iy_<=step0B_uiuj_24h);}i_++;}while(i_<=6);}
/*! PHIvdiff, vdiff*/
  {int i_=1;do{{ {  gkedata_130deriv((-1),step0B_uiuj_24h,(ssize_t)sizeof(struct BALANCE_),i_*(ssize_t)sizeof(double)+(char*)(*(struct BALANCE_*)(uiujtot_)).var_-((ssize_t)sizeof(double)),(-1),step0B_uiuj_24h,(ssize_t)sizeof(struct BALANCE_),i_*(ssize_t)sizeof(double)+(char*)(*(struct BALANCE_*)(uiujtot_)).PHIvdiff_-((ssize_t)sizeof(double))); {  {int _128i_=(-1);do{{(*(double *)(_128i_*(ssize_t)sizeof(struct BALANCE_)+i_*(ssize_t)sizeof(double)+(char*)(*(struct BALANCE_*)(uiujtot_)).PHIvdiff_-((ssize_t)sizeof(double))))*=ni_ ;}_128i_++;}while(_128i_<=step0B_uiuj_24h);}} }}i_++;}while(i_<=6);} 
  {int i_=1;do{{ { gkedata_129deriv2((-1),step0B_uiuj_24h,(ssize_t)sizeof(struct BALANCE_),i_*(ssize_t)sizeof(double)+(char*)(*(struct BALANCE_*)(uiujtot_)).var_-((ssize_t)sizeof(double)),(-1),step0B_uiuj_24h,(ssize_t)sizeof(struct BALANCE_),i_*(ssize_t)sizeof(double)+(char*)(*(struct BALANCE_*)(uiujtot_)).vdiff_-((ssize_t)sizeof(double)));    {  {int _129i_=(-1);do{{(*(double *)(_129i_*(ssize_t)sizeof(struct BALANCE_)+i_*(ssize_t)sizeof(double)+(char*)(*(struct BALANCE_*)(uiujtot_)).vdiff_-((ssize_t)sizeof(double))))*=ni_ ;}_129i_++;}while(_129i_<=step0B_uiuj_24h);}}    }}i_++;}while(i_<=6);} 
/*! ttrsp*/
  {int i_=1;do{{ { gkedata_130deriv((-1),step0B_uiuj_24h,(ssize_t)sizeof(struct BALANCE_),i_*(ssize_t)sizeof(double)+(char*)(*(struct BALANCE_*)(uiujtot_)).PHIttrsp_-((ssize_t)sizeof(double)),(-1),step0B_uiuj_24h,(ssize_t)sizeof(struct BALANCE_),i_*(ssize_t)sizeof(double)+(char*)(*(struct BALANCE_*)(uiujtot_)).ttrsp_-((ssize_t)sizeof(double))); }}i_++;}while(i_<=6);} 
/*! ptrsp*/
  {int i_=1;do{{ { gkedata_130deriv((-1),step0B_uiuj_24h,(ssize_t)sizeof(struct BALANCE_),i_*(ssize_t)sizeof(double)+(char*)(*(struct BALANCE_*)(uiujtot_)).PHIptrsp_-((ssize_t)sizeof(double)),(-1),step0B_uiuj_24h,(ssize_t)sizeof(struct BALANCE_),i_*(ssize_t)sizeof(double)+(char*)(*(struct BALANCE_*)(uiujtot_)).ptrsp_-((ssize_t)sizeof(double))); }}i_++;}while(i_<=6);} 
/*! prod*/
  {int iy_=(-1);do{{ { struct MEANTERMS_ *step0B_uiuj_130w;
struct BALANCE_ *step0B_uiuj_131w;
step0B_uiuj_130w=(struct MEANTERMS_ *)(iy_*(ssize_t)sizeof(struct MEANTERMS_)+meantot_);
step0B_uiuj_131w=(struct BALANCE_ *)(iy_*(ssize_t)sizeof(struct BALANCE_)+uiujtot_);
(*(double *)((ssize_t)sizeof(double)+(*step0B_uiuj_131w).prod_-((ssize_t)sizeof(double))))=-2.*(*(double *)(4*(ssize_t)sizeof(double)+(*step0B_uiuj_131w).var_-((ssize_t)sizeof(double))))*(*step0B_uiuj_130w).Uy_; (*(double *)(3*(ssize_t)sizeof(double)+(*step0B_uiuj_131w).prod_-((ssize_t)sizeof(double))))=-2.*(*(double *)(6*(ssize_t)sizeof(double)+(*step0B_uiuj_131w).var_-((ssize_t)sizeof(double))))*(*step0B_uiuj_130w).Wy_; (*(double *)(4*(ssize_t)sizeof(double)+(*step0B_uiuj_131w).prod_-((ssize_t)sizeof(double))))= - (*(double *)(2*(ssize_t)sizeof(double)+(*step0B_uiuj_131w).var_-((ssize_t)sizeof(double))))*(*step0B_uiuj_130w).Uy_; (*(double *)(5*(ssize_t)sizeof(double)+(*step0B_uiuj_131w).prod_-((ssize_t)sizeof(double))))= - (*(double *)(4*(ssize_t)sizeof(double)+(*step0B_uiuj_131w).var_-((ssize_t)sizeof(double))))*(*step0B_uiuj_130w).Wy_-(*(double *)(6*(ssize_t)sizeof(double)+(*step0B_uiuj_131w).var_-((ssize_t)sizeof(double))))*(*step0B_uiuj_130w).Uy_; (*(double *)(6*(ssize_t)sizeof(double)+(*step0B_uiuj_131w).prod_-((ssize_t)sizeof(double))))= - (*(double *)(2*(ssize_t)sizeof(double)+(*step0B_uiuj_131w).var_-((ssize_t)sizeof(double))))*(*step0B_uiuj_130w).Wy_; }}iy_++;}while(iy_<=step0B_uiuj_22h);}
  {int iy_=(-1);do{{ { struct MEANTERMS_ *step0B_uiuj_132w;
struct BALANCE_ *step0B_uiuj_133w;
struct MKETERMS_ *step0B_uiuj_134w;
step0B_uiuj_132w=(struct MEANTERMS_ *)(iy_*(ssize_t)sizeof(struct MEANTERMS_)+meantot_);
step0B_uiuj_133w=(struct BALANCE_ *)(iy_*(ssize_t)sizeof(struct BALANCE_)+uiujtot_);
step0B_uiuj_134w=(struct MKETERMS_ *)(iy_*(ssize_t)sizeof(struct MKETERMS_)+mketot_);
(*step0B_uiuj_134w).produv_= - 0.5*(*(double *)((ssize_t)sizeof(double)+(*step0B_uiuj_133w).prod_-((ssize_t)sizeof(double)))); (*step0B_uiuj_134w).prodvw_= - 0.5*(*(double *)(3*(ssize_t)sizeof(double)+(*step0B_uiuj_133w).prod_-((ssize_t)sizeof(double))) );}}iy_++;}while(iy_<=step0B_uiuj_22h);}
/*! dissU(MKE) and dissW(MKE)*/
  {int iy_=(-1);do{{ { struct MEANTERMS_ *step0B_uiuj_135w;
struct MKETERMS_ *step0B_uiuj_136w;
step0B_uiuj_135w=(struct MEANTERMS_ *)(iy_*(ssize_t)sizeof(struct MEANTERMS_)+meantot_);
step0B_uiuj_136w=(struct MKETERMS_ *)(iy_*(ssize_t)sizeof(struct MKETERMS_)+mketot_);
(*step0B_uiuj_136w).dissU_=ni_*((*step0B_uiuj_135w).Uy_*(*step0B_uiuj_135w).Uy_); (*step0B_uiuj_136w).dissW_=ni_*((*step0B_uiuj_135w).Wy_*(*step0B_uiuj_135w).Wy_);}}iy_++;}while(iy_<=step0B_uiuj_22h);}
/*! ttrsp(MKE)*/
  {int iy_=(-1);do{{ { struct MEANTERMS_ *step0B_uiuj_137w;
struct BALANCE_ *step0B_uiuj_138w;
struct MKETERMS_ *step0B_uiuj_139w;
step0B_uiuj_137w=(struct MEANTERMS_ *)(iy_*(ssize_t)sizeof(struct MEANTERMS_)+meantot_);
step0B_uiuj_138w=(struct BALANCE_ *)(iy_*(ssize_t)sizeof(struct BALANCE_)+uiujtot_);
step0B_uiuj_139w=(struct MKETERMS_ *)(iy_*(ssize_t)sizeof(struct MKETERMS_)+mketot_);
(*(struct MKETERMS_ *)(iy_*(ssize_t)sizeof(struct MKETERMS_)+mketot_)).PHIttrsp_= - (*(double *)(4*(ssize_t)sizeof(double)+(*step0B_uiuj_138w).var_-((ssize_t)sizeof(double))))*(*step0B_uiuj_137w).U_-(*(double *)(6*(ssize_t)sizeof(double)+(*step0B_uiuj_138w).var_-((ssize_t)sizeof(double))))*(*step0B_uiuj_137w).W_ ;}}iy_++;}while(iy_<=step0B_uiuj_22h);}
{ gkedata_130deriv((-1),step0B_uiuj_26h,(ssize_t)sizeof(struct MKETERMS_),(char*)&(*(struct MKETERMS_ *)(mketot_)).PHIttrsp_,(-1),step0B_uiuj_26h,(ssize_t)sizeof(struct MKETERMS_),(char*)&(*(struct MKETERMS_ *)(mketot_)).ttrsp_); }
/*! vdiff(MKE)*/
  {int iy_=(-1);do{{ { struct MEANTERMS_ *step0B_uiuj_140w;
struct MKETERMS_ *step0B_uiuj_141w;
step0B_uiuj_140w=(struct MEANTERMS_ *)(iy_*(ssize_t)sizeof(struct MEANTERMS_)+meantot_);
step0B_uiuj_141w=(struct MKETERMS_ *)(iy_*(ssize_t)sizeof(struct MKETERMS_)+mketot_);
(*step0B_uiuj_141w).PHIvdiff_=ni_*((*step0B_uiuj_140w).U_*(*step0B_uiuj_140w).Uy_+(*step0B_uiuj_140w).W_*(*step0B_uiuj_140w).Wy_) ;}}iy_++;}while(iy_<=step0B_uiuj_22h);}
{ gkedata_130deriv((-1),step0B_uiuj_26h,(ssize_t)sizeof(struct MKETERMS_),(char*)&(*(struct MKETERMS_ *)(mketot_)).PHIvdiff_,(-1),step0B_uiuj_26h,(ssize_t)sizeof(struct MKETERMS_),(char*)&(*(struct MKETERMS_ *)(mketot_)).vdiff_);  }
/*! pump(MKE)*/
{ double step0B_uiuj_143m;
step0B_uiuj_143m=0.5*((*(double *)(&(*(struct MEANTERMS_*)(mean_)).Uy_))-(*(double *)(ny_*(ssize_t)sizeof(struct MEANTERMS_)+(char*)&(*(struct MEANTERMS_*)(mean_)).Uy_)));
{  {int _142i_=(-1);do{{(*(double *)(_142i_*(ssize_t)sizeof(struct MKETERMS_)+(char*)&(*(struct MKETERMS_*)(mketot_)).pump_))=ni_*(*(double *)(_142i_*(ssize_t)sizeof(struct MEANTERMS_)+(char*)&(*(struct MEANTERMS_*)(mean_)).U_))*step0B_uiuj_143m ;}_142i_++;}while(_142i_<=step0B_uiuj_26h);}}}

/*! Write to binary file*/
/*! ------------------------------------*/
 errfopen(&uiujimage_ ,"uiuj.bin",O_RDWR|O_CREAT);
step0B_uiuj_144h=ny_+1;
step0B_uiuj_145h=ny_+1;
if((ssize_t)sizeof(struct MEANTERMS_)==(ssize_t)sizeof(struct MEANTERMS_)&&(ssize_t)sizeof(struct MEANTERMS_)==(ssize_t)sizeof(struct MEANTERMS_)){if(!(fseeko(uiujimage_,(off_t)(-gkedata_97st+(ssize_t)(char*)(void*)(0))+gkedata_97st,SEEK_SET)==0&&fwrite(meantot_+gkedata_97st,(ssize_t)sizeof(struct MEANTERMS_),step0B_uiuj_144h-(-1)+1,uiujimage_)==step0B_uiuj_144h-(-1)+1))ioerr(uiujimage_);}else{  {int _146i_=(-1);do{{if(!(fseeko(uiujimage_,_146i_*(off_t)(ssize_t)sizeof(struct MEANTERMS_)+(off_t)(-gkedata_97st+(ssize_t)(char*)(void*)(0)),SEEK_SET)==0&&fwrite((struct MEANTERMS_*)(_146i_*(ssize_t)sizeof(struct MEANTERMS_)+meantot_),(ssize_t)sizeof(struct MEANTERMS_),1,uiujimage_)==1))ioerr(uiujimage_);}_146i_++;}while(_146i_<=step0B_uiuj_144h);}};
    step0B_uiuj_147h=ny_+1;
step0B_uiuj_148h=ny_+1;
if((ssize_t)sizeof(struct MKETERMS_)==(ssize_t)sizeof(struct MKETERMS_)&&(ssize_t)sizeof(struct MKETERMS_)==(ssize_t)sizeof(struct MKETERMS_)){if(!(fseeko(uiujimage_,(off_t)(gkedata_96i-gkedata_99st+(ssize_t)(char*)(void*)(0))+gkedata_99st,SEEK_SET)==0&&fwrite(mketot_+gkedata_99st,(ssize_t)sizeof(struct MKETERMS_),step0B_uiuj_147h-(-1)+1,uiujimage_)==step0B_uiuj_147h-(-1)+1))ioerr(uiujimage_);}else{  {int _149i_=(-1);do{{if(!(fseeko(uiujimage_,_149i_*(off_t)(ssize_t)sizeof(struct MKETERMS_)+(off_t)(gkedata_96i-gkedata_99st+(ssize_t)(char*)(void*)(0)),SEEK_SET)==0&&fwrite((struct MKETERMS_*)(_149i_*(ssize_t)sizeof(struct MKETERMS_)+mketot_),(ssize_t)sizeof(struct MKETERMS_),1,uiujimage_)==1))ioerr(uiujimage_);}_149i_++;}while(_149i_<=step0B_uiuj_147h);}};
    step0B_uiuj_150h=ny_+1;
step0B_uiuj_151h=ny_+1;
if((ssize_t)sizeof(struct BALANCE_)==(ssize_t)sizeof(struct BALANCE_)&&(ssize_t)sizeof(struct BALANCE_)==(ssize_t)sizeof(struct BALANCE_)){if(!(fseeko(uiujimage_,(off_t)((gkedata_96i+gkedata_98i)-gkedata_101st+(ssize_t)(char*)(void*)(0))+gkedata_101st,SEEK_SET)==0&&fwrite(uiujtot_+gkedata_101st,(ssize_t)sizeof(struct BALANCE_),step0B_uiuj_150h-(-1)+1,uiujimage_)==step0B_uiuj_150h-(-1)+1))ioerr(uiujimage_);}else{  {int _152i_=(-1);do{{if(!(fseeko(uiujimage_,_152i_*(off_t)(ssize_t)sizeof(struct BALANCE_)+(off_t)((gkedata_96i+gkedata_98i)-gkedata_101st+(ssize_t)(char*)(void*)(0)),SEEK_SET)==0&&fwrite((struct BALANCE_*)(_152i_*(ssize_t)sizeof(struct BALANCE_)+uiujtot_),(ssize_t)sizeof(struct BALANCE_),1,uiujimage_)==1))ioerr(uiujimage_);}_152i_++;}while(_152i_<=step0B_uiuj_150h);}};
errfclose(&uiujimage_);

/*! Be polite and say goodbye*/
/*! ------------------------------------*/
if( (iproc_==nproc_) ){  fprintf(stdout,"""Finished!""");putc('\n',stdout);};
freemem(es);return 0;}
