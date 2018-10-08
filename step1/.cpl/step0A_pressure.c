/**/

#define _GNU_SOURCE
#define _FILE_OFFSET_BITS 64
#define _LARGE_FILES
#define printERR fprintf(stderr,"\r%s: PROGRAM HALTED  \n",errormessage);fflush(stderr)




#include <unistd.h>

#include <stdlib.h>
/*** struct __pthread_mutex_s
 {
 int __lock;
 unsigned int __count;
 int __owner;
unsigned int __nusers;
int __kind;
short __spins;
 short __elision;
 __pthread_list_t __list;
} __data ununderstood ***/

#include <stdio.h>

#include <fcntl.h>

#include <math.h>

#include <limits.h>

#include <float.h>

#include <string.h>


#include <sys/time.h>

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
/*gamma=0*/

/*!USE rtchecks*/
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


/*nsmp=28*/
extern int iproc_;
extern int nproc_;
/*bufsize=800*/
/*baseport=(IPPORT_USERRESERVED+111)*/
extern struct freefunc prev_f;extern FILE *prev_;
extern struct freefunc next_f;extern FILE *next_;
void rbmatmod_1LUdecompStep(const int A_l,const int A_h,const ssize_t A_i,char *A__);
void rbmatmod_2LeftLUDivStep1(const int x_l,const int x_h,const ssize_t x_i,char *x__,const int A_l,const int A_h,const ssize_t A_i,char *A__,const int t_l,const int t_h,const ssize_t t_i,char *t__);
void rbmatmod_3LeftLUDivStep2(const int x_l,const int x_h,const ssize_t x_i,char *x__,const int A_l,const int A_h,const ssize_t A_i,char *A__);
void rbmatmod_4RightLUDivStep1(const int x_l,const int x_h,const ssize_t x_i,char *x__,const int t_l,const int t_h,const ssize_t t_i,char *t__,const int A_l,const int A_h,const ssize_t A_i,char *A__);
void rbmatmod_5RightLUDivStep2(const int x_l,const int x_h,const ssize_t x_i,char *x__,const int A_l,const int A_h,const ssize_t A_i,char *A__);
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
void dnsdata_1read_initial_data();
extern int reread_;
void dnsdata_2kill_received(int signum_);
extern int dnsdata_4nyl;
/*nyl=dnsdata_4nyl*/
extern int dnsdata_5nyh;
/*nyh=dnsdata_5nyh*/
extern int dnsdata_6M;
extern int dnsdata_7l;
extern int dnsdata_8m;
extern int dnsdata_9h;
extern ssize_t dnsdata_10i;
extern ssize_t dnsdata_11st;
extern struct freefunc y_f;extern char *y_;
extern ssize_t dnsdata_13st;
struct dnsdata_s12{char d0_[(ssize_t)sizeof(double)*(2-(-2)+1)];char d1_[(ssize_t)sizeof(double)*(2-(-2)+1)];char d2_[(ssize_t)sizeof(double)*(2-(-2)+1)];char d4_[(ssize_t)sizeof(double)*(2-(-2)+1)];};extern int dnsdata_14M;
extern int dnsdata_15l;
extern int dnsdata_16m;
extern int dnsdata_17h;
extern ssize_t dnsdata_18i;
extern ssize_t dnsdata_19st;
extern struct freefunc derivatives_f;extern char *derivatives_;
extern char d040_[(ssize_t)sizeof(double)*(2-(-2)+1)];
extern char d140_[(ssize_t)sizeof(double)*(2-(-2)+1)];
extern char d240_[(ssize_t)sizeof(double)*(2-(-2)+1)];
extern char d340_[(ssize_t)sizeof(double)*(2-(-2)+1)];
extern char d14m1_[(ssize_t)sizeof(double)*(2-(-2)+1)];
extern char d24m1_[(ssize_t)sizeof(double)*(2-(-2)+1)];
extern char d04n_[(ssize_t)sizeof(double)*(2-(-2)+1)];
extern char d14n_[(ssize_t)sizeof(double)*(2-(-2)+1)];
extern char d24n_[(ssize_t)sizeof(double)*(2-(-2)+1)];
extern char d14np1_[(ssize_t)sizeof(double)*(2-(-2)+1)];
extern char d24np1_[(ssize_t)sizeof(double)*(2-(-2)+1)];
extern char dnsdata_setup_derivatives_M[(ssize_t)sizeof(double)*(4+1)*(4+1)];
extern char dnsdata_setup_derivatives_t[(ssize_t)sizeof(double)*(4+1)];
extern int dnsdata_setup_derivatives_20M;
extern int dnsdata_setup_derivatives_21m;
extern int dnsdata_setup_derivatives_22;
extern int dnsdata_setup_derivatives_23;
extern int dnsdata_25l;
extern int dnsdata_26h;
extern ssize_t dnsdata_27i;
extern ssize_t dnsdata_28i;
extern ssize_t dnsdata_29st;
extern ssize_t dnsdata_30st;
extern struct freefunc D2vmat_f;extern char *D2vmat_;
extern struct freefunc etamat_f;extern char *etamat_;
extern struct freefunc D0mat_f;extern char *D0mat_;
extern char v0bc_[(ssize_t)sizeof(double)*(2-(-2)+1)*(-(-1)+1)];
extern ssize_t dnsdata_33st;
extern char vnbc_[(ssize_t)sizeof(double)*(2-(-2)+1)*(1+1)];
extern char eta0bc_[(ssize_t)sizeof(double)*(2-(-2)+1)*(-(-1)+1)];
extern char etanbc_[(ssize_t)sizeof(double)*(2-(-2)+1)*(1+1)];
extern char phi0bc_[(ssize_t)sizeof(double)*(2-(-2)+1)*(-(-1)+1)];
extern char phinbc_[(ssize_t)sizeof(double)*(2-(-2)+1)*(1+1)];
void dnsdata_34applybc_0(const int eq_l,const int eq_h,const ssize_t eq_i,const int eq__l,const int eq__h,const ssize_t eq__i,char *eq___,char *bc_);
void dnsdata_35applybc_n(const int eq_l,const int eq_h,const ssize_t eq_i,const int eq__l,const int eq__h,const ssize_t eq__i,char *eq___,char *bc_);
void dnsdata_36yintegr(double *RESULT_,const int f_l,const int f_h,const ssize_t f_i,char *f__);
struct VELOCITY_{struct COMPLEX_ u_;struct COMPLEX_ v_;struct COMPLEX_ w_;};struct MOMFLUX_{struct COMPLEX_ uu_;struct COMPLEX_ uv_;struct COMPLEX_ vv_;struct COMPLEX_ vw_;struct COMPLEX_ ww_;struct COMPLEX_ uw_;};extern int nxd_;
extern int nzd_;
extern int dnsdata_37h;
extern int dnsdata_38h;
extern ssize_t dnsdata_39i;
extern ssize_t dnsdata_40i;
void Vd_free(void * ptr);
extern struct freefunc Vd_f;extern char *Vd_;
extern int dnsdata_41h;
extern int dnsdata_42h;
extern ssize_t dnsdata_43i;
extern ssize_t dnsdata_44i;
void VVd_free(void * ptr);
extern struct freefunc VVd_f;extern char *VVd_;
/*maxtimelevels=1*/
struct rhstype_{struct COMPLEX_ eta_;struct COMPLEX_ D2v_;};struct VETA_{struct COMPLEX_ v_;struct COMPLEX_ eta_;};extern int dnsdata_45h;
extern int dnsdata_46l;
extern int dnsdata_47h;
extern ssize_t dnsdata_48i;
extern ssize_t dnsdata_49i;
extern ssize_t dnsdata_50i;
extern ssize_t dnsdata_51st;
extern ssize_t dnsdata_52st;
void V_free(void * ptr);
extern struct freefunc V_f;extern char *V_;
extern int dnsdata_53h;
extern int dnsdata_54l;
extern int dnsdata_55h;
extern int dnsdata_56M;
extern int dnsdata_57l;
extern int dnsdata_58m;
extern int dnsdata_59h;
extern ssize_t dnsdata_60i;
extern ssize_t dnsdata_61i;
extern ssize_t dnsdata_62i;
extern ssize_t dnsdata_63st;
extern ssize_t dnsdata_64st;
void oldrhs_free(void * ptr);
extern struct freefunc oldrhs_f;extern char *oldrhs_;
extern int dnsdata_65h;
extern int dnsdata_66l;
extern int dnsdata_67h;
extern ssize_t dnsdata_68i;
extern ssize_t dnsdata_69i;
extern ssize_t dnsdata_70i;
extern ssize_t dnsdata_71st;
extern struct freefunc memrhs_f;extern char *memrhs_;
extern double u1zero_;
extern double w1zero_;
extern double phi1zero_;
extern int ismp_;
extern int dnsdata_72h;
extern int dnsdata_73h;
extern int dnsdata_74l;
extern int dnsdata_75h;
extern off_t dnsdata_76i;
extern off_t dnsdata_77i;
extern off_t dnsdata_79i;
extern off_t dnsdata_80i;
extern off_t dnsdata_81i;
extern off_t dnsdata_82st;
extern off_t dnsdata_83st;
struct dnsdata_s78{char header_[(1023+1)];};extern struct freefunc diskimage_f;extern FILE *diskimage_;
extern int dnsdata_84h;
extern int dnsdata_85h;
extern int dnsdata_86h;
extern int dnsdata_87l;
extern int dnsdata_88h;
extern off_t dnsdata_89i;
extern off_t dnsdata_90i;
extern off_t dnsdata_92i;
extern off_t dnsdata_93st;
extern off_t dnsdata_94i;
extern off_t dnsdata_95i;
extern off_t dnsdata_96i;
extern off_t dnsdata_97st;
extern off_t dnsdata_98st;
struct dnsdata_s91{int nyimage_;int nximage_;int nzimage_;double timage_;double yminimage_;double ymaximage_;double aimage_;double alfa0image_;double beta0image_;double niimage_;};extern struct freefunc diskfield_f;extern FILE *diskfield_;
extern int cont_;
extern int outcont_;
extern struct freefunc time_file_f;extern FILE *time_file_;
extern int miny_;
extern int maxy_;
extern double cfl_;
extern double cflm_;
void dnsdata_99getcfl();
extern double energy_;
extern double slice_energy_;
extern double diss_;
extern double slice_diss_;
extern struct COMPLEX_ dudy_;
extern struct COMPLEX_ dvdy_;
extern struct COMPLEX_ dwdy_;
extern int dnsdata_100h;
extern int dnsdata_101l;
extern int dnsdata_102h;
extern ssize_t dnsdata_103i;
extern ssize_t dnsdata_104i;
extern ssize_t dnsdata_105st;
extern struct freefunc fieldbuf_f;extern char *fieldbuf_;
extern int dnsdata_106h;
extern int dnsdata_107l;
extern int dnsdata_108h;
extern ssize_t dnsdata_109i;
extern ssize_t dnsdata_110i;
extern ssize_t dnsdata_111st;
extern struct freefunc velbuf_f;extern char *velbuf_;
void dnsdata_112outstats();
void dnsdata_113read_restart_file();
void dnsdata_114simple(struct COMPLEX_ *rhs_,const int old_l,const int old_h,const ssize_t old_i,char *old__,double unkn_REAL,double unkn_IMAG,double impl_REAL,double impl_IMAG,double expl_REAL,double expl_IMAG);
void dnsdata_115CN_AB(struct COMPLEX_ *rhs_,const int old_l,const int old_h,const ssize_t old_i,char *old__,double unkn_REAL,double unkn_IMAG,double impl_REAL,double impl_IMAG,double expl_REAL,double expl_IMAG);
void dnsdata_116RK1_rai(struct COMPLEX_ *rhs_,const int old_l,const int old_h,const ssize_t old_i,char *old__,double unkn_REAL,double unkn_IMAG,double impl_REAL,double impl_IMAG,double expl_REAL,double expl_IMAG);
extern double dnsdata_117RK1_rai_coeff;
void dnsdata_118RK2_rai(struct COMPLEX_ *rhs_,const int old_l,const int old_h,const ssize_t old_i,char *old__,double unkn_REAL,double unkn_IMAG,double impl_REAL,double impl_IMAG,double expl_REAL,double expl_IMAG);
extern double dnsdata_119RK2_rai_coeff;
void dnsdata_120RK3_rai(struct COMPLEX_ *rhs_,const int old_l,const int old_h,const ssize_t old_i,char *old__,double unkn_REAL,double unkn_IMAG,double impl_REAL,double impl_IMAG,double expl_REAL,double expl_IMAG);
extern double dnsdata_121RK3_rai_coeff;
void dnsdata_122RK1_kom(struct COMPLEX_ *rhs_,const int old_l,const int old_h,const ssize_t old_i,char *old__,double unkn_REAL,double unkn_IMAG,double impl_REAL,double impl_IMAG,double expl_REAL,double expl_IMAG);
extern double dnsdata_123RK1_kom_coeff;
void dnsdata_124RK2_kom(struct COMPLEX_ *rhs_,const int old_l,const int old_h,const ssize_t old_i,char *old__,double unkn_REAL,double unkn_IMAG,double impl_REAL,double impl_IMAG,double expl_REAL,double expl_IMAG);
extern double dnsdata_125RK2_kom_coeff;
void dnsdata_126RK3_kom(struct COMPLEX_ *rhs_,const int old_l,const int old_h,const ssize_t old_i,char *old__,double unkn_REAL,double unkn_IMAG,double impl_REAL,double impl_IMAG,double expl_REAL,double expl_IMAG);
extern double dnsdata_127RK3_kom_coeff;
void dnsdata_128RK4_kom(struct COMPLEX_ *rhs_,const int old_l,const int old_h,const ssize_t old_i,char *old__,double unkn_REAL,double unkn_IMAG,double impl_REAL,double impl_IMAG,double expl_REAL,double expl_IMAG);
extern double dnsdata_129RK4_kom_coeff;
/*!USE rtchecks*/
extern int dnsdirect_1h;
extern int dnsdirect_2l;
extern int dnsdirect_3h;
struct dnsdirect_s4{struct COMPLEX_ u_;struct COMPLEX_ v_;struct COMPLEX_ w_;struct COMPLEX_ vy_;struct COMPLEX_ eta_;struct COMPLEX_ ph_;};extern ssize_t dnsdirect_5i;
extern ssize_t dnsdirect_6i;
extern ssize_t dnsdirect_7st;
extern struct freefunc bc0_f;extern char *bc0_;
extern struct freefunc bcn_f;extern char *bcn_;
void dnsdirect_8buildrhs(void (*timescheme_)(struct COMPLEX_ *rhs_,const int old_l,const int old_h,const ssize_t old_i,char *old__,double unknown_REAL,double unknown_IMAG,double implicit_part_REAL,double implicit_part_IMAG,double explicit_part_REAL,double explicit_part_IMAG));
void dnsdirect_9linsolve(double lambda_);
void dnsdirect_10vetaTOuvw();
void dnsdirect_11calcp0(struct COMPLEX_ *RESULT_,int ix_,int iz_);
void dnsdirect_12calcpn(struct COMPLEX_ *RESULT_,int ix_,int iz_);
void dnsdirect_13computeflowrate(double lambda_);
void dnsdirect_14deriv(const int f0_l,const int f0_h,const ssize_t f0_i,char *f0__,const int f1_l,const int f1_h,const ssize_t f1_i,char *f1__);
void dnsdirect_15convolutions(const int Vplane_l,const int Vplane_h,const ssize_t Vplane_i,const int Vplane__l,const int Vplane__h,const ssize_t Vplane__i,char *Vplane___,const int VVplane_l,const int VVplane_h,const ssize_t VVplane_i,const int VVplane__l,const int VVplane__h,const ssize_t VVplane__i,char *VVplane___);
void dnsdirect_15convolutions(const int Vplane_l,const int Vplane_h,const ssize_t Vplane_i,const int Vplane__l,const int Vplane__h,const ssize_t Vplane__i,char *Vplane___,const int VVplane_l,const int VVplane_h,const ssize_t VVplane_i,const int VVplane__l,const int VVplane__h,const ssize_t VVplane__i,char *VVplane___);
void dnsdirect_8buildrhs(void (*timescheme_)(struct COMPLEX_ *rhs_,const int old_l,const int old_h,const ssize_t old_i,char *old__,double unknown_REAL,double unknown_IMAG,double implicit_part_REAL,double implicit_part_IMAG,double explicit_part_REAL,double explicit_part_IMAG));
void dnsdirect_11calcp0(struct COMPLEX_ *RESULT_,int ix_,int iz_);
void dnsdirect_12calcpn(struct COMPLEX_ *RESULT_,int ix_,int iz_);
void dnsdirect_9linsolve(double lambda_);
void dnsdirect_14deriv(const int f0_l,const int f0_h,const ssize_t f0_i,char *f0__,const int f1_l,const int f1_h,const ssize_t f1_i,char *f1__);
void dnsdirect_10vetaTOuvw();
void dnsdirect_13computeflowrate(double lambda_);
struct DERIVS_{struct COMPLEX_ ux_;struct COMPLEX_ uy_;struct COMPLEX_ uz_;struct COMPLEX_ vx_;struct COMPLEX_ vy_;struct COMPLEX_ vz_;struct COMPLEX_ wx_;struct COMPLEX_ wy_;struct COMPLEX_ wz_;};struct DERPRODS_{struct COMPLEX_ ux2_;struct COMPLEX_ vx2_;struct COMPLEX_ wx2_;struct COMPLEX_ uy2_;struct COMPLEX_ vy2_;struct COMPLEX_ wy2_;struct COMPLEX_ uz2_;struct COMPLEX_ vz2_;struct COMPLEX_ wz2_;};struct DERPRODSEXT_{struct COMPLEX_ ux2_;struct COMPLEX_ vx2_;struct COMPLEX_ wx2_;struct COMPLEX_ uy2_;struct COMPLEX_ vy2_;struct COMPLEX_ wy2_;struct COMPLEX_ uz2_;struct COMPLEX_ vz2_;struct COMPLEX_ wz2_;struct COMPLEX_ uxvx_;struct COMPLEX_ uyvy_;struct COMPLEX_ uzvz_;struct COMPLEX_ uxwx_;struct COMPLEX_ uywy_;struct COMPLEX_ uzwz_;struct COMPLEX_ vxwx_;struct COMPLEX_ vywy_;struct COMPLEX_ vzwz_;};struct convenience_s1{char d1_[(ssize_t)sizeof(double)*(2-(-2)+1)];char d2_[(ssize_t)sizeof(double)*(2-(-2)+1)];};extern ssize_t convenience_2i;
extern ssize_t convenience_3st;
extern struct freefunc derivs_standalone_f;extern char *derivs_standalone_;
extern int convenience_4M;
extern int convenience_5m;
extern int convenience_6;
extern int convenience_7;
void convenience_9ByteSwap(float *xxx_);
void convenience_10fourier2physical(const int plane_l,const int plane_h,const ssize_t plane_i,const int plane__l,const int plane__h,const ssize_t plane__i,char *plane___,const int planed_l,const int planed_h,const ssize_t planed_i,const int planed__l,const int planed__h,const ssize_t planed__i,char *planed___);
void convenience_11read_field_parallel(char *field_name_);
void convenience_12read_field(char *field_name_);
void convenience_13read_field_uvw(char *field_name_);
void convenience_14velocity_gradient(const int Vder_l,const int Vder_h,const ssize_t Vder_i,const int Vder__l,const int Vder__h,const ssize_t Vder__i,const int Vder___l,const int Vder___h,const ssize_t Vder___i,char *Vder____);
void convenience_15deriv2(const int f0_l,const int f0_h,const ssize_t f0_i,char *f0__,const int f2_l,const int f2_h,const ssize_t f2_i,char *f2__);
double convenience_16yintf(const int f_l,const int f_h,const ssize_t f_i,char *f__);

