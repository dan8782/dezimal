#include "../s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int err = 1;
  if (result != NULL) {
    if (get_sign(&value_2)) {
      set_sign(&value_2, 0);
    } else {
      set_sign(&value_2, 1);
    }
    err = s21_add(value_1, value_2, result);
  }

  return err;
}