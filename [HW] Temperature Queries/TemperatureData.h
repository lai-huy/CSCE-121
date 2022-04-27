#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <limits>
#include <cstdlib>
#include <vector>
#include <ctime>

using std::string;
using std::ostream;

#ifndef TEMPERATUREDATA
#define TEMPERATUREDATA

struct TemperatureData {
     /**
      * @brief location data was recorded
      */
     string id;

     /**
      * @brief year data was recorded
      */
     int year;

     /**
      * @brief year month was recorded
      */
     int month;

     /**
      * @brief temperature that was recorded
      */
     double temperature;
     
     /**
      * @brief Default constructor
      */
	TemperatureData();
     
     /**
      * @brief Construct a new Temperature Data object
      * 
      * @param id             where data was recorded
      * @param year           what year data was recorded
      * @param month          what month data was recorded
      * @param temperature    the temperature recorded
      */
	TemperatureData(string id, int year, int month, double temperature);

     /**
      * @brief Destructor
      */
	virtual ~TemperatureData();

     /**
      * @brief compares this data to b
      * 
      * @param b         other data
      * @return true     this->id is alphebetically before b.id.
      *                  Then this->year < b.year.
      *                  Then this->month < b.month.
      *                  Then this->temperature < b.temperature
      * @return false    otherwise
      */
	bool operator<(const TemperatureData& b);
     
     friend ostream& operator<<(ostream& os, const TemperatureData& rhs);
};

#endif /* TEMPERATUREDATA */
