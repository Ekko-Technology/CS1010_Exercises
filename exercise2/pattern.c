/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: Pattern
 *
 * @file: pattern.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"
#include <math.h>
#include <stdbool.h>

// leading cell from 1st row to h-th row (1, m, 1), (m + 1, m, 2), (3m + 1, m,
// 3), (6m + 1, m, 4), (10m + 1, m, 5) eseential take previous lead cell

// row_num corresponds to interval, m corresponds to interval

// drawing triangle full of hashes

long find_lead_cell(long row_num, long m)
{
  long num = 1;
  long counter = 1;
  while (counter < row_num) {
    num += counter * m;
    counter += 1;
  }

  return num;
}

bool is_prime(long value)
{
  if (value < 2) {
    return false;
  }

  if (value == 2 || value == 3) {
    return true;
  }

  if (value % 2 == 0 || value % 3 == 0) {
    return false;
  }

  // check if value is divisible by other prime numbers 5 and above

  long start = 5;
  long step = 6;
  long limit = (long)sqrt((double)value);

  for (long i = start; i <= limit; i += step) {
    if (value % i == 0 || value % (i + 2) == 0) {
      return false;
    }
  }
  return true;
}

bool contain_prime(long row, long col, long m)
{
  long lead_cell = find_lead_cell(row, m);
  lead_cell += col - 1;

  // iterate m times to check all elements within cell
  for (long i = 0; i < m; i += 1) {
    if (is_prime(lead_cell)) {
      return true;
    }
    lead_cell += row;
  }
  return false;
}

void draw_triangle(long m, long row_height)
{

  for (long i = 1; i <= row_height; i += 1) {
    long hashes_to_print = 2 * (i - 1) + 1;
    // print left trailing white space
    for (long j = 1; j <= row_height - i; j += 1) {
      cs1010_print_string(" ");
    }
    // print hash symbols
    for (long k = 1; k <= hashes_to_print; k++) {
      if (contain_prime(i, k, m)) {
        cs1010_print_string("#");
      } else {
        cs1010_print_string(".");
      }
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

  long interval = cs1010_read_long();
  long height = cs1010_read_long();

  draw_triangle(interval, height);
}
