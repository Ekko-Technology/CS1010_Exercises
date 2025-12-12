/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: Rectangle
 *
 * @file: rectangle.c
 * @author: Joshua Yeo (Group B03)
 */

#include "cs1010.h"

#define TOP_LEFT "╔"
#define TOP_RIGHT "╗"
#define BOTTOM_RIGHT "╝"
#define BOTTOM_LEFT "╚"
#define HORIZONTAL "═"
#define VERTICAL "║"
#define WHITESPACE " "

void rectangle(long width, long height)
{
  // print top row
  cs1010_print_string(TOP_LEFT);
  for (long i = 0; i < width - 2; i += 1) {
    cs1010_print_string(HORIZONTAL);
  }
  cs1010_println_string(TOP_RIGHT);

  // middle rows
  for (long k = 0; k < height - 2; k += 1) {
    cs1010_print_string(VERTICAL);

    for (long l = 0; l < width - 2; l += 1) {
      cs1010_print_string(WHITESPACE);
    }
    cs1010_println_string(VERTICAL);
  }

  // print bottom row
  cs1010_print_string(BOTTOM_LEFT);
  for (long j = 0; j < width - 2; j += 1) {
    cs1010_print_string(HORIZONTAL);
  }
  cs1010_println_string(BOTTOM_RIGHT);
}

int main()
{
  long width = cs1010_read_long();
  long height = cs1010_read_long();
  rectangle(width, height);
}
