#include "s21_decimal.h"

int main(int argc, char const *argv[])
{
	s21_decimal decimal1 = {1,0,0,0};
	s21_decimal decimal2= {1,0,0,0};
	s21_decimal result={0,0,0,0};
	// s21_from_int_to_decimal(64,&decimal);
	// s21_add(decimal1,decimal2, &result);
	set_exp(&decimal1,4);
	printf("%d",get_exp(decimal1));
	return 0;

}