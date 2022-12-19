#include "suitecases.h"

void run_testcase(Suite *testcase) {
  SRunner *runner = srunner_create(testcase);
  srunner_run_all(runner, CK_NORMAL);
  srunner_free(runner);
}

void run_all_testcases() {
  Suite *list_cases[] = {suite_s21_memcpy(), NULL};
  for (int i = 0; list_cases[i] != NULL; i++) {
    run_testcase(list_cases[i]);
  }
}

int main() {
  run_all_testcases();

  return 0;
}
