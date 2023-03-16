#include "../s21_decimal.h"
/////////////////////////////////////////////
// Если 96 битное число А < Б возвращает 1 //
/////////////////////////////////////////////
int is_bitwise_less(s21_decimal *a, s21_decimal *b) {
  int result = 0;
  for (char i = LAST_BIT - 1; i >= 0; i--) {
    if (get_bit(*a, i) < get_bit(*b, i)) {
      result = 1;
      break;
    }
  }
  return result;
}