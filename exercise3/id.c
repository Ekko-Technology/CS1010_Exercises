/**
 * CS1010 Semester 1 AY24/25
 * Exercise 3: ID
 *
 * @file: id.c
 * @author: Joshua Yeo (Group YYY)
 */
#include "cs1010.h"

int main()
{
  long value = cs1010_read_long();

  long sum = 0;

  while (value > 0) {
    sum += value % 10;
    value /= 10;
  }

  long remainder = sum % 13;

  char table[13] = {'Y', 'X', 'W', 'U', 'R', 'N', 'M',
                    'L', 'J', 'H', 'E', 'A', 'B'};

  putchar(table[remainder]);
}
