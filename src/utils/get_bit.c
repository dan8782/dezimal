#include "../s21_decimal.h"

// Возвращает значение указанного бита

int get_bit(s21_decimal decimal, int index) {
  return (decimal.bits[index / 32] & (1 << (index % 32))) != 0;
}