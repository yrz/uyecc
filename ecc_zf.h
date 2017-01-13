#ifndef __ECCZF_H__
#define __ECCZF_H__

#define z_set(a,b) _z_set(a, b, KEY_BITLEN)
#define z_set_ui(a,b) _z_set_ui(a, b, KEY_BITLEN)
#define z_cmp(a,b) _z_cmp(a, b, KEY_BITLEN)
#define z_sub(a,b,c) _z_sub(a, b, c, KEY_BITLEN)
#define z_add(a,b,c) _z_add(a, b, c, KEY_BITLEN)
#define z_add_ui(a,b,c) _z_add_ui(a, b, c, KEY_BITLEN)
#define z_mod(a,b,c) _z_mod(a, b, c, KEY_BITLEN)
#define z_mul(a,b,c) _z_mul(a, b, c, KEY_BITLEN)
#define z_mul_ui(a,b,c) _z_mul_ui(a, b, c, KEY_BITLEN)
#define z_powm_ui(a,b,c,d) _z_powm_ui(a, b, c, d, KEY_BITLEN)
#define z_powm(a,b,c,d) _z_powm(a, b, c, d, KEY_BITLEN)
#define z_invert(a,b,c) _z_inv_mod(a, b, c, KEY_BITLEN);
#define z_tstbit(a,b) _z_tstbit(a, b, KEY_BITLEN);

/*
void _z_decode(char *str_out, z_t op, z_uint len);
void _z_set_str(z_t r, char *str_in, z_uint len);
void _z_set_random(z_t r, z_t f, z_uint len);
void _z_set(z_t r, z_t op, z_uint len);
void _z_set2exp(z_t r, z_uint b, z_uint len);
void _z_add(z_t r, z_t op1, z_t op2, z_uint len);
void _z_add_mod(z_t r, z_t op1, z_t op2, z_t f, z_uint len);
void _z_sub(z_t r, z_t op1, z_t op2, z_uint len);
void _z_sub_mod(z_t r, z_t op1, z_t op2, z_t f, z_uint len);
void _z_neg(z_t r, z_t op1, z_uint len);
void _z_neg_mod(z_t r, z_t op1, z_t f, z_uint len);
void _z_mul(z_t r, z_t op1, z_t op2, z_uint len);
void _z_mul_mod(z_t r, z_t op1, z_t op2, z_t f, z_uint len);
z_uint _z_lshift(z_t r, z_t op1, z_uint op2, z_uint len);
z_uint _z_rshift(z_t r, z_t op1, z_uint op2, z_uint len);
void _z_div(z_t r, z_t op1, z_t op2, z_uint len);
void _z_sqrt(z_t r, z_t op, z_uint len);
void _z_mod(z_t r, z_t op, z_t f, z_uint len);
void _z_powm(z_t r, z_t b, z_t e, z_t f, z_uint len);
int _z_inv_mod(z_t r, z_t op, z_t f, z_uint len);
void _z_mul_opt(z_t r, z_t op1, z_t op2, z_t f, z_uint len);
void _z_div_mod(z_t r, z_t op1, z_t op2, z_t f, z_uint len);
void _z_mod_sqrt(z_t r, z_t op, z_t f, z_uint len);
int _z_cmp(z_t a, z_t b, z_uint len);
int _z_eq(z_t a, z_t b, z_uint len);
int _z_zero(z_t a, z_uint len);
int _z_one(z_t a, z_uint len); 
*/

#endif
