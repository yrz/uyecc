#include "zf.h"

z_uint
_z_sub(z_t r, z_t op1, z_t op2, z_uint len)
{
  z_word ai, borrow;
  int i;

  borrow = 0;
//  ebits = len%Z_WORD_BITS;
//  op1[rlen] = op1[rlen] << ebits;
//  op1[rlen] = op1[rlen] >> ebits;
//  op2[rlen] = op2[rlen] << ebits;
//  op2[rlen] = op2[rlen] >> ebits;
  
  for(i = 0; i < len; i++) {
    if((ai = op1[i] - borrow) > (Z_MAX_WORD - borrow)) {
      ai = Z_MAX_WORD - op2[i];
    } else if((ai -= op2[i]) > (Z_MAX_WORD - op2[i])) {
        borrow = 1;
    } else {
        borrow = 0;
    }
    r[i] = ai;
  }
  return borrow;
}

void
_z_sub_mod(z_t r, z_t op1, z_t op2, z_uint len)
{
  z_t tmp;
  z_uint borrow;
  borrow = _z_sub(tmp, op1, op2, len); 
  if(borrow) _z_add(r, tmp, __fp, len);
}

