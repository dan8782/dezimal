#include "../../s21_decimal.h"

int add_bitwise(s21_decimal value_a, s21_decimal value_b, s21_decimal *result) {
  int temp_bit = result->bits[3];
  int buffer = 0;
  int bit_a = 0;
  int bit_b = 0;
  s21_decimal bufferd;
  set_zero(&bufferd);
  for (int i = 0; i < 96; i++) {
    bit_a = get_bit(value_a, i);
    bit_b = get_bit(value_b, i);
    buffer = bit_a & bit_b;
    set_bit(&bufferd, i, bit_a & bit_b);
    set_bit(result, i, bit_a ^ bit_b);
    if (buffer != 0) {
      left_shift(&bufferd);
      value_b = bufferd;
    }
  }
  return buffer;
}