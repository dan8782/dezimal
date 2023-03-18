#include "../../s21_decimal.h"

// Сравниваем побитово мантиссу
int is_mantissa_less(s21_decimal x, s21_decimal y, int sign) {
  int i = LAST_MANTISSA_BIT;
  while (i >= 0) {
    int x_bit = get_bit(x, i);
    int y_bit = get_bit(y, i);
    if (x_bit > y_bit) {
      return (sign == 0) ? 0 : 1;
    } else if (x_bit < y_bit) {
      return (sign == 0) ? 1 : 0;
    }
    i--;
  }
  return 0;
}