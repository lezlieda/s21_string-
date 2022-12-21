#include "../s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t res = 0;
  while (str1[res] != '\0') {
    if (s21_is_delim(str1[res], str2)) {
      break;
    }
    res++;
  }
  return res;
}
