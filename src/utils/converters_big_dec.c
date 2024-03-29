#include "../s21_decimal.h"

// 7922816251426433759354395033[6] = 100...000
int is_too_large(big_decimal *big_dec) {
  return (!big_dec->bits[5] && !big_dec->bits[4] && big_dec->bits[3]);
}

int is_max_decimal(big_decimal *big_dec) {
  int res = 0;
  int last_3_bits = !big_dec->bits[5] && !big_dec->bits[4] && !big_dec->bits[3];
  int first_3_bits = big_dec->bits[2] == UINT_MAX &&
                     big_dec->bits[1] == UINT_MAX &&
                     big_dec->bits[0] == UINT_MAX;
  if (last_3_bits && first_3_bits)
    res = 1;
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

int big_to_dec(big_decimal big_dec, s21_decimal *s21_dec) {
  int err = OK;
  set_zero(s21_dec);
  int exp =
      big_dec.exp; // забираю степень и знак так как int_bitwise занулит их
  int sign = big_dec.sign;
  int is_s21_dec = 1;

  for (int i = 3; i < 6; i++) {
    if (big_dec.bits[i])
      is_s21_dec = 0;
  }
  //  Если биг децимал не влазит в обычный децимал:
  if (!is_s21_dec) {
    big_decimal ten = init();
    ten.bits[0] = 10;
    big_decimal last_diget = init();
    while (1) {
      mod_bitwise_big(big_dec, ten, &last_diget); // цифра за 96-м битом
      div_int_bitwise_big(big_dec, ten, &big_dec);
      exp -= 1;
      if (exp < 0) {
        exp = 0;
        err = 1;
        break;
      } else if (!big_dec.bits[5] && !big_dec.bits[4] && !big_dec.bits[3]) {
        err = banking_rounding(&big_dec, last_diget);
        break;
      }
    }
  }

  if (exp > 28) {
    while (exp-- > 28) {
      big_decimal ten = init();
      ten.bits[0] = 10;
      div_int_bitwise_big(big_dec, ten, &big_dec);
    }
    exp = 28;
  }
  //  завершено приведение BIG dec в обычный децимал
  for (int i = 0; i < 3; i++) {
    s21_dec->bits[i] = big_dec.bits[i];
  }

  set_exp(s21_dec, exp);
  set_sign(s21_dec, sign);

  return err;
}