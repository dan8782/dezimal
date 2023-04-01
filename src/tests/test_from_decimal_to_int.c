#include "./test_main.h"

START_TEST(zero_decimal) {
  s21_decimal x = {0};
  printf("zero_decimal\n");
  print_dec(&x);
  int result = 0;
  s21_from_decimal_to_int(x, &result);
  ck_assert_int_eq(0, result);
}
END_TEST

START_TEST(int_neg) {
  s21_decimal x = {{2147483647, -1, 0, 0}};
  set_sign(&x, 1);
  printf("int_neg\n");
  print_dec(&x);
  int result = 0;
  int error = s21_from_decimal_to_int(x, &result);
  //s21_from_decimal_to_int(x, &result);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(int_neg_2) {
  s21_decimal x = {{132, 0, 0, 0}};
  set_sign(&x, 1);
  printf("int_neg_2\n");
  print_dec(&x);
  int result = 0;
  int error = s21_from_decimal_to_int(x, &result);
  //s21_from_decimal_to_int(x, &result);
  ck_assert_int_eq(-132, result);
}
END_TEST

START_TEST(int_neg_3) {
  s21_decimal x = {{-1, 0, 0, 0}};
  //set_sign(&x, 1);
  printf("int_neg_3\n");
  print_dec(&x);
  int result = 0;
  int error = s21_from_decimal_to_int(x, &result);
  //s21_from_decimal_to_int(x, &result);
  ck_assert_int_eq(-1, result);
}
END_TEST

START_TEST(int_neg_4) {
  s21_decimal x = {{-1, 1, 0, 0}};
  //set_sign(&x, 1);
  printf("int_neg_4\n");
  print_dec(&x);
  int result = 0;
  int error = s21_from_decimal_to_int(x, &result);
  //s21_from_decimal_to_int(x, &result);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(int_pos) {
  s21_decimal x = {33, 0, 0, 0};
  printf("int_pos\n");
  print_dec(&x);
  int result = 0;
  s21_from_decimal_to_int(x, &result);
  ck_assert_int_eq(33, result);
}
END_TEST

START_TEST(int_with_exp) {
  s21_decimal x = {INT32_MAX, INT32_MAX, INT32_MAX, 0};
  set_exp(&x, 28);
  printf("int_with_exp\n");
  print_dec(&x);
  int result = 0;
  s21_from_decimal_to_int(x, &result);
  ck_assert_int_eq(3, result);
}
END_TEST

START_TEST(int_with_exp_2) {
  s21_decimal x = {75689, 0, 0, 0};
  set_exp(&x, 3);
  printf("int_with_exp\n");
  print_dec(&x);
  int result = 0;
  s21_from_decimal_to_int(x, &result);
  ck_assert_int_eq(75, result);
}
END_TEST

START_TEST(int_with_exp_3) {
  s21_decimal x = {125, 0, 0, 0};
  set_exp(&x, 3);
  printf("int_with_exp\n");
  print_dec(&x);
  int result = 0;
  s21_from_decimal_to_int(x, &result);
  ck_assert_int_eq(0, result);
}
END_TEST


Suite *suite_s21_from_decimal_to_int() {
  Suite *s1;
  TCase *tc1;
  s1 = suite_create("suite_s21_from_decimal_to_int");
  tc1 = tcase_create("case_from_decimal_to_int");
  tcase_add_test(tc1, zero_decimal);
  tcase_add_test(tc1, int_neg);
  tcase_add_test(tc1, int_neg_2);
  tcase_add_test(tc1, int_neg_3);
  tcase_add_test(tc1, int_neg_4);
  tcase_add_test(tc1, int_pos);
  tcase_add_test(tc1, int_with_exp);
  tcase_add_test(tc1, int_with_exp_2);
   tcase_add_test(tc1, int_with_exp_3);
  suite_add_tcase(s1, tc1);
  return s1;
}