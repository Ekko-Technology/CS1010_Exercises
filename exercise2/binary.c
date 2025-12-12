/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: Binary
 *
 * @file: binary.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

long pow(long base, long power)
{
  long result = 1;
  if (power == 0) {
    return 1;
  }

  for (long i = 0; i < power; i += 1) {
    result *= base;
  }

  return result;
}

long find_decimal(long binary_value)
{
  long sum = 0;
  long count = 0;
  while (binary_value > 0) {
    if (binary_value % 10 == 1) {
      sum += pow(2, count);
      // cs1010_println_long(sum);
    }

    binary_value /= 10;
    count += 1;
  }

  return sum;
}

int main()
{
  long input = cs1010_read_long();
  long result = find_decimal(input);
  // cs1010_print_string("the decimal number is:");
  cs1010_println_long(result);
}
