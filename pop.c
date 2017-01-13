#include "pop.h"

void p_set(p_t p, p_t q)
{
  z_set(p.x, q.x);
  z_set(p.y, q.y);
}

void p_add(p_t r, p_t p, p_t q, curve_t c) 
{
  z_t tmp1, tmp2;
  z_t y2my1;
  z_t x2mx1;
  z_t rx_tmp;
  z_t ry_tmp;
  
  if(p.inf && q.inf) {
    r.inf = 1;
    return;
  }
  if(p.inf == 1) {
    z_set(r.x, q.x);
    z_set(r.y, q.y);
    r.inf = 0;
    return;
  } else if(q.inf == 1) {
    z_set(r.x, p.x);
    z_set(r.y, p.y);
    r.inf = 0;
    return;
  }
  if(z_cmp(p.x, q.x) == 0 && z_cmp(p.y, q.y) == 0) {
    p_dbl(r, p, c);
    return;
  }
  r.inf = 0;

  z_sub(y2my1, q.y, p.y);
  z_mod(y2my1, y2my1, c.fp);
  
  z_sub(x2mx1, q.x, p.x);
  z_invert(x2mx1, x2mx1, c.fp);
  
  z_mul(tmp1, y2my1, x2mx1);
  z_mod(tmp1, tmp1, c.fp);
  
  z_powm_ui(rx_tmp, tmp1, 2, c.fp);
  z_sub(rx_tmp, rx_tmp, p.x);
  z_mod(rx_tmp, rx_tmp, c.fp);
  z_sub(rx_tmp, rx_tmp, q.x);
  z_mod(rx_tmp, rx_tmp, c.fp);
  
  z_sub(tmp2, p.x, rx_tmp);
  z_mod(tmp2, tmp2, c.fp);
  z_mul(ry_tmp, tmp1, tmp2);
  z_mod(ry_tmp, ry_tmp, c.fp);
  z_sub(ry_tmp, ry_tmp, p.y);
  z_mod(ry_tmp, ry_tmp, c.fp);
  
  z_set(r.x, rx_tmp);
  z_set(r.y, ry_tmp);
}

void p_dbl(p_t r, p_t p, curve_t c) 
{
  z_t tmp1, tmp2;
  z_t tx12a;
  z_t rx_tmp, ry_tmp;
  
  if(p.inf == 1) 
    return;
  
  z_powm_ui(tx12a, p.x, 2, c.fp);
  z_mul_ui(tx12a, tx12a, 3);
  z_mod(tx12a, tx12a, c.fp);
  z_add(tx12a, tx12a, c.a);
  z_mod(tx12a, tx12a, c.fp);
  z_mul_ui(tmp1, p.y, 2);
  z_mod(tmp1, tmp1, c.fp);
  z_invert(tmp1, tmp1, c.fp);
  z_mul(tmp1, tmp1, tx12a);
  
  //calc r.x
  z_powm_ui(tmp2, tmp1, 2, c.fp);
  z_sub(tmp2, tmp2, p.x);
  z_mod(tmp2, tmp2, c.fp);
  z_sub(tmp2, tmp2, p.x);
  z_mod(rx_tmp, tmp2, c.fp);
  
  //calc r.y
  z_sub(tmp2, p.x, rx_tmp);
  z_mod(tmp2, tmp2, c.fp);
  z_mul(tmp2, tmp1, tmp2);
  z_mod(tmp2, tmp2, c.fp);
  z_sub(tmp2, tmp2, p.y);
  z_mod(ry_tmp, tmp2, c.fp);

  z_set(r.x, rx_tmp);
  z_set(r.y, ry_tmp);
}

void p_mul_ui(p_t o, p_t p, unsigned int k, curve_t c)
{
  z_t nk;
    
  z_set_ui(nk, k);
  p_mul(o, p, nk, c);
  return;
}

void p_mul(p_t r0, p_t p, z_t k, curve_t c)
{
/* montgomery algorithm */
  p_t r1;
  int d, i;
  
  p_set(r1, p);
  r0.inf = 1;

  for(i = c.bit; i >= 0; i--) {
    d = z_tstbit (k, i);
    if(d == 0) {
      p_add(r1, r0, r1, c);
      p_dbl(r0, r0, c);
    } else {
      p_add(r0, r0, r1, c);
      p_dbl(r1, r1, c);
    }
  }
  return;
}

