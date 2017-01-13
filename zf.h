#ifndef __ZF_H__
#define __ZF_H__

#include <stdint.h>

#ifdef SECP112R2
#include "secp112r2_f.h"
#elif SECP128R1
#include "secp128r1_f.h"
#else
#error "no field defined"
#endif

#ifdef EIGHT_BIT_PROCESSOR
#include "zf8.h"
#endif

#ifdef SIXTEEN_BIT_PROCESSOR
#include "zf16.h"
#endif

#ifdef THIRTYTWO_BIT_PROCESSOR
#include "zf32.h"
#endif

typedef uint16_t z_uint;
typedef uint32_t z_dbl_uint;

#define Z_WORD_BYTES (Z_WORD_BITS/8)
#define KEY_WORDLEN (KEY_BITLEN/Z_WORD_BITS)
#define FF_WORDS ((KEY_BITLEN/Z_WORD_BITS)+1)
#define MAX_FF_WORDS (FF_WORDS+1)
#define FF_NUMWORDS MAX_FF_WORDS

typedef z_word z_t[FF_WORDS];
typedef z_word z_dt[FF_WORDS*2];
typedef z_word *z_p;

z_t __fp;
z_t __cp;

void _z_init();

void _z_print(z_word *op, z_uint len);
void _z_printn(z_word *op, z_uint len);
void _z_decode(char *str_out, z_word *op, z_uint len);

void _z_set_str(z_word *r, char *str_in, z_uint len);
void _z_set_random(z_word *r, z_word *f, z_uint len);
void _z_set(z_word *r, z_word *op, z_uint len);
void _z_set_ui(z_word *r, z_uint op, z_uint len);
void _z_set2exp(z_word *r, z_uint b, z_uint len);

z_uint _z_add(z_word *r, z_word *op1, z_word *op2, z_uint len);
z_uint _z_add_ui(z_word *r, z_word *op1, z_uint op2, z_uint len);
void _z_add_mod(z_word *r, z_word *op1, z_word *op2, z_uint len);

z_uint _z_sub(z_word *r, z_word *op1, z_word *op2, z_uint len);
void _z_sub_mod(z_word *r, z_word *op1, z_word *op2, z_uint len);

z_uint _z_neg(z_word *r, z_word *op1, z_uint len);
void _z_neg_mod(z_word *r, z_word *op1, z_word *f, z_uint len);

void _z_mul(z_word *r, z_word *op1, z_word *op2, z_uint len);
void _z_mul_ui(z_word *r, z_word *op1, z_uint op2, z_uint len);
void _z_mul_mod(z_word *r, z_word *op1, z_word *op2, z_uint len);

z_uint _z_lshift(z_word *r, z_word *op1, z_uint op2, z_uint len);
void _z_rshift(z_word *r, z_word *op1, z_uint shift, z_uint len);
z_uint _z_tstbit(z_word *a, z_uint b, z_uint len);

void _z_div(z_word *r, z_word *op1, z_word *op2, z_uint len);
void _z_sqrt(z_word *r, z_word *op, z_uint len);

void _z_mod(z_word *r, z_word *op, z_word *f, z_uint len);

void _z_powm(z_word *r, z_word *b, z_word *e, z_word *f, z_uint len);
void _z_powm_ui(z_word *r, z_word *b, z_uint e, z_word *f, z_uint len);

/* r = 1/op mod f, return error */
z_uint _z_inv_mod(z_word *r, z_word *op, z_word *f, z_uint len);

/* optimized for curves, f mersenne prime, 2^a-b */
void _z_mul_opt(z_word *r, z_word *op1, z_word *op2, z_word *f, z_uint len);

/* invert or montgomery */
void _z_div_mod(z_word *r, z_word *op1, z_word *op2, z_word *f, z_uint len);

/* algo? */
void _z_mod_sqrt(z_word *r, z_word *op, z_word *f, z_uint len);

short _z_cmp(z_word *a, z_word *b, z_uint len); /* +1 a>b, 0 a=b, -1 a<b */
short _z_is_zero(z_word *a, z_uint len); /* 1 a==0, 0 a!=0 */
short _z_eq(z_word *a, z_word *b, z_uint len); /* 1 a=b */

void _z_zero(z_word *a, z_uint len); /* 1 a=0 */
int _z_one(z_word *a, z_uint len); /* 1 a=1 */

#endif
