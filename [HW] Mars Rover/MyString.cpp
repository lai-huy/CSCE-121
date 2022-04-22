#include <iostream>

#include "MyString.h"

using std::ostream;
using std::out_of_range;

MyString::MyString() : _size{0}, _capacity{15}, _str{new char[15]} {
     for (size_t i = 0; i < this->_capacity; ++i)
          this->_str[i] = static_cast<char>(0);
}

MyString::MyString(const MyString& str) : _size{str._size}, _capacity{str._capacity}, _str{nullptr} {
     this->_size = str.size();
     this->_capacity = str.capacity();
     this->_str = new char[this->_capacity];

     for (size_t i = 0; i < this->_capacity; ++i)
          this->_str[i] = i < this->_size ? str.at(i) : static_cast<char>(0);
}

MyString::MyString(const char* str) : _size{0}, _capacity{15}, _str{nullptr} {
     if (str == nullptr)
          throw std::invalid_argument("c-string cannot be nullptr");

     size_t i = npos;
     while (str[++i]) {}

     this->_size = i;
     while (this->_size > this->_capacity)
          this->_capacity *= 2;

     this->_str = new char[this->_capacity];
     for (i = 0; i < this->_capacity; ++i)
          this->_str[i] = i < this->_size ? str[i] : static_cast<char>(0);
}

MyString::~MyString() {
     if (this->_str != nullptr)
          delete[] this->_str;
}

void MyString::resize(size_t n) {
     if (n < this->_size)
          this->_size = n;
     this->_capacity = n;
     this->_str[n] = static_cast<char>(0);
}

size_t MyString::capacity() const noexcept {
     return this->_capacity;
}

size_t MyString::size() const noexcept {
     return this->_size;
}

size_t MyString::length() const noexcept {
     return this->_size;
}

char* MyString::data() const noexcept {
     return this->_str;
}

bool MyString::empty() const noexcept {
     return !this->_size;
}

const char& MyString::front() const {
     return this->_str[0];
}

const char& MyString::at(size_t pos) const {
     if (pos >= this->_size)
          throw out_of_range("Index out of bounds");
     return this->_str[pos];
}

void MyString::clear() noexcept {
     for (size_t i = 0; i < this->_size; ++i)
          this->_str[i] = static_cast<char>(0);

     this->_size = 0;
     this->_capacity = 1;
     return;
}

ostream& operator<<(ostream& os, const MyString& str) {
     for (size_t i = 0; i < str.size(); ++i)
          os << str.at(i);

     return os;
}

MyString& MyString::operator=(const MyString& str) {
     this->_size = str.size();
     this->_capacity = str.capacity();

     delete[] this->_str;
     this->_str = new char[this->_capacity];

     char* temp = str.data();
     for (size_t i = 0; i < this->_capacity; ++i)
          this->_str[i] = temp[i];

     return *this;
}

MyString& MyString::operator+=(const MyString& str) {
     size_t l_size = this->_size, r_size = str.size(), cap = 15;

     while (l_size + r_size > cap)
          cap *= 2;

     char* temp = new char[cap];
     for (size_t i = 0; i < cap; ++i) {
          if (i < l_size)
               temp[i] = this->_str[i];
          else if (i < l_size + r_size)
               temp[i] = str.at(i - l_size);
          else
               temp[i] = static_cast<char>(0);
     }

     this->_size += str.size();
     this->_capacity = cap;
     delete[] this->_str;
     this->_str = temp;

     return *this;
}

size_t MyString::find(const MyString& str, size_t pos) const noexcept {
     size_t sz = str.size(), index = MyString::npos;
     for (size_t i = pos; i < this->_size - sz + 1; ++i) {
          bool eq = true;
          for (size_t j = 0; j < sz; ++j) {
               if (this->_str[i + j] != str.at(j)) {
                    eq = false;
                    break;
               }
          }

          if (eq)
               index = i;
     }

     return index;
}

bool operator==(const MyString& lhs, const MyString& rhs) noexcept {
     if (lhs.size() != rhs.size())
          return false;

     for (size_t i = 0; i < lhs.size(); ++i)
          if (lhs.at(i) != rhs.at(i))
               return false;

     return true;
}

MyString operator+(const MyString& lhs, const MyString& rhs) {
     size_t cap = lhs.capacity() + rhs.capacity(), l_size = lhs.size();
     char* temp = new char[cap];
     for (size_t i = 0; i < cap; ++i)
          try {
          temp[i] = i < l_size ? lhs.at(i) : rhs.at(i - l_size);
     } catch (const std::exception& err) {
          temp[i] = static_cast<char>(0);
     }

     return MyString(temp);
}