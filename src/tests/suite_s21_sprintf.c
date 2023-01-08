#include "../s21_string.h"
#include "../suitecases.h"

START_TEST(s21_sprintf_proc_1) {
  char dest[100];
  char s21_dest[100];
  sprintf(dest, "aa bb %% cc %%%% dd");
  s21_sprintf(s21_dest, "aa bb %% cc %%%% dd");
  ck_assert_str_eq(dest, s21_dest);
}
END_TEST

START_TEST(s21_sprintf_s_1) {
  char dest[100];
  char s21_dest[100];
  int s = sprintf(dest, "aa bb %s cc", "hello world");
  int s21 = s21_sprintf(s21_dest, "aa bb %s cc", "hello world");
  ck_assert_str_eq(dest, s21_dest);
  ck_assert_int_eq(s, s21);
}
END_TEST

START_TEST(s21_sprintf_s_2) {
  char dest[100];
  char s21_dest[100];
  int s = sprintf(dest, "aa bb %15s cc", "hello world");
  int s21 = s21_sprintf(s21_dest, "aa bb %15s cc", "hello world");
  ck_assert_str_eq(dest, s21_dest);
  ck_assert_int_eq(s, s21);
}
END_TEST

START_TEST(s21_sprintf_s_3) {
  char dest[100];
  char s21_dest[100];
  int s = sprintf(dest, "aa bb %-15s cc", "hello world");
  int s21 = s21_sprintf(s21_dest, "aa bb %-15s cc", "hello world");
  ck_assert_str_eq(dest, s21_dest);
  ck_assert_int_eq(s, s21);
}
END_TEST

START_TEST(s21_sprintf_s_4) {
  char dest[100];
  char s21_dest[100];
  int s = sprintf(dest, "aa bb %5s cc", "hello world");
  int s21 = s21_sprintf(s21_dest, "aa bb %5s cc", "hello world");
  ck_assert_str_eq(dest, s21_dest);
  ck_assert_int_eq(s, s21);
}
END_TEST

START_TEST(s21_sprintf_s_5) {
  char dest[100];
  char s21_dest[100];
  int s = sprintf(dest, "aa bb %*s cc", 15, "hello world");
  int s21 = s21_sprintf(s21_dest, "aa bb %*s cc", 15, "hello world");
  ck_assert_str_eq(dest, s21_dest);
  ck_assert_int_eq(s, s21);
}
END_TEST

START_TEST(s21_sprintf_s_6) {
  char dest[100];
  char s21_dest[100];
  int s = sprintf(dest, "aa bb %.*s cc", 5, "hello world");
  int s21 = s21_sprintf(s21_dest, "aa bb %.*s cc", 5, "hello world");
  ck_assert_str_eq(dest, s21_dest);
  ck_assert_int_eq(s, s21);
}
END_TEST

START_TEST(s21_sprintf_s_7) {
  char dest[100];
  char s21_dest[100];
  int s = sprintf(dest, "aa bb %.*s cc", 15, "hello world");
  int s21 = s21_sprintf(s21_dest, "aa bb %.*s cc", 15, "hello world");
  ck_assert_str_eq(dest, s21_dest);
  ck_assert_int_eq(s, s21);
}
END_TEST

START_TEST(s21_sprintf_s_8) {
  char dest[100];
  char s21_dest[100];
  int s = sprintf(dest, "aa bb %*.*s cc", 15, 13, "hello world");
  int s21 = s21_sprintf(s21_dest, "aa bb %*.*s cc", 15, 13, "hello world");
  ck_assert_str_eq(dest, s21_dest);
  ck_assert_int_eq(s, s21);
}
END_TEST

START_TEST(s21_sprintf_s_9) {
  char dest[100];
  char s21_dest[100];
  int s = sprintf(dest, "aa bb %-*.*s cc", 15, 5, "hello world");
  int s21 = s21_sprintf(s21_dest, "aa bb %-*.*s cc", 15, 5, "hello world");
  ck_assert_str_eq(dest, s21_dest);
  ck_assert_int_eq(s, s21);
}
END_TEST

/*
 * Test for %f
 */

START_TEST(s21_sprintf_f_1) {
  double value[10] = {-3.2321, -0.82, -0.0, 0.0,      0.616,
                      3.1415,  NAN,   -NAN, INFINITY, -INFINITY};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb % *.*f cc";
  int width = 1;
  int precision = 7;
  for (int i = 0; i < 10; i++) {
    int s = sprintf(dest, format, width, precision, value[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, value[i]);
    ck_assert_msg(s == s21, "\n\tvalue=%f\ns21_sprintf=%d; sprintf=%d;",
                  value[i], s21, s);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "\n\tvalue=%f\ns21_dest=%s;\n    dest=%s;", value[i],
                  s21_dest, dest);
  }
}
END_TEST

