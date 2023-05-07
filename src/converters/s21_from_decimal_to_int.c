#include "../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int err = 0;
  if (dst != NULL) {
    err = 1;
  } else {
    if (get_exp(&src)) s21_truncate(src, &src);
    if (src.bits[1] != 0 || src.bits[2] != 0 || src.bits[0] > INT_MAX) {
      err = 1;
    } else {
      *dst = src.bits[0];
      if (src.bits[3] % 2) *dst *= -1;
    }
  }
  return err;
}
