/**
 * CS1010 Semester 1 AY24/25
 * Exercise 7: Walk
 *
 * @file: walk.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"
#include <math.h>

int main()
{
  // Using P&C, it is the permutation of the number of up and right movements
  // given, whilst dividing each by its factorial to account for repetition
  long x = cs1010_read_long();

  long y = cs1010_read_long();

  long sum = x + y;

  double counter = 1.0;
  while (y > 0) {
    counter *= (double)sum / (double)y;
    sum -= 1;
    y -= 1;
  }

  cs1010_println_long((long)(round(counter)));

  return 0;
}
