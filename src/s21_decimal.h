#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int bits[4];
} s21_decimal;

void print_dec(s21_decimal decl);
void s21_copy(s21_decimal *decimal, s21_decimal origdec);
void set_sign(s21_decimal *decl, bool sign);
int get_bit(s21_decimal decimal, int index);
int get_sign(s21_decimal decl);
int s21_negate(s21_decimal value, s21_decimal *result);
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
s21_decimal *set_bit(s21_decimal *decimal, int index, bool sign);
s21_decimal *unset_bit(s21_decimal *decimal, int index);
s21_decimal *switch_bit(s21_decimal *decimal, int index);
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_is_less(s21_decimal x, s21_decimal y);
int s21_is_equal(s21_decimal x, s21_decimal y);
int get_exp(s21_decimal x);
int is_mantissa_less(s21_decimal x, s21_decimal y, int sign);
int s21_is_greater(s21_decimal x, s21_decimal y);
int s21_is_greater_or_equal(s21_decimal x, s21_decimal y);
int s21_is_less_or_equal(s21_decimal x, s21_decimal y);
void test(s21_decimal x, s21_decimal y);
void set_exp(s21_decimal *decimal, int exp);
int left_shift(s21_decimal *decimal);

#define SIGN_BIT 127
#define START_EXP_BIT 112
#define LAST_EXP_BIT 119
#define LAST_MANTISSA_BIT 95