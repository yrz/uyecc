#include "zf.h"

void 
_z_add_mod(z_t r, z_t op1, z_t op2, z_uint len)
{
  z_uint carry;
  
  carry = _z_add(r, op1, op2, len);
  if(carry) _z_sub(r, r, __fp, len);
  if(_z_cmp(__fp, r, len) < 1) _z_sub(r, r, __fp, len);
}

z_uint 
_z_add(z_word *r, z_word *op1, z_word *op2, z_uint len)
{
  z_word carry;
  z_uint i;
  z_word t;

  carry = 0;

  for(i = 0; i < len; i++) {
    if((t = op1[i] + carry) < carry) {
      t = op2[i];
    } else if ((t += op2[i]) < op2[i]) {
      carry = 1;
    } else {
      carry = 0;
    }
    r[i] = t;
  }
  return carry;
}

z_uint 
_z_add_ui(z_t r, z_t op1, z_uint op2, z_uint len)
{
  z_t zop2;
  
  _z_set_ui(zop2, op2, len);
  return _z_add(r, op1, zop2, len);
}
