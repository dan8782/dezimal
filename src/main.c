#include "s21_decimal.h"

int main(int argc, char const *argv[]) {
  // printf("START...\n");
  // s21_decimal val1 = {-1, -1, -1, 0};
  // set_exp(&val1, 2);
  // // print_dec(&val1);
  // s21_decimal val2 = {1, 0, 0, 0};
  // set_exp(&val2, 10);
  // set_sign(&val2, 1);
  // s21_decimal result = {0};

  // s21_add(val1, val2, &result);
  // print_dec(&result);
  // printf("%d", get_exp(&result));
  // big_decimal dec1 = init();
  // dec1.bits[5]=-1;
  // for (int i = 0; i < 33; i++)
  // {
  //   right_shift_big(&dec1);
  // }
  
  // print_big_mantissa(&dec1);
  s21_decimal decimal1 = {55, 0, 0, 0};
  s21_decimal decimal2 = {56, 0, 0, 0};
  s21_decimal decimalr = {0,0,0,0};
  print_dec(&decimal1);
  print_dec(&decimal2);
  s21_mul(decimal1,decimal2,&decimalr);
  print_dec(&decimalr);
  return 0;
}