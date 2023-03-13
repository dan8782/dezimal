#include "s21_decimal.h"

int main(int argc, char const *argv[]) {
  s21_decimal decimal1 = {5, 0, 0, 0};
  s21_decimal decimal2 = {123, 0, 0, 0};
  s21_decimal result = {0};
  // s21_from_int_to_decimal(64,&decimal);
  // s21_add(decimal1,decimal2, &result);
  // set_exp(&decimal1,4);
  // printf("%d",get_exp(decimal1));
  // s21_mul(decimal1,decimal2,&result);
  sub_96bit(decimal1, decimal2, &result);
  print_dec(result);
  return 0;
}

// 100
// 100
//   1000