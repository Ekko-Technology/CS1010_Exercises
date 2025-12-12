/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: Candy
 *
 * @file: candy.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"
#include <math.h>

unsigned long compute_num_of_boxes(unsigned long num_of_candies,
                                   unsigned long max_candies_per_box)
{
  unsigned long max_boxes;

  max_boxes = num_of_candies / max_candies_per_box;
  if (num_of_candies % max_candies_per_box != 0) {
    max_boxes += 1;
  }

  return max_boxes;
}

// No main function.  The main function is defined concat-main.c
