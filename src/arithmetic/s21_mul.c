#include "../s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = OK;
  s21_decimal val1Cpy;
  init_small(&val1Cpy);
  s21_decimal temp_res;
  init_small(&temp_res);
  int j = 0;
  for (int i = 0; i < 96; i++) {
    init_small(&val1Cpy);
    if (get_bit(value_2, i) == 1) {
      val1Cpy = value_1;
      j = 0;
      while (j < i) {
        if (left_shift(&val1Cpy)) {
          break;
        }
        j++;
      }
      res = add_bitwise(val1Cpy, temp_res, &temp_res);
    }
  }
  print_dec(&value_1);
  print_dec(&value_2);
  if (get_sign(&value_1) != get_sign(&value_2)) {
    if (res == 1) {
      res = 2;
    }
    set_sign(&temp_res, 1);
  } else {
    set_sign(&temp_res, 0);
  }
  if (get_exp(&value_1) + get_exp(&value_2) > 29) {
    set_exp(&temp_res, 29);
  } else {
    set_exp(&temp_res, get_exp(&value_1) + get_exp(&value_2));
  }
  if (res == OK) {
    init_small(result);
    *result = temp_res;
  }
  print_dec(result);
  return res;
}