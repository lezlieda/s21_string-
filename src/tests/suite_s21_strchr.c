#include "../s21_string.h"
#include "../suitecases.h"

START_TEST(s21_strchr_1) {
  char str[64] = "Lorem ipsum dolor sit amet";
  ck_assert_str_eq(strchr(str, 'L'), s21_strchr(str, 'L'));
}
END_TEST

START_TEST(s21_strchr_2) {
  char str[64] = "Lorem ipsum dolor sit amet";
  ck_assert_str_eq(strchr(str, 'm'), s21_strchr(str, 'm'));
}
END_TEST

START_TEST(s21_strchr_3) {
  char str[64] = "Lorem ipsum dolor sit amet";
  ck_assert_str_eq(strchr(str, 't'), s21_strchr(str, 't'));
}
END_TEST

START_TEST(s21_strchr_4) {
  char str[64] = "Lorem ipsum dolor sit amet";
  ck_assert_ptr_null(strchr(str, 'z'));
  ck_assert_ptr_null(s21_strchr(str, 'z'));
}
END_TEST

START_TEST(s21_strchr_5) {
  char str[64] = "Lorem ipsum dolor sit amet";
  ck_assert_str_eq(strchr(str, '\0'), s21_strchr(str, '\0'));
}
END_TEST

START_TEST(s21_strchr_6) {
  char str[64] = "\0";
  ck_assert_ptr_null(strchr(str, 'L'));
  ck_assert_ptr_null(s21_strchr(str, 'L'));
}
END_TEST

START_TEST(s21_strchr_7) {
  char str[64] = "\0";
  ck_assert_str_eq(strchr(str, '\0'), s21_strchr(str, '\0'));
}
END_TEST

START_TEST(s21_strchr_8) {
  char str[64] = "";
  ck_assert_ptr_null(strchr(str, 'x'));
  ck_assert_ptr_null(s21_strchr(str, 'x'));
}
END_TEST

Suite *suite_s21_strchr() {
  Suite *s;
  TCase *tc_case;

  s = suite_create("s21_strchr");

  /* Core test case */
  tc_case = tcase_create("case_s21_strchr");

  tcase_add_test(tc_case, s21_strchr_1);
  tcase_add_test(tc_case, s21_strchr_2);
  tcase_add_test(tc_case, s21_strchr_3);
  tcase_add_test(tc_case, s21_strchr_4);
  tcase_add_test(tc_case, s21_strchr_5);
  tcase_add_test(tc_case, s21_strchr_6);
  tcase_add_test(tc_case, s21_strchr_7);
  tcase_add_test(tc_case, s21_strchr_8);

  suite_add_tcase(s, tc_case);

  return s;
}
