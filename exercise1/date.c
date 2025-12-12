/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: Date
 *
 * @file: date.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

long month_to_days(long month, long days)
{

  long total = month * 30 + days;

  return total;
}

int main()
{
  long m1, d1;
  long m2, d2;
  long m3, d3;

  m1 = cs1010_read_long();
  d1 = cs1010_read_long();
  // if (m1 < 1 || m1 > 12 || d1 < 1 || d1 > 31){
  //    return -1;
  //}
  long days_1 = month_to_days(m1, d1);

  m2 = cs1010_read_long();
  d2 = cs1010_read_long();
  // if (m2 < 1 || m2 > 12 || d2 < 1 || d2 > 31){
  //    return -1;
  // }
  long days_2 = month_to_days(m2, d2);

  m3 = cs1010_read_long();
  d3 = cs1010_read_long();
  // if (m3 < 1 || m3 > 12 || d3 < 1 || d3 > 31){
  //   return -1;
  //}
  long days_3 = month_to_days(m3, d3);

  if (days_2 > days_1 && days_3 > days_2) {
    cs1010_println_string("yes");
  } else {
    cs1010_println_string("no");
  }

  return 0;
}
