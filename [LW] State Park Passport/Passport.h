// Header file for Passport class

#ifndef _PASSPORT_H
#define _PASSPORT_H

#include "StatePark.h"

// Class definition for Passport class
class Passport {
	std::string camperName;
	bool isJuniorPassport;
	std::vector<StatePark*> parksVisited;
	
	double getMilesHiked();
public:
	Passport(std::string camperName, bool isJuniorPassport);
	std::string getCamperName();
	bool checkJuniorPassport();
	void addParkVisited(StatePark* park);
	int getHikerLevel();
};

#endif