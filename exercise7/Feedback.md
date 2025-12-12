# CS1010 Exercise 7
## Feedback for Ekko-Technology

#### Submission

Link: https://www.github.com/nus-cs1010-2425-s1/ex07-Ekko-Technology/commit/242b5006611bdccb0e959e76207387b902954c58

This exercise is submitted 2562 minutes after the deadline.

---
### walk
<details><summary>Code for  walk.c </summary>

```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 7: Walk
 *
 * @file: walk.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"
#include <math.h>

int main()
{
  // Using P&C, it is the permutation of the number of up and right movements
  // given, whilst dividing each by its factorial to account for repetition
  long x = cs1010_read_long();

  long y = cs1010_read_long();

  long sum = x + y;

  double counter = 1.0;
  while (y > 0) {
    counter *= (double)sum / (double)y;
    sum -= 1;
    y -= 1;
  }

  cs1010_println_long((long)(round(counter)));

  return 0;
}
```

</details>

#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `walk.c`. No warnings are generated. :confetti_ball:

#### Test Cases

- Your `walk` fails to pass 5 of the test cases.

#### Other Issues

- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex07-Ekko-Technology/commit/242b5006611bdccb0e959e76207387b902954c58).

---
### maze
<details><summary>Code for  maze.c </summary>

```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 7: maze
 *
 * @file: maze.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"
#include <stdbool.h>
#include <unistd.h>

#define EMPTY '.'
#define WALL '#'
#define USER '@'

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

/**
 * Print one row of the maze to the screen (with colors)
 *
 * @param[in] maze_row The 1D array representing a row of maze.
 */
void print_maze_row_with_color(char *maze_row)
{
  long l = (long)strlen(maze_row);
  for (long j = 0; j < l; j++) {
    if (maze_row[j] == EMPTY) {
      cs1010_print_string(BLUE);
    } else if (maze_row[j] == USER) {
      cs1010_print_string(RED);
    } else {
      cs1010_print_string(YELLOW);
    }
    putchar(maze_row[j]);
  }
  cs1010_println_string("");
  cs1010_print_string(RESET);
}

/**
 * Print the maze to the screen.
 *
 * @param[in] maze The 2D array representing the maze.
 * @param[in] nrows The number of rows
 * @param[in] steps The number of steps taken so far.
 */
void print_maze(char **maze, long nrows, long steps)
{
  if (isatty(fileno(stdout))) {
    cs1010_clear_screen();
  }
  for (long i = 0; i < nrows; i += 1) {
    if (!isatty(fileno(stdout))) {
      cs1010_println_string(maze[i]);
    } else {
      print_maze_row_with_color(maze[i]);
    }
  }
  cs1010_println_long(steps);
  if (isatty(fileno(stdout))) {
    usleep(100 * 1000);
  }
}

bool check_deadend(char **maze, bool **visited, long pos_row, long pos_col)
{
  long walls_around = 0;
  if (maze[pos_row + 1][pos_col] == WALL ||
      visited[pos_row + 1][pos_col]) // visited spaces also treated as walls as
                                     // we do not want to enter back into it
  {
    walls_around += 1;
  }
  if (maze[pos_row - 1][pos_col] == WALL || visited[pos_row - 1][pos_col]) {
    walls_around += 1;
  }
  if (maze[pos_row][pos_col + 1] == WALL || visited[pos_row][pos_col + 1]) {
    walls_around += 1;
  }
  if (maze[pos_row][pos_col - 1] == WALL || visited[pos_row][pos_col - 1]) {
    walls_around += 1;
  }

  if (walls_around == 4) {
    return true;
  }
  return false;
}

void swap(char **maze, long row1, long col1, long row2, long col2)
{
  char temp = maze[row1][col1];
  maze[row1][col1] = maze[row2][col2];
  maze[row2][col2] = temp;
}

void update_counter_and_print_matrix(char **maze, bool **visited, long *counter,
                                     long pos_row, long pos_col, long rows)
{
  counter[0] += 1;
  visited[pos_row][pos_col] = true;
  print_maze(maze, rows, counter[0]);
}

void traverse(char **maze, bool **visited, long pos_row, long pos_col,
              long rows, long cols, long *counter, bool *can_stop)
{
  // base case: if @ is able to travel out of the maze's index range, he has
  // escaped
  if (pos_row == 0 || pos_row == rows - 1 || pos_col == 0 ||
      pos_col == cols - 1) {
    can_stop[0] = true;
    return;
  }

  // second base case to return when dead end is met which occurs when 3/4 ways
  // are blocked
  if (check_deadend(maze, visited, pos_row, pos_col)) {
    visited[pos_row][pos_col] = true;
    return;
  }

  // move up
  if (maze[pos_row - 1][pos_col] != WALL && !visited[pos_row - 1][pos_col]) {
    swap(maze, pos_row - 1, pos_col, pos_row, pos_col);
    update_counter_and_print_matrix(maze, visited, counter, pos_row, pos_col,
                                    rows);
    traverse(maze, visited, pos_row - 1, pos_col, rows, cols, counter,
             can_stop);
    // if end is reached, dont need to backtrack
    if (can_stop[0]) {
      return;
    }

    // backtracking
    swap(maze, pos_row - 1, pos_col, pos_row, pos_col); // swap back
    update_counter_and_print_matrix(maze, visited, counter, pos_row, pos_col,
                                    rows);
    // cs1010_println_string("backtrack down");
  }
  // move right
  if (maze[pos_row][pos_col + 1] != WALL && !visited[pos_row][pos_col + 1]) {
    swap(maze, pos_row, pos_col + 1, pos_row, pos_col);
    update_counter_and_print_matrix(maze, visited, counter, pos_row, pos_col,
                                    rows);
    traverse(maze, visited, pos_row, pos_col + 1, rows, cols, counter,
             can_stop);
    // if end is reached, dont need to backtrack
    if (can_stop[0]) {
      return;
    }

    // backtracking
    swap(maze, pos_row, pos_col + 1, pos_row, pos_col); // swap back
    update_counter_and_print_matrix(maze, visited, counter, pos_row, pos_col,
                                    rows);
    // cs1010_println_string("backtrack left");
  }

  // move down
  if (maze[pos_row + 1][pos_col] != WALL && !visited[pos_row + 1][pos_col]) {
    swap(maze, pos_row, pos_col, pos_row + 1, pos_col);
    update_counter_and_print_matrix(maze, visited, counter, pos_row, pos_col,
                                    rows);
    traverse(maze, visited, pos_row + 1, pos_col, rows, cols, counter,
             can_stop);
    // if end is reached, dont need to backtrack
    if (can_stop[0]) {
      return;
    }

    // backtracking
    swap(maze, pos_row, pos_col, pos_row + 1, pos_col);
    update_counter_and_print_matrix(maze, visited, counter, pos_row, pos_col,
                                    rows);
    // cs1010_println_string("backtrack up");
  }

  // move left
  if (maze[pos_row][pos_col - 1] != WALL && !visited[pos_row][pos_col - 1]) {
    swap(maze, pos_row, pos_col - 1, pos_row, pos_col);
    update_counter_and_print_matrix(maze, visited, counter, pos_row, pos_col,
                                    rows);
    traverse(maze, visited, pos_row, pos_col - 1, rows, cols, counter,
             can_stop);
    // if end is reached, dont need to backtrack
    if (can_stop[0]) {
      return;
    }

    // backtracking
    swap(maze, pos_row, pos_col - 1, pos_row, pos_col);
    update_counter_and_print_matrix(maze, visited, counter, pos_row, pos_col,
                                    rows);
    // cs1010_println_string("backtrack up");
  }
}

int main()
{
  size_t rows = cs1010_read_size_t();
  size_t cols = cs1010_read_size_t();

  long *counter = malloc(1 * sizeof(long));
  if (counter == NULL) {
    return 1;
  }
  counter[0] = 0;

  bool *can_stop = malloc(1 * sizeof(bool));
  /*if (can_stop == NULL)
    {
    free(counter);
    return 1;
    } */
  can_stop[0] = false;

  char **maze = cs1010_read_line_array(rows);
  /*if (maze == NULL)
    {
    free(counter);
    free(can_stop);
    return 1;
    }*/

  bool **visited = malloc(rows * sizeof(bool *));
  /* if (visited == NULL)
     {
     free(counter);
     free(can_stop);
     return 1;
     }*/

  for (size_t i = 0; i < rows; i += 1) {
    visited[i] = malloc(cols * sizeof(bool));
    /*if (visited[i] == NULL)
      {
      for (size_t j = 0; j < i; j +=1)
      {
      free(visited[j]);
      }
      free(visited);
      free(can_stop);
      free(counter);
      return 1;
      } */

    for (size_t k = 0; k < cols; k += 1) {
      visited[i][k] = false;
    }
  }
  // find position of Luke
  long pos_row, pos_col;
  for (size_t i = 0; i < rows; i += 1) {
    for (size_t j = 0; j < cols; j += 1) {
      if (maze[i][j] == USER) {
        pos_row = (long)i;
        pos_col = (long)j;
        break;
      }
    }
  }
  print_maze(maze, (long)rows, counter[0]);
  traverse(maze, visited, pos_row, pos_col, (long)rows, (long)cols, counter,
           can_stop);

  for (size_t i = 0; i < rows; i += 1) {
    free(maze[i]);
    free(visited[i]);
  }
  free(maze);
  free(visited);
  free(can_stop);
  free(counter);
}
```

