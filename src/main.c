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

  // long int ui[] = {-21474836121248, -161, 0, 1365, 3563456, 214748361147};
  // char dest[100];
  // char s21_dest[100];
  // const char *format = "aa bb % 0*.*li cc";
  // int width = 8;
  // int precision = 15;
  // for (int i = 0; i < 6; i++) {
  //   int s = sprintf(dest, format, width, precision, ui[i]);
  //   int s21 = s21_sprintf(s21_dest, format, width, precision, ui[i]);
  //   printf("ui = %li; s = %d; s21 = %d\n", ui[i], s, s21);
  //   printf("    dest = %s;\ns21_dest = %s\n", dest, s21_dest);
  // }

  // char dest[64] = "\0";
  // s21_sprintf_opt opt;
  // s21_sprintf_opt_init(&opt);
  // opt.width = 10;
  // opt.precision = 5;
  // opt.fl_plus = 0;
  // opt.fl_minus = 0;
  // int n = -10;
  // s21_sprinter_int(dest, opt, n);
  // printf("  n: %s\n", dest);

  // char s21_dest[64] = "\0";
  // s21_sprintf(s21_dest, "%*.*i", opt.width, opt.precision, n);
  // printf("s21: %s\n", s21_dest);

  // char sprintf_dest[64] = "\0";
  // sprintf(sprintf_dest, "%*.*i", opt.width, opt.precision, n);
  // printf(" sp: %s\n", sprintf_dest);

  return 0;
}
