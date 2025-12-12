/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: Collatz
 *
 * @file: collatz.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"
#include <math.h>

long collatz(long input, long steps)
{
  long steps_taken = steps;

  // base case
  if (input == 1) {
    return steps_taken;
  }
  if (input % 2 == 0) {
    input /= 2;
  } else {
    input = 3 * input + 1;
  }

  // cs1010_println_long(input);
  steps_taken += 1;
  return collatz(input, steps_taken);
}

int main()
{
  long small_num = cs1010_read_long();
  long big_num = cs1010_read_long();

  long steps_taken = 0;
  long lengthy_num;
  for (long i = small_num; i <= big_num; i += 1) {
    long temp_steps = collatz(i, 0);
    if (temp_steps >= steps_taken) {
      steps_taken = temp_steps;
      lengthy_num = i;
    }
  }

  cs1010_println_long(steps_taken);
  cs1010_println_long(lengthy_num);
}
