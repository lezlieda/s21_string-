#include "../s21_string.h"

int s21_memcmp(const void* str1, const void* str2, s21_size_t n) {
  char* s1 = (char*)str1;
  char* s2 = (char*)str2;
  int result = 0;
  if (str1 != s21_NULL && str2 != s21_NULL) {
    for (s21_size_t i = 0; i < n; i++) {
      if (!result && *s1 != *s2) result = ((*s1) - (*s2));
      s1++;
      s2++;
    }
  }
  return result;
}
