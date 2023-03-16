#include "../s21_decimal.h"

int s21_is_less(s21_decimal x, s21_decimal y) {
  int result = 0;  // 0 - FALSE, 1 - TRUE

  // Проверка по знаку
  int sign_x = get_bit(x, SIGN_BIT);
  int sign_y = get_bit(y, SIGN_BIT);
  // printf("sign_x=%d, sign_y=%d\n", sign_x, sign_y);
  //  exp = 1 - отрицательное число

  if (sign_x > sign_y) {
    result = 1;
  } else if (sign_x < sign_y) {
    result = 0;
  } else if (sign_x == sign_y) {
    result = 11;  // если оба + или - далее обрабатывается
  }

  // Проверка по степени
  int exp_x = get_exp(&x);
  int exp_y = get_exp(&y);
  // printf("exp_x=%d, exp_y=%d\n", exp_x, exp_y);
  if ((result == 11) &&
      (exp_x == exp_y)) {  // если степени равны, то сравниваем мантиссу
    result = is_mantissa_less(
        x, y, sign_x);  // Вернет 1, если  x < y, иначе 0
                        // передаем только знак х, т.к. с у они равны
  } else if (result == 11 && exp_x < exp_y) {
    result = 0;
  } else if (result == 11 && exp_x > exp_y) {
    result = 1;
  }

  return result;
}