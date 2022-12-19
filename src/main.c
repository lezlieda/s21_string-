#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "suitecases.h"

int main() {
  char str[16] = "1234567890";
  char substr[8] = "world!";
  char *res = memcpy(str, substr, 6);
  char *res_s21 = s21_memcpy(str, substr, 6);

  printf("%s\n", res);
  printf("%s\n", res_s21);

  return 0;
}
