# CS1010 Exercise 4
## Feedback for Ekko-Technology
#### Submission
Link: https://www.github.com/nus-cs1010-2425-s1/ex04-Ekko-Technology/commit/5d1a637ded092905a1eb51e68a38314a1598bca3

---
### word
```C
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
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `word.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `word` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex04-Ekko-Technology/commit/5d1a637ded092905a1eb51e68a38314a1598bca3).

---
### line
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 4: Line
 *
 * @file: line.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

int main()
{
  char *line = cs1010_read_line();
  if (line == NULL) {
    cs1010_println_string("Failed to allocate memory");
    return 1;
  }

  cs1010_print_string(line);
  free(line);
  return 0;
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `line.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `line` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex04-Ekko-Technology/commit/5d1a637ded092905a1eb51e68a38314a1598bca3).

---
### up
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 4: Up
 *
 * @file: up.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

int main()
{
  char *line = cs1010_read_line();
  if (line == NULL) {
    cs1010_print_string("Failed to allocate memory");
    return 1;
  }

  // traverses till it reaches null terminator
  for (long i = 0; line[i] != '\0'; i += 1) {
    long letter = line[i];
    if (letter >= 97 && letter <= 122) {
      line[i] -= 32;
    }
  }

  cs1010_println_string(line);
  free(line);
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `up.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `up` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex04-Ekko-Technology/commit/5d1a637ded092905a1eb51e68a38314a1598bca3).

---
### list
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 4: List
 *
 * @file: list.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

int main()
{
  size_t lens = cs1010_read_size_t();
  long *list = cs1010_read_long_array(lens);
  if (list == NULL) {
    cs1010_println_string("fail to allocate memory");
    return 1;
  }

  for (long index = (long)lens - 1; index >= 0; index -= 1) {
    cs1010_println_long(list[index]);
  }
  free(list);
  return 0;
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `list.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `list` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex04-Ekko-Technology/commit/5d1a637ded092905a1eb51e68a38314a1598bca3).

---
### length
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 4: Length
 *
 * @file: length.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

size_t length_of(const char *str)
{
  unsigned long i = 0;
  do {
    i += 1;
  } while (str[i] != '\0');

  return i;
}

// No main function.  The main function is defined length-main.c
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `length.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `length` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex04-Ekko-Technology/commit/5d1a637ded092905a1eb51e68a38314a1598bca3).

---
### concat
```C
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
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `concat.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `concat` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex04-Ekko-Technology/commit/5d1a637ded092905a1eb51e68a38314a1598bca3).

---
### search
```C
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
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `search.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `search` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex04-Ekko-Technology/commit/5d1a637ded092905a1eb51e68a38314a1598bca3).

---
### kendall
```C
/*
 * CS1010 Semester 1 AY24/25
 * Exercise 4: kendall
 *
 * @file: kendall.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

int main()
{
  size_t n = cs1010_read_size_t();

  long *order = cs1010_read_long_array(n);

  unsigned long paired_combi = (n * (n - 1)) / 2;

  long count = 0;
  for (unsigned long i = 0; i <= n; i += 1) // base ranking
  {
    for (unsigned long j = i + 1; j < n; j += 1) // index of order
    {
      if ((unsigned)order[i] > (unsigned)order[j]) {
        count += 1;
      }
    }
  }

  double tau = (double)count / (double)paired_combi;

  cs1010_println_double(tau);
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `kendall.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `kendall` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex04-Ekko-Technology/commit/5d1a637ded092905a1eb51e68a38314a1598bca3).

---
### subtract
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 4: Subtract
 *
 * @file: subtract.c
 * @author: Joshua Yeo (Group B03)
 */

#include "cs1010.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void edit_large(char *large, long index)
{
  if (index == 0) {
    return; // Prevent accessing out of bounds
  }

  if (large[index - 1] > '0') {
    long diff = large[index - 1] - '1';
    large[index - 1] = (char)(diff + '0');
    return;
  }
  // the left trailing digit is 0
  large[index - 1] = '9';
  edit_large(large, index - 1);
}

void print_result(char *large)
{
  // manage leading zeroes
  bool leading_zero = true;
  for (size_t i = 0; i < strlen(large); i += 1) {
    if (leading_zero && large[i] == '0') {
      continue;
    }
    leading_zero = false;
    putchar(large[i]);
  }

  if (leading_zero) {
    putchar('0');
  }
  cs1010_println_string("");
}

int main()
{
  char *large = cs1010_read_word();
  char *small = cs1010_read_word();
  if (large == NULL || small == NULL) {
    cs1010_println_string("failed to allocate memory");
    return 1;
  }

  long large_index = (long)(strlen(large) - 1);
  long small_index = (long)(strlen(small) - 1);

  while (small_index >= 0) {
    char last_large = large[large_index];
    char last_small = small[small_index];
    long diff;
    if (last_large >= last_small) {
      diff = last_large - last_small;
      large[large_index] = (char)(diff + '0');
    }
    // assertion that (last_small > last_large)
    else {
      // change to long type as last_large > 9
      long long_last_large = (last_large - '0') + 10;
      long long_last_small = (last_small - '0');
      diff = long_last_large - long_last_small;
      large[large_index] = (char)(diff + '0');
      // edit numbers before last_large
      edit_large(large, large_index);
    }
    large_index -= 1;
    small_index -= 1;
  }

  print_result(large);

  // let large point to the nearest non zero integer from te left
  free(large);
  free(small);
  return 0;
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `subtract.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `subtract` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex04-Ekko-Technology/commit/5d1a637ded092905a1eb51e68a38314a1598bca3).

## Summary
| Question | Achievement |
|----------|-------|
| [word](#word) | Excellent |
| [line](#line) | Excellent |
| [up](#up) | Excellent |
| [list](#list) | Excellent |
| [length](#length) | Excellent |
| [concat](#concat) | Excellent |
| [search](#search) | Excellent |
| [kendall](#kendall) | Excellent |
| [subtract](#subtract) | Excellent |
