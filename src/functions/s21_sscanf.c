#include "../s21_string.h"

int is_space(char c) { return (c == ' ' || c == '\t' || c == '\n'); }

int is_hex(char c) {
  return ('0' <= c && c <= '9') || ('A' <= c && c <= 'F') ||
         ('a' <= c && c <= 'f');
}

int is_octa(char c) { return ('0' <= c && c <= '7'); }

int is_spec(char c) {
  return (c == 'c' || c == 'd' || c == 'i' || c == 'f' || c == 's' ||
          c == 'u' || c == '%' || c == 'G' || c == 'g' || c == 'o' ||
          c == 'x' || c == 'X' || c == 'p' || c == 'n' || c == 'e' || c == 'E');
}

int is_digit(char c) { return (c >= '0' && c <= '9'); }

int hexchar_to_digit(char c) {
  int digit = 16;
  if (c == 'A' || c == 'a')
    digit = 10;
  else if (c == 'B' || c == 'b')
    digit = 11;
  else if (c == 'C' || c == 'c')
    digit = 12;
  else if (c == 'D' || c == 'd')
    digit = 13;
  else if (c == 'E' || c == 'e')
    digit = 14;
  else if (c == 'F' || c == 'f')
    digit = 15;
  else
    digit = c - 0x30;
  return digit;
}

int s21_getchar(char **str, char *c) {
  int result = **str ? 1 : 0;
  *c = **str;
  return result;
}

int s21_getstring(char **str, char *string, Token *tk) {
  int res = **str ? 1 : 0;
  int width = tk->width ? tk->width : INT_MAX;
  while (**str && !(is_space(**str)) && width) {
    width--;
    s21_getchar(str, string);
    string++;
    (*str)++;
  }
  *string = '\0';
  return res;
}

ll s21_stoi(char **data, Token *tk) {
  int res = -1;
  int width = tk->width ? tk->width : INT_MAX;
  if (**data == '-' && width) {
    tk->sign = -1;
    (*data)++;
    width--;
  }
  if (**data == '+' && width) {
    (*data)++;
    width--;
  }
  if (is_digit(**data) && width) res = 0;

  while (is_digit(**data) && width) {
    width--;
    res *= 10;
    res += (**data - '0');
    (*data)++;
  }
  return res;
}

ll hex_to_dec(char **data, Token *tk) {
  ll res = -1;
  ll base = 1;
  int width = tk->width ? tk->width : INT_MAX;
  if (**data == '-') {
    tk->sign = -1;
    (*data)++;
    width--;
  }
  if (**data == '+') {
    (*data)++;
    width--;
  }
  if ((*data)[0] == '0' && ((*data)[1] == 'x' || (*data)[1] == 'X') && width) {
    res = 0;
    (*data)++;
    (*data)++;
    width -= 2;
  } else if ((*data)[0] == '0' && width) {
    res = 0;
    (*data)++;
    width--;
  }
  if (is_hex(**data) && (width)) {
    int move = 0;
    res = 0;
    while (is_hex(**data) && (width)) {
      width--;
      move++;
      (*data)++;
    }
    char *copy = *data - 1;
    while (move) {
      res += hexchar_to_digit(*copy) * base;
      move--;
      (copy)--;
      base *= 16;
    }
  }
  return res;
}

ll octa_to_int(char **data, Token *tk) {
  ll res = -1;
  ll base = 1;
  int move = 0;
  int width = tk->width ? tk->width : INT_MAX;
  if (**data == '-') {
    tk->sign = -1;
    (*data)++;
    width--;
  }
  if (**data == '+') {
    (*data)++;
    width--;
  }
  if (is_octa(**data) && width)
    res = 0;
  else
    (*data)--;
  while (is_octa(**data) && width) {
    width--;
    move++;
    (*data)++;
  }
  char *copy = *data - 1;
  while (move) {
    res += (*copy - '0') * base;
    move--;
    copy--;
    base *= 8;
  }
  return res;
}

