#include "../s21_string.h"
#include "../suitecases.h"

START_TEST(s21_strerror_1) {
  for (int i = -1; i < 135; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
}
END_TEST

Suite *suite_s21_strerror() {
  Suite *suite = suite_create("s21_strerror");
  TCase *tcase = tcase_create("case_s21_strerror");

  tcase_add_test(tcase, s21_strerror_1);

  suite_add_tcase(suite, tcase);
  return suite;
}
