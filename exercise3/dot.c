/**
 * CS1010 Semester 1 AY24/25
 * Exercise 3: Dot
 *
 * @file: dot.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

long result(long a[], long b[])
{
  long result = 0;
  for (long i = 0; i < 4; i += 1) {
    result += (a[i] * b[i]);
  }
  return result;
}

int main()
{
  long a[4] = {0};
  long b[4] = {0};
  for (long i = 0; i < 4; i += 1) {
    a[i] = cs1010_read_long();
  }
  for (long j = 0; j < 4; j += 1) {
    b[j] = cs1010_read_long();
  }

  cs1010_println_long(result(a, b));
}
