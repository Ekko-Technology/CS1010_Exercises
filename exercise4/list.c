/**
 * CS1010 Semester 1 AY24/25
 * Exercise 4: List
 *
 * @file: list.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

int main()
{
  size_t lens = cs1010_read_size_t();
  long *list = cs1010_read_long_array(lens);
  if (list == NULL) {
    cs1010_println_string("fail to allocate memory");
    return 1;
  }

  for (long index = (long)lens - 1; index >= 0; index -= 1) {
    cs1010_println_long(list[index]);
  }
  free(list);
  return 0;
}
