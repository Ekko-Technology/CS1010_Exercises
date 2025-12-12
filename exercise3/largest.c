/**
 * CS1010 Semester 1 AY24/25
 * Exercise 3: Largest
 *
 * @file: largest.c
 * @author: Joshua Yeo (Group B03)
 */

#include "cs1010.h"

long find_largest(long n)
{
  long count[10] = {0};

  bool positive = true;
  if (n < 0) {
    positive = false;
    n -= (2 * n);
  }

  while (n != 0) {
    count[n % 10] += 1;
    n /= 10;
  }
  // cs1010_println_long(count[2]);

  // assert that n = 0
  // checks if input was a positive
  if (positive) {
    for (long i = 9; i >= 0; i -= 1) {
      while (count[i] > 0) {
        n = n * 10 + i;
        count[i] -= 1;
        // cs1010_println_long(n);
      }
    }
  }
  // counts for negative values
  else {
    for (long i = 1; i < 10; i += 1) {
      while (count[i] > 0) {
        n = n * 10 - i;
        count[i] -= 1;
      }
    }
  }
  return n;
}
