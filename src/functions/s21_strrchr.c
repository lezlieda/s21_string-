#include "../s21_string.h"

char *s21_strrchr(const char *str, int c) {
  s21_size_t len = s21_strlen((char *)str);
  while (*str != '\0') str++;
  while (len && *str != c) str--, len--;
  return *str == c ? (char *)str : s21_NULL;
}
