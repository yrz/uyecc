#include "zf.h"
#include <stdio.h>

z_word
_z_word_karatsuba(z_word *r, z_word op1, z_word op2)
{
  z_word z0, z2;
  z_dbl_word z1;
  z_word a1, b1, a2, b2;
  int carry = 0;
  
  a1 = (MH_WORD & op1) >> H_WORD_BITS;
  b1 = LH_WORD & op1;
  a2 = (MH_WORD & op2) >> H_WORD_BITS;
  b2 = LH_WORD & op2;
  z0 = b1*b2;
  z2 = a1*a2;
  z1 = (z_dbl_word)(a1+b1)*(z_dbl_word)(a2+b2);
  z1 = z1-z2-z0;
  
  if(z0 > Z_MAX_WORD-((LH_WORD&z1)<<H_WORD_BITS)) {
    carry++;
  }
  *r = z0+((LH_WORD&z1)<<H_WORD_BITS);
  carry += z2+(z1>>H_WORD_BITS);
  
  return carry;
}

/*
void 
_z_karatsuba(z_t rh, z_t rl, z_t op1, z_t op2, z_uint len)
{
  z_word *a1,*a2,*b1,*b2;
  z_uint nlen, rlen;
  z_word r;

  nlen = len/2;
  rlen = len-nlen;
  
    
    _z_karatsuba(rh+nlen, rh, op1+nlen, op2+nlen, rlen);
    _z_karatsuba(rl+nlen, rl, op1, op2, rlen);
  }
  return;
}
*/

void
_z_preprint(z_word u, z_uint post)
{
  int x;
  printf("0x%08x", u);
  for(x = post; x > 0; x--) {
    printf("%08x", 0);
  }
  printf("\n");
}

void 
_z_mul(z_word *r, z_word *op1, z_word *op2, z_uint len)
{
  int i, j;
  z_dt tr, ta;
  
  _z_zero(tr, len*2);
  _z_zero(ta, len*2);
	_z_set(ta, op1, len);
  
  for (i = len*Z_WORD_BITS-1; i >= 0; i--) {
    _z_rshift(tr, tr, 1, len*2);
    if(_z_tstbit(op2, i, len)) {
      _z_add(tr, tr, ta, len*2);
    }
  }
  _z_set(r, tr, len*2);

  return;
/*
  z_dt tr;
  z_word u, v, carry;
  z_uint ebits;
  int i, j, x;

//  ebits = len%Z_WORD_BITS;
  for(i = len*2+1; i >= 0; i--) {
    tr[i] = 0;
  }
  for(i = 0; i < len; i++) {
    u = 0;
    carry = 0;
    for(j = 0; j < len; j++) {
      if(u > (Z_MAX_WORD-tr[i+j])) {
        tr[i+j+1]++; 
	printf("u+1 on %d\n", i+j);
        printf("OVER: tr[%02d]=0x%08x 0x%08x\n", i+j, tr[i+j], u);
      }
      tr[i+j] += u;
      printf("tr[%02d]=0x%08x\n", i+j, tr[i+j]);
      u = _z_word_karatsuba(&v, op1[i], op2[j]);
      if(v > (Z_MAX_WORD-tr[i+j])) {
        tr[i+j+1]++; 
	printf("v+1 on %d\n", i+j);
        printf("OVER: tr[%02d]=0x%08x 0x%08x\n", i+j, tr[i+j], v);
      }
      tr[i+j] += v;
      printf("tr[%02d]=0x%08x\n", i+j, tr[i+j]);
    }
    //printf("OVER: tr[%02d]=0x%08x 0x%08x\n", i+j, tr[i+j], u);
    if(u > (Z_MAX_WORD-tr[i+j])) {tr[i+j+1]++; printf("over+1 on %d\n", i+j);}
    tr[i+j] += u;
  }
  _z_set(r, tr, len*2);
  _z_print(r, len*2);
  
  return;
  */
}

void
_z_mul2(z_word *r1, z_word *r2, z_word *op1, z_word *op2, z_uint len)
{
  z_dt tmp;
  
  _z_mul(tmp, op1, op2, len);
//    printf("tmp:   ");
//    _z_print(tmp, len*2);
  _z_set(r1, tmp, len);
  _z_set(r2, tmp+len, len);
  r1[4]=0;
  r2[4]=0;
}

void
_z_mul_mod(z_t r, z_t op1, z_t op2, z_uint len)
{
  z_t tmp1, tmp2, tmp3;
  short a;
  
  _z_mul2(tmp1, tmp2, op1, op2, len);
 
  while((a=_z_is_zero(tmp2, len)) == 0) {
    _z_mod(tmp2, tmp2, __fp, len);
    _z_mul2(tmp3, tmp2, __cp, tmp2, len);
    _z_add_mod(tmp1, tmp1, tmp3, len);
  }
  _z_set(r, tmp1, len);
  return;
}

void
_z_mul_ui(z_t r, z_t op1, z_uint op2, z_uint len)
{
}

