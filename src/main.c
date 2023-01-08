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
  for (int i = 24; list_cases[i] != NULL; i++) {
    run_testcase(list_cases[i]);
  }
}

int main() {
  run_all_testcases();

  // wchar_t c[] = {0, 12, 122, 255, 256, 1023, 2047, 2048, 8193, 65536, 65577};
  // char dest[100];
  // char s21_dest[100];
  // const char *format = "aa bb %lc cc";
  // for (int i = 0; i < 11; i++) {
  //   int s = sprintf(dest, format, c[i]);
  //   int s21 = s21_sprintf(s21_dest, format, c[i]);
  //   printf("c = %lc = %d, s = %d, s21 = %d\n", c[i], c[i], s, s21);
  //   printf("    dest = %s\ns21_dest = %s\n", dest, s21_dest);
  // }

  return 0;
}
