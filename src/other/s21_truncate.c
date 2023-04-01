#include "../s21_decimal.h"

int s21_truncate(s21_decimal val, s21_decimal *result) {
  int err = 0;
  int exp = get_exp(&val);
  int sign = get_sign(&val);
  set_zero(result);

  if (exp == 0) {
    copy_decimal(result, val);
  } else if (exp > 0 && exp < 29) {
    s21_decimal scale = pow_10_decimal(exp);
    div_int_bitwise(val, scale, result);
    set_exp(result, 0);
    set_sign(result, sign);
  } else {
    err = 1;
  }

  return err;
}