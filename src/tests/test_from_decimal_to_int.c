#include "./test_main.h"

START_TEST(test1) {
  s21_decimal src = {10, 0, 0, 0};
  print_dec(src);
  int result = 0;
  s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(10, result);
}
END_TEST

START_TEST(test2) {
  s21_decimal src = {INT_MAX, 0, 0, 0};
  print_dec(src);
  int result = 0;
  s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(INT_MAX, result);
}
END_TEST

Suite *suite_s21_from_decimal_to_int() {
  Suite *s1;
  TCase *tc1;
  s1 = suite_create("suite_s21_from_decimal_to_int");
  tc1 = tcase_create("case_from_decimal_to_int");
  tcase_add_test(tc1, test1);
  tcase_add_test(tc1, test2);
  suite_add_tcase(s1, tc1);
  return s1;
}
