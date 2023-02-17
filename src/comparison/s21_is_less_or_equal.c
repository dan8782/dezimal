#include "../s21_decimal.h"

int s21_is_less_or_equal(s21_decimal x, s21_decimal y) {
  return !s21_is_greater(x, y);
}