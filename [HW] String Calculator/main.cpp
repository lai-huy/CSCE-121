#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include "./string_calculator.h"

using std::boolalpha;
using std::cout, std::endl, std::cin;
using std::invalid_argument;
using std::out_of_range;
using std::string;
using std::stringstream;
using std::to_string;

const char PLUS = '+';
const char MINUS = '-';
const char MULT = '*';

// Convert any char to an int
int to_digit(char c)
{
     return (c >= '0' && c <= '9') ? (int)(c - '0') : (int)(c - 'A' + 10);
}

// Convert from any base between 2 and 36 (inclusive) to decimal
string to_decimal(string number, int base)
{
     if (base < 2 || base > 36)
          throw invalid_argument("Illegal Base: " + base);
     
     if (base == 10)
          return number;

     // Declare variables
     string result = "0";
     int power = 1;

     // Conversion
     for (int i = number.size() - 1; i > -1; i--)
     {
          char c = number.at(0);
          int val = to_digit(c);
          if (val >= base)
               throw invalid_argument("Inavalid Number at index " + c);
          
          result = add(result, to_string(val * power));
          power *= base;
     }

     return result;
}

// Convert from decimal to any base between 2 and 36 (inclusive)
string to_base(string number, int base)
{
     if (base < 2 || base > 36)
          throw invalid_argument("Illegal Base: " + base);

     if (base == 10)
          return number;

     string result = "0";

     /**
     for (int i = (int)number.size(); i > 0; --i) {
          result = add(result, to_string(0));
     }*/

     return result;
}

int main()
{
     cout << boolalpha;

     string input = "\0";
     cout << "String Calculator\n\"q\" or \"quit\" or ctrl+d to exit" << endl;
     while (true)
     {
          cout << ">> ";
          
          getline(cin, input);
          if (cin.eof() || cin.fail()) {
               cout << "farvel!" << endl;
               return 0;
          }

          cout << endl;

          if (input == "q" || input == "quit")
          {
               cout << "farvel!" << endl;
               return 0;
          }

          stringstream SS(input);
          string LHS, OP, RHS;
          SS >> LHS >> OP >> RHS;

          // Epic Debug Lines :)
          // cout << "LHS: " << LHS << endl;
          // cout << "OP: " << OP << endl;
          // cout << "RHS: " << RHS << endl;

          // Handle base 2-36 :)
          /*
          // Split string by '_'
          char del = '_';

          for (long unsigned int i = 0; i < LHS.size(); ++i)
          {
               char c = LHS.at(i);
               if (c == del)
                    LHS[i] = ' ';
               else if (c == ' ')
                    LHS[i] = del;
          }

          stringstream ss(LHS);
          string base;
          ss >> LHS >> base;

          LHS = to_decimal(LHS, stoi(base));

          for (long unsigned int i = 0; i < RHS.size(); i++)
          {
               char c = RHS.at(i);
               if (c == del)
                    RHS[i] = ' ';
               else if (c == ' ')
                    RHS[i] = del;
          }

          stringstream ss1(RHS);
          ss1 >> RHS >> base;

          RHS = to_decimal(RHS, stoi(base));*/

          const char op = OP.at(0);
          string ans = "\0";

          switch (op)
          {
          case PLUS:
               ans = add(LHS, RHS);
               break;
          case MINUS:
               ans = subtract(LHS, RHS);
               break;
          case MULT:
               ans = multiply(LHS, RHS);
               break;
          default:
               throw "Invalid Operator";
          }

          /*
          ans = to_base(ans, stoi(base));
          if (base != "10")
               ans += "_" + base;
               */

          cout << "ans =" << endl;
          cout << "\n    " << ans << endl;
          cout << endl;
     }

     return 0;
}
