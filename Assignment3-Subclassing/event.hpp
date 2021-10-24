#pragma once
#include <string>
#include "date.hpp"


class event: public date {
  private:
  std::string descr;

  public:
  event();
  ~event();

  std::string set_description(std::string description);
  std::string get_description();
  
};
