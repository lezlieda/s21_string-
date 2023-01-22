#include "../s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  int flag = 0;
  if (src == s21_NULL || trim_chars == s21_NULL) flag = 1;
  char *res = s21_NULL;
  if (!flag) {
    s21_size_t len_src = s21_strlen((char *)src);
    // char *p = (char *)malloc(len_src + 1);
    char *p = (char *)calloc(len_src + 2, sizeof(char));
    res = p;
    while (s21_is_delim(*src, trim_chars)) {
      src++;  // пропускаем все разделители в начале строки
    }
    while (*src != '\0') {
      *p++ = *src++;  // копируем строку
    }
    p--;
    if (*trim_chars != '\0') {
      while (s21_is_delim(*p, trim_chars)) {
        p--;  // пропускаем все разделители в конце строки
      }
    }
    p++;
    *p = '\0';  // ставим терминатор
  }
  return res;
}
