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
    big_decimal val_big = dec_to_big(val);
    big_decimal scale_big = dec_to_big(scale);
    big_decimal big_res = init();
    div_int_bitwise_big(val_big, scale_big, &big_res);
    // div_int_bitwise(val, scale, result);
    // set_exp(result, 0);
    // set_sign(result, sign);
    big_res.exp = 0;
    big_res.sign = sign;
    err = big_to_dec(big_res, result);
  } else {
    err = 1;
  }
  return err;
}