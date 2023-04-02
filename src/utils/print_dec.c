#include "../s21_decimal.h"

void print_dec(s21_decimal *dec) {
  switch (dec->status) {
    case DIVISION_BY_ZERO:
      printf("%s\n", StatusName[DIVISION_BY_ZERO]);
      break;
    case PLUS_INFINITY:
      printf("%s\n", StatusName[PLUS_INFINITY]);
      break;
    case MINUS_INFINITY:
      printf("%s\n", StatusName[MINUS_INFINITY]);
      break;
    default:
      for (int i = 127; i >= 0; i--) {
        printf("%d", get_bit(*dec, i));
        if (i % 32 == 0) {
          printf("|");
        }
      }
      printf("\n");
  }
}

void print_big_mantissa(big_decimal *dec) {
  for (int i = 191; i >= 0; i--) {
    printf("%d", get_bit_big(dec, i));
    if (i % 32 == 0) {
      printf("|");
    }
  }
  printf("\n");
}