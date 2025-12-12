/**
 * CS1010 Semester 1 AY24/25
 * Exercise 6: Sort
 *
 * @file: sort.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

void sort_v_array(long *array, long *new_array, long elements)
{
  long start_index = 0;
  long end_index = elements - 1;
  long new_array_index = elements - 1;

  while (new_array_index >= 0) {
    if (array[start_index] >= array[end_index]) {
      new_array[new_array_index] = array[start_index];
      start_index += 1;
    }
    // assert that array[end_index] > array[start_index]
    else {
      new_array[new_array_index] = array[end_index];
      end_index -= 1;
    }
    new_array_index -= 1;
    elements -= 1;
  }
}

int main()
{
  size_t elements = cs1010_read_size_t();

  long *array = cs1010_read_long_array(elements);
  if (array == NULL) {
    return 1;
  }

  long *sorted_array = malloc(elements * sizeof(long));
  if (sorted_array == NULL) {
    return 1;
  }

  sort_v_array(array, sorted_array, (long)elements);

  for (size_t i = 0; i < elements; i += 1) {
    cs1010_println_long(sorted_array[i]);
  }

  free(array);
  free(sorted_array);
}
