/**
 * CS1010 Semester 1 AY24/25
 * Exercise 3: Days
 *
 * @file: days.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

int main()
{
  long month = cs1010_read_long();

  long days = cs1010_read_long();

  long days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  for (long i = 0; i < month - 1; i += 1) {
    days += days_in_month[i];
  }

  cs1010_println_long(days);
}