void convenience_9ByteSwap(float *xxx_);
void convenience_10fourier2physical(const int plane_l,const int plane_h,const ssize_t plane_i,const int plane__l,const int plane__h,const ssize_t plane__i,char *plane___,const int planed_l,const int planed_h,const ssize_t planed_i,const int planed__l,const int planed__h,const ssize_t planed__i,char *planed___);
double convenience_16yintf(const int f_l,const int f_h,const ssize_t f_i,char *f__);
void convenience_11read_field_parallel(char *field_name_);
void convenience_12read_field(char *field_name_);
void convenience_13read_field_uvw(char *field_name_);
void convenience_14velocity_gradient(const int Vder_l,const int Vder_h,const ssize_t Vder_i,const int Vder__l,const int Vder__h,const ssize_t Vder__i,const int Vder___l,const int Vder___h,const ssize_t Vder___i,char *Vder____);
void convenience_15deriv2(const int f0_l,const int f0_h,const ssize_t f0_i,char *f0__,const int f2_l,const int f2_h,const ssize_t f2_i,char *f2__);
int nfmin_;
int nfmax_;
int dn_;



int step0A_pressure_1h;
int step0A_pressure_2l;
int step0A_pressure_3h;
ssize_t step0A_pressure_4i;
ssize_t step0A_pressure_5i;
ssize_t step0A_pressure_6i;
ssize_t step0A_pressure_7st;
ssize_t step0A_pressure_8st;
void pressure_free(void * ptr){munmap((char*)ptr+step0A_pressure_8st,step0A_pressure_6i);}struct freefunc pressure_f;char *pressure_;

int step0A_pressure_9h;
int step0A_pressure_10l;
int step0A_pressure_11h;
ssize_t step0A_pressure_12i;
ssize_t step0A_pressure_13i;
ssize_t step0A_pressure_14i;
ssize_t step0A_pressure_15st;
ssize_t step0A_pressure_16st;
void Vder_free(void * ptr){munmap((char*)ptr+step0A_pressure_16st,step0A_pressure_14i);}struct freefunc Vder_f;char *Vder_;

int step0A_pressure_17h;
int step0A_pressure_18l;
int step0A_pressure_19h;
ssize_t step0A_pressure_20i;
ssize_t step0A_pressure_21i;
ssize_t step0A_pressure_22st;
struct freefunc pbuf_f;char *pbuf_;

int step0A_pressure_23h;
int step0A_pressure_24l;
int step0A_pressure_25h;
off_t step0A_pressure_26i;
off_t step0A_pressure_27i;
struct freefunc pressuredata_f;FILE *pressuredata_;


/*! Definitions for machine first*/
extern int poisson_solver_parallel_1h;
extern ssize_t poisson_solver_parallel_2i;
extern struct freefunc y_first_f;extern char *y_first_;
extern int poisson_solver_parallel_3h;
extern ssize_t poisson_solver_parallel_4i;
extern struct freefunc fderivatives_f;extern char *fderivatives_;
extern char fd140_[(ssize_t)sizeof(double)*(2-(-2)+1)];
extern char fd240_[(ssize_t)sizeof(double)*(2-(-2)+1)];
extern char Mf_[(ssize_t)sizeof(double)*(4+1)*(4+1)];
extern char tf_[(ssize_t)sizeof(double)*(4+1)];
void poisson_solver_parallel_6calcp0v(struct COMPLEX_ *RESULT_,int ix_,int iz_,double vdudy_REAL,double vdudy_IMAG,double vdwdy_REAL,double vdwdy_IMAG);
void poisson_solver_parallel_7calcpnv(struct COMPLEX_ *RESULT_,int ix_,int iz_,double vdudy_REAL,double vdudy_IMAG,double vdwdy_REAL,double vdwdy_IMAG);
void poisson_solver_parallel_8solve_dirichelet(const int hp_l,const int hp_h,const ssize_t hp_i,char *hp__,double pres_up_REAL,double pres_up_IMAG,double pres_down_REAL,double pres_down_IMAG,double k2_,const int pres_l,const int pres_h,const ssize_t pres_i,char *pres__);
void poisson_solver_parallel_9solve_neumann(const int hp_l,const int hp_h,const ssize_t hp_i,char *hp__,double dpdy_down_REAL,double dpdy_down_IMAG,double integral_REAL,double integral_IMAG,const int pres_l,const int pres_h,const ssize_t pres_i,char *pres__);
void poisson_solver_parallel_10compute_pressure(const int velder_l,const int velder_h,const ssize_t velder_i,const int velder__l,const int velder__h,const ssize_t velder__i,const int velder___l,const int velder___h,const ssize_t velder___i,char *velder____,const int _pressure__l,const int _pressure__h,const ssize_t _pressure__i,const int _pressure___l,const int _pressure___h,const ssize_t _pressure___i,const int _pressure____l,const int _pressure____h,const ssize_t _pressure____i,char *_pressure_____);
mainstart



