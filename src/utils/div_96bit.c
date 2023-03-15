#include "../s21_decimal.h"

int div_96bit(s21_decimal x, s21_decimal y, s21_decimal *res) {
  int err = 0;
  if (is_zero(&y)) err = 3;  // devizion by zero

  s21_decimal buff_y = {0, 0, 0, 0};
  print_dec(buff_y);

  for (int i = LAST_BIT - 1; i >= 0; i--) {
    s21_copy(&buff_y, y);
    for (int j = 1; j < i - 1; j++) {
      left_shift(&buff_y);  // y multiplied by 2 to the power i
    }

    if (s21_is_less_or_equal(
            buff_y, x)) {  // checking if y multiplied by 2 * *i is <= x
      printf("i = %d\n", i);
      sub_96bit(x, buff_y, &x);  // subtracting y << i from x

      s21_decimal one = {1, 0, 0, 0};  // сбрасываем изменненный one
      for (int k = 1; k < i - 1; k++) {
        left_shift(&one);  // 1 << i;  2 power i
      }
      print_dec(one);
      Bitwise_add(*res, one, res);  // adding 2 power i to the answer
      print_dec(*res);
    }
  }

  return 0;
}