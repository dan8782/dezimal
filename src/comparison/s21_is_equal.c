#include "../s21_decimal.h"

int s21_is_equal(s21_decimal x, s21_decimal y) {
  int res = 0;
  if (is_zero(&x) && is_zero(&y)) {
    res = 1;
  } else if (get_sign(&x) != get_sign(&y)) {
    res = 0;
  } else {
    big_decimal big_x = dec_to_big(x);
    big_decimal big_y = dec_to_big(y);

    if (big_x.exp != big_y.exp) {
      normalize_big(&big_x, &big_y);
    }
    res = is_bitwise_equal_big(&big_x, &big_y);
  }

  return res;
}