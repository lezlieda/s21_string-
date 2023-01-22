#include "../s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  int flag = 0;
  while (n--) {
    if (*(char *)str == c) {
      flag = 1;
      break;
    }
    str = (char *)str +
          1;  // для увеличения адреса на 1 байт, str++ может не работать
  }
  return flag ? (char *)str : s21_NULL;
}
