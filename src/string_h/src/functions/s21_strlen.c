#include "../s21_string.h"

s21_size_t s21_strlen(char *str) {
  char *end = str;
  for (; *end != '\0'; end++) {
  }
  return end - str;
}
