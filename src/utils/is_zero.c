#include "../s21_decimal.h"

int is_zero(s21_decimal *val) {
  return !val->bits[0] && !val->bits[1] && !val->bits[2];
}

int is_zero_big(big_decimal *val) {
  int res = 1;

  for (int i = 0; i < 6; i++) {
    if (val->bits[i]) res = 0;
  }

  return res;
}
