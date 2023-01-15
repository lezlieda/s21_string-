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

  // int ui[] = {-2147483647, -10, 0, 1, 10, 2147483647};
  // char dest[100];
  // char s21_dest[100];
  // const char *format = "aa bb %*.*i cc";
  // int width[] = {0, 1, 4, 88};
  // int precision[] = {0, 1, 4, 16};
  // for (int i = 0; i < 6; i++) {
  //   for (int k = 0; k < 4; k++) {
  //     for (int j = 0; j < 4; j++) {
  //       int s = sprintf(dest, format, width[k], precision[j], ui[i]);
  //       int s21 = s21_sprintf(s21_dest, format, width[k], precision[j],
  //       ui[i]); printf("s = %d, s21 = %d\n", s, s21); printf("s = %d; dest =
  //       %s\n", s, dest); printf("s21_dest = %s\n", s21_dest);
  //     }
  //   }
  // }

  // printf("LDBL_MANT_DIG = %d\n", LDBL_MANT_DIG);
  // printf("LDBL_MIN_EXP = %d\n", LDBL_MIN_EXP);
  // printf("LDBL_MAX_EXP = %d\n", LDBL_MAX_EXP);
  // printf("(int)sizeof(long double) = %d\n", (int)sizeof(long double));

  return 0;
}

// 中国人民共国华