#include "../s21_string.h"

int s21_is_delim(char c, const char *delim) {
  int res = 0;  // 1 если символ является разделителем, 0 если нет
  while (*delim != '\0') {
    if (c == *delim) {
      res = 1;
    }
    delim++;
  }
  return res;
}
