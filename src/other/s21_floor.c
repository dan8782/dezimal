#include "../s21_decimal.h"

//////////////////////////////////////////////////////////////////////////
// Округлние до ближайщего целого в строну отрицательной бесконечности: //
// -2.1 = -3 || 2.1 = 2                                                 //
// -2.7 = -3 || 2.7 = 2                                                 //
//////////////////////////////////////////////////////////////////////////

int s21_floor(s21_decimal dec, s21_decimal *res) {
  int err = 0;
  int sign = get_sign(&dec);
  int exp = get_exp(&dec);

  s21_decimal one = {1, 0, 0, 0};
  set_zero(res);

  if (!is_zero(&dec)) {  // для условия ниже, слуячай -0: 0 / 10^n
    err = s21_truncate(dec, res);  // результат - целая часть
    s21_decimal scale = pow_10_decimal(exp);
    s21_decimal mod = {0, 0, 0, 0};
    mod_bitwise(dec, scale, &mod);

    if (sign && exp && !is_zero(&mod))  // если отрицательное и не целое
      err = add_bitwise(*res, one, res);
  }

  return err;
}
