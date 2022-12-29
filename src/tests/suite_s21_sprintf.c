#include "../s21_string.h"
#include "../suitecases.h"

START_TEST(s21_isdigit_1) {
  char a = '$';
  ck_assert_int_eq(0, s21_is_digit(a));
}
END_TEST

START_TEST(s21_isdigit_2) {
  char a = '0';
  ck_assert_int_eq(1, s21_is_digit(a));
}
END_TEST

START_TEST(s21_isdigit_3) {
  char a = '4';
  ck_assert_int_eq(1, s21_is_digit(a));
}
END_TEST

START_TEST(s21_isdigit_4) {
  char a = '9';
  ck_assert_int_eq(1, s21_is_digit(a));
}
END_TEST

START_TEST(s21_isdigit_5) {
  char a = 'a';
  ck_assert_int_eq(0, s21_is_digit(a));
}
END_TEST

START_TEST(s21_atoi_1) {
  char *a = "123";
  ck_assert_int_eq(123, s21_atoi(a));
}
END_TEST

START_TEST(s21_atoi_2) {
  char *a = "0";
  ck_assert_int_eq(0, s21_atoi(a));
}
END_TEST

START_TEST(s21_atoi_3) {
  char *a = "123456789";
  ck_assert_int_eq(123456789, s21_atoi(a));
}
END_TEST

Suite *suite_s21_sprintf() {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_sprintf");

  /* Core test case */
  tc_core = tcase_create("case_s21_sprintf");

  tcase_add_test(tc_core, s21_isdigit_1);
  tcase_add_test(tc_core, s21_isdigit_2);
  tcase_add_test(tc_core, s21_isdigit_3);
  tcase_add_test(tc_core, s21_isdigit_4);
  tcase_add_test(tc_core, s21_isdigit_5);
  tcase_add_test(tc_core, s21_atoi_1);
  tcase_add_test(tc_core, s21_atoi_2);
  tcase_add_test(tc_core, s21_atoi_3);

  suite_add_tcase(s, tc_core);

  return s;
}