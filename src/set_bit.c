#include "s21_decimal.h"


s21_decimal *set_bit(s21_decimal *decimal, int index, bool sign){
	decimal->bits[index/32] |= (sign << (index%32));	
	return decimal;
}