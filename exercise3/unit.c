/**
 * CS1010 Semester 1 AY24/25
 * Exercise 3: Unit
 *
 * @file: unit.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"
#include <math.h>

void find_unit_vector(const long v[3], double unit[3])
{
  long sum = 0;
  for (long i = 0; i < 3; i += 1) {
    sum += (v[i] * v[i]);
  }

  double average = sqrt((double)sum);

  for (long j = 0; j < 3; j += 1) {
    unit[j] = (1.0 / average) * (double)v[j];
    cs1010_println_double(unit[j]);
  }
}

int main()
{
  long vector[3] = {0};
  double unit_vector[3] = {0};
  for (long i = 0; i < 3; i++) {
    vector[i] = cs1010_read_long();
  }

  find_unit_vector(vector, unit_vector);
}
