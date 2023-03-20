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