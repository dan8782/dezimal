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
s21_decimal *set_bit(s21_decimal *decimal, int index,bool sign);
s21_decimal *unset_bit(s21_decimal *decimal, int index);
s21_decimal *switch_bit(s21_decimal *decimal, int index);
int s21_from_int_to_decimal(int src, s21_decimal *dst);