START_TEST(s21_sprintf_f_2) {
  double value[10] = {-3.2321, -0.82, -0.0, 0.0,      0.616,
                      3.1415,  NAN,   -NAN, INFINITY, -INFINITY};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb % *.*f cc";
  int width = 1;
  int precision = 0;
  for (int i = 0; i < 10; i++) {
    int s = sprintf(dest, format, width, precision, value[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, value[i]);
    ck_assert_msg(s == s21, "\n\tvalue=%f\ns21_sprintf=%d; sprintf=%d;",
                  value[i], s21, s);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "\n\tvalue=%f\ns21_dest=%s;\n    dest=%s;", value[i],
                  s21_dest, dest);
  }
}
END_TEST

START_TEST(s21_sprintf_f_3) {
  double value[10] = {-3.2321, -0.82, -0.0, 0.0,      0.616,
                      3.1415,  NAN,   -NAN, INFINITY, -INFINITY};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb % *.*f cc";
  int width = 10;
  int precision = 6;
  for (int i = 0; i < 10; i++) {
    int s = sprintf(dest, format, width, precision, value[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, value[i]);
    ck_assert_msg(s == s21, "\n\tvalue=%f\ns21_sprintf=%d; sprintf=%d;",
                  value[i], s21, s);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "\n\tvalue=%f\ns21_dest=%s;\n    dest=%s;", value[i],
                  s21_dest, dest);
  }
}
END_TEST

START_TEST(s21_sprintf_f_4) {
  double value[10] = {-3.2321, -0.82, -0.0, 0.0,      0.616,
                      3.1415,  NAN,   -NAN, INFINITY, -INFINITY};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb % *.*f cc";
  int width = 10;
  int precision = 0;
  for (int i = 0; i < 10; i++) {
    int s = sprintf(dest, format, width, precision, value[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, value[i]);
    ck_assert_msg(s == s21, "\n\tvalue=%f\ns21_sprintf=%d; sprintf=%d;",
                  value[i], s21, s);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "\n\tvalue=%f\ns21_dest=%s;\n    dest=%s;", value[i],
                  s21_dest, dest);
  }
}
END_TEST

START_TEST(s21_sprintf_f_5) {
  double value[10] = {-3.2321, -0.82, -0.0, 0.0,      0.616,
                      3.1415,  NAN,   -NAN, INFINITY, -INFINITY};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %-*.*f cc";
  int width = 1;
  int precision = 6;
  for (int i = 0; i < 10; i++) {
    int s = sprintf(dest, format, width, precision, value[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, value[i]);
    ck_assert_msg(s == s21, "\n\tvalue=%f\ns21_sprintf=%d; sprintf=%d;",
                  value[i], s21, s);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "\n\tvalue=%f\ns21_dest=%s;\n    dest=%s;", value[i],
                  s21_dest, dest);
  }
}
END_TEST

START_TEST(s21_sprintf_f_6) {
  double value[10] = {-3.2321, -0.82, -0.0, 0.0,      0.616,
                      3.1415,  NAN,   -NAN, INFINITY, -INFINITY};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %-*.*f cc";
  int width = 1;
  int precision = 0;
  for (int i = 0; i < 10; i++) {
    int s = sprintf(dest, format, width, precision, value[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, value[i]);
    ck_assert_msg(s == s21, "\n\tvalue=%f\ns21_sprintf=%d; sprintf=%d;",
                  value[i], s21, s);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "\n\tvalue=%f\ns21_dest=%s;\n    dest=%s;", value[i],
                  s21_dest, dest);
  }
}
END_TEST

START_TEST(s21_sprintf_f_7) {
  double value[10] = {-3.2321, -0.82, -0.0, 0.0,      0.616,
                      3.1415,  NAN,   -NAN, INFINITY, -INFINITY};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %-*.*f cc";
  int width = 10;
  int precision = 6;
  for (int i = 0; i < 10; i++) {
    int s = sprintf(dest, format, width, precision, value[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, value[i]);
    ck_assert_msg(s == s21, "\n\tvalue=%f\ns21_sprintf=%d; sprintf=%d;",
                  value[i], s21, s);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "\n\tvalue=%f\ns21_dest=%s;\n    dest=%s;", value[i],
                  s21_dest, dest);
  }
}
END_TEST

START_TEST(s21_sprintf_f_8) {
  double value[10] = {-3.2321, -0.82, -0.0, 0.0,      0.616,
                      3.1415,  NAN,   -NAN, INFINITY, -INFINITY};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %-*.*f cc";
  int width = 10;
  int precision = 0;
  for (int i = 0; i < 10; i++) {
    int s = sprintf(dest, format, width, precision, value[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, value[i]);
    ck_assert_msg(s == s21, "\n\tvalue=%f\ns21_sprintf=%d; sprintf=%d;",
                  value[i], s21, s);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "\n\tvalue=%f\ns21_dest=%s;\n    dest=%s;", value[i],
                  s21_dest, dest);
  }
}
END_TEST

