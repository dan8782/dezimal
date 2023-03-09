#include "s21_decimal.h"

int s21_get_scale(s21_decimal decl) {
  int scale = 0;
  for (int i = LAST_BIT + 23; i >= LAST_BIT + 16; i--) {
    scale <<= 1;
    scale |= get_bit(decl, i);
  }
  return scale;
}
