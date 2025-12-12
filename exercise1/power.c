/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: Power
 *
 * @file: power.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

long compute_power(long base, long pow)
{

  if (base == 0) {
    return 0;
  }

  if (pow == 0) {
    return 1;
  }

  return base * compute_power(base, pow - 1);
}

int main()
{

  long x = cs1010_read_long();
  long y = cs1010_read_long();

  cs1010_println_long(compute_power(x, y));
  return 0;
}
