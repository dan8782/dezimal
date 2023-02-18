#include "s21_decimal.h"

int get_exp(s21_decimal decl) {
  int scale = 0;
  for (int i = 119; i >= 112; i--) {
    scale <<= 1;
    scale |= get_bit(decl, i);
  }
  return scale;
}

