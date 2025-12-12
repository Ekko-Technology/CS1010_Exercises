/**
 * CS1010 Semester 1 AY24/25
 * Exercise 4: Subtract
 *
 * @file: subtract.c
 * @author: Joshua Yeo (Group B03)
 */

#include "cs1010.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void edit_large(char *large, long index)
{
  if (index == 0) {
    return; // Prevent accessing out of bounds
  }

  if (large[index - 1] > '0') {
    long diff = large[index - 1] - '1';
    large[index - 1] = (char)(diff + '0');
    return;
  }
  // the left trailing digit is 0
  large[index - 1] = '9';
  edit_large(large, index - 1);
}

void print_result(char *large)
{
  // manage leading zeroes
  bool leading_zero = true;
  for (size_t i = 0; i < strlen(large); i += 1) {
    if (leading_zero && large[i] == '0') {
      continue;
    }
    leading_zero = false;
    putchar(large[i]);
  }

  if (leading_zero) {
    putchar('0');
  }
  cs1010_println_string("");
}

int main()
{
  char *large = cs1010_read_word();
  char *small = cs1010_read_word();
  if (large == NULL || small == NULL) {
    cs1010_println_string("failed to allocate memory");
    return 1;
  }

  long large_index = (long)(strlen(large) - 1);
  long small_index = (long)(strlen(small) - 1);

  while (small_index >= 0) {
    char last_large = large[large_index];
    char last_small = small[small_index];
    long diff;
    if (last_large >= last_small) {
      diff = last_large - last_small;
      large[large_index] = (char)(diff + '0');
    }
    // assertion that (last_small > last_large)
    else {
      // change to long type as last_large > 9
      long long_last_large = (last_large - '0') + 10;
      long long_last_small = (last_small - '0');
      diff = long_last_large - long_last_small;
      large[large_index] = (char)(diff + '0');
      // edit numbers before last_large
      edit_large(large, large_index);
    }
    large_index -= 1;
    small_index -= 1;
  }

  print_result(large);

  // let large point to the nearest non zero integer from te left
  free(large);
  free(small);
  return 0;
}
