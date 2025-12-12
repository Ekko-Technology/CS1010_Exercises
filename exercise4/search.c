/**
 * CS1010 Semester 1 AY24/25
 * Exercise 4: Search
 *
 * @file: search.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"
#include <stdlib.h>
// determine length of string
size_t length_of(const char *str)
{
  size_t length = 0;
  while (str[length] != '\0') {
    length += 1;
  }
  return length;
}

long sub_index(char *word, char *main)
{
  long index = 0;
  while (main[index] != '\0') {
    if (main[index] == word[0]) {
      // loop through both word and main
      long i = 1;
      while (word[i] != '\0' && main[index + i] == word[i]) {
        i += 1;
      }
      // if loop exits successfully, there is a match
      if (word[i] == '\0') {
        return index;
      }
    }
    index += 1;
  }
  return -1; // to denote that word is not found
}

int main()
{
  char *main_line = cs1010_read_line();
  size_t num_words = cs1010_read_size_t();

  char **words = cs1010_read_word_array(num_words); // list of words
  if (words == NULL) {
    cs1010_println_string("Failed to allocate memory");
    return 1;
  }

  for (size_t j = 0; j < num_words; j += 1) {
    char *word = words[j];
    if (sub_index(word, main_line) >= 0) {
      cs1010_println_long(sub_index(word, main_line));
    } else {
      cs1010_println_string("not found");
    }
  }

  // free main line string
  free(main_line);
  // free inner strings
  for (size_t i = 0; i < num_words; i += 1) {
    free(words[i]);
  }
  // free outer list of strings
  free(words);
}
