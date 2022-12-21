#include "../s21_string.h"
#include "../suitecases.h"

START_TEST(s21_strrchr_1) {
  char str[64] = "Lorem ipsum dolor sit amet";
  ck_assert_str_eq(strrchr(str, 'L'), s21_strrchr(str, 'L'));
}
END_TEST

START_TEST(s21_strrchr_2) {
  char str[64] = "Lorem ipsum dolor sit amet";
  ck_assert_str_eq(strrchr(str, 'm'), s21_strrchr(str, 'm'));
}
END_TEST

START_TEST(s21_strrchr_3) {
  char str[64] = "Lorem ipsum dolor sit amet";
  ck_assert_str_eq(strrchr(str, 't'), s21_strrchr(str, 't'));
}
END_TEST

START_TEST(s21_strrchr_4) {
  char str[64] = "Lorem ipsum dolor sit amet";
  ck_assert_ptr_null(strrchr(str, 'z'));
  ck_assert_ptr_null(s21_strrchr(str, 'z'));
}
END_TEST

START_TEST(s21_strrchr_5) {
  char str[64] = "Lorem ipsum dolor sit amet";
  ck_assert_str_eq(strrchr(str, '\0'), s21_strrchr(str, '\0'));
}
END_TEST

START_TEST(s21_strrchr_6) {
  char str[64] = "\0";
  ck_assert_ptr_null(strrchr(str, 'L'));
  ck_assert_ptr_null(s21_strrchr(str, 'L'));
}
END_TEST

START_TEST(s21_strrchr_7) {
  char str[64] = "\0";
  ck_assert_str_eq(strrchr(str, '\0'), s21_strrchr(str, '\0'));
}
END_TEST

START_TEST(s21_strrchr_8) {
  char str[64] = "";
  ck_assert_ptr_null(strrchr(str, 'x'));
  ck_assert_ptr_null(s21_strrchr(str, 'x'));
}
END_TEST

Suite *suite_s21_strrchr() {
  Suite *s;
  TCase *tc_case;

  s = suite_create("s21_strrchr");

  /* Core test case */
  tc_case = tcase_create("case_s21_strrchr");

  tcase_add_test(tc_case, s21_strrchr_1);
  tcase_add_test(tc_case, s21_strrchr_2);
  tcase_add_test(tc_case, s21_strrchr_3);
  tcase_add_test(tc_case, s21_strrchr_4);
  tcase_add_test(tc_case, s21_strrchr_5);
  tcase_add_test(tc_case, s21_strrchr_6);
  tcase_add_test(tc_case, s21_strrchr_7);
  tcase_add_test(tc_case, s21_strrchr_8);

  suite_add_tcase(s, tc_case);

  return s;
}
