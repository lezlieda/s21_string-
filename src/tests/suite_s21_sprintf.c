#include <locale.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include "../s21_string.h"
#include "../suitecases.h"

START_TEST(s21_isdigit_1) {
  char a = '$';
  ck_assert_int_eq(0, s21_is_digit(a));
}
END_TEST

START_TEST(s21_isdigit_2) {
  char a = '0';
  ck_assert_int_eq(1, s21_is_digit(a));
}
END_TEST

START_TEST(s21_isdigit_3) {
  char a = '4';
  ck_assert_int_eq(1, s21_is_digit(a));
}
END_TEST

START_TEST(s21_isdigit_4) {
  char a = '9';
  ck_assert_int_eq(1, s21_is_digit(a));
}
END_TEST

START_TEST(s21_isdigit_5) {
  char a = 'a';
  ck_assert_int_eq(0, s21_is_digit(a));
}
END_TEST

START_TEST(s21_atoi_1) {
  char *a = "123";
  ck_assert_int_eq(123, s21_atoi(a));
}
END_TEST

START_TEST(s21_atoi_2) {
  char *a = "0";
  ck_assert_int_eq(0, s21_atoi(a));
}
END_TEST

START_TEST(s21_atoi_3) {
  char *a = "123456789";
  ck_assert_int_eq(123456789, s21_atoi(a));
}
END_TEST

START_TEST(s21_sprinter_char_1) {
  char *dest = malloc(100);
  s21_sprintf_opt opt = {0};
  opt.width = 1;
  opt.fl_minus = 0;
  int sc = s21_sprinter_char(dest, opt, 'a');
  ck_assert_str_eq("a", dest);
  ck_assert_int_eq(1, sc);
  free(dest);
}
END_TEST

START_TEST(s21_sprinter_char_2) {
  char *dest = malloc(100);
  s21_sprintf_opt opt = {0};
  opt.width = 2;
  opt.fl_minus = 0;
  int sc = s21_sprinter_char(dest, opt, 'a');
  ck_assert_str_eq(" a", dest);
  ck_assert_int_eq(2, sc);
  free(dest);
}
END_TEST

START_TEST(s21_sprinter_char_3) {
  char *dest = malloc(100);
  s21_sprintf_opt opt = {0};
  opt.width = 2;
  opt.fl_minus = 1;
  int sc = s21_sprinter_char(dest, opt, 'a');
  ck_assert_str_eq("a ", dest);
  ck_assert_int_eq(2, sc);
  free(dest);
}
END_TEST

START_TEST(s21_sprinter_char_4) {
  char *dest = malloc(100);
  s21_sprintf_opt opt = {0};
  opt.width = 5;
  opt.fl_minus = 1;
  int sc = s21_sprinter_char(dest, opt, 'a');
  ck_assert_str_eq("a    ", dest);
  ck_assert_int_eq(5, sc);
  free(dest);
}
END_TEST

START_TEST(s21_sprintf_proc_1) {
  char dest[100];
  char s21_dest[100];
  sprintf(dest, "aa bb %% cc %%%% dd");
  s21_sprintf(s21_dest, "aa bb %% cc %%%% dd");
  ck_assert_str_eq(dest, s21_dest);
}
END_TEST

START_TEST(s21_sprintf_c_1) {
  char dest[100];
  char s21_dest[100];
  sprintf(dest, "aa bb %3c cc %c dd", 'a', 'b');
  s21_sprintf(s21_dest, "aa bb %3c cc %c dd", 'a', 'b');
  ck_assert_str_eq(dest, s21_dest);
}
END_TEST

START_TEST(s21_sprintf_c_2) {
  char dest[100];
  char s21_dest[100];
  sprintf(dest, "aa bb %-3c cc %c dd", 'a', 'b');
  s21_sprintf(s21_dest, "aa bb %-3c cc %c dd", 'a', 'b');
  ck_assert_str_eq(dest, s21_dest);
}
END_TEST

START_TEST(s21_sprintf_c_3) {
  char dest[100];
  char s21_dest[100];
  sprintf(dest, "abc%-*cef", 3, 'D');
  s21_sprintf(s21_dest, "abc%-*cef", 3, 'D');
  ck_assert_str_eq(dest, s21_dest);
}
END_TEST

START_TEST(s21_sprintf_c_4) {
  setlocale(LC_ALL, "");
  char dest[100];
  char s21_dest[100];
  sprintf(dest, "abc%-*lcef", 3, L'Ā');
  s21_sprintf(s21_dest, "abc%-*lcef", 3, L'Ā');
  ck_assert_str_eq(dest, s21_dest);
}
END_TEST

