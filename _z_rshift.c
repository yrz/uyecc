#include "zf.h"
#include <stdio.h>

void
_z_rshift(z_word *r, z_word *op1, z_uint shift, z_uint len)
{
  int i, bs, ws;
  z_dt t;
  z_word an, bn;
  
  bs = shift%Z_WORD_BITS;
  ws = shift/Z_WORD_BITS;
  bn = Z_MAX_WORD>>(Z_WORD_BITS-bs);
  an = Z_MAX_WORD<<bs;
  
  for(i = len-1; i > ws; i--)
  {
    t[i] = (((op1[i-ws])<<bs)&an);
    t[i] |= (((op1[i-ws-1])>>(Z_WORD_BITS-bs)) & bn);
  }
  t[ws] = (op1[ws]<<bs)&an;
  if(ws>0)
  {
    for(i = ws-1; i >= 0; i--) {
      t[i] = 0;
    }
  }
  _z_set(r,t,len);
  return;
}
