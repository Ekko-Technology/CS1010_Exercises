/**
 * CS1010 Semester 1 AY24/25
 * Exercise 4: concat
 *
 * @file: concat.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

// Defined in length.c
size_t length_of(const char *str);

char *concatenate(const char *str1, const char *str2)
{
  // The following lines are placeholder.  REPLACE these lines in your solution.
  size_t len1 = length_of(str1);
  size_t len2 = length_of(str2);

  char *concat_string =
      malloc(((len1 + len2) * sizeof(char)) + 1); // +1 for null terminator
  if (concat_string == NULL) {
    return NULL;
  }

  for (unsigned long i = 0; i < len1; i += 1) {
    concat_string[i] = str1[i];
  }

  for (unsigned long j = 0; j < len2; j += 1) {
    concat_string[len1 + j] = str2[j];
  }

  // place null terminator after last char
  concat_string[len1 + len2] = '\0';
  return concat_string;
}

// No main function.  The main function is defined concat-main.c
