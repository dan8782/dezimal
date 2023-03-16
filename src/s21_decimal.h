#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOW_BIT 0
#define MID_BIT 32
#define HIGH_BIT 64
#define LAST_BIT 96
#define SIGN_BIT 127
#define START_EXP_BIT 112
#define LAST_EXP_BIT 119
#define LAST_MANTISSA_BIT 95

static char *StatusName[] = {
    "OK", "the number is too large or equal to infinity",
    "the number is too small or equal to negative infinity", "division by 0"};

typedef enum enumDiv_status {
  OK,
  PLUS_INFINITY,
  MINUS_INFINITY,
  DIVISION_BY_ZERO
} Div_status;

typedef struct {
  int bits[4];
  char status;
} s21_decimal;

void print_dec(s21_decimal *dec);
int get_bit(s21_decimal decimal, int index);
int get_sign(s21_decimal *decl);
int get_exp(s21_decimal *x);
void set_exp(s21_decimal *decimal, int exp);
void set_zero(s21_decimal *x);
void set_exp(s21_decimal *decimal, int exp);
void set_sign(s21_decimal *decl, bool sign);

int is_mantissa_less(s21_decimal x, s21_decimal y, int sign);
int s21_is_greater(s21_decimal x, s21_decimal y);
int s21_is_greater_or_equal(s21_decimal x, s21_decimal y);
int s21_is_less_or_equal(s21_decimal x, s21_decimal y);
int s21_is_less(s21_decimal x, s21_decimal y);
int s21_is_equal(s21_decimal x, s21_decimal y);

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

int s21_truncate(s21_decimal val, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

void copy_decimal(s21_decimal *decimal, s21_decimal origdec);

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

s21_decimal *set_bit(s21_decimal *decimal, int index, bool sign);
s21_decimal *unset_bit(s21_decimal *decimal, int index);
s21_decimal *switch_bit(s21_decimal *decimal, int index);

int left_shift(s21_decimal *decimal);
int sub_bitwise(s21_decimal x, s21_decimal y, s21_decimal *res);
int add_bitwise(s21_decimal value_a, s21_decimal value_b, s21_decimal *result);
int div_int_bitwise(s21_decimal x, s21_decimal y, s21_decimal *res);
int is_zero(s21_decimal *val);
int is_bitwise_less(s21_decimal *a, s21_decimal *b);