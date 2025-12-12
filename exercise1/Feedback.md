# CS1010 Exercise 1
## Feedback for Ekko-Technology
#### Submission
Link: https://www.github.com/nus-cs1010-2425-s1/ex01-Ekko-Technology/commit/187c01ecb82895f3902bcee478dd5466289e41f7

---
### odd
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: Odd
 *
 * @file: odd.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

long find_next_odd(long next_odd)
{
  if (next_odd % 2 == 1 || next_odd % 2 == -1) {
    next_odd += 2;
  } else {
    next_odd += 1;
  }

  return next_odd;
}

int main()
{
  long next_odd = cs1010_read_long();

  // test for odd
  cs1010_println_long(find_next_odd(next_odd));
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `odd.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `odd` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex01-Ekko-Technology/commit/187c01ecb82895f3902bcee478dd5466289e41f7).

---
### sum
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: Sum
 *
 * @file: sum.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"
#include <stdbool.h>

long positive_num(long number)
{
  if (number <= 0) {
    return 0;
  }

  return number;
}

long compute_sum_if_positive(long x, long y)
{
  long summation;

  summation = positive_num(x) + positive_num(y);

  return summation;
}

int main()
{
  long x = cs1010_read_long();

  long y = cs1010_read_long();

  cs1010_println_long(compute_sum_if_positive(x, y));
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `sum.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `sum` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex01-Ekko-Technology/commit/187c01ecb82895f3902bcee478dd5466289e41f7).

---
### candy
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: Candy
 *
 * @file: candy.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"
#include <math.h>

unsigned long compute_num_of_boxes(unsigned long num_of_candies,
                                   unsigned long max_candies_per_box)
{
  unsigned long max_boxes;

  max_boxes = num_of_candies / max_candies_per_box;
  if (num_of_candies % max_candies_per_box != 0) {
    max_boxes += 1;
  }

  return max_boxes;
}

// No main function.  The main function is defined concat-main.c
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `candy.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `candy` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex01-Ekko-Technology/commit/187c01ecb82895f3902bcee478dd5466289e41f7).

---
### triangle
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: Triangle
 *
 * @file: triangle.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

bool is_possible_triangle(long x, long y, long z)
{
  // find the two smallest side
  long longest, sum_smaller;
  if (x > y && x > z) {
    longest = x;
    sum_smaller = y + z;
  } else if (y > x && y > z) {
    longest = y;
    sum_smaller = x + z;
  } else {
    longest = z;
    sum_smaller = x + y;
  }

  if (sum_smaller > longest) {
    return true;
  }
  return false;
}

double compute_area(long a, long b, long c)
{
  double x = (double)(b - a + c);
  double y = (double)(a - b + c);
  double z = (double)(b - c + a);
  // printf("the value of x is %f\n", x);
  // printf("the value of y is %f\n", y);
  // printf("the value of z is %f\n", z);

  double s = 1.0 / 16.0 * (double)(a + b + c);
  // printf("the value of s is %f\n", s);

  double area = sqrt(s * x * y * z);
  return area;
}

int main()
{
  long x = cs1010_read_long();
  long y = cs1010_read_long();
  long z = cs1010_read_long();

  if (is_possible_triangle(x, y, z)) {
    cs1010_println_string("Possible");

    double area = compute_area(x, y, z);
    cs1010_println_double(area);
  } else {
    cs1010_println_string("Impossible");
  }
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `triangle.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `triangle` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex01-Ekko-Technology/commit/187c01ecb82895f3902bcee478dd5466289e41f7).

---
### leap
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: Leap
 *
 * @file: leap.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"
#include <stdbool.h>

// except for years divisible by 100 but not by 400
bool exception(long year)
{
  if (year % 100 == 0 && year % 400 != 0) {
    return false;
  }
  return true;
}

bool is_leap_year(long year)
{
  if (year % 4 == 0 && exception(year)) {
    return true;
  }
  return false;
}

int main()
{
  long year = cs1010_read_long();

  cs1010_print_long(year);

  if (is_leap_year(year)) {
    cs1010_println_string(" is a leap year");
  } else {
    cs1010_println_string(" is not a leap year");
  }
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `leap.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `leap` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex01-Ekko-Technology/commit/187c01ecb82895f3902bcee478dd5466289e41f7).

---
### multiple
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: Multiple
 *
 * @file: multiple.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"
#include <stdbool.h>

bool is_multiple(long num1, long num2)
{
  if (num1 == 0 || num2 == 0) {
    return true;
  }

  long big_num, small_num;

  if (num1 > num2) {
    big_num = num1;
    small_num = num2;
  } else {
    big_num = num2;
    small_num = num1;
  }

  if (big_num % small_num == 0) {
    return true;
  }
  return false;
}

int main()
{
  long x = cs1010_read_long();
  long y = cs1010_read_long();

  if (is_multiple(x, y)) {
    cs1010_println_string("true");
  } else {
    cs1010_println_string("false");
  }
  return 0;
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `multiple.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `multiple` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex01-Ekko-Technology/commit/187c01ecb82895f3902bcee478dd5466289e41f7).

