#include "zf.h"

void
_z_zero(z_t r, z_uint len)
{
  z_uint i;
  for(i = 0; i < len; i++) {
    r[i] = 0;
  }
}

void
_z_zerob(z_t r, z_uint len)
{
  z_uint i, ebits;
//  ebits = len%Z_WORD_BITS;
  for(i = 0; i < rlen; i++) {
    r[i] = 0;
  }
//  r[i] = r[i] >> ebits;
//  r[i] = r[i] << ebits;
}

