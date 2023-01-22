#include "../s21_string.h"

char *s21_strchr(char *str, char c) {
  while (*str != '\0' && *str != c) str++;
  return *str == c ? str : s21_NULL;
}
