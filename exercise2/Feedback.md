# CS1010 Exercise 2
## Feedback for Ekko-Technology
#### Submission
Link: https://www.github.com/nus-cs1010-2425-s1/ex02-Ekko-Technology/commit/b44480d2d185c0eb37dd68d2254c47833b9ab276

---
### lemon
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: Lemon
 *
 * @file: lemon.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

int main()
{
  long start = cs1010_read_long();
  long elements = cs1010_read_long();
  long step = cs1010_read_long();

  long count = 0;

  while (count < elements) {
    cs1010_println_long(start);
    start += step;
    count += 1;
  }
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `lemon.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `lemon` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex02-Ekko-Technology/commit/b44480d2d185c0eb37dd68d2254c47833b9ab276).

---
### factor
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: Factor
 *
 * @file: factor.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

long factor(long input)
{
  if (input <= 1) {
    return 0;
  }

  long count = 0;

  for (long i = 2; i < input; i += 1) {
    if (input % i == 0) {
      count += 1;
    }
  }

  return count;
}

int main()
{
  long input = cs1010_read_long();

  long value = factor(input);

  cs1010_println_long(value);
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `factor.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `factor` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex02-Ekko-Technology/commit/b44480d2d185c0eb37dd68d2254c47833b9ab276).

---
### parity
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: Parity
 *
 * @file: parity.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

void print_parity(long input)
{
  // TODO: The following line is a placeholder.  Replace it.
  long odd_count = 0;
  long even_count = 0;

  while (input > 0) {
    long last_digit = input % 10;

    if (last_digit % 2 == 0) {
      even_count += 1;
    } else {
      odd_count += 1;
    }

    input /= 10;
  }

  cs1010_print_string("odd: ");
  cs1010_println_long(odd_count);
  cs1010_print_string("even: ");
  cs1010_println_long(even_count);
}

// o main function.  The main function is defined concat-main.c
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `parity.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `parity` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex02-Ekko-Technology/commit/b44480d2d185c0eb37dd68d2254c47833b9ab276).

---
### nine
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: Nine
 *
 * @file: nine.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

long find_least_significant_9(long value)
{
  long index = 1;
  while (value > 1) {
    long last_digit = value % 10;

    if (last_digit == 9) {
      return index;
    }

    value /= 10;
    index += 1;
  }

  return 0;
}

int main()
{
  long value = cs1010_read_long();

  long result = find_least_significant_9(value);

  cs1010_println_long(result);
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `nine.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `nine` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex02-Ekko-Technology/commit/b44480d2d185c0eb37dd68d2254c47833b9ab276).

---
### hdb
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: HDB
 *
 * @file: hdb.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

void print_hdb(long length, long height)
{
  for (long i = 0; i < height; i += 1) {
    for (long j = 0; j < length; j += 1) {
      cs1010_print_string("#");
    }
    cs1010_println_string(" ");
  }
}

int main()
{
  long length = cs1010_read_long();
  long height = cs1010_read_long();

  print_hdb(length, height);
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `hdb.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `hdb` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex02-Ekko-Technology/commit/b44480d2d185c0eb37dd68d2254c47833b9ab276).

---
### binary
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: Binary
 *
 * @file: binary.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

long pow(long base, long power)
{
  long result = 1;
  if (power == 0) {
    return 1;
  }

  for (long i = 0; i < power; i += 1) {
    result *= base;
  }

  return result;
}

long find_decimal(long binary_value)
{
  long sum = 0;
  long count = 0;
  while (binary_value > 0) {
    if (binary_value % 10 == 1) {
      sum += pow(2, count);
      // cs1010_println_long(sum);
    }

    binary_value /= 10;
    count += 1;
  }

  return sum;
}

int main()
{
  long input = cs1010_read_long();
  long result = find_decimal(input);
  // cs1010_print_string("the decimal number is:");
  cs1010_println_long(result);
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` generate 1 (non-documentation-related) warnings for `binary.c`. Always fix your code so that it compiles cleanly without warnings.

<details>
<summary>Warnings from clang/clang-tidy</summary>

```
binary.c:10:6: warning: incompatible redeclaration of library function 'pow' [-Wincompatible-library-redeclaration]
```
</details>
What the warning/error messages from the compiler mean: (generated by an experimental AI and vetted by humans)

- **Incompatible Redeclaration of Library Function**: The warning indicates that the student has redeclared the `pow` function, which is a standard library function in C. The original `pow` function is defined to take two `double` arguments and return a `double`, while the student's version takes two `long` arguments and returns a `long`. This mismatch in the function signature leads to the warning.

  

- **Shadowing Built-in Functions**: By defining a function with the same name as a built-in library function, the student is shadowing the original `pow` function. This can lead to confusion and unexpected behavior in the program, as the compiler may not be able to distinguish between the two functions when they are called.

  

- **Potential Loss of Precision**: The student's implementation of `pow` using `long` types may lead to a loss of precision, especially when dealing with fractional powers or large numbers. The standard `pow` function is designed to handle a wider range of values and types, which is important for mathematical computations.

#### Test Cases
- Your `binary` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex02-Ekko-Technology/commit/b44480d2d185c0eb37dd68d2254c47833b9ab276).

