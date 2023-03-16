#include "../s21_decimal.h"

void copy_decimal(s21_decimal *decimal, s21_decimal origdec) {
  for (int i = 0; i < 4; ++i) {
    decimal->bits[i] = origdec.bits[i];
  }
}