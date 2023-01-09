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
  do {
    long long rem = num % base;
    dest[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
  } while (num /= base);
  dest[i] = '\0';
  s21_strrev(dest);
  return i;
}

int s21_utoa(char *dest, unsigned long long int num, int base) {
  int i = 0;
  do {
    unsigned long long rem = num % base;
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
  // printf(
  //     "opt->fl_minus = %d\nopt->fl_plus = %d\nopt->fl_space =
  //     %d\nopt->fl_hash "
  //     "= %d\nopt->fl_zero = %d\nopt->width = %d\nopt->precision = "
  //     "%d\nopt->len_h = %d\nopt->len_l = %d\nopt->len_L = %d\nopt->spec =
  //     %c\n", opt->fl_minus, opt->fl_plus, opt->fl_space, opt->fl_hash,
  //     opt->fl_zero, opt->width, opt->precision, opt->len_h, opt->len_l,
  //     opt->len_L, opt->spec);
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
        for (int i = 1; i < opt.width; i++) {
          s21_putch(&dest, ' ');
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
  char str[64] = "\0";
  char *strptr = str;
  int len = 0;
  int sign = 0;
  long long int num = c;
  if (opt.len_h == 1) {  // устанавливаем длину int в зависимости от флага
    num = (short int)num;
  } else if (opt.len_l == 1) {
    num = (long int)num;
  } else {
    num = (int)num;
  }
  if (num < 0) {
    sign = 1;
    num = -num;
  }
  len = s21_itoa(strptr, num, 10);       // формируем строку
  if (opt.precision == 0 && num == 0) {  // специальный случай
    s21_strncpy(strptr, " ", 1);
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
      char *tmp = s21_insert(str, "0", pos);
      s21_strncpy(str, tmp, len + 1);
      free(tmp);
      len++;
    }
  }
  if (opt.width > len) {  // добавляем пробелы
    int ow = opt.width - len;
    while (ow-- > 0) {
      if (opt.fl_minus == 1) {
        char *tmp = s21_insert(str, " ", len);
        s21_strncpy(str, tmp, len + 1);
        free(tmp);
      } else {
        if (opt.fl_zero == 1) {
          char *tmp = s21_insert(str, "0", pos);
          s21_strncpy(str, tmp, len + 1);
          free(tmp);
        } else {
          char *tmp = s21_insert(str, " ", 0);
          s21_strncpy(str, tmp, len + 1);
          free(tmp);
        }
      }
      len++;
    }
  }
  s21_strncpy(dest, str, len);
  res = len;
  return res;
}

int s21_sprinter_uint(char *dest, s21_sprintf_opt opt,
                      unsigned long long int c) {
  int res = 0;
  char str[64] = "\0";
  char *strptr = str;
  int len = 0;
  unsigned long long int num = 0;
  if (opt.len_h == 1) {  // устанавливаем длину int в зависимости от флага
    num = (unsigned short int)c;
  } else if (opt.len_l == 1) {
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
  }
  /***
   * добавляем пробелы и нули
   */
  int pos = 0;  // смещение для добавления знаков
  if ((opt.spec == 'x' || opt.spec == 'X') && opt.fl_hash == 1 && num != 0) {
    pos = 2;
  } else if (opt.spec == 'o' && opt.fl_hash == 1 && num != 0) {
    pos = 1;
  }
  if (opt.precision > len) {
    int op = opt.precision - len + pos;
    if (opt.spec == 'o' && opt.fl_hash == 1 && num != 0) {
      op--;
    }
    while (op-- > 0) {
      char *tmp = s21_insert(str, "0", pos);
      s21_strncpy(str, tmp, len + 1);
      free(tmp);
      len++;
    }
  }
  if (opt.width > len) {
    int ow = opt.width - len;
    while (ow-- > 0) {
      if (opt.fl_minus == 1) {
        char *tmp = s21_insert(str, " ", len);
        s21_strncpy(str, tmp, len + 1);
        free(tmp);
      } else {
        if (opt.fl_zero == 1 && opt.precision == -1) {
          char *tmp = s21_insert(str, "0", pos);
          s21_strncpy(str, tmp, len + 1);
          free(tmp);
        } else {
          char *tmp = s21_insert(str, " ", 0);
          s21_strncpy(str, tmp, len + 1);
          free(tmp);
        }
      }
      len++;
    }
  }
  if (opt.spec == 'X') {
    char *tmp = s21_to_upper(str);
    s21_strncpy(str, tmp, len);
    free(tmp);
  }
  s21_strncpy(dest, str, len);
  res = len;
  return res;
}

int s21_sprinter_str(char *dest, s21_sprintf_opt opt, char *c) {
  int res = 0;
  char str[8196] = "\0";
  // char *strptr = str;
  int len = 0;
  len = s21_strlen(c);
  if (opt.precision < len && opt.precision != -1) {  // если точность меньше
    len = opt.precision;  // длины строки - обрезаем строку до точности
  }
  s21_strncpy(str, c, len);
  if (opt.width > len) {  // если ширина больше длины строки - добавляем пробелы
    int ow = opt.width - len;
    while (ow-- > 0) {
      if (opt.fl_minus == 1) {
        char *tmp = s21_insert(str, " ", len);
        s21_strncpy(str, tmp, len + 1);
        free(tmp);
      } else {
        char *tmp = s21_insert(str, " ", 0);
        s21_strncpy(str, tmp, len + 1);
        free(tmp);
      }
      len++;
    }
  }
  s21_strncpy(dest, str, len);
  res = len;

  return res;
}

long double s21_pow(int a, int b) {
  long double res = 1;
  while (b-- > 0) {
    res *= a;
  }
  return res;
}

int s21_sprinter_float(char *dest, s21_sprintf_opt opt, double c) {
  char str[128] = "\0";
  char *strptr = str;
  int len = 0;
  int sign = 0;
  double num = c;
  int flag = 0;
  if (opt.precision == -1) opt.precision = 6;  // дефолтная точность
  if (c != c) {  // специальные значения
    flag = 1;
    opt.precision = 0;
    if (opt.width < 3) opt.width = 3;
  } else if (c == INFINITY) {
    flag = 2;
    opt.precision = 0;
  } else if (c == -INFINITY) {
    flag = 3;
    opt.precision = 0;
  }
  if (num < 0 || 1. / num == -INFINITY) {
    sign = 1;
    num = -num;
  }
  long double tmp = num;
  /***
   * записываем в строку целую часть
   */
  if (flag == 1) {
    s21_strncpy(str, "nan", 3);
    len = 3;
  } else if (flag == 2 || flag == 3) {
    s21_strncpy(str, "inf", 3);
    len = 3;
  } else {
    int range = 0;  // определяем порядок
    while (tmp >= 1) {
      tmp /= 10;
      range++;
    }
    if (range == 0) range = 1;
    tmp = num;
    while (range-- > 0) {
      char sym[2] = "\0";
      long double c = tmp / s21_pow(10, range);
      long long int cc = (long long int)c;
      if (opt.precision == 0) {
        if (num < 1 && num > 0) {
          cc++;
        }
      }
      s21_itoa(sym, cc, 10);
      s21_putch(&strptr, sym[0]);
      len++;
      tmp -= (long long int)c * s21_pow(10, range);
    }
  }
  /****
   * записываем в строку дробную часть
   */
  if (opt.precision > 0 || opt.fl_hash == 1) {
    if (!flag) {
      s21_putch(&strptr, '.');
      len++;
    }
    if (opt.precision < 17 && opt.precision > 0) {
      long long int pr = (long long)s21_pow(10, opt.precision);
      long long int dec = (long long)(num * pr) % pr;
      char sym[128] = "\0";
      char *sym_ptr = sym;
      if (dec == 0) {
        while (opt.precision-- > 0) {
          s21_putch(&sym_ptr, '0');
        }
      } else {
        s21_itoa(sym, dec, 10);
      }
      s21_strncpy(strptr, sym, s21_strlen(sym));
      len += s21_strlen(sym);
    } else {
      while (opt.precision-- > 0) {
        long double c = tmp * 10;
        if (opt.precision == 0 && num != 0) c++;
        char sym[2] = "\0";
        s21_itoa(sym, (int)c, 10);
        s21_putch(&strptr, sym[0]);
        len++;
        tmp = c - (int)c;
      }
    }
  }
  /***
   * добавляем знаки
   */
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
    char *tmp = s21_insert(str, fl, 0);
    s21_strncpy(str, tmp, s21_strlen(tmp));
    free(tmp);
    len++;
  }
  /***
   * добавляем пробелы
   */
  if (opt.width > len) {
    int ow = opt.width - len;
    while (ow-- > 0) {
      if (opt.fl_minus == 1) {
        char *tmp = s21_insert(str, " ", len);
        s21_strncpy(str, tmp, s21_strlen(tmp));
        free(tmp);
      } else {
        if (opt.fl_zero == 1 && !flag) {
          int pos = 0;
          if (sign == 1 || opt.fl_plus == 1 || opt.fl_space == 1) pos = 1;
          char *tmp = s21_insert(str, "0", pos);
          s21_strncpy(str, tmp, s21_strlen(tmp));
          free(tmp);
        } else {
          char *tmp = s21_insert(str, " ", 0);
          s21_strncpy(str, tmp, s21_strlen(tmp));
          free(tmp);
        }
      }
      len++;
    }
  }

  s21_strncpy(dest, str, len);
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
          step = s21_sprinter_str(str, opt, va_arg(args, char *));
          res += step;
          str += step;
          break;
        case 'f':
          if (opt.len_L == 1) {
            // step = s21_sprinter_float_L(str, opt, va_arg(args, long
            // double));
          } else {
            step = s21_sprinter_float(str, opt, va_arg(args, double));
          }
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
