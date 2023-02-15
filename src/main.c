#include <stdlib.h>
#include <stdio.h>
#include <math.h>   // pow(2,exp)


#define SIGN_BIT 127
#define START_EXP_BIT 112
#define LAST_EXP_BIT 119
#define LAST_MANTISSA_BIT 95


typedef struct 
{
    int bits[4];
} s21_decimal;


void print_dec(s21_decimal decl);
s21_decimal *set_bit(s21_decimal *decimal, int index);
int s21_is_less(s21_decimal x, s21_decimal y);
int s21_is_equal(s21_decimal x, s21_decimal y);
int get_exp(s21_decimal x);
int is_mantissa_less(s21_decimal x, s21_decimal y, int sign);
int s21_is_greater(s21_decimal x, s21_decimal y);
int s21_is_greater_or_equal(s21_decimal x, s21_decimal y);
int s21_is_less_or_equal(s21_decimal x, s21_decimal y);
void test(s21_decimal x, s21_decimal y);


int main(int argc, char const *argv[])
{
  // s21_decimal a = 15.1567
  // get_decimal(a) = {0,8,16,32}
	s21_decimal x_1 = {1, 0, 0, 0}; //2147483650}; // negavite {1, 0, 0, 2147483650};
  s21_decimal y_1 = {1, 0, 0, 0}; // 2147483650}; // negative {1, 0, 0, 2147483649};

  s21_decimal x_2 = {1, 0, 0, 2147483650}; 
  s21_decimal y_2 = {1, 0, 0, 2147483650};

  s21_decimal x_3 = {10, 0, 0, 0}; 
  s21_decimal y_3 = {1, 0, 0, 0};
  
  s21_decimal x_4 = {1, 0, 0, 2147483650}; 
  s21_decimal y_4 = {10, 0, 0, 2147483650};

  s21_decimal x_5 = {1, 0, 0, 0}; 
  s21_decimal y_5 = {10, 0, 0, 0};

  s21_decimal x_6 = {1, 0, 0, 0}; 
  s21_decimal y_6 = {10, 0, 0, 2147483650};

  s21_decimal x_7 = {1, 0, 0, 2147483650}; 
  s21_decimal y_7 = {10, 0, 0, 0};

	//set_bit(&decimal, 4);
  printf("\n\nEqual positive\n");
  test(x_1, y_1);

  printf("\n\nEqual negative\n");
  test(x_2, y_2);

  printf("\n\n X>Y positive\n");
  test(x_3, y_3);
  
  printf("\n\nX>Y negative\n");
  test(x_4, y_4);

  printf("\n\nX<Y positive\n");
  test(x_5, y_5);

  printf("\n\n X positive Y negative\n");
  test(x_6, y_6);

  printf("\n\n X negative Y positive\n");
  test(x_7, y_7);

  // printf("Equal positive");
  // test(x_1, y_1);

  // printf("Equal positive");
  // test(x_1, y_1);
  return 0;
}

// 1100
// 0100
//  1

void test(s21_decimal decimal_1, s21_decimal decimal_2){
  printf("is_less %d\n", s21_is_less(decimal_1, decimal_2)); 
  printf("is_equal %d\n", s21_is_equal(decimal_1, decimal_2));
  printf("is_greater %d\n", s21_is_greater(decimal_1, decimal_2));
  printf("is_less_or_equal %d\n", s21_is_less_or_equal(decimal_1, decimal_2));
  printf("is_greater_or_equal %d\n", s21_is_greater_or_equal(decimal_1, decimal_2));

  //printf("get_exp %d\n", get_exp_result);
   print_dec(decimal_1);
   print_dec(decimal_2);
}

int get_bit(s21_decimal decimal, int index){  // index 65  // << смещение на 1 в массиве 
	return (decimal.bits[index/32] & (1 << (index%32)))!=0; // (bits[2] & (1 << (1)))  << - сдвиг на N  (0-3 & ())
}

s21_decimal *set_bit(s21_decimal *decimal, int index){
	decimal->bits[index/32] |= (1 << (index%32));	  //* указатель 
	return decimal;
}

void print_dec(s21_decimal decl) {
  for (int i = 127; i >= 0; i--) {
    printf("%d", get_bit(decl, i));
    if (i % 32 == 0 || i == START_EXP_BIT || i == LAST_EXP_BIT+1) {
      printf(" ");
    }
  }
  printf("\n");
}


// Сравнение X < Y
int s21_is_less(s21_decimal x, s21_decimal y) {
  int result = 0;   // 0 - FALSE, 1 - TRUE
  
  // Проверка по знаку
  int sign_x = get_bit(x, SIGN_BIT);
  int sign_y = get_bit(y, SIGN_BIT);
  //printf("sign_x=%d, sign_y=%d\n", sign_x, sign_y);
  // exp = 1 - отрицательное число
  
  if (sign_x > sign_y) {
    result = 1;
  } else if (sign_x < sign_y) {
    result = 0;
  } else if (sign_x == sign_y) {
    result = 11;     // если оба + или - далее обрабатывается
  } 

  // Проверка по степени
  int exp_x = get_exp(x);
  int exp_y = get_exp(y);
  // printf("exp_x=%d, exp_y=%d\n", exp_x, exp_y);
  if ((result == 11) && (exp_x == exp_y)) { //если степени равны, то сравниваем мантиссу
    result = 111;
  } else if (result == 11 && exp_x < exp_y) {
    result = 0;
  } else if (result == 11 && exp_x > exp_y) {
    result = 1;
  } else if (result == 99 && exp_x > exp_y) {
    result = 0;
  } else if (result == 99 && exp_x < exp_y) {
    result = 1;
  }
  
  // Проверка по мантиссе 
  if (result == 111) {
    result = is_mantissa_less(x, y, sign_x);  // Вернет 1, если  x < y, иначе 0 
                                      //передаем только знак х, т.к. с у они равны
  }

  return result;
}

// Получаем степень  112 - старший бит, 119 - младший
int get_exp(s21_decimal x) {
  int exp = 0;
  for (int i = LAST_EXP_BIT; i >= START_EXP_BIT; i--) {
    exp += get_bit(x, i) * pow(2, LAST_EXP_BIT-i);
   // printf("i = %d, exp_2 = %d\n", i, LAST_EXP_BIT-i);
  }
  return exp;
}

// Сравниваем побитово мантиссу
int is_mantissa_less(s21_decimal x, s21_decimal y, int sign) {
  int i = LAST_MANTISSA_BIT;
  while (i >= 0) {
    int x_bit = get_bit(x, i);
    int y_bit = get_bit(y, i);
    if (x_bit > y_bit) {
      return (sign == 0) ? 0 : 1;
    } else if(x_bit < y_bit) {
      return (sign == 0) ? 1 : 0;
    }
    i--;
  }
  return 0;
}

// Сравнение X == Y
int s21_is_equal(s21_decimal x, s21_decimal y) {
  for (int i = 0; i < 4; i++) {
    if (x.bits[i] != y.bits[i]) {
      return 0;
    }
  }
  return 1;
}

int s21_is_greater(s21_decimal x, s21_decimal y) {
  return (!s21_is_equal(x, y) && !(s21_is_less(x, y)));

}

int s21_is_less_or_equal(s21_decimal x, s21_decimal y) {
  return !s21_is_greater(x, y);
}

int s21_is_greater_or_equal(s21_decimal x, s21_decimal y) {
  return !s21_is_less(x,y);
}
