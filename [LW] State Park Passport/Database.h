// Header file for Database class

#ifndef _DATABASE_H
#define _DATABASE_H

#include "Passport.h"

// Class definition for Database class
class Database {
	std::vector<StatePark*> stateParkList;
	std::vector<Passport*> camperList;
	
public:
	Database();
	~Database();
	void addStatePark(std::string parkName, double entranceFee, double trailMiles);
	void addPassport(std::string camperName, bool isJuniorPassport);
	void addParkToPassport(std::string camperName, std::string parkName);
	std::vector<std::string> getParksInRevenueRange(double lowerBound, double upperBound);
	std::vector<std::string> getHikersAtLeastLevel(int level);
};

#endif