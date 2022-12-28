#include <stdarg.h>
#include <string.h>  // strlen

#include "../s21_string.h"

typedef struct s21_sprintf_opt {
  int fl_minus;
  int fl_plus;
  int fl_space;
  int fl_hash;
  int fl_zero;
  int width;
  int precision;
  int len_h;
  int len_l;
  int len_L;
} s21_sprintf_opt;

void s21_sprintf_opt_init(s21_sprintf_opt *opt) {
  opt->fl_minus = 0;
  opt->fl_plus = 0;
  opt->fl_space = 0;
  opt->fl_hash = 0;
  opt->fl_zero = 0;
  opt->width = 0;
  opt->precision = 0;
  opt->len_h = 0;
  opt->len_l = 0;
  opt->len_L = 0;
}

int s21_atoi(char *str) {
  int res = 0;
  while (*str) {
    res = res * 10 + (*str - '0');
    str++;
  }
  return res;
}

int s21_itoa(char *dest, int num, int base) {
  int res = 0;
  int i = 0;
  int sign = 0;
  if (num < 0) {
    sign = 1;
    num = -num;
  }
  while (num > 0) {
    int ostatok = num % base;
    dest[i] = ostatok < 10 ? ostatok + '0' : ostatok - 10 + 'a';
    num = num / base;
    i++;
  }
  if (sign) {
    dest[i] = '-';
    i++;
  }
  dest[i] = '\0';
  res = i;
  int j = 0;
  i--;
  while (j < i) {
    char tmp = dest[j];
    dest[j] = dest[i];
    dest[i] = tmp;
    j++;
    i--;
  }
  return res;
}

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

int s21_is_digit(char c) {
  int res = 0;
  if (c >= '0' && c <= '9') {
    res = 1;
  }
  return res;
}

int s21_sprintf_opt_parse(s21_sprintf_opt *opt, const char *str, va_list args) {
  int res = 0;

  char *p = (char *)str;
  const char flags[6] = "-+ #0";
  const char length[3] = "hlL";
  // const char specifier[17] = "cdieEfgGosuxXpn\%";
  if (s21_is_delim(*p, flags)) {
    while (s21_is_delim(*p, flags)) {
      switch (*p) {
        case '-':
          opt->fl_minus++;
          res++;
          break;
        case '+':
          opt->fl_plus++;
          res++;
          break;
        case ' ':
          opt->fl_space++;
          res++;
          break;
        case '#':
          opt->fl_hash++;
          res++;
          break;
        case '0':
          opt->fl_zero++;
          res++;
          break;
        default:
          break;
      }
      p++;
    }
  }
  if (s21_is_digit(*p) || *p == '*') {
    if (*p == '*') {
      opt->width = va_arg(args, int);
      p++;
      res++;
    } else {
      char p1[10];
      int i = 0;
      while (s21_is_digit(*p)) {
        p1[i] = *p;
        p++;
        res++;
        i++;
      }
      p1[i] = '\0';
      opt->width = s21_atoi(p1);
    }
  }
  if (*p == '.') {
    p++;
    res++;
    if (s21_is_digit(*p) || *p == '*') {
      if (*p == '*') {
        opt->precision = va_arg(args, int);
        p++;
        res++;
      } else {
        char p1[10];
        int i = 0;
        while (s21_is_digit(*p)) {
          p1[i] = *p;
          p++;
          res++;
          i++;
        }
        p1[i] = '\0';
        opt->precision = s21_atoi(p1);
      }
    }
  }
  if (s21_is_delim(*p, length)) {
    switch (*p) {
      case 'h':
        opt->len_h++;
        p++;
        res++;
        break;
      case 'l':
        opt->len_l++;
        p++;
        res++;
        break;
      case 'L':
        opt->len_L++;
        p++;
        res++;
        break;
      default:
        break;
    }
    p++;
  }

  return res;  // возвращает количество обработанных символов, 0 в случае ошибки
}

int s21_vsprintf(char *str, const char *format, va_list args) {
  int flag = 0;
  if (str == S21_NULL || format == S21_NULL) flag = 1;
  int res = 0;
  if (!flag) {
    char *p = str;
    while (*format) {
      if (*format != '%') {
        *p = *format;
        p++;
        res++;
      } else {
        format++;
        s21_sprintf_opt opt;
        s21_sprintf_opt_init(&opt);
        int step = s21_sprintf_opt_parse(&opt, format, args);
        // if (step == 0) {
        //   flag = 1;
        //   break;
        // }

        printf("opt width: %d\n", opt.width);
        printf("opt precision: %d\n", opt.precision);
        printf("opt len_h: %d\n", opt.len_h);
        printf("opt len_l: %d\n", opt.len_l);
        printf("opt len_L: %d\n", opt.len_L);
        printf("opt fl_minus: %d\n", opt.fl_minus);
        printf("opt fl_plus: %d\n", opt.fl_plus);
        printf("opt fl_space: %d\n", opt.fl_space);
        printf("opt fl_hash: %d\n", opt.fl_hash);
        printf("opt fl_zero: %d\n", opt.fl_zero);
        printf("opt specifier: %c\n", opt.specifier);
        printf("*format: %c\n", *format);

        format += step - 1;  // -1 т.к. в конце цикла format++
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
