#include "s21_decimal.h"

int addhelp(int a, int b);
int Bitwise_add(s21_decimal value_a, s21_decimal value_b, s21_decimal *result);
int multiplyTwoNumbers(int a, int b);

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  // add_helper(value_1,value_2, result);
  //   for (int i = 0; i < 3; i++) {
  //     result->bits[i]= Bitwise_add(value_1.bits[i], value_2.bits[i]);
  //   }

  printf("\n");
  // result->bits[0] = multiplyTwoNumbers(1, 2147483647);
  Bitwise_add(value_1, value_2, result);
  //   result->bits[1]= safe_shl(result->bits[1],1);
  //   result->bits[1]= result->bits[1]<<1;
  return 0;
}

// int Bitwise_add(s21_decimal value_a, s21_decimal value_b, s21_decimal
// *result) {
//   int temp_bit = result->bits[3];
//   int buffer = 0;
//   int bit_a = 0;
//   int bit_b = 0;
//   s21_decimal bufferd;
//   s21_is_null(&bufferd);
//   for (int i = 0; i < 96; i++) {
//     bit_a = get_bit(value_a, i);
//     bit_b = get_bit(value_b, i);
//     buffer = bit_a & bit_b;
//     set_bit(&bufferd, i, bit_a & bit_b);
//     set_bit(result, i, bit_a ^ bit_b);
//     if (buffer != 0) {
//       left_shift(&bufferd);
//       value_b=bufferd;
//     }
//   }
//   return buffer;
// }

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
  printf("%d", buffer);
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
