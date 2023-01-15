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

START_TEST(s21_sprintf_u_1) {
  unsigned int ui[] = {-100, -1, 0, 1, 10, 4294967295};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %*.*u cc";
  int width[] = {0, 1, 5, 16};
  int precision[] = {0, 1, 5, 16};
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        int s = sprintf(dest, format, width[j], precision[k], ui[i]);
        int s21 = s21_sprintf(s21_dest, format, width[j], precision[k], ui[i]);
        ck_assert_msg(s == s21, "s = %d, s21 = %d, ui = %u", s, s21, ui[i]);
        ck_assert_msg(strcmp(dest, s21_dest) == 0,
                      "dest = %s, s21_dest = %s, ui = %u", dest, s21_dest,
                      ui[i]);
      }
    }
  }
}
END_TEST

START_TEST(s21_sprintf_u_2) {
  unsigned int ui[] = {-100, -1, 0, 1, 10, 4294967295};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %0*u cc";
  int width[] = {0, 1, 5, 16};
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 4; j++) {
      int s = sprintf(dest, format, width[j], ui[i]);
      int s21 = s21_sprintf(s21_dest, format, width[j], ui[i]);
      ck_assert_msg(s == s21, "s = %d, s21 = %d, ui = %u", s, s21, ui[i]);
      ck_assert_msg(strcmp(dest, s21_dest) == 0,
                    "dest = %s, s21_dest = %s, ui = %u", dest, s21_dest, ui[i]);
    }
  }
}
END_TEST

START_TEST(s21_sprintf_u_3) {
  unsigned int ui[] = {-100, -1, 0, 1, 10, 4294967295};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb % *.*u cc";
  int width[] = {0, 1, 5, 16};
  int precision[] = {0, 1, 5, 16};
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        int s = sprintf(dest, format, width[j], precision[k], ui[i]);
        int s21 = s21_sprintf(s21_dest, format, width[j], precision[k], ui[i]);
        ck_assert_msg(s == s21, "s = %d, s21 = %d, ui = %u", s, s21, ui[i]);
        ck_assert_msg(strcmp(dest, s21_dest) == 0,
                      "dest = %s, s21_dest = %s, ui = %u", dest, s21_dest,
                      ui[i]);
      }
    }
  }
}
END_TEST

START_TEST(s21_sprintf_u_4) {
  unsigned int ui[] = {-100, -1, 0, 1, 10, 4294967295};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %+*.*u cc";
  int width[] = {0, 1, 5, 16};
  int precision[] = {0, 1, 5, 16};
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        int s = sprintf(dest, format, width[j], precision[k], ui[i]);
        int s21 = s21_sprintf(s21_dest, format, width[j], precision[k], ui[i]);
        ck_assert_msg(s == s21, "s = %d, s21 = %d, ui = %u", s, s21, ui[i]);
        ck_assert_msg(strcmp(dest, s21_dest) == 0,
                      "dest = %s, s21_dest = %s, ui = %u", dest, s21_dest,
                      ui[i]);
      }
    }
  }
}
END_TEST

START_TEST(s21_sprintf_u_5) {
  unsigned int ui[] = {-100, -1, 0, 1, 10, 4294967295};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %+-*.*u cc";
  int width[] = {0, 1, 5, 16};
  int precision[] = {0, 1, 5, 16};
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        int s = sprintf(dest, format, width[j], precision[k], ui[i]);
        int s21 = s21_sprintf(s21_dest, format, width[j], precision[k], ui[i]);
        ck_assert_msg(s == s21, "s = %d, s21 = %d, ui = %u", s, s21, ui[i]);
        ck_assert_msg(strcmp(dest, s21_dest) == 0,
                      "dest = %s, s21_dest = %s, ui = %u", dest, s21_dest,
                      ui[i]);
      }
    }
  }
}
END_TEST

