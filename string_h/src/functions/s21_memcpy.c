#include "../s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *d = dest;
  const char *s = src;
  while (n--) {   // пока n не равно 0
    *d++ = *s++;  // копируем байт из s в d и увеличиваем указатели
  }
  return dest;
}
