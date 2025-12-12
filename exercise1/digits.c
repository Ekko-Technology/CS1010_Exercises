/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: Digits
 *
 * @file: digits.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"
#include <stdio.h>

long sum_of_digits_cubed(long remainder)
{
  if (remainder == 0) {
    return 0;
  }

  long digit = remainder % 10;

  long sum = (digit * digit * digit);

  remainder /= 10;

  return sum + sum_of_digits_cubed(remainder);
}

int main()
{
  long input = cs1010_read_long();

  cs1010_println_long(sum_of_digits_cubed(input));

  return 0;
}
