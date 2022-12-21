#include "../s21_string.h"
#include "../suitecases.h"

START_TEST(s21_strpbrk_1) {
  char str1[64] = "Lorem ipsum dolor sit amet";
  char str2[64] = "ai";
  ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_2) {
  char str1[64] = "Lorem ipsum dolor sit amet";
  char str2[64] = "Ll";
  ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_3) {
  char str1[64] = "Lorem ipsum dolor sit amet";
  char str2[64] = "tT";
  ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_4) {
  char str1[64] = "Lorem ipsum dolor sit amet";
  char str2[64] = "zZ";
  ck_assert_ptr_null(strpbrk(str1, str2));
  ck_assert_ptr_null(s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_5) {
  char str1[64] = "Lorem ipsum dolor sit amet";
  char str2[64] = "\0";
  ck_assert_ptr_null(strpbrk(str1, str2));
  ck_assert_ptr_null(s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_6) {
  char str1[64] = "\0";
  char str2[64] = "ai";
  ck_assert_ptr_null(strpbrk(str1, str2));
  ck_assert_ptr_null(s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_7) {
  char str1[64] = "\0";
  char str2[64] = "\0";
  ck_assert_ptr_null(strpbrk(str1, str2));
  ck_assert_ptr_null(s21_strpbrk(str1, str2));
}
END_TEST

Suite *suite_s21_strpbrk() {
  Suite *suite = suite_create("s21_strpbrk");
  TCase *tcase = tcase_create("case_21_strpbrk");

  tcase_add_test(tcase, s21_strpbrk_1);
  tcase_add_test(tcase, s21_strpbrk_2);
  tcase_add_test(tcase, s21_strpbrk_3);
  tcase_add_test(tcase, s21_strpbrk_4);
  tcase_add_test(tcase, s21_strpbrk_5);
  tcase_add_test(tcase, s21_strpbrk_6);
  tcase_add_test(tcase, s21_strpbrk_7);

  suite_add_tcase(suite, tcase);

  return suite;
}