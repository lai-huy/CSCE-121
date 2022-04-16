#include "MyString.h"

MyString::MyString() {

}

MyString::MyString(const MyString& str) {

}

MyString::MyString(const char* str) {

}

MyString::~MyString() {

}

void MyString::resize (size_t n) {

}

size_t MyString::capacity() const noexcept {

}

size_t MyString::size() const noexcept {

}

size_t MyString::length() const noexcept {

}

char* MyString::data() const noexcept {

}

bool MyString::empty() const noexcept {

}

const char& MyString::front() const {

}

const char& MyString::at(size_t pos) const {

}

void MyString::clear() noexcept {

}

friend ostream& MyString::operator<<(ostream& os, const MyString& str) {

}

MyString& MyString::operator=(const MyString& str) {

}

MyString& MyString::operator+=(const MyString& str) {

}

size_t MyString::find(const MyString& str, size_t pos = 0) const noexcept {
     return static_cast<size_t>(-1);
}

friend bool MyString::operator==(const MyString& lhs, const MyString& rhs) noexcept;
friend MyString MyString::operator+(const MyString& lhs, const MyString& rhs);