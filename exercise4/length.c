/**
 * CS1010 Semester 1 AY24/25
 * Exercise 4: Length
 *
 * @file: length.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

size_t length_of(const char *str)
{
  unsigned long i = 0;
  do {
    i += 1;
  } while (str[i] != '\0');

  return i;
}

// No main function.  The main function is defined length-main.c