START_TEST(s21_sprintf_c_5) {
  setlocale(LC_ALL, "");
  char dest[100];
  char s21_dest[100];
  sprintf(dest, "abc%-*lcef", 3, 'q');
  s21_sprintf(s21_dest, "abc%-*lcef", 3, 'q');
  ck_assert_str_eq(dest, s21_dest);
}
END_TEST

START_TEST(s21_sprintf_c_6) {
  setlocale(LC_ALL, "");
  char dest[100];
  char s21_dest[100];
  sprintf(dest, "abc%*lcef", 3, L'Ā');
  s21_sprintf(s21_dest, "abc%*lcef", 3, L'Ā');
  ck_assert_str_eq(dest, s21_dest);
}
END_TEST

START_TEST(s21_sprintf_c_7) {
  setlocale(LC_ALL, "");
  char dest[100];
  char s21_dest[100];
  sprintf(dest, "abc%*lcef", 1, 'q');
  s21_sprintf(s21_dest, "abc%*lcef", 1, 'q');
  ck_assert_str_eq(dest, s21_dest);
}
END_TEST

START_TEST(s21_itoa_1) {
  char dest[100] = {0};
  s21_itoa(dest, 123456789, 10);
  ck_assert_str_eq("123456789", dest);
}
END_TEST

START_TEST(s21_itoa_2) {
  char dest[100] = {0};
  s21_itoa(dest, -123456789, 10);
  ck_assert_str_eq("-123456789", dest);
}
END_TEST

START_TEST(s21_itoa_3) {
  char dest[100] = {0};
  s21_itoa(dest, -123456789, 16);
  ck_assert_str_eq("-75BCD15", s21_to_upper(dest));
}
END_TEST

START_TEST(s21_itoa_4) {
  char s21_dest[100] = {0};
  char dest[100] = {0};
  sprintf(dest, "%x", 123456789);
  s21_itoa(s21_dest, 123456789, 16);
  ck_assert_str_eq(dest, s21_dest);
}
END_TEST

START_TEST(s21_itoa_5) {
  char dest[100] = {0};
  s21_itoa(dest, 123456789, 8);
  ck_assert_str_eq("726746425", dest);
}
END_TEST

START_TEST(s21_itoa_6) {
  char dest[100] = {0};
  s21_itoa(dest, -123456789, 8);
  ck_assert_str_eq("-726746425", dest);
}
END_TEST

START_TEST(s21_itoa_7) {
  char dest[100] = {0};
  s21_itoa(dest, 123456789, 2);
  ck_assert_str_eq("111010110111100110100010101", dest);
}
END_TEST

START_TEST(s21_itoa_8) {
  char dest[100] = {0};
  s21_itoa(dest, -123456789, 2);
  ck_assert_str_eq("-111010110111100110100010101", dest);
}
END_TEST

START_TEST(s21_sprintf_d_1) {
  char dest[100];
  char s21_dest[100];
  sprintf(dest, "aa bb %3d cc %d dd", 123, 456);
  s21_sprintf(s21_dest, "aa bb %3d cc %d dd", 123, 456);
  ck_assert_str_eq(dest, s21_dest);
}
END_TEST

START_TEST(s21_sprintf_d_2) {
  char dest[100];
  char s21_dest[100];
  sprintf(dest, "aa bb %-3d cc %d dd", 123, 456);
  s21_sprintf(s21_dest, "aa bb %-3d cc %d dd", 123, 456);
  ck_assert_str_eq(dest, s21_dest);
}
END_TEST

START_TEST(s21_sprintf_d_3) {
  char dest[100];
  char s21_dest[100];
  sprintf(dest, "aa bb %03d cc %d dd", 123, 456);
  s21_sprintf(s21_dest, "aa bb %03d cc %d dd", 123, 456);
  ck_assert_str_eq(dest, s21_dest);
}
END_TEST

START_TEST(s21_sprintf_d_4) {
  char dest[100];
  char s21_dest[100];
  sprintf(dest, "aa bb %*d cc %d dd", 3, 123, 456);
  s21_sprintf(s21_dest, "aa bb %*d cc %d dd", 3, 123, 456);
  ck_assert_str_eq(dest, s21_dest);
}
END_TEST

START_TEST(s21_sprintf_d_5) {
  char dest[100];
  char s21_dest[100];
  sprintf(dest, "aa bb %*d cc %d dd", -3, 123, 456);
  s21_sprintf(s21_dest, "aa bb %*d cc %d dd", -3, 123, 456);
  ck_assert_str_eq(dest, s21_dest);
}
END_TEST

