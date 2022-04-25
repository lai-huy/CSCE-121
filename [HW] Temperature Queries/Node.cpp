#include <string>
#include "Node.h"

using std::string;

// Default constructor
Node::Node() : next{nullptr}, data{TemperatureData()} {}
Node::Node(const Node& node) : next{node.next}, data{node.data} {}
Node& Node::operator=(const Node& node) {
     delete this->next;
     this->next = node.next;
     this->data = node.data;

     return *this;
}

// Parameterized constructor
Node::Node(string id, int year, int month, double temperature) : next{nullptr}, data{TemperatureData(id, year, month, temperature)} {}

bool Node::operator<(const Node& b) {
     return this->data < b.data;
}

ostream& operator<<(ostream& os, const Node& rhs) {
     os << rhs.data;
     return os;
}
