#include "../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  s21_decimal truncated = {0};

  int flag = 0;
  int error = s21_truncate(src, &truncated);

  if (error == 1) {
    flag = 1;
    // printf("bug 1\n");
  } else if (truncated.bits[1] || truncated.bits[2]) {
    flag = 1;
    // printf("bug 2 \n");
  } else {
    *dst = (int)truncated.bits[0];
    // printf("%d func test \n", *dst);
    int sign = get_sign(&src);

    if (sign) *dst = -*dst;
  }
  return flag;
}
