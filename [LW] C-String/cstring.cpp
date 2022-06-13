#include <iostream>
#include "cstring.h"

using std::cout;

unsigned int length(char str[]) {
     unsigned int i = 0;
     while (str[i] != '\0')
          ++i;
     return i;
}

unsigned int find(char str[], char character) {
     unsigned int len = length(str);
     for (unsigned int i = 0; i < len; ++i)
          if (str[i] == character)
               return i;
     return len;
}

bool equalStr(char str1[], char str2[]) {
     unsigned int len1 = length(str1), len2 = length(str2);
     if (len1 != len2)
          return false;
     for (unsigned int i = 0, j = 0; i < len1; ++i, ++j)
          if (str1[i] != str2[i])
               return false;
     return true;
}