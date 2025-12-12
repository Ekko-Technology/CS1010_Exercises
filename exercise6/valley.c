/**
 * CS1010 Semester 1 AY24/25
 * Exercise 6: Valley
 *
 * @file: valley.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

long find_smallest(long *array, long start, long end)
{
  if (start == end) {
    return array[start];
  }

  long mid = (start + end) / 2;

  /* if (array[mid] < array[mid + 1] && array[mid] < array[mid - 1])
   {
     return array[mid];
   } */

  if (array[mid] > array[mid + 1]) {
    return find_smallest(array, mid + 1, end);
  }
  return find_smallest(array, start, mid);
}

int main()
{
  size_t elements = cs1010_read_size_t();

  long *array = cs1010_read_long_array(elements);
  if (array == NULL) {
    return 1;
  }

  long min = find_smallest(array, 0, (long)elements - 1);

  cs1010_println_long(min);

  free(array);
}
