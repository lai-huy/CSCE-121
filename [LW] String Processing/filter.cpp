#include <iostream>
#include <string>
using std::cin, std::cout, std::endl, std::string;
using std::flush;

int main()
{
     string result = "", input = "", filter = "";

     cout << "Please enter the sentence: " << flush;
     getline(cin, input);
     cout << "Please enter the filter word: " << flush;
     cin >> filter;

     long unsigned int LEN = filter.size();     
     
     string replace = "";

     for (long unsigned int i = 0; i < LEN; ++i) {
          replace += "#";
     }

     for (long unsigned int i = 0; i < input.size() - LEN; ++i) {
          if (input.substr(i, LEN) == filter) {
               input.replace(i, LEN, replace);
          }
     }

     result = input;
     cout << "Filtered sentence: " << result << endl;
     return 0;
}
