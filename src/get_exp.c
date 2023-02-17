#include "s21_decimal.h"

// Получаем степень  112 - старший бит, 119 - младший
int get_exp(s21_decimal x) {
  int exp = 0;
  for (int i = LAST_EXP_BIT; i >= START_EXP_BIT; i--) {
    exp += get_bit(x, i) * pow(2, LAST_EXP_BIT-i);
   // printf("i = %d, exp_2 = %d\n", i, LAST_EXP_BIT-i);
  }
  return exp;
}