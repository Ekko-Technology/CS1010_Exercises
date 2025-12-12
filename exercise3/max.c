/**
 * CS1010 Semester 1 AY24/25
 * Exercise 3: Max
 *
 * @file: max.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

long find_max(const long list[], long start, long end)
{
  // TODO: The following line is a placeholder.  Replace it.

  if (start == end - 1) {
    return list[start];
  }

  // binary search

  long mid = (start + end) / 2;
  long max_left = find_max(list, start, mid);
  long max_right = find_max(list, mid, end);

  if (max_left > max_right) {
    return max_left;
  }
  return max_right;
}

// No main function.  The main function is defined concat-main.c
