#include "../s21_decimal.h"

////////////////////////////////////////////////
// Приведение меньшей степени к большей       //
////////////////////////////////////////////////

int normalize_big(big_decimal *big_1, big_decimal *big_2) {
  int err = 1;

  int exp1 = big_1->exp;
  int exp2 = big_2->exp;

  if (exp1 != exp2) {
    big_decimal **with_max_exp = &big_1;
    big_decimal **with_min_exp = &big_2;

    if (exp2 > exp1) {
      with_max_exp = &big_2;
      with_min_exp = &big_1;
    }

    int exp_min = (*with_min_exp)->exp;
    int exp_max = (*with_max_exp)->exp;

    int step = exp_max - exp_min;

    // big_decimal ten = init();
    // ten.bits[0] = 10;

    while (step--) {
      // mul_by_10_big(&with_min_exp);
    }
    (*with_min_exp)->exp = exp_max;

    err = 0;
  }

  return err;
}