#ifndef _MYSTRING_H
#define _MYSTRING_H

#include <iostream>

using std::ostream;

/**
 * @brief implementation of a String class.
 * @version 2022-04-16
 */
class MyString {
private:
     size_t _size;
     size_t _capacity;
     char* _str;

public:
     static const size_t npos = 18446744073709551615UL;
     MyString();
     MyString(const MyString& str);
     MyString(const char* str);
     ~MyString();
     void resize (size_t n);
     size_t capacity() const noexcept;
     size_t size() const noexcept;
     size_t length() const noexcept;
     char* data() const noexcept;
     bool empty() const noexcept;
     const char& front() const;
     const char& at(size_t pos) const;
     void clear() noexcept;
     friend ostream& operator<<(ostream& os, const MyString& str);
     MyString& operator=(const MyString& str);
     MyString& operator+=(const MyString& str);
     size_t find(const MyString& str, size_t pos = 0) const noexcept;

     friend bool operator==(const MyString& lhs, const MyString& rhs) noexcept;
     friend MyString operator+(const MyString& lhs, const MyString& rhs);
};

#endif