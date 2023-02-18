// #include "../s21_decimal.h"

// int main(int argc, char const *argv[])
// {

//   s21_decimal x_1 = {1, 0, 0, 0}; //2147483650}; // negavite {1, 0, 0, 2147483650};
//   s21_decimal y_1 = {1, 0, 0, 0}; // 2147483650}; // negative {1, 0, 0, 2147483649};

//   s21_decimal x_2 = {1, 0, 0, 214748364}; 
//   s21_decimal y_2 = {1, 0, 0, 214748365};

// //   s21_decimal x_3 = {10, 0, 0, 0}; 
// //   s21_decimal y_3 = {1, 0, 0, 0};
  
// //   s21_decimal x_4 = {1, 0, 0, 2147483650}; 
// //   s21_decimal y_4 = {10, 0, 0, 2147483650};

// //   s21_decimal x_5 = {1, 0, 0, 0}; 
// //   s21_decimal y_5 = {10, 0, 0, 0};

// //   s21_decimal x_6 = {1, 0, 0, 0}; 
// //   s21_decimal y_6 = {10, 0, 0, 2147483650};

// //   s21_decimal x_7 = {1, 0, 0, 2147483650}; 
// //   s21_decimal y_7 = {10, 0, 0, 0};

//   printf("\n\nEqual positive\n");
//   test(x_1, y_1);

//   printf("\n\nEqual negative\n");
//   test(x_2, y_2);

// //   printf("\n\n X>Y positive\n");
// //   test(x_3, y_3);
  
// //   printf("\n\nX>Y negative\n");
// //   test(x_4, y_4);

// //   printf("\n\nX<Y positive\n");
// //   test(x_5, y_5);

// //   printf("\n\n X positive Y negative\n");
// //   test(x_6, y_6);

// //   printf("\n\n X negative Y positive\n");
// //   test(x_7, y_7);

//   // printf("Equal positive");
//   // test(x_1, y_1);

//   // printf("Equal positive");
//   // test(x_1, y_1);
//   return 0;
// }

// void test(s21_decimal decimal_1, s21_decimal decimal_2){
//   printf("is_less %d\n", s21_is_less(decimal_1, decimal_2)); 
//   printf("is_equal %d\n", s21_is_equal(decimal_1, decimal_2));
//   printf("is_greater %d\n", s21_is_greater(decimal_1, decimal_2));
//   printf("is_less_or_equal %d\n", s21_is_less_or_equal(decimal_1, decimal_2));
//   printf("is_greater_or_equal %d\n", s21_is_greater_or_equal(decimal_1, decimal_2));

//   //printf("get_exp %d\n", get_exp_result);
//    print_dec(decimal_1);
//    print_dec(decimal_2);
// }