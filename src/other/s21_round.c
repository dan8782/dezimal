#include "../s21_decimal.h"

/////////////////////////////////////////////////////////////////////////////////////////
// Округлние до ближайщего целого: // N+1 знак < 5, то N-й знак сохраняют // N+1
// знак ≥ 5, то N-й знак увеличивают на единицу, а N+1 и все последующие
// обнуляют  //
/////////////////////////////////////////////////////////////////////////////////////////

int s21_round(s21_decimal dec, s21_decimal *res) {
  int err = 0;
  int exp = get_exp(&dec);
  s21_decimal mod = {0};
  s21_decimal buff = {0};
  s21_decimal last_number = {0};
  s21_decimal ten = {10, 0, 0, 0};
  s21_decimal five = {5, 0, 0, 0};
  s21_decimal one = {1, 0, 0, 0};
  s21_decimal scale = {0};
  set_zero(res);

  if (exp) {
    s21_decimal scale =
        pow_10_decimal(exp - 1);  // на один знак больше чем целая часть
    div_int_bitwise(dec, scale, &buff);
    mod_bitwise(buff, ten, &last_number);

    err = s21_truncate(dec, res);  // учитывает знак, степень убирается там же
    int less = s21_is_less(last_number, five);  // N+1 знак < 5
    if (!less) err = add_bitwise(*res, one, res);
  } else {
    copy_decimal(res, dec);  // учитывает знак, степень равно 0
  }

  return err;
}