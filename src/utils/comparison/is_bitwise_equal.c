#include "../../s21_decimal.h"
/////////////////////////////////////////////
// Если 96 битное число А == Б возвращает 1 //
/////////////////////////////////////////////

int is_bitwise_equal(s21_decimal *x, s21_decimal *y) {
  int res = 1;
  for (int i = 0; i < 4; i++) {
    if (x->bits[i] != y->bits[i]) {
      res = 0;
      break;
    }
  }
  return res;
}

int is_bitwise_equal_big(big_decimal *x, big_decimal *y) {
  int res = 1;
  for (int i = 0; i < 6; i++) {
    if (x->bits[i] != y->bits[i]) {
      res = 0;
      break;
    }
  }
  return res;
}