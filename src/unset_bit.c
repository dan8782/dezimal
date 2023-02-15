#include "s21_decimal.h"

s21_decimal *unset_bit(s21_decimal *decimal, int index) {
    decimal->bits[index/32] &= ~(1 << (index %32));
	return decimal;
}
