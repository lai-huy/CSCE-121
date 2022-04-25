#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <limits>
#include <cstdlib>
#include <vector>
#include <ctime>

#include "LinkedList.h"
#include "Node.h"

using std::string;
using std::to_string;
using std::ostream;

LinkedList::LinkedList() : head{nullptr}, tail{nullptr} {}

LinkedList::~LinkedList() {
     this->clear();
}

LinkedList::LinkedList(const LinkedList& source) : head{nullptr}, tail{nullptr} {
     Node* h = source.getHead();

     if (!h)
          return;

     TemperatureData data = h->data;
     this->head = new Node(data.id, data.year, data.month, data.temperature);
     this->head->next = nullptr;

     Node* curr = this->head, * node = h->next;
     while (node != nullptr) {
          curr->next = new Node(node->data.id, node->data.year, node->data.month, node->data.temperature);
          curr = curr->next;
          node = node->next;
     }
     this->tail = curr;
}

LinkedList& LinkedList::operator=(const LinkedList& source) {
     this->clear();

     Node* h = source.getHead();
     TemperatureData data = h->data;
     this->head = new Node(data.id, data.year, data.month, data.temperature);
     this->head->next = nullptr;

     Node* curr = this->head, * node = h->next;
     while (node != nullptr) {
          curr->next = new Node(node->data.id, node->data.year, node->data.month, node->data.temperature);
          curr = curr->next;
          node = node->next;
     }
     this->tail = curr;

     return *this;
}

void LinkedList::insert(string location, int year, int month, double temperature) {
     if (temperature == -99.99)
          return;

     Node* new_node = new Node(location, year, month, temperature);
     // std::cout << "Intersting:\t" << *new_node;

     // Inserting into empty list
     if (!this->head) {
          this->head = new_node;
          this->tail = new_node;
          return;
     }

     // Inserting before head
     if (*new_node < *this->head) {
          new_node->next = this->head;
          this->head = new_node;
          return;
     }

     // Inserting after tail
     if (*this->tail < *new_node) {
          this->tail->next = new_node;
          this->tail = new_node;
          return;
     }

     // Inserting middle
     Node* node = this->head;
     while (*node < *new_node) {
          // Store previous node
          new_node->next = node;
          node = node->next;
     }

     new_node->next->next = new_node;
     new_node->next = node;
}

void LinkedList::clear() {
     if (!this->head)
          return;

     Node* curr = this->head, * next;
     while (curr) {
          next = curr->next;
          delete curr;
          curr = next;
     }
     this->head = nullptr;
     this->tail = nullptr;
}

Node* LinkedList::getHead() const {
     return this->head;
}

string LinkedList::print() const {
     string outputString = "";

     if (this->head == nullptr)
          return outputString;

     Node* node = this->head;
     while (node != nullptr) {
          string flt = to_string(node->data.temperature);
          flt.erase(flt.find_last_not_of('0') + 1, string::npos);
          if (flt.back() == '.')
               flt = flt.substr(0, flt.size() - 1);

          outputString += node->data.id + " " + to_string(node->data.year) + " " + to_string(node->data.month) + " " + flt + "\n";
          node = node->next;
     }

     return outputString;
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
     os << ll.print();
     return os;
}
