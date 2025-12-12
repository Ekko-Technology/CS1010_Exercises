/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: Suffix
 *
 * @file: suffix.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

void print_with_suffix(long n)
{
  long last_digit = n % 10;

  long last_2_digits = n % 100;

  cs1010_print_long(n);

  // numbers ending with 1
  if (last_digit == 1 && last_2_digits != 11) {
    cs1010_println_string("st");
  }
  // numbers ending with 2
  else if (last_digit == 2 && last_2_digits != 12) {
    cs1010_println_string("nd");
  }
  // numbers ending wiht 3
  else if (last_digit == 3 && last_2_digits != 13) {
    cs1010_println_string("rd");
  }
  // all other numbers
  else {
    cs1010_println_string("th");
  }
}

int main()
{
  long input = cs1010_read_long();

  print_with_suffix(input);

  return 0;
}
