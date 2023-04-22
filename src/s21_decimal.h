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
  unsigned int bits[4];
  char status;
} s21_decimal;

typedef struct {
  unsigned int bits[6];
  int exp;
  int sign;
} big_decimal;

typedef union {
  float f;
  struct {
    unsigned int mantisa : 23;
    unsigned int exponent : 8;
    unsigned int sign : 1;
  } parts;
} float_cast;

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
int s21_is_not_equal(s21_decimal x, s21_decimal y);

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);
int s21_floor(s21_decimal dec, s21_decimal *res);
int s21_round(s21_decimal dec, s21_decimal *res);

void copy_decimal(s21_decimal *decimal, s21_decimal origdec);

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

s21_decimal *set_bit(s21_decimal *decimal, int index, bool sign);
s21_decimal *unset_bit(s21_decimal *decimal, int index);
s21_decimal *switch_bit(s21_decimal *decimal, int index);

int left_shift(s21_decimal *decimal);
int right_shift(s21_decimal *decimal);
int sub_bitwise(s21_decimal x, s21_decimal y, s21_decimal *res);
int add_bitwise(s21_decimal value_a, s21_decimal value_b, s21_decimal *result);
int div_int_bitwise(s21_decimal x, s21_decimal y, s21_decimal *res);
int mod_bitwise(s21_decimal x, s21_decimal y, s21_decimal *mod);
s21_decimal pow_10_decimal(int n);
s21_decimal mul_by_10(s21_decimal *dec);
int is_zero(s21_decimal *val);
int is_bitwise_equal(s21_decimal *x, s21_decimal *y);
int is_bitwise_less(s21_decimal *a, s21_decimal *b);
int is_bitwise_grater(s21_decimal *a, s21_decimal *b);
int is_bitwise_less_or_equal(s21_decimal *a, s21_decimal *b);

// BIG DECIMAL:

big_decimal init();
void set_zero_big(big_decimal *big_dec);
big_decimal dec_to_big(s21_decimal dec);

int get_bit_big(big_decimal *decimal, int index);
big_decimal *set_bit_big(big_decimal *decimal, int index, bool sign);
void print_big_mantissa(big_decimal *dec);

int left_shift_big(big_decimal *decimal_big);
int is_zero_big(big_decimal *val);
void init_small(s21_decimal *num);
void copy_decimal_big(big_decimal *decimal, big_decimal origdec);
int add_bitwise_big(big_decimal x, big_decimal y, big_decimal *res);
big_decimal *mul_by_10_big(big_decimal *dec);
int normalize_big(big_decimal *big_1, big_decimal *big_2);
int big_to_dec(big_decimal big_dec, s21_decimal *s21_dec);
big_decimal dec_to_big(s21_decimal dec);
int is_too_large(big_decimal *big_dec);
int is_bitwise_equal_big(big_decimal *x, big_decimal *y);
int is_bitwise_grater_big(big_decimal *a, big_decimal *b);
int is_bitwise_less_or_equal_big(big_decimal *a, big_decimal *b);
int is_bitwise_less_big(big_decimal *a, big_decimal *b);
int sub_bitwise_big(big_decimal x, big_decimal y, big_decimal *res);
int mod_bitwise_big(big_decimal x, big_decimal y, big_decimal *mod);
big_decimal pow_10_decimal_big(int n);
int div_int_bitwise_big(big_decimal x, big_decimal y, big_decimal *res);
s21_decimal div_int_test(s21_decimal dividend, s21_decimal divisor,
                         s21_decimal *result);

int banking_rounding(big_decimal *big_dec, big_decimal last_diget);
