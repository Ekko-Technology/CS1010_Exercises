/**
 * CS1010 Semester 1 AY24/25
 * Exercise 7: Fill
 *
 * @file: fill.c
 * @author: Joshua Yeo (Group B03)
 */

#include "cs1010.h"

void update_matrix(long **matrix, long row, long col, long max_row,
                   long max_col, long new_red, long new_green, long new_blue,
                   long old_red, long old_green, long old_blue)
{
  // check if indexes are within matrix range && if surrounding pixels are of
  // same rgb value to old rgb && if that new rgb values are not repeated
  if ((row < 0 || row >= max_row || col < 0 || col >= max_col) ||
      (matrix[row][col * 3] != old_red ||
       matrix[row][3 * col + 1] != old_green ||
       matrix[row][3 * col + 2] != old_blue) ||
      (new_red == old_red && new_blue == old_blue && new_green == old_green)) {
    return;
  }

  // update new rgb
  matrix[row][3 * col] = new_red;
  matrix[row][3 * col + 1] = new_green;
  matrix[row][3 * col + 2] = new_blue;

  update_matrix(matrix, row + 1, col, max_row, max_col, new_red, new_green,
                new_blue, old_red, old_green, old_blue);
  update_matrix(matrix, row - 1, col, max_row, max_col, new_red, new_green,
                new_blue, old_red, old_green, old_blue);
  update_matrix(matrix, row, col + 1, max_row, max_col, new_red, new_green,
                new_blue, old_red, old_green, old_blue);
  update_matrix(matrix, row, col - 1, max_row, max_col, new_red, new_green,
                new_blue, old_red, old_green, old_blue);
}

void print_matrix(long **matrix, size_t rows, size_t cols)
{
  cs1010_print_string("P3");
  cs1010_print_string(" ");
  cs1010_print_size_t(cols);
  cs1010_print_string(" ");
  cs1010_print_size_t(rows);
  cs1010_print_string(" ");
  cs1010_println_long(255);

  for (size_t i = 0; i < rows; i += 1) {
    for (size_t j = 0; j < cols; j += 1) {
      cs1010_print_long(matrix[i][3 * j]);
      cs1010_print_string(" ");
      cs1010_print_long(matrix[i][3 * j + 1]);
      cs1010_print_string(" ");
      cs1010_println_long(matrix[i][3 * j + 2]);
    }
  }
}

int main()
{
  size_t rows = cs1010_read_size_t();
  size_t cols = cs1010_read_size_t();

  long **matrix = malloc(rows * sizeof(long *));
  if (matrix == NULL) {
    return 1;
  }
  // read matrix into 2D array
  for (size_t i = 0; i < rows; i += 1) {
    matrix[i] = cs1010_read_long_array(3 * cols);
    if (matrix[i] == NULL) {
      for (size_t j = 0; j < i; j += 1) {
        free(matrix[j]);
      }
      free(matrix);
      return 1;
    }
  }

  size_t changes = cs1010_read_size_t();
  for (size_t i = 0; i < changes; i += 1) {
    long row_pt = cs1010_read_long();
    long col_pt = cs1010_read_long();
    long new_red = cs1010_read_long();
    long new_green = cs1010_read_long();
    long new_blue = cs1010_read_long();
    update_matrix(matrix, row_pt, col_pt, (long)rows, (long)cols, new_red,
                  new_green, new_blue, matrix[row_pt][3 * col_pt],
                  matrix[row_pt][3 * col_pt + 1],
                  matrix[row_pt][3 * col_pt + 2]);
  }
  print_matrix(matrix, rows, cols);

  for (size_t i = 0; i < rows; i += 1) {
    free(matrix[i]);
  }
  free(matrix);
}
