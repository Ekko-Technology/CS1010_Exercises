/*
**
* CS1010 Semester 1 AY24/25
* Exercise 5: Social
*
* @file: life.c
* @author: Joshua Yeo (Group B03)
*/

#include "cs1010.h"
#include <stdio.h>

#define FRIEND '1'
#define STRANGER '0'

void add_hop(char **jagged_array, size_t id_1, size_t id_2, char degree_str,
             size_t num_lines)
{
  // instance when id_1 hope through id_2
  // check horizontally from left/id_1 to id_2/right
  for (size_t i = id_1; i < id_2; i += 1) {
    if (jagged_array[id_2][i] == FRIEND && jagged_array[i][id_1] == STRANGER) {
      jagged_array[i][id_1] = degree_str;
    }
  }

  // check from id_2 vertical down
  for (size_t j = id_2; j < num_lines; j += 1) {
    if (jagged_array[j][id_2] == FRIEND && jagged_array[j][id_1] == STRANGER) {
      jagged_array[j][id_1] = degree_str;
    }
  }

  // check for instances when id_2 hops through id_1
  for (size_t k = id_2; k < num_lines; k += 1) {
    if (jagged_array[k][id_1] == FRIEND && jagged_array[k][id_2] == STRANGER) {
      jagged_array[k][id_2] = degree_str;
    }
  }
}

// iterates through matrix up to down, left to right
void edit_array(char **jagged_array, size_t degree, size_t num_lines)
{
  // convert degree into char for comparision with array elements
  char degree_str = (char)(degree + '0');

  // analyzing from left columns to right columns
  for (size_t i = 0; i < num_lines;
       i += 1) // i would be the person id we checking for
  {
    for (size_t j = i + 1; j < num_lines;
         j += 1) // j being the index of people we traverse down to see if
                 // friends with i
    {
      if (jagged_array[j][i] ==
          degree_str) // if direct contact, make second party's friends first
                      // party's friends and label them as (degree_str + 1)
      {
        add_hop(jagged_array, i, j, degree_str + 1, num_lines);
      }
    }
  }
}

int main()
{
  size_t num_lines = cs1010_read_size_t();

  size_t degree = cs1010_read_size_t();

  char **jagged_array = cs1010_read_word_array(num_lines);
  if (jagged_array == NULL) {
    free(jagged_array);
    return 1;
  }

  for (size_t i = 1; i < degree; i += 1) {
    edit_array(jagged_array, i, num_lines);
  }

  for (size_t i = 0; i < num_lines; i += 1) {
    for (size_t j = 0; j <= i; j += 1) {
      if (jagged_array[i][j] != '0') {
        putchar('1');
      } else {
        putchar('0');
      }
      // putchar(jagged_array[i][j]);
    }
    cs1010_println_string("");
  }

  // freeing process
  for (size_t i = 0; i < num_lines; i += 1) {
    free(jagged_array[i]);
  }
  free(jagged_array);

  return 0;
}