fft: 

fft_fft_LASTN=1;fft_fft_12C3=sin(3.14159265358979323846/3.);
fft_exit:;





Lanczos_norm_=0.;

Lanczos_R: 
Lanczos_R_exit:;


setup_signal_USR1();


barrier_=mmap(NULL,(ssize_t)sizeof(volatile int),PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANON,-1,0);if(barrier_==MAP_FAILED)errmalloc();atblockexit(barrier_f,barrier_free,(void*)barrier_);(*barrier_)=0;if( (argc-1)<1 ){ iproc_=1; nproc_=1 ;}else{
iproc_=atoi((void *)((*(char**)((ssize_t)sizeof(char*)+(char*)argv))));  nproc_=atoi((void *)((*(char**)(2*(ssize_t)sizeof(char*)+(char*)argv))));  };
prev_=NULL;atblockexit(prev_f,errfclose,&prev_);next_=NULL;atblockexit(next_f,errfclose,&next_);if( iproc_<nproc_ ){
  next_=fdopen(tcpserver((IPPORT_USERRESERVED+111)+iproc_),(void *)("r+"));
  setvbuf(next_,malloc(800),_IOFBF,800);
};
if( iproc_>1 ){
  prev_=fdopen(tcpclient((void *)((*(char**)(3*(ssize_t)sizeof(char*)+(char*)argv))),(IPPORT_USERRESERVED+111)+iproc_-1),(void *)("r+"));
  setvbuf(prev_,malloc(800),_IOFBF,800);
};


meanpx_=-99.;meanpz_=-99.;meanflowx_=-99.;meanflowz_=-99.;px_=0.;corrpx_=0.;pz_=0.;corrpz_=0.;flowx_=0.;flowz_=0.;deltat_=0.;cflmax_=0.;time_=0.;restart_file_=0;atblockexit(restart_file_f,condfree,restart_file_);reread_=0;dnsdata_1read_initial_data();  signal(SIGUSR2,dnsdata_2kill_received);

/*! Grid in y direction and compact finite differences operators*/
dnsdata_4nyl=1+((iproc_-1)*(ny_-1) / nproc_);
dnsdata_5nyh=(iproc_*(ny_-1) / nproc_);
dnsdata_6M=dnsdata_4nyl-4;
dnsdata_7l= - 1;if(dnsdata_7l<dnsdata_6M)dnsdata_7l=dnsdata_6M;dnsdata_8m=dnsdata_5nyh+4;
dnsdata_9h=ny_+1;if(dnsdata_9h>dnsdata_8m)dnsdata_9h=dnsdata_8m;dnsdata_10i=(ssize_t)sizeof(double)*(dnsdata_9h-dnsdata_7l+1);
dnsdata_11st=dnsdata_7l*(ssize_t)sizeof(double);

y_=malloc(dnsdata_10i);if(y_==NULL)errmalloc();y_-=dnsdata_11st;atblockexit(y_f,free,y_+dnsdata_11st);  {int i_=dnsdata_7l;do{ /*!Channel*/{ (*(double *)(i_*(ssize_t)sizeof(double)+y_))=ymin_+0.5*(ymax_-ymin_)*(tanh(a_*((double)(2*i_)/(double)(ny_)-1.))/tanh(a_)+0.5*(ymax_-ymin_)) ;}i_++;}while(i_<=dnsdata_9h);}


dnsdata_13st=(-2)*(ssize_t)sizeof(double);
dnsdata_14M=dnsdata_4nyl-2;
dnsdata_15l=1;if(dnsdata_15l<dnsdata_14M)dnsdata_15l=dnsdata_14M;dnsdata_16m=dnsdata_5nyh+2;
dnsdata_17h=ny_-1;if(dnsdata_17h>dnsdata_16m)dnsdata_17h=dnsdata_16m;dnsdata_18i=(ssize_t)sizeof(struct dnsdata_s12)*(dnsdata_17h-dnsdata_15l+1);
dnsdata_19st=dnsdata_15l*(ssize_t)sizeof(struct dnsdata_s12);

