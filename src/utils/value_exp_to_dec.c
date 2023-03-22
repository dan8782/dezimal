#include "../s21_decimal.h"
////////////////////////////////////////////////////////
// Возвращает децимал со значением от 10^0 до 10^28   //
////////////////////////////////////////////////////////

int value_exp_to_decimal(s21_decimal *res, int n) {
  s21_decimal ten = {10, 0, 0, 0};
  s21_decimal buffer = {0, 0, 0, 0};
  set_zero(res);
  int i = 0;
  while (i < pow(10, n - 2)) {
    for (int k = 0; k < 10; k++, add_bitwise(*res, ten, res))
      ;
    i++;
    print_dec(res);
  }

  return 0;
}
// 10 * 10 = 10 + 10 + 10 + 10 10 ^ 2 = (10 + 10 + 10 + 10..+ 10) N =
//               10 10 ^ 3 = (10 + 10 + 10 + 10..+ 10) N = 10