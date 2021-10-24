#include <iostream>
#include "event.hpp"

using namespace std;

//default constructor
event::event() {

}

//destructor
event::~event() {

}

string event::set_description(string description) {
  descr = description;
  return descr;
}

string event::get_description() {
  return descr;
}
