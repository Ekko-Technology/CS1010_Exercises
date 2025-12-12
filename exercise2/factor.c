/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: Factor
 *
 * @file: factor.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

long factor(long input)
{
  if (input <= 1) {
    return 0;
  }

  long count = 0;

  for (long i = 2; i < input; i += 1) {
    if (input % i == 0) {
      count += 1;
    }
  }

  return count;
}

int main()
{
  long input = cs1010_read_long();

  long value = factor(input);

  cs1010_println_long(value);
}
