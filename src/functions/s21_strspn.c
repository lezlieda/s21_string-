#include "../s21_string.h"

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t i = 0;
  while (str1[i] != '\0') {
    if (!s21_is_delim(str1[i], str2)) {
      break;
    }
    i++;
  }
  return i;
}
