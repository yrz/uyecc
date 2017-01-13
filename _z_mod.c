#include "zf.h"

void _z_mod(z_t r, z_t op, z_t f, z_uint len)
{
  _z_set(r, op, len);
  while((_z_cmp(f, r, len)) < 1) {
    _z_sub(r, r, f, len);
  }
  return;
}
