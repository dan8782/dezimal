#include "s21_decimal.h"

int main(int argc, char const *argv[]) {
  s21_decimal decimal1 = {75656, 0, 0, 0};
  set_exp(&decimal1, 4);
  set_sign(&decimal1, 1);
  s21_decimal decimal2 = {-1, -1, -1, 0};
  s21_decimal result = {0};
  // s21_decimal result2 = {0};
  //  s21_from_int_to_decimal(64,&decimal);
  //  s21_add(decimal1,decimal2, &result);
  //  set_exp(&decimal1,4);
  //  printf("%d",get_exp(&decimal1));
  //  s21_mul(decimal1,decimal2,&result);
  //  sub_96bit(decimal1, decimal2, &result);
  printf("Start...\n");
  // div_int_bitwise(decimal1, decimal2, &result);
  // s21_truncate(decimal1, &result);
  // add_bitwise(decimal1, decimal2, &result);
  // s21_truncate(decimal1, &result);
  // add_bitwise(decimal1, decimal2, &result);
  //   for (int i = 0; i < 29; i++) {
  //     printf(" i = %d\n", i);
  //     result = pow_10_decimal(i);
  //     print_dec(&result);
  //   }
  // s21_round(decimal1, &result);
  s21_floor(decimal1, &result);

  print_dec(&decimal1);
  // print_dec(&decimal2);
  print_dec(&result);

  // BIG DEC
  printf("BIG ADD...\n");
  big_decimal big_dec1 = init();
  big_decimal big_dec2 = init();
  big_decimal res = init();

  big_dec1.bits[0] = 1;
  // for (int i = 0; i < 4; big_dec2.bits[i] = -1, i++);
  big_dec2.bits[0] = 2;

  print_big_mantissa(&big_dec1);
  print_big_mantissa(&big_dec2);

  add_bitwise_big(big_dec1, big_dec2, &res);
  mul_by_10_big(&res);  // проверяй

  print_big_mantissa(&res);

  return 0;
}