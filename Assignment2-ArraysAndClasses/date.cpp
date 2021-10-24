#include <iostream>
#include "date.hpp"

using namespace std;

bool is_a_leap_year(int y);

date::date(int y, int m, int d) {
  year = y;
  month = m;
  day = d;
}

date::date() {

}

date::~date() {

}

int date::get_date_number() {
  //days due to completed years 
  int accumulated_days = (year - 2000) * 365;
  //days due to completed!! leap years
  for (int ty = 2000 ; ty < year; ty++) {
    if (is_a_leap_year(ty)) {
      accumulated_days++;
    }
  }
  
  //capture the real world data for month lengths
  int month_length[] = {31,28,31,30,31,30,31,31,30,31,30,31};
  for (int mt = 0; mt < month - 1; mt++) {
    accumulated_days += month_length[mt];
  }

  //deal with the possibility that the date is in a leap year and that it is February or later.

  if ((is_a_leap_year(year)) && (month > 2)) {
    accumulated_days++;
  }

  accumulated_days += day-1;

  return accumulated_days;
}

int date::get_day_of_week() {
  return 0; 
}

//to print the year month and day
void date::print_diagnostics() {
  cout << year << " " << month << " " << day << " ";
}

//function to take leap years into account
bool is_a_leap_year(int y) {
  bool r = false;
  if ((y % 4) == 0) {
    r = true;
  }
  if ((y % 100) == 0) {
    r = false;
  }
  if ((y % 400) == 0) {
    r = true;
  }
  return r;
}

//function to sort the date array in ascending order
void date::sort_array(int number, date date_arr[], int daynum_arr[]) {
  for (int starting_point = 0; starting_point < number; starting_point++) {
      int index_of_smallest = starting_point;
      date temporary_date = date_arr[index_of_smallest];
      int smallest_so_far = daynum_arr[index_of_smallest];
      for (int i = starting_point+1; i <number ; i++) {
        if (daynum_arr[i] < smallest_so_far) {
          smallest_so_far = daynum_arr[i];
          index_of_smallest = i;
          temporary_date = date_arr[i];
        }
      }
            
    daynum_arr[index_of_smallest] = daynum_arr[starting_point];
    date_arr[index_of_smallest] = date_arr[starting_point];

    daynum_arr[starting_point] = smallest_so_far;
    date_arr[starting_point] = temporary_date;
  }
}  
