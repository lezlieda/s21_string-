#include "../s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *p = dest;
  while (n--) {
    *dest = *src;
    dest++;
    src++;
  }
  return p;
}
