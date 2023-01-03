#include <locale.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include "../s21_string.h"

void s21_sprintf_opt_init(s21_sprintf_opt *opt) {
  opt->fl_minus = -1;
  opt->fl_plus = -1;
  opt->fl_space = -1;
  opt->fl_hash = -1;
  opt->fl_zero = -1;
  opt->width = -1;
  opt->precision = -1;
  opt->len_h = -1;
  opt->len_l = -1;
  opt->len_L = -1;
  opt->spec = '\0';
}

int s21_is_digit(char c) { return c >= '0' && c <= '9'; }

int s21_atoi(const char *str) {  // перевод строки в число >= 0
  int res = 0;
  while (*str) {
    res = res * 10 + (*str - '0');
    str++;
  }
  return res;
}

void s21_strrev(char *str) {
  int len = s21_strlen(str);
  for (int i = 0; i < len / 2; i++) {
    char tmp = str[i];
    str[i] = str[len - i - 1];
    str[len - i - 1] = tmp;
  }
}

int s21_itoa(char *dest, long long int num, int base) {
  int i = 0;
  int sign = 0;
  if (num < 0) {
    sign = 1;
    num = -num;
  }
  do {
    long long rem = num % base;
    dest[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
  } while (num /= base);
  if (sign) {
    dest[i++] = '-';
  }
  dest[i] = '\0';
  s21_strrev(dest);
  return i;
}

void s21_putch(char **dest, char c) {
  **dest = c;
  (*dest)++;
}

int s21_opt_parse(const char *format, s21_sprintf_opt *opt, va_list args) {
  int res = 0;
  const char flags[6] = "-+ #0";
  const char length[4] = "hlL";
  const char spesc[17] = "cdieEfgGosuxXpn\%";
  if (s21_is_delim(*format, flags)) {
    while (s21_is_delim(*format, flags)) {
      switch (*format) {
        case '-':
          opt->fl_minus = 1;
          break;
        case '+':
          opt->fl_plus = 1;
          break;
        case ' ':
          opt->fl_space = 1;
          break;
        case '#':
          opt->fl_hash = 1;
          break;
        case '0':
          opt->fl_zero = 1;
          break;
      }
      format++;
      res++;
    }
  }
  if (s21_is_digit(*format) || *format == '*') {
    if (*format == '*') {
      opt->width = va_arg(args, int);
      format++;
      res++;
    } else {
      char numbuf[16] = "\0";
      int i = 0;
      while (s21_is_digit(*format)) {
        numbuf[i] = *format;
        i++;
        format++;
        res++;
      }
      numbuf[i] = '\0';
      opt->width = s21_atoi(numbuf);
    }
  }
  if (*format == '.') {
    format++;
    res++;
    if (*format == '*') {
      opt->precision = va_arg(args, int);
      format++;
      res++;
    } else {
      char numbuf[16] = "\0";
      int i = 0;
      while (s21_is_digit(*format)) {
        numbuf[i] = *format;
        i++;
        format++;
        res++;
      }
      numbuf[i] = '\0';
      opt->precision = s21_atoi(numbuf);
    }
  }
  if (s21_is_delim(*format, length)) {
    switch (*format) {
      case 'h':
        opt->len_h = 1;
        break;
      case 'l':
        opt->len_l = 1;
        break;
      case 'L':
        opt->len_L = 1;
        break;
    }
    format++;
    res++;
  }
  if (s21_is_delim(*format, spesc)) {
    opt->spec = *format;
    format++;
    res++;
  } else {
    opt->spec = '\0';
  }
  return res;
}

int s21_sprinter_char(char *dest, s21_sprintf_opt opt, int c) {
  setlocale(LC_ALL, "");
  int res = 0;
  char sym = c;
  if (opt.len_l == 1 && c > 127) {
    wchar_t wc = c;
    wchar_t *wstr = &wc;
    wcstombs(NULL, wstr, 0);
    char *str = (char *)malloc(sizeof(char) * 3);
    wcstombs(str, wstr, 3);
    if (opt.fl_minus == 1) {
      for (int i = 0; i < 2; i++) {
        *dest = str[i];
        dest++;
        res++;
      }
      for (int i = 2; i < opt.width; i++) {
        *dest = ' ';
        dest++;
        res++;
      }
    } else {
      for (int i = 2; i < opt.width; i++) {
        *dest = ' ';
        dest++;
        res++;
      }
      for (int i = 0; i < 2; i++) {
        *dest = str[i];
        dest++;
        res++;
      }
    }
    free(str);
  } else {
    if (opt.width < 2) {
      *dest = sym;
      dest++;
      res++;
    } else {
      if (opt.fl_minus == 1) {
        *dest = sym;
        dest++;
        res++;
        for (int i = 1; i < opt.width; i++) {
          *dest = ' ';
          dest++;
          res++;
        }
      } else {
        for (int i = 1; i < opt.width; i++) {
          *dest = ' ';
          dest++;
          res++;
        }
        *dest = sym;
        dest++;
        res++;
      }
    }
  }
  *dest = '\0';
  return res;
}

int s21_sprinter_int(char *dest, s21_sprintf_opt opt, long long int c) {
  int res = 0;
  char str[64] = "\0";
  char *strptr = str;
  int len = 0;
  int sign = 0;
  long long int num = 0;
  if (opt.len_h == 1) {  // устанавливаем длину int в зависимости от флага
    num = (short int)c;
  } else if (opt.len_l == 1) {
    num = (long int)c;
  } else if (opt.len_L == 1) {
    num = (long long int)c;
  } else {
    num = (int)c;
  }
  if (num < 0) sign = 1;
  len = s21_itoa(strptr, num, 10);  // формируем строку в str
  if (opt.fl_plus == 1 &&
      num >= 0) {  // если есть флаг +, вставляем его в начало
    char *tmp = s21_insert(str, "+", 0);
    s21_strcpy(str, tmp);
    free(tmp);
    len++;
  }
  if (opt.fl_space == 1 &&
      num >= 0) {  // если есть флаг пробела, вставляем его в начало
    char *tmp = s21_insert(str, " ", 0);
    s21_strcpy(str, tmp);
    free(tmp);
    len++;
  }
  if (opt.precision > len) {
    int op = (sign || opt.fl_plus == 1) ? opt.precision - len + 1
                                        : opt.precision - len;
    while (op-- > 0) {
      if (sign || opt.fl_plus == 1) {
        char *tmp = s21_insert(str, "0", 1);
        s21_strcpy(str, tmp);
        free(tmp);
      } else {
        char *tmp = s21_insert(str, "0", 0);
        s21_strcpy(str, tmp);
        free(tmp);
      }
      len++;
    }
  }
  if (opt.width > len) {
    int ow = opt.width - len;
    while (ow-- > 0) {
      if (opt.fl_minus == 1) {
        char *tmp = s21_insert(str, " ", len);
        s21_strcpy(str, tmp);
        free(tmp);
      } else {
        if (opt.fl_zero == 1) {
          if (sign || opt.fl_plus == 1 || opt.fl_space == 1) {
            char *tmp = s21_insert(str, "0", 1);
            s21_strcpy(str, tmp);
            free(tmp);
          } else {
            char *tmp = s21_insert(str, "0", 0);
            s21_strcpy(str, tmp);
            free(tmp);
          }
        } else {
          char *tmp = s21_insert(str, " ", 0);
          s21_strcpy(str, tmp);
          free(tmp);
        }
      }
      len++;
    }
  }
  s21_strcpy(dest, str);
  res = len;
  return res;
}

int s21_vsprintf(char *str, const char *format, va_list args) {
  int res = 0;
  int step = 0;
  s21_sprintf_opt opt;
  while (*format) {
    if (*format != '%') {
      *str = *format;
      str++;
      format++;
      res++;
      continue;
    } else {
      format++;
      if (*format == '%') {
        *str = '%';
        str++;
        format++;
        res++;
        continue;
      }
      s21_sprintf_opt_init(&opt);
      step = s21_opt_parse(format, &opt, args) - 1;
      format += step;
      switch (opt.spec) {
        case 'c':
          step = s21_sprinter_char(str, opt, va_arg(args, int));
          res += step;
          str += step;
          break;
        case 'd':
        case 'i':
          step = s21_sprinter_int(str, opt, va_arg(args, long long int));
          res += step;
          str += step;
          break;
        default:
          break;
      }
    }
    format++;
  }
  *str = '\0';
  return res;
}

int s21_sprintf(char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  *str = '\0';
  int res = s21_vsprintf(str, format, args);
  va_end(args);
  return res;
}
