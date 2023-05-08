#include "../s21_decimal.h"

s21_decimal *switch_bit(s21_decimal *decimal, int index) {
  decimal->bits[index / 32] ^= (1 << (index % 32)); // тут XOR
  return decimal;
}
