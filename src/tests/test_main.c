// #include "./test_main.h"

// int main() {
//   Suite *test_suites[] = {suite_s21_from_decimal_to_int(),
//                           suite_s21_from_int_to_decimal(),
//                           suite_s21_is_equal()};

//   SRunner *suite_runner = srunner_create(test_suites[0]);
//   srunner_set_fork_status(suite_runner, CK_NOFORK);

//   for (unsigned long i = 1; i < ARRAY_SIZE(test_suites); i++) {
//     srunner_add_suite(suite_runner, test_suites[i]);
//   }
//   srunner_run_all(suite_runner, CK_NORMAL);
//   int failed_count = srunner_ntests_failed(suite_runner);
//   srunner_free(suite_runner);

//   if (failed_count != 0) {
//     return EXIT_FAILURE;
//   }
//   return EXIT_SUCCESS;
// }
