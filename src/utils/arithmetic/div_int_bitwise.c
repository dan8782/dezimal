#include "../../s21_decimal.h"
////////////////////////////////////////////////////////
// Делит два 96 битных числа и возвращает целую часть //
// Знаки и степня входящих децималов не учитываются   //
// Сравнения чисел только по мантиссе                 //
////////////////////////////////////////////////////////
int div_int_bitwise(s21_decimal x, s21_decimal y, s21_decimal *res) {
  int err = OK;
  int less = is_bitwise_less(&x, &y);  // if |x| < |a| return 1

  if (is_zero(&y)) {
    err = DIVISION_BY_ZERO;
    res->status = DIVISION_BY_ZERO;
  } else if (less) {
    set_zero(res);  // целая часть 0
  } else {
    s21_decimal buff_y = {0, 0, 0, 0};

    for (int i = LAST_BIT - 1; i >= 0; i--) {
      // printf("i = %d\n", i);
      copy_decimal(&buff_y, y);

      for (int j = 0; j < i; j++) {
        if (left_shift(&buff_y)) {  // y * 2^i
          break;
        }  // переполнение
        // left_shift(&buff_y);
      }
      if (is_bitwise_less_or_equal(&buff_y, &x)) {  // checking if: y * 2^i <= x
        sub_bitwise(x, buff_y, &x);                 // subtracting y << i from x
        // print_dec(&x);
        s21_decimal one = {1, 0, 0, 0};  // сбрасываем изменненный one
        for (int k = 0; k < i; k++, left_shift(&one))
          ;  // 1 << i;  2^i

        add_bitwise(*res, one, res);  // adding 2^i to the answer
      }
    }
  }

  return err;
}