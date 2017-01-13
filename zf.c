#include "zf.h"
#ifdef DEVRANDOM
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#endif

#include <stdio.h>

short
_z_cmp(z_t r, z_t op, z_uint len)
{
  int i;
  for(i = len-1; i >= 0; i--) {
    if(r[i] > op[i]) return 1;
    if(r[i] < op[i]) return -1;
  }
  return 0;
}

void
_z_print(z_t r, z_uint len)
{
  _z_printn(r, len);
  printf("\n");
  return;
}

void
_z_printn(z_t r, z_uint len)
{
  int i;
  printf("0x");
  for(i = len-1; i >= 0; i--) {
    printf("%08x", r[i]);
  }
  return;
}

short
_z_is_zero(z_t r, z_uint len)
{
  int i;
  for(i = len; i >= 0; i--) {
    if(r[i] != 0) return 0;
  }
  return 1;
}

void
_z_set_ui(z_t r, z_uint op, z_uint len)
{
  int i;
  r[0] = op;
  for(i = 1; i <= len; i++) {
    r[i] = 0;
  }
}

void
_z_zero(z_t r, z_uint len)
{
  _z_set_ui(r, 0, len);
}

void
_z_set(z_t r, z_t op, z_uint len)
{
  z_uint i;
  for(i = 0; i <= len; i++) {
    r[i] = op[i];
  }
}

#ifdef DEVRANDOM
void 
_z_set_random(z_t r, z_t f, z_uint len)
{
  z_uint i, rand, size;
  z_t tmp;

  rand = open("/dev/random", O_RDONLY);
  if(rand < 0) printf("open /dev/random failed\n");
//  excess_bits = len%Z_WORD_BITS;
//  printf("z_word_bits %d\n", Z_WORD_BITS);
//  printf("len: %d, excess bits: %d\n", len, excess_bits);
  for(i = 0; i < len; i++) {
    size = read(rand, (void *)&tmp[i], sizeof(z_word));
//    printf("i%d/%d my read %d, expected %d\n", i,len, size, sizeof(z_word));
    if(size != sizeof(z_word)){
//      printf("read %d, expected %d, are differents?\n", size, sizeof(z_word));
      i--;
    }
  }
  tmp[i] = 0;
//  i--;
//  tmp[i] = tmp[i] << excess_bits;
//  tmp[i] = tmp[i] >> excess_bits;
  close(rand);
  _z_set(r, tmp, len);
}
#else
void 
_z_set_random(z_t r, z_t f, z_uint len)
{
#error "not implemented"  
}
#endif

#ifdef EIGHT_BIT_PROCESSOR
#include "zf8.c"
#endif

#ifdef SIXTEEN_BIT_PROCESSOR
#include "zf16.c"
#endif

#ifdef THIRTYTWO_BIT_PROCESSOR
#include "zf32.c"
#endif
