#include "../../s21_decimal.h"
////////////////////////////////////////////////////////
// Делит два 96 битных числа и возвращает целую часть //
// Знаки и степня входящих децималов не учитываются   //
// Сравнения чисел только по мантиссе                 //
////////////////////////////////////////////////////////
int div_int_bitwise(s21_decimal x, s21_decimal y, s21_decimal *res) {
  int err = OK;
  int less = is_bitwise_less(&x, &y);  // if |x| < |a| return 1
  set_zero(res);
  if (is_zero(&y)) {
    err = DIVISION_BY_ZERO;
    // res->status = DIVISION_BY_ZERO;
  } else if (less) {
    set_zero(res);  // целая часть 0
  } else {
    s21_decimal buff_y = {0, 0, 0, 0};

    for (int i = LAST_BIT - 1; i >= 0; i--) {
      // printf("i = %d\n", i);
      copy_decimal(&buff_y, y);

      for (int j = 0; j < i; j++) {
        if (left_shift(&buff_y)) {  // y * 2^i
          break;
        }  // переполнение
        // left_shift(&buff_y);
      }
      if (is_bitwise_less_or_equal(&buff_y, &x) &&
          !get_bit(buff_y, 95)) {    // checking if: y * 2^i <= x
        sub_bitwise(x, buff_y, &x);  // subtracting y << i from x
        // print_dec(&x);
        s21_decimal one = {1, 0, 0, 0};  // сбрасываем изменненный one
        for (int k = 0; k < i; k++, left_shift(&one))
          ;  // 1 << i;  2^i
        if (get_bit(buff_y, 95)) {
          int last_bit = get_last_bit(&buff_y);
          if (last_bit)
            for (int j = 0; j < (96 - last_bit); j++, right_shift(&one))
              ;
        }
        add_bitwise(*res, one, res);  // adding 2^i to the answer
      } else if (get_bit(buff_y, 95)) {
        s21_decimal one = {1, 0, 0, 0};
        // left_shift(&one);
        add_bitwise(*res, one, res);
      }
    }
  }

  return err;
}

int div_int_bitwise_big(big_decimal x, big_decimal y, big_decimal *res) {
  int err = OK;
  *res = init();  // БЕЗ ЗАНУЛЕНИЯ БЫЛИ ПРОБЛЕМЫ - ПРОВЕРЯТЬ ОБЫЧНЫЙ DIV_INT ()
  int less = is_bitwise_less_big(&x, &y);  // if |x| < |a| return 1

  if (is_zero_big(&y)) {
    err = DIVISION_BY_ZERO;
  } else if (less) {
    set_zero_big(res);  // целая часть 0
  } else {
    big_decimal buff_y = init();

    for (int i = 191; i >= 0; i--) {
      // printf("i = %d\n", i);
      copy_decimal_big(&buff_y, y);

      for (int j = 0; j < i; j++) {
        if (left_shift_big(&buff_y)) {  // y * 2^i
          break;
        }  // переполнение
        // left_shift(&buff_y);
      }
      if (is_bitwise_less_or_equal_big(&buff_y,
                                       &x)) {  // checking if: y * 2^i <= x
        sub_bitwise_big(x, buff_y, &x);        // subtracting y << i from x
        // print_dec(&x);
        big_decimal one = init();  // сбрасываем изменненный one
        one.bits[0] = 1;
        for (int k = 0; k < i; k++, left_shift_big(&one))
          ;  // 1 << i;  2^i
        if (get_bit_big(&buff_y, 191)) {
          int last_bit = get_last_bit_big(&buff_y);
          if (last_bit)
            for (int j = 0; j < (192 - last_bit); j++, right_shift_big(&one))
              ;
        }
        err = add_bitwise_big(*res, one, res);  // adding 2^i to the answer
      }
    }
  }

  return err;
}

int get_last_bit(s21_decimal *val1) {
  int i = 0;
  if (val1 != NULL) {
    for (; i < 96; i++) {
      if (get_bit(*val1, i)) break;
    }
  }
  return i;
}

int get_last_bit_big(big_decimal *val1) {
  int i = 0;
  if (val1 != NULL) {
    for (; i < 192; i++) {
      if (get_bit_big(val1, i)) break;
    }
  }
  return i;
}