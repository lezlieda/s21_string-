#include "../s21_string.h"
#include "../suitecases.h"

START_TEST(s21_trim_1) {
  char *src = "Hello, world!";
  char *trim_chars = "H";
  char *res = s21_trim(src, trim_chars);
  ck_assert_str_eq(res, "ello, world!");
  if (res != NULL) free(res);
}
END_TEST

START_TEST(s21_trim_2) {
  char *src = "Hello, world!";
  char *trim_chars = "!d";
  char *res = s21_trim(src, trim_chars);
  ck_assert_str_eq(res, "Hello, worl");
  if (res != NULL) free(res);
}
END_TEST

START_TEST(s21_trim_3) {
  char *src = "Hello, world!";
  char *trim_chars = "H!";
  char *res = s21_trim(src, trim_chars);
  ck_assert_str_eq(res, "ello, world");
  if (res != NULL) free(res);
}
END_TEST

START_TEST(s21_trim_4) {
  char *src = "Hello, world!";
  char *trim_chars = "H!d";
  char *res = s21_trim(src, trim_chars);
  ck_assert_str_eq(res, "ello, worl");
  if (res != NULL) free(res);
}
END_TEST

START_TEST(s21_trim_5) {
  char *src = "Hello, world!";
  char *trim_chars = "359z";
  char *res = s21_trim(src, trim_chars);
  ck_assert_str_eq(res, "Hello, world!");
  if (res != NULL) free(res);
}
END_TEST

START_TEST(s21_trim_6) {
  char *src = "Hello, world!";
  char *trim_chars = NULL;
  char *res = s21_trim(src, trim_chars);
  ck_assert_ptr_null(res);
  if (res != NULL) free(res);
}
END_TEST

START_TEST(s21_trim_7) {
  char *src = NULL;
  char *trim_chars = "H";
  char *res = s21_trim(src, trim_chars);
  ck_assert_ptr_null(res);
  if (res != NULL) free(res);
}
END_TEST

START_TEST(s21_trim_8) {
  char *src = NULL;
  char *trim_chars = NULL;
  char *res = s21_trim(src, trim_chars);
  ck_assert_ptr_null(res);
  if (res != NULL) free(res);
}
END_TEST

START_TEST(s21_trim_9) {
  char *src = "Hello, world!";
  char *trim_chars = "";
  char *res = s21_trim(src, trim_chars);
  ck_assert_str_eq(res, "Hello, world!");
  if (res != NULL) free(res);
}
END_TEST

Suite *suite_s21_trim() {
  Suite *suite = suite_create("s21_trim");
  TCase *tcase = tcase_create("case_s21_trim");

  tcase_add_test(tcase, s21_trim_1);
  tcase_add_test(tcase, s21_trim_2);
  tcase_add_test(tcase, s21_trim_3);
  tcase_add_test(tcase, s21_trim_4);
  tcase_add_test(tcase, s21_trim_5);
  tcase_add_test(tcase, s21_trim_6);
  tcase_add_test(tcase, s21_trim_7);
  tcase_add_test(tcase, s21_trim_8);
  tcase_add_test(tcase, s21_trim_9);

  suite_add_tcase(suite, tcase);
  return suite;
}
