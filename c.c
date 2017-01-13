#include "c.h"

curve_t *curve_init(){
  curve_t *c;
  c = (curve_t *)malloc(sizeof(curve_t));
  c->g = p_init();
  mpz_init(c->fp);
  mpz_init(c->a);
  mpz_init(c->b);
  
  return c;
}

curve_t *curve_mini_init(){
  curve_t *c;
  
  c = curve_init();
  mpz_set_str(c->fp, "29", 10);
  mpz_set_str(c->a, "4", 10);
  mpz_set_str(c->b, "20", 10);
  mpz_set_str(c->g->x, "5", 10);
  mpz_set_str(c->g->y, "22", 10);
  mpz_set_str(c->h, "42", 10);
  c->bit = 6;
  
  return c;
}

curve_t *curve_112r1_init(){
  curve_t *c;

  c = curve_init();
  mpz_set_str(c->fp, "0x0000DB7C2ABF62E35E668076BEAD208B", 0);
  mpz_set_str(c->a, "0x00006127C24C05F38A0AAAF65C0EF02C", 0);
  mpz_set_str(c->b, "0x000051DEF1815DB5ED74FCC34C85D709", 0);
  mpz_set_str(c->g->x, "0x00004BA30AB5E892B4E1649DD0928643", 0);
  mpz_set_str(c->g->y, "0x0000acdc46f5882e3747def36e956e97", 0);
  c->bit = 112;
//  mpz_set_str(r, "0x000036DF0AAFD8B8D7597CA10520D04B", 0);
//  h = 4;
    
  return c;
}
