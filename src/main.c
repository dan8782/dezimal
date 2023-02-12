#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

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

int main(int argc, char const *argv[])
{
	s21_decimal decimal = {0,8,16,32};
	s21_decimal newdec;
	// s21_copy(&newdec,decimal);
	// set_bit(&decimal, 127,1);
	print_dec(decimal);
	printf("\n");
	s21_negate(decimal,&newdec);
	// unset_bit(&decimal, 127);
	// printf("%d\n",get_sign(decimal));
	print_dec(newdec);
	return 0;
}

int get_bit(s21_decimal decimal, int index){
	return (decimal.bits[index/32] & (1 << (index%32)))!=0;
}

s21_decimal *unset_bit(s21_decimal *decimal, int index) {
    decimal->bits[index/32] &= ~(1 << (index %32));
	return decimal;
}

s21_decimal *set_bit(s21_decimal *decimal, int index, bool sign){
	decimal->bits[index/32] |= (sign << (index%32));	
	return decimal;
}

s21_decimal *switch_bit(s21_decimal *decimal, int index){
	decimal->bits[index/32] ^= (1 << (index%32)); //тут XOR 
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


void s21_copy(s21_decimal *decimal, s21_decimal origdec) {
  for (int i = 0; i < 4; ++i) {
    decimal->bits[i] = origdec.bits[i];
  }
}

int s21_negate(s21_decimal value, s21_decimal *result) {

    s21_copy(result, value);
	switch_bit(result,127);

    return 0;
}

void set_sign(s21_decimal *decl, bool sign) {
  set_bit(decl, 127, sign);
}

int get_sign(s21_decimal decl) { 
	return get_bit(decl, 127); 
}