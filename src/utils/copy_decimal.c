#include "../s21_decimal.h"

void copy_decimal(s21_decimal *decimal, s21_decimal origdec) {
  for (int i = 0; i < 4; ++i) {
    decimal->bits[i] = origdec.bits[i];
  }
}

void copy_decimal_big(big_decimal *decimal, big_decimal origdec) {
  for (int i = 0; i < 6; ++i) {
    decimal->bits[i] = origdec.bits[i];
  }
  decimal->exp = origdec.exp;
  decimal->sign = origdec.sign;
}