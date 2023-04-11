// #include "s21_decimal.h"

// int main(int argc, char const *argv[]) {
//   //   printf("START...\n");
//   //   s21_decimal val1 = {-1, -1, -1, 0};  //7922816251426433759354395033(5)
//   s21_decimal val1 = {0x00000019, 0x00000000, 0x00000000, 0x00010000};
//   //   set_exp(&val1, 0);
//   //   set_sign(&val1, 0);
//   //   // print_dec(&val1);
//   //   s21_decimal val2 = {6, 0, 0, 0};  // 0.5
//   s21_decimal val2 = {0x00000064, 0x00000000, 0x00000000, 0x00000000};
//   //   set_exp(&val2, 1);
//   //   set_sign(&val2, 0);
//   s21_decimal result = {0};

//   int err = s21_add(val1, val2, &result);
//   printf("ERROR: %d\n", err);
//   print_dec(&result);
//   printf("%u", result.bits[3]);
//   return 0;
// }