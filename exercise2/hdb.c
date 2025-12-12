/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: HDB
 *
 * @file: hdb.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

void print_hdb(long length, long height)
{
  for (long i = 0; i < height; i += 1) {
    for (long j = 0; j < length; j += 1) {
      cs1010_print_string("#");
    }
    cs1010_println_string(" ");
  }
}

int main()
{
  long length = cs1010_read_long();
  long height = cs1010_read_long();

  print_hdb(length, height);
}
