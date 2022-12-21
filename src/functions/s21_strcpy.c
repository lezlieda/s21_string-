#include "../s21_string.h"

char *s21_strcpy(char *dest, const char *src) {
  char *p = dest;
  while (*src != '\0') {
    *dest = *src;
    dest++;
    src++;
  }
  *dest = '\0';
  return p;
}
