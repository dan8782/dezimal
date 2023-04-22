#include "../s21_decimal.h"

int s21_is_not_equal(s21_decimal x, s21_decimal y) {
  return !s21_is_equal(x, y);
}