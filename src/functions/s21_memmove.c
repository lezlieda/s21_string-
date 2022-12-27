#include "../s21_string.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char tmp[n];
  s21_memcpy(tmp, src, n);
  s21_memcpy(dest, tmp, n);
  return dest;
}
