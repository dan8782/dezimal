#include "s21_decimal.h"

int addhelp(int a,int b);
int Bitwise_add(int a,int b);
int multiplyTwoNumbers(int a, int b);

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  // add_helper(value_1,value_2, result);
//   for (int i = 0; i < 3; i++) {
//     result->bits[i]= Bitwise_add(value_1.bits[i], value_2.bits[i]);
//   }

  printf("\n");
  result->bits[0] = multiplyTwoNumbers(1, 2147483646);
//   result->bits[1]= safe_shl(result->bits[1],1);
//   result->bits[1]= result->bits[1]<<1;
  return 0;
}

int Bitwise_add(int a, int b) {
    for (int i = 0; i < 96; i++) {
          int buffer = a & b;
          a = a ^ b;
          b = buffer << 1;
        }
        return a;
}

int add_helper(s21_decimal val_1, s21_decimal val_2, s21_decimal *result) {
  int temp_bit = result->bits[3];
  int buffer = 0;
  int bitVal_1 = 0;
  int bitVal_2 = 0;
  for (int i = 0; i < 96; i++) {
    bitVal_1 = get_bit(val_1, i);
    bitVal_2 = get_bit(val_2, i);
    set_bit(result, i, bitVal_1 ^ bitVal_2 ^ buffer);
    buffer =
        (bitVal_1 && bitVal_2) || (bitVal_1 && buffer) || (bitVal_2 && buffer);
  }
  result->bits[3] = temp_bit;
  printf("%d",buffer);
  return buffer;
}

int multiplyTwoNumbers(int a, int b) {
  int result = 0;
  for (int i = 0; i < 32; i++) {
    while (b > 0) {
      if (b & 1) {
        result += a;
      }
      a = a << 1;
      b = b >> 1;
    }
  }
  return result;
}

