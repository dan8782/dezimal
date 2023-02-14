#include "s21_decimal.h"

int main(int argc, char const *argv[])
{ 
	 s21_decimal decimal;
   int a = s21_from_int_to_decimal(10, &decimal);
	 print_dec(decimal);
	printf("\n");
    return 0;

}