---
### onigiri
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: Onigiri
 *
 * @file: onigiri.c
 * @author: Joshua Yeo(Group B03)
 */

#include "cs1010.h"

void draw_triangle(long row_height)
{

  for (long i = 1; i <= row_height; i += 1) {
    long hashes_to_print = 2 * (i - 1) + 1;
    // print left trailing white space
    for (long j = 1; j <= row_height - i; j += 1) {
      cs1010_print_string(" ");
    }
    // print hash symbols
    for (long k = 1; k <= hashes_to_print; k++) {

      cs1010_print_string("#");
    }
    // print right trailing white space
    for (long l = 1; l <= row_height - i; l += 1) {
      cs1010_print_string(" ");
    }
    cs1010_println_string("");
  }
}

int main()
{
  long height = cs1010_read_long();
  draw_triangle(height);
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` generate 1 (non-documentation-related) warnings for `onigiri.c`. Always fix your code so that it compiles cleanly without warnings.

<details>
<summary>Warnings from clang/clang-tidy</summary>

```
onigiri.c:11:6: warning: function 'draw_triangle' exceeds recommended size/complexity thresholds [readability-function-size]
```
</details>
What the warning/error messages from the compiler mean: (generated by an experimental AI and vetted by humans)

- **Function Size and Complexity**: The warning indicates that the function `draw_triangle` has exceeded the recommended size and complexity thresholds. Specifically, it contains 21 statements, while the threshold is set at 20. This suggests that the function may be doing too much, which can make it harder to read, maintain, and understand.

  
- **Readability Concerns**: A function that is too large can lead to decreased readability. When a function contains many statements, it becomes challenging for someone reading the code to quickly grasp its purpose and logic. This can hinder collaboration and debugging efforts.

  
- **Potential for Code Duplication**: Larger functions often contain repeated logic or similar code blocks. This can lead to code duplication, which is generally discouraged in programming as it increases the risk of errors and makes future changes more difficult.

  
- **Testing and Debugging Difficulty**: Functions that are overly complex can be harder to test and debug. If a function has many statements, isolating the source of an error or understanding the flow of execution can become cumbersome, leading to longer development times.

#### Test Cases
- Your `onigiri` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex02-Ekko-Technology/commit/b44480d2d185c0eb37dd68d2254c47833b9ab276).

---
### fibonacci
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: Fibonacci
 *
 * @file: fibonacci.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

long fibonacci(long n_index)
{
  long index1 = 1;
  long index2 = 1;
  long next_num;

  if (n_index <= 0) {
    cs1010_println_string("invalid input...returning 0");
    return 0;
  }

  if (n_index <= 2) {
    return 1;
  }

  for (long i = n_index - 2; i > 0; i -= 1) {
    next_num = index1 + index2;
    index1 = index2;
    index2 = next_num;
  }

  return next_num;
}

int main()
{
  long input = cs1010_read_long();

  long result = fibonacci(input);

  cs1010_println_long(result);

  return 0;
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `fibonacci.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `fibonacci` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex02-Ekko-Technology/commit/b44480d2d185c0eb37dd68d2254c47833b9ab276).

---
### collatz
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: Collatz
 *
 * @file: collatz.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"
#include <math.h>

long collatz(long input, long steps)
{
  long steps_taken = steps;

  // base case
  if (input == 1) {
    return steps_taken;
  }
  if (input % 2 == 0) {
    input /= 2;
  } else {
    input = 3 * input + 1;
  }

  // cs1010_println_long(input);
  steps_taken += 1;
  return collatz(input, steps_taken);
}

