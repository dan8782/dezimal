#include "../s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dest) {
  int error = 0;
  set_zero(dest);
  if ((dest != NULL) && (error == 0) &&
      (((fabs(src) < 79228162514264337593543950335.0) &&
        (fabs(src) > 1.0e-28)) ||
       (src == 0.0))) {
    int scale = 0;
    unsigned int temp_src = 0;
    long double not_src = src;

    if (!!((*((unsigned int *)&src)) & 2147483648u) == 1) {
      set_sign(dest, 1);
      src *= -1;
    }

    not_src = (long double)src;
    if (src < 1000000.0) {
      while ((ceil(not_src) != not_src) && (not_src < 1000000.0) &&
             scale < 28) {
        not_src *= 10;
        scale++;
      }
      src *= powf(10.0, scale);
    } else if (src >= 10000000.0) {
      for (; not_src > 10000000.0; not_src /= 10.0, scale--) {
      }
    }
    temp_src = (unsigned int)round(not_src);
    for (int i = 0; temp_src && i < 96; i++, (temp_src /= 2)) {
      if (i < 32) {
        if ((temp_src % 2) == 1) {
          dest->bits[0] |= (1u << i);
        }
      } else if (i > 31 && i < 64) {
        if ((temp_src % 2) == 1) {
          dest->bits[1] |= (1u << i);
        }
      } else if (i > 63 && i < 96) {
        if ((temp_src % 2) == 1) {
          dest->bits[2] |= (1u << i);
        }
      }
    }
    if (scale < 0) {
      while (scale < 0) {
        *dest = mul_by_10(dest);
        scale++;
      }
    } else if (scale > 0) {
      set_exp(dest, scale);
      cut_zeros(dest);
    }
    error = 0;
  } else {
    error = 1;
  }
  return error;
}

void cut_zeros(s21_decimal *value) {
  int scale = get_exp(value);
  int sign = get_sign(value);
  s21_decimal ten = {{10, 0, 0, 0}};
  s21_decimal temp = {{0}};
  s21_decimal result = {{0}};
  for (int out = -1; out < 0;) {
    temp = s21_whole(*value, ten, &result);
    if (is_zero(&temp) && (scale != 0)) {
      *value = result;
      set_zero(&result);
      set_zero(&temp);
      scale--;
    } else if (!is_zero(&temp) || (scale == 0)) {
      out = 1;
    }
  }
  if (sign == 1) {
    set_sign(value, 1);
  }
  set_exp(value, scale);
}

s21_decimal s21_whole(s21_decimal value_1, s21_decimal value_2,
                      s21_decimal *result) {
  s21_decimal temp = {{0}};
  set_zero(result);
  value_1.bits[3] = 0;
  value_2.bits[3] = 0;

  for (int i = 95; i > -1; i--) {
    left_shift(&temp);
    if (get_bit(value_1, i)) {
      set_bit(&temp, 0, 1);
    }
    if (s21_is_greater_or_equal(temp, value_2)) {
      set_bit(result, i, 1);
      sub_bitwise(temp, value_2, &temp);
    }
  }

  value_1 = temp;
  return value_1;
}