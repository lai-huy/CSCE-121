#ifndef NODE
#define NODE

#include <string>
#include <iostream>
#include "TemperatureData.h"

using std::string, std::ostream;

struct Node {
     Node* next;
     TemperatureData data;

     // Default constructor
     Node(); // remember to initialize next to nullptr
     Node(const Node& node);
     Node& operator=(const Node& node);
     Node(std::string id, int year, int month, double temperature); // remember to initialize next to nullptr

     // This operator will allow you to just ask if a node is smaller than another
     //  rather than looking at all of the location, temperature and date information
     bool operator<(const Node& b);

     friend ostream& operator<<(ostream& os, const Node& rhs);

     // The function below is written. Do not modify it
     virtual ~Node() {}
};

#endif
