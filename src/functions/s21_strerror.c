#include <string.h>  // временно для sprintf

#include "../s21_string.h"
#include "error_lists.h"

char *s21_strerror(int errnum) {
  static char result[100];

#ifdef __APPLE__
  if (errnum < 0 || errnum > 106) {
    sprintf(result, "Unknown error: %d", errnum);
  } else {
    sprintf(result, "%s", error_list_macos[errnum]);
  }
#elif __linux__
  if (errnum < 0 || errnum > 133) {
    sprintf(result, "Unknown error: %d", errnum);
  } else {
    sprintf(result, "%s", error_list_linux[errnum]);
  }
#endif

  return (char *)result;
}