START_TEST(s21_sprintf_u_6) {
  unsigned int ui[] = {-100, -1, 0, 1, 10, 4294967295};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb % -*.*u cc";
  int width[] = {0, 1, 5, 16};
  int precision[] = {0, 1, 5, 16};
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        int s = sprintf(dest, format, width[j], precision[k], ui[i]);
        int s21 = s21_sprintf(s21_dest, format, width[j], precision[k], ui[i]);
        ck_assert_msg(s == s21, "s = %d, s21 = %d, ui = %u", s, s21, ui[i]);
        ck_assert_msg(strcmp(dest, s21_dest) == 0,
                      "dest = %s, s21_dest = %s, ui = %u", dest, s21_dest,
                      ui[i]);
      }
    }
  }
}
END_TEST

START_TEST(s21_sprintf_u_7) {
  unsigned int ui[] = {-100, -1, 0, 1, 10, 4294967295};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %0*.*u cc";
  int width[] = {0, 1, 5, 16};
  int precision[] = {0, 1, 5, 16};
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        int s = sprintf(dest, format, width[j], precision[k], ui[i]);
        int s21 = s21_sprintf(s21_dest, format, width[j], precision[k], ui[i]);
        ck_assert_msg(s == s21, "s = %d, s21 = %d, ui = %u", s, s21, ui[i]);
        ck_assert_msg(strcmp(dest, s21_dest) == 0,
                      "dest = %s, s21_dest = %s, ui = %u", dest, s21_dest,
                      ui[i]);
      }
    }
  }
}
END_TEST

START_TEST(s21_sprintf_u_8) {
  unsigned short int ui[] = {-100, -1, 0, 1, 10, 32768};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %0*.*hu cc";
  int width[] = {0, 1, 5, 16};
  int precision[] = {0, 1, 5, 16};
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        int s = sprintf(dest, format, width[j], precision[k], ui[i]);
        int s21 = s21_sprintf(s21_dest, format, width[j], precision[k], ui[i]);
        ck_assert_msg(s == s21, "s = %d, s21 = %d, ui = %hu", s, s21, ui[i]);
        ck_assert_msg(strcmp(dest, s21_dest) == 0,
                      "dest = %s, s21_dest = %s, ui = %hu", dest, s21_dest,
                      ui[i]);
      }
    }
  }
}
END_TEST

START_TEST(s21_sprintf_u_9) {
  unsigned long int ui[] = {-100, -1, 0, 1, 10, 9223372036854775807};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %0*.*lu cc";
  int width[] = {0, 1, 5, 16};
  int precision[] = {0, 1, 5, 16};
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        int s = sprintf(dest, format, width[j], precision[k], ui[i]);
        int s21 = s21_sprintf(s21_dest, format, width[j], precision[k], ui[i]);
        ck_assert_msg(s == s21, "s = %d, s21 = %d, ui = %lu", s, s21, ui[i]);
        ck_assert_msg(strcmp(dest, s21_dest) == 0,
                      "dest = %s, s21_dest = %s, ui = %lu", dest, s21_dest,
                      ui[i]);
      }
    }
  }
}
END_TEST

START_TEST(s21_sprintf_i_1) {
  int ui[] = {-2147483647, -10, 0, 1, 10, 2147483647};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %*.*i cc";
  int width[] = {0, 1, 4, 88};
  int precision[] = {0, 1, 4, 16};
  for (int i = 0; i < 6; i++) {
    for (int k = 0; k < 4; k++) {
      for (int j = 0; j < 4; j++) {
        int s = sprintf(dest, format, width[k], precision[j], ui[i]);
        int s21 = s21_sprintf(s21_dest, format, width[k], precision[j], ui[i]);
        ck_assert_msg(s == s21, "s = %d, s21 = %d, ui = %i", s, s21, ui[i]);
        ck_assert_msg(strcmp(dest, s21_dest) == 0,
                      "dest = %s, s21_dest = %s, ui = %i", dest, s21_dest,
                      ui[i]);
      }
    }
  }
}
END_TEST

START_TEST(s21_sprintf_i_2) {
  int ui[] = {-2147483647, -10, 0, 1, 10, 2147483647};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %-*.*i cc";
  int width[] = {0, 1, 4, 16};
  int precision[] = {0, 1, 4, 16};
  for (int i = 0; i < 6; i++) {
    for (int k = 0; k < 4; k++) {
      for (int j = 0; j < 4; j++) {
        int s = sprintf(dest, format, width[k], precision[j], ui[i]);
        int s21 = s21_sprintf(s21_dest, format, width[k], precision[j], ui[i]);
        ck_assert_msg(s == s21, "s = %d, s21 = %d, ui = %i", s, s21, ui[i]);
        ck_assert_msg(strcmp(dest, s21_dest) == 0,
                      "dest = %s, s21_dest = %s, ui = %i", dest, s21_dest,
                      ui[i]);
      }
    }
  }
}
END_TEST

