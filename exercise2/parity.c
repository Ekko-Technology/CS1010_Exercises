/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: Parity
 *
 * @file: parity.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

void print_parity(long input)
{
  // TODO: The following line is a placeholder.  Replace it.
  long odd_count = 0;
  long even_count = 0;

  while (input > 0) {
    long last_digit = input % 10;

    if (last_digit % 2 == 0) {
      even_count += 1;
    } else {
      odd_count += 1;
    }

    input /= 10;
  }

  cs1010_print_string("odd: ");
  cs1010_println_long(odd_count);
  cs1010_print_string("even: ");
  cs1010_println_long(even_count);
}

// o main function.  The main function is defined concat-main.c
