#include "s21_string.h"
#include "suitecases.h"

void run_testcase(Suite *testcase) {
  SRunner *runner = srunner_create(testcase);
  srunner_run_all(runner, CK_NORMAL);
  srunner_free(runner);
}

void run_all_testcases() {
  Suite *list_cases[] = {
      suite_s21_memcpy(),   suite_s21_strcat(),   suite_s21_strchr(),
      s21_strcmp_suite(),   suite_s21_strcpy(),   suite_s21_strlen(),
      suite_s21_strstr(),   suite_s21_strtok(),   suite_s21_memchr(),
      suite_s21_to_upper(), suite_s21_to_lower(), suite_s21_insert(),
      suite_s21_trim(),     suite_s21_memcmp(),   suite_s21_memmove(),
      suite_s21_memset(),   suite_s21_strncmp(),  NULL};
  for (int i = 0; list_cases[i] != NULL; i++) {
    run_testcase(list_cases[i]);
  }
}

int main() {
  run_all_testcases();

  return 0;
}
