/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: Prime
 *
 * @file: prime.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"
#include <math.h>
#include <stdbool.h>

bool is_prime(long value)
{
  if (value < 2) {
    return false;
  }

  if (value == 2 || value == 3) {
    return true;
  }

  if (value % 2 == 0 || value % 3 == 0) {
    return false;
  }

  long start = 5;
  long step = 6;
  long limit = (long)sqrt((double)value);

  for (long i = start; i <= limit; i += step) {
    if (value % i == 0 || value % (i + 2) == 0) {
      return false;
    }
  }
  return true;
}

int main()
{
  long value = cs1010_read_long();

  while (!is_prime(value)) {
    value -= 1;
  }

  cs1010_println_long(value);
}