START_TEST(s21_sprintf_d_6) {
  char dest[100];
  char s21_dest[100];
  sprintf(dest, "aa bb %*d cc %d dd", 3, -123, 456);
  s21_sprintf(s21_dest, "aa bb %*d cc %d dd", 3, -123, 456);
  ck_assert_str_eq(dest, s21_dest);
}
END_TEST

START_TEST(s21_sprintf_d_7) {
  char dest[100];
  char s21_dest[100];
  sprintf(dest, "aa bb %*.*d cc %d dd", 10, 5, -123, 456);
  s21_sprintf(s21_dest, "aa bb %*.*d cc %d dd", 10, 5, -123, 456);
  ck_assert_str_eq(dest, s21_dest);
}
END_TEST

START_TEST(s21_sprintf_d_8) {
  char dest[100];
  char s21_dest[100];
  sprintf(dest, "aa bb %+-*.*d cc %+d dd", 10, 5, 123, 456);
  s21_sprintf(s21_dest, "aa bb %+-*.*d cc %+d dd", 10, 5, 123, 456);
  ck_assert_str_eq(dest, s21_dest);
}
END_TEST

START_TEST(s21_sprintf_d_9) {
  char dest[100];
  char s21_dest[100];
  sprintf(dest, "aa bb %+-*.*d cc % d dd", 10, 5, -123, 456);
  s21_sprintf(s21_dest, "aa bb %+-*.*d cc % d dd", 10, 5, -123, 456);
  ck_assert_str_eq(dest, s21_dest);
}
END_TEST

START_TEST(s21_sprintf_d_10) {
  char dest[100];
  char s21_dest[100];
  sprintf(dest, "aa bb %+-*.5d cc % d dd", 10, 123, 456);
  s21_sprintf(s21_dest, "aa bb %+-*.5d cc % d dd", 10, 123, 456);
  ck_assert_str_eq(dest, s21_dest);
}
END_TEST

Suite *suite_s21_sprintf() {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_sprintf");

  /* Core test case */
  tc_core = tcase_create("case_s21_sprintf");

  tcase_add_test(tc_core, s21_isdigit_1);
  tcase_add_test(tc_core, s21_isdigit_2);
  tcase_add_test(tc_core, s21_isdigit_3);
  tcase_add_test(tc_core, s21_isdigit_4);
  tcase_add_test(tc_core, s21_isdigit_5);

  tcase_add_test(tc_core, s21_atoi_1);
  tcase_add_test(tc_core, s21_atoi_2);
  tcase_add_test(tc_core, s21_atoi_3);

  tcase_add_test(tc_core, s21_sprinter_char_1);
  tcase_add_test(tc_core, s21_sprinter_char_2);
  tcase_add_test(tc_core, s21_sprinter_char_3);
  tcase_add_test(tc_core, s21_sprinter_char_4);

  tcase_add_test(tc_core, s21_sprintf_proc_1);

  tcase_add_test(tc_core, s21_sprintf_c_1);
  tcase_add_test(tc_core, s21_sprintf_c_2);
  tcase_add_test(tc_core, s21_sprintf_c_3);
  tcase_add_test(tc_core, s21_sprintf_c_4);
  tcase_add_test(tc_core, s21_sprintf_c_5);
  tcase_add_test(tc_core, s21_sprintf_c_6);
  tcase_add_test(tc_core, s21_sprintf_c_7);

  tcase_add_test(tc_core, s21_itoa_1);
  tcase_add_test(tc_core, s21_itoa_2);
  tcase_add_test(tc_core, s21_itoa_3);
  tcase_add_test(tc_core, s21_itoa_4);
  tcase_add_test(tc_core, s21_itoa_5);
  tcase_add_test(tc_core, s21_itoa_6);
  tcase_add_test(tc_core, s21_itoa_7);
  tcase_add_test(tc_core, s21_itoa_8);

  tcase_add_test(tc_core, s21_sprintf_d_1);
  tcase_add_test(tc_core, s21_sprintf_d_2);
  tcase_add_test(tc_core, s21_sprintf_d_3);
  tcase_add_test(tc_core, s21_sprintf_d_4);
  tcase_add_test(tc_core, s21_sprintf_d_5);
  tcase_add_test(tc_core, s21_sprintf_d_6);
  tcase_add_test(tc_core, s21_sprintf_d_7);
  tcase_add_test(tc_core, s21_sprintf_d_8);
  tcase_add_test(tc_core, s21_sprintf_d_9);
  tcase_add_test(tc_core, s21_sprintf_d_10);

  suite_add_tcase(s, tc_core);

  return s;
}