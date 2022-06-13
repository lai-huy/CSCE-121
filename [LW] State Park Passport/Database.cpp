// Class file for Database class

#include "Database.h"
#include "StatePark.h"
#include "Passport.h"

using std::string, std::vector;

// Constructor
// Constructor for Database class
// TODO(student): implement constructor using member initializer list
Database::Database() : stateParkList{vector<StatePark*>()}, camperList{vector<Passport*>()} {}

// Destructor
// DO NOT CHANGE, ALREADY IMPLEMENTED
Database::~Database() {
     for (unsigned int i = 0; i < stateParkList.size(); ++i) {
          delete stateParkList.at(i);
     }

     for (unsigned int i = 0; i < camperList.size(); ++i) {
          delete camperList.at(i);
     }
}

// Mandatory
// Dynamically creates a new state park and adds it to stateParkList
void Database::addStatePark(string parkName, double entranceFee, double trailMiles) {
     INFO(parkName)
          INFO(entranceFee)
          INFO(trailMiles)
          // TODO(student): implement function

          this->stateParkList.push_back(new StatePark(parkName, entranceFee, trailMiles));
     return;
}

// Mandatory
// Dynamically creates a new passport and adds it to camperList
void Database::addPassport(string camperName, bool isJuniorPassport) {
     INFO(camperName)
          INFO(isJuniorPassport)
          // TODO(student): implement function
          this->camperList.push_back(new Passport(camperName, isJuniorPassport));
     return;
}

// Mandatory
// Searches for a passport and state park whose name matches the given parameters and
// adds the park to the passport
void Database::addParkToPassport(string camperName, string parkName) {
     INFO(camperName)
          INFO(parkName)
          Passport* camper = nullptr;
     StatePark* park = nullptr;

     for (Passport* p : this->camperList) {
          if (p->getCamperName() == camperName) {
               camper = p;
               break;
          }
     }

     for (StatePark* p : this->stateParkList) {
          if (p->getParkName() == parkName) {
               park = p;
               break;
          }
     }

     camper->addParkVisited(park);
     return;
}

// Option A
// Returns a vector of the names of all the parks whose revenue is between the parameters
// given (including the boundaries)
vector<string> Database::getParksInRevenueRange(double lowerBound, double upperBound) {
     INFO(lowerBound)
          INFO(upperBound)
          // TODO(student): implement function

          vector<string> temp;

     for (StatePark* park : this->stateParkList) {
          double rev = park->getRevenue();
          if (lowerBound <= rev && rev <= upperBound)
               temp.push_back(park->getParkName());
     }

     return temp;
}

// Option B
// Returns a vector of the names of all the campers who have reached at least the hiking
// level given by the parameter
vector<string> Database::getHikersAtLeastLevel(int level) {
     INFO(level)
          // TODO(student): implement function

          vector<string> temp;

     for (Passport* camper : this->camperList) {
          if (camper->getHikerLevel() >= level)
               temp.push_back(camper->getCamperName());
     }

     return temp;
}