/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: Lemon
 *
 * @file: lemon.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

int main()
{
  long start = cs1010_read_long();
  long elements = cs1010_read_long();
  long step = cs1010_read_long();

  long count = 0;

  while (count < elements) {
    cs1010_println_long(start);
    start += step;
    count += 1;
  }
}