---
### date
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: Date
 *
 * @file: date.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

long month_to_days(long month, long days)
{

  long total = month * 30 + days;

  return total;
}

int main()
{
  long m1, d1;
  long m2, d2;
  long m3, d3;

  m1 = cs1010_read_long();
  d1 = cs1010_read_long();
  // if (m1 < 1 || m1 > 12 || d1 < 1 || d1 > 31){
  //    return -1;
  //}
  long days_1 = month_to_days(m1, d1);

  m2 = cs1010_read_long();
  d2 = cs1010_read_long();
  // if (m2 < 1 || m2 > 12 || d2 < 1 || d2 > 31){
  //    return -1;
  // }
  long days_2 = month_to_days(m2, d2);

  m3 = cs1010_read_long();
  d3 = cs1010_read_long();
  // if (m3 < 1 || m3 > 12 || d3 < 1 || d3 > 31){
  //   return -1;
  //}
  long days_3 = month_to_days(m3, d3);

  if (days_2 > days_1 && days_3 > days_2) {
    cs1010_println_string("yes");
  } else {
    cs1010_println_string("no");
  }

  return 0;
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `date.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `date` fails to pass 1 of the test cases.
- Hidden test cases that cause your `date` to fail include the following:
```
8 31 9 1 9 2
```
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex01-Ekko-Technology/commit/187c01ecb82895f3902bcee478dd5466289e41f7).

---
### pressure
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: Pressure
 *
 * @file: pressure.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

void print_blood_pressure(long systolic, long diastolic)
{
  if (systolic >= 140 || diastolic >= 90) {
    cs1010_println_string("high");
  } else if (systolic >= 120 || diastolic >= 80) {
    cs1010_println_string("pre-high");
  } else if (systolic >= 90 || diastolic >= 60) {
    cs1010_println_string("ideal");
  } else if (systolic >= 70 || diastolic >= 40) {
    cs1010_println_string("low");
  }
}

int main()
{
  long systolic = cs1010_read_long();
  long diastolic = cs1010_read_long();
  print_blood_pressure(systolic, diastolic);
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `pressure.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `pressure` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex01-Ekko-Technology/commit/187c01ecb82895f3902bcee478dd5466289e41f7).

---
### gcd
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: GCD
 *
 * @file: gcd.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

long compute_gcd(long a, long b)
{
  // TODO: Replcae the following placeholder with
  // the code to compute GCD
  if (b == 0) {
    return a;
  }
  long new_a = b;
  long new_b = a % b;
  return compute_gcd(new_a, new_b);
}

int main()
{
  long a = cs1010_read_long();
  long b = cs1010_read_long();
  cs1010_println_long(compute_gcd(a, b));
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `gcd.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `gcd` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex01-Ekko-Technology/commit/187c01ecb82895f3902bcee478dd5466289e41f7).

---
### digits
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: Digits
 *
 * @file: digits.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"
#include <stdio.h>

long sum_of_digits_cubed(long remainder)
{
  if (remainder == 0) {
    return 0;
  }

  long digit = remainder % 10;

  long sum = (digit * digit * digit);

  remainder /= 10;

  return sum + sum_of_digits_cubed(remainder);
}

int main()
{
  long input = cs1010_read_long();

  cs1010_println_long(sum_of_digits_cubed(input));

  return 0;
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `digits.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `digits` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex01-Ekko-Technology/commit/187c01ecb82895f3902bcee478dd5466289e41f7).

---
### power
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: Power
 *
 * @file: power.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

long compute_power(long base, long pow)
{

  if (base == 0) {
    return 0;
  }

  if (pow == 0) {
    return 1;
  }

  return base * compute_power(base, pow - 1);
}

int main()
{

  long x = cs1010_read_long();
  long y = cs1010_read_long();

  cs1010_println_long(compute_power(x, y));
  return 0;
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `power.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `power` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex01-Ekko-Technology/commit/187c01ecb82895f3902bcee478dd5466289e41f7).

---
### suffix
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: Suffix
 *
 * @file: suffix.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"

void print_with_suffix(long n)
{
  long last_digit = n % 10;

  long last_2_digits = n % 100;

  cs1010_print_long(n);

  // numbers ending with 1
  if (last_digit == 1 && last_2_digits != 11) {
    cs1010_println_string("st");
  }
  // numbers ending with 2
  else if (last_digit == 2 && last_2_digits != 12) {
    cs1010_println_string("nd");
  }
  // numbers ending wiht 3
  else if (last_digit == 3 && last_2_digits != 13) {
    cs1010_println_string("rd");
  }
  // all other numbers
  else {
    cs1010_println_string("th");
  }
}

int main()
{
  long input = cs1010_read_long();

  print_with_suffix(input);

  return 0;
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `suffix.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `suffix` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex01-Ekko-Technology/commit/187c01ecb82895f3902bcee478dd5466289e41f7).

