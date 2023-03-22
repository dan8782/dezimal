#include "./test_main.h"

START_TEST(division_by_zero) {
  s21_decimal dec1 = {8798797, 0, 0, 0};
  s21_decimal dec2 = {0, 0, 0, 0};
  s21_decimal res = {0};

  printf("division_by_zero:\n");
  print_dec(&dec1);
  print_dec(&dec2);
  printf("result:\n");
  div_int_bitwise(dec1, dec2, &res);
  print_dec(&res);

  ck_assert_int_eq(DIVISION_BY_ZERO, res.status);
}
END_TEST

START_TEST(dec1_less_dec2) {
  s21_decimal dec1 = {UINT32_MAX, 123, 0, 0};
  s21_decimal dec2 = {UINT32_MAX, 124, 0, 0};
  s21_decimal res = {0};

  printf("dec1_less_dec2:\n");
  print_dec(&dec1);
  print_dec(&dec2);
  printf("result:\n");
  div_int_bitwise(dec1, dec2, &res);
  print_dec(&res);
  ck_assert_int_eq(0, res.bits[0]);
}
END_TEST

START_TEST(dec1_eq_dec2) {
  s21_decimal dec1 = {UINT32_MAX, 555, 11, 0};
  s21_decimal dec2 = {UINT32_MAX, 555, 11, 0};
  s21_decimal res = {0};

  printf("dec1_eq_dec2:\n");
  print_dec(&dec1);
  print_dec(&dec2);
  printf("result:\n");
  div_int_bitwise(dec1, dec2, &res);
  print_dec(&res);
  ck_assert_int_eq(1, res.bits[0]);
}
END_TEST

START_TEST(div_zero) {
  s21_decimal dec1 = {0, 0, 0, 0};
  s21_decimal dec2 = {UINT32_MAX, UINT32_MAX, 0, 0};
  s21_decimal res = {0};

  printf("div_zero:\n");
  print_dec(&dec1);
  print_dec(&dec2);
  printf("result:\n");
  div_int_bitwise(dec1, dec2, &res);
  print_dec(&res);
  ck_assert_int_eq(0, res.bits[0]);
}
END_TEST

START_TEST(dec1_greate_dec2_1) {
  s21_decimal dec1 = {7994643, 0, 0, 0};
  s21_decimal dec2 = {1000000, 0, 0, 0};
  s21_decimal res = {0};

  printf("dec1_greate_dec2_1:\n");
  print_dec(&dec1);
  print_dec(&dec2);
  printf("result:\n");
  div_int_bitwise(dec1, dec2, &res);
  print_dec(&res);
  ck_assert_int_eq(7, res.bits[0]);
}
END_TEST

START_TEST(dec1_MAX_dec2) {
  s21_decimal dec1 = {UINT32_MAX, UINT32_MAX, UINT32_MAX, 0};
  s21_decimal dec2 = {3456, 0, 0, 0};
  s21_decimal res = {0};

  printf("dec1_MAX_dec2:\n");
  print_dec(&dec1);
  print_dec(&dec2);
  printf("result:\n");
  div_int_bitwise(dec1, dec2, &res);
  print_dec(&res);
  ck_assert_int_eq(123, res.bits[0]);
}
END_TEST

START_TEST(dec1_dec2_MAX) {
  s21_decimal dec1 = {UINT32_MAX - 1, 0, 0, 0};
  s21_decimal dec2 = {UINT32_MAX, UINT32_MAX, UINT32_MAX, 0};
  s21_decimal res = {0};

  printf("dec1_dec2_MAX:\n");
  print_dec(&dec1);
  print_dec(&dec2);
  printf("result:\n");
  div_int_bitwise(dec1, dec2, &res);
  print_dec(&res);
  ck_assert_int_eq(0, res.bits[0]);
}
END_TEST

START_TEST(dec1_MAX_dec2_MAX) {
  s21_decimal dec1 = {UINT32_MAX, UINT32_MAX, UINT32_MAX, 0};
  s21_decimal dec2 = {UINT32_MAX, UINT32_MAX, UINT32_MAX, 0};
  s21_decimal res = {0};

  printf("dec1_MAX_dec2_MAX:\n");
  print_dec(&dec1);
  print_dec(&dec2);
  printf("result:\n");
  div_int_bitwise(dec1, dec2, &res);
  print_dec(&res);
  ck_assert_int_eq(1, res.bits[0]);
}
END_TEST

Suite *suite_div_int_bitwise() {
  Suite *s1;
  TCase *tc1;
  s1 = suite_create("suite_test_div_int_bitwise");
  tc1 = tcase_create("case_div_int_bitwise");
  tcase_add_test(tc1, division_by_zero);
  tcase_add_test(tc1, dec1_less_dec2);
  tcase_add_test(tc1, dec1_eq_dec2);
  tcase_add_test(tc1, div_zero);
  tcase_add_test(tc1, dec1_greate_dec2_1);
  tcase_add_test(tc1, dec1_MAX_dec2);
  tcase_add_test(tc1, dec1_dec2_MAX);
  tcase_add_test(tc1, dec1_MAX_dec2_MAX);
  suite_add_tcase(s1, tc1);
  return s1;
}