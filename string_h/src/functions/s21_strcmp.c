#include "../s21_string.h"

int s21_strcmp(char *str1, char *str2) {
  int res;
  while (!(res = *str1 - *str2) && *str2) ++str1, ++str2;
  return res;
}
