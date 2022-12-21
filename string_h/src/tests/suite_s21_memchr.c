#include "../s21_string.h"
#include "../suitecases.h"

START_TEST(s21_memchr_1) {
  const char src[64] = "Lorem ipsum dolor sit amet";
  ck_assert_pstr_eq(memchr(src, 'm', 64), s21_memchr(src, 'm', 64));
}
END_TEST

START_TEST(s21_memchr_2) {
  const char src[64] = "Lorem ipsum dolor sit amet";
  ck_assert_pstr_eq(memchr(src, 'm', 6), s21_memchr(src, 'm', 6));
}
END_TEST

START_TEST(s21_memchr_3) {
  const char src[64] = "Lorem ipsum dolor sit amet";
  ck_assert_pstr_eq(memchr(src, 'm', 0), s21_memchr(src, 'm', 0));
}
END_TEST

START_TEST(s21_memchr_4) {
  const char src[64] = "Lorem ipsum dolor sit amet";
  ck_assert_pstr_eq(memchr(src, 'z', 64), s21_memchr(src, 'z', 64));
}
END_TEST

Suite *suite_s21_memchr() {
  Suite *suite = suite_create("s21_memchr");
  TCase *tcase = tcase_create("case_s21_memchr");

  tcase_add_test(tcase, s21_memchr_1);
  tcase_add_test(tcase, s21_memchr_2);
  tcase_add_test(tcase, s21_memchr_3);
  tcase_add_test(tcase, s21_memchr_4);

  suite_add_tcase(suite, tcase);

  return suite;
}