</details>

#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `maze.c`. No warnings are generated. :confetti_ball:

#### Test Cases

- Your `maze` fails to pass 5 of the test cases.

#### Other Issues

- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex07-Ekko-Technology/commit/242b5006611bdccb0e959e76207387b902954c58).

---
### fill
<details><summary>Code for  fill.c </summary>

```C
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
```

</details>

#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `fill.c`. No warnings are generated. :confetti_ball:

#### Test Cases

- Your `fill` fails to pass 13 of the test cases.

#### Other Issues

- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex07-Ekko-Technology/commit/242b5006611bdccb0e959e76207387b902954c58).

---
### sudoku
<details><summary>Code for  sudoku.c </summary>

```C
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
```

</details>

#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `sudoku.c`. No warnings are generated. :confetti_ball:

#### Test Cases

- Your `sudoku` fails to pass 5 of the test cases.

#### Other Issues

- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex07-Ekko-Technology/commit/242b5006611bdccb0e959e76207387b902954c58).

## Summary
| Question | Achievement |
|----------|-------|
| [walk](#walk) | Late/No Submission/Cannot Compile |
| [maze](#maze) | Late/No Submission/Cannot Compile |
| [fill](#fill) | Late/No Submission/Cannot Compile |
| [sudoku](#sudoku) | Late/No Submission/Cannot Compile |

Note: The achievement badges for this exercise take the running time of your solution into consideration.  See [the grader's comments](https://www.github.com/nus-cs1010-2425-s1/ex07-Ekko-Technology/commit/242b5006611bdccb0e959e76207387b902954c58) for details.
