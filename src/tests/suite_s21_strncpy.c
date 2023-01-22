#include "../s21_string.h"
#include "../suitecases.h"

START_TEST(s21_strncpy_1) {
  char src[64] = "Lorem ipsum";
  char dest[64] = "\0";
  char s21_dest[64] = "\0";
  ck_assert_str_eq(strncpy(dest, src, 63), s21_strncpy(s21_dest, src, 63));
}
END_TEST

START_TEST(s21_strncpy_2) {
  char src[64] = "Lorem ipsum";
  char dest[64] = "\0";
  char s21_dest[64] = "\0";
  ck_assert_str_eq(strncpy(dest, src, 6), s21_strncpy(s21_dest, src, 6));
}
END_TEST

// START_TEST(s21_strncpy_3) {
//   char src[64] = "Lorem ipsum";
//   char dest[64] = "\0";
//   char s21_dest[64] = "\0";
//   ck_assert_str_eq(strncpy(dest, src, 0), s21_strncpy(s21_dest, src, 0));
// }
// END_TEST

START_TEST(s21_strncpy_4) {
  char src[64] = "Lorem ipsum";
  char dest[64] = "dolor sit amet";
  char s21_dest[64] = "dolor sit amet";
  ck_assert_str_eq(strncpy(dest, src, 63), s21_strncpy(s21_dest, src, 63));
}
END_TEST

START_TEST(s21_strncpy_5) {
  char src[64] = "Lorem ipsum";
  char dest[64] = "dolor sit amet";
  char s21_dest[64] = "dolor sit amet";
  ck_assert_str_eq(strncpy(dest, src, 6), s21_strncpy(s21_dest, src, 6));
}
END_TEST

// START_TEST(s21_strncpy_6) {
//   char src[64] = "Lorem ipsum";
//   char dest[64] = "dolor sit amet";
//   char s21_dest[64] = "dolor sit amet";
//   ck_assert_str_eq(strncpy(dest, src, 0), s21_strncpy(s21_dest, src, 0));
// }
// END_TEST

START_TEST(s21_strncpy_7) {
  char src[64] = "\0";
  char dest[64] = "\0";
  char s21_dest[64] = "\0";
  ck_assert_str_eq(strncpy(dest, src, 63), s21_strncpy(s21_dest, src, 63));
}
END_TEST

START_TEST(s21_strncpy_8) {
  char src[64] = "\0";
  char dest[64] = "\0";
  char s21_dest[64] = "\0";
  ck_assert_str_eq(strncpy(dest, src, 6), s21_strncpy(s21_dest, src, 6));
}
END_TEST

// START_TEST(s21_strncpy_9) {
//   char src[64] = "\0";
//   char dest[64] = "\0";
//   char s21_dest[64] = "\0";
//   ck_assert_str_eq(strncpy(dest, src, 0), s21_strncpy(s21_dest, src, 0));
// }
// END_TEST

START_TEST(s21_strncpy_10) {
  char src[64] = "\0";
  char dest[64] = "dolor sit amet";
  char s21_dest[64] = "dolor sit amet";
  ck_assert_str_eq(strncpy(dest, src, 63), s21_strncpy(s21_dest, src, 63));
}
END_TEST

START_TEST(s21_strncpy_11) {
  char src[64] = "\0";
  char dest[64] = "dolor sit amet";
  char s21_dest[64] = "dolor sit amet";
  ck_assert_str_eq(strncpy(dest, src, 6), s21_strncpy(s21_dest, src, 6));
}
END_TEST

// START_TEST(s21_strncpy_12) {
//   char src[64] = "\0";
//   char dest[64] = "dolor sit amet";
//   char s21_dest[64] = "dolor sit amet";
//   ck_assert_str_eq(strncpy(dest, src, 0), s21_strncpy(s21_dest, src, 0));
// }
// END_TEST

START_TEST(s21_strncpy_13) {
  char src[16] = "Lorem ipsum";
  char dest[16] = "\0";
  char s21_dest[16] = "\0";
  ck_assert_str_eq(strncpy(dest, src, 15), s21_strncpy(s21_dest, src, 15));
}
END_TEST

START_TEST(s21_strncpy_14) {
  char src[64] = "Lorem ipsum";
  char dest[16] = "\0";
  char s21_dest[16] = "\0";
  ck_assert_str_eq(strncpy(dest, src, 6), s21_strncpy(s21_dest, src, 6));
}
END_TEST

// START_TEST(s21_strncpy_15) {
//   char src[64] = "Lorem ipsum";
//   char dest[16] = "\0";
//   char s21_dest[16] = "\0";
//   ck_assert_str_eq(strncpy(dest, src, 0), s21_strncpy(s21_dest, src, 0));
// }
// END_TEST

// START_TEST(s21_strncpy_16) {
//   char src[64] = "Lorem ipsum";
//   char dest[4] = "\0";
//   char s21_dest[4] = "\0";
//   ck_assert_str_eq(strncpy(dest, src, 0), s21_strncpy(s21_dest, src, 0));
// }
// END_TEST

Suite *suite_s21_strncpy() {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_strncpy");
  tc_core = tcase_create("case_s21_strncpy");

  tcase_add_test(tc_core, s21_strncpy_1);
  tcase_add_test(tc_core, s21_strncpy_2);
  // tcase_add_test(tc_core, s21_strncpy_3);
  tcase_add_test(tc_core, s21_strncpy_4);
  tcase_add_test(tc_core, s21_strncpy_5);
  // tcase_add_test(tc_core, s21_strncpy_6);
  tcase_add_test(tc_core, s21_strncpy_7);
  tcase_add_test(tc_core, s21_strncpy_8);
  // tcase_add_test(tc_core, s21_strncpy_9);
  tcase_add_test(tc_core, s21_strncpy_10);
  tcase_add_test(tc_core, s21_strncpy_11);
  // tcase_add_test(tc_core, s21_strncpy_12);
  tcase_add_test(tc_core, s21_strncpy_13);
  tcase_add_test(tc_core, s21_strncpy_14);
  // tcase_add_test(tc_core, s21_strncpy_15);
  // tcase_add_test(tc_core, s21_strncpy_16);

  suite_add_tcase(s, tc_core);

  return s;
}