derivatives_=malloc(dnsdata_18i);if(derivatives_==NULL)errmalloc();derivatives_-=dnsdata_19st;atblockexit(derivatives_f,free,derivatives_+dnsdata_19st);setup_derivatives: 
dnsdata_setup_derivatives_20M=dnsdata_4nyl-2;
dnsdata_setup_derivatives_21m=dnsdata_5nyh+2;
dnsdata_setup_derivatives_22=1;if(dnsdata_setup_derivatives_22<dnsdata_setup_derivatives_20M)dnsdata_setup_derivatives_22=dnsdata_setup_derivatives_20M;dnsdata_setup_derivatives_23=ny_-1;if(dnsdata_setup_derivatives_23>dnsdata_setup_derivatives_21m)dnsdata_setup_derivatives_23=dnsdata_setup_derivatives_21m; {int iy_=dnsdata_setup_derivatives_22  ;while(iy_<=dnsdata_setup_derivatives_23 ){{
  struct dnsdata_s12 *dnsdata_setup_derivatives_24w;
dnsdata_setup_derivatives_24w=(struct dnsdata_s12 *)(iy_*(ssize_t)sizeof(struct dnsdata_s12)+derivatives_);
 {int i_=0  ;do{ {int j_=0  ;do{{ (*(double *)(j_*(ssize_t)sizeof(double)+i_*(ssize_t)sizeof(double)*(4+1)+dnsdata_setup_derivatives_M))=pow(((*(double *)((iy_-2+j_)*(ssize_t)sizeof(double)+y_))-(*(double *)(iy_*(ssize_t)sizeof(double)+y_))),(4-i_) );}j_+=1;}while(j_<=4);}i_+=1;}while(i_<=4 );}  rbmat_6LUdecomp(0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),dnsdata_setup_derivatives_M);
  memset(dnsdata_setup_derivatives_t,0,(ssize_t)sizeof(double)*(4+1));  (*(double *)(dnsdata_setup_derivatives_t))=24.;
  {{rbmat_8LeftLDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+(*dnsdata_setup_derivatives_24w).d4_-dnsdata_13st),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(dnsdata_setup_derivatives_M),0,4,(ssize_t)sizeof(double),(dnsdata_setup_derivatives_t)); rbmat_9LeftUDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+(*dnsdata_setup_derivatives_24w).d4_-dnsdata_13st),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(dnsdata_setup_derivatives_M),(1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+(*dnsdata_setup_derivatives_24w).d4_-dnsdata_13st));};}
   {int i_=0  ;do{ {int j_=0  ;do{{ (*(double *)(j_*(ssize_t)sizeof(double)+i_*(ssize_t)sizeof(double)*(4+1)+dnsdata_setup_derivatives_M))=(double)((5-i_)*(6-i_)*(7-i_)*(8-i_))*pow(((*(double *)((iy_-2+j_)*(ssize_t)sizeof(double)+y_))-(*(double *)(iy_*(ssize_t)sizeof(double)+y_))),(4-i_) );}j_+=1;}while(j_<=4);}i_+=1;}while(i_<=4 );}  rbmat_6LUdecomp(0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),dnsdata_setup_derivatives_M);
   {int i_=0  ;do{{  (*(double *)(i_*(ssize_t)sizeof(double)+dnsdata_setup_derivatives_t))=0.; {int j_= - 2  ;do{{(*(double *)(i_*(ssize_t)sizeof(double)+dnsdata_setup_derivatives_t))+=((*(double *)(j_*(ssize_t)sizeof(double)+(*dnsdata_setup_derivatives_24w).d4_-dnsdata_13st))*pow(((*(double *)((iy_+j_)*(ssize_t)sizeof(double)+y_))-(*(double *)(iy_*(ssize_t)sizeof(double)+y_))),(8-i_))) ;}j_+=1;}while(j_<=2 );}}i_+=1;}while(i_<=4);}
  {{rbmat_8LeftLDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+(*dnsdata_setup_derivatives_24w).d0_-dnsdata_13st),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(dnsdata_setup_derivatives_M),0,4,(ssize_t)sizeof(double),(dnsdata_setup_derivatives_t)); rbmat_9LeftUDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+(*dnsdata_setup_derivatives_24w).d0_-dnsdata_13st),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(dnsdata_setup_derivatives_M),(1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+(*dnsdata_setup_derivatives_24w).d0_-dnsdata_13st));};}
   {int i_=0  ;do{ {int j_=0  ;do{{ (*(double *)(j_*(ssize_t)sizeof(double)+i_*(ssize_t)sizeof(double)*(4+1)+dnsdata_setup_derivatives_M))=pow(((*(double *)((iy_-2+j_)*(ssize_t)sizeof(double)+y_))-(*(double *)(iy_*(ssize_t)sizeof(double)+y_))),(4-i_) );}j_+=1;}while(j_<=4);}i_+=1;}while(i_<=4 );}  rbmat_6LUdecomp(0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),dnsdata_setup_derivatives_M);
  memset(dnsdata_setup_derivatives_t,0,(ssize_t)sizeof(double)*(4+1));   {int i_=0  ;do{{  (*(double *)(i_*(ssize_t)sizeof(double)+dnsdata_setup_derivatives_t))=0.; {int j_= - 2  ;do{{(*(double *)(i_*(ssize_t)sizeof(double)+dnsdata_setup_derivatives_t))+=(*(double *)(j_*(ssize_t)sizeof(double)+(*dnsdata_setup_derivatives_24w).d0_-dnsdata_13st))*(double)((4-i_))*(double)((3-i_))*pow(((*(double *)((iy_+j_)*(ssize_t)sizeof(double)+y_))-(*(double *)(iy_*(ssize_t)sizeof(double)+y_))),(2-i_) );}j_+=1;}while(j_<=2 );}}i_+=1;}while(i_<=2);}
  {{rbmat_8LeftLDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+(*dnsdata_setup_derivatives_24w).d2_-dnsdata_13st),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(dnsdata_setup_derivatives_M),0,4,(ssize_t)sizeof(double),(dnsdata_setup_derivatives_t)); rbmat_9LeftUDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+(*dnsdata_setup_derivatives_24w).d2_-dnsdata_13st),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(dnsdata_setup_derivatives_M),(1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+(*dnsdata_setup_derivatives_24w).d2_-dnsdata_13st));};}
  memset(dnsdata_setup_derivatives_t,0,(ssize_t)sizeof(double)*(4+1));   {int i_=0  ;do{{  (*(double *)(i_*(ssize_t)sizeof(double)+dnsdata_setup_derivatives_t))=0.; {int j_= - 2  ;do{{(*(double *)(i_*(ssize_t)sizeof(double)+dnsdata_setup_derivatives_t))+=(*(double *)(j_*(ssize_t)sizeof(double)+(*dnsdata_setup_derivatives_24w).d0_-dnsdata_13st))*(double)((4-i_))*pow(((*(double *)((iy_+j_)*(ssize_t)sizeof(double)+y_))-(*(double *)(iy_*(ssize_t)sizeof(double)+y_))),(3-i_) );}j_+=1;}while(j_<=2 );}}i_+=1;}while(i_<=3);}
  {{rbmat_8LeftLDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+(*dnsdata_setup_derivatives_24w).d1_-dnsdata_13st),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(dnsdata_setup_derivatives_M),0,4,(ssize_t)sizeof(double),(dnsdata_setup_derivatives_t)); rbmat_9LeftUDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+(*dnsdata_setup_derivatives_24w).d1_-dnsdata_13st),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(dnsdata_setup_derivatives_M),(1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+(*dnsdata_setup_derivatives_24w).d1_-dnsdata_13st));};}
}iy_+=1;};}
if( (prev_==NULL) ){
  memset(dnsdata_13st+d040_-((-2)*(ssize_t)sizeof(double)),0,(ssize_t)sizeof(double)*(2-(-2)+1));  (*(double *)(-(ssize_t)sizeof(double)+d040_-((-2)*(ssize_t)sizeof(double))))=1.;
   {int i_=0  ;do{ {int j_=0  ;do{{ (*(double *)(j_*(ssize_t)sizeof(double)+i_*(ssize_t)sizeof(double)*(4+1)+dnsdata_setup_derivatives_M))=pow(((*(double *)((-1+j_)*(ssize_t)sizeof(double)+y_))-(*(double *)(y_))),(4-i_) );}j_+=1;}while(j_<=4);}i_+=1;}while(i_<=4 );}  rbmat_6LUdecomp(0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),dnsdata_setup_derivatives_M);
  memset(dnsdata_setup_derivatives_t,0,(ssize_t)sizeof(double)*(4+1));  (*(double *)(3*(ssize_t)sizeof(double)+dnsdata_setup_derivatives_t))=1.;
  {{rbmat_8LeftLDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+d140_-((-2)*(ssize_t)sizeof(double))),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(dnsdata_setup_derivatives_M),0,4,(ssize_t)sizeof(double),(dnsdata_setup_derivatives_t)); rbmat_9LeftUDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+d140_-((-2)*(ssize_t)sizeof(double))),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(dnsdata_setup_derivatives_M),(1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+d140_-((-2)*(ssize_t)sizeof(double))));};}
  memset(dnsdata_setup_derivatives_t,0,(ssize_t)sizeof(double)*(4+1));  (*(double *)(2*(ssize_t)sizeof(double)+dnsdata_setup_derivatives_t))=2.;
  {{rbmat_8LeftLDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+d240_-((-2)*(ssize_t)sizeof(double))),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(dnsdata_setup_derivatives_M),0,4,(ssize_t)sizeof(double),(dnsdata_setup_derivatives_t)); rbmat_9LeftUDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+d240_-((-2)*(ssize_t)sizeof(double))),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(dnsdata_setup_derivatives_M),(1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+d240_-((-2)*(ssize_t)sizeof(double))));};}
  memset(dnsdata_setup_derivatives_t,0,(ssize_t)sizeof(double)*(4+1));  (*(double *)(3*(ssize_t)sizeof(double)+dnsdata_setup_derivatives_t))=6.;
  {{rbmat_8LeftLDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+d340_-((-2)*(ssize_t)sizeof(double))),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(dnsdata_setup_derivatives_M),0,4,(ssize_t)sizeof(double),(dnsdata_setup_derivatives_t)); rbmat_9LeftUDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+d340_-((-2)*(ssize_t)sizeof(double))),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(dnsdata_setup_derivatives_M),(1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+d340_-((-2)*(ssize_t)sizeof(double))));};}
   {int i_=0  ;do{ {int j_=0  ;do{{ (*(double *)(j_*(ssize_t)sizeof(double)+i_*(ssize_t)sizeof(double)*(4+1)+dnsdata_setup_derivatives_M))=pow(((*(double *)((-1+j_)*(ssize_t)sizeof(double)+y_))-(*(double *)(-(ssize_t)sizeof(double)+y_))),(4-i_) );}j_+=1;}while(j_<=4);}i_+=1;}while(i_<=4 );}  rbmat_6LUdecomp(0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),dnsdata_setup_derivatives_M);
  memset(dnsdata_setup_derivatives_t,0,(ssize_t)sizeof(double)*(4+1));  (*(double *)(3*(ssize_t)sizeof(double)+dnsdata_setup_derivatives_t))=1.;
  {{rbmat_8LeftLDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+d14m1_-((-2)*(ssize_t)sizeof(double))),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(dnsdata_setup_derivatives_M),0,4,(ssize_t)sizeof(double),(dnsdata_setup_derivatives_t)); rbmat_9LeftUDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+d14m1_-((-2)*(ssize_t)sizeof(double))),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(dnsdata_setup_derivatives_M),(1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+d14m1_-((-2)*(ssize_t)sizeof(double))));};}
  memset(dnsdata_setup_derivatives_t,0,(ssize_t)sizeof(double)*(4+1));  (*(double *)(2*(ssize_t)sizeof(double)+dnsdata_setup_derivatives_t))=2.;
  {{rbmat_8LeftLDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+d24m1_-((-2)*(ssize_t)sizeof(double))),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(dnsdata_setup_derivatives_M),0,4,(ssize_t)sizeof(double),(dnsdata_setup_derivatives_t)); rbmat_9LeftUDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+d24m1_-((-2)*(ssize_t)sizeof(double))),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(dnsdata_setup_derivatives_M),(1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+d24m1_-((-2)*(ssize_t)sizeof(double))));};}
};
if( (next_==NULL) ){
  memset(dnsdata_13st+d04n_-((-2)*(ssize_t)sizeof(double)),0,(ssize_t)sizeof(double)*(2-(-2)+1));  (*(double *)((ssize_t)sizeof(double)+d04n_-((-2)*(ssize_t)sizeof(double))))=1.;
   {int i_=0  ;do{ {int j_=0  ;do{{ (*(double *)(j_*(ssize_t)sizeof(double)+i_*(ssize_t)sizeof(double)*(4+1)+dnsdata_setup_derivatives_M))=pow(((*(double *)((ny_-3+j_)*(ssize_t)sizeof(double)+y_))-(*(double *)(ny_*(ssize_t)sizeof(double)+y_))),(4-i_) );}j_+=1;}while(j_<=4);}i_+=1;}while(i_<=4 );}  rbmat_6LUdecomp(0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),dnsdata_setup_derivatives_M);
  memset(dnsdata_setup_derivatives_t,0,(ssize_t)sizeof(double)*(4+1));  (*(double *)(3*(ssize_t)sizeof(double)+dnsdata_setup_derivatives_t))=1.;
  {{rbmat_8LeftLDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+d14n_-((-2)*(ssize_t)sizeof(double))),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(dnsdata_setup_derivatives_M),0,4,(ssize_t)sizeof(double),(dnsdata_setup_derivatives_t)); rbmat_9LeftUDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+d14n_-((-2)*(ssize_t)sizeof(double))),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(dnsdata_setup_derivatives_M),(1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+d14n_-((-2)*(ssize_t)sizeof(double))));};}
  memset(dnsdata_setup_derivatives_t,0,(ssize_t)sizeof(double)*(4+1));  (*(double *)(2*(ssize_t)sizeof(double)+dnsdata_setup_derivatives_t))=2.;
  {{rbmat_8LeftLDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+d24n_-((-2)*(ssize_t)sizeof(double))),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(dnsdata_setup_derivatives_M),0,4,(ssize_t)sizeof(double),(dnsdata_setup_derivatives_t)); rbmat_9LeftUDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+d24n_-((-2)*(ssize_t)sizeof(double))),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(dnsdata_setup_derivatives_M),(1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+d24n_-((-2)*(ssize_t)sizeof(double))));};}
   {int i_=0  ;do{ {int j_=0  ;do{{ (*(double *)(j_*(ssize_t)sizeof(double)+i_*(ssize_t)sizeof(double)*(4+1)+dnsdata_setup_derivatives_M))=pow(((*(double *)((ny_-3+j_)*(ssize_t)sizeof(double)+y_))-(*(double *)((ny_+1)*(ssize_t)sizeof(double)+y_))),(4-i_) );}j_+=1;}while(j_<=4);}i_+=1;}while(i_<=4 );}  rbmat_6LUdecomp(0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),dnsdata_setup_derivatives_M);
  memset(dnsdata_setup_derivatives_t,0,(ssize_t)sizeof(double)*(4+1));  (*(double *)(3*(ssize_t)sizeof(double)+dnsdata_setup_derivatives_t))=1.;
  {{rbmat_8LeftLDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+d14np1_-((-2)*(ssize_t)sizeof(double))),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(dnsdata_setup_derivatives_M),0,4,(ssize_t)sizeof(double),(dnsdata_setup_derivatives_t)); rbmat_9LeftUDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+d14np1_-((-2)*(ssize_t)sizeof(double))),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(dnsdata_setup_derivatives_M),(1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+d14np1_-((-2)*(ssize_t)sizeof(double))));};}
  memset(dnsdata_setup_derivatives_t,0,(ssize_t)sizeof(double)*(4+1));  (*(double *)(2*(ssize_t)sizeof(double)+dnsdata_setup_derivatives_t))=2.;
  {{rbmat_8LeftLDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+d24np1_-((-2)*(ssize_t)sizeof(double))),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(dnsdata_setup_derivatives_M),0,4,(ssize_t)sizeof(double),(dnsdata_setup_derivatives_t)); rbmat_9LeftUDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+d24np1_-((-2)*(ssize_t)sizeof(double))),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(dnsdata_setup_derivatives_M),(1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+d24np1_-((-2)*(ssize_t)sizeof(double))));};}
};
setup_derivatives_exit:;

dnsdata_25l= - nz_;
dnsdata_26h=nz_;
dnsdata_27i=(ssize_t)sizeof(double)*(2-(-2)+1)*((dnsdata_5nyh+2)-dnsdata_4nyl+1);
dnsdata_28i=dnsdata_27i*(dnsdata_26h-dnsdata_25l+1);
dnsdata_29st=dnsdata_4nyl*(ssize_t)sizeof(double)*(2-(-2)+1)+dnsdata_13st;
dnsdata_30st=dnsdata_25l*dnsdata_27i+dnsdata_29st;

D2vmat_=malloc(dnsdata_28i);if(D2vmat_==NULL)errmalloc();D2vmat_-=dnsdata_30st;atblockexit(D2vmat_f,free,D2vmat_+dnsdata_30st);memset(dnsdata_30st+D2vmat_,0,dnsdata_28i);
etamat_=malloc(dnsdata_28i);if(etamat_==NULL)errmalloc();etamat_-=dnsdata_30st;atblockexit(etamat_f,free,etamat_+dnsdata_30st);memset(dnsdata_30st+etamat_,0,dnsdata_28i);
D0mat_=malloc(dnsdata_27i);if(D0mat_==NULL)errmalloc();D0mat_-=dnsdata_29st;atblockexit(D0mat_f,free,D0mat_+dnsdata_29st);memset(dnsdata_29st+D0mat_,0,dnsdata_27i);{char *dnsdata_32_;

dnsdata_32_=dnsdata_4nyl*(ssize_t)sizeof(struct dnsdata_s12)+(char*)(*(struct dnsdata_s12*)(derivatives_)).d0_-dnsdata_13st; {char *dnsdata_31_=dnsdata_4nyl*(ssize_t)sizeof(double)*(2-(-2)+1)+D0mat_;int dnsdata_31_1=dnsdata_5nyh-dnsdata_4nyl; do{{ memcpy(dnsdata_13st+dnsdata_31_,dnsdata_13st+dnsdata_32_,(ssize_t)sizeof(double)*(2-(-2)+1)); dnsdata_32_ =(ssize_t)sizeof(struct dnsdata_s12)+dnsdata_32_;}dnsdata_31_+=(ssize_t)sizeof(double)*(2-(-2)+1);dnsdata_31_1--;}while(dnsdata_31_1>=0);}}rbmatmod_1LUdecompStep(dnsdata_4nyl,(dnsdata_5nyh+2),(ssize_t)sizeof(double)*(2-(-2)+1),D0mat_);

