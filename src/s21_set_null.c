#include "s21_decimal.h"

void s21_set_null(s21_decimal *x) {
  for (int i = 0; i < 128; ++i) {
    set_bit(x, i, 0);
  }
}
