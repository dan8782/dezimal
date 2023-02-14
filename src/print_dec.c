#include "s21_decimal.h"

void print_dec(s21_decimal decl) {
  for (int i = 127; i >= 0; i--) {
    printf("%d", get_bit(decl, i));
    if (i % 32 == 0) {
      printf(" ");
    }
  }
  printf("\n");
}