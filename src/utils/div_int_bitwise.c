#include "../s21_decimal.h"
////////////////////////////////////////////////////////
// Делит два 96 битных числа и возвращает целую часть //
////////////////////////////////////////////////////////
int div_int_bitwise(s21_decimal x, s21_decimal y, s21_decimal *res) {
  int err = OK;
  int less = is_bitwise_less(&x, &y);  // if |x| < |a| return 0

  if (is_zero(&y)) {
    err = DIVISION_BY_ZERO;
    res->status = DIVISION_BY_ZERO;
  } else if (less) {
    set_zero(res);  // целая часть 0
  } else {
    s21_decimal buff_y = {0, 0, 0, 0};

    for (int i = LAST_BIT - 1; i >= 0; i--) {
      copy_decimal(&buff_y, y);
      for (int j = 1; j < i - 1; j++) {
        left_shift(&buff_y);  // y multiplied by 2 to the power i
      }

      if (s21_is_less_or_equal(
              buff_y, x)) {  // checking if y multiplied by 2 * *i is <= x
        sub_bitwise(x, buff_y, &x);  // subtracting y << i from x

        s21_decimal one = {1, 0, 0, 0};  // сбрасываем изменненный one
        for (int k = 1; k < i - 1; k++) {
          left_shift(&one);  // 1 << i;  2 power i
        }
        add_bitwise(*res, one, res);  // adding 2 power i to the answer
      }
    }
  }

  return err;
}