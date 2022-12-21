#ifndef S21_STRING_H
#define S21_STRING_H

#include <stdio.h>
#include <stdlib.h>

#define S21_NULL ((void *)0)

typedef unsigned long s21_size_t;

void *s21_memcpy(void *dest, const void *src, s21_size_t n);
int s21_is_delim(char c, const char *delim);
char *s21_strtok(char *str, const char *delim);
s21_size_t s21_strlen(char *str);
int s21_strcmp(char *str1, char *str2);
char *s21_strcpy(char *dest, char *src);
char *s21_strcat(char *dest, char *src);
char *s21_strchr(char *str, char c);
char *s21_strstr(char *str, char *substr);
void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
int s21_strncmp(char *str1, char *str2, s21_size_t n);

/* Special string processing functions (from the String class in C#) */
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

#endif
