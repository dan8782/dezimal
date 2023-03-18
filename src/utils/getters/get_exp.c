#include "../../s21_decimal.h"

int get_exp(s21_decimal *x) {
  int exp = 0;
  for (int i = START_EXP_BIT; i <= LAST_EXP_BIT; i++) {
    exp += get_bit(*x, i) * pow(2, i - START_EXP_BIT);
  }
  return exp;
}
