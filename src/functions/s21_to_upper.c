#include "../s21_string.h"

void *s21_to_upper(const char *str) {
  int flag = 0;
  if (str == s21_NULL) flag = 1;
  char *res;
  if (!flag) {
    s21_size_t len = s21_strlen((char *)str);
    // char *p = (char *)malloc(len + 1);
    char *p = (char *)calloc(len + 1, sizeof(char));
    s21_sprintf(p, "%s", str);
    res = p;
    while (*p != '\0') {
      if (*p >= 'a' && *p <= 'z') *p -= 32;
      p++;
    }
  }
  return !flag ? (char *)res : s21_NULL;
}
