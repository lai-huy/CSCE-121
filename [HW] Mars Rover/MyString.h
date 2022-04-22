#ifndef _MYSTRING_H
#define _MYSTRING_H

#include <iostream>

using std::ostream;

/**
 * @brief implementation of a String class.
 * @version 2022-04-16
 * @note I ctrl+c ctrl+v the comments from https://www.cplusplus.com/reference/string/string/
 */
class MyString {
private:
     /**
      * @brief The number of bytes in the string.
      */
     size_t _size;

     /**
      * @brief Return size of allocated storage
      */
     size_t _capacity;

     /**
      * @brief Dynamic array holding the data
      */
     char* _str;

public:
     /**
      * @brief the greatest possible value for an element of type size_t.
      */
     static const size_t npos = 18446744073709551615UL;

     /**
      * @brief Constructs an empty string, with a length of zero characters.
      */
     MyString();

     /**
      * @brief Constructs a copy of str.
      *
      * @param str MyString to copy from.
      */
     MyString(const MyString& str);

     /**
      * @brief Copies the null-terminated character sequence (C-string) pointed by str.
      *
      * @param str C-string to copy from
      */
     MyString(const char* str);

     /**
      * @brief Destroy the My String object
      */
     ~MyString();

     /**
      * @brief Resizes the string to a length of n characters.
      *
      * @param n New string length, expressed in number of characters.
      */
     void resize(size_t n);

     /**
      * @brief Return size of allocated storage
      *
      * @return size_t The size of the storage capacity currently allocated for the string.
      */
     size_t capacity() const noexcept;

     /**
      * @brief Return length of string
      *
      * @return size_t The number of bytes in the string.
      */
     size_t size() const noexcept;

     /**
      * @brief return this->_size
      *
      * @return size_t size of string
      */
     size_t length() const noexcept;

     /**
      * @brief Get string data
      *
      * @return char* A pointer to the c-string representation of the string object's value.
      */
     char* data() const noexcept;

     /**
      * @brief Test if string is empty
      *
      * @return true true if the string length is 0
      * @return false otherwise
      */
     bool empty() const noexcept;

     /**
      * @brief Access first character
      *
      * @return const char& A reference to the first character in the string.
      */
     const char& front() const;

     /**
      * @brief Returns a reference to the character at position pos in the string.
      *
      * @param pos Value with the position of a character within the string.
      * @return const char& The character at the specified position in the string.
      */
     const char& at(size_t pos) const;

     /**
      * @brief Erases the contents of the string, which becomes an empty string (with a length of 0 characters).
      */
     void clear() noexcept;

     /**
      * @brief Inserts the sequence of characters that conforms value of str into os.
      *
      * @param os   ostream object where characters are inserted.
      * @param str  MyString object with the content to insert.
      * @return ostream& The same as parameter os.
      */
     friend ostream& operator<<(ostream& os, const MyString& str);

     /**
      * @brief Assigns a new value to the string, replacing its current contents.
      *
      * @param str A string object, whose value is either copied (1) or moved (5) if different from *this (if moved, str is left in an unspecified but valid state).
      * @return MyString& *this
      */
     MyString& operator=(const MyString& str);

     /**
      * @brief Extends the string by appending additional characters at the end of its current value:
      * 
      * @param str  A string object, whose value is copied at the end.
      * @return MyString& *this
      */
     MyString& operator+=(const MyString& str);

     /**
      * @brief Searches the MyString for the first occurrence of the sequence specified by its arguments.
      * 
      * @param str  Another MyString with the subject to search for.
      * @param pos  Position of the first character in the string to be considered in the search.
      * @return size_t The position of the first character of the first match. If no matches were found, the function returns -1.
      */
     size_t find(const MyString& str, size_t pos = 0) const noexcept;

     friend bool operator==(const MyString& lhs, const MyString& rhs) noexcept;

     /**
      * @brief Returns a newly constructed MyString object with its value being the concatenation of the characters in lhs followed by those of rhs.
      * 
      * @param lhs left-hand side of the operator.
      * @param rhs rhs-hand side of the operator.
      * @return MyString A MyString whose value is the concatenation of lhs and rhs.
      */
     friend MyString operator+(const MyString& lhs, const MyString& rhs);
};

#endif