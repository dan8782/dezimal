#include <math.h>

#include "../s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  set_zero(dst);
  src = fabsf(src);

  if (src < 0) {
    set_sign(dst, 1);
    src *= -1;
  }
  dst->bits[0] = src;
  return 0;
}
