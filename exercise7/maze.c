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
