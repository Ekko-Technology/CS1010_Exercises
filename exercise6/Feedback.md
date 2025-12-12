# CS1010 Exercise 6
## Feedback for Ekko-Technology

#### Submission

Link: https://www.github.com/nus-cs1010-2425-s1/ex06-Ekko-Technology/commit/be48e234e6c7c5d362ad5201ed4a0d20c1fe6d6c

---
### sort
<details><summary>Code for  sort.c </summary>

```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 6: Sort
 *
 * @file: sort.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

void sort_v_array(long *array, long *new_array, long elements)
{
  long start_index = 0;
  long end_index = elements - 1;
  long new_array_index = elements - 1;

  while (new_array_index >= 0) {
    if (array[start_index] >= array[end_index]) {
      new_array[new_array_index] = array[start_index];
      start_index += 1;
    }
    // assert that array[end_index] > array[start_index]
    else {
      new_array[new_array_index] = array[end_index];
      end_index -= 1;
    }
    new_array_index -= 1;
    elements -= 1;
  }
}

int main()
{
  size_t elements = cs1010_read_size_t();

  long *array = cs1010_read_long_array(elements);
  if (array == NULL) {
    return 1;
  }

  long *sorted_array = malloc(elements * sizeof(long));
  if (sorted_array == NULL) {
    return 1;
  }

  sort_v_array(array, sorted_array, (long)elements);

  for (size_t i = 0; i < elements; i += 1) {
    cs1010_println_long(sorted_array[i]);
  }

  free(array);
  free(sorted_array);
}
```

</details>

#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `sort.c`. No warnings are generated. :confetti_ball:

#### Test Cases

- Your `sort` passes all test cases. :thumbsup:

#### Other Issues

- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex06-Ekko-Technology/commit/be48e234e6c7c5d362ad5201ed4a0d20c1fe6d6c).

---
### valley
<details><summary>Code for  valley.c </summary>

```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 6: Valley
 *
 * @file: valley.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

long find_smallest(long *array, long start, long end)
{
  if (start == end) {
    return array[start];
  }

  long mid = (start + end) / 2;

  /* if (array[mid] < array[mid + 1] && array[mid] < array[mid - 1])
   {
     return array[mid];
   } */

  if (array[mid] > array[mid + 1]) {
    return find_smallest(array, mid + 1, end);
  }
  return find_smallest(array, start, mid);
}

int main()
{
  size_t elements = cs1010_read_size_t();

  long *array = cs1010_read_long_array(elements);
  if (array == NULL) {
    return 1;
  }

  long min = find_smallest(array, 0, (long)elements - 1);

  cs1010_println_long(min);

  free(array);
}
```

</details>

#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `valley.c`. No warnings are generated. :confetti_ball:

#### Test Cases

- Your `valley` passes all test cases. :thumbsup:

#### Other Issues

- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex06-Ekko-Technology/commit/be48e234e6c7c5d362ad5201ed4a0d20c1fe6d6c).

---
### inversion
<details><summary>Code for  inversion.c </summary>

```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 6: Inversion
 *
 * @file: inversion.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

int main()
{
  size_t elements = cs1010_read_size_t();

  long *array = cs1010_read_long_array(elements);
  if (array == NULL) {
    return 1;
  }

  long start_index = 0;
  long end_index = (long)elements - 1;

  long inversion_count = 0;

  while (start_index < end_index) {
    if (array[start_index] > array[end_index]) {
      inversion_count += end_index - start_index;
      end_index -= 1;
    }
    start_index += 1;
  }

  cs1010_println_long(inversion_count);

  free(array);
}
```

</details>

#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `inversion.c`. No warnings are generated. :confetti_ball:

#### Test Cases

- Your `inversion` fails to pass 1 of the test cases.
<details><summary>Hidden test cases that cause your `inversion` to fail include the following:</summary>
 
```
5
4 5 3 2 1
```
</details>


#### Other Issues

- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex06-Ekko-Technology/commit/be48e234e6c7c5d362ad5201ed4a0d20c1fe6d6c).

---
### marks
<details><summary>Code for  marks.c </summary>

```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 6: Marks
 *
 * @file: marks.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

int main()
{
  size_t elements = cs1010_read_size_t();

  long *marks_array = malloc(elements * sizeof(long));
  if (marks_array == NULL) {
    return 1;
  }

  char **name_list = malloc(elements * sizeof(char *));
  if (name_list == NULL) {
    free(marks_array);
    return 1;
  }

  // read inputs
  for (size_t i = 0; i < elements; i += 1) {
    name_list[i] = cs1010_read_word();
    marks_array[i] = cs1010_read_long();
  }

  for (long i = 0; i <= 100; i += 1) {
    for (size_t j = 0; j < elements; j += 1) {
      if (marks_array[j] == i) {
        cs1010_print_long(i);
        cs1010_print_string(" ");
        cs1010_println_string(name_list[j]);
      }
    }
  }

  free(marks_array);
  for (size_t i = 0; i < elements; i += 1) {
    free(name_list[i]);
  }
}
```

</details>

#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `marks.c`. No warnings are generated. :confetti_ball:

#### Test Cases

- Your `marks` passes all test cases. :thumbsup:

#### Other Issues

- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex06-Ekko-Technology/commit/be48e234e6c7c5d362ad5201ed4a0d20c1fe6d6c).

## Summary
| Question | Achievement |
|----------|-------|
| [sort](#sort) | Excellent |
| [valley](#valley) | Excellent |
| [inversion](#inversion) | Need Improvement |
| [marks](#marks) | Need Improvement |

Note: The achievement badges for this exercise take the running time of your solution into consideration.  See [the grader's comments](https://www.github.com/nus-cs1010-2425-s1/ex06-Ekko-Technology/commit/be48e234e6c7c5d362ad5201ed4a0d20c1fe6d6c) for details.
