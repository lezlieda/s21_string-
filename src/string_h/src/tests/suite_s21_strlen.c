#include "../s21_string.h"
#include "../suitecases.h"

START_TEST(s21_strlen_1) {
  char *str = "Lorem ipsum dolor sit amet";
  ck_assert_msg(s21_strlen(str) == strlen(str),
                "s21_strlen(%s) = %ld, strlen(%s) = %ld", str, s21_strlen(str),
                str, strlen(str));
}
END_TEST

START_TEST(s21_strlen_2) {
  char *str = "L\0";
  ck_assert_msg(s21_strlen(str) == strlen(str),
                "s21_strlen(%s) = %ld, strlen(%s) = %ld", str, s21_strlen(str),
                str, strlen(str));
}
END_TEST

START_TEST(s21_strlen_3) {
  char *str = "\0";
  ck_assert_msg(s21_strlen(str) == strlen(str),
                "s21_strlen(%s) = %ld, strlen(%s) = %ld", str, s21_strlen(str),
                str, strlen(str));
}
END_TEST

Suite *suite_s21_strlen() {
  Suite *s = suite_create("s21_strlen");
  TCase *tc_case = tcase_create("case_s21_strlen");

  tcase_add_test(tc_case, s21_strlen_1);
  tcase_add_test(tc_case, s21_strlen_2);
  tcase_add_test(tc_case, s21_strlen_3);

  suite_add_tcase(s, tc_case);

  return s;
}
