#include "../s21_string.h"
#include "../suitecases.h"

START_TEST(s21_to_upper_1) {
  const char str[] = "LoReM iPsUm dOlOr SiT AmEt";
  char res[] = "LOREM IPSUM DOLOR SIT AMET";
  char *p = s21_to_upper(str);
  ck_assert_str_eq(p, res);
  if (p != NULL) free(p);
}
END_TEST

START_TEST(s21_to_upper_2) {
  const char str[] = "LOREM IPSUM DOLOR SIT AMET";
  char res[] = "LOREM IPSUM DOLOR SIT AMET";
  char *p = s21_to_upper(str);
  ck_assert_str_eq(p, res);
  if (p != NULL) free(p);
}
END_TEST

START_TEST(s21_to_upper_3) {
  const char str[] = "359";
  char res[] = "359";
  char *p = s21_to_upper(str);
  ck_assert_str_eq(p, res);
  if (p != NULL) free(p);
}
END_TEST

START_TEST(s21_to_upper_4) {
  const char str[] = "\0";
  char res[] = "\0";
  char *p = s21_to_upper(str);
  ck_assert_str_eq(p, res);
  if (p != NULL) free(p);
}
END_TEST

START_TEST(s21_to_upper_5) {
  const char *str = NULL;
  char *p = s21_to_upper(str);
  ck_assert_ptr_null(p);
  if (p != NULL) free(p);
}
END_TEST

START_TEST(s21_to_upper_6) {
  const char str[] = "Lorem {ipsum} dolor sit amet";
  char res[] = "LOREM {IPSUM} DOLOR SIT AMET";
  char *p = s21_to_upper(str);
  ck_assert_str_eq(p, res);
  if (p != NULL) free(p);
}
END_TEST

Suite *suite_s21_to_upper() {
  Suite *suite = suite_create("s21_to_upper");
  TCase *tcase = tcase_create("case_s21_to_upper");

  tcase_add_test(tcase, s21_to_upper_1);
  tcase_add_test(tcase, s21_to_upper_2);
  tcase_add_test(tcase, s21_to_upper_3);
  tcase_add_test(tcase, s21_to_upper_4);
  tcase_add_test(tcase, s21_to_upper_5);
  tcase_add_test(tcase, s21_to_upper_6);

  suite_add_tcase(suite, tcase);
  return suite;
}
