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

int s21_utoa(char *dest, unsigned long long num, int base) {
  int i = 0;
  do {
    unsigned long long rem = (unsigned long long)num % base;
    dest[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
  } while (num /= base);
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
        numbuf[i++] = *format++;
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
        numbuf[i++] = *format++;
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
    int char_width = 2;
    if (c > 2047 && c < 65535) {
      char_width = 3;
    } else if (c > 65535) {
      char_width = 4;
    }
    wcstombs(NULL, wstr, 0);
    char *str = (char *)malloc(sizeof(char) * (char_width + 1));
    wcstombs(str, wstr, char_width + 1);
    if (opt.fl_minus == 1) {
      for (int i = 0; i < char_width; i++) {
        s21_putch(&dest, str[i]);
        res++;
      }
      for (int i = char_width; i < opt.width; i++) {
        s21_putch(&dest, ' ');
        res++;
      }
    } else {
      for (int i = char_width; i < opt.width; i++) {
        s21_putch(&dest, ' ');
        res++;
      }
      for (int i = 0; i < char_width; i++) {
        s21_putch(&dest, str[i]);
        res++;
      }
    }
    free(str);
  } else {
    if (opt.width < 2) {
      s21_putch(&dest, sym);
      res++;
    } else {
      if (opt.fl_minus == 1) {
        s21_putch(&dest, sym);
        res++;
        for (int i = 1; i < opt.width; i++) {
          s21_putch(&dest, ' ');
          res++;
        }
      } else {
        char ins = ' ';
        if (opt.fl_zero == 1) {
          ins = '0';
        }
        for (int i = 1; i < opt.width; i++) {
          s21_putch(&dest, ins);
          res++;
        }
        s21_putch(&dest, sym);
        res++;
      }
    }
  }
  *dest = '\0';
  return res;
}

int s21_sprinter_int(char *dest, s21_sprintf_opt opt, long long int c) {
  int res = 0;
  char *strptr = dest;
  int len = 0;
  int sign = 0;
  long long int num = c;
  if (opt.len_h == 1) {  // устанавливаем длину int в зависимости от флага
    num = (short int)num;
  } else if (opt.len_l == 1) {
    num = (long long int)num;
  } else {
    num = (int)num;
  }
  if (num < 0) {
    sign = 1;
    num = -num;
  }
  len = s21_utoa(strptr, num, 10);       // формируем строку
  if (opt.precision == 0 && num == 0) {  // специальный случай
    s21_strncpy(strptr, " ", 1);
    len--;
  }
  /***
   * добавляем знаки
   */
  if (sign == 1) {
    char *tmp = s21_insert(strptr, "-", 0);
    s21_strncpy(strptr, tmp, len + 1);
    free(tmp);
    len++;
  } else if (opt.fl_plus == 1) {
    char *tmp = s21_insert(strptr, "+", 0);
    s21_strncpy(strptr, tmp, len + 1);
    free(tmp);
    len++;
  } else if (opt.fl_space == 1) {
    char *tmp = s21_insert(strptr, " ", 0);
    s21_strncpy(strptr, tmp, len + 1);
    free(tmp);
    len++;
  }
  /***
   * добавляем пробелы и нули
   */
  int pos = 0;  // смещение для добавления знаков
  if (sign == 1 || opt.fl_plus == 1 || opt.fl_space == 1) {
    pos = 1;
  }
  if (opt.precision > len - 1) {  // добавляем нули
    int op = opt.precision - len + pos;
    while (op-- > 0) {
      char *tmp = s21_insert(strptr, "0", pos);
      s21_strncpy(strptr, tmp, len + 1);
      free(tmp);
      len++;
    }
  }
  if (opt.width > len) {  // добавляем пробелы
    int ow = opt.width - len;
    while (ow-- > 0) {
      if (opt.fl_minus == 1) {
        char *tmp = s21_insert(strptr, " ", len);
        s21_strncpy(strptr, tmp, len + 1);
        free(tmp);
      } else {
        if (opt.fl_zero == 1 && opt.precision == -1) {
          char *tmp = s21_insert(strptr, "0", pos);
          s21_strncpy(strptr, tmp, len + 1);
          free(tmp);
        } else {
          char *tmp = s21_insert(strptr, " ", 0);
          s21_strncpy(strptr, tmp, len + 1);
          free(tmp);
        }
      }
      len++;
    }
  }
  res = len;
  return res;
}