START_TEST(s21_sprintf_i_3) {
  int ui[] = {-2147483647, -10, 0, 1, 10, 2147483647};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb % *.*i cc";
  int width[] = {0, 1, 4, 16};
  int precision[] = {0, 1, 4, 16};
  for (int i = 0; i < 6; i++) {
    for (int k = 0; k < 4; k++) {
      for (int j = 0; j < 4; j++) {
        int s = sprintf(dest, format, width[k], precision[j], ui[i]);
        int s21 = s21_sprintf(s21_dest, format, width[k], precision[j], ui[i]);
        ck_assert_msg(s == s21, "s = %d, s21 = %d, ui = %i", s, s21, ui[i]);
        ck_assert_msg(strcmp(dest, s21_dest) == 0,
                      "dest = %s, s21_dest = %s, ui = %i", dest, s21_dest,
                      ui[i]);
      }
    }
  }
}
END_TEST

START_TEST(s21_sprintf_i_4) {
  int ui[] = {-2147483647, -10, 0, 1, 10, 2147483647};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %0*.*i cc";
  int width[] = {0, 1, 4, 16};
  int precision[] = {0, 1, 4, 16};
  for (int i = 0; i < 6; i++) {
    for (int k = 0; k < 4; k++) {
      for (int j = 0; j < 4; j++) {
        int s = sprintf(dest, format, width[k], precision[j], ui[i]);
        int s21 = s21_sprintf(s21_dest, format, width[k], precision[j], ui[i]);
        ck_assert_msg(s == s21, "s = %d, s21 = %d, ui = %i", s, s21, ui[i]);
        ck_assert_msg(strcmp(dest, s21_dest) == 0,
                      "dest = %s, s21_dest = %s, ui = %i", dest, s21_dest,
                      ui[i]);
      }
    }
  }
}
END_TEST

START_TEST(s21_sprintf_i_5) {
  int ui[] = {-2147483647, -10, 0, 1, 10, 2147483647};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %+*.*i cc";
  int width[] = {0, 1, 4, 16};
  int precision[] = {0, 1, 4, 16};
  for (int i = 0; i < 6; i++) {
    for (int k = 0; k < 4; k++) {
      for (int j = 0; j < 4; j++) {
        int s = sprintf(dest, format, width[k], precision[j], ui[i]);
        int s21 = s21_sprintf(s21_dest, format, width[k], precision[j], ui[i]);
        ck_assert_msg(s == s21, "s = %d, s21 = %d, ui = %i", s, s21, ui[i]);
        ck_assert_msg(strcmp(dest, s21_dest) == 0,
                      "dest = %s, s21_dest = %s, ui = %i", dest, s21_dest,
                      ui[i]);
      }
    }
  }
}
END_TEST

START_TEST(s21_sprintf_i_6) {
  int ui[] = {-2147483647, -10, 0, 1, 10, 2147483647};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %+0*.*i cc";
  int width[] = {0, 1, 4, 16};
  int precision[] = {0, 1, 4, 16};
  for (int i = 0; i < 6; i++) {
    for (int k = 0; k < 4; k++) {
      for (int j = 0; j < 4; j++) {
        int s = sprintf(dest, format, width[k], precision[j], ui[i]);
        int s21 = s21_sprintf(s21_dest, format, width[k], precision[j], ui[i]);
        ck_assert_msg(s == s21, "s = %d, s21 = %d, ui = %i", s, s21, ui[i]);
        ck_assert_msg(strcmp(dest, s21_dest) == 0,
                      "dest = %s, s21_dest = %s, ui = %i", dest, s21_dest,
                      ui[i]);
      }
    }
  }
}
END_TEST

