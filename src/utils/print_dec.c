#include "../s21_decimal.h"

void print_dec(s21_decimal *dec) {
  for (int i = 127; i >= 0; i--) {
    printf("%d", get_bit(*dec, i));
    if (i % 32 == 0) {
      printf("|");
    }
  }
  printf("\n");
}

void print_big_mantissa(big_decimal *dec) {
  printf("Mantissa:\n");
  for (int i = 191; i >= 0; i--) {
    printf("%d", get_bit_big(dec, i));
    if (i % 32 == 0) {
      printf("|");
    }
  }
  printf("\n");
  printf("Sign:\n");
  printf("%d\n", dec->sign);
  printf("Exp:\n");
  printf("%d\n", dec->exp);
}