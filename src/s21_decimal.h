#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

typedef struct 
{
    int bits[4];
} s21_decimal;

void print_dec(s21_decimal decl);
void s21_copy(s21_decimal *decimal, s21_decimal origdec);
void set_sign(s21_decimal *decl, bool sign);
int get_bit(s21_decimal decimal, int index);
int get_sign(s21_decimal decl);
int s21_negate(s21_decimal value, s21_decimal *result);
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
s21_decimal *set_bit(s21_decimal *decimal, int index,bool sign);
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
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
void test(s21_decimal x, s21_decimal y);
void set_exp(s21_decimal *decimal,int exp);
int add_helper(s21_decimal val_1, s21_decimal val_2, s21_decimal *result);

#define SIGN_BIT 127
#define START_EXP_BIT 112
#define LAST_EXP_BIT 119
#define LAST_MANTISSA_BIT 95