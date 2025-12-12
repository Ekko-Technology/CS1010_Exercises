# CS1010 Exercise 3
## Feedback for Ekko-Technology
#### Submission
Link: https://www.github.com/nus-cs1010-2425-s1/ex03-Ekko-Technology/commit/f38ea867fbca35205ec4b594ea5e5ef458907f5c

---
### counter
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 3: Counter
 *
 * @file: counter.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

void counter(long number)
{
  if (number == 0) {
    cs1010_print_long(0);
    cs1010_print_string(": ");
    cs1010_println_long(1);
  } else {
    long list[10] = {0};
    while (number > 0) {
      long last_digit = number % 10;
      list[last_digit] += 1;
      number /= 10;
    }
    for (long i = 0; i < 10; i += 1) {
      if (list[i] != 0) {
        cs1010_print_long(i);
        cs1010_print_string(": ");
        cs1010_println_long(list[i]);
      }
    }
  }
}

int main()
{
  long number = cs1010_read_long();

  counter(number);
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `counter.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `counter` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex03-Ekko-Technology/commit/f38ea867fbca35205ec4b594ea5e5ef458907f5c).

---
### dot
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 3: Dot
 *
 * @file: dot.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

long result(long a[], long b[])
{
  long result = 0;
  for (long i = 0; i < 4; i += 1) {
    result += (a[i] * b[i]);
  }
  return result;
}

int main()
{
  long a[4] = {0};
  long b[4] = {0};
  for (long i = 0; i < 4; i += 1) {
    a[i] = cs1010_read_long();
  }
  for (long j = 0; j < 4; j += 1) {
    b[j] = cs1010_read_long();
  }

  cs1010_println_long(result(a, b));
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `dot.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `dot` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex03-Ekko-Technology/commit/f38ea867fbca35205ec4b594ea5e5ef458907f5c).

---
### unit
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 3: Unit
 *
 * @file: unit.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"
#include <math.h>

void find_unit_vector(const long v[3], double unit[3])
{
  long sum = 0;
  for (long i = 0; i < 3; i += 1) {
    sum += (v[i] * v[i]);
  }

  double average = sqrt((double)sum);

  for (long j = 0; j < 3; j += 1) {
    unit[j] = (1.0 / average) * (double)v[j];
    cs1010_println_double(unit[j]);
  }
}

int main()
{
  long vector[3] = {0};
  double unit_vector[3] = {0};
  for (long i = 0; i < 3; i++) {
    vector[i] = cs1010_read_long();
  }

  find_unit_vector(vector, unit_vector);
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `unit.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `unit` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex03-Ekko-Technology/commit/f38ea867fbca35205ec4b594ea5e5ef458907f5c).

---
### largest
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 3: Largest
 *
 * @file: largest.c
 * @author: Joshua Yeo (Group B03)
 */

#include "cs1010.h"

long find_largest(long n)
{
  long count[10] = {0};

  bool positive = true;
  if (n < 0) {
    positive = false;
    n -= (2 * n);
  }

  while (n != 0) {
    count[n % 10] += 1;
    n /= 10;
  }
  // cs1010_println_long(count[2]);

  // assert that n = 0
  // checks if input was a positive
  if (positive) {
    for (long i = 9; i >= 0; i -= 1) {
      while (count[i] > 0) {
        n = n * 10 + i;
        count[i] -= 1;
        // cs1010_println_long(n);
      }
    }
  }
  // counts for negative values
  else {
    for (long i = 1; i < 10; i += 1) {
      while (count[i] > 0) {
        n = n * 10 - i;
        count[i] -= 1;
      }
    }
  }
  return n;
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `largest.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `largest` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex03-Ekko-Technology/commit/f38ea867fbca35205ec4b594ea5e5ef458907f5c).

---
### days
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 3: Days
 *
 * @file: days.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

int main()
{
  long month = cs1010_read_long();

  long days = cs1010_read_long();

  long days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  for (long i = 0; i < month - 1; i += 1) {
    days += days_in_month[i];
  }

  cs1010_println_long(days);
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `days.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `days` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex03-Ekko-Technology/commit/f38ea867fbca35205ec4b594ea5e5ef458907f5c).

---
### id
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 3: ID
 *
 * @file: id.c
 * @author: Joshua Yeo (Group YYY)
 */
#include "cs1010.h"

int main()
{
  long value = cs1010_read_long();

  long sum = 0;

  while (value > 0) {
    sum += value % 10;
    value /= 10;
  }

  long remainder = sum % 13;

  char table[13] = {'Y', 'X', 'W', 'U', 'R', 'N', 'M',
                    'L', 'J', 'H', 'E', 'A', 'B'};

  putchar(table[remainder]);
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `id.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `id` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex03-Ekko-Technology/commit/f38ea867fbca35205ec4b594ea5e5ef458907f5c).

---
### max
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 3: Max
 *
 * @file: max.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

long find_max(const long list[], long start, long end)
{
  // TODO: The following line is a placeholder.  Replace it.

  if (start == end - 1) {
    return list[start];
  }

  // binary search

  long mid = (start + end) / 2;
  long max_left = find_max(list, start, mid);
  long max_right = find_max(list, mid, end);

  if (max_left > max_right) {
    return max_left;
  }
  return max_right;
}

// No main function.  The main function is defined concat-main.c
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `max.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `max` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex03-Ekko-Technology/commit/f38ea867fbca35205ec4b594ea5e5ef458907f5c).

---
### padovan
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 3: Padovan
 *
 * @file: padovan.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

void padovan(long number)
{
  long first = 1;
  long second = 0;
  long third = 0;

  long list_of_hundred[100] = {0};

  for (long i = 2; i < number - 98; i += 1) {
    long new_element = (second + first) % 10000;

    first = second;
    second = third;
    third = new_element;
  }

  list_of_hundred[0] = first;
  list_of_hundred[1] = second;
  list_of_hundred[2] = third;

  for (long i = 3; i < 100; i += 1) {
    long new_element =
        (list_of_hundred[i - 3] + list_of_hundred[i - 2]) % 10000;
    list_of_hundred[i] = new_element;
  }

  //  cs1010_print_string("the last element in the list is:");
  //  cs1010_println_long(list_of_hundred[99]);

  for (long i = 99; i >= 0; i -= 1) {
    cs1010_println_long(list_of_hundred[i]);
  }
}

int main()
{
  long degree = cs1010_read_long();

  padovan(degree);
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `padovan.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `padovan` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex03-Ekko-Technology/commit/f38ea867fbca35205ec4b594ea5e5ef458907f5c).

## Summary
| Question | Achievement |
|----------|-------|
| [counter](#counter) | Excellent |
| [dot](#dot) | Excellent |
| [unit](#unit) | Excellent |
| [largest](#largest) | Excellent |
| [days](#days) | Excellent |
| [id](#id) | Excellent |
| [max](#max) | Excellent |
| [padovan](#padovan) | Excellent |
