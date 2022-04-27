#ifndef NODE
#define NODE

#include <string>
#include <iostream>
#include "TemperatureData.h"

using std::string;
using std::ostream;

struct Node {
     /**
      * @brief Node* to the next node in the list
      */
     Node* next;

     /**
      * @brief TemperatureData this node contains
      */
     TemperatureData data;

     /**
      * @brief Default constructor
      */
     Node();

     /**
      * @brief Copy constructor
      * 
      * @param node to copy from
      */
     Node(const Node& node);

     /**
      * @brief Copy assignment operator
      * 
      * @param node      to copy from
      * @return Node&    *this
      */
     Node& operator=(const Node& node);

     /**
      * @brief Construct a new Node object
      * 
      * @param id             location data was recorded
      * @param year           what year data was recorded
      * @param month          what month data was recorded
      * @param temperature    what temperature data was recorded
      */
     Node(std::string id, int year, int month, double temperature);

     // This operator will allow you to just ask if a node is smaller than another
     //  rather than looking at all of the location, temperature and date information
     /**
      * @brief compare nodes
      * 
      * @param b         other node to compare with
      * @return true     if this node should be inserted before b
      * @return false    otherwise
      */
     bool operator<(const Node& b);

     friend ostream& operator<<(ostream& os, const Node& rhs);

     /**
      * @brief Destructor
      */
     virtual ~Node() {}
};

#endif
