#include "../s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  int flag = 0;
  if (src == S21_NULL || str == S21_NULL) flag = 1;
  char *res;
  if (!flag) {
    s21_size_t len_src = s21_strlen((char *)src);
    s21_size_t len_str = s21_strlen((char *)str);
    if (start_index > len_src) flag = 1;
    if (!flag) {
      char *p = (char *)malloc(len_src + len_str + 1);
      res = p;
      while (start_index--) {
        *p = *src;
        p++;
        src++;
        len_src--;
      }
      while (len_str--) {
        *p = *str;
        p++;
        str++;
      }
      while (len_src--) {
        *p = *src;
        p++;
        src++;
      }
      *p = '\0';
    }
  }
  return !flag ? (char *)res : S21_NULL;
}
