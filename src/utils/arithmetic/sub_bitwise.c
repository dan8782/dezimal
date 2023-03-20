#include "../../s21_decimal.h"

int sub_bitwise(s21_decimal x, s21_decimal y, s21_decimal *res) {
  s21_decimal borrow = {0};

  s21_decimal max = x;
  s21_decimal min = y;

  if (is_bitwise_grater(&y, &x)) {
    max = y;
    min = x;
  }
  if (is_zero(&min)) {
    copy_decimal(res, max);
  } else {
    while (!is_zero(&min)) {
      for (int i = 0; i < 3; i++) {
        borrow.bits[i] = ~max.bits[i] & min.bits[i];  // int borrow = (~x) & y;
        max.bits[i] ^= min.bits[i];                   // x = x ^ y;
      }
      // y = borrow << 1;
      left_shift(&borrow);
      for (int i = 0; i < 3; i++) {
        min.bits[i] = borrow.bits[i];
        res->bits[i] = max.bits[i];
      }
    }
  }
  return 0;
}