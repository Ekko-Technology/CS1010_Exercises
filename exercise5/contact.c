/**
 * CS1010 Semester 1 AY24/25
 * Exercise 5: Contact
 *
 * @file: contact.c
 * @author: Joshua Yeo (Group B03)
 */

#include "cs1010.h"
#include <stdbool.h>

int main()
{
  bool no_contact = true;
  long n = cs1010_read_long();

  char **jagged_matrix = cs1010_read_word_array((size_t)n);
  if (jagged_matrix == NULL) {
    free(jagged_matrix);
  }

  // ensures that second_id is always greater than first_id
  long first_id = cs1010_read_long();
  long second_id = cs1010_read_long();
  if (first_id > second_id) {
    long temp = second_id;
    second_id = first_id;
    first_id = temp;
  }

  if (jagged_matrix[second_id][first_id] == '1') {
    cs1010_println_string("direct contact");
  } else {
    for (long i = 0; i < second_id; i += 1) {
      // check for other contacts with second_id on horizontal left
      if (jagged_matrix[second_id][i] == '1' &&
          jagged_matrix[i][first_id] == '1') {
        cs1010_print_string("contact through ");
        cs1010_println_long(i);
        no_contact = false;
        break;
      }
    }

    for (long i = second_id + 1; i < n; i += 1) {
      // check for other contacts with second_id on vertical down
      if (jagged_matrix[i][second_id] == '1' &&
          jagged_matrix[i][first_id] == '1') {
        cs1010_print_string("contact through ");
        cs1010_println_long(i);
        no_contact = false;
        break;
      }
    }

    if (no_contact) {
      cs1010_println_string("no contact");
    }
  }

  for (long i = 0; i < n; i += 1) {
    free(jagged_matrix[i]);
  }
  free(jagged_matrix);
}
