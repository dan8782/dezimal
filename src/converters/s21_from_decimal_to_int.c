#include "../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  if (get_exp(src)) {
    s21_truncate(src, &src);
  }

  if (src.bits[2] || src.bits[1] || src.bits[0] > 0x7fffffff) {
    return 1;
  } 
    *dst = src.bits[0] & 0x7fffffff;
    if (get_sign(src)) {
      *dst *= -1;
    }
  return 0;
}