ll get_any_number(char **data, Token *tk) {
  int res = -1;
  int width = tk->width ? tk->width : INT_MAX;
  if (**data == '-') {
    tk->sign = -1;
    (*data)++;
    width--;
  }
  if (**data == '+') {
    (*data)++;
    width--;
  }
  if ((*data)[0] == '0' && ((*data)[1] == 'x' || (*data)[1] == 'X') && width) {
    tk->width = width;
    res = 0;
    res += hex_to_dec(data, tk);
  } else if ((*data)[0] == '0' && width) {
    tk->width = width;
    res = 0;
    res += octa_to_int(data, tk);
  } else if (width) {
    tk->width = width;
    res = 0;
    res += s21_stoi(data, tk);
  }
  return res;
}

ll func_for_int(Token *tk, char **data) {
  ll b = -1;
  if (tk->spec == 'o') b = octa_to_int(data, tk) * tk->sign;
  if (tk->spec == 'u') b = s21_stoi(data, tk) * tk->sign;
  if (tk->spec == 'x' || tk->spec == 'X') b = hex_to_dec(data, tk) * tk->sign;
  if (tk->spec == 'i') b = get_any_number(data, tk) * tk->sign;
  if (tk->spec == 'd') b = s21_stoi(data, tk) * tk->sign;
  if (tk->spec == 'p') b = hex_to_dec(data, tk);
  return b;
}

void implementation_int(Token *tk, int *res, va_list *args, char **data) {
  ll b = func_for_int(tk, data);
  if (tk->spec == 'o' || tk->spec == 'u' || tk->spec == 'x' ||
      tk->spec == 'X') {
    if (tk->length_h) {
      unsigned short int *a = va_arg(*args, unsigned short int *);
      if (b != -1) {
        *a = b;
        (*res)++;
      }
    } else if (tk->length_l) {
      unsigned long int *a = va_arg(*args, unsigned long int *);
      if (b != -1) {
        *a = b;
        (*res)++;
      }
    } else {
      unsigned int *a = va_arg(*args, unsigned int *);
      if (b != -1) {
        *a = b;
        (*res)++;
      }
    }
  }
  if (tk->spec == 'd' || tk->spec == 'i') {
    if (tk->length_h) {
      short int *a = va_arg(*args, short int *);
      if (b != -1) {
        *a = b;
        (*res)++;
      }
    } else if (tk->length_l) {
      long int *a = va_arg(*args, long int *);
      if (b != -1) {
        *a = b;
        (*res)++;
      }
    } else {
      int *a = va_arg(*args, int *);
      if (b != -1) {
        *a = b;
        (*res)++;
      }
    }
  }
  if (tk->spec == 'p') {
    void **a = va_arg(*args, void **);
    if (b != -1) {
      *a = (void *)b;
      (*res)++;
    }
  }
}

void token_config(char **fmt, Token *tk) {
  while (**fmt) {
    if (**fmt == '*') tk->width_star = 1;
    if (is_digit(**fmt)) {
      tk->width = s21_stoi(fmt, tk);
    }
    if (**fmt == '%') break;
    if (**fmt == 'h') tk->length_h = 1;
    if (**fmt == 'l') tk->length_l = 1;
    if (**fmt == 'L') tk->length_L = 1;
    if (is_spec(**fmt)) {
      tk->spec = **fmt;
      break;
    }
    (*fmt)++;
  }
}

void reset_specs(Token *tk) {
  tk->width = 0;
  tk->width_star = 0;
  tk->length_l = 0;
  tk->length_h = 0;
  tk->length_L = 0;
  tk->sign = 1;
  tk->spec = '\0';
}

int what_sign(char c) {
  int res = 0;
  if (c == '-') res = -1;
  if (c == '+') res = 1;
  return res;
}

int is_inf(const char *str) {
  int res = 0;
  if ((str[0] == 'i' || str[0] == 'I') && (str[1] == 'n' || str[1] == 'N') &&
      (str[2] == 'f' || str[2] == 'F'))
    res = 1;
  return res;
}

int is_nan(const char *str) {
  int res = 0;
  if ((str[0] == 'n' || str[0] == 'N') && (str[1] == 'a' || str[1] == 'A') &&
      (str[2] == 'n' || str[2] == 'N'))
    res = 1;
  return res;
}

void final_float(Token *tk, int *res, va_list *args, long double ans) {
  if (tk->length_L) {
    long double *a = va_arg(*args, long double *);
    *a = ans;
    if (*a) (*res)++;
  } else if (tk->length_l) {
    double *a = va_arg(*args, double *);
    *a = ans;
    if (*a) (*res)++;
  } else {
    float *a = va_arg(*args, float *);
    *a = ans;
    if (*a) (*res)++;
  }
}

