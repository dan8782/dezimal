#include "./test_main.h"

int main() {
  Suite *test_suites[] = {suite_from_decimal_to_float(),
                          suite_from_decimal_to_int(),
                          suite_from_float_to_decimal(),
                          suite_from_int_to_decimal(),
                          suite_is_equal(),
                          suite_is_less(),
                          suite_is_greater(),
                          suite_is_greater_or_equal(),
                          suite_is_less_or_equal(),
                          suite_is_not_equal(),
                          suite_add(),
                          suite_sub(),
                          suite_truncate(),
                          suite_negate(),
                          suite_floor(),
                          suite_round(),
                          suite_div(),
                          suite_mul()};
  SRunner *suite_runner = srunner_create(test_suites[0]);
  srunner_set_fork_status(suite_runner, CK_NOFORK);

  for (unsigned long i = 1; i < ARRAY_SIZE(test_suites); i++) {
    srunner_add_suite(suite_runner, test_suites[i]);
  }
  srunner_run_all(suite_runner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  if (failed_count != 0) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
