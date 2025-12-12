/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: Multiple
 *
 * @file: multiple.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"
#include <stdbool.h>

bool is_multiple(long num1, long num2)
{
  if (num1 == 0 || num2 == 0) {
    return true;
  }

  long big_num, small_num;

  if (num1 > num2) {
    big_num = num1;
    small_num = num2;
  } else {
    big_num = num2;
    small_num = num1;
  }

  if (big_num % small_num == 0) {
    return true;
  }
  return false;
}

int main()
{
  long x = cs1010_read_long();
  long y = cs1010_read_long();

  if (is_multiple(x, y)) {
    cs1010_println_string("true");
  } else {
    cs1010_println_string("false");
  }
  return 0;
}