int main()
{
  long small_num = cs1010_read_long();
  long big_num = cs1010_read_long();

  long steps_taken = 0;
  long lengthy_num;
  for (long i = small_num; i <= big_num; i += 1) {
    long temp_steps = collatz(i, 0);
    if (temp_steps >= steps_taken) {
      steps_taken = temp_steps;
      lengthy_num = i;
    }
  }

  cs1010_println_long(steps_taken);
  cs1010_println_long(lengthy_num);
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `collatz.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `collatz` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex02-Ekko-Technology/commit/b44480d2d185c0eb37dd68d2254c47833b9ab276).

---
### rectangle
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: Rectangle
 *
 * @file: rectangle.c
 * @author: Joshua Yeo (Group B03)
 */

#include "cs1010.h"

#define TOP_LEFT "╔"
#define TOP_RIGHT "╗"
#define BOTTOM_RIGHT "╝"
#define BOTTOM_LEFT "╚"
#define HORIZONTAL "═"
#define VERTICAL "║"
#define WHITESPACE " "

void rectangle(long width, long height)
{
  // print top row
  cs1010_print_string(TOP_LEFT);
  for (long i = 0; i < width - 2; i += 1) {
    cs1010_print_string(HORIZONTAL);
  }
  cs1010_println_string(TOP_RIGHT);

  // middle rows
  for (long k = 0; k < height - 2; k += 1) {
    cs1010_print_string(VERTICAL);

    for (long l = 0; l < width - 2; l += 1) {
      cs1010_print_string(WHITESPACE);
    }
    cs1010_println_string(VERTICAL);
  }

  // print bottom row
  cs1010_print_string(BOTTOM_LEFT);
  for (long j = 0; j < width - 2; j += 1) {
    cs1010_print_string(HORIZONTAL);
  }
  cs1010_println_string(BOTTOM_RIGHT);
}

int main()
{
  long width = cs1010_read_long();
  long height = cs1010_read_long();
  rectangle(width, height);
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` generate 1 (non-documentation-related) warnings for `rectangle.c`. Always fix your code so that it compiles cleanly without warnings.

<details>
<summary>Warnings from clang/clang-tidy</summary>

```
rectangle.c:19:6: warning: function 'rectangle' exceeds recommended size/complexity thresholds [readability-function-size]
```
</details>
What the warning/error messages from the compiler mean: (generated by an experimental AI and vetted by humans)

- **Function Size and Complexity**: The warning indicates that the function `rectangle` has exceeded the recommended size and complexity thresholds. Specifically, it contains 25 statements, while the threshold is set at 20. This suggests that the function may be doing too much work, which can make it harder to read, understand, and maintain.

  

- **Readability Concerns**: A function that is too large can lead to decreased readability. When a function contains many statements, it becomes challenging for someone reading the code to quickly grasp its purpose and logic. This can also increase the likelihood of bugs and make debugging more difficult.

  

- **Potential for Code Duplication**: Larger functions often contain repeated logic or similar code blocks. This can lead to code duplication, which is generally discouraged in programming as it makes maintenance more cumbersome and increases the risk of inconsistencies.

  

- **Difficulty in Testing**: Functions that are too complex can be harder to test effectively. If a function has many responsibilities, it may not be clear how to isolate and test each part, which can lead to incomplete testing and undetected errors.

#### Test Cases
- Your `rectangle` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex02-Ekko-Technology/commit/b44480d2d185c0eb37dd68d2254c47833b9ab276).

---
### prime
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: Prime
 *
 * @file: prime.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"
#include <math.h>
#include <stdbool.h>

bool is_prime(long value)
{
  if (value < 2) {
    return false;
  }

  if (value == 2 || value == 3) {
    return true;
  }

  if (value % 2 == 0 || value % 3 == 0) {
    return false;
  }

  long start = 5;
  long step = 6;
  long limit = (long)sqrt((double)value);

  for (long i = start; i <= limit; i += step) {
    if (value % i == 0 || value % (i + 2) == 0) {
      return false;
    }
  }
  return true;
}

