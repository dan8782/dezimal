#include "s21_decimal.h"

int main(int argc, char const *argv[]) {
  printf("START...\n");
  s21_decimal val1 = {-1, -1, -1, 0};  // 7922816251426433759354395033(5)
  set_exp(&val1, 0);
  set_sign(&val1, 1);
  // print_dec(&val1);
  s21_decimal val2 = {5, 0, 0, 0};  // 0.5
  set_exp(&val2, 1);
  set_sign(&val2, 1);
  s21_decimal result = {0};

  int err = s21_add(val1, val2, &result);
  printf("ERROR: %d\n", err);
  print_dec(&result);
  return 0;
}