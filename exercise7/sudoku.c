/**
 * CS1010 Semester 1 AY24/25
 * Exercise 7: Sudoku
 *
 * @file: sudoku.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"
#include <stdio.h>
#include <unistd.h>

#define EMPTY '.'

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

void print_row_file(char *row)
{
  for (int i = 0; i < 9; i += 1) {
    putchar(row[i]);
    if (i == 2 || i == 5) {
      cs1010_print_string("│");
    }
  }
  putchar('\n');
}

void print_row_screen(char *row)
{
  for (int i = 0; i < 9; i += 1) {
    if (row[i] == EMPTY) {
      cs1010_print_string(YELLOW);
      putchar(row[i]);
      cs1010_print_string(RESET);
    } else {
      putchar(row[i]);
    }
    if (i == 2 || i == 5) {
      cs1010_print_string(RED);
      cs1010_print_string("│");
      cs1010_print_string(RESET);
    }
  }
  putchar('\n');
}

void print_sudoku_file(char *puzzle[9])
{
  for (int i = 0; i < 9; i += 1) {
    print_row_file(puzzle[i]);
    if (i == 2 || i == 5) {
      cs1010_println_string("───┼───┼───");
    }
  }
}

void print_sudoku_screen(char *puzzle[9])
{
  cs1010_clear_screen();
  for (int i = 0; i < 9; i += 1) {
    print_row_screen(puzzle[i]);
    if (i == 2 || i == 5) {
      cs1010_print_string(RED);
      cs1010_println_string("───┼───┼───");
      cs1010_print_string(RESET);
    }
  }
  usleep(10 * 1000);
}

void print_sudoku(char *puzzle[9])
{
  if (isatty(fileno(stdout))) {
    print_sudoku_screen(puzzle);
  } else {
    print_sudoku_file(puzzle);
  }
}

// check if inputting a specific number into the specified position will lead to
// duplicates
bool check_row_and_column(char **sudoku, char value_placed, long pos_row,
                          long pos_col)
{
  if (sudoku[pos_row][pos_col] != EMPTY) {
    return false;
  }

  // check row
  for (long i = 0; i < 9; i += 1) {
    if (sudoku[pos_row][i] == value_placed) {
      return false;
    }
  }

  // check column
  for (long i = 0; i < 9; i += 1) {
    if (sudoku[i][pos_col] == value_placed) {
      return false;
    }
  }

  // check 3 x 3 grid
  long start_row = (pos_row / 3) * 3;
  long start_col = (pos_col / 3) * 3;

  for (long i = start_row; i < start_row + 3; i += 1) {
    for (long j = start_col; j < start_col + 3; j += 1) {
      if (sudoku[i][j] == value_placed) {
        return false;
      }
    }
  }

  return true;
}

void recursive_fill(char **sudoku, long pos_row, long pos_col, bool *settled)
{
  // if index reaches the bottom right and is valid, stop the run
  if (pos_row == 8 && pos_col == 9) {
    settled[0] = true;
    print_sudoku(sudoku);
    return;
  }

  // once it reaches the end of the row, proceed to next row and repeat
  if (pos_col == 9) {
    recursive_fill(sudoku, pos_row + 1, 0, settled);
    return;
  }

  // if space is not empty skip to the next space
  if (sudoku[pos_row][pos_col] != EMPTY) {
    print_sudoku(sudoku);
    recursive_fill(sudoku, pos_row, pos_col + 1, settled);
  }

  for (long i = 1; i <= 9; i += 1) {
    char char_digit = (char)i + '0';
    if (check_row_and_column(sudoku, char_digit, pos_row, pos_col)) {
      sudoku[pos_row][pos_col] = char_digit;
      print_sudoku(sudoku);
      recursive_fill(sudoku, pos_row, pos_col + 1, settled);
      // if all numbers for future call failed to fill, backtrack here
      if (!settled[0]) {
        sudoku[pos_row][pos_col] = EMPTY;
        // print_sudoku(sudoku);
      }
    }
  }
}

int main()
{
  char **sudoku = cs1010_read_line_array(9);
  if (sudoku == NULL) {
    return 1;
  }

  bool *settled = malloc(1 * sizeof(bool));
  {
    if (settled == NULL) {
      return 1;
    }
  }
  settled[0] = false;

  // fill position(0, 0)
  print_sudoku(sudoku);
  recursive_fill(sudoku, 0, 0, settled);

  if (!settled[0]) {
    cs1010_println_string("no solution");
  }

  for (long i = 0; i < 9; i += 1) {
    free(sudoku[i]);
  }
  free(sudoku);
  free(settled);
}
