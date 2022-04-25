#include <iostream>
#include <string>
using std::cin, std::cout, std::endl, std::string;
using std::flush;

int main() {
     cout << "Please enter a sentence (end with \'quit\'): " << flush;

     string word = "";
     int count = 0;
     bool is_palindrome = false;

     while (word != "quit") {
          cin >> word;
          is_palindrome = false;
          int s = word.size();
          if (s == 1)
               count++;
          else {
               for(int i = 0; i < s/2; ++i) {
                    if (word.at(i) != word.at(s - 1 - i))
                         break;
                    is_palindrome = true;
               }
               count += is_palindrome ? 1 : 0;
          }
     }

     cout << "You have typed " << count << " palindromes.\n";
    return 0;
}
