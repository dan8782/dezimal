#include "../s21_decimal.h"
/* Old one:
int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int flag = 0;
  int data = 0;
  int scale = get_exp(&src);
  for (int i = 1; i < 3; i++) {
    if (src.bits[i] != 0) {
      flag = 1;
    }
  }

*dst = 0;

  if (!flag) {
    for (int i = scale + 30; i >= scale; --i) {
      data <<= 1;
      data |= get_bit(src, i);
    }
    if (get_sign(&src)) {
      data = -data;
    }
  return *dst;
}

int dst2 = 0.0;

int return_val = 0;
  *dst = 0;

  int scale = get_exp(src);
  if (!dst) {
    return_val = 1;
  }

  for (int i = 0; i < LAST_BIT; i++) {
    if (get_bit(src, i)) {
      dst2 += pow(2, i);
    }
  }
  while (scale) {
    dst2 /= 10;
    scale--;
  }
  if (get_sign(src)) {
    dst2 = dst2 * (-1);
  }
  printf("%d\n", dst2);
  *dst = (int)dst2;
  return *dst;
}
*/

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
    s21_decimal truncated = {0};

    int code = s21_truncate(src, &truncated);

    int sign = get_sign(&src);

    if (!dst || code == 1)
        return 1;

    if (get_bit(truncated, 31) || truncated.bits[1] || truncated.bits[2])
        return 1;

    int tmp = 0;

    for (int i = 0; i < 31; i++)
        tmp += pow(2, i) * get_bit(truncated, i);

    if (tmp == src.bits[0] && sign)
        return 1;

    if (sign)
        tmp = -tmp;

    *dst = tmp;

    return 0;
}
