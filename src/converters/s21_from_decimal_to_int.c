#include "../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
 /*if (get_exp(src)) {
    s21_truncate(src, &src);
  }

*dst = 0;

  if (src.bits[2] || src.bits[1] || src.bits[0] > 0x7fffffff) {
    return 1;
  } 
    *dst = src.bits[0] & 0x7fffffff;
    if (get_sign(src)) {
      *dst *= -1;
    }
  return *dst;
}
*/
int dst2 = 0.0;

int return_val = 0;
  *dst = 0;

  int scale = get_exp(src);
  if (!dst) {
    return_val = 1;
  }

  for (int i = 0; i < LAST_BIT; i++) {
    if (get_bit(src, i)) {
      dst2 += pow(2, i);
    }
  }
  while (scale) {
    dst2 /= 10;
    scale--;
  }
  if (get_sign(src)) {
    dst2 = dst2 * (-1);
  }
  printf("%d\n", dst2);
  *dst = (int)dst2;
  return *dst;
}