int s21_sprinter_uint(char *dest, s21_sprintf_opt opt,
                      unsigned long long int c) {
  char *strptr = dest;
  int len = 0;
  unsigned long long int num = 0;
  if (opt.len_h == 1) {  // устанавливаем длину int в зависимости от флага
    num = (unsigned short int)c;
  } else if (opt.len_l == 1 || opt.spec == 'p') {
    num = (unsigned long int)c;
  } else {
    num = (unsigned int)c;
  }
  int base = 0;
  switch (opt.spec) {
    case 'o':
      base = 8;
      break;
    case 'x':
      base = 16;
      break;
    case 'X':
      base = 16;
      break;
    case 'u':
      base = 10;
      break;
    case 'p':
      base = 16;
      break;
  }
  len = s21_utoa(strptr, num, base);   // формируем строку в str
  if (opt.fl_hash == 1 && num != 0) {  // флаг #
    if (opt.spec == 'o') {
      char *tmp = s21_insert(strptr, "0", 0);
      s21_strncpy(strptr, tmp, len + 1);
      len++;
      free(tmp);
    } else if (opt.spec == 'x' || opt.spec == 'X') {
      char *tmp = s21_insert(strptr, "0x", 0);
      s21_strncpy(strptr, tmp, len + 2);
      len += 2;
      free(tmp);
    }
  }
  if (opt.precision == 0 &&
      num == 0) {  // специальный случай, если точность 0 и число 0
    s21_strncpy(strptr, " ", 1);
    len--;
  }
  if (opt.spec == 'p') {
    char *tmp = s21_insert(strptr, "0x", 0);
    s21_strncpy(strptr, tmp, len + 2);
    len += 2;
    free(tmp);
  }
  // добавляем пробелы и нули
  int pos = 0;  // смещение для добавления знаков
  if (((opt.spec == 'x' || opt.spec == 'X') && opt.fl_hash == 1 && num != 0) ||
      opt.spec == 'p') {
    pos = 2;
  } else if (opt.spec == 'o' && opt.fl_hash == 1 && num != 0) {
    pos = 1;
  }
  if (opt.precision > len - pos) {
    int op = opt.precision - len + pos;
    if (opt.spec == 'o' && opt.fl_hash == 1 && num != 0) {
      op--;
    }
    while (op-- > 0) {
      char *tmp = s21_insert(strptr, "0", pos);
      s21_strncpy(strptr, tmp, len + 1);
      free(tmp);
      len++;
    }
  }
  if (opt.width > len) {
    int ow = opt.width - len;
    while (ow-- > 0) {
      if (opt.fl_minus == 1) {
        char *tmp = s21_insert(strptr, " ", len);
        s21_strncpy(strptr, tmp, len + 1);
        free(tmp);
      } else {
        if (opt.fl_zero == 1 && opt.precision == -1) {
          char *tmp = s21_insert(strptr, "0", pos);
          s21_strncpy(strptr, tmp, len + 1);
          free(tmp);
        } else {
          char *tmp = s21_insert(strptr, " ", 0);
          s21_strncpy(strptr, tmp, len + 1);
          free(tmp);
        }
      }
      len++;
    }
  }
  if (opt.spec == 'X') {
    char *tmp = s21_to_upper(strptr);
    s21_strncpy(strptr, tmp, len);
    free(tmp);
  }
  return len;
}

size_t s21_wcslen(const wchar_t *s) {
  size_t len = 0;
  while (*s++ != L'\0') {
    len++;
  }
  return len;
}

int s21_wstrToStr(char **dest, wchar_t *wstr) {
  s21_size_t res = 0;
  int wlen = 0;
  wlen = s21_wcslen(wstr);
  char *str = (char *)malloc(wlen * 4 + 1);
  *dest = str;
  res = wcstombs(str, wstr, wlen * 4 + 1);
  return res;
}

