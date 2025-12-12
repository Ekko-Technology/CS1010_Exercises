/**
 * CS1010 Semester 1 AY24/25
 * Exercise 4: Subtract
 *
 * @file: subtract.c
 * @author: Joshua (Group B03)
 */
#include "cs1010.h"

#define NCOLS 3
#define NROWS 3

int main()
{
  long matrix1[NROWS][NCOLS] = {0};
  long matrix2[NROWS][NCOLS] = {0};
  long matrix3[NROWS][NCOLS] = {0};

  for (long i = 0; i < NROWS; i += 1) {
    for (long j = 0; j < NCOLS; j += 1) {
      matrix1[i][j] = cs1010_read_long();
    }
  }

  for (long i = 0; i < NROWS; i += 1) {
    for (long j = 0; j < NCOLS; j += 1) {
      matrix2[i][j] = cs1010_read_long();
    }
  }

  for (long i = 0; i < NROWS; i += 1) {
    for (long j = 0; j < NCOLS; j += 1) {
      matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
      cs1010_print_long(matrix3[i][j]);
      cs1010_print_string(" ");
    }
    cs1010_println_string("");
  }

  return 0;
}
