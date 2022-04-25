#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <limits>
#include <cstdlib>
#include <vector>
#include <ctime>

using std::string, std::ostream;

#ifndef TEMPERATUREDATA
#define TEMPERATUREDATA

struct TemperatureData {
     string id;
     int year;
     int month;
     double temperature;
     
	TemperatureData();
	TemperatureData(string id, int year, int month, double temperature);
	virtual ~TemperatureData();
	bool operator<(const TemperatureData& b);
     friend ostream& operator<<(ostream& os, const TemperatureData& rhs);
};

#endif /* TEMPERATUREDATA */
