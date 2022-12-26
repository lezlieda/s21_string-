#include "../s21_string.h"
#include "../suitecases.h"

START_TEST(s21_strcmp_1) {
  char *s1 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do";
  char *s2 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do";
  ck_assert_int_eq(strcmp(s1, s2), s21_strcmp(s1, s2));
}
END_TEST

START_TEST(s21_strcmp_2) {
  char *s1 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit";
  char *s2 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do";
  ck_assert_int_eq(strcmp(s1, s2), s21_strcmp(s1, s2));
}
END_TEST

START_TEST(s21_strcmp_3) {
  char *s1 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do";
  char *s2 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit";
  ck_assert_int_eq(strcmp(s1, s2), s21_strcmp(s1, s2));
}
END_TEST

START_TEST(s21_strcmp_4) {
  char *s1 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do";
  char *s2 = "\0";
  ck_assert_int_eq(strcmp(s1, s2), s21_strcmp(s1, s2));
}
END_TEST

START_TEST(s21_strcmp_5) {
  char *s1 = "\0";
  char *s2 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do";
  ck_assert_int_eq(strcmp(s1, s2), s21_strcmp(s1, s2));
}
END_TEST

START_TEST(s21_strcmp_6) {
  char *s1 = "\0";
  char *s2 = "\0";
  ck_assert_int_eq(strcmp(s1, s2), s21_strcmp(s1, s2));
}
END_TEST

Suite *suite_s21_strcmp() {
  Suite *s;
  TCase *tc_case;

  s = suite_create("s21_strcmp");

  tc_case = tcase_create("case_s21_strcmp");

  tcase_add_test(tc_case, s21_strcmp_1);
  tcase_add_test(tc_case, s21_strcmp_2);
  tcase_add_test(tc_case, s21_strcmp_3);
  tcase_add_test(tc_case, s21_strcmp_4);
  tcase_add_test(tc_case, s21_strcmp_5);
  tcase_add_test(tc_case, s21_strcmp_6);

  suite_add_tcase(s, tc_case);

  return s;
}
