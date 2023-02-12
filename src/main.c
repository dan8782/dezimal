#include <stdlib.h>
#include <stdio.h>

typedef struct 
{
    int bits[4];
} s21_decimal;

void print_dec(s21_decimal decl);
int get_bit(s21_decimal decimal, int index);
int get_sign(s21_decimal decl);
s21_decimal *set_bit(s21_decimal *decimal, int index);
s21_decimal *unset_bit(s21_decimal *decimal, int index);

int main(int argc, char const *argv[])
{
	s21_decimal decimal = {0,8,16,32};
	set_bit(&decimal, 127);
	unset_bit(&decimal, 127);
	printf("%d\n",get_sign(decimal));
	print_dec(decimal);
	return 0;
}

int get_bit(s21_decimal decimal, int index){
	return (decimal.bits[index/32] & (1 << (index%32)))!=0;
}

s21_decimal *unset_bit(s21_decimal *decimal, int index) {
    decimal->bits[index/32] &= ~(1 << (index %32));
	return decimal;
}

s21_decimal *set_bit(s21_decimal *decimal, int index){
	decimal->bits[index/32] |= (1 << (index%32));	
	return decimal;
}

void print_dec(s21_decimal decl) {
  for (int i = 127; i >= 0; i--) {
    printf("%d", get_bit(decl, i));
    if (i % 32 == 0) {
      printf(" ");
    }
  }
  printf("\n");
}

int get_sign(s21_decimal decl) { 
	return get_bit(decl, 127); 
}

