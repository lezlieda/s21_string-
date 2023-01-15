#include "../s21_string.h"

char *s21_strerror(int errnum) {
  const char *err_list[] = ERROR_LIST;
  static char result[100] = "\0";
  if (errnum < 0 || errnum > ERROR_LIST_SIZE) {
    s21_sprintf(result, "Unknown error: %d", errnum);
  } else {
    s21_sprintf(result, "%s", err_list[errnum]);
  }
  return result;
}
