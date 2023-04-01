#include "./test_main.h"

START_TEST(zero_decimal) {
  s21_decimal x = {0};
  printf("zero_decimal\n");
  print_dec(&x);
  float result = 0;
  s21_from_decimal_to_float(x, &result);
   printf("%.8f  bugfix\n", result);
  ck_assert_float_eq(0, result);
}
END_TEST

START_TEST(int_neg) {
  s21_decimal x = {{INT_MAX, 0, 0, 0}};
  set_sign(&x, 1);
  printf("int_neg\n");
  print_dec(&x);
  float result = 0;
  s21_from_decimal_to_float(x, &result);
   printf("%.8f  bugfix\n", result);
  ck_assert_float_eq_tol(-INT_MAX, result, 8);
}
END_TEST

START_TEST(int_pos) {
  s21_decimal x = {{33, 0, 0, 0}};
  printf("int_pos\n");
  print_dec(&x);
  float result = 0;
  s21_from_decimal_to_float(x, &result);
   printf("%f bugfix\n", result);
  ck_assert_float_eq(33, result);
}
END_TEST

START_TEST(int_with_exp) {
  s21_decimal x = {{12345, 0, 0, 0}};
  set_exp(&x, 6);
  printf("int_with_exp\n");
  print_dec(&x);
  float result = 0;
  s21_from_decimal_to_float(x, &result);
   printf("%.8f bugfix\n", result);
  ck_assert_float_eq_tol(0, result, 8);
}
END_TEST

START_TEST(int_with_exp_2) {
  s21_decimal x = {{1, 0, 0, 0}};
  set_exp(&x, 8);
  printf("int_with_exp_2\n");
  print_dec(&x);
  float result = 0;
  s21_from_decimal_to_float(x, &result);
  printf("%.8f  bugfix\n", result);
  ck_assert_float_eq_tol(1, result, 8);
}
END_TEST

Suite *suite_s21_from_decimal_to_float() {
  Suite *s1;
  TCase *tc1;
  s1 = suite_create("suite_s21_from_decimal_to_float");
  tc1 = tcase_create("case_from_decimal_to_float");
  tcase_add_test(tc1, zero_decimal);
  tcase_add_test(tc1, int_neg);
  tcase_add_test(tc1, int_pos);
  tcase_add_test(tc1, int_with_exp);
  tcase_add_test(tc1, int_with_exp_2);
  suite_add_tcase(s1, tc1);
  return s1;
}
