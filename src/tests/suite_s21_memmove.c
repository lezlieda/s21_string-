#include "../s21_string.h"
#include "../suitecases.h"

START_TEST(s21_memmove_1) {
  const char src[64] = "Lorem ipsum";
  char dest[64] = "\0";
  char s21_dest[64] = "\0";
  ck_assert_str_eq(memmove(dest, src, 64), s21_memmove(s21_dest, src, 64));
}
END_TEST

START_TEST(s21_memmove_2) {
  const char src[64] = "Lorem ipsum";
  char dest[64] = "\0";
  char s21_dest[64] = "\0";
  ck_assert_str_eq(memmove(dest, src, 6), s21_memmove(s21_dest, src, 6));
}
END_TEST

START_TEST(s21_memmove_3) {
  const char src[64] = "Lorem ipsum";
  char dest[64] = "\0";
  char s21_dest[64] = "\0";
  ck_assert_str_eq(memmove(dest, src, 0), s21_memmove(s21_dest, src, 0));
}
END_TEST

START_TEST(s21_memmove_4) {
  const char src[64] = "Lorem ipsum";
  char dest[64] = "dolor sit amet";
  char s21_dest[64] = "dolor sit amet";
  ck_assert_str_eq(memmove(dest, src, 64), s21_memmove(s21_dest, src, 64));
}
END_TEST

START_TEST(s21_memmove_5) {
  const char src[64] = "Lorem ipsum";
  char dest[64] = "dolor sit amet";
  char s21_dest[64] = "dolor sit amet";
  ck_assert_str_eq(memmove(dest, src, 6), s21_memmove(s21_dest, src, 6));
}
END_TEST

START_TEST(s21_memmove_6) {
  const char src[64] = "Lorem ipsum";
  char dest[64] = "dolor sit amet";
  char s21_dest[64] = "dolor sit amet";
  ck_assert_str_eq(memmove(dest, src, 0), s21_memmove(s21_dest, src, 0));
}
END_TEST

START_TEST(s21_memmove_7) {
  const char src[64] = "\0";
  char dest[64] = "\0";
  char s21_dest[64] = "\0";
  ck_assert_str_eq(memmove(dest, src, 64), s21_memmove(s21_dest, src, 64));
}
END_TEST

START_TEST(s21_memmove_8) {
  const char src[64] = "\0";
  char dest[64] = "\0";
  char s21_dest[64] = "\0";
  ck_assert_str_eq(memmove(dest, src, 0), s21_memmove(s21_dest, src, 0));
}
END_TEST

START_TEST(s21_memmove_9) {
  const char src[64] = "\0";
  char dest[64] = "dolor sit amet";
  char s21_dest[64] = "dolor sit amet";
  ck_assert_str_eq(memmove(dest, src, 64), s21_memmove(s21_dest, src, 64));
}
END_TEST

START_TEST(s21_memmove_10) {
  const char src[64] = "\0";
  char dest[64] = "dolor sit amet";
  char s21_dest[64] = "dolor sit amet";
  ck_assert_str_eq(memmove(dest, src, 0), s21_memmove(s21_dest, src, 0));
}
END_TEST

START_TEST(s21_memmove_11) {
  const char src[64] = "Lorem ipsum";
  char dest[16] = "\0";
  char s21_dest[16] = "\0";
  ck_assert_str_eq(memmove(dest, src, 12), s21_memmove(s21_dest, src, 12));
}
END_TEST

Suite *suite_s21_memmove() {
  Suite *s = suite_create("s21_memmove");
  TCase *tc_case = tcase_create("case_s21_memmove");

  tcase_add_test(tc_case, s21_memmove_1);
  tcase_add_test(tc_case, s21_memmove_2);
  tcase_add_test(tc_case, s21_memmove_3);
  tcase_add_test(tc_case, s21_memmove_4);
  tcase_add_test(tc_case, s21_memmove_5);
  tcase_add_test(tc_case, s21_memmove_6);
  tcase_add_test(tc_case, s21_memmove_7);
  tcase_add_test(tc_case, s21_memmove_8);
  tcase_add_test(tc_case, s21_memmove_9);
  tcase_add_test(tc_case, s21_memmove_10);
  tcase_add_test(tc_case, s21_memmove_11);

  suite_add_tcase(s, tc_case);

  return s;
}
