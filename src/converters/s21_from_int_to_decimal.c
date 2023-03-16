#include "../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  // заполненение массива указанными символами = 0
  set_zero(dst);
  if (src < 0) {
    set_sign(dst, 1);
    src *= -1;
  }
  dst->bits[0] = src;
  return 0;
}