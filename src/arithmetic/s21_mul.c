#include "../s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int err = OK;

  init_small(result);
  big_decimal big_1 = dec_to_big(value_1);
  big_decimal big_2 = dec_to_big(value_2);
  big_decimal temp_res = init();
  big_decimal val1Cpy = init();
  int res_sign = (big_1.sign != big_2.sign) ? 1 : 0;
  // умножение в cтолбиком start
  int j = 0;
  for (int i = 0; i < 192; i++) {
    val1Cpy = init();
    if (get_bit_big(&big_2, i)) {
      val1Cpy = big_1;
      j = 0;
      while (j < i) {
        if (left_shift_big(&val1Cpy)) {
          break;
        }
        j++;
      }
      err = add_bitwise_big(val1Cpy, temp_res, &temp_res);
    }
  }
  // умножение в cтолбико end
  int scale_exp = big_1.exp + big_2.exp;
  temp_res.exp = scale_exp;
  temp_res.sign = res_sign;
  // print_big_mantissa(&temp_res);
  if (!err)
    err = big_to_dec(temp_res, result);
  if (err && res_sign) {
    err = 2;
  }
  // print_dec(result);
  return err;
}