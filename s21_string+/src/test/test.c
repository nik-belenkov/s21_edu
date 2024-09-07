
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
  Suite *list[] = {suite_memchr(),
                   suite_memcmp(),
                   suite_memcpy(),
                   suite_memset(),
                   suite_strncat(),
                   suite_strchr(),
                   suite_strncmp(),
                   suite_strncpy(),
                   suite_strcspn(),
                   suite_strerror(),
                   suite_strlen(),
                   suite_strpbrk(),
                   suite_to_upper(),
                   suite_strrchr(),
                   suite_strstr(),
                   suite_strtok(),
                   suite_to_lower(),
                   suite_insert(),
                   suite_trim(),
                   suite_insert(),
                   suite_sprintf(),
                   suite_sscanf(),
                   NULL};

  for (Suite **current = list; *current != NULL; current++) {
    run_one_test(*current);
  }
}
