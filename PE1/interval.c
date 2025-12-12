/**
 * CS1010 Semester 1 AY24/25
 * Practical Exam 1: Interval
 *
 * @file: interval.c
 * @author: XXX
 */

#include "cs1010.h"

void print_interval(long start, long end) {
  cs1010_print_string("[");
  cs1010_print_long(start);
  cs1010_print_string(", ");
  cs1010_print_long(end);
  cs1010_println_string("]");
}

int main()
{
}
