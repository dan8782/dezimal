#include "../s21_decimal.h"

void set_zero(s21_decimal *decl) {
  for (int i = 0; i < 128; ++i) {
    set_bit(decl, i, 0);
  }
}