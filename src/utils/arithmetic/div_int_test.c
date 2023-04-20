#include "../../s21_decimal.h"

s21_decimal div_int_test(s21_decimal dividend, s21_decimal divisor,
                         s21_decimal *result) {
  s21_decimal original_divisor = divisor;
  s21_decimal modified_dividend = {0};
  s21_decimal one = {{1}};
  int unused_code = 0;

  if (is_bitwise_equal(&dividend, &divisor))
    return one;
  else if (is_bitwise_less(&dividend, &divisor))
    return modified_dividend;

  while ((is_bitwise_less(&divisor, &dividend) ||
          is_bitwise_equal(&divisor, &dividend)) &&
         !get_bit(divisor, 95)) {
    left_shift(&divisor);
    left_shift(result);
  }

  /* Shifting (@divisor) once to correctly align it with dividend */
  if (is_bitwise_less(&dividend, &divisor)) {
    // printf("4\n");
    right_shift(&divisor);
    right_shift(result);
  }

  sub_bitwise(dividend, divisor, &modified_dividend);

  one = div_int_test(modified_dividend, original_divisor, &one);

  add_bitwise(one, *result, result);

  return *result;
}