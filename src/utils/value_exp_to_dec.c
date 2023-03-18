#include "../s21_decimal.h"
////////////////////////////////////////////////////////
// Возвращает децимал со значением от 10^0 до 10^28   //
////////////////////////////////////////////////////////

int value_exp_to_decimal(s21_decimal *res, int n) {
  s21_decimal ten = {10, 0, 0, 0};
  s21_decimal buffer = {0, 0, 0, 0};
  set_zero(res);
  char i = 0;
  while ( i < n * 10) {
    printf("%d\n", i);
    add_bitwise(*res, ten, res);
    i++;
    print_dec(res);
  }
   
return 0;
}