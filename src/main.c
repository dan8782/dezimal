#include "s21_decimal.h"

int main(int argc, char const *argv[]) {
  printf("START...\n");
  s21_decimal val1 = {-1, -1, -1, 0};
  set_exp(&val1, 2);
  // print_dec(&val1);
  s21_decimal val2 = {1, 0, 0, 0};
  set_exp(&val2, 10);
  set_sign(&val2, 1);
  s21_decimal result = {0};

  s21_add(val1, val2, &result);
  print_dec(&result);
  printf("%d", get_exp(&result));
  return 0;
}