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
    *dst = data;
  }
  return flag;
}

// int s21_from_decimal_to_int(s21_decimal src, int *dst) {
//   int result = 1;
//   s21_decimal max_dec = {{2147483647, 0, 0, 0}};
//   s21_decimal min_dec = {{2147483648, 0, 0, 0}};
//   set_sign(&min_dec, 1);
//   if (1) {
//     *dst = src.bits[0];
//     *dst *= get_sign(src) ? -1 : 1;
//     *dst = *dst / (int)pow(10.0, (double)get_exp(src));
//     result = 0;
//   }
//   return result;
// }