/* This file was automatically generated by CasADi 3.6.7+.
 *  It consists of: 
 *   1) content generated by CasADi runtime: not copyrighted
 *   2) template code copied from CasADi source: permissively licensed (MIT-0)
 *   3) user code: owned by the user
 *
 */
#ifdef __cplusplus
extern "C" {
#endif

/* How to prefix internal symbols */
#ifdef CASADI_CODEGEN_PREFIX
  #define CASADI_NAMESPACE_CONCAT(NS, ID) _CASADI_NAMESPACE_CONCAT(NS, ID)
  #define _CASADI_NAMESPACE_CONCAT(NS, ID) NS ## ID
  #define CASADI_PREFIX(ID) CASADI_NAMESPACE_CONCAT(CODEGEN_PREFIX, ID)
#else
  #define CASADI_PREFIX(ID) Aircraft_Attitude_expl_vde_adj_ ## ID
#endif

#include <math.h>

#ifndef casadi_real
#define casadi_real double
#endif

#ifndef casadi_int
#define casadi_int int
#endif

/* Add prefix to internal symbols */
#define casadi_f0 CASADI_PREFIX(f0)
#define casadi_s0 CASADI_PREFIX(s0)
#define casadi_s1 CASADI_PREFIX(s1)
#define casadi_s2 CASADI_PREFIX(s2)
#define casadi_s3 CASADI_PREFIX(s3)
#define casadi_sq CASADI_PREFIX(sq)

/* Symbol visibility in DLLs */
#ifndef CASADI_SYMBOL_EXPORT
  #if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
    #if defined(STATIC_LINKED)
      #define CASADI_SYMBOL_EXPORT
    #else
      #define CASADI_SYMBOL_EXPORT __declspec(dllexport)
    #endif
  #elif defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
    #define CASADI_SYMBOL_EXPORT __attribute__ ((visibility ("default")))
  #else
    #define CASADI_SYMBOL_EXPORT
  #endif
#endif

casadi_real casadi_sq(casadi_real x) { return x*x;}

static const casadi_int casadi_s0[3] = {11, 1, 1};
static const casadi_int casadi_s1[3] = {3, 1, 1};
static const casadi_int casadi_s2[3] = {0, 0, 1};
static const casadi_int casadi_s3[3] = {14, 1, 1};

/* Aircraft_Attitude_expl_vde_adj:(i0[11],i1[11],i2[3],i3[])->(o0[14]) */
static int casadi_f0(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  casadi_real a00, a01, a02, a03, a04, a05, a06, a07, a08, a09, a10, a11;
  casadi_real a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22;
  a00=arg[0]? arg[0][6] : 0;
  a01=5.0000000000000000e-01;
  a02=arg[1]? arg[1][5] : 0;
  a02=(a01*a02);
  a03=(a00*a02);
  a04=arg[0]? arg[0][5] : 0;
  a05=arg[1]? arg[1][6] : 0;
  a05=(a01*a05);
  a06=(a04*a05);
  a03=(a03-a06);
  a06=arg[0]? arg[0][3] : 0;
  a07=arg[1]? arg[1][4] : 0;
  a07=(a01*a07);
  a08=(a06*a07);
  a03=(a03+a08);
  a08=arg[0]? arg[0][4] : 0;
  a09=arg[1]? arg[1][3] : 0;
  a01=(a01*a09);
  a09=(a08*a01);
  a03=(a03-a09);
  a09=-1.0000000000000001e-01;
  a10=arg[0]? arg[0][2] : 0;
  a11=10.;
  a12=arg[1]? arg[1][1] : 0;
  a12=(a11*a12);
  a13=(a10*a12);
  a13=(a09*a13);
  a03=(a03-a13);
  if (res[0]!=0) res[0][0]=a03;
  a03=(a08*a05);
  a13=(a06*a02);
  a03=(a03+a13);
  a13=(a00*a07);
  a03=(a03-a13);
  a13=(a04*a01);
  a03=(a03-a13);
  a13=arg[1]? arg[1][0] : 0;
  a11=(a11*a13);
  a13=(a10*a11);
  a13=(a09*a13);
  a03=(a03+a13);
  if (res[0]!=0) res[0][1]=a03;
  a06=(a06*a05);
  a08=(a08*a02);
  a06=(a06-a08);
  a04=(a04*a07);
  a06=(a06+a04);
  a00=(a00*a01);
  a06=(a06-a00);
  a00=arg[0]? arg[0][0] : 0;
  a04=(a09*a00);
  a04=(a04*a12);
  a06=(a06-a04);
  a04=arg[0]? arg[0][1] : 0;
  a09=(a09*a04);
  a09=(a09*a11);
  a06=(a06+a09);
  if (res[0]!=0) res[0][2]=a06;
  a06=(a10*a05);
  a09=(a04*a02);
  a06=(a06+a09);
  a09=(a00*a07);
  a06=(a06+a09);
  if (res[0]!=0) res[0][3]=a06;
  a06=(a04*a05);
  a09=(a10*a02);
  a06=(a06-a09);
  a09=(a00*a01);
  a06=(a06-a09);
  if (res[0]!=0) res[0][4]=a06;
  a06=(a10*a07);
  a05=(a00*a05);
  a06=(a06-a05);
  a05=(a04*a01);
  a06=(a06-a05);
  if (res[0]!=0) res[0][5]=a06;
  a00=(a00*a02);
  a04=(a04*a07);
  a00=(a00-a04);
  a10=(a10*a01);
  a00=(a00-a10);
  if (res[0]!=0) res[0][6]=a00;
  a00=arg[0]? arg[0][7] : 0;
  a10=(a00+a00);
  a01=-1.3000000000000001e-09;
  a04=8.0000000000000002e-03;
  a07=arg[0]? arg[0][9] : 0;
  a02=(a04*a07);
  a06=sin(a02);
  a06=(a06*a12);
  a06=(a01*a06);
  a06=(a10*a06);
  a05=3.4499999999999998e-08;
  a09=3.0000000000000001e-03;
  a08=(a09*a07);
  a03=cos(a08);
  a13=7.2499999999999995e-02;
  a14=5.;
  a15=arg[1]? arg[1][2] : 0;
  a14=(a14*a15);
  a14=(a13*a14);
  a15=5.0000000000000001e-03;
  a15=(a15*a12);
  a16=(a14+a15);
  a03=(a03*a16);
  a03=(a05*a03);
  a03=(a10*a03);
  a06=(a06-a03);
  a03=-1.0000000000000000e-08;
  a17=7.0000000000000001e-03;
  a07=(a17*a07);
  a18=sin(a07);
  a19=-4.9999999999999996e-02;
  a19=(a19*a12);
  a13=(a13*a11);
  a11=(a19+a13);
  a18=(a18*a11);
  a18=(a03*a18);
  a10=(a10*a18);
  a06=(a06+a10);
  if (res[0]!=0) res[0][7]=a06;
  a06=arg[0]? arg[0][8] : 0;
  a10=(a06+a06);
  a18=arg[0]? arg[0][10] : 0;
  a20=(a09*a18);
  a21=cos(a20);
  a14=(a14-a15);
  a21=(a21*a14);
  a21=(a05*a21);
  a21=(a10*a21);
  a15=(a04*a18);
  a22=sin(a15);
  a22=(a22*a12);
  a22=(a01*a22);
  a22=(a10*a22);
  a21=(a21-a22);
  a18=(a17*a18);
  a22=sin(a18);
  a13=(a13-a19);
  a22=(a22*a13);
  a22=(a03*a22);
  a10=(a10*a22);
  a21=(a21+a10);
  if (res[0]!=0) res[0][8]=a21;
  a08=sin(a08);
  a00=casadi_sq(a00);
  a21=(a05*a00);
  a21=(a21*a16);
  a08=(a08*a21);
  a08=(a09*a08);
  a02=cos(a02);
  a21=(a01*a00);
  a21=(a21*a12);
  a02=(a02*a21);
  a02=(a04*a02);
  a08=(a08+a02);
  a07=cos(a07);
  a00=(a03*a00);
  a00=(a00*a11);
  a07=(a07*a00);
  a07=(a17*a07);
  a08=(a08+a07);
  if (res[0]!=0) res[0][9]=a08;
  a18=cos(a18);
  a06=casadi_sq(a06);
  a03=(a03*a06);
  a03=(a03*a13);
  a18=(a18*a03);
  a17=(a17*a18);
  a20=sin(a20);
  a05=(a05*a06);
  a05=(a05*a14);
  a20=(a20*a05);
  a09=(a09*a20);
  a15=cos(a15);
  a01=(a01*a06);
  a01=(a01*a12);
  a15=(a15*a01);
  a04=(a04*a15);
  a09=(a09+a04);
  a17=(a17-a09);
  if (res[0]!=0) res[0][10]=a17;
  a17=arg[1]? arg[1][7] : 0;
  a09=arg[1]? arg[1][8] : 0;
  a17=(a17-a09);
  if (res[0]!=0) res[0][11]=a17;
  a17=arg[1]? arg[1][9] : 0;
  if (res[0]!=0) res[0][12]=a17;
  a17=arg[1]? arg[1][10] : 0;
  if (res[0]!=0) res[0][13]=a17;
  return 0;
}

CASADI_SYMBOL_EXPORT int Aircraft_Attitude_expl_vde_adj(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
  return casadi_f0(arg, res, iw, w, mem);
}

CASADI_SYMBOL_EXPORT int Aircraft_Attitude_expl_vde_adj_alloc_mem(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT int Aircraft_Attitude_expl_vde_adj_init_mem(int mem) {
  return 0;
}

CASADI_SYMBOL_EXPORT void Aircraft_Attitude_expl_vde_adj_free_mem(int mem) {
}

CASADI_SYMBOL_EXPORT int Aircraft_Attitude_expl_vde_adj_checkout(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT void Aircraft_Attitude_expl_vde_adj_release(int mem) {
}

CASADI_SYMBOL_EXPORT void Aircraft_Attitude_expl_vde_adj_incref(void) {
}

CASADI_SYMBOL_EXPORT void Aircraft_Attitude_expl_vde_adj_decref(void) {
}

CASADI_SYMBOL_EXPORT casadi_int Aircraft_Attitude_expl_vde_adj_n_in(void) { return 4;}

CASADI_SYMBOL_EXPORT casadi_int Aircraft_Attitude_expl_vde_adj_n_out(void) { return 1;}

CASADI_SYMBOL_EXPORT casadi_real Aircraft_Attitude_expl_vde_adj_default_in(casadi_int i) {
  switch (i) {
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* Aircraft_Attitude_expl_vde_adj_name_in(casadi_int i) {
  switch (i) {
    case 0: return "i0";
    case 1: return "i1";
    case 2: return "i2";
    case 3: return "i3";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* Aircraft_Attitude_expl_vde_adj_name_out(casadi_int i) {
  switch (i) {
    case 0: return "o0";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* Aircraft_Attitude_expl_vde_adj_sparsity_in(casadi_int i) {
  switch (i) {
    case 0: return casadi_s0;
    case 1: return casadi_s0;
    case 2: return casadi_s1;
    case 3: return casadi_s2;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* Aircraft_Attitude_expl_vde_adj_sparsity_out(casadi_int i) {
  switch (i) {
    case 0: return casadi_s3;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT int Aircraft_Attitude_expl_vde_adj_work(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w) {
  if (sz_arg) *sz_arg = 4;
  if (sz_res) *sz_res = 1;
  if (sz_iw) *sz_iw = 0;
  if (sz_w) *sz_w = 0;
  return 0;
}

CASADI_SYMBOL_EXPORT int Aircraft_Attitude_expl_vde_adj_work_bytes(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w) {
  if (sz_arg) *sz_arg = 4*sizeof(const casadi_real*);
  if (sz_res) *sz_res = 1*sizeof(casadi_real*);
  if (sz_iw) *sz_iw = 0*sizeof(casadi_int);
  if (sz_w) *sz_w = 0*sizeof(casadi_real);
  return 0;
}


#ifdef __cplusplus
} /* extern "C" */
#endif
