#include "s21_decimal.h"

int left_shift(s21_decimal *decimal) {
  int last_bit[2] = {0};
  if (get_bit(*decimal, 95)) {
    return 1;
  }
  last_bit[0] = get_bit(*decimal, 31);
  last_bit[1] = get_bit(*decimal, 63);
  for (int i = 0; i < 3; i++) {
    decimal->bits[i] <<= 1;
  }
  set_bit(decimal, 32, last_bit[0]);
  set_bit(decimal, 64, last_bit[1]);
  return 0;
}