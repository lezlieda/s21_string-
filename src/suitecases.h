#ifndef SUITECASES_H
#define SUITECASES_H

#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Suite *suite_s21_memcpy();
Suite *suite_s21_strcat();
Suite *suite_s21_strchr();
Suite *s21_strcmp_suite();
Suite *suite_s21_strcpy();
Suite *suite_s21_strlen();
Suite *suite_s21_strstr();
Suite *suite_s21_strtok();
Suite *suite_s21_memchr();
Suite *s21_memcmp_suite();

Suite *suite_s21_to_upper();
Suite *suite_s21_to_lower();
Suite *suite_s21_insert();
Suite *suite_s21_trim();

#endif
