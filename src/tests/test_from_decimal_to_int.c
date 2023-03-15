#include "./test_main.h"

START_TEST(zero_decimal) {
  s21_decimal x = {0};
  printf("zero_decimal\n");
  print_dec(x);
  int result = 0;
  s21_from_decimal_to_int(x, &result);
  ck_assert_int_eq(0, result);
}
END_TEST

START_TEST(int_neg) {
  s21_decimal x = {{INT_MAX, 0, 0, 0}};
  set_sign(&x, 1);
  printf("int_neg\n");
  print_dec(x);
  int result = 0;
  s21_from_decimal_to_int(x, &result);
  ck_assert_int_eq(-INT_MAX, result);
}
END_TEST

START_TEST(int_pos) {
  s21_decimal x = { {33, 0, 0, 0} };
  printf("int_pos\n");
  print_dec(x);
  int result = 0;
  s21_from_decimal_to_int(x, &result);
  ck_assert_int_eq(33, result);
}
END_TEST

START_TEST(int_with_exp) {
<<<<<<< HEAD
  s21_decimal x = {12345, 0, 0, 0};
  set_exp(&x, 2);
=======
  s21_decimal x = { {12345, 0, 0, 0} };
  set_exp(&x, 5);
>>>>>>> 31fcce9b1f12e12b08c0e5ec023045f422681971
  printf("int_with_exp\n");
  print_dec(x);
  int result = 0;
  s21_from_decimal_to_int(x, &result);
<<<<<<< HEAD
  ck_assert_int_eq(12345, result);
=======
  ck_assert_int_eq(0, result);
>>>>>>> 31fcce9b1f12e12b08c0e5ec023045f422681971
}
END_TEST

Suite *suite_s21_from_decimal_to_int() {
  Suite *s1;
  TCase *tc1;
  s1 = suite_create("suite_s21_from_decimal_to_int");
  tc1 = tcase_create("case_from_decimal_to_int");
  tcase_add_test(tc1, zero_decimal);
  tcase_add_test(tc1, int_neg);
  tcase_add_test(tc1, int_pos);
  tcase_add_test(tc1, int_with_exp);
  suite_add_tcase(s1, tc1);
  return s1;
}
