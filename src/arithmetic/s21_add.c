#include "../s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int err = OK;
  set_zero(result);
  big_decimal big_1 = dec_to_big(value_1);
  big_decimal big_2 = dec_to_big(value_2);
  big_decimal big_res = init();

  if (big_1.exp != big_2.exp) {
    normalize_big(&big_1, &big_2);
  }
  // print_big_mantissa(&big_1);
  // print_big_mantissa(&big_2);
  int minus_minus = big_1.sign && big_2.sign;
  int plus_plus = !big_1.sign && !big_2.sign;

  if (minus_minus || plus_plus) {  // случай - - и + +
    err = add_bitwise_big(big_1, big_2, &big_res);
    big_res.sign = minus_minus ? 1 : 0;
  } else {                                          // случай - + и + -
    err = sub_bitwise_big(big_1, big_2, &big_res);  // вычитание по модулю
    if (is_zero_big(&big_res)) {
      big_res.sign = 0;
    } else {
      int grate = is_bitwise_grater_big(&big_1, &big_2);
      // min - max  = -res || -max + min = -res
      big_res.sign = ((grate && !big_2.sign) || (!grate && big_2.sign)) ? 1 : 0;
    }
  }

  big_res.exp = big_1.exp;  // big_1.exp == big_2.exp после нормализации
  err = big_to_dec(big_res, result);

  if (err && big_res.sign) err = MINUS_INFINITY;
  // printf("ERROR = %d\n", err);
  return err;
}