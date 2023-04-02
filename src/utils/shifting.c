#include "../s21_decimal.h"
////////////////////////////////////////////////
// Смещает на один бит влево 96 битовое число //
////////////////////////////////////////////////
int left_shift(s21_decimal *decimal) {
  int err = 0;
  int last_bit[2] = {0};
  if (get_bit(*decimal, LAST_BIT - 1)) {
    err = 1;
  } else {
    last_bit[0] = get_bit(*decimal, MID_BIT - 1);
    last_bit[1] = get_bit(*decimal, HIGH_BIT - 1);
    for (int i = 0; i < 3; i++) {
      decimal->bits[i] <<= 1;
    }
    set_bit(decimal, MID_BIT, last_bit[0]);
    set_bit(decimal, HIGH_BIT, last_bit[1]);
  }
  return err;
}

int right_shift(s21_decimal *decimal) {
  int err = 0;
  int last_bit[2] = {0};
  last_bit[0] = get_bit(*decimal, MID_BIT);
  last_bit[1] = get_bit(*decimal, HIGH_BIT);
  for (int i = 0; i < 3; i++) {
    decimal->bits[i] >>= 1;
  }
  set_bit(decimal, MID_BIT - 1, last_bit[0]);
  set_bit(decimal, HIGH_BIT - 1, last_bit[1]);

  return err;
}

int left_shift_big(big_decimal *decimal_big) {
  int err = 0;

  int last_bit[5] = {0};
  err = get_bit_big(decimal_big, 191);

  if (!err) {
    int last_bit_int = 31;
    for (int i = 0; i < 5; i++) {
      last_bit[i] = get_bit_big(decimal_big, last_bit_int);
      last_bit_int += 32;
    }

    for (int i = 0; i < 6; i++) {
      decimal_big->bits[i] <<= 1;
    }

    int bit = 0;
    for (int i = 0; i < 5; i++) {
      set_bit_big(decimal_big, bit += MID_BIT, last_bit[i]);
    }
  }
  return err;
}