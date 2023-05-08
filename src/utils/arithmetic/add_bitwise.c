#include "../../s21_decimal.h"

// def Bitwise_add(a,b):
//     while b != 0:
//         carry = a&b // Carry value is calculated
//         a = a^b // Sum value is calculated and stored in a
//         b = carry<<1 // The carry value is shifted towards left by a bit

//     return a // returns the final sum

int add_bitwise(s21_decimal x, s21_decimal y, s21_decimal *res) {
  int err = 0;
  s21_decimal carry = {0};

  if (is_zero(&y)) {
    copy_decimal(res, x);
  } else {
    while (!is_zero(&y)) {
      for (int i = 0; i < 3; i++) {
        carry.bits[i] = x.bits[i] & y.bits[i];
        x.bits[i] ^= y.bits[i];
      }

      if (left_shift(&carry))
        err = 1;
      for (int i = 0; i < 3; i++) {
        y.bits[i] = carry.bits[i];
      }
    }
    for (int i = 0; i < 3; i++) {
      res->bits[i] = x.bits[i];
    }
  }
  return err;
}

int add_bitwise_big(big_decimal x, big_decimal y, big_decimal *res) {
  int err = 0;
  big_decimal carry = init();
  *res = init();

  if (is_zero_big(&y)) {
    copy_decimal_big(res, x);
  } else {
    while (!is_zero_big(&y)) {
      for (int i = 0; i < 6; i++) {
        carry.bits[i] = x.bits[i] & y.bits[i];
        x.bits[i] ^= y.bits[i];
      }

      if (left_shift_big(&carry))
        err = 1;
      for (int i = 0; i < 6; i++) {
        y.bits[i] = carry.bits[i];
      }
    }
    for (int i = 0; i < 6; i++) {
      res->bits[i] = x.bits[i];
    }
  }
  return err;
}