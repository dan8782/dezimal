#include "./test_main.h"

START_TEST(zero_int) {
  s21_decimal x = {0};
  printf("zero_int\n");
  int src = 0;
  s21_from_int_to_decimal(src, &x);
  print_dec(&x);
}
END_TEST

START_TEST(pos_max_int) {
  s21_decimal x = {0};
  printf("pos_max_int\n");
  int src = INT_MAX;
  s21_from_int_to_decimal(src, &x);
  print_dec(&x);
}
END_TEST

START_TEST(neg_max_int) {
  s21_decimal x = {0};
  printf("neg_max_int\n");
  int src = -INT_MAX;
  s21_from_int_to_decimal(src, &x);
  print_dec(&x);
}
END_TEST

START_TEST(neg_int) {
  s21_decimal x = {0};
  printf("neg_int\n");
  int src = -10;
  s21_from_int_to_decimal(src, &x);
  print_dec(&x);
}
END_TEST

START_TEST(pos_int) {
  s21_decimal x = {0};
  printf("pos_int\n");
  int src = 10;
  s21_from_int_to_decimal(src, &x);
  print_dec(&x);
}
END_TEST

Suite *suite_s21_from_int_to_decimal() {
  Suite *s1;
  TCase *tc1;
  s1 = suite_create("suite_s21_from_int_to_decimal");
  tc1 = tcase_create("case_from_int_to_decimal");
  tcase_add_test(tc1, zero_int);
  tcase_add_test(tc1, pos_max_int);
  tcase_add_test(tc1, neg_max_int);
  tcase_add_test(tc1, pos_int);
  tcase_add_test(tc1, neg_int);
  suite_add_tcase(s1, tc1);
  return s1;
}