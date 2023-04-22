#include "../s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int err = 0;
  if (result != NULL) {
    copy_decimal(result, value);
    switch_bit(result, 127);
  } else {
    err = 1;
  }
  return err;
}