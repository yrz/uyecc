#ifndef _UYECC_POP_H
#define _UYECC_POP_H

#include "zf.h"
#include "p.h"
#include "ecc.h"
#include "ecc_zf.h"

void p_dbl(p_t r, p_t p, curve_t c);

void p_add(p_t r, p_t p, p_t q, curve_t c);

void p_dbl(p_t r, p_t p, curve_t c);

void p_mul_ui(p_t o, p_t p, unsigned int k, curve_t c);

void p_mul(p_t r0, p_t p, z_t k, curve_t c);

#endif
