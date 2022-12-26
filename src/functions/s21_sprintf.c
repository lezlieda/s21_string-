#include <stdarg.h>

#include "../s21_string.h"

int s21_strrev(char *str) {
  int flag = 0;
  if (str == S21_NULL) flag = 1;
  int res = 0;
  if (!flag) {
    s21_size_t len = s21_strlen(str);
    char *p = str;
    char *q = str + len - 1;
    while (p < q) {
      char tmp = *p;
      *p = *q;
      *q = tmp;
      p++;
      q--;
    }
    res = 1;
  }
  return !flag ? res : -1;
}

char *s21_itoa(int num) {
  int flag = 0;
  if (num == 0) flag = 1;
  char *res;
  if (!flag) {
    int len = 0;
    int tmp = num;
    while (tmp) {
      tmp /= 10;
      len++;
    }
    char *p = (char *)malloc(len + 1);
    res = p;
    while (num) {
      *p = num % 10 + '0';
      p++;
      num /= 10;
    }
    *p = '\0';
    s21_strrev(res);
  }
  return !flag ? (char *)res : S21_NULL;
}

typedef struct s21_sprintf_spec {
  char flags;
  int width;
  int precision;
  char length;
  char specifier;
} s21_sprintf_spec;

void s21_sprintf_spec_init(s21_sprintf_spec *spec) {
  spec->flags = '\0';
  spec->width = 0;
  spec->precision = 0;
  spec->length = '\0';
  spec->specifier = '\0';
}

void s21_sprintf_spec_parse(s21_sprintf_spec *spec, char *str, va_list args) {
  s21_sprintf_spec_init(spec);
  char *p = str;
  while (*p) {
    switch (*p) {
      case '-':
      case '+':
      case ' ':
      case '#':
      case '0':
        spec->flags = *p;
        break;
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
        spec->width = *p - '0';
        break;
      case '*':
        spec->width = va_arg(args, int);
        break;
      case '.':
        spec->precision = -1;
        break;
      case 'h':
      case 'l':
      case 'L':
        spec->length = *p;
        break;
      default:
        spec->specifier = *p;
        break;
    }
    p++;
  }
}

int s21_vsprintf(char *str, const char *format, va_list args) {
  int flag = 0;
  if (str == S21_NULL || format == S21_NULL) flag = 1;
  int res = 0;
  if (!flag) {
    char *p = str;
    while (*format) {
      if (*format == '%') {
            } else {
        *p = *format;
        p++;
        res++;
      }
      if (flag) break;
      format++;
    }
    *p = '\0';
  }
  return !flag ? res : -1;
}

int s21_sprintf(char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  int res = s21_vsprintf(str, format, args);
  va_end(args);
  return res;
}