---
### taxi
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: Taxi
 *
 * @file: taxi.c
 * @author: Joshua Yeo (Group B03)
 */
#include "cs1010.h"
#include <math.h>
#include <stdbool.h>

// return true if it is a weekday
bool check_date(long index_day)
{
  if (index_day > 0 && index_day < 6) {
    return true;
  }
  return false;
}

// check time of boarding:
// check if its midnight, morning or evening period
bool morning_period(long hour, long min)
{
  if ((hour >= 6 && hour < 9) || (hour == 9 && min < 30)) {
    // cs1010_println_string("morning period it is");
    return true;
  }
  return false;
}

bool evening_period(long hour)
{
  if (hour >= 18 && hour <= 23) {
    return true;
  }
  return false;
}

bool midnight_period(long hour)
{
  if (hour >= 0 && hour <= 5) {
    return true;
  }
  return false;
}

double meter_fare(long distance)
{
  double price = 3.90;
  long multiples;

  if (distance <= 1000) {
    return price;
  }

  distance -= 1000;

  // if distance is within the 10km threshold
  if (distance < 9000) {
    multiples = (long)ceil((double)distance / 400);
    price += (double)multiples * 0.24;
    return price;
  }
  distance -= 9000;
  price += 23 * 0.24;

  multiples = (long)ceil((double)distance / 350);
  // cs1010_println_long(multiples);
  price += (double)multiples * 0.24;

  return price;
}

double meter_fare_final(double price, long day, long hour, long minutes)
{
  if ((evening_period(hour)) ||
      (check_date(day) && morning_period(hour, minutes))) {
    return price + 0.25 * price;
  }
  if (midnight_period(hour)) {
    return price + 0.50 * price;
  }

  return price;
}

int main()
{
  long day = cs1010_read_long();
  long hour = cs1010_read_long();
  long minutes = cs1010_read_long();
  long distance = cs1010_read_long();

  double price_before_surcharge = meter_fare(distance);

  double price_after_surcharge =
      meter_fare_final(price_before_surcharge, day, hour, minutes);

  cs1010_println_double(price_after_surcharge);

  return 0;
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` generate 2 (non-documentation-related) warnings for `taxi.c`. Always fix your code so that it compiles cleanly without warnings.

<details>
<summary>Warnings from clang/clang-tidy</summary>

```
taxi.c:61:23: warning: cast from function call of type 'double' to non-matching type 'long' [-Wbad-function-cast]
taxi.c:68:21: warning: cast from function call of type 'double' to non-matching type 'long' [-Wbad-function-cast]
```
</details>
What the warning/error messages from the compiler mean: (generated by an experimental AI and vetted by humans)

- **Type Mismatch in Casting**: The warnings indicate that there is a type mismatch when casting the result of the `ceil` function. The `ceil` function returns a `double`, but it is being cast to a `long`. This can lead to potential data loss or unexpected behavior since `long` cannot accurately represent all possible values of a `double`.

  

- **Function Return Type Awareness**: The warnings highlight the importance of understanding the return types of functions. In this case, `ceil` is designed to return a `double`, and casting it directly to a different type without considering the implications can lead to issues in the program's logic and correctness.

  

- **Division Result Type**: The expression `(double)distance / 400` ensures that the division is performed in floating-point arithmetic. However, the subsequent casting of the result of `ceil` to `long` may not align with the intended use of the result, especially if the original division yields a non-integer value. This can create confusion about the expected data type throughout the calculations.

#### Test Cases
- Your `taxi` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex01-Ekko-Technology/commit/187c01ecb82895f3902bcee478dd5466289e41f7).

## Summary
| Question | Achievement |
|----------|-------|
| [odd](#odd) | Excellent |
| [sum](#sum) | Excellent |
| [candy](#candy) | Excellent |
| [triangle](#triangle) | Excellent |
| [leap](#leap) | Excellent |
| [multiple](#multiple) | Excellent |
| [date](#date) | Need Improvement |
| [pressure](#pressure) | Excellent |
| [gcd](#gcd) | Excellent |
| [digits](#digits) | Excellent |
| [power](#power) | Excellent |
| [suffix](#suffix) | Excellent |
| [taxi](#taxi) | Good |
