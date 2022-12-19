#include "../suitecases.h"

START_TEST(s21_memcpy_1) {
  const char src[64] = "Lorem ipsum dolor sit amet";
  char dest[64];
  char result[64] = memcpy(dest, src, 64);
  char s21_result[64] = s21_memcpy(dest, src, 64);
  ck_assert_str_eq(result, s21_result);
}
END_TEST

Suite *suite_s21_memcpy(void) {
  Suite *s = suite_create("s21_memcpy");
  TCase *tc_case = tcase_create("case_s21_memcpy");

  tcase_add_test(tc_case, s21_memcpy_1);
  suite_add_tcase(s, tc_case);

  return s;
}