dnsdata_33st=(-1)*(ssize_t)sizeof(double)*(2-(-2)+1)+dnsdata_13st;
memset(dnsdata_33st+v0bc_-(-(ssize_t)sizeof(double)*(2-(-2)+1)+dnsdata_13st),0,(ssize_t)sizeof(double)*(2-(-2)+1)*(-(-1)+1));memset(dnsdata_13st+vnbc_-dnsdata_13st,0,(ssize_t)sizeof(double)*(2-(-2)+1)*(1+1));memset(dnsdata_33st+eta0bc_-(-(ssize_t)sizeof(double)*(2-(-2)+1)+dnsdata_13st),0,(ssize_t)sizeof(double)*(2-(-2)+1)*(-(-1)+1));memset(dnsdata_13st+etanbc_-dnsdata_13st,0,(ssize_t)sizeof(double)*(2-(-2)+1)*(1+1));memset(dnsdata_33st+phi0bc_-(-(ssize_t)sizeof(double)*(2-(-2)+1)+dnsdata_13st),0,(ssize_t)sizeof(double)*(2-(-2)+1)*(-(-1)+1));memset(dnsdata_13st+phinbc_-dnsdata_13st,0,(ssize_t)sizeof(double)*(2-(-2)+1)*(1+1));if( (prev_==NULL) ){
  memcpy(dnsdata_13st+v0bc_-(-(ssize_t)sizeof(double)*(2-(-2)+1)+dnsdata_13st),dnsdata_13st+d040_-((-2)*(ssize_t)sizeof(double)),(ssize_t)sizeof(double)*(2-(-2)+1));  memcpy(dnsdata_13st-(ssize_t)sizeof(double)*(2-(-2)+1)+v0bc_-(-(ssize_t)sizeof(double)*(2-(-2)+1)+dnsdata_13st),dnsdata_13st+d140_-((-2)*(ssize_t)sizeof(double)),(ssize_t)sizeof(double)*(2-(-2)+1));  memcpy(dnsdata_13st+eta0bc_-(-(ssize_t)sizeof(double)*(2-(-2)+1)+dnsdata_13st),dnsdata_13st+d040_-((-2)*(ssize_t)sizeof(double)),(ssize_t)sizeof(double)*(2-(-2)+1));
  memcpy(dnsdata_13st-(ssize_t)sizeof(double)*(2-(-2)+1)+eta0bc_-(-(ssize_t)sizeof(double)*(2-(-2)+1)+dnsdata_13st),dnsdata_13st+(*(struct dnsdata_s12*)((ssize_t)sizeof(struct dnsdata_s12)+derivatives_)).d4_-dnsdata_13st,(ssize_t)sizeof(double)*(2-(-2)+1));
  memcpy(dnsdata_13st+phi0bc_-(-(ssize_t)sizeof(double)*(2-(-2)+1)+dnsdata_13st),dnsdata_13st+d040_-((-2)*(ssize_t)sizeof(double)),(ssize_t)sizeof(double)*(2-(-2)+1));  memcpy(dnsdata_13st-(ssize_t)sizeof(double)*(2-(-2)+1)+phi0bc_-(-(ssize_t)sizeof(double)*(2-(-2)+1)+dnsdata_13st),dnsdata_13st+(*(struct dnsdata_s12*)((ssize_t)sizeof(struct dnsdata_s12)+derivatives_)).d4_-dnsdata_13st/*!Dirichlet*/,(ssize_t)sizeof(double)*(2-(-2)+1));
/*! phi0bc(0)=d140; phi0bc(-1)=derivatives(1).d4 !Neumann*/
   {int i_=  - 1  ;do{{ (*(double *)(i_*(ssize_t)sizeof(double)+v0bc_-(-(ssize_t)sizeof(double)*(2-(-2)+1)+dnsdata_13st)))-=(*(double *)((-2)*(ssize_t)sizeof(double)+v0bc_-(-(ssize_t)sizeof(double)*(2-(-2)+1)+dnsdata_13st)))*(*(double *)(i_*(ssize_t)sizeof(double)-(ssize_t)sizeof(double)*(2-(-2)+1)+v0bc_-(-(ssize_t)sizeof(double)*(2-(-2)+1)+dnsdata_13st)))/(*(double *)((-2)*(ssize_t)sizeof(double)-(ssize_t)sizeof(double)*(2-(-2)+1)+v0bc_-(-(ssize_t)sizeof(double)*(2-(-2)+1)+dnsdata_13st)) );}i_+=1;}while(i_<=2);}
   {int i_=  - 1  ;do{{ (*(double *)(i_*(ssize_t)sizeof(double)+eta0bc_-(-(ssize_t)sizeof(double)*(2-(-2)+1)+dnsdata_13st)))-=(*(double *)((-2)*(ssize_t)sizeof(double)+eta0bc_-(-(ssize_t)sizeof(double)*(2-(-2)+1)+dnsdata_13st)))*(*(double *)(i_*(ssize_t)sizeof(double)-(ssize_t)sizeof(double)*(2-(-2)+1)+eta0bc_-(-(ssize_t)sizeof(double)*(2-(-2)+1)+dnsdata_13st)))/(*(double *)((-2)*(ssize_t)sizeof(double)-(ssize_t)sizeof(double)*(2-(-2)+1)+eta0bc_-(-(ssize_t)sizeof(double)*(2-(-2)+1)+dnsdata_13st)) );}i_+=1;}while(i_<=2);}
   {int i_=  - 1  ;do{{ (*(double *)(i_*(ssize_t)sizeof(double)+phi0bc_-(-(ssize_t)sizeof(double)*(2-(-2)+1)+dnsdata_13st)))-=(*(double *)((-2)*(ssize_t)sizeof(double)+phi0bc_-(-(ssize_t)sizeof(double)*(2-(-2)+1)+dnsdata_13st)))*(*(double *)(i_*(ssize_t)sizeof(double)-(ssize_t)sizeof(double)*(2-(-2)+1)+phi0bc_-(-(ssize_t)sizeof(double)*(2-(-2)+1)+dnsdata_13st)))/(*(double *)((-2)*(ssize_t)sizeof(double)-(ssize_t)sizeof(double)*(2-(-2)+1)+phi0bc_-(-(ssize_t)sizeof(double)*(2-(-2)+1)+dnsdata_13st)) );}i_+=1;}while(i_<=2);}
};
if( (next_==NULL) ){
/*! vnbc(0)=d04n; vnbc(1)=d24n; etanbc(0)=d14n !Boundary layer*/
  memcpy(dnsdata_13st+vnbc_-dnsdata_13st,dnsdata_13st+d04n_-((-2)*(ssize_t)sizeof(double)),(ssize_t)sizeof(double)*(2-(-2)+1));  memcpy(dnsdata_13st+(ssize_t)sizeof(double)*(2-(-2)+1)+vnbc_-dnsdata_13st,dnsdata_13st+d14n_-((-2)*(ssize_t)sizeof(double)),(ssize_t)sizeof(double)*(2-(-2)+1));  memcpy(dnsdata_13st+etanbc_-dnsdata_13st,dnsdata_13st+d04n_-((-2)*(ssize_t)sizeof(double)),(ssize_t)sizeof(double)*(2-(-2)+1));
  memcpy(dnsdata_13st+(ssize_t)sizeof(double)*(2-(-2)+1)+etanbc_-dnsdata_13st,dnsdata_13st+(*(struct dnsdata_s12*)((ny_-1)*(ssize_t)sizeof(struct dnsdata_s12)+derivatives_)).d4_-dnsdata_13st,(ssize_t)sizeof(double)*(2-(-2)+1));
  memcpy(dnsdata_13st+phinbc_-dnsdata_13st,dnsdata_13st+d04n_-((-2)*(ssize_t)sizeof(double)),(ssize_t)sizeof(double)*(2-(-2)+1));  memcpy(dnsdata_13st+(ssize_t)sizeof(double)*(2-(-2)+1)+phinbc_-dnsdata_13st,dnsdata_13st+(*(struct dnsdata_s12*)((ny_-1)*(ssize_t)sizeof(struct dnsdata_s12)+derivatives_)).d4_-dnsdata_13st/*!Dirichlet*/,(ssize_t)sizeof(double)*(2-(-2)+1));
/*! phinbc(0)=d04n; phinbc(1)=d14n                 !Dirichlet+Neumann*/
   {int i_=  - 2  ;do{{ (*(double *)(i_*(ssize_t)sizeof(double)+vnbc_-dnsdata_13st))-=(*(double *)(2*(ssize_t)sizeof(double)+vnbc_-dnsdata_13st))*(*(double *)(i_*(ssize_t)sizeof(double)+(ssize_t)sizeof(double)*(2-(-2)+1)+vnbc_-dnsdata_13st))/(*(double *)(2*(ssize_t)sizeof(double)+(ssize_t)sizeof(double)*(2-(-2)+1)+vnbc_-dnsdata_13st) );}i_+=1;}while(i_<=1);}
   {int i_=  - 2  ;do{{ (*(double *)(i_*(ssize_t)sizeof(double)+etanbc_-dnsdata_13st))-=(*(double *)(2*(ssize_t)sizeof(double)+etanbc_-dnsdata_13st))*(*(double *)(i_*(ssize_t)sizeof(double)+(ssize_t)sizeof(double)*(2-(-2)+1)+etanbc_-dnsdata_13st))/(*(double *)(2*(ssize_t)sizeof(double)+(ssize_t)sizeof(double)*(2-(-2)+1)+etanbc_-dnsdata_13st) );}i_+=1;}while(i_<=1);}
   {int i_=  - 2  ;do{{ (*(double *)(i_*(ssize_t)sizeof(double)+phinbc_-dnsdata_13st))-=(*(double *)(2*(ssize_t)sizeof(double)+phinbc_-dnsdata_13st))*(*(double *)(i_*(ssize_t)sizeof(double)+(ssize_t)sizeof(double)*(2-(-2)+1)+phinbc_-dnsdata_13st))/(*(double *)(2*(ssize_t)sizeof(double)+(ssize_t)sizeof(double)*(2-(-2)+1)+phinbc_-dnsdata_13st) );}i_+=1;}while(i_<=1);}
};


/*! Boundary conditions*/
nxd_=(3*nx_ / 2 )- 1;{do{  nxd_ +=1;}while(!(fft_9FFTfit(nxd_)));}
nzd_=3*nz_ - 1;{do{  nzd_ +=1;}while(!(fft_9FFTfit(nzd_)));}
dnsdata_37h=nxd_-1;
dnsdata_38h=nzd_-1;
dnsdata_39i=(ssize_t)sizeof(struct VELOCITY_)*(dnsdata_38h+1);
dnsdata_40i=dnsdata_39i*(dnsdata_37h+1);

Vd_=mmap(NULL,dnsdata_40i,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANON,-1,0);if(Vd_==MAP_FAILED)errmalloc();atblockexit(Vd_f,Vd_free,(void*)Vd_);dnsdata_41h=nxd_-1;
dnsdata_42h=nzd_-1;
dnsdata_43i=(ssize_t)sizeof(struct MOMFLUX_)*(4+1)*(dnsdata_42h+1);
dnsdata_44i=dnsdata_43i*(dnsdata_41h+1);

VVd_=mmap(NULL,dnsdata_44i,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANON,-1,0);if(VVd_==MAP_FAILED)errmalloc();atblockexit(VVd_f,VVd_free,(void*)VVd_);dnsdata_45h=nx_;
dnsdata_46l= - nz_;
dnsdata_47h=nz_;
dnsdata_48i=(ssize_t)sizeof(struct VELOCITY_)*((dnsdata_5nyh+2)-(dnsdata_4nyl-2)+1);
dnsdata_49i=dnsdata_48i*(dnsdata_47h-dnsdata_46l+1);
dnsdata_50i=dnsdata_49i*(dnsdata_45h+1);
dnsdata_51st=(dnsdata_4nyl-2)*(ssize_t)sizeof(struct VELOCITY_);
dnsdata_52st=dnsdata_46l*dnsdata_48i+dnsdata_51st;

