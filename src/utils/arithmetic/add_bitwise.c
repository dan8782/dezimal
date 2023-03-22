#include "../../s21_decimal.h"

// def Bitwise_add(a,b):
//     while b != 0:
//         carry = a&b // Carry value is calculated
//         a = a^b // Sum value is calculated and stored in a
//         b = carry<<1 // The carry value is shifted towards left by a bit

//     return a // returns the final sum

int add_bitwise(s21_decimal x, s21_decimal y, s21_decimal *res) {
  s21_decimal carry = {0};

  if (is_zero(&y)) {
    copy_decimal(res, x);
  } else {
    while (!is_zero(&y)) {
      for (int i = 0; i < 3; i++) {
        carry.bits[i] = x.bits[i] & y.bits[i];
        x.bits[i] ^= y.bits[i];
      }

      left_shift(&carry);
      for (int i = 0; i < 3; i++) {
        y.bits[i] = carry.bits[i];
      }
    }
    for (int i = 0; i < 3; i++) {
      res->bits[i] = x.bits[i];
    }
  }
  return 0;
}