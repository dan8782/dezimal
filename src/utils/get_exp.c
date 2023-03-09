#include "../s21_decimal.h"

int get_exp(s21_decimal x) {
  int exp = 0;
  for (int i = 112; i <= 119; i++) {
    exp += get_bit(x, i) * pow(2, i - 112);
  }
  return exp;
}

// int get_exp(s21_decimal decl) {
//   int scale = 0;
//   for (int i = 112; i <= 119; i++) {
//     scale <<= 1;
//     scale |= get_bit(decl, i);
//   }
//   return scale;
// }
