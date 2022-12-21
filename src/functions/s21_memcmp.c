#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const char *s1 = str1;
  const char *s2 = str2;
  int res = 0;
  while (n--) {
    if (!(res = *s1 - *s2) && *s2) ++s1, ++s2;
  }
  return res;
}
