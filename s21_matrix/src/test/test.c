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
  Suite *list[] = {
      suite_create_matrix(), suite_remove_matrix(), suite_sum(),
      suite_sub(),           suite_transpose(),     suite_equal(),
      suite_mult_number(),   suite_mult_matrix(),   suite_calc_complements(),
      suite_determinant(),   suite_inverse(),       NULL};

  for (Suite **current = list; *current != NULL; current++) {
    run_one_test(*current);
  }
}