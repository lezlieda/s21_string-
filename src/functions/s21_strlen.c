#include "../s21_string.h"

s21_size_t s21_strlen(const char *str) {
  s21_size_t counter = 0;
  const char *tmp = str;
  while (tmp[counter] != '\0') {
    counter++;
  }
  return counter;
}