int s21_sprinter_str(char *dest, s21_sprintf_opt opt, char *c) {
  char *strptr = dest;
  int len = 0;
  if (c == NULL) {
    c = "(null)";
  }
  len = s21_strlen(c);
  if (opt.precision < len && opt.precision != -1) {  // если точность меньше
    len = opt.precision;  // длины строки - обрезаем строку до точности
  }
  s21_strncpy(strptr, c, len);
  if (opt.precision == 0) {  // если точность 0 - строка пустая
    s21_strncpy(strptr, "", 0);
    len = 0;
  }
  if (opt.width > len) {  // если ширина больше длины строки - добавляем пробелы
    int ow = opt.width - len;
    while (ow-- > 0) {
      if (opt.fl_minus == 1) {
        char *tmp = s21_insert(strptr, " ", len);
        s21_strncpy(strptr, tmp, len + 1);
        free(tmp);
      } else {
        char ins[2] = " ";
        if (opt.fl_zero == 1) {
          ins[0] = '0';
        }
        char *tmp = s21_insert(strptr, ins, 0);
        s21_strncpy(strptr, tmp, len + 1);
        free(tmp);
      }
      len++;
    }
  }
  return len;
}

long double s21_pow(int a, int b) {
  long double res = 1;
  while (b-- > 0) {
    res *= a;
  }
  return res;
}

