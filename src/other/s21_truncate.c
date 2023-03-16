#include "../s21_decimal.h"

int s21_truncate(s21_decimal val, s21_decimal *result) {
  int err = 0;
  int exp = get_exp(&val);
  int sign = get_sign(&val);

  if (exp == 0) {
    copy_decimal(result, val);
  }
  if (exp > 0 && exp < 29) {
    s21_decimal del = {pow(10, exp), 0, 0, 0};
    // set_exp(&val, 0); // не работает
    val.bits[3] = 0;
    div_int_bitwise(val, del, result);
    set_sign(result, sign);
  } else {
    err = 1;
  }

  return err;
}