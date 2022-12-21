#include "../s21_string.h"
#include "../suitecases.h"

START_TEST(s21_strcspn_1) {
  ck_assert_int_eq(strcspn("Lorem ipsum", "a"),
                   s21_strcspn("Lorem ipsum", "a"));
}
END_TEST

START_TEST(s21_strcspn_2) {
  ck_assert_int_eq(strcspn("Lorem ipsum", "L"),
                   s21_strcspn("Lorem ipsum", "L"));
}
END_TEST

START_TEST(s21_strcspn_3) {
  ck_assert_int_eq(strcspn("Lorem ipsum", "m"),
                   s21_strcspn("Lorem ipsum", "m"));
}
END_TEST

START_TEST(s21_strcspn_4) {
  ck_assert_int_eq(strcspn("Lorem ipsum", "\0"),
                   s21_strcspn("Lorem ipsum", "\0"));
}
END_TEST

START_TEST(s21_strcspn_5) {
  ck_assert_int_eq(strcspn("Lorem ipsum", "aeiou"),
                   s21_strcspn("Lorem ipsum", "aeiou"));
}
END_TEST

Suite *suite_s21_strcspn() {
  Suite *suite = suite_create("s21_strcspn");
  TCase *tcase = tcase_create("case_s21_strcspn");

  tcase_add_test(tcase, s21_strcspn_1);
  tcase_add_test(tcase, s21_strcspn_2);
  tcase_add_test(tcase, s21_strcspn_3);
  tcase_add_test(tcase, s21_strcspn_4);
  tcase_add_test(tcase, s21_strcspn_5);

  suite_add_tcase(suite, tcase);
  return suite;
}
