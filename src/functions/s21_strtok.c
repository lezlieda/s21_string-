#include "../s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  int flag = 0;
  static char *last;  // класс static позволяет сохранять значение переменной
                      // между вызовами функции
  char *res;
  if (str == s21_NULL) {
    str = last;  // если str == NULL, то берем последнее значение str
  }
  if (str == s21_NULL) {
    flag = 1;  // если str == NULL, то возвращаем NULL
  }
  if (!flag) {
    while (s21_is_delim(*str, delim)) {
      str++;  // пропускаем все разделители
    }
    if (*str == '\0') {
      flag = 1;  // если строка закончилась, то возвращаем NULL
    }
    res = str;
    while (*str != '\0' && !s21_is_delim(*str, delim)) {
      str++;  // ищем конец строки или разделитель
    }
    if (*str != '\0') {
      *str = '\0';  // если строка не закончилась, то ставим терминатор
      str++;  // и переходим к следующему символу
    }
    last = str;  // запоминаем последнее значение str
  }
  if (flag) res = s21_NULL;
  return res;
}
