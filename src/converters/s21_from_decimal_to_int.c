#include "../s21_decimal.h"

int s21_abs(int x);

int s21_from_decimal_to_int(s21_decimal src, int *dest) {
  int error = 0;
  int sign = get_sign(&src);
  if (src.bits[2] == 0 && src.bits[1] == 0 && (dest != NULL) &&
      (((src.bits[0] <= (unsigned int)INT_MAX) && (sign == 0)) ||
       ((src.bits[0] <= (unsigned int)s21_abs(INT_MIN)) && (sign == 1))) &&
      (get_exp(&src) < 29)) {
    *dest = 0;
    if (get_exp(&src) != 0) {
      s21_truncate(src, &src);
    }
    *dest = (sign == 1) ? -(int)src.bits[0] : (int)src.bits[0];
  } else {
    if (dest != NULL) {
      *dest = 0;
    }
    error = 1;
  }
  return error;
}

int s21_abs(int x) {
  if (x < 0) {
    x *= -1;
  }
  return x;
}