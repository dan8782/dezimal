#include "s21_decimal.h"


int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result){
	*result = value_2;
	return 0;
}

void set_exp(s21_decimal *decimal,int exp){
	for (int i = 112; i < 120; i++)
	{
		set_bit(decimal, i, exp & 1);
		exp >>= 1;
	}
}