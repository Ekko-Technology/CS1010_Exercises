/**
 * CS1010 Semester 1 AY24/25
 * Exercise 3: Counter
 *
 * @file: counter.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

void counter(long number)
{
  if (number == 0) {
    cs1010_print_long(0);
    cs1010_print_string(": ");
    cs1010_println_long(1);
  } else {
    long list[10] = {0};
    while (number > 0) {
      long last_digit = number % 10;
      list[last_digit] += 1;
      number /= 10;
    }
    for (long i = 0; i < 10; i += 1) {
      if (list[i] != 0) {
        cs1010_print_long(i);
        cs1010_print_string(": ");
        cs1010_println_long(list[i]);
      }
    }
  }
}

int main()
{
  long number = cs1010_read_long();

  counter(number);
}
