#ifndef MY_LIST_H
#define MY_LIST_H

#include <string>
#include <iostream>

/**
 * Simple node representation of linked list data structure.
 *    - std::string name;
 *    - int score;
 *    - MyNode* next;
 *    - MyNode* prev;
 *    - MyNode(const std::string&, int);
 */
struct MyNode {
     /**
      * Name value of node.
      */
     std::string name;

     /**
      * Score value of node.
      */
     int score;

     /**
      * Link to next node in linked list.
      */
     MyNode* next;

     /**
      * Link to next node in linked list.
      */
     MyNode* prev;

     /**
      * Two-parameter constructor for name and score.
      * @param	name	Name.
      * @param	score	Score.
      */
     MyNode(const std::string& name, int score);
};


/**
 * Simple linked list data structure representation.
 * - private
 *    - size_t _size
 *    - MyNode* _head
 *    - MyNode* _tail
 * - public:
 *    - MyList()
 *    - ~MyList()
 *    - size_t size()
 *    - bool empty()
 *    - MyNode* head()
 *    - void add(const std::string&, int)
 *    - bool remove(const std::string&)
 *    - void clear()
 *    - void insert(const std::string&, int, size_t)
 */
class MyList {
     /**
      * Size of linked list.
      */
     size_t _size;

     /**
      * Pointer to head node.
      */
     MyNode* _head;

     /**
      * Pointer to tail node.
      */
     MyNode* _tail;

public:
     /**
      * Default constructor that initializes list size and node pointers.
      */
     MyList();

     /**
      * Destructor that deallocates node pointers
      */
     ~MyList();

     /**
      * Get size of linked list.
      * @return      Size of linked list.
      */
     size_t size() const;

     /**
      * Get whether linked list is empty or not.
      * @return      Whether linked list is empty or not.
      */
     bool empty() const;

     /**
      * Get head node of linked list.
      * @return      Head node of linked list.
      */
     MyNode* head() const;

     /**
      * @brief Get tail node of linked list
      * 
      * @return MyNode* Tail node of linked list
      */
     MyNode* tail() const;

     /**
      * Add node to end of linked list with node data.
      * @param   name    Name data of node.
      * @param   score   Score data of node.
      */
     void add(const std::string& name, int score);

     /**
      * Clears linked list of all nodes, if any.
      */
     void clear();

     /**
      * Remove the first node from linked list with name data.
      * @param       Name data of node to remove.
      * @return      Whether a node was removed from the list.
      */
     bool remove(const std::string& name);

     /**
      * Insert node into index of linked list with node data.
      * @param       name of node to insert.
      * @param       score of node to insert.
      * @param       index of node to insert.
      * @return      true if the node was inserted.
      */
     bool insert(const std::string& name, int score, size_t index);
};

/**
 * Display data of every node in linked list.
 */
std::ostream& operator<<(std::ostream& os, const MyList& myList);


#endif
