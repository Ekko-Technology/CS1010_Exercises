/*
 * CS1010 Semester 1 AY24/25
 * Exercise 4: Word
 *
 * @file: word.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

int main()
{
  char *first_word = cs1010_read_word();
  if (first_word == NULL) {
    cs1010_println_string("Failed to allocate memory");
    return 1;
  }

  cs1010_println_string(first_word);
  free(first_word);
  return 0;
}
