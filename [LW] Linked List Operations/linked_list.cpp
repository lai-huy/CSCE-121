#include "linked_list.h"
#include <iostream>
#include <string>

using std::cout, std::endl, std::string, std::ostream;

void MyList::add(const std::string& name, int score) {
     MyNode* new_tail = new MyNode(name, score);
     new_tail->prev = nullptr;
     new_tail->next = nullptr;
     if (!this->_size) {
          this->_head = new_tail;
          this->_tail = new_tail;
     } else {
          new_tail->prev = this->_tail;
          new_tail->next = nullptr;
          this->_tail->next = new_tail;
          this->_tail = new_tail;
     }

     ++this->_size;
}

void MyList::clear() {
     switch (this->_size) {
     case 0:
          return;
     case 1:
          this->_size = 0;
          delete this->_head;
          return;
     default:
          MyNode* node = this->_head;
          while (node->next != nullptr) {
               node = node->next;
               delete node->prev;
          }
          delete node;

          this->_head = nullptr;
          this->_tail = nullptr;
          this->_size = 0;
     }
}

bool MyList::remove(const std::string& name) {
     switch (this->_size) {
     case 0:
          return false;
     case 1:
          if (this->_head->name != name)
               return false;
          delete this->_head;
          this->_head = nullptr;
          --this->_size;
          return true;
     default:
          MyNode* node = this->_head;
          while (node->name != name) {
               if (node->next == nullptr)
                    return false;
               node = node->next;
          }

          if (node->prev == nullptr) {
               this->_head = this->_head->next;
               delete this->_head->prev;
               this->_head->prev = nullptr;
               --this->_size;
               return true;
          }

          if (node->next == nullptr) {
               this->_tail = this->_tail->prev;
               delete this->_tail->next;
               this->_tail->next = nullptr;
               --this->_size;
               return true;
          }

          node->prev->next = node->next;
          node->next->prev = node->prev;
          node->prev = nullptr;
          node->next = nullptr;
          delete node;
          --this->_size;
          return true;
     }
}

bool MyList::insert(const std::string& name, int score, size_t index) {
     // TODO(student)
     if (index > this->_size)
          return false;

     if (index == this->_size) {
          this->add(name, score);
          return true;
     }

     MyNode* node = new MyNode(name, score);
     node->next = nullptr;
     node->prev = nullptr;

     if (index == 0) {
          node->next = this->_head;
          this->_head->prev = node;
          this->_head = node;
          ++this->_size;
          return true;
     }

     MyNode* curr = this->_head;
     for (size_t i = 0; i < index; ++i)
          curr = curr->next;

     if (curr->prev == nullptr) {
          this->_head->prev = node;
          node->next = this->_head;
          this->_head = node;
     } else if (curr->next == nullptr) {
          node->prev = this->_tail;
          this->_tail = node;
     } else {
          curr->prev->next = node;
          node->prev = curr->prev;
          node->next = curr;
          curr->prev = node;
     }
     ++this->_size;
     return true;
}

MyList::MyList() : _size(0), _head(nullptr), _tail(nullptr) {}

MyList::~MyList() {
     this->clear();
}

size_t MyList::size() const {
     return this->_size;
}

bool MyList::empty() const {
     return this->_head == nullptr;
}

MyNode* MyList::head() const {
     return this->_head;
}

MyNode* MyList::tail() const {
     return this->_tail;
}

ostream& operator<<(ostream& os, const MyList& myList) {
     MyNode* _current = myList.head();
     if (_current == nullptr) {
          os << "<empty>" << endl;
          return os;
     }

     os << "[ " << _current->name << ", " << _current->score << " ]";
     _current = _current->next;
     while (_current != nullptr) {
          os << " --> [ " << _current->name << ", " << _current->score << " ]";
          _current = _current->next;
     }

     return os;
}

MyNode::MyNode(const std::string& name, int score) : name{name}, score{score}, next{nullptr}, prev{nullptr} {}