START_TEST(s21_sprintf_f_9) {
  double value[10] = {-3.2321, -0.82, -0.0, 0.0,      0.616,
                      3.1415,  NAN,   -NAN, INFINITY, -INFINITY};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %+*.*f cc";
  int width = 1;
  int precision = 6;
  for (int i = 0; i < 10; i++) {
    int s = sprintf(dest, format, width, precision, value[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, value[i]);
    ck_assert_msg(s == s21, "\n\tvalue=%f\ns21_sprintf=%d; sprintf=%d;",
                  value[i], s21, s);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "\n\tvalue=%f\ns21_dest=%s;\n    dest=%s;", value[i],
                  s21_dest, dest);
  }
}
END_TEST

START_TEST(s21_sprintf_f_10) {
  double value[10] = {-3.2321, -0.82, -0.0, 0.0,      0.616,
                      3.1415,  NAN,   -NAN, INFINITY, -INFINITY};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %+*.*f cc";
  int width = 1;
  int precision = 0;
  for (int i = 0; i < 10; i++) {
    int s = sprintf(dest, format, width, precision, value[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, value[i]);
    ck_assert_msg(s == s21, "\n\tvalue=%f\ns21_sprintf=%d; sprintf=%d;",
                  value[i], s21, s);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "\n\tvalue=%f\ns21_dest=%s;\n    dest=%s;", value[i],
                  s21_dest, dest);
  }
}
END_TEST

START_TEST(s21_sprintf_f_11) {
  double value[10] = {-3.2321, -0.82, -0.0, 0.0,      0.616,
                      3.1415,  NAN,   -NAN, INFINITY, -INFINITY};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %+*.*f cc";
  int width = 10;
  int precision = 6;
  for (int i = 0; i < 10; i++) {
    int s = sprintf(dest, format, width, precision, value[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, value[i]);
    ck_assert_msg(s == s21, "\n\tvalue=%f\ns21_sprintf=%d; sprintf=%d;",
                  value[i], s21, s);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "\n\tvalue=%f\ns21_dest=%s;\n    dest=%s;", value[i],
                  s21_dest, dest);
  }
}
END_TEST

START_TEST(s21_sprintf_f_12) {
  double value[10] = {-3.2321, -0.82, -0.0, 0.0,      0.616,
                      3.1415,  NAN,   -NAN, INFINITY, -INFINITY};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %+*.*f cc";
  int width = 10;
  int precision = 0;
  for (int i = 0; i < 10; i++) {
    int s = sprintf(dest, format, width, precision, value[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, value[i]);
    ck_assert_msg(s == s21, "\n\tvalue=%f\ns21_sprintf=%d; sprintf=%d;",
                  value[i], s21, s);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "\n\tvalue=%f\ns21_dest=%s;\n    dest=%s;", value[i],
                  s21_dest, dest);
  }
}
END_TEST

START_TEST(s21_sprintf_f_13) {
  double value[10] = {-3.2321, -0.82, -0.0, 0.0,      0.616,
                      3.1415,  NAN,   -NAN, INFINITY, -INFINITY};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %0*.*f cc";
  int width = 1;
  int precision = 6;
  for (int i = 0; i < 10; i++) {
    int s = sprintf(dest, format, width, precision, value[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, value[i]);
    ck_assert_msg(s == s21, "\n\tvalue=%f\ns21_sprintf=%d; sprintf=%d;",
                  value[i], s21, s);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "\n\tvalue=%f\ns21_dest=%s;\n    dest=%s;", value[i],
                  s21_dest, dest);
  }
}
END_TEST

START_TEST(s21_sprintf_f_14) {
  double value[10] = {-3.2321, -0.82, -0.0, 0.0,      0.616,
                      3.1415,  NAN,   -NAN, INFINITY, -INFINITY};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %0*.*f cc";
  int width = 1;
  int precision = 0;
  for (int i = 0; i < 10; i++) {
    int s = sprintf(dest, format, width, precision, value[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, value[i]);
    ck_assert_msg(s == s21, "\n\tvalue=%f\ns21_sprintf=%d; sprintf=%d;",
                  value[i], s21, s);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "\n\tvalue=%f\ns21_dest=%s;\n    dest=%s;", value[i],
                  s21_dest, dest);
  }
}
END_TEST

START_TEST(s21_sprintf_f_15) {
  double value[10] = {-3.2321, -0.82, -0.0, 0.0,      0.616,
                      3.1415,  NAN,   -NAN, INFINITY, -INFINITY};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %0*.*f cc";
  int width = 10;
  int precision = 6;
  for (int i = 0; i < 10; i++) {
    int s = sprintf(dest, format, width, precision, value[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, value[i]);
    ck_assert_msg(s == s21, "\n\tvalue=%f\ns21_sprintf=%d; sprintf=%d;",
                  value[i], s21, s);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "\n\tvalue=%f\ns21_dest=%s;\n    dest=%s;", value[i],
                  s21_dest, dest);
  }
}
END_TEST

