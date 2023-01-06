#include "s21_string.h"
#include "suitecases.h"

void run_testcase(Suite *testcase) {
  SRunner *runner = srunner_create(testcase);
  srunner_run_all(runner, CK_NORMAL);
  srunner_free(runner);
}

void run_all_testcases() {
  Suite *list_cases[] = {suite_s21_memcpy(),   suite_s21_strcat(),
                         suite_s21_strchr(),   suite_s21_strcmp(),
                         suite_s21_strcpy(),   suite_s21_strlen(),
                         suite_s21_strstr(),   suite_s21_strtok(),
                         suite_s21_memchr(),   suite_s21_to_upper(),
                         suite_s21_to_lower(), suite_s21_insert(),
                         suite_s21_trim(),     suite_s21_memcmp(),
                         suite_s21_memmove(),  suite_s21_memset(),
                         suite_s21_strncmp(),  suite_s21_strncpy(),
                         suite_s21_strcspn(),  suite_s21_strncat(),
                         suite_s21_strspn(),   suite_s21_strrchr(),
                         suite_s21_strpbrk(),  suite_s21_strerror(),
                         suite_s21_sprintf(),  NULL};
  for (int i = 0; list_cases[i] != NULL; i++) {
    run_testcase(list_cases[i]);
  }
}

int main() {
  run_all_testcases();

  // long double d = 1234567.89L;
  // char dest[100];
  // char s21_dest[100];
  // int s = sprintf(dest, "aa bb %0+*.*Lf\ne\te", 24, 8, d);
  // int s21_s = s21_sprintf(s21_dest, "aa bb %0+*.*Lf\ne\te", 24, 8, d);

  // char dest[100];
  // char s21_dest[100];
  // int s = sprintf(dest, "aa bb %0*.*f cc", 15, 28, 1.234);
  // int s21_s = s21_sprintf(s21_dest, "aa bb %0*.*f cc", 15, 28, 1.234);

  // printf("    str = %s;     s = %d\n", dest, s);
  // printf("s21_str = %s; s21_s = %d\n", s21_dest, s21_s);

  return 0;
}