START_TEST(s21_sprintf_i_7) {
  int ui[] = {-2147483647, -10, 0, 1, 10, 2147483647};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb % 0*.*i cc";
  int width[] = {0, 1, 4, 16};
  int precision[] = {0, 1, 4, 16};
  for (int i = 0; i < 6; i++) {
    for (int k = 0; k < 4; k++) {
      for (int j = 0; j < 4; j++) {
        int s = sprintf(dest, format, width[k], precision[j], ui[i]);
        int s21 = s21_sprintf(s21_dest, format, width[k], precision[j], ui[i]);
        ck_assert_msg(s == s21, "s = %d, s21 = %d, ui = %i", s, s21, ui[i]);
        ck_assert_msg(strcmp(dest, s21_dest) == 0,
                      "dest = %s, s21_dest = %s, ui = %i", dest, s21_dest,
                      ui[i]);
      }
    }
  }
}
END_TEST

START_TEST(s21_sprintf_i_8) {
  int ui[] = {-2147483647, -10, 0, 1, 10, 2147483647};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %+-*.*i cc";
  int width[] = {0, 1, 4, 16};
  int precision[] = {0, 1, 4, 16};
  for (int i = 0; i < 6; i++) {
    for (int k = 0; k < 4; k++) {
      for (int j = 0; j < 4; j++) {
        int s = sprintf(dest, format, width[k], precision[j], ui[i]);
        int s21 = s21_sprintf(s21_dest, format, width[k], precision[j], ui[i]);
        ck_assert_msg(s == s21, "s = %d, s21 = %d, ui = %i", s, s21, ui[i]);
        ck_assert_msg(strcmp(dest, s21_dest) == 0,
                      "dest = %s, s21_dest = %s, ui = %i", dest, s21_dest,
                      ui[i]);
      }
    }
  }
}
END_TEST

START_TEST(s21_sprintf_i_9) {
  long int ui[] = {-9223372036854775807, -10, 0, 1, 10, 9223372036854775807};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %+-*.*li cc";
  int width[] = {0, 1, 4, 16};
  int precision[] = {0, 1, 4, 16};
  for (int i = 0; i < 6; i++) {
    for (int k = 0; k < 4; k++) {
      for (int j = 0; j < 4; j++) {
        int s = sprintf(dest, format, width[k], precision[j], ui[i]);
        int s21 = s21_sprintf(s21_dest, format, width[k], precision[j], ui[i]);
        // printf("width = %d, precision = %d, ui = %li, s = %d, s21 = %d\n",
        //        width[k], precision[j], ui[i], s, s21);
        // printf("dest = %s, s21_dest = %s\n", dest, s21_dest);
        ck_assert_msg(s == s21, "s = %d, s21 = %d, ui = %li", s, s21, ui[i]);
        ck_assert_msg(strcmp(dest, s21_dest) == 0,
                      "dest = %s, s21_dest = %s, ui = %li", dest, s21_dest,
                      ui[i]);
      }
    }
  }
}
END_TEST

START_TEST(s21_sprintf_i_10) {
  short int ui[] = {-32768, -10, 0, 1, 10, 32768};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %+-*.*hi cc";
  int width[] = {0, 1, 4, 16};
  int precision[] = {0, 1, 4, 16};
  for (int i = 0; i < 6; i++) {
    for (int k = 0; k < 4; k++) {
      for (int j = 0; j < 4; j++) {
        int s = sprintf(dest, format, width[k], precision[j], ui[i]);
        int s21 = s21_sprintf(s21_dest, format, width[k], precision[j], ui[i]);
        ck_assert_msg(s == s21, "s = %d, s21 = %d, ui = %hi", s, s21, ui[i]);
        ck_assert_msg(strcmp(dest, s21_dest) == 0,
                      "dest = %s, s21_dest = %s, ui = %hi", dest, s21_dest,
                      ui[i]);
      }
    }
  }
}
END_TEST