START_TEST(s21_sprintf_f_16) {
  double value[10] = {-3.2321, -0.82, -0.0, 0.0,      0.616,
                      3.1415,  NAN,   -NAN, INFINITY, -INFINITY};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %0*.*f cc";
  int width = 10;
  int precision = 0;
  for (int i = 0; i < 10; i++) {
    int s = sprintf(dest, format, width, precision, value[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, value[i]);
    ck_assert_msg(s == s21, "\n\tvalue=%f\ns21_sprintf=%d; sprintf=%d;",
                  value[i], s21, s);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "\n\tvalue=%f\ns21_dest=%s;\n    dest=%s;", value[i],
                  s21_dest, dest);
  }
}
END_TEST

START_TEST(s21_sprintf_f_17) {
  double value[10] = {-3.2321, -0.82, -0.0, 0.0,      0.616,
                      3.1415,  NAN,   -NAN, INFINITY, -INFINITY};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %#*.*f cc";
  int width = 1;
  int precision = 6;
  for (int i = 0; i < 10; i++) {
    int s = sprintf(dest, format, width, precision, value[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, value[i]);
    ck_assert_msg(s == s21, "\n\tvalue=%f\ns21_sprintf=%d; sprintf=%d;",
                  value[i], s21, s);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "\n\tvalue=%f\ns21_dest=%s;\n    dest=%s;", value[i],
                  s21_dest, dest);
  }
}
END_TEST

START_TEST(s21_sprintf_f_18) {
  double value[10] = {-3.2321, -0.82, -0.0, 0.0,      0.616,
                      3.1415,  NAN,   -NAN, INFINITY, -INFINITY};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %#*.*f cc";
  int width = 1;
  int precision = 0;
  for (int i = 0; i < 10; i++) {
    int s = sprintf(dest, format, width, precision, value[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, value[i]);
    ck_assert_msg(s == s21, "\n\tvalue=%f\ns21_sprintf=%d; sprintf=%d;",
                  value[i], s21, s);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "\n\tvalue=%f\ns21_dest=%s;\n    dest=%s;", value[i],
                  s21_dest, dest);
  }
}
END_TEST

START_TEST(s21_sprintf_f_19) {
  double value[10] = {-3.2321, -0.82, -0.0, 0.0,      0.616,
                      3.1415,  NAN,   -NAN, INFINITY, -INFINITY};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %#*.*f cc";
  int width = 10;
  int precision = 6;
  for (int i = 0; i < 10; i++) {
    int s = sprintf(dest, format, width, precision, value[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, value[i]);
    ck_assert_msg(s == s21, "\n\tvalue=%f\ns21_sprintf=%d; sprintf=%d;",
                  value[i], s21, s);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "\n\tvalue=%f\ns21_dest=%s;\n    dest=%s;", value[i],
                  s21_dest, dest);
  }
}
END_TEST

START_TEST(s21_sprintf_f_20) {
  double value[10] = {-3.2321, -0.82, -0.0, 0.0,      0.616,
                      3.1415,  NAN,   -NAN, INFINITY, -INFINITY};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %#*.*f cc";
  int width = 10;
  int precision = 0;
  for (int i = 0; i < 10; i++) {
    int s = sprintf(dest, format, width, precision, value[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, value[i]);
    ck_assert_msg(s == s21, "\n\tvalue=%f\ns21_sprintf=%d; sprintf=%d;",
                  value[i], s21, s);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "\n\tvalue=%f\ns21_dest=%s;\n    dest=%s;", value[i],
                  s21_dest, dest);
  }
}
END_TEST

START_TEST(s21_sprintf_f_21) {
  double value[10] = {-3.2321, -0.82, -0.0, 0.0,      0.616,
                      3.1415,  NAN,   -NAN, INFINITY, -INFINITY};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %-+*.*f cc";
  int width = 1;
  int precision = 6;
  for (int i = 0; i < 10; i++) {
    int s = sprintf(dest, format, width, precision, value[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, value[i]);
    ck_assert_msg(s == s21, "\n\tvalue=%f\ns21_sprintf=%d; sprintf=%d;",
                  value[i], s21, s);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "\n\tvalue=%f\ns21_dest=%s;\n    dest=%s;", value[i],
                  s21_dest, dest);
  }
}
END_TEST

START_TEST(s21_sprintf_f_22) {
  double value[10] = {-3.2321, -0.82, -0.0, 0.0,      0.616,
                      3.1415,  NAN,   -NAN, INFINITY, -INFINITY};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %- *.*f cc";
  int width = 1;
  int precision = 0;
  for (int i = 0; i < 10; i++) {
    int s = sprintf(dest, format, width, precision, value[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, value[i]);
    ck_assert_msg(s == s21, "\n\tvalue=%f\ns21_sprintf=%d; sprintf=%d;",
                  value[i], s21, s);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "\n\tvalue=%f\ns21_dest=%s;\n    dest=%s;", value[i],
                  s21_dest, dest);
  }
}
END_TEST

