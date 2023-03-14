#include "../s21_decimal.h"

int div_96bit(s21_decimal x, s21_decimal y, s21_decimal *res) {
  s21_decimal one = {1, 0, 0, 0};
  s21_decimal buff_y = {0};
  s21_copy(&buff_y, y);

  for (int i = LAST_BIT - 1; i >= 0; i--) {
    for (int j = 0; j <= i; j++) {
      left_shift(&buff_y);  // y multiplied by 2 to the power i
    }
    if (s21_is_less_or_equal(
            buff_y, x)) {        // checking if y multiplied by 2 * *i is <= x
      sub_96bit(x, buff_y, &x);  // subtracting y << i from x
      for (int k = 0; k <= i; k++) {
        left_shift(&one);  // 1 << i;  2 power i
      }
      Bitwise_add(*res, one, res);  // adding 2 power i to the answer
    } else {
      s21_copy(&buff_y, y);
    }
  }

  return 0;
}
