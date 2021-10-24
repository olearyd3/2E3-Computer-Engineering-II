#include <iostream>
#include <string>
#include "event.hpp"

using namespace std;

void sort_array(int number, date date_arr[], int daynum_arr[], event event_arr[]);

int main() {
  const int ARRAYSIZE = 20;
  int daynum_array[ARRAYSIZE];
  date datearray[ARRAYSIZE];
  event eventarray[ARRAYSIZE];
  int amount = 0;
  string description;
  cout << "Enter the events in year month day:description format, one per line. To finish, enter the date 0 0 0." << endl;
  int y, m, d;
  cin >> y >> m >> d;
  //account for a sentinel of y, m, d being 0.
  while(y != 0 && m!= 0 && d !=0) {
    cin.ignore(1);
    getline(cin, description);
    if(amount < ARRAYSIZE) {
      datearray[amount] = date(y, m, d);
      daynum_array[amount] = datearray[amount].get_date_number();
      eventarray[amount].set_description(description);
      amount++;
      cin >> y >> m >> d;   
    }
    else {
      cout << "ERROR: Array overflow!";
    }
  }
  //sorting the array in ascending order and including the events
  sort_array(amount, datearray, daynum_array, eventarray);
  
  //printing out the results in ascending order
   for (int i = 0; i < amount; i++) {
    cout << datearray[i].get_year() << " " << datearray[i].get_month() << " " << datearray[i].get_day() << " " << eventarray[i].get_description() << endl;
  }


  return 0;
}

//function to sort in ascending order
void sort_array(int number, date date_arr[], int daynum_arr[], event event_arr[]) {
  for (int starting_point = 0; starting_point < number; starting_point++) {
      int index_of_smallest = starting_point;
      date temporary_date = date_arr[index_of_smallest];
      event temp_event = event_arr[index_of_smallest];
      int smallest_so_far = daynum_arr[index_of_smallest];
      for (int i = starting_point+1; i <number ; i++) {
        if (daynum_arr[i] < smallest_so_far) {
          smallest_so_far = daynum_arr[i];
          index_of_smallest = i;
          temporary_date = date_arr[i];
          temp_event = event_arr[i];
        }
      }
            
    daynum_arr[index_of_smallest] = daynum_arr[starting_point];
    date_arr[index_of_smallest] = date_arr[starting_point];
    event_arr[index_of_smallest] = event_arr[starting_point];

    daynum_arr[starting_point] = smallest_so_far;
    date_arr[starting_point] = temporary_date;
    event_arr[starting_point] = temp_event;
  }
}  
