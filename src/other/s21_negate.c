#include "../s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  copy_decimal(result, value);
  switch_bit(result, 127);

  return 0;
}