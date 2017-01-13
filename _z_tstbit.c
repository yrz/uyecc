#include "zf.h"

z_uint 
_z_tstbit(z_t a, z_uint b, z_uint len)
{
  int bb,bw;
  z_word i = 1;
  
  bb = b%Z_WORD_BITS;
  bw = b/Z_WORD_BITS;
  i = i<<(bb);
  
  return ((a[bw]&i)>>bb);
}
