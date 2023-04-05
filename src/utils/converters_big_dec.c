#include "../s21_decimal.h"

big_decimal dec_to_big(s21_decimal dec) {
  big_decimal big_dec;
  set_zero_big(&big_dec);

  for (int i = 0; i < 3; i++) {
    big_dec.bits[i] = dec.bits[i];
  }
  big_dec.exp = get_exp(&dec);
  big_dec.sign = get_sign(&dec);

  return big_dec;
}

// PLUS_INFINITY ??? надо разобрать
// MINUS_INFINITY ??? надо разобрать
int big_to_dec(big_decimal big_dec, s21_decimal *s21_dec) {
  int err = OK;
  set_zero(s21_dec);
  int exp =
      big_dec.exp;  // забираю степень и знак так как int_bitwise занулит их
  int sign = big_dec.sign;
  int is_s21_dec = 1;

  for (int i = 3; i < 6; i++) {
    if (big_dec.bits[i]) is_s21_dec = 0;
  }
  //  Если биг децимал не влазит в обычный децимал:
  if (!is_s21_dec) {
    big_decimal ten = init();
    ten.bits[0] = 10;
    big_decimal last_diget = init();
    while (1) {
      mod_bitwise_big(
          big_dec, ten,
          &last_diget);  // последняя цифра за мантисой 96-и битного числа
      div_int_bitwise_big(big_dec, ten, &big_dec);
      if (!big_dec.bits[5] && !big_dec.bits[4] && !big_dec.bits[3]) {
        banking_rounding(&big_dec, last_diget);
        break;
      }
    }
  }
  //  завершено приведение BIG dec в обычный децимал
  for (int i = 0; i < 3; i++) {
    s21_dec->bits[i] = big_dec.bits[i];
  }
  set_exp(s21_dec, exp);
  set_sign(s21_dec, sign);

  return err;
}