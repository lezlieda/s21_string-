#include "../s21_string.h"

char *s21_strstr(char *str, char *substr) {
  char *p = str;
  int flag = 0;
  while (*p != '\0') {  // перебираем все символы строки до терминатора
    if (*p == *substr) {  // если совпадали первые символы
      char *p1 = p;  // сравниваем указатели на начало слова и подстроки
      char *p2 = substr;
      while (*p1 == *p2 && *p1 != '\0') {
        p1++;
        p2++;
      }
      if (*p2 == '\0') {
        flag = 1;  // если строки совпали, то возвращаем указатель на начало
        break;
      }
    }
    p++;
  }
  if (!flag) {
    p = S21_NULL;  // если подстрока не найдена, то возвращаем NULL
  }
  if (*substr == '\0') {
    p = str;  // если подстрока пустая, то возвращаем указатель на начало строки
  }
  return p;
}
