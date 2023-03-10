#include "../s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int return_val = 0;
  *dst = 0.0;

  int scale = get_exp(src);
  for (int i = 0; i < LAST_BIT; i++) {
    if (get_bit(src, i)) {
      *dst += pow(2, i);
    }
  }
  while (scale) {
    *dst /= 10;
    scale--;
  }
  if (get_sign(src)) {
    *dst = *dst * (-1);
  }
  return return_val;
}
