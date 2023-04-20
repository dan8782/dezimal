#include "../../s21_decimal.h"
// Установить знак числа децимал
void set_sign(s21_decimal *decl, bool sign) {
  if (decl != NULL) {
    if (sign) {
      decl->bits[3] |= (1 << 31);
    } else {
      decl->bits[3] &= ~(1 << 31);
    }
  }
}