START_TEST(s21_sprintf_f_23) {
  double value[10] = {-3.2321, -0.82, -0.0, 0.0,      0.616,
                      3.1415,  NAN,   -NAN, INFINITY, -INFINITY};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb % #*.*f cc";
  int width = 10;
  int precision = 6;
  for (int i = 0; i < 10; i++) {
    int s = sprintf(dest, format, width, precision, value[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, value[i]);
    ck_assert_msg(s == s21, "\n\tvalue=%f\ns21_sprintf=%d; sprintf=%d;",
                  value[i], s21, s);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "\n\tvalue=%f\ns21_dest=%s;\n    dest=%s;", value[i],
                  s21_dest, dest);
  }
}
END_TEST

START_TEST(s21_sprintf_f_24) {
  double value[10] = {-3.2321, -0.82, -0.0, 0.0,      0.616,
                      3.1415,  NAN,   -NAN, INFINITY, -INFINITY};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %#0*.*f cc";
  int width = 10;
  int precision = 0;
  for (int i = 0; i < 10; i++) {
    int s = sprintf(dest, format, width, precision, value[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, value[i]);
    ck_assert_msg(s == s21, "\n\tvalue=%f\ns21_sprintf=%d; sprintf=%d;",
                  value[i], s21, s);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "\n\tvalue=%f\ns21_dest=%s;\n    dest=%s;", value[i],
                  s21_dest, dest);
  }
}
END_TEST

START_TEST(s21_sprintf_f_25) {
  double value[10] = {-3.2321, -0.82, -0.0, 0.0,      0.616,
                      3.1415,  NAN,   -NAN, INFINITY, -INFINITY};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %0*f cc";
  int width = 10;
  for (int i = 0; i < 10; i++) {
    int s = sprintf(dest, format, width, value[i]);
    int s21 = s21_sprintf(s21_dest, format, width, value[i]);
    ck_assert_msg(s == s21, "\n\tvalue=%f\ns21_sprintf=%d; sprintf=%d;",
                  value[i], s21, s);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "\n\tvalue=%f\ns21_dest=%s;\n    dest=%s;", value[i],
                  s21_dest, dest);
  }
}
END_TEST

START_TEST(s21_sprintf_f_26) {
  double value[10] = {-3.2321, -0.82, -0.0, 0.0,      0.616,
                      3.1415,  NAN,   -NAN, INFINITY, -INFINITY};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %0*.*f cc";
  int width = 10;
  int precision = 22;
  for (int i = 0; i < 10; i++) {
    int s = sprintf(dest, format, width, precision, value[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, value[i]);
    ck_assert_msg(s == s21, "\n\tvalue=%f\ns21_sprintf=%d; sprintf=%d;",
                  value[i], s21, s);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "\n\tvalue=%f\ns21_dest=%s;\n    dest=%s;", value[i],
                  s21_dest, dest);
  }
}
END_TEST

