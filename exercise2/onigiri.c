/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: Onigiri
 *
 * @file: onigiri.c
 * @author: Joshua Yeo(Group B03)
 */

#include "cs1010.h"

void draw_triangle(long row_height)
{

  for (long i = 1; i <= row_height; i += 1) {
    long hashes_to_print = 2 * (i - 1) + 1;
    // print left trailing white space
    for (long j = 1; j <= row_height - i; j += 1) {
      cs1010_print_string(" ");
    }
    // print hash symbols
    for (long k = 1; k <= hashes_to_print; k++) {

      cs1010_print_string("#");
    }
    // print right trailing white space
    for (long l = 1; l <= row_height - i; l += 1) {
      cs1010_print_string(" ");
    }
    cs1010_println_string("");
  }
}

int main()
{
  long height = cs1010_read_long();
  draw_triangle(height);
}
