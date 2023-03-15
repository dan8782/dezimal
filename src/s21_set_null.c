#include "s21_decimal.h"

void s21_set_null(s21_decimal *decl) {
  for (int i = 0; i < 128; ++i) {
    set_bit(decl, i, 0);
  }
}
