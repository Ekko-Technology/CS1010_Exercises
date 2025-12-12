/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: Fibonacci
 *
 * @file: fibonacci.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

long fibonacci(long n_index)
{
  long index1 = 1;
  long index2 = 1;
  long next_num;

  if (n_index <= 0) {
    cs1010_println_string("invalid input...returning 0");
    return 0;
  }

  if (n_index <= 2) {
    return 1;
  }

  for (long i = n_index - 2; i > 0; i -= 1) {
    next_num = index1 + index2;
    index1 = index2;
    index2 = next_num;
  }

  return next_num;
}

int main()
{
  long input = cs1010_read_long();

  long result = fibonacci(input);

  cs1010_println_long(result);

  return 0;
}
