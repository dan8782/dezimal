#include "../s21_decimal.h"

int s21_is_less(s21_decimal x, s21_decimal y) {
  int result = 0; // 0 - FALSE, 1 - TRUE
  int bitwise_compare = 0;
  int sign_x = get_sign(&x);
  int sign_y = get_sign(&y);
  int equal = is_bitwise_equal(&x, &y);

  if (!equal) {
    if (sign_x > sign_y && !is_zero(&y)) {
      result = 1;
    } else if (sign_x == sign_y) {
      big_decimal big_x = dec_to_big(x);
      big_decimal big_y = dec_to_big(y);

      if (big_x.exp != big_y.exp) {
        normalize_big(&big_x, &big_y);
      }

      bitwise_compare = is_bitwise_less_big(&big_x, &big_y);
      if ((!bitwise_compare && sign_x) || (bitwise_compare && !sign_x))
        result = 1;
    }
  }

  return result;
}