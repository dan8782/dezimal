#include "../s21_decimal.h"

// Сравнение X == Y
int s21_is_equal(s21_decimal x, s21_decimal y) {
  for (int i = 0; i < 4; i++) {
    if (x.bits[i] != y.bits[i]) {
      return 0;
    }
  }
  return 1;
}