V_=mmap(NULL,dnsdata_50i,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANON,-1,0);if(V_==MAP_FAILED)errmalloc();V_-=dnsdata_52st;atblockexit(V_f,V_free,(void*)V_);dnsdata_53h=nx_;
dnsdata_54l= - nz_;
dnsdata_55h=nz_;
dnsdata_56M=dnsdata_4nyl-2;
dnsdata_57l=1;if(dnsdata_57l<dnsdata_56M)dnsdata_57l=dnsdata_56M;dnsdata_58m=dnsdata_5nyh+2;
dnsdata_59h=ny_-1;if(dnsdata_59h>dnsdata_58m)dnsdata_59h=dnsdata_58m;dnsdata_60i=(ssize_t)sizeof(struct rhstype_)*(dnsdata_59h-dnsdata_57l+1);
dnsdata_61i=dnsdata_60i*(dnsdata_55h-dnsdata_54l+1);
dnsdata_62i=dnsdata_61i*(dnsdata_53h+1);
dnsdata_63st=dnsdata_57l*(ssize_t)sizeof(struct rhstype_)+(ssize_t)sizeof(struct rhstype_);
dnsdata_64st=dnsdata_54l*dnsdata_60i+dnsdata_63st;

oldrhs_=mmap(NULL,dnsdata_62i,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANON,-1,0);if(oldrhs_==MAP_FAILED)errmalloc();oldrhs_-=dnsdata_64st;atblockexit(oldrhs_f,oldrhs_free,(void*)oldrhs_);dnsdata_65h=nx_;
dnsdata_66l= - nz_;
dnsdata_67h=nz_;
dnsdata_68i=(ssize_t)sizeof(struct rhstype_)*(2+1);
dnsdata_69i=dnsdata_68i*(dnsdata_67h-dnsdata_66l+1);
dnsdata_70i=dnsdata_69i*(dnsdata_65h+1);
dnsdata_71st=dnsdata_66l*dnsdata_68i;

memrhs_=malloc(dnsdata_70i);if(memrhs_==NULL)errmalloc();memrhs_-=dnsdata_71st;atblockexit(memrhs_f,free,memrhs_+dnsdata_71st);u1zero_=0.;w1zero_=0.;dnsdata_72h=ny_+1;
dnsdata_73h=nx_;
dnsdata_74l= - nz_;
dnsdata_75h=nz_;
dnsdata_76i=(ssize_t)sizeof(struct VELOCITY_)*(dnsdata_75h-dnsdata_74l+1);
dnsdata_77i=dnsdata_76i*(dnsdata_73h+1);
dnsdata_79i=(ssize_t)sizeof(struct VELOCITY_)*(dnsdata_75h-dnsdata_74l+1);
dnsdata_80i=dnsdata_79i*(dnsdata_73h+1);
dnsdata_81i=dnsdata_80i*(dnsdata_72h-(-1)+1);
dnsdata_82st=dnsdata_74l*(ssize_t)sizeof(struct VELOCITY_);
dnsdata_83st=(-1)*dnsdata_77i+dnsdata_82st;
diskimage_=NULL;atblockexit(diskimage_f,errfclose,&diskimage_);dnsdata_84h=ny_+1;
dnsdata_85h=ny_+1;
dnsdata_86h=nx_;
dnsdata_87l= - nz_;
dnsdata_88h=nz_;
dnsdata_89i=(ssize_t)sizeof(struct VETA_)*(dnsdata_88h-dnsdata_87l+1);
dnsdata_90i=dnsdata_89i*(dnsdata_86h+1);
dnsdata_92i=(ssize_t)sizeof(double)*(dnsdata_84h-(-1)+1);
dnsdata_93st=(-1)*(ssize_t)sizeof(double);
dnsdata_94i=(ssize_t)sizeof(struct VETA_)*(dnsdata_88h-dnsdata_87l+1);
dnsdata_95i=dnsdata_94i*(dnsdata_86h+1);
dnsdata_96i=dnsdata_95i*(dnsdata_85h-(-1)+1);
dnsdata_97st=dnsdata_87l*(ssize_t)sizeof(struct VETA_);
dnsdata_98st=(-1)*dnsdata_90i+dnsdata_97st;
diskfield_=NULL;atblockexit(diskfield_f,errfclose,&diskfield_);cont_=0;outcont_=1000;time_file_=NULL;atblockexit(time_file_f,errfclose,&time_file_);if( (next_==NULL) ){ errfopen(&time_file_,"Runtimedata",O_RDWR|O_CREAT|O_TRUNC);};
if( (prev_==NULL) ){ miny_=dnsdata_4nyl-2; maxy_=dnsdata_5nyh   ;}else{ miny_=dnsdata_4nyl;};
if( (next_==NULL)  ){ miny_=dnsdata_4nyl;   maxy_=dnsdata_5nyh+2 ;}else{ maxy_=dnsdata_5nyh;};
if( ((prev_==NULL) )&&( (next_==NULL) )){ miny_=dnsdata_4nyl-2; maxy_=dnsdata_5nyh+2;};

cfl_=0.;cflm_=0.;dnsdata_100h=nx_;
dnsdata_101l= - nz_;
dnsdata_102h=nz_;
dnsdata_103i=(ssize_t)sizeof(struct VETA_)*(dnsdata_102h-dnsdata_101l+1);
dnsdata_104i=dnsdata_103i*(dnsdata_100h+1);
dnsdata_105st=dnsdata_101l*(ssize_t)sizeof(struct VETA_);

fieldbuf_=malloc(dnsdata_104i);if(fieldbuf_==NULL)errmalloc();fieldbuf_-=dnsdata_105st;atblockexit(fieldbuf_f,free,fieldbuf_+dnsdata_105st);dnsdata_106h=nx_;
dnsdata_107l= - nz_;
dnsdata_108h=nz_;
dnsdata_109i=(ssize_t)sizeof(struct VELOCITY_)*(dnsdata_108h-dnsdata_107l+1);
dnsdata_110i=dnsdata_109i*(dnsdata_106h+1);
dnsdata_111st=dnsdata_107l*(ssize_t)sizeof(struct VELOCITY_);

velbuf_=malloc(dnsdata_110i);if(velbuf_==NULL)errmalloc();velbuf_-=dnsdata_111st;atblockexit(velbuf_f,free,velbuf_+dnsdata_111st);dnsdata_117RK1_rai_coeff=120./32.;
dnsdata_119RK2_rai_coeff=120./8.;
dnsdata_121RK3_rai_coeff=120./20.;
dnsdata_123RK1_kom_coeff=1020./240.;
dnsdata_125RK2_kom_coeff=1020./32.;
dnsdata_127RK3_kom_coeff=1020./68.;
dnsdata_129RK4_kom_coeff=1020./170.;

dnsdirect_1h=nx_;
dnsdirect_2l= - nz_;
dnsdirect_3h=nz_;
dnsdirect_5i=(ssize_t)sizeof(struct dnsdirect_s4)*(dnsdirect_3h-dnsdirect_2l+1);
dnsdirect_6i=dnsdirect_5i*(dnsdirect_1h+1);
dnsdirect_7st=dnsdirect_2l*(ssize_t)sizeof(struct dnsdirect_s4);

bc0_=malloc(dnsdirect_6i);if(bc0_==NULL)errmalloc();bc0_-=dnsdirect_7st;atblockexit(bc0_f,free,bc0_+dnsdirect_7st);memset(dnsdirect_7st+bc0_,0,dnsdirect_6i);
bcn_=malloc(dnsdirect_6i);if(bcn_==NULL)errmalloc();bcn_-=dnsdirect_7st;atblockexit(bcn_f,free,bcn_+dnsdirect_7st);memset(dnsdirect_7st+bcn_,0,dnsdirect_6i);dnsdirect: 

dnsdirect_exit:;

/*!USE rtchecks*/
convenience_2i=(ssize_t)sizeof(struct convenience_s1)*((dnsdata_5nyh+2)-(dnsdata_4nyl-2)+1);
convenience_3st=(dnsdata_4nyl-2)*(ssize_t)sizeof(struct convenience_s1);

derivs_standalone_=malloc(convenience_2i);if(derivs_standalone_==NULL)errmalloc();derivs_standalone_-=convenience_3st;atblockexit(derivs_standalone_f,free,derivs_standalone_+convenience_3st);convenience_4M=dnsdata_4nyl-2;
convenience_5m=dnsdata_5nyh+2;
convenience_6=1;if(convenience_6<convenience_4M)convenience_6=convenience_4M;convenience_7=ny_-1;if(convenience_7>convenience_5m)convenience_7=convenience_5m; {int iy_=convenience_6  ;while(iy_<=convenience_7 ){{
  struct convenience_s1 *convenience_8w;
char matder_[(ssize_t)sizeof(double)*(4+1)*(4+1)];

  char tnder_[(ssize_t)sizeof(double)*(4+1)];

  convenience_8w=(struct convenience_s1 *)(iy_*(ssize_t)sizeof(struct convenience_s1)+derivs_standalone_);
memset(matder_,0,(ssize_t)sizeof(double)*(4+1)*(4+1));memset(tnder_,0,(ssize_t)sizeof(double)*(4+1)); {int ic_=0  ;do{ {int ir_=0  ;do{{  (*(double *)(ic_*(ssize_t)sizeof(double)+ir_*(ssize_t)sizeof(double)*(4+1)+matder_) )= pow(((*(double *)((iy_-2+ic_)*(ssize_t)sizeof(double)+y_))-(*(double *)(iy_*(ssize_t)sizeof(double)+y_))),(4-ir_) );}ir_+=1;}while(ir_<=4);}ic_+=1;}while(ic_<=4 );}
  rbmat_6LUdecomp(0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),matder_);
  memset(dnsdata_13st+(*convenience_8w).d1_-dnsdata_13st,0,(ssize_t)sizeof(double)*(2-(-2)+1));  memset(tnder_,0,(ssize_t)sizeof(double)*(4+1));   (*(double *)(3*(ssize_t)sizeof(double)+tnder_) )= 1.;
   {{rbmat_8LeftLDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+(*convenience_8w).d1_-dnsdata_13st ),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(matder_),0,4,(ssize_t)sizeof(double),(tnder_)); rbmat_9LeftUDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+(*convenience_8w).d1_-dnsdata_13st ),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(matder_),(1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+(*convenience_8w).d1_-dnsdata_13st ));};}
  memset(dnsdata_13st+(*convenience_8w).d2_-dnsdata_13st,0,(ssize_t)sizeof(double)*(2-(-2)+1));  memset(tnder_,0,(ssize_t)sizeof(double)*(4+1));   (*(double *)(2*(ssize_t)sizeof(double)+tnder_) )= 2.;
   {{rbmat_8LeftLDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+(*convenience_8w).d2_-dnsdata_13st ),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(matder_),0,4,(ssize_t)sizeof(double),(tnder_)); rbmat_9LeftUDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+(*convenience_8w).d2_-dnsdata_13st ),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(matder_),(1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+(*convenience_8w).d2_-dnsdata_13st ));};}
}iy_+=1;};}
if( (prev_==NULL) ){ { memcpy(dnsdata_13st-(ssize_t)sizeof(struct convenience_s1)+(char*)(*(struct convenience_s1*)(derivs_standalone_)).d1_-dnsdata_13st,dnsdata_13st+d14m1_-((-2)*(ssize_t)sizeof(double)),(ssize_t)sizeof(double)*(2-(-2)+1)); memcpy(dnsdata_13st-(ssize_t)sizeof(struct convenience_s1)+(char*)(*(struct convenience_s1*)(derivs_standalone_)).d2_-dnsdata_13st,dnsdata_13st+d24m1_-((-2)*(ssize_t)sizeof(double)),(ssize_t)sizeof(double)*(2-(-2)+1)); memcpy(dnsdata_13st+(char*)(*(struct convenience_s1*)(derivs_standalone_)).d1_-dnsdata_13st,dnsdata_13st+d140_-((-2)*(ssize_t)sizeof(double)),(ssize_t)sizeof(double)*(2-(-2)+1)); memcpy(dnsdata_13st+(char*)(*(struct convenience_s1*)(derivs_standalone_)).d2_-dnsdata_13st,dnsdata_13st+d240_-((-2)*(ssize_t)sizeof(double)),(ssize_t)sizeof(double)*(2-(-2)+1));}};
if( (next_==NULL)  ){ { memcpy(dnsdata_13st+ny_*(ssize_t)sizeof(struct convenience_s1)+(char*)(*(struct convenience_s1*)(derivs_standalone_)).d1_-dnsdata_13st,dnsdata_13st+d14n_-((-2)*(ssize_t)sizeof(double)),(ssize_t)sizeof(double)*(2-(-2)+1));  memcpy(dnsdata_13st+ny_*(ssize_t)sizeof(struct convenience_s1)+(char*)(*(struct convenience_s1*)(derivs_standalone_)).d2_-dnsdata_13st,dnsdata_13st+d24n_-((-2)*(ssize_t)sizeof(double)),(ssize_t)sizeof(double)*(2-(-2)+1));  memcpy(dnsdata_13st+(ny_+1)*(ssize_t)sizeof(struct convenience_s1)+(char*)(*(struct convenience_s1*)(derivs_standalone_)).d1_-dnsdata_13st,dnsdata_13st+d14np1_-((-2)*(ssize_t)sizeof(double)),(ssize_t)sizeof(double)*(2-(-2)+1)); memcpy(dnsdata_13st+(ny_+1)*(ssize_t)sizeof(struct convenience_s1)+(char*)(*(struct convenience_s1*)(derivs_standalone_)).d2_-dnsdata_13st,dnsdata_13st+d24np1_-((-2)*(ssize_t)sizeof(double)),(ssize_t)sizeof(double)*(2-(-2)+1));}};

