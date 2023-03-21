#include "../../s21_decimal.h"
////////////////////////////////////////////////////////
// Возвращает децимал со значением от 10^0 до 10^28   //
////////////////////////////////////////////////////////

s21_decimal mul_by_10(s21_decimal *dec) {
  // return decimal = dec_10 * 10
  s21_decimal buff_x = {0};
  s21_decimal buff_y = {0};
  s21_decimal res = {0};
  copy_decimal(&buff_x, *dec);
  copy_decimal(&buff_y, *dec);
  for (int j = 0; j < 3; j++, left_shift(&buff_x))
    ;
  left_shift(&buff_y);
  add_bitwise(buff_x, buff_y, &res);

  return res;
}

s21_decimal pow_10_decimal(int n) {
  int i = 0;
  s21_decimal res = {10, 0, 0, 0};
  if (n == 0) {
    res.bits[0] = 1;
  } else if (n > 0 && n < 29) {
    while (i < n) {
      res = mul_by_10(&res);
      i++;
    }
  }
  return res;
}