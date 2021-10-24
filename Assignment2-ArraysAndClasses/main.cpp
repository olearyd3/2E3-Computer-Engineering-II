#include <iostream>
#include "date.hpp"

using namespace std;

int main() {
  const int ARRAYSIZE = 20;
  int daynum_array[ARRAYSIZE];
  date datearray[ARRAYSIZE];
  int amount = 0;
  cout << "Enter the dates in year month day format, one per line. To finish, enter the date 0 0 0." << endl;
  int y, m, d;
  cin >> y >> m >> d;
  //account for a sentinel of y, m, d being 0.
  while(y != 0 && m!= 0 && d !=0) {
    if(amount < ARRAYSIZE) {
      datearray[amount] = date(y, m, d);
      daynum_array[amount] = datearray[amount].get_date_number();
      amount++;
      cin >> y >> m >> d;
    }
    else {
      cout << "ERROR: Array overflow!";
    }
  }
  //sorting the array in ascending order and including the daynumbers
  date mydate;
  mydate.sort_array(amount, datearray, daynum_array);
  
  //printing out the answers
  for(int i = 0; i < amount; i++) {
    datearray[i].print_diagnostics();
    cout << daynum_array[i] << endl; 
  }

  return 0;
}
