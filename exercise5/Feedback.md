# CS1010 Exercise 5
## Feedback for Ekko-Technology
#### Submission
Link: https://www.github.com/nus-cs1010-2425-s1/ex05-Ekko-Technology/commit/36dea9b0eb5a91505e038b1dcec9b2d37c0aa748

---
### add
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 4: Subtract
 *
 * @file: subtract.c
 * @author: Joshua (Group B03)
 */
#include "cs1010.h"

#define NCOLS 3
#define NROWS 3

int main()
{
  long matrix1[NROWS][NCOLS] = {0};
  long matrix2[NROWS][NCOLS] = {0};
  long matrix3[NROWS][NCOLS] = {0};

  for (long i = 0; i < NROWS; i += 1) {
    for (long j = 0; j < NCOLS; j += 1) {
      matrix1[i][j] = cs1010_read_long();
    }
  }

  for (long i = 0; i < NROWS; i += 1) {
    for (long j = 0; j < NCOLS; j += 1) {
      matrix2[i][j] = cs1010_read_long();
    }
  }

  for (long i = 0; i < NROWS; i += 1) {
    for (long j = 0; j < NCOLS; j += 1) {
      matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
      cs1010_print_long(matrix3[i][j]);
      cs1010_print_string(" ");
    }
    cs1010_println_string("");
  }

  return 0;
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `add.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `add` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex05-Ekko-Technology/commit/36dea9b0eb5a91505e038b1dcec9b2d37c0aa748).

---
### echo
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 5: Echo
 *
 * @file: echo.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"
#include <stdlib.h>

long **read_matrix(size_t nrows, size_t ncols)
{
  // allocate memory for outer loop of long pointers
  long **matrix = malloc(nrows * sizeof(long *));
  {
    if (matrix == NULL) {
      return NULL;
    }
  }

  // allocate memory for long values within inner loop
  for (size_t i = 0; i < nrows; i += 1) {
    matrix[i] = malloc(ncols * sizeof(long));
    if (matrix[i] == NULL) {
      for (size_t k = 0; k < i; k++) {
        free(matrix[k]);
      }
      free(matrix);
      return NULL;
    }

    for (size_t j = 0; j < ncols; j += 1) {
      matrix[i][j] = cs1010_read_long();
    }
  }

  return matrix;
}

void print_matrix(size_t nrows, size_t ncols, long **matrix)
{
  for (size_t i = 0; i < nrows; i += 1) {
    for (size_t j = 0; j < ncols; j += 1) {
      cs1010_print_long(matrix[i][j]);
      cs1010_print_string(" ");
    }
    cs1010_println_string("");
  }
}

int main()
{
  size_t rows = cs1010_read_size_t();
  size_t cols = cs1010_read_size_t();

  long **matrix = read_matrix(rows, cols);

  print_matrix(rows, cols, matrix);

  for (size_t i = 0; i < rows; i += 1) {
    free(matrix[i]);
  }

  free(matrix);

  return 0;
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `echo.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `echo` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex05-Ekko-Technology/commit/36dea9b0eb5a91505e038b1dcec9b2d37c0aa748).

---
### line
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 5: Line
 *
 * @file: line.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"
#include <math.h>

#define BLACK 0
#define WHITE 255

long **read_matrix(long width, long height, double gradient, long x1, double y1,
                   long x2, long y2)
{
  long **matrix = malloc((size_t)height * sizeof(long *));
  if (matrix == NULL) {
    return NULL;
  }

  for (long i = 0; i < height; i += 1) {
    matrix[i] = malloc((size_t)width * sizeof(long));
    if (matrix[i] == NULL) {
      for (long k = 0; k < i; k += 1) {
        free(matrix[k]);
      }
      free(matrix);
      return NULL;
    }

    for (long j = 0; j < width; j += 1) {
      matrix[i][j] = BLACK;
    }
  }

  while (x1 != x2) {
    matrix[(long)round(y1)][x1] = WHITE;
    x1 += 1;
    y1 = y1 + gradient;
  }
  matrix[y2][x2] = WHITE;
  return matrix;
}

void print_line(long **matrix, long width, long height)
{
  cs1010_println_string("P2");
  cs1010_print_long(width);
  cs1010_print_string(" ");
  cs1010_println_long(height);
  cs1010_println_long(WHITE);

  for (long i = 0; i < height; i += 1) {
    for (long j = 0; j < width - 1; j += 1) {
      cs1010_print_long(matrix[i][j]);
      cs1010_print_string(" ");
    }
    cs1010_println_long(matrix[i][width - 1]);
  }
}

int main()
{
  long width = cs1010_read_long();
  long height = cs1010_read_long();

  long x1 = cs1010_read_long();
  long y1 = cs1010_read_long();
  long x2 = cs1010_read_long();
  long y2 = cs1010_read_long();

  double m = (double)(y2 - y1) / (double)(x2 - x1);

  long **matrix = read_matrix(width, height, m, x1, (double)y1, x2, y2);

  print_line(matrix, width, height);

  for (long i = 0; i < height; i += 1) {
    free(matrix[i]);
  }
  free(matrix);

  return 0;
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `line.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `line` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex05-Ekko-Technology/commit/36dea9b0eb5a91505e038b1dcec9b2d37c0aa748).

---
### popular
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 5: Popular
 *
 * @file: popular.c
 * @author: Joshua Yeo (Group B03)
 */

#include "cs1010.h"

int main()
{
  long n = cs1010_read_long();

  char **array = cs1010_read_word_array((size_t)n);
  if (array == NULL) {
    free(array);
    return 1;
  }

  long *num_friends = malloc((size_t)n * sizeof(long));
  if (num_friends == NULL) {
    return 1;
  }

  for (long i = 0; i < n; i += 1) {
    num_friends[i] = 0;
  }

  for (long i = 0; i < n; i += 1) {
    for (long j = 0; j < i; j += 1) {
      if (array[i][j] == '1') {
        num_friends[i] += 1;
        num_friends[j] += 1;
      }
    }
  }

  long highest_count = 0;
  long index = 0;

  for (long i = 0; i < n; i += 1) {
    long temp = num_friends[i];
    if (temp > highest_count) {
      highest_count = temp;
      index = i;
    }
  }
  cs1010_println_long(index);
  cs1010_println_long(highest_count);

  for (long k = 0; k < n; k += 1) {
    free(array[k]);
  }

  free(array);
  free(num_friends);
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `popular.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `popular` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex05-Ekko-Technology/commit/36dea9b0eb5a91505e038b1dcec9b2d37c0aa748).

---
### contact
```C
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
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `contact.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `contact` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex05-Ekko-Technology/commit/36dea9b0eb5a91505e038b1dcec9b2d37c0aa748).

---
### social
```C
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
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `social.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `social` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex05-Ekko-Technology/commit/36dea9b0eb5a91505e038b1dcec9b2d37c0aa748).

## Summary
| Question | Achievement |
|----------|-------|
| [add](#add) | Excellent |
| [echo](#echo) | Excellent |
| [line](#line) | Excellent |
| [popular](#popular) | Excellent |
| [contact](#contact) | Excellent |
| [social](#social) | Excellent |
