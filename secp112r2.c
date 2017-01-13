#include "ecc.h"

void 
ecc_init()
{
  ecc.bit = 112;

  ecc.fp[3] = 0x0000DB7C;
  ecc.fp[2] = 0x2ABF62E3;
  ecc.fp[1] = 0x5E668076;
  ecc.fp[0] = 0xBEAD208B;
    
  // 2^ecc.bit mod ecc.fp
  ecc.op[3]=0x0000241e;
  ecc.op[2]=0xaa05e8e5;
  ecc.op[1]=0x0cccfc4a;
  ecc.op[0]=0x0a97fba8;
    
  //cure that will be used
  //a
  ecc.a[3] = 0x00006127;
  ecc.a[2] = 0xC24C05F3;
  ecc.a[1] = 0x8A0AAAF6;
  ecc.a[0] = 0x5C0EF02C;
/*
  ecc.a_minus3 = 0;
  ecc.a_zero = 0;
*/   
    //b
  ecc.b[3] = 0x000051DE;
  ecc.b[2] = 0xF1815DB5;
  ecc.b[1] = 0xED74FCC3;
  ecc.b[0] = 0x4C85D709;
          
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
    
  ecc.h = 4;
  */
}
