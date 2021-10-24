#pragma once

class date {
  private:
  int year;
  int month;
  int day;
  
  public:
  date(int y, int m, int d); //convenience constructor
  date(); //default constructor
  ~date(); //destructor

  void print_diagnostics();
  void sort_array(int number, date date_arr[], int daynum_arr[]);
  //methods we are required to implement
  int get_date_number();
  int get_day_of_week();
};
