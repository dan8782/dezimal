#include "s21_decimal.h"
// Проверка знака числа децимал
int get_sign(s21_decimal decl) { 
	return get_bit(decl, 127); 
}