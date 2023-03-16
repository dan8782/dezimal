#include "../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int flag = 0;
  int data = 0;
  int scale = get_exp(&src);
  for (int i = 1; i < 3; i++) {
    if (src.bits[i] != 0) {
      flag = 1;
    }
  }
  * / *dst = 0;

  // if (scale + 31 < 95) {
  //   for (int i = scale + 31; i <= 95; ++i) {
  //     if (get_bit(src, i)) {
  //       flag = 1;
  //     }
  //   }
  // }

  if (!flag) {
    for (int i = scale + 30; i >= scale; --i) {
      data <<= 1;
      data |= get_bit(src, i);
    }
    if (get_sign(&src)) {
      data = -data;
    }
    return 0;
  }
