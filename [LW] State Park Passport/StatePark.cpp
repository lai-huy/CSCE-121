// Class file for StatePark class

#include "Passport.h"

using std::string, std::vector;

// Mandatory
// Constructor for StatePark class
// TODO(student): implement constructor using member initializer list
StatePark::StatePark(std::string parkName, double entranceFee, double trailMiles) : parkName{parkName}, entranceFee{entranceFee}, trailMiles{trailMiles}, camperLog{vector<Passport *>()} {}

// Mandatory
// Getter for data member parkName
string StatePark::getParkName()
{
     // TODO(student): implement getter
     return this->parkName;
}

// Mandatory
// Getter for data member entranceFee
double StatePark::getEntranceFee()
{
     // TODO(student): implement getter
     return this->entranceFee;
}

// Mandatory
// Getter for data member trailMiles
double StatePark::getTrailMiles()
{
     // TODO(student): implement getter
     return this->trailMiles;
}

// Mandatory
// Adds a camper (represented by Passport object) to data member camperLog
void StatePark::addCamper(Passport *camper)
{
     INFO(camper)
     // TODO(student): implement function
     this->camperLog.push_back(camper);
     return;
}

// Option A
// Calculates the park revenue based on the campers in camperLog
double StatePark::getRevenue()
{
     return this->entranceFee * this->camperLog.size();
}