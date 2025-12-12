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
