#include "../s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  int flag = 0;
  if (src == S21_NULL || trim_chars == S21_NULL) flag = 1;
  char *res;
  if (!flag) {
    s21_size_t len_src = s21_strlen((char *)src);
    char *p = (char *)malloc(len_src + 1);
    res = p;
    while (s21_is_delim(*src, trim_chars)) {
      src++;  // пропускаем все разделители в начале строки
    }
    while (*src != '\0') {
      *p = *src;  // копируем строку
      p++;
      src++;
    }
    p--;
    while (s21_is_delim(*p, trim_chars)) {
      p--;  // пропускаем все разделители в конце строки
    }
    p++;
    *p = '\0';  // ставим терминатор
  }
  return !flag ? (char *)res : S21_NULL;
}
