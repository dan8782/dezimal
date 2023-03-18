#include "../../s21_decimal.h"
/////////////////////////////////////////////
// Если 96 битное число А <= Б возвращает 1 //
/////////////////////////////////////////////
int is_bitwise_less_or_equal(s21_decimal *a, s21_decimal *b) {
  int result = 0;
  int a_bit = 0;
  int b_bit = 0;
  for (int i = LAST_BIT - 1; i >= 0; i--) {
    a_bit = get_bit(*a, i);
    b_bit = get_bit(*b, i);
    if (a_bit < b_bit) {
      result = 1;
      break;
    } else if (a_bit > b_bit){
      result = 0;
      break;
    }
    result = 1;
  }
  return result;
}