#include "../s21_string.h"

char *s21_strcat(char *dest, char *src) {
  char *p = dest;
  while (*p != '\0') p++;
  while (*src != '\0') *p++ = *src++;
  *p = '\0';
  return dest;
}
