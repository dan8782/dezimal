#include "../s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int err = 0;
  int scale_less_zero = 0;
  int scale_exp = 0;
  // int dig_befor_point = 0;
  int exp = 0;
  set_zero(result);
  if (is_zero(&value_2)) {
    err = DIVISION_BY_ZERO;
  } else if (!is_zero(&value_1)) {
    // иницилизация переменных
    big_decimal big_1 = dec_to_big(value_1);
    big_decimal big_2 = dec_to_big(value_2);
    big_decimal big_res = init();

    int res_sign = (big_1.sign != big_2.sign) ? 1 : 0;
    // нормализация если степени разные
    if (big_1.exp != big_2.exp) {
      normalize_big(&big_1, &big_2);
    }
    if (is_bitwise_equal_big(&big_1, &big_2)) {
      big_res.bits[0] = 1;
    } else {
      // если value_1 < value_2
      if (is_bitwise_less_big(&big_1, &big_2)) {
        while (is_bitwise_less_big(&big_1, &big_2)) {
          mul_by_10_big(&big_1);
          scale_less_zero++;
        }
      }
      if (scale_less_zero < 28) {
        // если value_1 < value_2
        int dig_befor_point = 0;
        int dig_after_point = 0;
        err = normal_div(big_1, big_2, &big_res, &dig_befor_point,
                         &dig_after_point);

        // printf("dig_befor_point = %d\n", dig_befor_point);
        // printf("dig_after_point = %d\n", dig_after_point);
        if (scale_less_zero && !err) {  // если value_1 < value_2
          exp = dig_after_point + scale_less_zero;
          if (exp > 28) {
            big_decimal big_res_last = init();
            big_decimal last_diget = init();
            big_decimal scale_mantisa = init();
            big_decimal scale_last_dig = init();
            big_decimal ten = init();
            ten.bits[0] = 10;
            scale_exp = exp - 28;
            scale_mantisa = pow_10_decimal_big(scale_exp);
            scale_last_dig = pow_10_decimal_big(scale_exp - 1);
            div_int_bitwise_big(big_res, scale_last_dig, &big_res_last);
            mod_bitwise_big(big_res_last, ten, &last_diget);
            div_int_bitwise_big(big_res, scale_mantisa, &big_res);
            banking_rounding(&big_res, last_diget);
            exp = 28;
          }
          // print_big_mantissa(&big_res);
        } else if (!err) {  // если value_1 > value_2
          if (dig_after_point) exp = dig_after_point;
        }
      }
    }
    big_res.sign = res_sign;
    big_res.exp = exp;
    err = big_to_dec(big_res, result);
    if (err && res_sign) err = MINUS_INFINITY;
  }
  return err;
}

int normal_div(big_decimal big_1, big_decimal big_2, big_decimal *big_res,
               int *dig_befor_point, int *dig_after_point) {
  int err = 0;
  *dig_befor_point = 0;
  *dig_after_point = 0;
  set_zero_big(big_res);
  big_decimal ten = init();
  ten.bits[0] = 10;
  big_decimal last_diget = init();

  if (is_bitwise_grater_big(&big_1, &big_2) && !is_zero_big(&big_2)) {
    big_decimal big_mod = init();
    big_decimal big_buff = init();
    copy_decimal_big(&big_mod, big_1);
    div_int_bitwise_big(big_mod, big_2, big_res);  // целочисленный результат
    mod_bitwise_big(big_1, big_2, &big_buff);
    if (big_res->bits[5] || big_res->bits[4] || big_res->bits[3]) {
      err = 1;
    } else if (!is_zero_big(&big_buff)) {  // нецелочисленный результат
      set_zero_big(&big_buff);
      // количество цифр целой части
      copy_decimal_big(&big_buff, *big_res);
      while (!is_zero_big(&big_buff)) {
        div_int_bitwise_big(big_buff, ten, &big_buff);
        (*dig_befor_point)++;
      }
      set_zero_big(&big_buff);
      // количество цифр целой части

      // деление столбиком
      do {
        mod_bitwise_big(big_mod, big_2, &big_mod);
        mul_by_10_big(&big_mod);
        div_int_bitwise_big(big_mod, big_2, &big_buff);
        if (!is_zero_big(&big_mod)) {
          (*dig_after_point)++;
          mul_by_10_big(big_res);
          err = add_bitwise_big(*big_res, big_buff, big_res);
          if (big_res->bits[3]) {
            set_zero_big(&last_diget);
            mod_bitwise_big(*big_res, ten, &last_diget);
            div_int_bitwise_big(*big_res, ten, big_res);
            banking_rounding(big_res, last_diget);
            (*dig_after_point)--;
            break;
          }
          set_zero_big(&big_buff);
        }
      } while (!is_zero_big(&big_mod));

    }  // нецелочисленный результат
  } else {
    err = 1;
  }
  return err;
}