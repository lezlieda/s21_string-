#include "../s21_string.h"
#include "../suitecases.h"

START_TEST(s21_memset_1) {
  char str[64] = "Lorem ipsum";
  ck_assert_str_eq(memset(str, 'a', 63), s21_memset(str, 'a', 63));
}
END_TEST

START_TEST(s21_memset_2) {
  char str[64] = "Lorem ipsum";
  ck_assert_str_eq(memset(str, 'a', 6), s21_memset(str, 'a', 6));
}
END_TEST

// START_TEST(s21_memset_3) {
//   char str[64] = "Lorem ipsum";
//   ck_assert_str_eq(memset(str, 'a', 0), s21_memset(str, 'a', 0));
// }
// END_TEST
// warning: memset() called to fill 0 bytes. [memsetZeroBytes]

START_TEST(s21_memset_4) {
  char str[64] = "\0";
  ck_assert_str_eq(memset(str, 'a', 63), s21_memset(str, 'a', 63));
}
END_TEST

START_TEST(s21_memset_5) {
  char str[64] = "\0";
  ck_assert_str_eq(memset(str, 'a', 6), s21_memset(str, 'a', 6));
}
END_TEST

// START_TEST(s21_memset_6) {
//   char str[64] = "\0";
//   ck_assert_str_eq(memset(str, 'a', 0), s21_memset(str, 'a', 0));
// }
// END_TEST
// warning: memset() called to fill 0 bytes. [memsetZeroBytes]

START_TEST(s21_memset_7) {
  char str[64] = "Lorem ipsum";
  ck_assert_str_eq(memset(str, '\0', 63), s21_memset(str, '\0', 63));
}
END_TEST

START_TEST(s21_memset_8) {
  char str[64] = "Lorem ipsum";
  ck_assert_str_eq(memset(str, '\0', 6), s21_memset(str, '\0', 6));
}
END_TEST

// START_TEST(s21_memset_9) {
//   char str[64] = "Lorem ipsum";
//   ck_assert_str_eq(memset(str, '\0', 0), s21_memset(str, '\0', 0));
// }
// END_TEST
// warning: memset() called to fill 0 bytes. [memsetZeroBytes]

START_TEST(s21_memset_10) {
  char str[64] = "\0";
  ck_assert_str_eq(memset(str, '\0', 63), s21_memset(str, '\0', 63));
}
END_TEST

START_TEST(s21_memset_11) {
  char str[64] = "\0";
  ck_assert_str_eq(memset(str, '\0', 6), s21_memset(str, '\0', 6));
}
END_TEST

// START_TEST(s21_memset_12) {
//   char str[64] = "\0";
//   ck_assert_str_eq(memset(str, '\0', 0), s21_memset(str, '\0', 0));
// }
// END_TEST
// warning: memset() called to fill 0 bytes. [memsetZeroBytes]

Suite *suite_s21_memset() {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_memset");
  tc_core = tcase_create("case_s21_memset");

  tcase_add_test(tc_core, s21_memset_1);
  tcase_add_test(tc_core, s21_memset_2);
  // tcase_add_test(tc_core, s21_memset_3);
  tcase_add_test(tc_core, s21_memset_4);
  tcase_add_test(tc_core, s21_memset_5);
  // tcase_add_test(tc_core, s21_memset_6);
  tcase_add_test(tc_core, s21_memset_7);
  tcase_add_test(tc_core, s21_memset_8);
  // tcase_add_test(tc_core, s21_memset_9);
  tcase_add_test(tc_core, s21_memset_10);
  tcase_add_test(tc_core, s21_memset_11);
  // tcase_add_test(tc_core, s21_memset_12);

  suite_add_tcase(s, tc_core);

  return s;
}