long double mantissa(char **data, int *width) {
  long double res = 0;
  int sign = 1;
  int state1 = (**data == 'E' || **data == 'e');
  int state2 = ((*(*data + 1) >= '0') && (*(*data + 1) <= '9'));
  int state3 = (*(*data + 1) == '-' || *(*data + 1) == '+');
  if (state1 && (state2 || state3) && (*width)--) {
    (*data)++;
    if (**data == '-') sign *= -1;
    if ((**data == '-' || **data == '+') && *width) {
      (*data)++;
      (*width)--;
    }
    while ((**data >= '0' && **data <= '9') && (*width)--) {
      res *= 10;
      res += hexchar_to_digit(**data);
      (*data)++;
    }
  }
  return pow(10, (res * sign));
}

long double get_float(char **str, Token *tk) {
  int width = tk->width ? tk->width : INT_MAX;
  int signIs = what_sign(**str);
  long double final = 0;
  if (signIs && (width > 1) && (is_inf(*str + 1) || is_nan(*str + 1))) {
    (*str)++;
    width--;
  }
  if ((is_inf(*str) || is_nan(*str)) && width >= 3) {
    if (is_inf(*str)) {
      final = signIs / 0.0;
      (*str) += 3;
      // width -= 3;
    }
    if (is_nan(*str)) {
      final = NAN;
      (*str) += 3;
      // width -= 3;
    }
  } else {
    int del = 1;
    long double res_int = 0;
    long double res_float = 0;
    if (**str == '-') {
      tk->sign = -1;
      (*str)++;
      width--;
    }
    if (**str == '+') {
      tk->sign = 1;
      (*str)++;
      width--;
    }
    while ((**str >= '0' && **str <= '9') && width--) {
      res_int *= 10;
      res_int += hexchar_to_digit(**str);
      (*str)++;
    }
    if (**str == '.' && width--) {
      (*str)++;
      while ((**str >= '0' && **str <= '9') && width--) {
        res_float *= 10;
        res_float += hexchar_to_digit(**str);
        del *= 10;
        (*str)++;
      }
    }
    long double multiplier = mantissa(str, &width);
    res_float /= del;
    final = multiplier * (res_int + res_float) * (tk->sign);
  }
  return final;
}

int s21_sscanf(const char *str, const char *format, ...) {
  Token tk = {0};
  char *data = (char *)str, *fmt = (char *)format;
  va_list args;
  va_start(args, format);
  int res = *str ? 0 : -1;
  while (*fmt && *data) {
    if (*fmt == '%') {
      fmt++;
      reset_specs(&tk);
      token_config(&fmt, &tk);
      if (tk.spec == 'c') {
        if (!tk.width_star) {
          char *s = (char *)va_arg(args, char *);
          res += s21_getchar(&data, s);
        }
        data++;
      }
      while (is_space(*data) && tk.spec != 'c') data++;
      if (tk.spec == 's') {
        while (is_space(*data)) data++;
        char ans1[512];
        char *ans = ans1;
        int resForStr = s21_getstring(&data, ans, &tk);
        if (!tk.width_star) {
          char *s = (char *)va_arg(args, char *);
          s21_getstring(&ans, s, &tk);

          res += resForStr;
        }
      }
      if (tk.spec == 'o' || tk.spec == 'u' || tk.spec == 'x' ||
          tk.spec == 'X' || tk.spec == 'd' || tk.spec == 'i' ||
          tk.spec == 'p') {
        if (!tk.width_star) {
          implementation_int(&tk, &res, &args, &data);
        }
      }
      if (tk.spec == 'n') {
        if (!tk.width_star) {
          int *a = va_arg(args, int *);
          *a = (int)(data - str);
        }
      }
      if (tk.spec == 'e' || tk.spec == 'E' || tk.spec == 'f' ||
          tk.spec == 'g' || tk.spec == 'G') {
        while (is_space(*data)) data++;

        long double ans = get_float(&data, &tk);
        if (!tk.width_star) {
          final_float(&tk, &res, &args, ans);
        }
      }
    } else if (*data == *fmt) {
      data++;
    }
    fmt++;
    va_end(args);
  }
  return res;
}
