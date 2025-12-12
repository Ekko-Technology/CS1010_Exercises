/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: GCD
 *
 * @file: gcd.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

long compute_gcd(long a, long b)
{
  // TODO: Replcae the following placeholder with
  // the code to compute GCD
  if (b == 0) {
    return a;
  }
  long new_a = b;
  long new_b = a % b;
  return compute_gcd(new_a, new_b);
}

int main()
{
  long a = cs1010_read_long();
  long b = cs1010_read_long();
  cs1010_println_long(compute_gcd(a, b));
}
