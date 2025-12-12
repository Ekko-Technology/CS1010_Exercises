/**
 * CS1010 Semester 1 AY24/25
 * Exercise 8: Digits
 *
 * @file: digits.c
 * @author: Joshua Yeo (Group B03)
 */

#include "cs1010.h"
#include <stdbool.h>

#define NCOLS 28
#define NROWS 28
#define WHITE '.'
#define BLACK '#'
#define K 5

// declaring new data type: digit
typedef struct {
  char **grid;
  long label;
} digit;

// declaring new data type: neighbour
typedef struct {
  long label;
  long distance;
} neighbour;

long find_distance(char **training_grid, char **testing_grid)
{
  long counter = 0;
  for (long i = 0; i < NROWS; i += 1) {
    for (long j = 0; j < NCOLS; j += 1) {
      if ((training_grid[i][j] == BLACK && testing_grid[i][j] == WHITE) ||
          (training_grid[i][j] == WHITE && testing_grid[i][j] == BLACK)) {
        counter += 1;
      }
    }
  }
  return counter;
}

void manage_k_list(neighbour *k_list, long max_index, long last_lowest)
{
  // as k_list is already in ascending order, find the index where last_lowest
  // first appears and do a loop for all these ties to paste into k_list
  long first_index = 0;
  while (k_list[first_index].distance != last_lowest) {
    first_index += 1;
  }

  while (true) {
    // find lowest label among tied elements
    long lowest_label = 100;
    long previous_label = -1;
    for (long j = first_index; j < max_index; j += 1) {
      if (k_list[j].label < lowest_label && k_list[j].label > previous_label) {
        lowest_label = k_list[j].label;
      }
    }
    // update k_list
    for (long j = first_index; j < max_index && first_index < K; j += 1) {
      if (k_list[j].label == lowest_label) {
        k_list[first_index] = k_list[j];
        first_index += 1;
      }
    }
    if (first_index >= K) {
      return;
    }
    previous_label = lowest_label;
    lowest_label = 100;
  }
}

bool find_lowest_detection(neighbour *k_list, long label1, long label2)
{
  long label_1 = 99999;
  long label_2 = 99999;
  for (long i = 0; i < K; i += 1) {
    if (k_list[i].label == label1 && k_list[i].distance < label_1) {
      label_1 = k_list[i].distance;
    } else if (k_list[i].label == label2 && k_list[i].distance < label_2) {
      label_2 = k_list[i].distance;
    }
  }

  if (label_1 < label_2) {
    return true;
  }
  return false;
}

long find_best(neighbour *k_list, long max_index, long last_lowest)
{
  long label_count[10] = {0};

  // this means that our k_list > 5 and needs to be trimmed
  if (max_index > K - 1) {
    // find the index that is before last_lowest
    manage_k_list(k_list, max_index, last_lowest);
  }

  for (long i = 0; i < K; i += 1) {
    label_count[k_list[i].label] += 1;
    // cs1010_print_long(k_list[i].label);
    // cs1010_print_string(" ");
  }
  // cs1010_println_string("");

  long most_common = 0;
  long frequency = 0;
  for (long i = 0; i < 10; i += 1) {
    if (label_count[i] > frequency) {
      most_common = i;
      frequency = label_count[i];
    } else if (label_count[i] == frequency &&
               find_lowest_detection(k_list, i, most_common)) {
      most_common = i;
    }
  }
  // cs1010_print_string("most common is: ");
  // cs1010_println_long(most_common);

  return most_common;
}

void finding_k(digit *training_digits, size_t trg_images_len,
               digit *testing_digits, size_t test_images_len,
               neighbour *neighbours)
{
  long corrects = 0;
  bool identical = false;
  neighbour *k_list = malloc(
      K * sizeof(neighbour)); // stores the lowest difference 5 neighbours

  for (size_t i = 0; i < test_images_len; i += 1) {
    for (size_t j = 0; j < trg_images_len; j += 1) {
      long difference =
          find_distance(training_digits[j].grid, testing_digits[i].grid);
      neighbours[j].distance = difference;
      // if exact identical copy found with training data, return the training
      // data and break
      if (difference == 0) {
        identical = true;
        cs1010_print_long(testing_digits[i].label);
        cs1010_print_string(" ");
        cs1010_println_long(training_digits[j].label);
        if (testing_digits[i].label == training_digits[j].label) {
          corrects += 1;
        }
      }
    }

    if (identical) {
      continue;
    }

    long previous_lowest = 0;
    long lowest = 999;
    size_t k_index = 0;

    // update k list
    while (k_index < K) {
      // find lowest value in list
      for (size_t l = 0; l < trg_images_len; l += 1) {
        if (lowest > neighbours[l].distance &&
            neighbours[l].distance > previous_lowest) {
          lowest = neighbours[l].distance;
        }
      }

      for (size_t l = 0; l < trg_images_len; l += 1) {
        if (neighbours[l].distance == lowest) {
          if (k_index >= K) {
            k_list = realloc(k_list, (k_index + 1) * sizeof(neighbour));
          }
          k_list[k_index] = neighbours[l];
          k_index += 1;
        }
      }
      previous_lowest = lowest;
      lowest = 999;
    }

    // find most occuring digit out of the 5
    long best_match = find_best(k_list, (long)k_index, previous_lowest);

    cs1010_print_long(testing_digits[i].label);
    cs1010_print_string(" ");
    cs1010_println_long(best_match);
    if (testing_digits[i].label == best_match) {
      corrects += 1;
    }
  }
  double percentage = ((double)corrects / (double)test_images_len) * 100;
  cs1010_println_double(percentage);

  free(k_list);
}
// if we have N training and K testing images, we should have (N + K) digits and
// N neighbours
int main()
{
  size_t trg_images = cs1010_read_size_t();

  digit *training_digits = malloc(trg_images * sizeof(digit));

  neighbour *neighbours = malloc(trg_images * sizeof(neighbour));

  for (size_t i = 0; i < trg_images; i += 1) {
    long number = cs1010_read_long();
    training_digits[i].grid = cs1010_read_word_array(NROWS);
    training_digits[i].label = number;
    neighbours[i].label = number;
  }

  size_t test_images = cs1010_read_size_t();

  digit *testing_digits = malloc(test_images * sizeof(digit));

  for (size_t i = 0; i < test_images; i += 1) {
    testing_digits[i].label = cs1010_read_long();
    testing_digits[i].grid = cs1010_read_word_array(NROWS);
  }

  // we now have a list of training datasets, testing datasets and neighbours

  finding_k(training_digits, trg_images, testing_digits, test_images,
            neighbours);

  for (size_t i = 0; i < trg_images; i += 1) {
    for (size_t j = 0; j < NROWS; j += 1) {
      free(training_digits[i].grid[j]);
    }
    free(training_digits[i].grid);
  }
  for (size_t i = 0; i < test_images; i += 1) {
    for (long j = 0; j < NROWS; j += 1) {
      free(testing_digits[i].grid[j]);
    }
    free(testing_digits[i].grid);
  }
  free(training_digits);
  free(testing_digits);
  free(neighbours);
}
