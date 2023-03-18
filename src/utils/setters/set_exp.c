#include "../../s21_decimal.h"

void set_exp(s21_decimal *decimal, int exp) {
  for (int i = 112; i < 120; i++) {
    set_bit(decimal, i, exp & 1);
    exp >>= 1;
  }
}