#include "../s21_decimal.h"
#include <math.h>

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
    int return = 0;
    s21_set_null(dst);
    src = fabsf(src);

   
  if (src < 0) {
    set_sign(dst, 1);
    src *= -1;
  }
  dst->bits[0] = src;
  return 0;
}
