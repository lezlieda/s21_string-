#include "../s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *res = s21_NULL;
  while (*str1) {
    if (s21_is_delim(*str1, str2)) {
      res = (char *)str1;
      break;
    }
    str1++;
  }
  return res;
}
