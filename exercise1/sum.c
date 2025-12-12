/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: Sum
 *
 * @file: sum.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"
#include <stdbool.h>

long positive_num(long number)
{
  if (number <= 0) {
    return 0;
  }

  return number;
}

long compute_sum_if_positive(long x, long y)
{
  long summation;

  summation = positive_num(x) + positive_num(y);

  return summation;
}

int main()
{
  long x = cs1010_read_long();

  long y = cs1010_read_long();

  cs1010_println_long(compute_sum_if_positive(x, y));
}
