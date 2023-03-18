#include "s21_decimal.h"

int main(int argc, char const *argv[]) {
  s21_decimal decimal1 = {78900, 0, 0, 0};
  // set_exp(&decimal1, 5);
  s21_decimal decimal2 = {10005, 0, 0, 0};
  s21_decimal result = {0};
  // s21_from_int_to_decimal(64,&decimal);
  // s21_add(decimal1,decimal2, &result);
  // set_exp(&decimal1,4);
  // printf("%d",get_exp(&decimal1));
  // s21_mul(decimal1,decimal2,&result);
  // sub_96bit(decimal1, decimal2, &result);
  printf("Start...\n");
  div_int_bitwise(decimal1, decimal2, &result);
  // s21_truncate(decimal1, &result);
  print_dec(&decimal1);
  print_dec(&decimal2);
  print_dec(&result);

  return 0;
}