convenience: 

convenience_exit:;


/*! Parameters*/
/*! -----------------------------*/
nfmin_=atoi((void *)((*(char**)(4*(ssize_t)sizeof(char*)+(char*)argv))));
nfmax_=atoi((void *)((*(char**)(5*(ssize_t)sizeof(char*)+(char*)argv))));
dn_=atoi((void *)((*(char**)(6*(ssize_t)sizeof(char*)+(char*)argv))));
/*!------------------------------*/



/*! Definitions*/
/*! ------------------------------------*/
step0A_pressure_1h=nx_;
step0A_pressure_2l= - nz_;
step0A_pressure_3h=nz_;
step0A_pressure_4i=(ssize_t)sizeof(struct COMPLEX_)*((dnsdata_5nyh+2)-(dnsdata_4nyl-2)+1);
step0A_pressure_5i=step0A_pressure_4i*(step0A_pressure_3h-step0A_pressure_2l+1);
step0A_pressure_6i=step0A_pressure_5i*(step0A_pressure_1h+1);
step0A_pressure_7st=(dnsdata_4nyl-2)*(ssize_t)sizeof(struct COMPLEX_);
step0A_pressure_8st=step0A_pressure_2l*step0A_pressure_4i+step0A_pressure_7st;

pressure_=mmap(NULL,step0A_pressure_6i,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANON,-1,0);if(pressure_==MAP_FAILED)errmalloc();pressure_-=step0A_pressure_8st;atblockexit(pressure_f,pressure_free,(void*)pressure_);memset(step0A_pressure_8st+pressure_,0,step0A_pressure_6i);step0A_pressure_9h=nx_;
step0A_pressure_10l= - nz_;
step0A_pressure_11h=nz_;
step0A_pressure_12i=(ssize_t)sizeof(struct DERIVS_)*((dnsdata_5nyh+2)-(dnsdata_4nyl-2)+1);
step0A_pressure_13i=step0A_pressure_12i*(step0A_pressure_11h-step0A_pressure_10l+1);
step0A_pressure_14i=step0A_pressure_13i*(step0A_pressure_9h+1);
step0A_pressure_15st=(dnsdata_4nyl-2)*(ssize_t)sizeof(struct DERIVS_);
step0A_pressure_16st=step0A_pressure_10l*step0A_pressure_12i+step0A_pressure_15st;

Vder_=mmap(NULL,step0A_pressure_14i,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANON,-1,0);if(Vder_==MAP_FAILED)errmalloc();Vder_-=step0A_pressure_16st;atblockexit(Vder_f,Vder_free,(void*)Vder_);memset(step0A_pressure_16st+Vder_,0,step0A_pressure_14i);step0A_pressure_17h=nx_;
step0A_pressure_18l= - nz_;
step0A_pressure_19h=nz_;
step0A_pressure_20i=(ssize_t)sizeof(struct COMPLEX_)*(step0A_pressure_19h-step0A_pressure_18l+1);
step0A_pressure_21i=step0A_pressure_20i*(step0A_pressure_17h+1);
step0A_pressure_22st=step0A_pressure_18l*(ssize_t)sizeof(struct COMPLEX_);

pbuf_=malloc(step0A_pressure_21i);if(pbuf_==NULL)errmalloc();pbuf_-=step0A_pressure_22st;atblockexit(pbuf_f,free,pbuf_+step0A_pressure_22st);step0A_pressure_23h=nx_;
step0A_pressure_24l= - nz_;
step0A_pressure_25h=nz_;
step0A_pressure_26i=(ssize_t)sizeof(struct COMPLEX_)*(step0A_pressure_25h-step0A_pressure_24l+1);
step0A_pressure_27i=step0A_pressure_26i*(step0A_pressure_23h+1);
pressuredata_=NULL;atblockexit(pressuredata_f,errfclose,&pressuredata_);poisson_solver_parallel_1h=ny_+1;
poisson_solver_parallel_2i=(ssize_t)sizeof(double)*(poisson_solver_parallel_1h-(-1)+1);

y_first_=malloc(poisson_solver_parallel_2i);if(y_first_==NULL)errmalloc();y_first_-=dnsdata_93st;atblockexit(y_first_f,free,y_first_+dnsdata_93st);memset(dnsdata_93st+y_first_,0,poisson_solver_parallel_2i);  {int i_=(-1);do{{ (*(double *)(i_*(ssize_t)sizeof(double)+y_first_))=ymin_+0.5*(ymax_-ymin_)*(tanh(a_*((double)(2*i_)/(double)(ny_)-1.))/tanh(a_)+1.) ;}i_++;}while(i_<=poisson_solver_parallel_1h);}
poisson_solver_parallel_3h=ny_-1;
poisson_solver_parallel_4i=(ssize_t)sizeof(struct dnsdata_s12)*poisson_solver_parallel_3h;

fderivatives_=malloc(poisson_solver_parallel_4i);if(fderivatives_==NULL)errmalloc();fderivatives_-=(ssize_t)sizeof(struct dnsdata_s12);atblockexit(fderivatives_f,free,fderivatives_+(ssize_t)sizeof(struct dnsdata_s12));if( (prev_==NULL) ){
         {int iy_=1  ;while(iy_<=ny_-1 ){{
                struct dnsdata_s12 *poisson_solver_parallel_5w;
poisson_solver_parallel_5w=(struct dnsdata_s12 *)(iy_*(ssize_t)sizeof(struct dnsdata_s12)+fderivatives_);
 {int i_=0  ;do{ {int j_=0  ;do{{ (*(double *)(j_*(ssize_t)sizeof(double)+i_*(ssize_t)sizeof(double)*(4+1)+Mf_))=pow(((*(double *)((iy_-2+j_)*(ssize_t)sizeof(double)+y_first_))-(*(double *)(iy_*(ssize_t)sizeof(double)+y_first_))),(4-i_) );}j_+=1;}while(j_<=4);}i_+=1;}while(i_<=4 );}  rbmat_6LUdecomp(0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),Mf_);
                memset(tf_,0,(ssize_t)sizeof(double)*(4+1));  (*(double *)(tf_))=24.;
                {{rbmat_8LeftLDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+(*poisson_solver_parallel_5w).d4_-dnsdata_13st),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(Mf_),0,4,(ssize_t)sizeof(double),(tf_)); rbmat_9LeftUDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+(*poisson_solver_parallel_5w).d4_-dnsdata_13st),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(Mf_),(1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+(*poisson_solver_parallel_5w).d4_-dnsdata_13st));};}
                 {int i_=0  ;do{ {int j_=0  ;do{{ (*(double *)(j_*(ssize_t)sizeof(double)+i_*(ssize_t)sizeof(double)*(4+1)+Mf_))=(double)((5-i_)*(6-i_)*(7-i_)*(8-i_))*pow(((*(double *)((iy_-2+j_)*(ssize_t)sizeof(double)+y_first_))-(*(double *)(iy_*(ssize_t)sizeof(double)+y_first_))),(4-i_) );}j_+=1;}while(j_<=4);}i_+=1;}while(i_<=4 );}  rbmat_6LUdecomp(0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),Mf_);
                 {int i_=0  ;do{{  (*(double *)(i_*(ssize_t)sizeof(double)+tf_))=0.; {int j_= - 2  ;do{{(*(double *)(i_*(ssize_t)sizeof(double)+tf_))+=((*(double *)(j_*(ssize_t)sizeof(double)+(*poisson_solver_parallel_5w).d4_-dnsdata_13st))*pow(((*(double *)((iy_+j_)*(ssize_t)sizeof(double)+y_first_))-(*(double *)(iy_*(ssize_t)sizeof(double)+y_first_))),(8-i_))) ;}j_+=1;}while(j_<=2 );}}i_+=1;}while(i_<=4);}
                {{rbmat_8LeftLDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+(*poisson_solver_parallel_5w).d0_-dnsdata_13st),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(Mf_),0,4,(ssize_t)sizeof(double),(tf_)); rbmat_9LeftUDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+(*poisson_solver_parallel_5w).d0_-dnsdata_13st),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(Mf_),(1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+(*poisson_solver_parallel_5w).d0_-dnsdata_13st));};}
                 {int i_=0  ;do{ {int j_=0  ;do{{ (*(double *)(j_*(ssize_t)sizeof(double)+i_*(ssize_t)sizeof(double)*(4+1)+Mf_))=pow(((*(double *)((iy_-2+j_)*(ssize_t)sizeof(double)+y_first_))-(*(double *)(iy_*(ssize_t)sizeof(double)+y_first_))),(4-i_) );}j_+=1;}while(j_<=4);}i_+=1;}while(i_<=4 );}  rbmat_6LUdecomp(0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),Mf_);
                memset(tf_,0,(ssize_t)sizeof(double)*(4+1));   {int i_=0  ;do{{  (*(double *)(i_*(ssize_t)sizeof(double)+tf_))=0.; {int j_= - 2  ;do{{(*(double *)(i_*(ssize_t)sizeof(double)+tf_))+=(*(double *)(j_*(ssize_t)sizeof(double)+(*poisson_solver_parallel_5w).d0_-dnsdata_13st))*(double)((4-i_))*(double)((3-i_))*pow(((*(double *)((iy_+j_)*(ssize_t)sizeof(double)+y_first_))-(*(double *)(iy_*(ssize_t)sizeof(double)+y_first_))),(2-i_) );}j_+=1;}while(j_<=2 );}}i_+=1;}while(i_<=2);}
                {{rbmat_8LeftLDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+(*poisson_solver_parallel_5w).d2_-dnsdata_13st),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(Mf_),0,4,(ssize_t)sizeof(double),(tf_)); rbmat_9LeftUDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+(*poisson_solver_parallel_5w).d2_-dnsdata_13st),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(Mf_),(1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+(*poisson_solver_parallel_5w).d2_-dnsdata_13st));};}
                memset(tf_,0,(ssize_t)sizeof(double)*(4+1));   {int i_=0  ;do{{  (*(double *)(i_*(ssize_t)sizeof(double)+tf_))=0.; {int j_= - 2  ;do{{(*(double *)(i_*(ssize_t)sizeof(double)+tf_))+=(*(double *)(j_*(ssize_t)sizeof(double)+(*poisson_solver_parallel_5w).d0_-dnsdata_13st))*(double)((4-i_))*pow(((*(double *)((iy_+j_)*(ssize_t)sizeof(double)+y_first_))-(*(double *)(iy_*(ssize_t)sizeof(double)+y_first_))),(3-i_) );}j_+=1;}while(j_<=2 );}}i_+=1;}while(i_<=3);}
                {{rbmat_8LeftLDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+(*poisson_solver_parallel_5w).d1_-dnsdata_13st),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(Mf_),0,4,(ssize_t)sizeof(double),(tf_)); rbmat_9LeftUDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+(*poisson_solver_parallel_5w).d1_-dnsdata_13st),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(Mf_),(1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+(*poisson_solver_parallel_5w).d1_-dnsdata_13st));};}
        }iy_+=1;};}

	 {int i_=0  ;do{ {int j_=0  ;do{{ (*(double *)(j_*(ssize_t)sizeof(double)+i_*(ssize_t)sizeof(double)*(4+1)+Mf_))=pow(((*(double *)((-1+j_)*(ssize_t)sizeof(double)+y_first_))-(*(double *)(y_first_))),(4-i_) );}j_+=1;}while(j_<=4);}i_+=1;}while(i_<=4 );}  rbmat_6LUdecomp(0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),Mf_);
	memset(tf_,0,(ssize_t)sizeof(double)*(4+1));  (*(double *)(3*(ssize_t)sizeof(double)+tf_))=1.;
	{{rbmat_8LeftLDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+fd140_-((-2)*(ssize_t)sizeof(double))),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(Mf_),0,4,(ssize_t)sizeof(double),(tf_)); rbmat_9LeftUDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+fd140_-((-2)*(ssize_t)sizeof(double))),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(Mf_),(1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+fd140_-((-2)*(ssize_t)sizeof(double))));};}
	memset(tf_,0,(ssize_t)sizeof(double)*(4+1));  (*(double *)(2*(ssize_t)sizeof(double)+tf_))=2.;
	{{rbmat_8LeftLDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+fd240_-((-2)*(ssize_t)sizeof(double))),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(Mf_),0,4,(ssize_t)sizeof(double),(tf_)); rbmat_9LeftUDiv((1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+fd240_-((-2)*(ssize_t)sizeof(double))),0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),(Mf_),(1==0?INT_MIN:((-2)-(-2))),(1==0?INT_MAX:(2-(-2))),(ssize_t)sizeof(double),((-2)*(ssize_t)sizeof(double)+fd240_-((-2)*(ssize_t)sizeof(double))));};}
	 {int i_=0  ;do{ {int j_=0  ;do{{ (*(double *)(j_*(ssize_t)sizeof(double)+i_*(ssize_t)sizeof(double)*(4+1)+Mf_))=pow(((*(double *)((-1+j_)*(ssize_t)sizeof(double)+y_first_))-(*(double *)(-(ssize_t)sizeof(double)+y_first_))),(4-i_) );}j_+=1;}while(j_<=4);}i_+=1;}while(i_<=4 );}  rbmat_6LUdecomp(0,4,(ssize_t)sizeof(double)*(4+1),0,4,(ssize_t)sizeof(double),Mf_);
};



