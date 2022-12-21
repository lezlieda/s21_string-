#include "../s21_string.h"
#include "../suitecases.h"

START_TEST(s21_memcpy_1) {
  const char src[64] = "Lorem ipsum dolor sit amet";
  char dest[64] = "\0";
  char s21_dest[64] = "\0";
  ck_assert_str_eq(memcpy(dest, src, 64), s21_memcpy(s21_dest, src, 64));
}
END_TEST

START_TEST(s21_memcpy_2) {
  const char src[64] = "Lorem ipsum dolor sit amet";
  char dest[64] = "\0";
  char s21_dest[64] = "\0";
  ck_assert_str_eq(memcpy(dest, src, 6), s21_memcpy(s21_dest, src, 6));
}
END_TEST

START_TEST(s21_memcpy_3) {
  const char src[64] = "Lorem ipsum dolor sit amet";
  char dest[64] = "\0";
  char s21_dest[64] = "\0";
  ck_assert_str_eq(memcpy(dest, src, 0), s21_memcpy(s21_dest, src, 0));
}
END_TEST

START_TEST(s21_memcpy_4) {
  const char src[64] = "Lorem ipsum dolor sit amet";
  char dest[64] = "consectetur adipiscing elit";
  char s21_dest[64] = "consectetur adipiscing elit";
  ck_assert_str_eq(memcpy(dest, src, 64), s21_memcpy(s21_dest, src, 64));
}
END_TEST

START_TEST(s21_memcpy_5) {
  const char src[64] = "Lorem ipsum dolor sit amet";
  char dest[64] = "consectetur adipiscing elit";
  char s21_dest[64] = "consectetur adipiscing elit";
  ck_assert_str_eq(memcpy(dest, src, 6), s21_memcpy(s21_dest, src, 6));
}
END_TEST

START_TEST(s21_memcpy_6) {
  const char src[64] = "Lorem ipsum dolor sit amet";
  char dest[64] = "consectetur adipiscing elit";
  char s21_dest[64] = "consectetur adipiscing elit";
  ck_assert_str_eq(memcpy(dest, src, 0), s21_memcpy(s21_dest, src, 0));
}
END_TEST

START_TEST(s21_memcpy_7) {
  const char src[64] = "\0";
  char dest[64] = "\0";
  char s21_dest[64] = "\0";
  ck_assert_str_eq(memcpy(dest, src, 64), s21_memcpy(s21_dest, src, 64));
}
END_TEST

START_TEST(s21_memcpy_8) {
  const char src[64] = "\0";
  char dest[64] = "\0";
  char s21_dest[64] = "\0";
  ck_assert_str_eq(memcpy(dest, src, 0), s21_memcpy(s21_dest, src, 0));
}
END_TEST

START_TEST(s21_memcpy_9) {
  const char src[64] = "\0";
  char dest[64] = "consectetur adipiscing elit";
  char s21_dest[64] = "consectetur adipiscing elit";
  ck_assert_str_eq(memcpy(dest, src, 64), s21_memcpy(s21_dest, src, 64));
}
END_TEST

START_TEST(s21_memcpy_10) {
  const char src[64] = "\0";
  char dest[64] = "consectetur adipiscing elit";
  char s21_dest[64] = "consectetur adipiscing elit";
  ck_assert_str_eq(memcpy(dest, src, 0), s21_memcpy(s21_dest, src, 0));
}
END_TEST

Suite *suite_s21_memcpy() {
  Suite *s = suite_create("s21_memcpy");
  TCase *tc_case = tcase_create("case_s21_memcpy");

  tcase_add_test(tc_case, s21_memcpy_1);
  tcase_add_test(tc_case, s21_memcpy_2);
  tcase_add_test(tc_case, s21_memcpy_3);
  tcase_add_test(tc_case, s21_memcpy_4);
  tcase_add_test(tc_case, s21_memcpy_5);
  tcase_add_test(tc_case, s21_memcpy_6);
  tcase_add_test(tc_case, s21_memcpy_7);
  tcase_add_test(tc_case, s21_memcpy_8);
  tcase_add_test(tc_case, s21_memcpy_9);
  tcase_add_test(tc_case, s21_memcpy_10);

  suite_add_tcase(s, tc_case);

  return s;
}