int s21_sprinter_float(char *dest, s21_sprintf_opt opt, double c) {
  char *strptr = dest;
  int len = 0;
  int sign = 0;
  double num = c;
  int flag = 0;
  if (opt.precision == -1) opt.precision = 6;  // дефолтная точность
  if (c != c) {  // специальные значения
    flag = 1;
    opt.precision = 0;
    // if (opt.width < 3) opt.width = 3;
  } else if (c == INFINITY) {
    flag = 2;
    opt.precision = 0;
  } else if (c == -INFINITY) {
    flag = 3;
    opt.precision = 0;
  }
  if (num < 0 || 1. / num < 0) {
    sign = 1;
    num = -num;
  }
  /***
   * записываем число в строку
   */
  if (flag == 1) {
    s21_strncpy(strptr, "nan", 3);
    len = 3;
  } else if (flag == 2 || flag == 3) {
    s21_strncpy(strptr, "inf", 3);
    len = 3;
  } else {
    // записываем целую часть
    double intpart = 0;
    double fracpart = modf(num, &intpart);
    double rcount = intpart;
    int range = 0;
    while (rcount >= 1) {
      rcount /= 10;
      range++;
    }
    if (range == 0) range = 1;
    if (opt.precision == 0 && fracpart > 0.5) intpart++;
    while (range-- > 0) {
      int d = intpart / s21_pow(10, range);
      intpart -= (double)d * s21_pow(10, range);
      char num[2];
      s21_utoa(num, d, 10);
      char *tmp = s21_insert(strptr, num, len);
      s21_strncpy(strptr, tmp, len + 1);
      free(tmp);
      len++;
    }
    // записываем дробную часть
    if (opt.precision > 0 || opt.fl_hash == 1) {
      char *tmp = s21_insert(strptr, ".", len);
      s21_strncpy(strptr, tmp, len + 1);
      free(tmp);
      len++;
      while (opt.precision-- > 0) {
        fracpart *= 10;
        int d =
            opt.precision == 0 ? (int)(fracpart + 0.5) : (int)(fracpart + .01);
        fracpart = modf(fracpart, &intpart);
        if (d == 10) {
          d = 0;
        }
        char num[2];
        s21_utoa(num, d, 10);
        char *tmp = s21_insert(strptr, num, len);
        s21_strncpy(strptr, tmp, len + 1);
        free(tmp);
        len++;
      }
    }
  }
  /***
   * добавляем знаки
   */
  int pos = 0;
  if (sign == 1 || opt.fl_plus == 1 || opt.fl_space == 1) {
    char fl[2] = "\0";
    if (sign == 1) {
      fl[0] = '-';
    } else if (opt.fl_plus == 1) {
      if (flag == 1) {
        len--;
      } else {
        fl[0] = '+';
      }
    } else if (opt.fl_space == 1) {
      if (flag == 1) {
        len--;
      } else {
        fl[0] = ' ';
      }
    }
    char *tmp = s21_insert(strptr, fl, 0);
    s21_strncpy(strptr, tmp, s21_strlen(tmp));
    free(tmp);
    len++;
    pos++;
  }
  if (opt.precision > len - pos) {
    int op = opt.precision - len + pos;
    if (opt.spec == 'o' && opt.fl_hash == 1 && num != 0) {
      op--;
    }
    while (op-- > 0) {
      char *tmp = s21_insert(strptr, "0", pos);
      s21_strncpy(strptr, tmp, len + 1);
      free(tmp);
      len++;
    }
  }
  if (opt.width > len) {
    int ow = opt.width - len;
    while (ow-- > 0) {
      if (opt.fl_minus == 1) {
        char *tmp = s21_insert(strptr, " ", len);
        s21_strncpy(strptr, tmp, len + 1);
        free(tmp);
      } else {
        if (opt.fl_zero == 1 && opt.precision == -1) {
          char *tmp = s21_insert(strptr, "0", pos);
          s21_strncpy(strptr, tmp, len + 1);
          free(tmp);
        } else {
          char *tmp = s21_insert(strptr, " ", 0);
          s21_strncpy(strptr, tmp, len + 1);
          free(tmp);
        }
      }
      len++;
    }
  }
  /***
   * добавляем пробелы или нули
   */
  // if (opt.width > len) {
  //   int ow = opt.width - len;
  //   while (ow-- > 0) {
  //     if (opt.fl_minus == 1) {
  //       char *tmp = s21_insert(strptr, " ", len);
  //       s21_strncpy(strptr, tmp, s21_strlen(tmp));
  //       free(tmp);
  //     } else {
  //       if (opt.fl_zero == 1 && !flag) {
  //         int pos = 0;
  //         if (sign == 1 || opt.fl_plus == 1 || opt.fl_space == 1) pos = 1;
  //         char *tmp = s21_insert(strptr, "0", pos);
  //         s21_strncpy(strptr, tmp, s21_strlen(tmp));
  //         free(tmp);
  //       } else {
  //         char *tmp = s21_insert(strptr, " ", 0);
  //         s21_strncpy(strptr, tmp, s21_strlen(tmp));
  //         free(tmp);
  //       }
  //     }
  //     len++;
  //   }
  // }
  return len;
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
      char *tmp;
      switch (opt.spec) {
        case 'c':
          step = s21_sprinter_char(str, opt, va_arg(args, int));
          res += step;
          str += step;
          break;
        case 'd':
        case 'i':
          if (opt.len_l == 1) {
            step = s21_sprinter_int(str, opt, va_arg(args, long int));
          } else {
            step = s21_sprinter_int(str, opt, va_arg(args, int));
          }
          res += step;
          str += step;
          break;
        case 'u':
          step =
              s21_sprinter_uint(str, opt, va_arg(args, unsigned long long int));
          res += step;
          str += step;
          break;
        case 's':
          if (opt.len_l == 1) {
            s21_wstrToStr(&tmp, va_arg(args, wchar_t *));
            step = s21_sprinter_str(str, opt, tmp);
            free(tmp);
          } else {
            step = s21_sprinter_str(str, opt, va_arg(args, char *));
          }
          res += step;
          str += step;
          break;
        case 'f':
          step = s21_sprinter_float(str, opt, va_arg(args, double));
          res += step;
          str += step;
          break;
        // case 'e':
        // case 'E':
        // case 'f':
        // case 'g':
        // case 'G':
        //   if (opt.len_L == 1) {
        //     step = s21_sprinter_float_L(str, opt, va_arg(args, long
        //     double));
        //   } else {
        //     step = s21_sprinter_float(str, opt, va_arg(args, double));
        //   }
        //   res += step;
        //   str += step;
        //   break;
        case 'p':
          step = s21_sprinter_uint(str, opt,
                                   (unsigned long long)va_arg(args, void *));
          res += step;
          str += step;
          break;
        case 'o':
          step =
              s21_sprinter_uint(str, opt, va_arg(args, unsigned long long int));
          res += step;
          str += step;
          break;
        case 'x':
          step =
              s21_sprinter_uint(str, opt, va_arg(args, unsigned long long int));
          res += step;
          str += step;
          break;
        case 'X':
          step =
              s21_sprinter_uint(str, opt, va_arg(args, unsigned long long int));
          res += step;
          str += step;
          break;
        case 'n':
          *va_arg(args, int *) = res;
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
