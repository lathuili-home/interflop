#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../../include/interflop.h"

static bool debug = false;
#define debug_print(fmt, ...) \
            do { if (debug) fprintf(stderr, fmt, __VA_ARGS__); } while (0)


static void _interflop_add_float(float a, float b , float* c, void* context) {
  *c = a + b;
  debug_print("interflop %g + %g -> %g\n", a, b, c);
}

static void _interflop_sub_float(float a, float b, float* c, void* context) {
  *c = a - b;
  debug_print("interflop %g - %g -> %g\n", a, b, c);
}

static void _interflop_mul_float(float a, float b, float* c, void* context) {
  *c = a * b;
  debug_print("interflop %g * %g -> %g\n", a, b, c);
}

static void _interflop_div_float(float a, float b, float* c, void* context) {
  *c = a / b;
  debug_print("interflop %g / %g -> %g\n", a, b, c);
}

static void _interflop_add_double(double a, double b , double* c, void* context) {
  *c = a + b;
  debug_print("interflop %g + %g -> %g\n", a, b, c);
}

static void _interflop_sub_double(double a, double b, double* c, void* context) {
  *c = a - b;
  debug_print("interflop %g - %g -> %g\n", a, b, c);
}

static void _interflop_mul_double(double a, double b, double* c, void* context) {
  *c = a * b;
  debug_print("interflop %g * %g -> %g\n", a, b, c);
}

static void _interflop_div_double(double a, double b, double* c, void* context) {
  *c = a / b;
  debug_print("interflop %g / %g -> %g\n", a, b, c);
}

struct interflop_backend_interface_t interflop_init(void ** context) {

  char * interflop_backend_debug = getenv("INTERFLOP_IEEE_DEBUG");
  if (interflop_backend_debug != NULL) {
    debug = true;
  }

  struct interflop_backend_interface_t interflop_backend_ieee = {
    _interflop_add_float,
    _interflop_sub_float,
    _interflop_mul_float,
    _interflop_div_float,
    _interflop_add_double,
    _interflop_sub_double,
    _interflop_mul_double,
    _interflop_div_double,

    NULL, //void (*interflop_add_floatx2)(floatx2, floatx2, floatx2*, void*);
    NULL, //void (*interflop_sub_floatx2)(floatx2, floatx2, floatx2*, void*);
    NULL, //void (*interflop_mul_floatx2)(floatx2, floatx2, floatx2*, void*);
    NULL, //void (*interflop_div_floatx2)(floatx2, floatx2, floatx2*, void*);

    NULL, //void (*interflop_add_floatx4)(floatx4, floatx4, floatx4*, void*);
    NULL, //void (*interflop_sub_floatx4)(floatx4, floatx4, floatx4*, void*);
    NULL, //void (*interflop_mul_floatx4)(floatx4, floatx4, floatx4*, void*);
    NULL, //void (*interflop_div_floatx4)(floatx4, floatx4, floatx4*, void*);

    NULL, //void (*interflop_add_floatx8)(floatx8, floatx8, floatx8*, void*);
    NULL, //void (*interflop_sub_floatx8)(floatx8, floatx8, floatx8*, void*);
    NULL, //void (*interflop_mul_floatx8)(floatx8, floatx8, floatx8*, void*);
    NULL, //void (*interflop_div_floatx8)(floatx8, floatx8, floatx8*, void*);

    NULL, //void (*interflop_add_doublex2)(doublex2, doublex2, doublex2*, void*);
    NULL, //void (*interflop_sub_doublex2)(doublex2, doublex2, doublex2*, void*);
    NULL, //void (*interflop_mul_doublex2)(doublex2, doublex2, doublex2*, void*);
    NULL, //void (*interflop_div_doublex2)(doublex2, doublex2, doublex2*, void*);

    NULL, //void (*interflop_add_doublex4)(doublex4, doublex4, doublex4*, void*);
    NULL, //void (*interflop_sub_doublex4)(doublex4, doublex4, doublex4*, void*);
    NULL, //void (*interflop_mul_doublex4)(doublex4, doublex4, doublex4*, void*);
    NULL, //void (*interflop_div_doublex4)(doublex4, doublex4, doublex4*, void*);

    NULL,  //void (*interflop_cast_double_to_float)(double, float*, void*);

    NULL, //void (*interflop_madd_float)(float, float, float, float*, void*);
    NULL  //void (*interflop_madd_double)(double, double, double, double*, void*);
  };

  return interflop_backend_ieee;
}
