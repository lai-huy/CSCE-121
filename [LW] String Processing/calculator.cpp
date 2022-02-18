#include <iostream>
#include <string>

using std::cin, std::cout, std::endl, std::string;
using std::to_string;

int from_string(string number)
{
     if (number == "one")
          return 1;
     if (number == "two")
          return 2;
     if (number == "three")
          return 3;
     if (number == "four")
          return 4;
     if (number == "five")
          return 5;
     if (number == "six")
          return 6;
     if (number == "seven")
          return 7;
     if (number == "eight")
          return 8;
     if (number == "nine")
          return 9;
     if (number == "zero")
          return 0;
     return -1;
}

int main()
{
     string word = "", line = "", op = "0";

     cout << "Please enter word equation (type 'equals' at the end): " << endl;

     int number = 0;

     string numbers = "";
     string opers = "";
     
     // Process user input
     while (word != "equals") {
          cin >> word;
          // cout << "Word:\t" << word << endl;

          number = from_string(word);
          if (number == -1) {
               if (word == "plus")
                    op = "+";
               else if (word == "minus")
                    op = "-";
               else if (word == "times")
                    op = "*";
               else if (word == "divides")
                    op = "/";
               else if (word == "equals")
                    op = "=";
               else
                    op = "0";
          } else
               op = "0";

          if (number != -1) {
               line += to_string(number) + " ";
               numbers.push_back(number + '0');
          }

          if (op != "0") {
               line += op + " ";
               opers.append(op);
          }
     }

     // Preparation for calculations
     int result = numbers.at(0) - '0';
     numbers.erase(0, 1);
     opers.erase(opers.size() - 1);
     
     // cout << "Numbers: " << numbers << "\n";
     // cout << "Oppers: " << opers << "\n";

     // Perform calculations
     for (char op : opers) {
          switch (op) {
          case '+':
               result += numbers.at(0) - '0';
               numbers.erase(0, 1);
               break;
          case '-':
               result -= numbers.at(0) - '0';
               numbers.erase(0, 1);
               break;
          case '*':
               result *= numbers.at(0) - '0';
               numbers.erase(0, 1);
               break;
          case '/':
               result /= numbers.at(0) - '0';
               numbers.erase(0, 1);
               break;
          default:
               break;
          }
     }

     cout << line << result << endl;
     return 0;
}
