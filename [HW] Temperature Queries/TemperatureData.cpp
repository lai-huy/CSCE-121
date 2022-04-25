#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <limits>
#include <cstdlib>
#include <vector>
#include <ctime>

#include "TemperatureData.h"
using std::string, std::ostream, std::to_string;

TemperatureData::TemperatureData() : id{string()}, year{0}, month{0}, temperature{0} {} //initialize everything
TemperatureData::TemperatureData(string id, int year, int month, double temperature) : id{id}, year{year}, month{month}, temperature{temperature} {} //initialize everything
TemperatureData::~TemperatureData() {} // You should not need to implement this

bool TemperatureData::operator<(const TemperatureData& b) {
     // std::cout << "This:\t" << this->id << " " << std::to_string(this->year) << " " << std::to_string(this->month) << " " << std::to_string(this->temperature) << "\n";
     // std::cout << "That:\t" << b.id << " " << std::to_string(b.year) << " " << std::to_string(b.month) << " " << std::to_string(b.temperature) << "\n";
     
     if (this->id < b.id)
          return true;
     if (this->id > b.id)
          return false;
     if (this->year < b.year)
          return true;
     if (this->year > b.year)
          return false;
     if (this->month < b.month)
          return true;
     if (this->month > b.month)
          return false;
     if (this->temperature < b.temperature)
          return true;
     return false;
}

ostream& operator<<(ostream& os, const TemperatureData& rhs) {
     string flt = to_string(rhs.temperature);
     flt.erase(flt.find_last_not_of('0') + 1, string::npos);
     os << rhs.id << " " << to_string(rhs.year) << " " << to_string(rhs.month) << " " << flt;
     return os;
}
