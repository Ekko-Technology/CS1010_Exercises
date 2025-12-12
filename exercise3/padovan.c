/**
 * CS1010 Semester 1 AY24/25
 * Exercise 3: Padovan
 *
 * @file: padovan.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

void padovan(long number)
{
  long first = 1;
  long second = 0;
  long third = 0;

  long list_of_hundred[100] = {0};

  for (long i = 2; i < number - 98; i += 1) {
    long new_element = (second + first) % 10000;

    first = second;
    second = third;
    third = new_element;
  }

  list_of_hundred[0] = first;
  list_of_hundred[1] = second;
  list_of_hundred[2] = third;

  for (long i = 3; i < 100; i += 1) {
    long new_element =
        (list_of_hundred[i - 3] + list_of_hundred[i - 2]) % 10000;
    list_of_hundred[i] = new_element;
  }

  //  cs1010_print_string("the last element in the list is:");
  //  cs1010_println_long(list_of_hundred[99]);

  for (long i = 99; i >= 0; i -= 1) {
    cs1010_println_long(list_of_hundred[i]);
  }
}

int main()
{
  long degree = cs1010_read_long();

  padovan(degree);
}
