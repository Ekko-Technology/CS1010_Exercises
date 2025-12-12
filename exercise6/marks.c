/**
 * CS1010 Semester 1 AY24/25
 * Exercise 6: Marks
 *
 * @file: marks.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

int main()
{
  size_t elements = cs1010_read_size_t();

  long *marks_array = malloc(elements * sizeof(long));
  if (marks_array == NULL) {
    return 1;
  }

  char **name_list = malloc(elements * sizeof(char *));
  if (name_list == NULL) {
    free(marks_array);
    return 1;
  }

  // read inputs
  for (size_t i = 0; i < elements; i += 1) {
    name_list[i] = cs1010_read_word();
    marks_array[i] = cs1010_read_long();
  }

  for (long i = 0; i <= 100; i += 1) {
    for (size_t j = 0; j < elements; j += 1) {
      if (marks_array[j] == i) {
        cs1010_print_long(i);
        cs1010_print_string(" ");
        cs1010_println_string(name_list[j]);
      }
    }
  }

  free(marks_array);
  for (size_t i = 0; i < elements; i += 1) {
    free(name_list[i]);
  }
}
