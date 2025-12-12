/**
 * CS1010 Semester 1 AY24/25
 * Exercise 4: Line
 *
 * @file: line.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

int main()
{
  char *line = cs1010_read_line();
  if (line == NULL) {
    cs1010_println_string("Failed to allocate memory");
    return 1;
  }

  cs1010_print_string(line);
  free(line);
  return 0;
}
