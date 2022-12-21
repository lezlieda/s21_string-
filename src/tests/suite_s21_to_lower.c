#include "../s21_string.h"
#include "../suitecases.h"

START_TEST(s21_to_lower_1) {
  const char str[] = "LoReM iPsUm dOlOr SiT AmEt";
  char res[] = "lorem ipsum dolor sit amet";
  char *p = s21_to_lower(str);
  ck_assert_str_eq(p, res);
  if (p != NULL) free(p);
}
END_TEST

START_TEST(s21_to_lower_2) {
  const char str[] = "lorem ipsum dolor sit amet";
  char res[] = "lorem ipsum dolor sit amet";
  char *p = s21_to_lower(str);
  ck_assert_str_eq(p, res);
  if (p != NULL) free(p);
}
END_TEST

START_TEST(s21_to_lower_3) {
  const char str[] = "359";
  char res[] = "359";
  char *p = s21_to_lower(str);
  ck_assert_str_eq(p, res);
  if (p != NULL) free(p);
}
END_TEST

START_TEST(s21_to_lower_4) {
  const char str[] = "\0";
  char res[] = "\0";
  char *p = s21_to_lower(str);
  ck_assert_str_eq(p, res);
  if (p != NULL) free(p);
}
END_TEST

START_TEST(s21_to_lower_5) {
  const char *str = NULL;
  char *p = s21_to_lower(str);
  ck_assert_ptr_null(p);
  if (p != NULL) free(p);
}
END_TEST

Suite *suite_s21_to_lower() {
  Suite *suite = suite_create("s21_to_lower");
  TCase *tcase = tcase_create("case_s21_to_lower");

  tcase_add_test(tcase, s21_to_lower_1);
  tcase_add_test(tcase, s21_to_lower_2);
  tcase_add_test(tcase, s21_to_lower_3);
  tcase_add_test(tcase, s21_to_lower_4);
  tcase_add_test(tcase, s21_to_lower_5);

  suite_add_tcase(suite, tcase);
  return suite;
}
