#include "ecc.h"

void 
_z_init()
{
  __cp[4]=0x00000000;
  __cp[3]=0x00000002;
  __cp[2]=0x00000000;
  __cp[1]=0x00000000;
  __cp[0]=0x00000001;

  __fp[4]=0x00000000;
  __fp[3]=0xfffffffd;
  __fp[2]=0xffffffff;
  __fp[1]=0xffffffff;
  __fp[0]=0xffffffff;
}
