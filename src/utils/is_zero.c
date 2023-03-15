#include "../s21_decimal.h"

int is_zero(s21_decimal *val) {
  return !val->bits[0] && !val->bits[1] && !val->bits[2];
}
