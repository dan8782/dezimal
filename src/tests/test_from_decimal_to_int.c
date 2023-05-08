#include "./test_main.h"

static s21_decimal src[] = {
    {{0x00000001, 0x00000000, 0x00000000, 0x00000000}},  // 1
    {{0x0000006E, 0x00000000, 0x00000000, 0x00020000}},  // 1.10
    {{0x00000457, 0x00000000, 0x00000000, 0x00030000}},  // 1.111
    {{0x773593FF, 0x00000000, 0x00000000, 0x00090000}},  // 1.999999999
    {{0x0000007B, 0x00000000, 0x00000000, 0x00000000}},  // 123
    {{0x0001E078, 0x00000000, 0x00000000, 0x00030000}},  // 123.000
    {{0x0001E45F, 0x00000000, 0x00000000, 0x00030000}},  // 123.999
    {{0xFFFFFFFF, 0x000003E7, 0x00000000, 0x00030000}},  // 4294967295.999
    {{0x00000000, 0x00000001, 0x00000000, 0x00000000}},  // 4294967296
    {{0x00000000, 0x00000001, 0x00000000, 0x80000000}},  // -4294967296
    {{0xFFFFFFFF, 0x000001F3, 0x00000000, 0x00030000}},  // 2147483647.999
    {{0x80000000, 0x00000000, 0x00000000, 0x00000000}},  // 2147483648
    {{0x000003E7, 0x00000000, 0x00000000, 0x80030000}},  // -0.999
    {{0x00000001, 0x00000000, 0x00000000, 0x80000000}},  // -1
    {{0x000003E7, 0x000001F4, 0x00000000, 0x80030000}},  // -2147483648.999
    {{0x80000000, 0x00000000, 0x00000000, 0x80000000}},  // -2147483648
    // {{0x80000001, 0x00000000, 0x00000000, 0x80000000}},  // -2147483649
    // {{0x000F4240, 0x00002710, 0x00002710,
    //   0x00000000}},  // 184467440780045190120000
    // {{0x000F4240, 0x00002710, 0x00002710,
    //   0x80000000}},  // -184467440780045190120000
    // {{0x000F4240, 0x00000000, 0x00002710,
    //   0x00000000}},  // 184467440737095517160000
    // {{0x000F4240, 0x00000000, 0x00002710,
    //   0x80000000}},  // -184467440737095517160000
    // {{0x00002F59, 0x0CA55839, 0x00000000, 0x00000000}},  // 911231501448785753
    // {{0x000004C2, 0x01518D64, 0x00000000, 0x80000000}},  // -95012527787738306
    {{0x00000000, 0x00000000, 0x00000000, 0x80000000}},  // 0
    {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  // 0
    {{0x00000097, 0x00000000, 0x00000000, 0x00010000}},  // 15.1
    {{0x0000060D, 0x00000000, 0x00000000, 0x00020000}},  // 15.49
    {{0x0000060F, 0x00000000, 0x00000000, 0x00020000}},  // 15.51
    {{0x00000097, 0x00000000, 0x00000000, 0x80010000}},  // -15.1
    {{0x0000060D, 0x00000000, 0x00000000, 0x80020000}},  // -15.49
    {{0x0000060F, 0x00000000, 0x00000000, 0x80020000}},  // -15.51
    {{0x00000619, 0x00000000, 0x00000000, 0x00010000}},  // 156.1
    {{0x00003D21, 0x00000000, 0x00000000, 0x00020000}},  // 156.49
    {{0x00003D23, 0x00000000, 0x00000000, 0x00020000}},  // 156.51
    {{0x00000619, 0x00000000, 0x00000000, 0x80010000}},  // -156.1
    {{0x00003D21, 0x00000000, 0x00000000, 0x80020000}},  // -156.49
    {{0x00003D23, 0x00000000, 0x00000000, 0x80020000}},  // -156.51
};

static int dst[] = {
    1, 1, 1, 1, 123, 123, 123, 0, 0,
    -1,  -2147483648, -2147483648, -1, 0, 15, 15, 15, -15,
    -15, -15, 156, 156, 156, -156, -156, -156
};

START_TEST(test) {
  for (size_t i = 0, j = 0; i < sizeof(src) / sizeof(s21_decimal); ++i) {
    int tmp;
    printf("i = %zu\n", i);
    int ret = s21_from_decimal_to_int(src[i], &tmp);
    if (ret == 0) {
      ck_assert_int_eq(tmp, dst[j]);
      ++j;
    } else {
      ck_assert_int_eq(ret, 1);
    }
  }
}
END_TEST

START_TEST(error_test) {
  s21_decimal a = {{10, 13, 827, 30 << 16}};
  int tmp;
  int ret = s21_from_decimal_to_int(a, &tmp);
  ck_assert_int_eq(ret, 1);
}
END_TEST

Suite *suite_from_decimal_to_int(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_from_decimal_to_int");
  tc = tcase_create("s21_from_decimal_to_int");

  if (s != NULL && tc != NULL) {
    tcase_add_test(tc, test);
    tcase_add_test(tc, error_test);
    suite_add_tcase(s, tc);
  }

  return (s);
}