#ifndef __UYECC_C_
#define __UYECC_C_

#include <stdlib.h>
#include "gmp-5.0.2/gmp.h"
#include "p.h"

typedef struct curve_s{
  mpz_t fp;
  mpz_t a;
  mpz_t b;
  p_t  *g;
  mpz_t h;
  int bit;
} curve_t;

curve_t *curve_init();
curve_t *curve_mini_init();
curve_t *curve_112r1_init();

#endif
