#include "../s21_string.h"
#include "../suitecases.h"

START_TEST(s21_strncmp_1) {
  char str1[64] = "Lorem ipsum";
  char str2[64] = "Lorem ipsum";
  ck_assert_int_eq(strncmp(str1, str2, 64), s21_strncmp(str1, str2, 64));
}
END_TEST

START_TEST(s21_strncmp_2) {
  char str1[64] = "Lorem ipsum";
  char str2[64] = "Lorem ipsum";
  ck_assert_int_eq(strncmp(str1, str2, 6), s21_strncmp(str1, str2, 6));
}
END_TEST

START_TEST(s21_strncmp_3) {
  char str1[64] = "Lorem ipsum";
  char str2[64] = "Lorem ipsum";
  ck_assert_int_eq(strncmp(str1, str2, 0), s21_strncmp(str1, str2, 0));
}
END_TEST

START_TEST(s21_strncmp_4) {
  char str1[64] = "\0";
  char str2[64] = "\0";
  ck_assert_int_eq(strncmp(str1, str2, 64), s21_strncmp(str1, str2, 64));
}
END_TEST

START_TEST(s21_strncmp_5) {
  char str1[64] = "\0";
  char str2[64] = "\0";
  ck_assert_int_eq(strncmp(str1, str2, 6), s21_strncmp(str1, str2, 6));
}
END_TEST

START_TEST(s21_strncmp_6) {
  char str1[64] = "\0";
  char str2[64] = "\0";
  ck_assert_int_eq(strncmp(str1, str2, 0), s21_strncmp(str1, str2, 0));
}
END_TEST

START_TEST(s21_strncmp_7) {
  char str1[64] = "Lorem ipsum";
  char str2[64] = "Lorem dorem";
  ck_assert_int_eq(strncmp(str1, str2, 64), s21_strncmp(str1, str2, 64));
}
END_TEST

START_TEST(s21_strncmp_8) {
  char str1[64] = "Lorem ipsum";
  char str2[64] = "Lorem dorem";
  ck_assert_int_eq(strncmp(str1, str2, 6), s21_strncmp(str1, str2, 6));
}
END_TEST

START_TEST(s21_strncmp_9) {
  char str1[64] = "Lorem ipsum";
  char str2[64] = "Lorem dorem";
  ck_assert_int_eq(strncmp(str1, str2, 0), s21_strncmp(str1, str2, 0));
}
END_TEST

START_TEST(s21_strncmp_10) {
  char str1[64] = "\0";
  char str2[64] = "Lorem dorem";
  ck_assert_int_eq(strncmp(str1, str2, 5), s21_strncmp(str1, str2, 5));
}
END_TEST

START_TEST(s21_strncmp_11) {
  char str1[64] = "Lorem ipsum";
  char str2[64] = "\0";
  ck_assert_int_eq(strncmp(str1, str2, 5), s21_strncmp(str1, str2, 5));
}
END_TEST

Suite *suite_s21_strncmp() {
  Suite *suite;
  TCase *tcase;

  suite = suite_create("s21_strncmp");
  tcase = tcase_create("case_s21_strncmp");

  tcase_add_test(tcase, s21_strncmp_1);
  tcase_add_test(tcase, s21_strncmp_2);
  tcase_add_test(tcase, s21_strncmp_3);
  tcase_add_test(tcase, s21_strncmp_4);
  tcase_add_test(tcase, s21_strncmp_5);
  tcase_add_test(tcase, s21_strncmp_6);
  tcase_add_test(tcase, s21_strncmp_7);
  tcase_add_test(tcase, s21_strncmp_8);
  tcase_add_test(tcase, s21_strncmp_9);
  tcase_add_test(tcase, s21_strncmp_10);
  tcase_add_test(tcase, s21_strncmp_11);

  suite_add_tcase(suite, tcase);

  return suite;
}