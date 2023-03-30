#include "../../s21_decimal.h"

int mod_bitwise(s21_decimal x, s21_decimal y, s21_decimal *mod) {
  int err = OK;
  int less = is_bitwise_less(&x, &y);  // if |x| < |a| return 1
  set_zero(mod);

  if (is_zero(&y)) {
    err = DIVISION_BY_ZERO;
    mod->status = DIVISION_BY_ZERO;
  } else if (less) {
    copy_decimal(mod, x);  // целая часть 0 остаток равен делимому
  } else {
    s21_decimal buff_y = {0, 0, 0, 0};

    for (int i = LAST_BIT - 1; i >= 0; i--) {
      copy_decimal(&buff_y, y);

      for (int j = 0; j < i; j++) {
        if (left_shift(&buff_y)) break;
      }
      if (is_bitwise_less_or_equal(&buff_y, &x)) {  // checking if: y * 2^i <= x
        sub_bitwise(x, buff_y, &x);                 // subtracting y << i from x
      }
    }
    copy_decimal(mod, x);
  }

  return err;
}