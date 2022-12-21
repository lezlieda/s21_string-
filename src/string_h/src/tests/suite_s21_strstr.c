#include "../s21_string.h"
#include "../suitecases.h"

START_TEST(s21_strstr_1) {
  char *str = "Lorem ipsum dolor sit amet";
  char *substr = "Lorem";
  ck_assert_pstr_eq(strstr(str, substr), s21_strstr(str, substr));
}
END_TEST

START_TEST(s21_strstr_2) {
  char *str = "Lorem ipsum dolor sit amet";
  char *substr = "dolor";
  ck_assert_pstr_eq(strstr(str, substr), s21_strstr(str, substr));
}
END_TEST

START_TEST(s21_strstr_3) {
  char *str = "Lorem ipsum dolor sit amet";
  char *substr = "amet";
  ck_assert_pstr_eq(strstr(str, substr), s21_strstr(str, substr));
}
END_TEST

START_TEST(s21_strstr_4) {
  char *str = "Lorem ipsum dolor sit amet";
  char *substr = "Loled";
  ck_assert_pstr_eq(strstr(str, substr), s21_strstr(str, substr));
}
END_TEST

START_TEST(s21_strstr_5) {
  char *str = "Lorem ipsum dolor sit amet";
  char *substr = "\0";
  ck_assert_pstr_eq(strstr(str, substr), s21_strstr(str, substr));
}
END_TEST

START_TEST(s21_strstr_6) {
  char *str = "Lorem ipsum dolor sit amet";
  char *substr = "Lorem ipsum dolor sit amet";
  ck_assert_pstr_eq(strstr(str, substr), s21_strstr(str, substr));
}
END_TEST

START_TEST(s21_strstr_7) {
  char *str = "Lorem ipsum dolor sit amet";
  char *substr = "Lorem ipsum dolor sit amet\0";
  ck_assert_pstr_eq(strstr(str, substr), s21_strstr(str, substr));
}
END_TEST

START_TEST(s21_strstr_8) {
  char *str = "\0";
  char *substr = "Lorem ipsum";
  ck_assert_pstr_eq(strstr(str, substr), s21_strstr(str, substr));
}
END_TEST

Suite *suite_s21_strstr() {
  Suite *s;
  TCase *tc_case;

  s = suite_create("s21_strstr");

  /* Core test case */
  tc_case = tcase_create("case_s21_strstr");

  tcase_add_test(tc_case, s21_strstr_1);
  tcase_add_test(tc_case, s21_strstr_2);
  tcase_add_test(tc_case, s21_strstr_3);
  tcase_add_test(tc_case, s21_strstr_4);
  tcase_add_test(tc_case, s21_strstr_5);
  tcase_add_test(tc_case, s21_strstr_6);
  tcase_add_test(tc_case, s21_strstr_7);
  tcase_add_test(tc_case, s21_strstr_8);

  suite_add_tcase(s, tc_case);

  return s;
}
