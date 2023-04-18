#ifndef SRC_TESTS_TEST_MAIN_H_
#define SRC_TESTS_TEST_MAIN_H_

#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>  //  EXIT_SUCCESS //EXIT_FAILURE
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

#include "../s21_decimal.h"

Suite *suite_s21_from_decimal_to_int();
Suite *suite_s21_from_decimal_to_float();
Suite *suite_s21_from_float_to_decimal();
Suite *suite_s21_from_int_to_decimal();
Suite *suite_add();
Suite *suite_is_less();
Suite *suite_is_equal();
Suite *suite_is_greater();
Suite *suite_is_greater_or_equal();
Suite *suite_is_less_or_equal();

#endif  //  SRC_TESTS_TEST_MAIN_H_
