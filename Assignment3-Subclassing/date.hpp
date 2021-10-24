#pragma once

class date {
  protected:
  int year;
  int month;
  int day;
  
  public:
  void set_date(int y, int m, int d);
  int get_year();
  int get_month();
  int get_day();
  date(int y, int m, int d); //convenience constructor
  date(); //default constructor
  ~date(); //destructor


  //methods required to implement
  int get_date_number();
  int get_day_of_week();
};
