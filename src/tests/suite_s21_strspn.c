#include "../s21_string.h"
#include "../suitecases.h"

START_TEST(s21_strspn_1) {
  ck_assert_int_eq(strspn("Lorem ipsum", "a"), s21_strspn("Lorem ipsum", "a"));
}
END_TEST

START_TEST(s21_strspn_2) {
  ck_assert_int_eq(strspn("Lorem ipsum", "L"), s21_strspn("Lorem ipsum", "L"));
}
END_TEST

START_TEST(s21_strspn_3) {
  ck_assert_int_eq(strspn("Lorem ipsum", "m"), s21_strspn("Lorem ipsum", "m"));
}
END_TEST

START_TEST(s21_strspn_4) {
  ck_assert_int_eq(strspn("Lorem ipsum", "\0"),
                   s21_strspn("Lorem ipsum", "\0"));
}
END_TEST

START_TEST(s21_strspn_5) {
  ck_assert_int_eq(strspn("Lorem ipsum", "aeiou"),
                   s21_strspn("Lorem ipsum", "aeiou"));
}
END_TEST

START_TEST(s21_strspn_6) {
  ck_assert_int_eq(strspn("Lorem ipsum", "69"),
                   s21_strspn("Lorem ipsum", "69"));
}
END_TEST

START_TEST(s21_strspn_7) {
  ck_assert_int_eq(strspn("\0", "Lm"), s21_strspn("\0", "Lm"));
}
END_TEST

Suite *suite_s21_strspn() {
  Suite *suite = suite_create("s21_strspn");
  TCase *tcase = tcase_create("case_s21_strspn");

  tcase_add_test(tcase, s21_strspn_1);
  tcase_add_test(tcase, s21_strspn_2);
  tcase_add_test(tcase, s21_strspn_3);
  tcase_add_test(tcase, s21_strspn_4);
  tcase_add_test(tcase, s21_strspn_5);
  tcase_add_test(tcase, s21_strspn_6);
  tcase_add_test(tcase, s21_strspn_7);

  suite_add_tcase(suite, tcase);
  return suite;
}
