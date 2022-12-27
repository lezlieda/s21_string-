#include <stdarg.h>

#include "../s21_string.h"

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

int s21_atoi(char *str) {
  int res = 0;
  while (*str) {
    res = res * 10 + (*str - '0');
    str++;
  }
  return res;
}

void s21_sprintf_spec_parse(s21_sprintf_spec *spec, char *str, va_list args) {
  s21_sprintf_spec_init(spec);
  char *p = str;
  while (*p) {
    switch (*p) {
      case '-' || '+' || ' ' || '#' || '0':
        spec->flags = *p;
        break;
      case '1' ... '9':
        char *tmp;
        while (*p >= '0' && *p <= '9') {
          *tmp = *p;
          tmp++;
          p++;
        }
        *tmp = '\0';
        spec->width = s21_atoi(tmp);
        break;
      case '*':
        spec->width = va_arg(args, int);
        break;
      case '.':
        p++;
        if (*p == '*') {
          spec->precision = va_arg(args, int);
        } else {
          char *tmp;
          while (*p >= '0' && *p <= '9') {
            *tmp = *p;
            tmp++;
            p++;
          }
          *tmp = '\0';
          spec->precision = s21_atoi(tmp);
        }
        break;
      case 'h' || 'l' || 'L':
        spec->length = *p;
        break;
      case 'c' || 'd' || 'i' || 'e' || 'E' || 'f' || 'g' || 'G' || 'o' || 's' ||
          'u' || 'x' || 'X' || 'p' || 'n' || '%':
        spec->specifier = *p;
      default:
        printf("Error: unknown specifier '%c' in format string\n", *p);
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
        format++;
        struct s21_sprintf_spec spec;
        s21_sprintf_spec_init(&spec);
        s21_sprintf_spec_parse(&spec, (char *)format, args);
        s21_
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
