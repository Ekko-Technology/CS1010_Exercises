/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: Triangle
 *
 * @file: triangle.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

bool is_possible_triangle(long x, long y, long z)
{
  // find the two smallest side
  long longest, sum_smaller;
  if (x > y && x > z) {
    longest = x;
    sum_smaller = y + z;
  } else if (y > x && y > z) {
    longest = y;
    sum_smaller = x + z;
  } else {
    longest = z;
    sum_smaller = x + y;
  }

  if (sum_smaller > longest) {
    return true;
  }
  return false;
}

double compute_area(long a, long b, long c)
{
  double x = (double)(b - a + c);
  double y = (double)(a - b + c);
  double z = (double)(b - c + a);
  // printf("the value of x is %f\n", x);
  // printf("the value of y is %f\n", y);
  // printf("the value of z is %f\n", z);

  double s = 1.0 / 16.0 * (double)(a + b + c);
  // printf("the value of s is %f\n", s);

  double area = sqrt(s * x * y * z);
  return area;
}

int main()
{
  long x = cs1010_read_long();
  long y = cs1010_read_long();
  long z = cs1010_read_long();

  if (is_possible_triangle(x, y, z)) {
    cs1010_println_string("Possible");

    double area = compute_area(x, y, z);
    cs1010_println_double(area);
  } else {
    cs1010_println_string("Impossible");
  }
}
