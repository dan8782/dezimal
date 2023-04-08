#include "../../s21_decimal.h"

void set_zero(s21_decimal *decl) {
  for (int i = 0; i < 128; ++i) {
    set_bit(decl, i, 0);
  }
}

void set_zero_big(big_decimal *big_dec) {
  for (int i = 0; i < 6; ++i) {
    big_dec->bits[i] = 0;
  }
  big_dec->exp = 0;
  big_dec->sign = 0;
}

big_decimal init() {
  big_decimal big_dec;
  for (int i = 0; i < 6; ++i) {
    big_dec.bits[i] = 0;
  }
  big_dec.exp = 0;
  big_dec.sign = 0;

  return big_dec;
}

void init_small(s21_decimal *num) {
  num->bits[0] = 0U;
  num->bits[1] = 0U;
  num->bits[2] = 0U;
  num->bits[3] = 0U;
}
