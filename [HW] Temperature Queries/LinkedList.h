#ifndef LINKEDLIST
#define LINKEDLIST

#include <iostream>
#include <string>
#include "Node.h"

using std::string;
using std::ostream;

class LinkedList {
private:
     /**
      * @brief Head of the list
      */
     Node* head;

     /**
      * @brief Tail of the list
      */
     Node* tail;

     void copy(const LinkedList& list);

public:
     /**
      * @brief Default constructor
      */
     LinkedList();

     /**
      * @brief Destructor
      */
     ~LinkedList();

     /**
      * @brief Copy constructor
      *
      * @param other LinkedList to copy from.
      */
     LinkedList(const LinkedList& other);

     /**
      * @brief Copy assignment operator
      *
      * @param other          LinkedList to copy from
      * @return LinkedList&
      */
     LinkedList& operator=(const LinkedList& other);

     // Insert a record to the linked list
     /**
      * @brief Insert a record to the linked list
      *
      * @param location       where data was recorded
      * @param year           what year data was recorded
      * @param month          what month data was recorded
      * @param temperature    what temperature was recorded
      */
     void insert(string location, int year, int month, double temperature);

     /**
      * @brief Clear the contents of this LinkedList
      *
      */
     void clear();

     /**
      * @brief helper method
      *
      * @return string string representation of this LinkedList
      */
     string print() const;

     Node* getHead() const;
};

ostream& operator<<(ostream& os, const LinkedList& ll);
#endif
