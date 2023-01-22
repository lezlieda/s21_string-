#include "../s21_string.h"
#include "../suitecases.h"

START_TEST(s21_memcmp_1) {
  char *s1 = "Lorem ipsum dolor sit amet";
  char *s2 = "Lorem ipsum dolor sit amet";
  ck_assert_int_eq(memcmp(s1, s2, 27), s21_memcmp(s1, s2, 27));
}
END_TEST

START_TEST(s21_memcmp_2) {
  char *s1 = "Lorem ipsum dolor sit amet";
  char *s2 = "Lorem ipsum";
  ck_assert_int_eq(memcmp(s1, s2, 27), s21_memcmp(s1, s2, 27));
}
END_TEST

START_TEST(s21_memcmp_3) {
  char *s1 = "Lorem ipsum";
  char *s2 = "Lorem ipsum dolor sit amet";
  ck_assert_int_eq(memcmp(s1, s2, 14), s21_memcmp(s1, s2, 14));
}
END_TEST

START_TEST(s21_memcmp_4) {
  char *s1 = "Lorem ipsum dolor sit amet";
  char *s2 = "\0";
  ck_assert_int_eq(memcmp(s1, s2, 6), s21_memcmp(s1, s2, 6));
}
END_TEST

START_TEST(s21_memcmp_5) {
  char *s1 = "\0";
  char *s2 = "Lorem ipsum dolor sit amet";
  ck_assert_int_eq(memcmp(s1, s2, 6), s21_memcmp(s1, s2, 6));
}
END_TEST

START_TEST(s21_memcmp_6) {
  char *s1 = "\0";
  char *s2 = "\0";
  ck_assert_int_eq(memcmp(s1, s2, 6), s21_memcmp(s1, s2, 6));
}
END_TEST

START_TEST(s21_memcmp_7) {
  char *s1 = "Lorem ipsum dolor sit amet";
  char *s2 = "Lorem ipsum dolor sit amet";
  ck_assert_int_eq(memcmp(s1, s2, 0), s21_memcmp(s1, s2, 0));
}
END_TEST

START_TEST(s21_memcmp_8) {
  char *s1 = "Lorem ipsum dolor sit amet";
  char *s2 = "consectetur adipiscing elit";
  ck_assert_int_eq(memcmp(s1, s2, 1), s21_memcmp(s1, s2, 1));
}
END_TEST

START_TEST(s21_memcmp_9) {
  char *s1 = NULL;
  char *s2 = "consectetur adipiscing elit";
  ck_assert_int_eq(s21_memcmp(s1, s2, 2), s21_memcmp(s1, s2, 2));
}
END_TEST

Suite *suite_s21_memcmp() {
  Suite *s;
  TCase *tc_case;

  s = suite_create("s21_memcmp");

  tc_case = tcase_create("case_s21_memcmp");

  tcase_add_test(tc_case, s21_memcmp_1);
  tcase_add_test(tc_case, s21_memcmp_2);
  tcase_add_test(tc_case, s21_memcmp_3);
  tcase_add_test(tc_case, s21_memcmp_4);
  tcase_add_test(tc_case, s21_memcmp_5);
  tcase_add_test(tc_case, s21_memcmp_6);
  tcase_add_test(tc_case, s21_memcmp_7);
  tcase_add_test(tc_case, s21_memcmp_8);
  tcase_add_test(tc_case, s21_memcmp_9);

  suite_add_tcase(s, tc_case);

  return s;
}