START_TEST(s21_sprintf_i_11) {
  int ui[] = {-2147483647, -10, 0, 1, 10, 2147483647};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %+0*i cc";
  int width[] = {0, 1, 4, 16};
  for (int i = 0; i < 6; i++) {
    for (int k = 0; k < 4; k++) {
      int s = sprintf(dest, format, width[k], ui[i]);
      int s21 = s21_sprintf(s21_dest, format, width[k], ui[i]);
      ck_assert_msg(s == s21, "s = %d, s21 = %d, ui = %i", s, s21, ui[i]);
      ck_assert_msg(strcmp(dest, s21_dest) == 0,
                    "dest = %s, s21_dest = %s, ui = %i", dest, s21_dest, ui[i]);
    }
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
  const char *format = "aa bb %*c cc";
  int width = 10;
  for (int i = 0; i < 26; i++) {
    int s = sprintf(dest, format, width, c[i]);
    int s21 = s21_sprintf(s21_dest, format, width, c[i]);
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
  const char *format = "aa bb %-*c cc";
  int width = 10;
  for (int i = 0; i < 26; i++) {
    int s = sprintf(dest, format, width, c[i]);
    int s21 = s21_sprintf(s21_dest, format, width, c[i]);
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
  int precision = 0;
  for (int i = 0; i < 9; i++) {
    int s = sprintf(dest, format, width, precision, c[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, c[i]);
    ck_assert_msg(s == s21, "s = %d, s21 = %d, c = %lc", s, s21, c[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, c = %lc", dest, s21_dest, c[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_o_1) {
  int val[] = {-100, -10, 0, 1, 10, 2147483647, 2147483648, 4294967295};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %*.*o cc";
  int width = 10;
  int precision = 5;
  for (int i = 0; i < 8; i++) {
    int s = sprintf(dest, format, width, precision, val[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, val[i]);
    ck_assert_msg(s == s21, "s = %d, s21 = %d, val = %o", s, s21, val[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, val = %o", dest, s21_dest, val[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_o_2) {
  int val[] = {-100, -10, 0, 1, 10, 2147483647, 2147483648, 4294967295};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %1.2o cc";
  for (int i = 0; i < 8; i++) {
    int s = sprintf(dest, format, val[i]);
    int s21 = s21_sprintf(s21_dest, format, val[i]);
    ck_assert_msg(s == s21, "s = %d, s21 = %d, val = %o", s, s21, val[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, val = %o", dest, s21_dest, val[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_o_3) {
  int val[] = {-100, -10, 0, 1, 10, 2147483647, 2147483648, 4294967295};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb % *.*o cc";
  int width = 0;
  int precision = 15;
  for (int i = 0; i < 8; i++) {
    int s = sprintf(dest, format, width, precision, val[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, val[i]);
    ck_assert_msg(s == s21, "s = %d, s21 = %d, val = %o", s, s21, val[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, val = %o", dest, s21_dest, val[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_o_4) {
  int val[] = {-100, -10, 0, 1, 10, 2147483647, 2147483648, 4294967295};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %- *.*o cc";
  int width = 10;
  int precision = 5;
  for (int i = 0; i < 8; i++) {
    int s = sprintf(dest, format, width, precision, val[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, val[i]);
    ck_assert_msg(s == s21, "s = %d, s21 = %d, val = %o", s, s21, val[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, val = %o", dest, s21_dest, val[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_o_5) {
  int val[] = {-100, -10, 0, 1, 10, 2147483647, 2147483648, 4294967295};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %0*.*o cc";
  int width = 16;
  int precision = 5;
  for (int i = 0; i < 8; i++) {
    int s = sprintf(dest, format, width, precision, val[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, val[i]);
    ck_assert_msg(s == s21, "s = %d, s21 = %d, val = %o", s, s21, val[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, val = %o", dest, s21_dest, val[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_o_6) {
  int val[] = {-100, -10, 0, 1, 10, 2147483647, 2147483648, 4294967295};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %#0*.*o cc";
  int width = 16;
  int precision = 5;
  for (int i = 0; i < 8; i++) {
    int s = sprintf(dest, format, width, precision, val[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, val[i]);
    ck_assert_msg(s == s21, "s = %d, s21 = %d, val = %o", s, s21, val[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, val = %o", dest, s21_dest, val[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_o_7) {
  int val[] = {-100, -10, 0, 1, 10, 2147483647, 2147483648, 4294967295};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %#0*o cc";
  int width = 16;
  for (int i = 0; i < 8; i++) {
    int s = sprintf(dest, format, width, val[i]);
    int s21 = s21_sprintf(s21_dest, format, width, val[i]);
    ck_assert_msg(s == s21, "s = %d, s21 = %d, val = %o", s, s21, val[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, val = %o", dest, s21_dest, val[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_x_1) {
  int val[] = {-100, -10, 0, 1, 10, 2147483647, 2147483648, 4294967295};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %*.*x cc";
  int width = 10;
  int precision = 5;
  for (int i = 0; i < 8; i++) {
    int s = sprintf(dest, format, width, precision, val[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, val[i]);
    ck_assert_msg(s == s21, "s = %d, s21 = %d, val = %x", s, s21, val[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, val = %x", dest, s21_dest, val[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_x_2) {
  int val[] = {-100, -10, 0, 1, 10, 2147483647, 2147483648, 4294967295};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %1.2x cc";
  int width = 10;
  int precision = 5;
  for (int i = 0; i < 8; i++) {
    int s = sprintf(dest, format, width, precision, val[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, val[i]);
    ck_assert_msg(s == s21, "s = %d, s21 = %d, val = %x", s, s21, val[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, val = %x", dest, s21_dest, val[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_x_3) {
  int val[] = {-100, -10, 0, 1, 10, 2147483647, 2147483648, 4294967295};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb % *.*x cc";
  int width = 0;
  int precision = 15;
  for (int i = 0; i < 8; i++) {
    int s = sprintf(dest, format, width, precision, val[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, val[i]);
    ck_assert_msg(s == s21, "s = %d, s21 = %d, val = %x", s, s21, val[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, val = %x", dest, s21_dest, val[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_x_4) {
  int val[] = {-100, -10, 0, 1, 10, 2147483647, 2147483648, 4294967295};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %- *.*x cc";
  int width = 10;
  int precision = 5;
  for (int i = 0; i < 8; i++) {
    int s = sprintf(dest, format, width, precision, val[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, val[i]);
    ck_assert_msg(s == s21, "s = %d, s21 = %d, val = %x", s, s21, val[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, val = %x", dest, s21_dest, val[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_x_5) {
  int val[] = {-100, -10, 0, 1, 10, 2147483647, 2147483648, 4294967295};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %0*.*x cc";
  int width = 16;
  int precision = 5;
  for (int i = 0; i < 8; i++) {
    int s = sprintf(dest, format, width, precision, val[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, val[i]);
    ck_assert_msg(s == s21, "s = %d, s21 = %d, val = %x", s, s21, val[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, val = %x", dest, s21_dest, val[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_x_6) {
  int val[] = {-100, -10, 0, 1, 10, 2147483647, 2147483648, 4294967295};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %#0*.*x cc";
  int width = 16;
  int precision = 5;
  for (int i = 0; i < 8; i++) {
    int s = sprintf(dest, format, width, precision, val[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, val[i]);
    ck_assert_msg(s == s21, "s = %d, s21 = %d, val = %x", s, s21, val[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, val = %x", dest, s21_dest, val[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_x_7) {
  int val[] = {-100, -10, 0, 1, 10, 2147483647, 2147483648, 4294967295};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %#0*x cc";
  int width = 16;
  for (int i = 0; i < 8; i++) {
    int s = sprintf(dest, format, width, val[i]);
    int s21 = s21_sprintf(s21_dest, format, width, val[i]);
    ck_assert_msg(s == s21, "s = %d, s21 = %d, val = %x", s, s21, val[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, val = %x", dest, s21_dest, val[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_X_1) {
  int val[] = {-100, -10, 0, 1, 10, 2147483647, 2147483648, 4294967295};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %*.*X cc";
  int width = 10;
  int precision = 5;
  for (int i = 0; i < 8; i++) {
    int s = sprintf(dest, format, width, precision, val[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, val[i]);
    ck_assert_msg(s == s21, "s = %d, s21 = %d, val = %X", s, s21, val[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, val = %X", dest, s21_dest, val[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_X_2) {
  int val[] = {-100, -10, 0, 1, 10, 2147483647, 2147483648, 4294967295};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %1.2X cc";
  int width = 10;
  int precision = 5;
  for (int i = 0; i < 8; i++) {
    int s = sprintf(dest, format, width, precision, val[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, val[i]);
    ck_assert_msg(s == s21, "s = %d, s21 = %d, val = %X", s, s21, val[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, val = %X", dest, s21_dest, val[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_X_3) {
  int val[] = {-100, -10, 0, 1, 10, 2147483647, 2147483648, 4294967295};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb % *.*X cc";
  int width = 0;
  int precision = 15;
  for (int i = 0; i < 8; i++) {
    int s = sprintf(dest, format, width, precision, val[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, val[i]);
    ck_assert_msg(s == s21, "s = %d, s21 = %d, val = %X", s, s21, val[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, val = %X", dest, s21_dest, val[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_X_4) {
  int val[] = {-100, -10, 0, 1, 10, 2147483647, 2147483648, 4294967295};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %- *.*X cc";
  int width = 10;
  int precision = 5;
  for (int i = 0; i < 8; i++) {
    int s = sprintf(dest, format, width, precision, val[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, val[i]);
    ck_assert_msg(s == s21, "s = %d, s21 = %d, val = %X", s, s21, val[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, val = %X", dest, s21_dest, val[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_X_5) {
  int val[] = {-100, -10, 0, 1, 10, 2147483647, 2147483648, 4294967295};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %0*.*X cc";
  int width = 16;
  int precision = 5;
  for (int i = 0; i < 8; i++) {
    int s = sprintf(dest, format, width, precision, val[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, val[i]);
    ck_assert_msg(s == s21, "s = %d, s21 = %d, val = %X", s, s21, val[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, val = %X", dest, s21_dest, val[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_X_6) {
  int val[] = {-100, -10, 0, 1, 10, 2147483647, 2147483648, 4294967295};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %#0*.*X cc";
  int width = 16;
  int precision = 5;
  for (int i = 0; i < 8; i++) {
    int s = sprintf(dest, format, width, precision, val[i]);
    int s21 = s21_sprintf(s21_dest, format, width, precision, val[i]);
    ck_assert_msg(s == s21, "s = %d, s21 = %d, val = %X", s, s21, val[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, val = %X", dest, s21_dest, val[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_X_7) {
  int val[] = {-100, -10, 0, 1, 10, 2147483647, 2147483648, 4294967295};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %#0*X cc";
  int width = 16;
  for (int i = 0; i < 8; i++) {
    int s = sprintf(dest, format, width, val[i]);
    int s21 = s21_sprintf(s21_dest, format, width, val[i]);
    ck_assert_msg(s == s21, "s = %d, s21 = %d, val = %X", s, s21, val[i]);
    ck_assert_msg(strcmp(dest, s21_dest) == 0,
                  "dest = %s, s21_dest = %s, val = %X", dest, s21_dest, val[i]);
  }
}
END_TEST

START_TEST(s21_sprintf_s_1) {
  char *val[] = {"", "a", "a   b", "lorem\tipsum", "dolor\nsit\amet"};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %*.*s cc";
  int width[] = {0, 1, 10, 20};
  int precision[] = {0, 1, 10, 20};
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        int s = sprintf(dest, format, width[j], precision[k], val[i]);
        int s21 = s21_sprintf(s21_dest, format, width[j], precision[k], val[i]);
        ck_assert_msg(s == s21, "s = %d, s21 = %d, val = %s", s, s21, val[i]);
        ck_assert_msg(strcmp(dest, s21_dest) == 0,
                      "    dest = %s\ns21_dest = %s, val = %s", dest, s21_dest,
                      val[i]);
      }
    }
  }
}

START_TEST(s21_sprintf_s_2) {
  char *val[] = {"", "a", "a   b", "lorem\tipsum", "dolor\nsit\amet"};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %0*.*s cc";
  int width[] = {0, 1, 10, 20};
  int precision[] = {0, 1, 10, 20};
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        int s = sprintf(dest, format, width[j], precision[k], val[i]);
        int s21 = s21_sprintf(s21_dest, format, width[j], precision[k], val[i]);
        ck_assert_msg(s == s21, "s = %d, s21 = %d, val = %s", s, s21, val[i]);
        ck_assert_msg(strcmp(dest, s21_dest) == 0,
                      "    dest = %s\ns21_dest = %s, val = %s", dest, s21_dest,
                      val[i]);
      }
    }
  }
}

START_TEST(s21_sprintf_s_3) {
  char *val[] = {"", "a", "a   b", "lorem\tipsum", "dolor\nsit\\amet"};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %-*.*s cc";
  int width[] = {0, 1, 10, 20};
  int precision[] = {0, 1, 10, 20};
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        int s = sprintf(dest, format, width[j], precision[k], val[i]);
        int s21 = s21_sprintf(s21_dest, format, width[j], precision[k], val[i]);
        ck_assert_msg(s == s21, "s = %d, s21 = %d, val = %s", s, s21, val[i]);
        ck_assert_msg(strcmp(dest, s21_dest) == 0,
                      "    dest = %s\ns21_dest = %s, val = %s", dest, s21_dest,
                      val[i]);
      }
    }
  }
}

START_TEST(s21_sprintf_s_4) {
  wchar_t *val[] = {L"", L"a", L"a   b", L"lorem\tipsum", L"dolor\nsit\\amet"};
  char dest[100];
  char s21_dest[100];
  const char *format = "aa bb %*.*ls cc";
  int width[] = {0, 1, 10, 20};
  int precision[] = {0, 1, 10, 20};
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        int s = sprintf(dest, format, width[j], precision[k], val[i]);
        int s21 = s21_sprintf(s21_dest, format, width[j], precision[k], val[i]);
        ck_assert_msg(s == s21, "s = %d, s21 = %d, val = %ls", s, s21, val[i]);
        ck_assert_msg(strcmp(dest, s21_dest) == 0,
                      "    dest = %s\ns21_dest = %s, val = %ls", dest, s21_dest,
                      val[i]);
      }
    }
  }
}

Suite *suite_s21_sprintf() {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_sprintf");

  /* Core test case */
  tc_core = tcase_create("case_s21_sprintf");

  tcase_add_test(tc_core, s21_sprintf_x_1);
  tcase_add_test(tc_core, s21_sprintf_x_2);
  tcase_add_test(tc_core, s21_sprintf_x_3);
  tcase_add_test(tc_core, s21_sprintf_x_4);
  tcase_add_test(tc_core, s21_sprintf_x_5);
  tcase_add_test(tc_core, s21_sprintf_x_6);
  tcase_add_test(tc_core, s21_sprintf_x_7);

  tcase_add_test(tc_core, s21_sprintf_X_1);
  tcase_add_test(tc_core, s21_sprintf_X_2);
  tcase_add_test(tc_core, s21_sprintf_X_3);
  tcase_add_test(tc_core, s21_sprintf_X_4);
  tcase_add_test(tc_core, s21_sprintf_X_5);
  tcase_add_test(tc_core, s21_sprintf_X_6);
  tcase_add_test(tc_core, s21_sprintf_X_7);

  tcase_add_test(tc_core, s21_sprintf_o_1);
  tcase_add_test(tc_core, s21_sprintf_o_2);
  tcase_add_test(tc_core, s21_sprintf_o_3);
  tcase_add_test(tc_core, s21_sprintf_o_4);
  tcase_add_test(tc_core, s21_sprintf_o_5);
  tcase_add_test(tc_core, s21_sprintf_o_6);
  tcase_add_test(tc_core, s21_sprintf_o_7);

  tcase_add_test(tc_core, s21_sprintf_proc_1);

  tcase_add_test(tc_core, s21_sprintf_u_1);
  tcase_add_test(tc_core, s21_sprintf_u_2);
  tcase_add_test(tc_core, s21_sprintf_u_3);
  tcase_add_test(tc_core, s21_sprintf_u_4);
  tcase_add_test(tc_core, s21_sprintf_u_5);
  tcase_add_test(tc_core, s21_sprintf_u_6);
  tcase_add_test(tc_core, s21_sprintf_u_7);
  tcase_add_test(tc_core, s21_sprintf_u_8);
  tcase_add_test(tc_core, s21_sprintf_u_9);

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
  tcase_add_test(tc_core, s21_sprintf_i_11);

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

  suite_add_tcase(s, tc_core);

  return s;
}
