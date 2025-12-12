/**
 * CS1010 Semester 1 AY24/25
 * Exercise 5: Echo
 *
 * @file: echo.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"
#include <stdlib.h>

long **read_matrix(size_t nrows, size_t ncols)
{
  // allocate memory for outer loop of long pointers
  long **matrix = malloc(nrows * sizeof(long *));
  {
    if (matrix == NULL) {
      return NULL;
    }
  }

  // allocate memory for long values within inner loop
  for (size_t i = 0; i < nrows; i += 1) {
    matrix[i] = malloc(ncols * sizeof(long));
    if (matrix[i] == NULL) {
      for (size_t k = 0; k < i; k++) {
        free(matrix[k]);
      }
      free(matrix);
      return NULL;
    }

    for (size_t j = 0; j < ncols; j += 1) {
      matrix[i][j] = cs1010_read_long();
    }
  }

  return matrix;
}

void print_matrix(size_t nrows, size_t ncols, long **matrix)
{
  for (size_t i = 0; i < nrows; i += 1) {
    for (size_t j = 0; j < ncols; j += 1) {
      cs1010_print_long(matrix[i][j]);
      cs1010_print_string(" ");
    }
    cs1010_println_string("");
  }
}

int main()
{
  size_t rows = cs1010_read_size_t();
  size_t cols = cs1010_read_size_t();

  long **matrix = read_matrix(rows, cols);

  print_matrix(rows, cols, matrix);

  for (size_t i = 0; i < rows; i += 1) {
    free(matrix[i]);
  }

  free(matrix);

  return 0;
}
