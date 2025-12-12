/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: Leap
 *
 * @file: leap.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"
#include <stdbool.h>

// except for years divisible by 100 but not by 400
bool exception(long year)
{
  if (year % 100 == 0 && year % 400 != 0) {
    return false;
  }
  return true;
}

bool is_leap_year(long year)
{
  if (year % 4 == 0 && exception(year)) {
    return true;
  }
  return false;
}

int main()
{
  long year = cs1010_read_long();

  cs1010_print_long(year);

  if (is_leap_year(year)) {
    cs1010_println_string(" is a leap year");
  } else {
    cs1010_println_string(" is not a leap year");
  }
}
