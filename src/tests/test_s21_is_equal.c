#include "./test_main.h"

START_TEST(equal_positive_zero_1) {
  s21_decimal x = {0};
  s21_decimal y = {0};
  printf("equal_positive_zero_1\n");
  print_dec(x);
  print_dec(y);
  ck_assert_int_eq(1, s21_is_equal(x, y));
}
END_TEST

START_TEST(equal_neg_pos_zero_1_1) {
  s21_decimal x = {0};
  set_sign(&x, 1);
  s21_decimal y = {0};
  printf("equal_neg_pos_zero_1_1\n");
  print_dec(x);
  print_dec(y);
  ck_assert_int_eq(0, s21_is_equal(x, y));
}
END_TEST

START_TEST(equal_pos_neg_zero_1_2) {
  s21_decimal x = {0};
  s21_decimal y = {0};
  set_sign(&y, 1);
  printf("equal_pos_neg_zero_1_2\n");
  print_dec(x);
  print_dec(y);
  ck_assert_int_eq(0, s21_is_equal(x, y));
}
END_TEST

START_TEST(equal_positive_int_2) {
  s21_decimal x = {INT_MAX, 0, 0, 0};
  s21_decimal y = {INT_MAX, 0, 0, 0};
  printf("equal_positive_int_2\n");
  print_dec(x);
  print_dec(y);
  ck_assert_int_eq(1, s21_is_equal(x, y));
}
END_TEST

START_TEST(equal_positive_negative_int_3) {
  s21_decimal x = {INT_MAX, 0, 0, 0};
  s21_decimal y = {INT_MAX, 0, 0, 0};
  set_sign(&y, 1);
  printf("equal_positive_negative_int_3\n");
  print_dec(x);
  print_dec(y);
  ck_assert_int_eq(0, s21_is_equal(x, y));
}
END_TEST

START_TEST(equal_negative_positive_int_4) {
  s21_decimal x = {INT_MAX, 0, 0, 0};
  set_sign(&x, 1);
  s21_decimal y = {INT_MAX, 0, 0, 0};
  printf("equal_negative_positive_int_4\n");
  print_dec(x);
  print_dec(y);
  ck_assert_int_eq(0, s21_is_equal(x, y));
}
END_TEST

START_TEST(les_neg_int_great_pos_int_5) {
  s21_decimal x = {12, 0, 0, 0};
  set_sign(&x, 1);
  s21_decimal y = {INT_MAX, 0, 0, 0};
  printf("les_neg_int_great_pos_int_5\n");
  print_dec(x);
  print_dec(y);
  ck_assert_int_eq(0, s21_is_equal(x, y));
}
END_TEST

START_TEST(les_pos_int_great_pos_int_6) {
  s21_decimal x = {12, 0, 0, 0};
  s21_decimal y = {INT_MAX, 0, 0, 0};
  printf("les_pos_int_great_pos_int_6\n");
  print_dec(x);
  print_dec(y);
  ck_assert_int_eq(0, s21_is_equal(x, y));
}
END_TEST

START_TEST(les_pos_int_great_neg_int_7) {
  s21_decimal x = {12, 0, 0, 0};
  s21_decimal y = {INT_MAX, 0, 0, 0};
  set_sign(&y, 1);
  printf("les_pos_int_great_neg_int_7\n");
  print_dec(x);
  print_dec(y);
  ck_assert_int_eq(0, s21_is_equal(x, y));
}
END_TEST

Suite *suite_s21_is_equal() {
  Suite *s1;
  TCase *tc1;
  s1 = suite_create("suite_s21_is_equal");
  tc1 = tcase_create("case_s21_is_equal");
  tcase_add_test(tc1, equal_positive_zero_1);
  tcase_add_test(tc1, equal_neg_pos_zero_1_1);
  tcase_add_test(tc1, equal_pos_neg_zero_1_2);
  tcase_add_test(tc1, equal_positive_int_2);
  tcase_add_test(tc1, equal_positive_negative_int_3);
  tcase_add_test(tc1, equal_negative_positive_int_4);
  tcase_add_test(tc1, les_neg_int_great_pos_int_5);
  tcase_add_test(tc1, les_pos_int_great_pos_int_6);
  tcase_add_test(tc1, les_pos_int_great_neg_int_7);
  suite_add_tcase(s1, tc1);
  return s1;
}
