/*
 * CS1010 Semester 1 AY24/25
 * Exercise 4: kendall
 *
 * @file: kendall.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

int main()
{
  size_t n = cs1010_read_size_t();

  long *order = cs1010_read_long_array(n);

  unsigned long paired_combi = (n * (n - 1)) / 2;

  long count = 0;
  for (unsigned long i = 0; i <= n; i += 1) // base ranking
  {
    for (unsigned long j = i + 1; j < n; j += 1) // index of order
    {
      if ((unsigned)order[i] > (unsigned)order[j]) {
        count += 1;
      }
    }
  }

  double tau = (double)count / (double)paired_combi;

  cs1010_println_double(tau);
}
