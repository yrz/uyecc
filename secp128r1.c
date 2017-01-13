#include "ecc.h"

void 
ecc_init()
{
  ecc.bit = 128;

  ecc.fp[4]=0x00000000;
  ecc.fp[3]=0xfffffffd;
  ecc.fp[2]=0xffffffff;
  ecc.fp[1]=0xffffffff;
  ecc.fp[0]=0xffffffff;
    
  // 2^ecc.bit mod ecc.fp
  ecc.op[4]=0x00000000;
  ecc.op[3]=0x00000002;
  ecc.op[2]=0x00000000;
  ecc.op[1]=0x00000000;
  ecc.op[0]=0x00000001;

  //a
  ecc.a[4]=0x00000000;
  ecc.a[3]=0xfffffffd;
  ecc.a[2]=0xffffffff;
  ecc.a[1]=0xffffffff;
  ecc.a[0]=0xfffffffc;
/*
  ecc.a_minus3 = 0;
  ecc.a_zero = 0;
*/   
    //b
  ecc.b[4]=0x00000000;
  ecc.b[3]=0xe87579c1;
  ecc.b[2]=0x1079f43d;
  ecc.b[1]=0xd824993c;
  ecc.b[0]=0x2cee5ed3;
          
/*	  
    //base point
  ecc.G.x[3] =  0x00004ba3;
  ecc.G.x[2] =  0x0ab5e892;
  ecc.G.x[1] =  0xb4e1649d;
  ecc.G.x[0] =  0xd0928643;
   
  ecc.G.y[3] =  0x0000acdc;
  ecc.G.y[2] =  0x46f5882e;
  ecc.G.y[1] =  0x3747def3;
  ecc.G.y[0] =  0x6e956e97;
  */ 
   /*       	
    //prime divide the number of points
  ecc.r[3] = 0x000036DF;
  ecc.r[2] = 0x0AAFD8B8;
  ecc.r[1] = 0xD7597CA1;
  ecc.r[0] = 0x0520D04B;
    
  ecc.h = 1;
  */
}
