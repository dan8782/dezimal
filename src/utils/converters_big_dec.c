#include "../s21_decimal.h"

big_decimal dec_to_big(s21_decimal dec) {
  big_decimal big_dec;
  set_zero_big(&big_dec);

  for (int i = 0; i < 3; i++) {
    big_dec.bits[i] = dec.bits[i];
  }
  big_dec.exp = get_exp(&dec);
  big_dec.sign = get_sign(&dec);

  return big_dec;
}

s21_decimal big_to_dec(big_decimal *big_dec) {
  s21_decimal s21_dec = {0};

  for (int i = 0; i < 3; i++) {
    s21_dec.bits[i] = big_dec->bits[i];
  }
  set_exp(&s21_dec, big_dec->exp);
  set_sign(&s21_dec, big_dec->sign);

  return s21_dec;
}