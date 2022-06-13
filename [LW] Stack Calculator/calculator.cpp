#include <iostream>
#include <string>
#include <sstream>
#include "functions.h"
using std::cin, std::cout, std::string, std::istringstream;

int main() {
     // prompt user input
     cout << "Type RPN expression (end with '=').\n";
     cout << "> " << std::flush;

     // TODO: create a command-line interface for calculator GUI
     Stack s;
     string line;
     getline(cin, line);

     istringstream ss(line);
     string val;
     while (val != "=") {
          ss >> val;
          int num;
          try {
               num = stoi(val);
               push(s, num);
          } catch (const std::invalid_argument& err) {
               int right = pop(s), left = pop(s);
               switch (val.at(0)) {
               case '+':
                    push(s, left + right);
                    break;
               case '-':
                    push(s, left - right);
                    break;
               case '*':
                    push(s, left * right);
                    break;
               case '/':
                    push(s, left / right);
                    break;
               case '^':
               {
                    int pow = 1;
                    for (int i = 0; i < right; ++i)
                         pow *= left;
                    push(s, pow);
                    break;
               }
               case '=':
                    cout << "Ans: " << std::to_string(right) << "\n";
                    break;
               default:
                    cout << val << "\n";
               }
          }
     }

     delete[] s.numbers;

     return 0;
}
