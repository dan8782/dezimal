#include "../s21_decimal.h"

// 7922816251426433759354395033[6] = 100...000
int is_too_large(big_decimal *big_dec) {
  return (!big_dec->bits[5] && !big_dec->bits[4] && big_dec->bits[3] == 1);
}

int is_max_decimal(big_decimal *big_dec) {
  int res = 0;
  int last_3_bits = !big_dec->bits[5] && !big_dec->bits[4] && !big_dec->bits[3];
  int first_3_bits = big_dec->bits[2] == -1 && big_dec->bits[1] == -1 &&
                     big_dec->bits[0] == -1;
  if (last_3_bits && first_3_bits) res = 1;
  return res;
}

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
      mod_bitwise_big(big_dec, ten, &last_diget);  // цифра за 96-м битом
      printf("MOD:\n");
      print_big_mantissa(&last_diget);
      div_int_bitwise_big(big_dec, ten, &big_dec);
      printf("DIV by 10:\n");
      print_big_mantissa(&big_dec);
      if (is_too_large(&big_dec) || is_max_decimal(&big_dec)) {
        if (sign)
          err = MINUS_INFINITY;
        else
          err = PLUS_INFINITY;
        for (int i = 0; i < 3; big_dec.bits[i] = -1,
                 i++)  // заполняем мантису еденицами, но это не обязательно
          ;
        break;
      }
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