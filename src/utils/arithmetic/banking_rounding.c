#include "../../s21_decimal.h"

/////////////////////////////////////////////////////////////////////////////////
// Если число не влезает в мантису 96 бит, то необходимо выполнить банковское //
// округление: // param 1 -> big_dec подготовленной мантисой в 96 бит //
/////////////////////////////////////////////////////////////////////////////////

int banking_rounding(big_decimal *big_dec, big_decimal last_diget) {
  int err = 0;

  big_decimal five = init();
  five.bits[0] = 5;
  big_decimal one = init();
  one.bits[0] = 1;

  if (big_dec != NULL) {
    int equal_five = is_bitwise_equal_big(&last_diget, &five);
    int grater_five = is_bitwise_grater_big(&last_diget, &five);
    int parity = get_bit_big(big_dec, 0);  // 0 - четная мантиса или 1- нечетная
    if ((equal_five && parity) || grater_five)
      add_bitwise_big(*big_dec, one, big_dec);
  } else {
    err = 1;
  }

  return err;
}