#include "../s21_decimal.h"
/////////////////////////////////////////////
// Если 96 битное число А < Б возвращает 1 //
/////////////////////////////////////////////
int is_bitwise_less(s21_decimal *a, s21_decimal *b) {
  int result = 0;
  int a_bit = 0;
  int b_bit = 0;
  for (int i = LAST_BIT - 1; i >= 0; i--) {
    a_bit = get_bit(*a, i);
    b_bit = get_bit(*b, i);
    if ((a != b) && (a < b)) {
      result = 1;
      break;
    }
  }
  return result;
}