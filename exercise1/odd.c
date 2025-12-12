/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: Odd
 *
 * @file: odd.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

long find_next_odd(long next_odd)
{
  if (next_odd % 2 == 1 || next_odd % 2 == -1) {
    next_odd += 2;
  } else {
    next_odd += 1;
  }

  return next_odd;
}

int main()
{
  long next_odd = cs1010_read_long();

  // test for odd
  cs1010_println_long(find_next_odd(next_odd));
}
