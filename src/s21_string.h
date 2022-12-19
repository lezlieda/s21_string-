#ifndef S21_STRING_H
#define S21_STRING_H

#include <stdio.h>
#include <stdlib.h>


#define S21_NULL ((void *)0)

typedef unsigned long s21_size_t;

void *s21_memcpy(void *dest, const void *src, s21_size_t n);
int is_delim(char c, const char *delim);
char *s21_strtok(char *str, const char *delim);
s21_size_t s21_strlen(char *str);
int s21_strcmp(char *str1, char *str2);
char *s21_strcpy(char *dest, char *src);
char *s21_strcat(char *dest, char *src);
char *s21_strchr(char *str, char c);
char *s21_strstr(char *str, char *substr);

#endif
