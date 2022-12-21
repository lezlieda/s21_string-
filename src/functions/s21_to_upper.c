#include <string.h>
// временно добавлена библиотека для работы sprintf

#include "../s21_string.h"

void *s21_to_upper(const char *str) {
  int flag = 0;
  if (str == S21_NULL) flag = 1;
  char *res;
  if (!flag) {
    s21_size_t len = s21_strlen((char *)str);
    char *p = (char *)malloc(len + 1);
    sprintf(p, "%s", str);  // здесь должен использоваться s21_sprintf, но он
                            // пока не реализован
    res = p;
    while (*p != '\0') {
      if (*p >= 'a' && *p <= 'z') *p -= 32;
      p++;
    }
  }
  return !flag ? (char *)res : S21_NULL;
}
