#include "s21_decimal.h"

int main(int argc, char const *argv[]) {
  printf("START...\n");
  s21_decimal val1 = {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF,
                      0x00000000};  // 79228162514264337593543950334
  s21_decimal val2 = {1, 0, 0, 0};
  s21_decimal result = {0};
  div_int_bitwise(val1, val2, &result);
  print_dec(&result);

  return 0;
}