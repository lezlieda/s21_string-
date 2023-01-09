#include "../s21_string.h"

void *s21_to_lower(const char *str) {
  int flag = 0;
  if (str == S21_NULL) flag = 1;
  char *res;
  if (!flag) {
    s21_size_t len = s21_strlen((char *)str);
    char *p = (char *)malloc(len + 1);
    s21_sprintf(p, "%s", str);
    res = p;
    while (*p != '\0') {
      if (*p >= 'A' && *p <= 'Z') *p += 32;
      p++;
    }
  }
  return !flag ? (char *)res : S21_NULL;
}
