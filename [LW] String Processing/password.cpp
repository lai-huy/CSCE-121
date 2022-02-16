#include <iostream>
#include <string>
using std::cin, std::cout, std::endl, std::string;
using std::flush;

int main() {
     string password = "", result = "";

     /*
     a = @
     e = 3
     i = !
     o = 0
     u = ^
     */

     cout << "Please enter your text input: " << flush;
     cin >> password;
     cout << "input: " << password;
     cout << endl;

     for (char c: password) {
          switch (c) {
          case 'a':
               result += '@';
               break;
          case 'e':
               result += '3';
               break;
          case 'i':
               result += '!';
               break;
          case 'o':
               result += '0';
               break;
          case 'u':
               result += '^';
               break;
          default:
               result += c;
               break;
          }
     }

     for (int i = result.size() - 1; i > -1; --i)
          result += result.at(i);

     cout << "output: " << result << endl;

    return 0;
}
