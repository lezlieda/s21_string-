#include "../s21_string.h"
#include "../suitecases.h"

START_TEST(test_d_1) {
  int origScan = 0, s21_Scan = 0, d1 = 0, d2 = 0;

  origScan = sscanf("123", "%002d", &d1);
  s21_Scan = s21_sscanf("123", "%002d", &d2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(origScan, s21_Scan);
}
END_TEST

START_TEST(test_f_1) {
  int origScan = 0, s21_Scan = 0;
  float f1 = 0, f2 = 0;

  origScan = sscanf("12e-3", "%f", &f1);
  s21_Scan = s21_sscanf("12e-3", "%f", &f2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(origScan, s21_Scan);

  origScan = sscanf("-123.45", "%f", &f1);
  s21_Scan = s21_sscanf("-123.45", "%f", &f2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(origScan, s21_Scan);

  origScan = sscanf("-12.345", "%5f", &f1);
  s21_Scan = s21_sscanf("-12.345", "%5f", &f2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(origScan, s21_Scan);

  origScan = sscanf("12.345", "%5f", &f1);
  s21_Scan = s21_sscanf("12.345", "%5f", &f2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(origScan, s21_Scan);
}
END_TEST

START_TEST(test_e_1) {
  float e1 = 0, e2 = 0;
  int origScan = 0, s21_Scan = 0;

  origScan = sscanf("123e34", "%e", &e1);
  s21_Scan = s21_sscanf("123e34", "%e", &e2);
  ck_assert_msg(e1 == e2, "float not equals");
  ck_assert_int_eq(origScan, s21_Scan);

  origScan = sscanf("12e34", "%e", &e1);
  s21_Scan = s21_sscanf("12e34", "%e", &e2);
  ck_assert_msg(e1 == e2, "float not equals");
  ck_assert_int_eq(origScan, s21_Scan);

  origScan = sscanf("123.345e-34", "%9e", &e1);
  s21_Scan = s21_sscanf("123.345e-34", "%9e", &e2);
  ck_assert_int_eq(origScan, s21_Scan);
  ck_assert_float_eq(e1, e2);
  ck_assert_msg(e1 == e2, "float not equals");

  origScan = sscanf("123.345e+34", "%7e", &e1);
  s21_Scan = s21_sscanf("123.345e+34", "%7e", &e2);
  ck_assert_float_eq(e1, e2);
  ck_assert_msg(e1 == e2, "float not equals");
  ck_assert_int_eq(origScan, s21_Scan);
}
END_TEST

START_TEST(test_s_1) {
  int origScan = 0, s21_Scan = 0;
  char suite[512] = {0}, str[512] = {0};
  char data[] = "chelChuvak";
  char format[] = "%s";
  char *s1 = suite;
  char *s2 = str;
  origScan = sscanf(data, format, s1);
  s21_Scan = s21_sscanf(data, format, s2);

  ck_assert_str_eq(suite, str);
  ck_assert_int_eq(origScan, s21_Scan);
}
END_TEST

START_TEST(sscanf_o_2) {
  char format[] = "%o%o%o";
  char str[] = "143 +164 -1723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_p_1) {
  char format[] = "%p";
  char str[] = "0xAFA";
  int *p1 = 0, *p2 = 0;

  int res1 = s21_sscanf(str, format, &p1);
  int res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_p_2) {
  char format[] = "%5p";
  char str[] = "0xAAAA";
  int *p1 = 0, *p2 = 0;

  int res1 = s21_sscanf(str, format, &p1);
  int res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_p_3) {
  char format[] = "%p";
  char str[] = "0xFFFFFF";
  int *p1 = 0, *p2 = 0;

  int res1 = s21_sscanf(str, format, &p1);
  int res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_p_4) {
  char format[] = "%p";
  char str[] = "0x0000";
  int *p1 = 0, *p2 = 0;

  int res1 = s21_sscanf(str, format, &p1);
  int res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_p_5) {
  char format[] = "%p";
  char str[] = "0xA2361598";
  int *p1 = 0, *p2 = 0;

  int res1 = s21_sscanf(str, format, &p1);
  int res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_p_6) {
  char format[] = "%p";
  char str[] = "0x34567hjk";
  int *p1 = 0, *p2 = 0;

  int res1 = s21_sscanf(str, format, &p1);
  int res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_p_7) {
  char format[] = "%p";
  char str[] = "0x34567hjk678";
  int *p1 = 0, *p2 = 0;

  int res1 = s21_sscanf(str, format, &p1);
  int res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_p_8) {
  char format[] = "%p";
  char str[] = "0x34ABcd68";
  int *p1 = 0, *p2 = 0;

  int res1 = s21_sscanf(str, format, &p1);
  int res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_p_9) {
  char format[] = "%p";
  char str[] = "1234567890ABCDEF";
  int *p1 = 0, *p2 = 0;

  int res1 = s21_sscanf(str, format, &p1);
  int res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_p_10) {
  char format[] = "%5p";
  char str[] = "0x237481";
  int *p1 = 0, *p2 = 0;

  int res1 = s21_sscanf(str, format, &p1);
  int res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_p_11) {
  char format[] = "%6p";
  char str[] = "0xdksajh";
  int *p1 = 0, *p2 = 0;

  int res1 = s21_sscanf(str, format, &p1);
  int res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_p_12) {
  char format[] = "%6p";
  char str[] = "0xAGAGUIY";
  int *p1 = 0, *p2 = 0;

  int res1 = s21_sscanf(str, format, &p1);
  int res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_p_13) {
  char format[] = "%p";
  char str[] = "0xAGAGUIYUYGFSV";
  int *p1 = 0, *p2 = 0;

  int res1 = s21_sscanf(str, format, &p1);
  int res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_p_14) {
  char format[] = "%p";
  char str[] = "0xAA64BB";
  int *p1 = 0, *p2 = 0;

  int res1 = s21_sscanf(str, format, &p1);
  int res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_p_15) {
  char format[] = "%p";
  char str[] = "0xGGH7TY";
  int *p1 = 0, *p2 = 0;

  int res1 = s21_sscanf(str, format, &p1);
  int res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}

START_TEST(sscanf_o_4) {
  char format[] = "%2o %2o %2o";
  char str[] = "123 +04 -3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_llo_2) {
  char format[] = "%llo%llo%llo";
  char str[] = "123 +1564 -1723";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_llo_4) {
  char format[] = "%2llo %2llo %2llo";
  char str[] = "0123 +04 -3723";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST
START_TEST(sscanf_llo_3) {
  char format[] = "%1llo %1llo %1llo";
  char str[] = "1 +04 -3723";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_hhx_1) {
  char format[] = "%hx%hx%hx";
  char str[] = "123 +198 -87";
  unsigned short int d1, d2;
  unsigned short int q1, q2;
  unsigned short int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_hhx_2) {
  char format[] = "%hx%hx%hx";
  char str[] = "12a3 +156B4 -17C23";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_hhx_3) {
  char format[] = "%hx%hx";
  char str[] = "0 +0x";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1);
  int res2 = sscanf(str, format, &d2, &q2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
}
END_TEST

START_TEST(sscanf_hhx_4) {
  char format[] = "%hx%hx%hx";
  char str[] = "0 -0XABC -0X";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_hhx_5) {
  char format[] = "%hx%hx%hx";
  char str[] = "0abc4 -0XABC 0x";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_hhx_6) {
  char format[] = "%1hx %1hx %1hx";
  char str[] = "1a +04 -3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_hhx_7) {
  char format[] = "%1hx %1hx %1hx";
  char str[] = "1a 0x -3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_hhx_8) {
  char format[] = "%2hx %2hx %2hx";
  char str[] = "1a bc 0x -3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_hhx_9) {
  char format[] = "%2hx %2hx %2hx";
  char str[] = "1a bCc 0x -3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_hhx_10) {
  char format[] = "%3hx %3hx %3hx";
  char str[] = "0x123 +0X4 -37x23";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_hhx_11) {
  char format[] = "%*hx %*hx %*hx";
  char str[] = "0x123 +04 -372f3";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_hx_1) {
  char format[] = "%hx%hx%hx";
  char str[] = "123 +198 -87";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_hx_2) {
  char format[] = "%hx%hx%hx";
  char str[] = "12a3 +156B4 -17C23";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_hx_3) {
  char format[] = "%hx%hx";
  char str[] = "0 +0x";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1);
  int res2 = sscanf(str, format, &d2, &q2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
}
END_TEST

START_TEST(sscanf_hx_4) {
  char format[] = "%hx%hx%hx";
  char str[] = "0 -0XABC -0X";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_hx_5) {
  char format[] = "%hx%hx%hx";
  char str[] = "0abc4 -0XABC 0x";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_hx_6) {
  char format[] = "%1hx %1hx %1hx";
  char str[] = "1a +04 -3723";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_hx_7) {
  char format[] = "%1hx %1hx %1hx";
  char str[] = "1a 0x -3723";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_hx_8) {
  char format[] = "%2hx %2hx %2hx";
  char str[] = "1a bc 0x -3723";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_hx_9) {
  char format[] = "%2hx %2hx %2hx";
  char str[] = "1a bCc 0x -3723";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_hx_10) {
  char format[] = "%3hx %3hx %3hx";
  char str[] = "0x123 +0X4 -37x23";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_hx_11) {
  char format[] = "%*hx %*hx %*hx";
  char str[] = "0x123 +04 -372f3";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_x_1) {
  char format[] = "%x%x%x";
  char str[] = "123 +198 -87";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_x_2) {
  char format[] = "%x%x%x";
  char str[] = "12a3 +156B4 -17C23";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_x_3) {
  char format[] = "%x%x";
  char str[] = "0 +0x";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1);
  int res2 = sscanf(str, format, &d2, &q2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
}
END_TEST

START_TEST(sscanf_x_4) {
  char format[] = "%x%x%x";
  char str[] = "0 -0XABC -0X";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_x_5) {
  char format[] = "%x%x%x";
  char str[] = "0abc4 -0XABC 0x";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_x_6) {
  char format[] = "%1x %1x %1x";
  char str[] = "1a +04 -3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_x_7) {
  char format[] = "%1x %1x %1x";
  char str[] = "1a 0x -3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_x_8) {
  char format[] = "%2x %2x %2x";
  char str[] = "1a bc 0x -3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_x_9) {
  char format[] = "%2x %2x %2x";
  char str[] = "1a bCc 0x -3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_x_10) {
  char format[] = "%3x %3x %3x";
  char str[] = "0x123 +0X4 -37x23";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_x_11) {
  char format[] = "%*x %*x %*x";
  char str[] = "0x123 +04 -372f3";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_lx_1) {
  char format[] = "%lx%lx%lx";
  char str[] = "123 +198 -87";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_lx_2) {
  char format[] = "%lx%lx%lx";
  char str[] = "12a3 +156B4 -17C23";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_lx_3) {
  char format[] = "%lx%lx";
  char str[] = "0 +0x";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1);
  int res2 = sscanf(str, format, &d2, &q2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
}
END_TEST

START_TEST(sscanf_lx_4) {
  char format[] = "%lx%lx%lx";
  char str[] = "0 -0XABC -0X";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_lx_5) {
  char format[] = "%lx%lx%lx";
  char str[] = "0abc4 -0XABC 0x";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_lx_6) {
  char format[] = "%1lx %1lx %1lx";
  char str[] = "1a +04 -3723";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_lx_7) {
  char format[] = "%1lx %1lx %1lx";
  char str[] = "1a 0x -3723";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_lx_8) {
  char format[] = "%2lx %2lx %2lx";
  char str[] = "1a bc 0x -3723";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_lx_9) {
  char format[] = "%2lx %2lx %2lx";
  char str[] = "1a bCc 0x -3723";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_lx_10) {
  char format[] = "%3lx %3lx %3lx";
  char str[] = "0x123 +0X4 -37x23";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_lx_11) {
  char format[] = "%*lx %*lx %*lx";
  char str[] = "0x123 +04 -372f3";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_llx_1) {
  char format[] = "%llx%llx%llx";
  char str[] = "123 +198 -87";
  unsigned long long int d1, d2;
  unsigned long long int q1, q2;
  unsigned long long int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_llx_2) {
  char format[] = "%llx%llx%llx";
  char str[] = "12a3 +156B4 -17C23";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_llx_3) {
  char format[] = "%llx%llx";
  char str[] = "0 +0x";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1);
  int res2 = sscanf(str, format, &d2, &q2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
}
END_TEST

START_TEST(sscanf_llx_4) {
  char format[] = "%llx%llx%llx";
  char str[] = "0 -0XABC -0X";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_llx_5) {
  char format[] = "%llx%llx%llx";
  char str[] = "0abc4 -0XABC 0x";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_llx_6) {
  char format[] = "%1llx %1llx %1llx";
  char str[] = "1a +04 -3723";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_llx_7) {
  char format[] = "%1llx %1llx %1llx";
  char str[] = "1a 0x -3723";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_llx_8) {
  char format[] = "%2llx %2llx %2llx";
  char str[] = "1a bc 0x -3723";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_llx_9) {
  char format[] = "%2llx %2llx %2llx";
  char str[] = "1a bCc 0x -3723";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_llx_10) {
  char format[] = "%3llx %3llx %3llx";
  char str[] = "0x123 +0X4 -37x23";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_llx_11) {
  char format[] = "%*llx %*llx %*llx";
  char str[] = "0xF23 +04 -372f3";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_o_3) {
  char format[] = "%1o %1o %1o";
  char str[] = "1 +04 -3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_o_5) {
  char format[] = "%3o %3o %3o";
  char str[] = "0123 +04 -3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_o_6) {
  char format[] = "%*o %*o %*o";
  char str[] = "0123 +04 -3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_c_2) {
  char format[] = "%c";
  char str[] = "\t\n\n  1 \n  \t";
  char c1, c2;

  int res1 = s21_sscanf(str, format, &c1);
  int res2 = sscanf(str, format, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_c_4) {
  char format[] = "%c";
  char str[] = "\t\n\n   \n  \ta";
  char c1, c2;
  int res1 = s21_sscanf(str, format, &c1);
  int res2 = sscanf(str, format, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_c_5) {
  char format[] = "r%c%c%c";
  char str[] = "r\t\n\n  123 \n  \t";
  char c11, c12, c13, c21, c22, c23;

  int res1 = s21_sscanf(str, format, &c11, &c12, &c13);
  int res2 = sscanf(str, format, &c21, &c22, &c23);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
  ck_assert_int_eq(c13, c23);
}
END_TEST

START_TEST(sscanf_hi_dec_1) {
  char format[] = "%hi%hi%hi";
  char str[] = "123 +198 -87";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_hi_dec_2) {
  char format[] = "%hi %hi %hi";
  char str[] = "123 +198 -87";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_hi_dec_3) {
  char format[] = "%1hi %1hi %1hi";
  char str[] = "13 +137 -8";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_hi_dec_4) {
  char format[] = "%2hi %2hi %2hi";
  char str[] = "13 +137 -8";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_hi_dec_5) {
  char format[] = "%3hi %3hi %3hi";
  char str[] = "13 +137 -8";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_hi_dec_6) {
  char format[] = "%30hi %24hi %21hi";
  char str[] = "13 +137 -8";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_hi_dec_7) {
  char format[] = "%hi %hi %hi %hi";
  char str[] = "2147483647 +2147483648 -2147483648 -2147483649";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;
  unsigned short w1, w2;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_hi_oct_1) {
  char format[] = "%hi%hi%hi";
  char str[] = "0123 +0198 -087";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;
  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_hi_oct_2) {
  char format[] = "%hi %hi %hi";
  char str[] = "0123 +0198 -087";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_hi_oct_3) {
  char format[] = "%1hi %1hi %1hi";
  char str[] = "013 +0137 -08";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_hi_oct_4) {
  char format[] = "%2hi %2hi %2hi";
  char str[] = "013 +0137 -08";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_hi_oct_5) {
  char format[] = "%3hi %3hi %3hi";
  char str[] = "013 +0137 -08";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_hi_oct_6) {
  char format[] = "%30hi %24hi %21hi";
  char str[] = "013 +0137 -08";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;
  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_hi_hex_1) {
  char format[] = "%hi%hi%hi";
  char str[] = "0x123 +0X198 -0x87";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_hi_hex_2) {
  char format[] = "%hi %hi %hi";
  char str[] = "0X123 +0x198 -0X87";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_hi_hex_5) {
  char format[] = "%3hi %3hi %3hi";
  char str[] = "0x13 +0x137 -0x8";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_hi_hex_6) {
  char format[] = "%30hi %24hi %21hi";
  char str[] = "0x13 +0x1a -0x8";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;
  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_i_dec_1) {
  char format[] = "%i%i%i";
  char str[] = "123 +198 -87";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_i_dec_2) {
  char format[] = "%i %i %i";
  char str[] = "123 +198 -87";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_i_dec_3) {
  char format[] = "%1i %1i %1i";
  char str[] = "13 +137 -8";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_i_dec_4) {
  char format[] = "%2i %2i %2i";
  char str[] = "13 +137 -8";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_i_dec_5) {
  char format[] = "%3i %3i %3i";
  char str[] = "13 +137 -8";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_i_dec_6) {
  char format[] = "%30i %24i %21i";
  char str[] = "13 +137 -8";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_i_dec_7) {
  char format[] = "%i %i %i %i";
  char str[] = "2147483647 +2147483648 -2147483648 -2147483649";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;
  unsigned int w1, w2;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_i_oct_1) {
  char format[] = "%i%i%i";
  char str[] = "0123 +0198 -087";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_i_oct_2) {
  char format[] = "%i %i %i";
  char str[] = "0123 +0198 -087";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_i_oct_3) {
  char format[] = "%1i %1i %1i";
  char str[] = "013 +0137 -08";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_i_oct_4) {
  char format[] = "%2i %2i %2i";
  char str[] = "013 +0137 -08";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_i_oct_5) {
  char format[] = "%3i %3i %3i";
  char str[] = "013 +0137 -08";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_i_oct_6) {
  char format[] = "%30i %24i %21i";
  char str[] = "013 +0137 -08";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;
  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_i_hex_1) {
  char format[] = "%i%i%i";
  char str[] = "0x123 +0X198 -0x87";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_i_hex_2) {
  char format[] = "%i %i %i";
  char str[] = "0X123 +0x198 -0X87";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_i_hex_5) {
  char format[] = "%3i %3i %3i";
  char str[] = "0x13 +0x1F7 -0x1";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_i_hex_6) {
  char format[] = "%30i %24i %21i";
  char str[] = "0x23 +0x2a -0x8";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;
  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_li_dec_1) {
  char format[] = "%li%li%li";
  char str[] = "123 +198 -87";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_li_dec_2) {
  char format[] = "%li %li %li";
  char str[] = "123 +198 -87";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_li_dec_3) {
  char format[] = "%1li %1li %1li";
  char str[] = "13 +137 -8";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_li_dec_4) {
  char format[] = "%2li %2li %2li";
  char str[] = "13 +107 -8";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_li_dec_5) {
  char format[] = "%3li %3li %3li";
  char str[] = "13 +137 -8";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_li_dec_6) {
  char format[] = "%30li %24li %21li";
  char str[] = "13 +137 -8";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_li_oct_1) {
  char format[] = "%li%li%li";
  char str[] = "0123 +0198 -087";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_li_oct_2) {
  char format[] = "%li %li %li";
  char str[] = "0123 +0198 -087";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_li_oct_3) {
  char format[] = "%1li %1li %1li";
  char str[] = "013 +0137 -08";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_li_oct_4) {
  char format[] = "%2li %2li %2li";
  char str[] = "013 +0137 -08";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_li_oct_5) {
  char format[] = "%3li %3li %3li";
  char str[] = "013 +0137 -08";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_li_oct_6) {
  char format[] = "%30li %24li %21li";
  char str[] = "013 +0137 -08";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_li_hex_1) {
  char format[] = "%li%li%li";
  char str[] = "0x123 +0X198 -0x87";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_li_hex_2) {
  char format[] = "%li %li %li";
  char str[] = "0X123 +0x198 -0X87";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_li_hex_5) {
  char format[] = "%3li %3li %3li";
  char str[] = "0x13 +0x137 -0x8";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_li_hex_6) {
  char format[] = "%30li %24li %21li";
  char str[] = "0x13 +0x1a -0x8";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_hd_9) {
  char format[] = "%4hd";
  char str[] = "+123";
  short d1, d2;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_hd_10) {
  char format[] = "%10hd";
  char str[] = "+123";
  short d1, d2;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_hd_11) {
  char format[] = "%1hd";
  char str[] = "+123";
  short d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_hd_12) {
  char format[] = "%*1hd";
  char str[] = "+123";
  short d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_hd_13) {
  char format[] = "%*hd";
  char str[] = "123";
  short d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_hd_14) {
  char format[] = "%hd";
  char str[] = "2147483647";
  short d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_hd_15) {
  char format[] = "%hd";
  char str[] = "+2147483648";
  short d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_hd_16) {
  char format[] = "%hd";
  char str[] = "214743483648";
  short d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_hd_17) {
  char format[] = "%hd";
  char str[] = "-2147483648";
  short d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_hd_18) {
  char format[] = "%hd";
  char str[] = "-2147483649";
  short d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_hd_19) {
  char format[] = "%hd";
  char str[] = "-214748364239";
  short d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_hd_20) {
  char format[] = "%hd";
  char str[] = "−9223372036854775808";
  short d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_hd_21) {
  char format[] = "%hd";
  char str[] = "−9223372036854775809";
  short d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_hd_22) {
  char format[] = "%hd";
  char str[] = "−922337203685477582309";
  short d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_d_1) {
  char format[] = "%d";
  char str[] = "123";
  int d1, d2;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_d_2) {
  char format[] = "%d";
  char str[] = "-123";
  int d1, d2;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_d_3) {
  char format[] = "%d";
  char str[] = "+123";
  int d1, d2;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_d_4) {
  char format[] = "%3d";
  char str[] = "-123";
  int d1, d2;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_d_5) {
  char format[] = "%4d";
  char str[] = "-123";
  int d1, d2;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_d_6) {
  char format[] = "%10d";
  char str[] = "-123";
  int d1, d2;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_ld_17) {
  char format[] = "%*ld";
  char str[] = "-2147483648";
  long int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_ld_18) {
  char format[] = "%5ld";
  char str[] = "-2147483649";
  long int d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_n_1) {
  char format[] = "%n";
  char str[] = "Sasha";
  int n1 = 0, n2 = 0;

  int res1 = s21_sscanf(str, format, &n1);
  int res2 = sscanf(str, format, &n2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sscanf_n_2) {
  char format[] = "%d %n";
  char str[] = "80 Sasha";
  int d1 = 0, d2 = 0;
  int n1 = 0, n2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &n1);
  int res2 = sscanf(str, format, &d2, &n2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sscanf_n_3) {
  char format[] = "%d %d %n %d %d %d";
  char str[] = "80 50 70 371 327";
  int d1 = 0, d2 = 0;
  int dd1 = 0, dd2 = 0;
  int f1 = 0, f2 = 0;
  int ff1 = 0, ff2 = 0;
  int k1 = 0, k2 = 0;
  int n1 = 0, n2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &dd1, &n1, &f1, &ff1, &k1);
  int res2 = sscanf(str, format, &d2, &dd2, &n2, &f2, &ff2, &k2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(dd1, dd2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(ff1, ff2);
  ck_assert_int_eq(k1, k2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sscanf_f_1) {
  char format[] = "%f %f %f";
  char str[] = "344. +198 -87";
  float d1, d2;
  float q1, q2;
  float z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_f_2) {
  char format[] = "%3fg %f w%fx";
  char str[] = "75g +19.8w -87.x";
  float d1, d2;
  float q1, q2;
  float z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_f_3) {
  char format[] = "%5f %f %f %f";
  char str[] = "NAN -nan +INF -inf";
  float d1, d2;
  float q1, q2;
  float z1, z2;
  float w1, w2;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_nan(d1);
  ck_assert_float_nan(d2);
  ck_assert_float_nan(q1);
  ck_assert_float_nan(q2);
  ck_assert_float_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_f_4) {
  char format[] = "%f";
  char str[] = "Nap";
  float d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_f_5) {
  char format[] = "%f";
  char str[] = "Np";
  float d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_f_6) {
  char format[] = "%f";
  char str[] = "iNd";
  float d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_f_7) {
  char format[] = "%f";
  char str[] = "id";
  float d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_f_8) {
  char format[] = "%f %f %f %f";
  char str[] = "34.56e3 83.2e-4 .43e+1 +2.43e3";
  float d1, d2;
  float q1, q2;
  float z1, z2;
  float w1, w2;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_f_9) {
  char format[] = "%1f %1f %2f %1f";
  char str[] = "34.5+6e3 83.2e-4 .43e+1 +2.43e3";
  float d1, d2;
  float q1, q2;
  float z1, z2;
  float w1 = 0, w2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_f_10) {
  char format[] = "%*f %7f %*f %*f";
  char str[] = "34.5+6e3 83.2e-4 +43e+1 +2.43e3";
  float d1, d2;
  float q1 = 0, q2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1);
  int res2 = sscanf(str, format, &d2, &q2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
}
END_TEST

START_TEST(sscanf_f_11) {
  char format[] = "%fr %7f p";
  char str[] = "34.5r 83.2ep4";
  float d1, d2;
  float q1 = 0, q2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1);
  int res2 = sscanf(str, format, &d2, &q2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
}
END_TEST

START_TEST(sscanf_f_12) {
  char format[] = "%1f %1f %1f %1f";
  char str[] = "34 32. +45.e +23E3 -0.3e4";
  float d1, d2;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_f_13) {
  char format[] = "%2f %2f %2f %2f";
  char str[] = "34 3. +45.e +23E3 -0.3e4";
  float d1, d2;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_f_14) {
  char format[] = "%3f %3f %4f %3f";
  char str[] = "34 3. +45.e +23E3 -0.3e4";
  float d1, d2;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_f_15) {
  char format[] = "%4f %4f %4f %4f";
  char str[] = "34 3. +45.e +23E3 -0.3e4";
  float d1, d2;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_f_16) {
  float e1 = 0, e2 = 0;
  int origScan = 0, s21_Scan = 0;

  origScan = sscanf("123e34", "%e", &e1);
  s21_Scan = s21_sscanf("123e34", "%e", &e2);
  ck_assert_msg(e1 == e2, "float not equals");
  ck_assert_int_eq(origScan, s21_Scan);

  origScan = sscanf("12e34", "%e", &e1);
  s21_Scan = s21_sscanf("12e34", "%e", &e2);
  ck_assert_msg(e1 == e2, "float not equals");
  ck_assert_int_eq(origScan, s21_Scan);

  origScan = sscanf("123.345e-34", "%9e", &e1);
  s21_Scan = s21_sscanf("123.345e-34", "%9e", &e2);
  ck_assert_int_eq(origScan, s21_Scan);
  ck_assert_float_eq(e1, e2);
  ck_assert_msg(e1 == e2, "float not equals");

  origScan = sscanf("123.345e+34", "%7e", &e1);
  s21_Scan = s21_sscanf("123.345e+34", "%7e", &e2);
  ck_assert_float_eq(e1, e2);
  ck_assert_msg(e1 == e2, "float not equals");
  ck_assert_int_eq(origScan, s21_Scan);
}
END_TEST

START_TEST(sscanf_f_17) {
  char format[] = "%le";
  char str[] = "8762e+2";
  double d1, d2;
  int res1 = s21_sscanf(str, format, &d1);
  int res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_f_18) {
  char format[] = "%f %fx %2f1 %2fx %*f %*f";
  char str[] = "1.1 2.x 1.1 2.x 1.1 2.x";
  float d1, d2;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_f_19) {
  char format[] = "%f %4f %5fq %6f %*f q%*f";
  char str[] = "1.3e1 1.4eq2 1.3e1q 1.4 1.3eq 1.4e2";
  float d1, d2;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_f_20) {
  long double fl1, fl2;
  long double dbl1, dbl2;
  char str[] = "  -876.214235  2145.9356544  324.21427 ";
  char format[] = "%Lf%Lf%*f";
  int Std_Lib = sscanf(str, format, &fl1, &dbl1);
  int Our_Lib = s21_sscanf(str, format, &fl2, &dbl2);
  ck_assert_int_eq(Std_Lib, Our_Lib);
  ck_assert_float_eq(dbl1, dbl2);
  ck_assert_float_eq(fl1, fl2);
}
END_TEST

START_TEST(sscanf_s_1) {
  char s1[512] = {'\0'};
  char s2[512] = {'\0'};
  char s3[512] = {'\0'};
  char s5[512] = {'\0'};
  char s6[512] = {'\0'};
  char s7[512] = {'\0'};
  char s8[512] = {'\0'};
  char s9[512] = {'\0'};

  const char str[] = "cbobErobM fl? asdfasdflkasdf asdfasdf asdfasdf 88888";
  const char fstr[] = "%s %s %s %s";

  int32_t res1 = s21_sscanf(str, fstr, s1, s2, s9, s3);
  int32_t res2 = sscanf(str, fstr, s5, s6, s8, s7);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s9, s8);
  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
}
END_TEST

START_TEST(sscanf_s_2) {
  char s1[512] = {'\0'};
  char s2[512] = {'\0'};
  char s3[512] = {'\0'};
  char s4[512] = {'\0'};

  char s5[512] = {'\0'};
  char s6[512] = {'\0'};
  char s7[512] = {'\0'};
  char s8[512] = {'\0'};

  const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
  const char fstr[] = "%s%s%s\t%s";

  int res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(sscanf_s_3) {
  char s1[512] = {'\0'};
  char s2[512] = {'\0'};
  char s3[512] = {'\0'};
  char s4[512] = {'\0'};

  char s5[512] = {'\0'};
  char s6[512] = {'\0'};
  char s7[512] = {'\0'};
  char s8[512] = {'\0'};

  const char str[] = "Aboba Floppa Keppa Shleppa Anuroba";
  const char fstr[] = "%s %s %s %s";

  int res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(sscanf_s_4) {
  char s1[512] = {'\0'};
  char s2[512] = {'\0'};
  char s3[512] = {'\0'};
  char s4[512] = {'\0'};

  char s5[512] = {'\0'};
  char s6[512] = {'\0'};
  char s7[512] = {'\0'};
  char s8[512] = {'\0'};

  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] = "Aboba 123 Floppa -3 Keppa 4444Shleppa 333Anuroba 3";
  const char fstr[] = "%s%ld%s%d%s%d%s";

  int res1 = s21_sscanf(str, fstr, s1, &a1, s2, &b1, s3, &c1, s4, &d1);
  int res2 = s21_sscanf(str, fstr, s5, &a2, s6, &b2, s7, &c2, s8, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(sscanf_s_5) {
  char s1[512] = {'\0'};
  char s2[512] = {'\0'};
  char s3[512] = {'\0'};
  char s4[512] = {'\0'};

  char s5[512] = {'\0'};
  char s6[512] = {'\0'};
  char s7[512] = {'\0'};
  char s8[512] = {'\0'};

  const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
  const char fstr[] = "%s%s%s%s";

  int res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(sscanf_s_6) {
  char s1[512] = {'\0'};
  char s2[512] = {'\0'};
  char s3[512] = {'\0'};
  char s4[512] = {'\0'};

  char s5[512] = {'\0'};
  char s6[512] = {'\0'};
  char s7[512] = {'\0'};
  char s8[512] = {'\0'};

  const char str[] = "aboba\tkepaboba floppa shleppa koooppa ap p p p p";
  const char fstr[] = "%*s%*s%*s%*s";

  int res1 = s21_sscanf(str, fstr);
  int res2 = sscanf(str, fstr);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(sscanf_s_7) {
  char s1[512] = {'\0'};
  char *s11 = s1;
  char s2[512] = {'\0'};
  char *s12 = s2;
  char s3[512] = {'\0'};
  char *s13 = s3;
  char s4[512] = {'\0'};
  char *s14 = s4;

  char s5[512] = {'\0'};
  char *s15 = s5;
  char s6[512] = {'\0'};
  char *s16 = s6;
  char s7[512] = {'\0'};
  char *s17 = s7;
  char s8[512] = {'\0'};
  char *s18 = s8;

  const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
  const char fstr[] = "%1s%1s%1s%1s";

  int res1 = s21_sscanf(str, fstr, s11, s12, s13, s14);
  int res2 = sscanf(str, fstr, s15, s16, s17, s18);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(sscanf_s_8) {
  char s1[512] = {'\0'};
  char *s11 = s1;
  char s2[512] = {'\0'};
  char *s12 = s2;
  char s3[512] = {'\0'};
  char *s13 = s3;
  char s4[512] = {'\0'};
  char *s14 = s4;

  char s5[512] = {'\0'};
  char *s15 = s5;
  char s6[512] = {'\0'};
  char *s16 = s6;
  char s7[512] = {'\0'};
  char *s17 = s7;
  char s8[512] = {'\0'};
  char *s18 = s8;

  const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
  const char fstr[] = "%3s%3s%3s%3s";

  int res1 = s21_sscanf(str, fstr, s11, s12, s13, s14);
  int res2 = sscanf(str, fstr, s15, s16, s17, s18);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(test_parse_string) {
  char buf1[100] = {0}, buf2[100] = {0};
  char *buf11 = buf1;
  char *buf12 = buf2;
  char format1[] = "%s";
  char format2[] = "%5s";
  char format3[] = "%s %s";

  char data1[] = "1234567890";
  char data2[] = "abcdefghk";
  char data3[] = "123 456";
  char data4[] = "";

  ck_assert_int_eq(s21_sscanf(data1, format1, buf11),
                   sscanf(data1, format1, buf12));
  ck_assert_str_eq(buf1, buf2);

  ck_assert_int_eq(s21_sscanf(data2, format2, buf11),
                   sscanf(data2, format2, buf12));
  ck_assert_str_eq(buf1, buf2);

  // empty string
  ck_assert_int_eq(s21_sscanf(data4, format1, buf11),
                   sscanf(data4, format1, buf12));
  ck_assert_str_eq(buf1, buf2);

  // two strings with space
  char buf3[100] = {0}, buf4[100] = {0};
  char *buf13 = buf3;
  char *buf14 = buf4;
  ck_assert_int_eq(s21_sscanf(data3, format3, buf11, buf13),
                   sscanf(data3, format3, buf12, buf14));
  ck_assert_str_eq(buf1, buf2);
  ck_assert_str_eq(buf3, buf4);
}
END_TEST

START_TEST(sscanf_u_1) {
  char format[] = "%u%u%u";
  char str[] = "12 -100 4";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

Suite *suite_s21_sscanf() {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_sscanf");

  /* Core test case */
  tc_core = tcase_create("case_s21_sscanf");

  tcase_add_test(tc_core, test_e_1);
  tcase_add_test(tc_core, test_f_1);
  tcase_add_test(tc_core, test_d_1);
  tcase_add_test(tc_core, test_s_1);

  tcase_add_test(tc_core, sscanf_o_2);

  tcase_add_test(tc_core, sscanf_p_1);
  tcase_add_test(tc_core, sscanf_p_2);

  tcase_add_test(tc_core, sscanf_p_3);
  tcase_add_test(tc_core, sscanf_p_4);
  tcase_add_test(tc_core, sscanf_p_5);
  tcase_add_test(tc_core, sscanf_p_6);
  tcase_add_test(tc_core, sscanf_p_7);
  tcase_add_test(tc_core, sscanf_p_8);
  tcase_add_test(tc_core, sscanf_p_9);
  tcase_add_test(tc_core, sscanf_p_10);
  tcase_add_test(tc_core, sscanf_p_11);
  tcase_add_test(tc_core, sscanf_p_12);
  tcase_add_test(tc_core, sscanf_p_13);
  tcase_add_test(tc_core, sscanf_p_14);
  tcase_add_test(tc_core, sscanf_p_15);
  tcase_add_test(tc_core, sscanf_o_4);

  tcase_add_test(tc_core, sscanf_llo_2);
  tcase_add_test(tc_core, sscanf_llo_3);
  tcase_add_test(tc_core, sscanf_llo_4);

  tcase_add_test(tc_core, sscanf_hhx_1);
  tcase_add_test(tc_core, sscanf_hhx_2);
  tcase_add_test(tc_core, sscanf_hhx_3);
  tcase_add_test(tc_core, sscanf_hhx_4);
  tcase_add_test(tc_core, sscanf_hhx_5);
  tcase_add_test(tc_core, sscanf_hhx_6);
  tcase_add_test(tc_core, sscanf_hhx_7);
  tcase_add_test(tc_core, sscanf_hhx_8);
  tcase_add_test(tc_core, sscanf_hhx_9);
  tcase_add_test(tc_core, sscanf_hhx_10);
  tcase_add_test(tc_core, sscanf_hhx_11);
  tcase_add_test(tc_core, sscanf_hx_1);
  tcase_add_test(tc_core, sscanf_hx_2);
  tcase_add_test(tc_core, sscanf_hx_3);
  tcase_add_test(tc_core, sscanf_hx_4);
  tcase_add_test(tc_core, sscanf_hx_5);
  tcase_add_test(tc_core, sscanf_hx_6);
  tcase_add_test(tc_core, sscanf_hx_7);
  tcase_add_test(tc_core, sscanf_hx_8);
  tcase_add_test(tc_core, sscanf_hx_9);
  tcase_add_test(tc_core, sscanf_hx_10);
  tcase_add_test(tc_core, sscanf_hx_11);
  tcase_add_test(tc_core, sscanf_x_1);
  tcase_add_test(tc_core, sscanf_x_2);
  tcase_add_test(tc_core, sscanf_x_3);
  tcase_add_test(tc_core, sscanf_x_4);
  tcase_add_test(tc_core, sscanf_x_5);
  tcase_add_test(tc_core, sscanf_x_6);
  tcase_add_test(tc_core, sscanf_x_7);
  tcase_add_test(tc_core, sscanf_x_8);
  tcase_add_test(tc_core, sscanf_x_9);
  tcase_add_test(tc_core, sscanf_x_10);
  tcase_add_test(tc_core, sscanf_x_11);
  tcase_add_test(tc_core, sscanf_lx_1);
  tcase_add_test(tc_core, sscanf_lx_2);
  tcase_add_test(tc_core, sscanf_lx_3);
  tcase_add_test(tc_core, sscanf_lx_4);
  tcase_add_test(tc_core, sscanf_lx_5);
  tcase_add_test(tc_core, sscanf_lx_6);
  tcase_add_test(tc_core, sscanf_lx_7);
  tcase_add_test(tc_core, sscanf_lx_8);
  tcase_add_test(tc_core, sscanf_lx_9);
  tcase_add_test(tc_core, sscanf_lx_10);
  tcase_add_test(tc_core, sscanf_lx_11);
  tcase_add_test(tc_core, sscanf_llx_1);
  tcase_add_test(tc_core, sscanf_llx_2);
  tcase_add_test(tc_core, sscanf_llx_3);
  tcase_add_test(tc_core, sscanf_llx_4);
  tcase_add_test(tc_core, sscanf_llx_5);
  tcase_add_test(tc_core, sscanf_llx_6);
  tcase_add_test(tc_core, sscanf_llx_7);
  tcase_add_test(tc_core, sscanf_llx_8);
  tcase_add_test(tc_core, sscanf_llx_9);
  tcase_add_test(tc_core, sscanf_llx_10);
  tcase_add_test(tc_core, sscanf_llx_11);

  tcase_add_test(tc_core, sscanf_o_3);
  tcase_add_test(tc_core, sscanf_o_5);
  tcase_add_test(tc_core, sscanf_o_6);

  tcase_add_test(tc_core, sscanf_c_2);
  tcase_add_test(tc_core, sscanf_c_4);
  tcase_add_test(tc_core, sscanf_c_5);

  tcase_add_test(tc_core, sscanf_i_dec_1);
  tcase_add_test(tc_core, sscanf_i_dec_2);
  tcase_add_test(tc_core, sscanf_i_dec_3);
  tcase_add_test(tc_core, sscanf_i_dec_4);
  tcase_add_test(tc_core, sscanf_i_dec_5);
  tcase_add_test(tc_core, sscanf_i_dec_6);
  tcase_add_test(tc_core, sscanf_i_dec_7);

  tcase_add_test(tc_core, sscanf_i_oct_1);
  tcase_add_test(tc_core, sscanf_i_oct_2);
  tcase_add_test(tc_core, sscanf_i_oct_3);
  tcase_add_test(tc_core, sscanf_i_oct_4);
  tcase_add_test(tc_core, sscanf_i_oct_5);
  tcase_add_test(tc_core, sscanf_i_oct_6);

  tcase_add_test(tc_core, sscanf_i_hex_1);
  tcase_add_test(tc_core, sscanf_i_hex_2);
  tcase_add_test(tc_core, sscanf_i_hex_5);
  tcase_add_test(tc_core, sscanf_i_hex_6);

  tcase_add_test(tc_core, sscanf_hi_dec_1);
  tcase_add_test(tc_core, sscanf_hi_dec_2);
  tcase_add_test(tc_core, sscanf_hi_dec_3);
  tcase_add_test(tc_core, sscanf_hi_dec_4);
  tcase_add_test(tc_core, sscanf_hi_dec_5);
  tcase_add_test(tc_core, sscanf_hi_dec_6);
  tcase_add_test(tc_core, sscanf_hi_dec_7);

  tcase_add_test(tc_core, sscanf_hi_oct_1);
  tcase_add_test(tc_core, sscanf_hi_oct_2);
  tcase_add_test(tc_core, sscanf_hi_oct_3);
  tcase_add_test(tc_core, sscanf_hi_oct_4);
  tcase_add_test(tc_core, sscanf_hi_oct_5);
  tcase_add_test(tc_core, sscanf_hi_oct_6);

  tcase_add_test(tc_core, sscanf_hi_hex_1);
  tcase_add_test(tc_core, sscanf_hi_hex_2);
  tcase_add_test(tc_core, sscanf_hi_hex_5);
  tcase_add_test(tc_core, sscanf_hi_hex_6);

  tcase_add_test(tc_core, sscanf_li_dec_1);
  tcase_add_test(tc_core, sscanf_li_dec_2);
  tcase_add_test(tc_core, sscanf_li_dec_3);
  tcase_add_test(tc_core, sscanf_li_dec_4);
  tcase_add_test(tc_core, sscanf_li_dec_5);
  tcase_add_test(tc_core, sscanf_li_dec_6);

  tcase_add_test(tc_core, sscanf_li_oct_1);
  tcase_add_test(tc_core, sscanf_li_oct_2);
  tcase_add_test(tc_core, sscanf_li_oct_3);
  tcase_add_test(tc_core, sscanf_li_oct_4);
  tcase_add_test(tc_core, sscanf_li_oct_5);
  tcase_add_test(tc_core, sscanf_li_oct_6);

  tcase_add_test(tc_core, sscanf_li_hex_1);
  tcase_add_test(tc_core, sscanf_li_hex_2);
  tcase_add_test(tc_core, sscanf_li_hex_5);
  tcase_add_test(tc_core, sscanf_li_hex_6);

  tcase_add_test(tc_core, sscanf_hd_9);
  tcase_add_test(tc_core, sscanf_hd_10);
  tcase_add_test(tc_core, sscanf_hd_11);
  tcase_add_test(tc_core, sscanf_hd_12);
  tcase_add_test(tc_core, sscanf_hd_13);
  tcase_add_test(tc_core, sscanf_hd_14);
  tcase_add_test(tc_core, sscanf_hd_15);
  tcase_add_test(tc_core, sscanf_hd_16);
  tcase_add_test(tc_core, sscanf_hd_17);
  tcase_add_test(tc_core, sscanf_hd_18);
  tcase_add_test(tc_core, sscanf_hd_19);
  tcase_add_test(tc_core, sscanf_hd_20);
  tcase_add_test(tc_core, sscanf_hd_21);
  tcase_add_test(tc_core, sscanf_hd_22);
  tcase_add_test(tc_core, sscanf_d_1);
  tcase_add_test(tc_core, sscanf_d_2);
  tcase_add_test(tc_core, sscanf_d_3);
  tcase_add_test(tc_core, sscanf_d_4);
  tcase_add_test(tc_core, sscanf_d_5);
  tcase_add_test(tc_core, sscanf_d_6);
  tcase_add_test(tc_core, sscanf_ld_17);
  tcase_add_test(tc_core, sscanf_ld_18);

  tcase_add_test(tc_core, sscanf_n_1);
  tcase_add_test(tc_core, sscanf_n_2);
  tcase_add_test(tc_core, sscanf_n_3);

  tcase_add_test(tc_core, sscanf_f_1);
  tcase_add_test(tc_core, sscanf_f_2);
  tcase_add_test(tc_core, sscanf_f_3);
  tcase_add_test(tc_core, sscanf_f_4);
  tcase_add_test(tc_core, sscanf_f_5);
  tcase_add_test(tc_core, sscanf_f_6);
  tcase_add_test(tc_core, sscanf_f_7);
  tcase_add_test(tc_core, sscanf_f_8);
  tcase_add_test(tc_core, sscanf_f_9);
  tcase_add_test(tc_core, sscanf_f_10);
  tcase_add_test(tc_core, sscanf_f_11);
  tcase_add_test(tc_core, sscanf_f_12);
  tcase_add_test(tc_core, sscanf_f_13);
  tcase_add_test(tc_core, sscanf_f_14);
  tcase_add_test(tc_core, sscanf_f_15);
  tcase_add_test(tc_core, sscanf_f_16);
  tcase_add_test(tc_core, sscanf_f_17);
  tcase_add_test(tc_core, sscanf_f_18);
  tcase_add_test(tc_core, sscanf_f_19);
  tcase_add_test(tc_core, sscanf_f_20);

  tcase_add_test(tc_core, sscanf_s_1);
  tcase_add_test(tc_core, sscanf_s_2);
  tcase_add_test(tc_core, sscanf_s_3);
  tcase_add_test(tc_core, sscanf_s_4);
  tcase_add_test(tc_core, sscanf_s_5);
  tcase_add_test(tc_core, sscanf_s_6);
  tcase_add_test(tc_core, sscanf_s_7);
  tcase_add_test(tc_core, sscanf_s_8);
  tcase_add_test(tc_core, test_parse_string);
  tcase_add_test(tc_core, sscanf_u_1);

  suite_add_tcase(s, tc_core);

  return s;
}
