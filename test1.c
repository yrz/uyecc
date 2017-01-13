/*
#include "c.h"
#include "pop.h"
 */

#include "ecc.h"
#include <stdio.h>
#include "zf.h"
#include "p.h"
#include "pop.h"

void
uyc_gen_prv_key(z_t d)
{
  do {
    _z_set_random(d, ecc.fp, KEY_WORDLEN);
  } while (_z_cmp(ecc.fp, d, KEY_WORDLEN) < 0);
}

void
uyc_gen_pub_key(p_t Q, z_t d)
{
 p_mul(Q, ecc.G, d, ecc);
}

int main(void) 
{
  z_t a, b;
  z_dt c;
	z_t d;

  _z_init();
  ecc_init();
  
  a[4] = 0x00000000;
  a[3] = 0x80000000;
  a[2] = 0x00000000;
  a[1] = 0x00000000;
  a[0] = 0x00000001;
 
  b[4] = 0x00000000;
  b[3] = 0x80000000;
  b[2] = 0x00000000;
  b[1] = 0x00000000;
  b[0] = 0x00000001;

/*
  _z_set_random(a, __fp, KEY_WORDLEN);
  _z_set_random(b, __fp, KEY_WORDLEN);
  a[4] = 0;
  b[4] = 0;
  */
  printf("../uyecc_gmp/112 ");
  _z_printn(a, KEY_WORDLEN);
  printf(" ");
  _z_printn(b, KEY_WORDLEN);
  printf(" ");
  _z_print(__fp, KEY_WORDLEN);

  _z_mul(c, b, a, KEY_WORDLEN);
  _z_print(c, KEY_WORDLEN*2);

  _z_mul_mod(d, b, a, KEY_WORDLEN);
  _z_print(d, KEY_WORDLEN);

/*
  printf("c:     ");
  _z_print(c, KEY_WORDLEN);
  printf("fp:    ");
  _z_print(__fp, KEY_WORDLEN);
  */
/*
  _z_mod(c, a, ecc.fp, ecc.bit);
  for(i = 3; i >= 0; i--) {
    printf("ecc.op[%d]=0x%08x\n", i, c[i]);
  }
 */
 /*
  uyc_gen_prv_key(d);
  */
  return 0;
}
