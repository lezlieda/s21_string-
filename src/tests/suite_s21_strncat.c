#include "../s21_string.h"
#include "../suitecases.h"

START_TEST(s21_strncat_1) {
  char dest[32] = "Lorem ipsum";
  char src[32] = " dolor sit amet";
  ck_assert_str_eq(strncat(dest, src, 5), s21_strncat(dest, src, 5));
}
END_TEST

START_TEST(s21_strncat_2) {
  char dest[32] = "Lorem ipsum";
  char src[32] = " dolor sit amet";
  ck_assert_str_eq(strncat(dest, src, 0), s21_strncat(dest, src, 0));
}
END_TEST

START_TEST(s21_strncat_3) {
  char dest[64] = "Lorem ipsum";
  char src[32] = " dolor sit amet";
  ck_assert_str_eq(strncat(dest, src, 32), s21_strncat(dest, src, 32));
}
END_TEST

START_TEST(s21_strncat_4) {
  char dest[32] = "\0";
  char src[32] = " dolor sit amet";
  ck_assert_str_eq(strncat(dest, src, 1), s21_strncat(dest, src, 1));
}
END_TEST

START_TEST(s21_strncat_5) {
  char dest[32] = "Lorem ipsum";
  char src[32] = "\0";
  ck_assert_str_eq(strncat(dest, src, 1), s21_strncat(dest, src, 1));
}
END_TEST

Suite *suite_s21_strncat() {
  Suite *suite = suite_create("s21_strncat");
  TCase *tcase = tcase_create("case_s21_strncat");

  tcase_add_test(tcase, s21_strncat_1);
  tcase_add_test(tcase, s21_strncat_2);
  tcase_add_test(tcase, s21_strncat_3);
  tcase_add_test(tcase, s21_strncat_4);
  tcase_add_test(tcase, s21_strncat_5);

  suite_add_tcase(suite, tcase);
  return suite;
}
