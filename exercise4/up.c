/**
 * CS1010 Semester 1 AY24/25
 * Exercise 4: Up
 *
 * @file: up.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

int main()
{
  char *line = cs1010_read_line();
  if (line == NULL) {
    cs1010_print_string("Failed to allocate memory");
    return 1;
  }

  // traverses till it reaches null terminator
  for (long i = 0; line[i] != '\0'; i += 1) {
    long letter = line[i];
    if (letter >= 97 && letter <= 122) {
      line[i] -= 32;
    }
  }

  cs1010_println_string(line);
  free(line);
}
