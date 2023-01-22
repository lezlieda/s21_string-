#include "../s21_string.h"
#include "../suitecases.h"

START_TEST(s21_insert_1) {
  const char *src = "Hello, world!";
  const char *str = "my ";
  char *res = s21_insert(src, str, 0);
  ck_assert_str_eq(res, "my Hello, world!");
  if (res != NULL) free(res);
}
END_TEST

START_TEST(s21_insert_2) {
  const char *src = "Hello, world!";
  const char *str = "my ";
  char *res = s21_insert(src, str, 7);
  ck_assert_str_eq(res, "Hello, my world!");
  if (res != NULL) free(res);
}
END_TEST

START_TEST(s21_insert_3) {
  const char *src = "Hello, world!";
  const char *str = "my ";
  char *res = s21_insert(src, str, 13);
  ck_assert_str_eq(res, "Hello, world!my ");
  if (res != NULL) free(res);
}
END_TEST

START_TEST(s21_insert_4) {
  const char *src = "Hello, world!";
  const char *str = "my ";
  char *res = s21_insert(src, str, 144);
  ck_assert_ptr_null(res);
  if (res != NULL) free(res);
}
END_TEST

START_TEST(s21_insert_5) {
  const char *src = "Hello, world!";
  const char *str = NULL;
  char *res = s21_insert(src, str, 2);
  ck_assert_ptr_null(res);
  if (res != NULL) free(res);
}
END_TEST

START_TEST(s21_insert_6) {
  const char *src = NULL;
  const char *str = "my ";
  char *res = s21_insert(src, str, 2);
  ck_assert_ptr_null(res);
  if (res != NULL) free(res);
}
END_TEST

Suite *suite_s21_insert() {
  Suite *suite = suite_create("s21_insert");
  TCase *tcase = tcase_create("case_s21_insert");

  tcase_add_test(tcase, s21_insert_1);
  tcase_add_test(tcase, s21_insert_2);
  tcase_add_test(tcase, s21_insert_3);
  tcase_add_test(tcase, s21_insert_4);
  tcase_add_test(tcase, s21_insert_5);
  tcase_add_test(tcase, s21_insert_6);

  suite_add_tcase(suite, tcase);
  return suite;
}
