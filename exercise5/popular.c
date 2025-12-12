/**
 * CS1010 Semester 1 AY24/25
 * Exercise 5: Popular
 *
 * @file: popular.c
 * @author: Joshua Yeo (Group B03)
 */

#include "cs1010.h"

int main()
{
  long n = cs1010_read_long();

  char **array = cs1010_read_word_array((size_t)n);
  if (array == NULL) {
    free(array);
    return 1;
  }

  long *num_friends = malloc((size_t)n * sizeof(long));
  if (num_friends == NULL) {
    return 1;
  }

  for (long i = 0; i < n; i += 1) {
    num_friends[i] = 0;
  }

  for (long i = 0; i < n; i += 1) {
    for (long j = 0; j < i; j += 1) {
      if (array[i][j] == '1') {
        num_friends[i] += 1;
        num_friends[j] += 1;
      }
    }
  }

  long highest_count = 0;
  long index = 0;

  for (long i = 0; i < n; i += 1) {
    long temp = num_friends[i];
    if (temp > highest_count) {
      highest_count = temp;
      index = i;
    }
  }
  cs1010_println_long(index);
  cs1010_println_long(highest_count);

  for (long k = 0; k < n; k += 1) {
    free(array[k]);
  }

  free(array);
  free(num_friends);
}
