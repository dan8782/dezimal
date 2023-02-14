#include "s21_decimal.h"
//Установить знак числа децимал
void set_sign(s21_decimal *decl, bool sign) {
  set_bit(decl, 127, sign);
}