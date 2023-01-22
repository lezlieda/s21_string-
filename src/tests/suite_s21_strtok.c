#include "../s21_string.h"
#include "../suitecases.h"

START_TEST(s21_strtok_1) {
  char str1[32] = "Lorem ipsum dolor sit amet";
  char str2[32] = "Lorem ipsum dolor sit amet";
  char delim[8] = " ";
  char *result, *s21_result;
  result = strtok(str1, delim);
  s21_result = s21_strtok(str2, delim);
  ck_assert_pstr_eq(result, s21_result);
  while (result != NULL) {
    result = strtok(NULL, delim);
    s21_result = s21_strtok(NULL, delim);
    ck_assert_pstr_eq(result, s21_result);
  }
}
END_TEST

START_TEST(s21_strtok_2) {
  char str1[32] = "Lorem ipsum dolor sit amet";
  char str2[32] = "Lorem ipsum dolor sit amet";
  char delim[8] = "ipsum";
  char *result, *s21_result;
  result = strtok(str1, delim);
  s21_result = s21_strtok(str2, delim);
  ck_assert_pstr_eq(result, s21_result);
  while (result != NULL) {
    result = strtok(NULL, delim);
    s21_result = s21_strtok(NULL, delim);
    ck_assert_pstr_eq(result, s21_result);
  }
}
END_TEST

START_TEST(s21_strtok_3) {
  char str1[32] = "Lorem ipsum dolor sit amet";
  char str2[32] = "Lorem ipsum dolor sit amet";
  char delim[32] = "Lorem ipsum dolor sit amet";
  char *result, *s21_result;
  result = strtok(str1, delim);
  s21_result = s21_strtok(str2, delim);
  ck_assert_pstr_eq(result, s21_result);
  while (result != NULL) {
    result = strtok(NULL, delim);
    s21_result = s21_strtok(NULL, delim);
    ck_assert_pstr_eq(result, s21_result);
  }
}
END_TEST

START_TEST(s21_strtok_4) {
  char str1[32] = "Lorem ipsum dolor sit amet";
  char str2[32] = "Lorem ipsum dolor sit amet";
  char delim[32] = "z";
  char *result, *s21_result;
  result = strtok(str1, delim);
  s21_result = s21_strtok(str2, delim);
  ck_assert_pstr_eq(result, s21_result);
  while (result != NULL) {
    result = strtok(NULL, delim);
    s21_result = s21_strtok(NULL, delim);
    ck_assert_pstr_eq(result, s21_result);
  }
}
END_TEST

START_TEST(s21_strtok_5) {
  char str1[32] = "Lorem ipsum dolor sit amet";
  char str2[32] = "Lorem ipsum dolor sit amet";
  char delim[32] = "\0";
  char *result, *s21_result;
  result = strtok(str1, delim);
  s21_result = s21_strtok(str2, delim);
  ck_assert_pstr_eq(result, s21_result);
  while (result != NULL) {
    result = strtok(NULL, delim);
    s21_result = s21_strtok(NULL, delim);
    ck_assert_pstr_eq(result, s21_result);
  }
}
END_TEST

START_TEST(s21_strtok_6) {
  char str1[32] = "\0";
  char str2[32] = "\0";
  char delim[32] = "L";
  char *result, *s21_result;
  result = strtok(str1, delim);
  s21_result = s21_strtok(str2, delim);
  ck_assert_pstr_eq(result, s21_result);
  while (result != NULL) {
    result = strtok(NULL, delim);
    s21_result = s21_strtok(NULL, delim);
    ck_assert_pstr_eq(result, s21_result);
  }
}
END_TEST

START_TEST(s21_strtok_7) {
  char str1[32] = "\0";
  char str2[32] = "\0";
  char delim[32] = "\0";
  char *result, *s21_result;
  result = strtok(str1, delim);
  s21_result = s21_strtok(str2, delim);
  ck_assert_pstr_eq(result, s21_result);
  while (result != NULL) {
    result = strtok(NULL, delim);
    s21_result = s21_strtok(NULL, delim);
    ck_assert_pstr_eq(result, s21_result);
  }
}
END_TEST

// START_TEST(s21_strtok_8) {
//   char *str1 = NULL;
//   char *str2 = NULL;
//   char delim[32] = "L";
//   char *result, *s21_result;
//   result = strtok(str1, delim);
//   s21_result = s21_strtok(str2, delim);
//   ck_assert_pstr_eq(result, s21_result);
//   while (result != NULL) {
//     result = strtok(NULL, delim);
//     s21_result = s21_strtok(NULL, delim);
//     ck_assert_pstr_eq(result, s21_result);
//   }
// }
// END_TEST

Suite *suite_s21_strtok() {
  Suite *suite = suite_create("s21_strtok");
  TCase *tcase = tcase_create("case_s21_strtok");

  tcase_add_test(tcase, s21_strtok_1);
  tcase_add_test(tcase, s21_strtok_2);
  tcase_add_test(tcase, s21_strtok_3);
  tcase_add_test(tcase, s21_strtok_4);
  tcase_add_test(tcase, s21_strtok_5);
  tcase_add_test(tcase, s21_strtok_6);
  tcase_add_test(tcase, s21_strtok_7);
  // tcase_add_test(tcase, s21_strtok_8);

  suite_add_tcase(suite, tcase);

  return suite;
}
