#include "../s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int res = 0;
  while (n--) {
    if (!(res = *str1 - *str2) && *str2) ++str1, ++str2;
  }
  return res;
}
