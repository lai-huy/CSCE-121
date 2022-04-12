// Header file for StatePark class

#ifndef _STATEPARK_H
#define _STATEPARK_H

#include <string>
#include <vector>
#include <iostream>

#define INFO(X) std::cout << "[INFO] ("<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " = " << X << std::endl;

// Need to forward declare Passport class
class Passport;

// Class definition for StatePark class
class StatePark {
	std::string parkName;
	double entranceFee;
	double trailMiles;
	std::vector<Passport*> camperLog;
public:
	StatePark(std::string parkName, double entranceFee, double trailMiles);
	std::string getParkName();
	double getEntranceFee();
	double getTrailMiles();
	void addCamper(Passport* camper);
	double getRevenue();
};

#endif