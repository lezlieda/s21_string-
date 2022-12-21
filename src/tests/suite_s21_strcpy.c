#include "../s21_string.h"
#include "../suitecases.h"

START_TEST(s21_strcpy_1) {
  char src[64] = "Lorem ipsum dolor sit amet";
  char dest[64] = "\0";
  char s21_dest[64] = "\0";
  ck_assert_str_eq(strcpy(dest, src), s21_strcpy(s21_dest, src));
}
END_TEST

START_TEST(s21_strcpy_2) {
  char src[64] = "Lorem ipsum ";
  char dest[64] = "dolor sit amet";
  char s21_dest[64] = "dolor sit amet";
  ck_assert_str_eq(strcpy(dest, src), s21_strcpy(s21_dest, src));
}
END_TEST

START_TEST(s21_strcpy_3) {
  char src[64] = "\0";
  char dest[64] = "dolor sit amet";
  char s21_dest[64] = "dolor sit amet";
  ck_assert_str_eq(strcpy(dest, src), s21_strcpy(s21_dest, src));
}
END_TEST

START_TEST(s21_strcpy_4) {
  char src[64] = "\0";
  char dest[64] = "\0";
  char s21_dest[64] = "\0";
  ck_assert_str_eq(strcpy(dest, src), s21_strcpy(s21_dest, src));
}
END_TEST

Suite *suite_s21_strcpy() {
  Suite *s = suite_create("s21_strcpy");
  TCase *tc_case = tcase_create("case_s21_strcpy");

  tcase_add_test(tc_case, s21_strcpy_1);
  tcase_add_test(tc_case, s21_strcpy_2);
  tcase_add_test(tc_case, s21_strcpy_3);
  tcase_add_test(tc_case, s21_strcpy_4);

  suite_add_tcase(s, tc_case);

  return s;
}