START_TEST(s21_sprintf_u_1) {
  unsigned int ui[] = {-100, -1, 0, 1, 10, 4294967295};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %*.*u cc";
  int width = 10;
  int precision = 5;
  for (int i = 0; i < 6; i++) {
    int s = sprintf(dest, format, width, precision, ui[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, ui[i]);
    ck_assert_msg(s == s21, "s = %d, s21 = %d, ui = %u", s, s21, ui[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, ui = %u", dest, s21_dest, ui[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_u_2) {
  unsigned int ui[] = {-100, -1, 0, 1, 10, 4294967295};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %0*u cc";
  int width = 8;
  for (int i = 0; i < 6; i++) {
    int s = sprintf(dest, format, width, ui[i]);

    int s21 = s21_sprintf(s21_dest, format, width, ui[i]);

    ck_assert_msg(s == s21, "s = %d, s21 = %d, ui = %u", s, s21, ui[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, ui = %u", dest, s21_dest, ui[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_u_3) {
  unsigned int ui[] = {-100, -1, 0, 1, 10, 4294967295};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %-*.*u cc";
  int width = 8;
  int precision = 5;
  for (int i = 0; i < 6; i++) {
    int s = sprintf(dest, format, width, precision, ui[i]);

    int s21 = s21_sprintf(s21_dest, format, width, precision, ui[i]);

    ck_assert_msg(s == s21, "s = %d, s21 = %d, ui = %u", s, s21, ui[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, ui = %u", dest, s21_dest, ui[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_u_4) {
  unsigned int ui[] = {-100, -1, 0, 1, 10, 4294967295};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %0*.*u cc";
  int width = 8;
  int precision = 5;
  for (int i = 0; i < 6; i++) {
    int s = sprintf(dest, format, width, precision, ui[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, ui[i]);
    ck_assert_msg(s == s21, "s = %d, s21 = %d, ui = %u", s, s21, ui[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, ui = %u", dest, s21_dest, ui[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_u_5) {
  unsigned int ui[] = {-100, -1, 0, 1, 10, 4294967295};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %+0*.*u cc";
  int width = 13;
  int precision = 15;
  for (int i = 0; i < 6; i++) {
    int s = sprintf(dest, format, width, precision, ui[i]);

    int s21 = s21_sprintf(s21_dest, format, width, precision, ui[i]);

    ck_assert_msg(s == s21, "s = %d, s21 = %d, ui = %u", s, s21, ui[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, ui = %u", dest, s21_dest, ui[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_u_6) {
  unsigned short int ui[] = {-100, -1, 0, 1, 10, 65535};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %+0*.*hu cc";
  int width = 13;
  int precision = 0;
  for (int i = 0; i < 6; i++) {
    int s = sprintf(dest, format, width, precision, ui[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, ui[i]);
    ck_assert_msg(s == s21, "s = %d, s21 = %d, ui = %u", s, s21, ui[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, ui = %u", dest, s21_dest, ui[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_u_7) {
  unsigned short int ui[] = {-100, -1, 0, 1, 1000, 65535};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %+0*.*hu cc";
  int width = 2;
  int precision = 0;
  for (int i = 0; i < 6; i++) {
    int s = sprintf(dest, format, width, precision, ui[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, ui[i]);
    ck_assert_msg(s == s21, "\ns = %d, s21 = %d, ui = %u", s, s21, ui[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "\n    dest = %s,\ns21_dest = %s, ui = %u", dest, s21_dest,
                  ui[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_u_8) {
  unsigned long int ui[] = {-100, -1, 0, 1, 10, 9223372036854775807};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %+0*.*lu cc";
  int width = 13;
  int precision = 15;
  for (int i = 0; i < 6; i++) {
    int s = sprintf(dest, format, width, precision, ui[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, ui[i]);
    ck_assert_msg(s == s21, "s = %d, s21 = %d, ui = %lu", s, s21, ui[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, ui = %lu", dest, s21_dest, ui[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_i_1) {
  int ui[] = {-2147483647, -10, 0, 1, 10, 2147483647};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %*.*i cc";
  int width = 10;
  int precision = 5;
  for (int i = 0; i < 6; i++) {
    int s = sprintf(dest, format, width, precision, ui[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, ui[i]);
    ck_assert_msg(s == s21, "s = %d, s21 = %d, ui = %i", s, s21, ui[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, ui = %i", dest, s21_dest, ui[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_i_2) {
  int ui[] = {-2147483647, -10, 0, 1, 10, 2147483647};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %*.*i cc";
  int width = 0;
  int precision = 5;
  for (int i = 0; i < 6; i++) {
    int s = sprintf(dest, format, width, precision, ui[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, ui[i]);
    ck_assert_msg(s == s21, "s = %d, s21 = %d, ui = %i", s, s21, ui[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, ui = %i", dest, s21_dest, ui[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_i_3) {
  int ui[] = {-2147483647, -10, 0, 1, 10, 2147483647};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %*.*i cc";
  int width = 10;
  int precision = 0;
  for (int i = 0; i < 6; i++) {
    int s = sprintf(dest, format, width, precision, ui[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, ui[i]);
    ck_assert_msg(s == s21, "s = %d, s21 = %d, ui = %i", s, s21, ui[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, ui = %i", dest, s21_dest, ui[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_i_4) {
  int ui[] = {-2147483647, -10, 0, 1, 10, 2147483647};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb % *.*i cc";
  int width = 0;
  int precision = 5;
  for (int i = 0; i < 6; i++) {
    int s = sprintf(dest, format, width, precision, ui[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, ui[i]);
    ck_assert_msg(s == s21, "s = %d, s21 = %d, ui = %i", s, s21, ui[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, ui = %i", dest, s21_dest, ui[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_i_5) {
  int ui[] = {-2147483647, -10, 0, 1, 10, 2147483647};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %-+*.*i cc";
  int width = 5;
  int precision = 16;
  for (int i = 0; i < 6; i++) {
    int s = sprintf(dest, format, width, precision, ui[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, ui[i]);
    ck_assert_msg(s == s21, "s = %d, s21 = %d, ui = %i", s, s21, ui[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, ui = %i", dest, s21_dest, ui[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_i_6) {
  int ui[] = {-2147483647, -161, 0, 1365, 3563456, 2147483647};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb % 0*.*i cc";
  int width = 3;
  int precision = 5;
  for (int i = 0; i < 6; i++) {
    int s = sprintf(dest, format, width, precision, ui[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, ui[i]);
    // printf("ui = %i; s = %d; s21 = %d\n", ui[i], s, s21);
    // printf("    dest = %s;\ns21_dest = %s\n", dest, s21_dest);
    ck_assert_msg(s == s21, "s = %d, s21 = %d, ui = %i", s, s21, ui[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, ui = %i", dest, s21_dest, ui[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_i_7) {
  long int ui[] = {-9223372036854775807, -161, 0, 1365, 3563456,
                   9223372036854775807};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb % 0*.*li cc";
  int width = 8;
  int precision = 15;
  for (int i = 0; i < 6; i++) {
    int s = sprintf(dest, format, width, precision, ui[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, ui[i]);
    ck_assert_msg(s == s21, "s = %d, s21 = %d, ui = %li", s, s21, ui[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, ui = %li", dest, s21_dest, ui[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_i_8) {
  long int ui[] = {-9223372036854775807, -161, 0, 1365, 3563456,
                   9223372036854775807};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb % -*.*li cc";
  int width = 18;
  int precision = 14;
  for (int i = 0; i < 6; i++) {
    int s = sprintf(dest, format, width, precision, ui[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, ui[i]);
    ck_assert_msg(s == s21, "s = %d, s21 = %d, ui = %li", s, s21, ui[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, ui = %li", dest, s21_dest, ui[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_i_9) {
  short int ui[] = {-32767, -10, 0, 1, 10, 65535};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %*.*hi cc";
  int width = 10;
  int precision = 0;
  for (int i = 0; i < 6; i++) {
    int s = sprintf(dest, format, width, precision, ui[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, ui[i]);
    ck_assert_msg(s == s21, "s = %d, s21 = %d, ui = %hi", s, s21, ui[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, ui = %hi", dest, s21_dest, ui[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_i_10) {
  short int ui[] = {-32767, -10, 0, 1, 10, 65535};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %0*hi cc";
  int width = 10;

  for (int i = 0; i < 6; i++) {
    int s = sprintf(dest, format, width, ui[i]);
    int s21 = s21_sprintf(s21_dest, format, width, ui[i]);
    ck_assert_msg(s == s21, "s = %d, s21 = %d, ui = %hi", s, s21, ui[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, ui = %hi", dest, s21_dest, ui[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_c_1) {
  char c[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
              'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %c cc";
  for (int i = 0; i < 26; i++) {
    int s = sprintf(dest, format, c[i]);
    int s21 = s21_sprintf(s21_dest, format, c[i]);
    ck_assert_msg(s == s21, "s = %d, s21 = %d, c = %c", s, s21, c[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, c = %c", dest, s21_dest, c[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_c_2) {
  char c[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
              'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %3c cc";
  for (int i = 0; i < 26; i++) {
    int s = sprintf(dest, format, c[i]);
    int s21 = s21_sprintf(s21_dest, format, c[i]);
    ck_assert_msg(s == s21, "s = %d, s21 = %d, c = %c", s, s21, c[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, c = %c", dest, s21_dest, c[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_c_3) {
  char c[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
              'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %.3c cc";
  for (int i = 0; i < 26; i++) {
    int s = sprintf(dest, format, c[i]);
    int s21 = s21_sprintf(s21_dest, format, c[i]);
    ck_assert_msg(s == s21, "s = %d, s21 = %d, c = %c", s, s21, c[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, c = %c", dest, s21_dest, c[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_c_4) {
  char c[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
              'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %*.*c cc";
  int width = 10;
  int precision = 4;
  for (int i = 0; i < 26; i++) {
    int s = sprintf(dest, format, width, precision, c[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, c[i]);
    ck_assert_msg(s == s21, "s = %d, s21 = %d, c = %c", s, s21, c[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, c = %c", dest, s21_dest, c[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_c_5) {
  char c[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
              'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %-*.*c cc";
  int width = 10;
  int precision = 4;
  for (int i = 0; i < 26; i++) {
    int s = sprintf(dest, format, width, precision, c[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, c[i]);
    ck_assert_msg(s == s21, "s = %d, s21 = %d, c = %c", s, s21, c[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, c = %c", dest, s21_dest, c[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_c_6) {
  wchar_t c[] = {0, 12, 123, 1234, 12345, 32132, 33333, 66666, 99999};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %lc cc";
  for (int i = 0; i < 9; i++) {
    int s = sprintf(dest, format, c[i]);
    int s21 = s21_sprintf(s21_dest, format, c[i]);
    // printf("c = %lc, s = %d, s21 = %d\n", c[i], s, s21);
    // printf("    dest = %s\ns21_dest = %s\n", dest, s21_dest);
    ck_assert_msg(s == s21, "s = %d, s21 = %d, c = %lc", s, s21, c[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, c = %lc", dest, s21_dest, c[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_c_7) {
  wchar_t c[] = {0, 12, 123, 1234, 12345, 32132, 33333, 66666, 99999};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %-*.*lc cc";
  int width = 10;
  int precision = 4;
  for (int i = 0; i < 9; i++) {
    int s = sprintf(dest, format, width, precision, c[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, c[i]);
    // printf("c = %lc, s = %d, s21 = %d\n", c[i], s, s21);
    // printf("    dest = %s\ns21_dest = %s\n", dest, s21_dest);
    ck_assert_msg(s == s21, "s = %d, s21 = %d, c = %lc", s, s21, c[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, c = %lc", dest, s21_dest, c[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_c_8) {
  wchar_t c[] = {0, 12, 123, 1234, 12345, 32132, 33333, 66666, 99999};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %*.*lc cc";
  int width = 4;
  int precision = 10;
  for (int i = 0; i < 9; i++) {
    int s = sprintf(dest, format, width, precision, c[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, c[i]);
    // printf("c = %lc, s = %d, s21 = %d\n", c[i], s, s21);
    // printf("    dest = %s\ns21_dest = %s\n", dest, s21_dest);
    ck_assert_msg(s == s21, "s = %d, s21 = %d, c = %lc", s, s21, c[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, c = %lc", dest, s21_dest, c[i]);
  }
}
END_TEST

Suite *suite_s21_sprintf() {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_sprintf");

  /* Core test case */
  tc_core = tcase_create("case_s21_sprintf");

  tcase_add_test(tc_core, s21_sprintf_proc_1);

  tcase_add_test(tc_core, s21_sprintf_u_1);
  tcase_add_test(tc_core, s21_sprintf_u_2);
  tcase_add_test(tc_core, s21_sprintf_u_3);
  tcase_add_test(tc_core, s21_sprintf_u_4);
  tcase_add_test(tc_core, s21_sprintf_u_5);
  tcase_add_test(tc_core, s21_sprintf_u_6);
  tcase_add_test(tc_core, s21_sprintf_u_7);
  tcase_add_test(tc_core, s21_sprintf_u_8);

  tcase_add_test(tc_core, s21_sprintf_i_1);
  tcase_add_test(tc_core, s21_sprintf_i_2);
  tcase_add_test(tc_core, s21_sprintf_i_3);
  tcase_add_test(tc_core, s21_sprintf_i_4);
  tcase_add_test(tc_core, s21_sprintf_i_5);
  tcase_add_test(tc_core, s21_sprintf_i_6);
  tcase_add_test(tc_core, s21_sprintf_i_7);
  tcase_add_test(tc_core, s21_sprintf_i_8);
  tcase_add_test(tc_core, s21_sprintf_i_9);
  tcase_add_test(tc_core, s21_sprintf_i_10);

  tcase_add_test(tc_core, s21_sprintf_c_1);
  tcase_add_test(tc_core, s21_sprintf_c_2);
  tcase_add_test(tc_core, s21_sprintf_c_3);
  tcase_add_test(tc_core, s21_sprintf_c_4);
  tcase_add_test(tc_core, s21_sprintf_c_5);
  tcase_add_test(tc_core, s21_sprintf_c_6);
  tcase_add_test(tc_core, s21_sprintf_c_7);
  tcase_add_test(tc_core, s21_sprintf_c_8);

  tcase_add_test(tc_core, s21_sprintf_s_1);
  tcase_add_test(tc_core, s21_sprintf_s_2);
  tcase_add_test(tc_core, s21_sprintf_s_3);
  tcase_add_test(tc_core, s21_sprintf_s_4);
  tcase_add_test(tc_core, s21_sprintf_s_5);
  tcase_add_test(tc_core, s21_sprintf_s_6);
  tcase_add_test(tc_core, s21_sprintf_s_7);
  tcase_add_test(tc_core, s21_sprintf_s_8);
  tcase_add_test(tc_core, s21_sprintf_s_9);

  tcase_add_test(tc_core, s21_sprintf_f_1);
  tcase_add_test(tc_core, s21_sprintf_f_2);
  tcase_add_test(tc_core, s21_sprintf_f_3);
  tcase_add_test(tc_core, s21_sprintf_f_4);
  tcase_add_test(tc_core, s21_sprintf_f_5);
  tcase_add_test(tc_core, s21_sprintf_f_6);
  tcase_add_test(tc_core, s21_sprintf_f_7);
  tcase_add_test(tc_core, s21_sprintf_f_8);
  tcase_add_test(tc_core, s21_sprintf_f_9);
  tcase_add_test(tc_core, s21_sprintf_f_10);
  tcase_add_test(tc_core, s21_sprintf_f_11);
  tcase_add_test(tc_core, s21_sprintf_f_12);
  tcase_add_test(tc_core, s21_sprintf_f_13);
  tcase_add_test(tc_core, s21_sprintf_f_14);
  tcase_add_test(tc_core, s21_sprintf_f_15);
  tcase_add_test(tc_core, s21_sprintf_f_16);
  tcase_add_test(tc_core, s21_sprintf_f_17);
  tcase_add_test(tc_core, s21_sprintf_f_18);
  tcase_add_test(tc_core, s21_sprintf_f_19);
  tcase_add_test(tc_core, s21_sprintf_f_20);
  tcase_add_test(tc_core, s21_sprintf_f_21);
  tcase_add_test(tc_core, s21_sprintf_f_22);
  tcase_add_test(tc_core, s21_sprintf_f_23);
  tcase_add_test(tc_core, s21_sprintf_f_24);
  tcase_add_test(tc_core, s21_sprintf_f_25);
  tcase_add_test(tc_core, s21_sprintf_f_26);

  suite_add_tcase(s, tc_core);

  return s;
}
