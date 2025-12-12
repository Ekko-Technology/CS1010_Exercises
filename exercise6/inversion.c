/**
 * CS1010 Semester 1 AY24/25
 * Exercise 6: Inversion
 *
 * @file: inversion.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

int main()
{
  size_t elements = cs1010_read_size_t();

  long *array = cs1010_read_long_array(elements);
  if (array == NULL) {
    return 1;
  }

  long start_index = 0;
  long end_index = (long)elements - 1;

  long inversion_count = 0;

  while (start_index < end_index) {
    if (array[start_index] > array[end_index]) {
      inversion_count += end_index - start_index;
      end_index -= 1;
    }
    start_index += 1;
  }

  cs1010_println_long(inversion_count);

  free(array);
}
