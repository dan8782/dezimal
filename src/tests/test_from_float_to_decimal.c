// #include "./test_main.h"

// START_TEST(zero_int) {
//   s21_decimal x = {0};
//   printf("zero_int\n");
//   float src = 0;
//   s21_from_float_to_decimal(src, &x);
//   print_dec(&x);
// }
// END_TEST

// START_TEST(pos_max_int) {
//   s21_decimal x = {0};
//   printf("pos_max_int\n");
//   float src = 2.1;
//   s21_from_float_to_decimal(src, &x);
//   printf("pos_max_int\n");
//   print_dec(&x);
// }
// END_TEST

// START_TEST(neg_max_int) {
//   s21_decimal x = {0};
//   printf("neg_max_int\n");
//   float src = -INT_MAX;
//   printf("%.8f\n", src);
//   s21_from_float_to_decimal(src, &x);
//   print_dec(&x);
//   printf("%.8d\n", x);
// }
// END_TEST

// START_TEST(neg_int) {
//   s21_decimal x = {0};
//   printf("neg_int\n");
//   float src = -10;
//   s21_from_float_to_decimal(src, &x);
//   print_dec(&x);
// }
// END_TEST

// START_TEST(pos_int) {
//   s21_decimal x = {0};
//   printf("pos_int\n");
//   float src = 10;
//   s21_from_float_to_decimal(src, &x);
//   print_dec(&x);
// }
// END_TEST

// Suite *suite_s21_from_float_to_decimal() {
//   Suite *s1;
//   TCase *tc1;
//   s1 = suite_create("suite_s21_from_float_to_decimal");
//   tc1 = tcase_create("case_from_float_to_decimal");
//   tcase_add_test(tc1, zero_int);
//   tcase_add_test(tc1, pos_max_int);
//   tcase_add_test(tc1, neg_max_int);
//   tcase_add_test(tc1, pos_int);
//   tcase_add_test(tc1, neg_int);
//   suite_add_tcase(s1, tc1);
//   return s1;
// }