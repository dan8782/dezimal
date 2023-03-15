#include "../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  if (get_exp(src)) {
    s21_truncate(src, &src);
  }

  if (src.bits[1] != 0 || src.bits[2] != 0 || src.bits[0] > 0x80000000) {
    return 1;
  } else {
    *dst = src.bits[0];
    if (get_sign(src)) {
      *dst *= -1;
    }
  }
  return 0;
}