/*! Compute the pressure field*/
/*! ------------------------------------*/
files:;  {int n_=nfmin_  ;while(n_<=nfmax_ ){
  struct freefunc field_name_f;char *field_name_; 

  struct freefunc cart_name_f;char *cart_name_; 

  struct freefunc pfield_name_f;char *pfield_name_; 

  field_name_=0;atblockexit(field_name_f,condfree,field_name_); {char *tmp; tmp=malloc(snprintf(NULL,0,"""Field""%d"".fld""",n_)+1); sprintf(tmp,"""Field""%d"".fld""",n_); if(field_name_)free(field_name_);field_name_=tmp;}convenience_11read_field_parallel(field_name_);
  poisson_solver_parallel_10compute_pressure(0,step0A_pressure_9h,step0A_pressure_13i,step0A_pressure_10l,step0A_pressure_11h,step0A_pressure_12i,(dnsdata_4nyl-2),(dnsdata_5nyh+2),(ssize_t)sizeof(struct DERIVS_),Vder_,0,step0A_pressure_1h,step0A_pressure_5i,step0A_pressure_2l,step0A_pressure_3h,step0A_pressure_4i,(dnsdata_4nyl-2),(dnsdata_5nyh+2),(ssize_t)sizeof(struct COMPLEX_),pressure_);
  if( !(prev_==NULL) ){  while(!feof( prev_)&&getc( prev_)!='\n'){};};
  cart_name_=0;atblockexit(cart_name_f,condfree,cart_name_); {char *tmp; tmp=malloc(snprintf(NULL,0,"""Dati.cart.""%d"".fld""",n_)+1); sprintf(tmp,"""Dati.cart.""%d"".fld""",n_); if(cart_name_)free(cart_name_);cart_name_=tmp;}pfield_name_=0;atblockexit(pfield_name_f,condfree,pfield_name_); {char *tmp; tmp=malloc(snprintf(NULL,0,"""pField""%d"".fld""",n_)+1); sprintf(tmp,"""pField""%d"".fld""",n_); if(pfield_name_)free(pfield_name_);pfield_name_=tmp;} errfopen(&diskimage_ ,cart_name_,O_RDWR|O_CREAT);
   errfopen(&pressuredata_ ,pfield_name_,O_RDWR|O_CREAT);
  {
    if( (next_==NULL) ){
      char *step0A_pressure_28; fprintf(stdout,"""Writing " "%s",cart_name_);putc('\n',stdout);
      fseeko(diskimage_,(-(0))+(ssize_t)(*(struct dnsdata_s78 *)(0)).header_ ,SEEK_SET);step0A_pressure_28=malloc(snprintf(NULL,0,"         ny=""%d""       nx=""%d""       nz=""%d""\n"
"	 alfa0=""%g""     beta0=""%g""\n"
"         ymin=""%g""        ymax=""%g""          a=""%g""\n"
"         ni=""%g""       time=""%g""\n"
"         """,ny_,nx_,nz_,alfa0_,beta0_,ymin_,ymax_,a_,1./ni_,time_)+1);sprintf(step0A_pressure_28,"         ny=""%d""       nx=""%d""       nz=""%d""\n"
"	 alfa0=""%g""     beta0=""%g""\n"
"         ymin=""%g""        ymax=""%g""          a=""%g""\n"
"         ni=""%g""       time=""%g""\n"
"         """,ny_,nx_,nz_,alfa0_,beta0_,ymin_,ymax_,a_,1./ni_,time_); fprintf( diskimage_,"%s",step0A_pressure_28);putc('\n', diskimage_);
    free(step0A_pressure_28);};
    {int iy_=  miny_  ;while(iy_<=maxy_){
     off_t step0A_pressure_39st;
off_t step0A_pressure_40st;
  {int iz_=dnsdata_107l;do{{ int step0A_pressure_29h;
int step0A_pressure_30h;
int step0A_pressure_33h;
int step0A_pressure_34h;
step0A_pressure_29h=nx_;
step0A_pressure_30h=nx_;
{char *step0A_pressure_32_;

step0A_pressure_32_=iy_*(ssize_t)sizeof(struct VELOCITY_)+iz_*dnsdata_48i+V_; {char *step0A_pressure_31_=iz_*(ssize_t)sizeof(struct VELOCITY_)+velbuf_;int step0A_pressure_31_1=step0A_pressure_29h; do{{ (*(struct VELOCITY_ *)(step0A_pressure_31_))=(*(struct VELOCITY_ *)(step0A_pressure_32_)); step0A_pressure_32_ =dnsdata_49i+step0A_pressure_32_;}step0A_pressure_31_+=dnsdata_109i;step0A_pressure_31_1--;}while(step0A_pressure_31_1>=0);}}   step0A_pressure_33h=nx_;
step0A_pressure_34h=nx_;
{char *step0A_pressure_36_;

step0A_pressure_36_=iy_*(ssize_t)sizeof(struct COMPLEX_)+iz_*step0A_pressure_4i+pressure_; {char *step0A_pressure_35_=iz_*(ssize_t)sizeof(struct COMPLEX_)+pbuf_;int step0A_pressure_35_1=step0A_pressure_33h; do{{ {register double temp=(*(struct COMPLEX_*)(step0A_pressure_36_)).REAL_;(*(struct COMPLEX_ *)(step0A_pressure_35_)).IMAG_=(*(struct COMPLEX_*)(step0A_pressure_36_)).IMAG_;(*(struct COMPLEX_ *)(step0A_pressure_35_)).REAL_=temp;}; step0A_pressure_36_ =step0A_pressure_5i+step0A_pressure_36_;}step0A_pressure_35_+=step0A_pressure_20i;step0A_pressure_35_1--;}while(step0A_pressure_35_1>=0);}}}iz_++;}while(iz_<=dnsdata_108h);}
        {int _37i_=dnsdata_73h;do{{if((ssize_t)sizeof(struct VELOCITY_)==(ssize_t)sizeof(struct VELOCITY_)&&(ssize_t)sizeof(struct VELOCITY_)==(ssize_t)sizeof(struct VELOCITY_)){if(!(fseeko(diskimage_,_37i_*(off_t)dnsdata_76i+iy_*(off_t)dnsdata_77i+(off_t)((ssize_t)sizeof(struct dnsdata_s78)-dnsdata_83st+(ssize_t)(char*)(struct dnsdata_s78*)(0))+dnsdata_82st,SEEK_SET)==0&&fwrite(_37i_*dnsdata_109i+velbuf_+dnsdata_82st,(ssize_t)sizeof(struct VELOCITY_),dnsdata_75h-dnsdata_74l+1,diskimage_)==dnsdata_75h-dnsdata_74l+1))ioerr(diskimage_);}else{  {int _38i_=dnsdata_74l;do{{if(!(fseeko(diskimage_,_38i_*(off_t)(ssize_t)sizeof(struct VELOCITY_)+_37i_*(off_t)dnsdata_76i+iy_*(off_t)dnsdata_77i+(off_t)((ssize_t)sizeof(struct dnsdata_s78)-dnsdata_83st+(ssize_t)(char*)(struct dnsdata_s78*)(0)),SEEK_SET)==0&&fwrite((struct VELOCITY_*)(_38i_*(ssize_t)sizeof(struct VELOCITY_)+_37i_*dnsdata_109i+velbuf_),(ssize_t)sizeof(struct VELOCITY_),1,diskimage_)==1))ioerr(diskimage_);}_38i_++;}while(_38i_<=dnsdata_75h);}};}_37i_--;}while(_37i_>=0);}
     step0A_pressure_39st=step0A_pressure_24l*(ssize_t)sizeof(struct COMPLEX_);
step0A_pressure_40st=(dnsdata_4nyl-2)*step0A_pressure_27i+step0A_pressure_39st;
   {int _41i_=step0A_pressure_23h;do{{ssize_t step0A_pressure_42st;
step0A_pressure_42st=step0A_pressure_24l*(ssize_t)sizeof(struct COMPLEX_);
if((ssize_t)sizeof(struct COMPLEX_)==(ssize_t)sizeof(struct COMPLEX_)&&(ssize_t)sizeof(struct COMPLEX_)==(ssize_t)sizeof(struct COMPLEX_)){if(!(fseeko(pressuredata_,_41i_*(off_t)step0A_pressure_26i+iy_*(off_t)step0A_pressure_27i+(-step0A_pressure_40st)+step0A_pressure_42st,SEEK_SET)==0&&fwrite(_41i_*step0A_pressure_20i+pbuf_+step0A_pressure_42st,(ssize_t)sizeof(struct COMPLEX_),step0A_pressure_25h-step0A_pressure_24l+1,pressuredata_)==step0A_pressure_25h-step0A_pressure_24l+1))ioerr(pressuredata_);}else{  {int _43i_=step0A_pressure_24l;do{{if(!(fseeko(pressuredata_,_43i_*(off_t)(ssize_t)sizeof(struct COMPLEX_)+_41i_*(off_t)step0A_pressure_26i+iy_*(off_t)step0A_pressure_27i+(-step0A_pressure_40st),SEEK_SET)==0&&fwrite((struct COMPLEX_*)(_43i_*(ssize_t)sizeof(struct COMPLEX_)+_41i_*step0A_pressure_20i+pbuf_),(ssize_t)sizeof(struct COMPLEX_),1,pressuredata_)==1))ioerr(pressuredata_);}_43i_++;}while(_43i_<=step0A_pressure_25h);}};}_41i_--;}while(_41i_>=0);}
   iy_+=1;};}
  errfclose(&diskimage_);
  errfclose(&pressuredata_);
  if( !(next_==NULL) ){  putc('\n', next_);};
}freemem(&fderivatives_f);n_+= dn_;};}files_exit:;
     
freemem(es);return 0;}