int main()
{
  long value = cs1010_read_long();

  while (!is_prime(value)) {
    value -= 1;
  }

  cs1010_println_long(value);
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` generate 1 (non-documentation-related) warnings for `prime.c`. Always fix your code so that it compiles cleanly without warnings.

<details>
<summary>Warnings from clang/clang-tidy</summary>

```
prime.c:28:22: warning: cast from function call of type 'double' to non-matching type 'long' [-Wbad-function-cast]
```
</details>
What the warning/error messages from the compiler mean: (generated by an experimental AI and vetted by humans)

- **Type Mismatch in Casting**: The warning indicates that there is a type mismatch when casting the result of the `sqrt` function. The `sqrt` function returns a `double`, but the code attempts to cast it directly to a `long`. This can lead to potential data loss or unexpected behavior since `long` and `double` represent different types of data.

  

- **Improper Use of Function Return Types**: The warning highlights that the function call to `sqrt` is being treated in a way that does not match its return type. In C, it is important to ensure that the types of variables and the return types of functions are compatible to avoid warnings and potential runtime errors.

  

- **Lack of Explicit Type Handling**: The warning suggests that there is a lack of explicit handling of the types involved in the operation. When performing mathematical operations or type conversions, it is crucial to be aware of the types being used to ensure that the program behaves as expected and to avoid warnings from the compiler.

#### Test Cases
- Your `prime` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex02-Ekko-Technology/commit/b44480d2d185c0eb37dd68d2254c47833b9ab276).

---
### pattern
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: Pattern
 *
 * @file: pattern.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"
#include <math.h>
#include <stdbool.h>

// leading cell from 1st row to h-th row (1, m, 1), (m + 1, m, 2), (3m + 1, m,
// 3), (6m + 1, m, 4), (10m + 1, m, 5) eseential take previous lead cell

// row_num corresponds to interval, m corresponds to interval

// drawing triangle full of hashes

long find_lead_cell(long row_num, long m)
{
  long num = 1;
  long counter = 1;
  while (counter < row_num) {
    num += counter * m;
    counter += 1;
  }

  return num;
}

bool is_prime(long value)
{
  if (value < 2) {
    return false;
  }

  if (value == 2 || value == 3) {
    return true;
  }

  if (value % 2 == 0 || value % 3 == 0) {
    return false;
  }

  // check if value is divisible by other prime numbers 5 and above

  long start = 5;
  long step = 6;
  long limit = (long)sqrt((double)value);

  for (long i = start; i <= limit; i += step) {
    if (value % i == 0 || value % (i + 2) == 0) {
      return false;
    }
  }
  return true;
}

bool contain_prime(long row, long col, long m)
{
  long lead_cell = find_lead_cell(row, m);
  lead_cell += col - 1;

  // iterate m times to check all elements within cell
  for (long i = 0; i < m; i += 1) {
    if (is_prime(lead_cell)) {
      return true;
    }
    lead_cell += row;
  }
  return false;
}

void draw_triangle(long m, long row_height)
{

  for (long i = 1; i <= row_height; i += 1) {
    long hashes_to_print = 2 * (i - 1) + 1;
    // print left trailing white space
    for (long j = 1; j <= row_height - i; j += 1) {
      cs1010_print_string(" ");
    }
    // print hash symbols
    for (long k = 1; k <= hashes_to_print; k++) {
      if (contain_prime(i, k, m)) {
        cs1010_print_string("#");
      } else {
        cs1010_print_string(".");
      }
    }
    // print right trailing white space
    for (long l = 1; l <= row_height - i; l += 1) {
      cs1010_print_string(" ");
    }
    cs1010_println_string("");
  }
}

int main()
{

  long interval = cs1010_read_long();
  long height = cs1010_read_long();

  draw_triangle(interval, height);
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` generate 2 (non-documentation-related) warnings for `pattern.c`. Always fix your code so that it compiles cleanly without warnings.

<details>
<summary>Warnings from clang/clang-tidy</summary>

```
pattern.c:49:22: warning: cast from function call of type 'double' to non-matching type 'long' [-Wbad-function-cast]
pattern.c:74:6: warning: function 'draw_triangle' exceeds recommended size/complexity thresholds [readability-function-size]
```
</details>
What the warning/error messages from the compiler mean: (generated by an experimental AI and vetted by humans)

- **Function Size/Complexity Warning**: The function `draw_triangle` has been flagged for exceeding the recommended size and complexity thresholds. It contains 24 statements, while the threshold is set at 20. This suggests that the function may be doing too much, which can make it harder to read and maintain.

  

- **Nesting Level Warning**: The code has a nesting level of 4, which exceeds the recommended threshold of 3. This indicates that there are too many nested control structures (like loops or conditionals) within the function, making the logic more complex and difficult to follow.

  

- **Type Casting Warning**: There is a warning regarding a type cast from a function call. The code attempts to cast the result of `sqrt`, which returns a `double`, to a `long`. This is problematic because the types do not match, and it can lead to potential data loss or unexpected behavior.

#### Test Cases
- Your `pattern` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex02-Ekko-Technology/commit/b44480d2d185c0eb37dd68d2254c47833b9ab276).

## Summary
| Question | Achievement |
|----------|-------|
| lemon | Excellent |
| factor | Excellent |
| parity | Excellent |
| nine | Excellent |
| hdb | Excellent |
| binary | Good |
| onigiri | Good |
| fibonacci | Excellent |
| collatz | Excellent |
| rectangle | Good |
| prime | Good |
| pattern | Good |
