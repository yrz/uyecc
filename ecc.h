#ifndef __ECC_H__
#define __ECC_H__

#ifdef SEC112R2
#include "sec112r2.h"
#endif

#include "zf.h"
#include "p.h"

typedef struct curve_s{
z_t fp;
z_t op;
z_t a;
z_t b;
p_t G;
z_uint bit;
} curve_t;

curve_t ecc;

void ecc_init();

/*
short ecc_a_m3 = 0;
short ecc_a_zero = 0;
short ecc_h = 4; 
z_t ecc_r; // prime divide number of point, eh???
*/

#endif
