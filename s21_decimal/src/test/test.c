#include "test.h"

int main() {
  run_tests();
  return 0;
}

void run_one_test(Suite *tc) {
  static int number_tc = 1;

  if (number_tc > 1) putchar('\n');
  printf("%s%d%s", "CURRENT TEST: ", number_tc, "\n");
  number_tc++;

  SRunner *sr = srunner_create(tc);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);

  srunner_free(sr);
}

void run_tests(void) {
  Suite *list[] = {suite_add(),
                   suite_div(),
                   suite_floor(),
                   suite_decimal_to_float(),
                   suite_decimal_to_int(),
                   suite_float_to_decimal(),
                   suite_int_to_decimal(),
                   suite_is_equal(),
                   suite_is_greater_or_equal(),
                   suite_is_greater(),
                   suite_is_less_or_equal(),
                   suite_is_less(),
                   suite_is_not_equal(),
                   suite_mul(),
                   suite_negate(),
                   suite_round(),
                   suite_sub(),
                   suite_truncate(),
                   NULL};

  for (Suite **current = list; *current != NULL; current++) {
    run_one_test(*current);
  }
}
