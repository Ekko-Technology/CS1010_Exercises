/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: Nine
 *
 * @file: nine.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

long find_least_significant_9(long value)
{
  long index = 1;
  while (value > 1) {
    long last_digit = value % 10;

    if (last_digit == 9) {
      return index;
    }

    value /= 10;
    index += 1;
  }

  return 0;
}

int main()
{
  long value = cs1010_read_long();

  long result = find_least_significant_9(value);

  cs1010_println_long(result);
}
