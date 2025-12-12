/**
 * CS1010 Semester 1 AY24/25
 * Exercise 5: Line
 *
 * @file: line.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"
#include <math.h>

#define BLACK 0
#define WHITE 255

long **read_matrix(long width, long height, double gradient, long x1, double y1,
                   long x2, long y2)
{
  long **matrix = malloc((size_t)height * sizeof(long *));
  if (matrix == NULL) {
    return NULL;
  }

  for (long i = 0; i < height; i += 1) {
    matrix[i] = malloc((size_t)width * sizeof(long));
    if (matrix[i] == NULL) {
      for (long k = 0; k < i; k += 1) {
        free(matrix[k]);
      }
      free(matrix);
      return NULL;
    }

    for (long j = 0; j < width; j += 1) {
      matrix[i][j] = BLACK;
    }
  }

  while (x1 != x2) {
    matrix[(long)round(y1)][x1] = WHITE;
    x1 += 1;
    y1 = y1 + gradient;
  }
  matrix[y2][x2] = WHITE;
  return matrix;
}

void print_line(long **matrix, long width, long height)
{
  cs1010_println_string("P2");
  cs1010_print_long(width);
  cs1010_print_string(" ");
  cs1010_println_long(height);
  cs1010_println_long(WHITE);

  for (long i = 0; i < height; i += 1) {
    for (long j = 0; j < width - 1; j += 1) {
      cs1010_print_long(matrix[i][j]);
      cs1010_print_string(" ");
    }
    cs1010_println_long(matrix[i][width - 1]);
  }
}

int main()
{
  long width = cs1010_read_long();
  long height = cs1010_read_long();

  long x1 = cs1010_read_long();
  long y1 = cs1010_read_long();
  long x2 = cs1010_read_long();
  long y2 = cs1010_read_long();

  double m = (double)(y2 - y1) / (double)(x2 - x1);

  long **matrix = read_matrix(width, height, m, x1, (double)y1, x2, y2);

  print_line(matrix, width, height);

  for (long i = 0; i < height; i += 1) {
    free(matrix[i]);
  }
  free(matrix);

  return 0;
}
