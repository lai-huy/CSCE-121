#include <iostream>
#include <string>
#include "./string_calculator.h"

using std::cout;
using std::endl;
using std::invalid_argument;
using std::min;
using std::string;
using std::to_string;

unsigned int digit_to_decimal(char digit) {
     // Epic Debugging Lines
     // cout << flush;
     // cout << "Digit: " << digit << endl;

     int x = digit - '0';
     if (-1 < x && x < 10)
          return x;

     throw invalid_argument("Illegal char:\t" + digit);
}

char decimal_to_digit(unsigned int decimal) {
     // Epic Debugging Lines
     // cout << flush;
     // cout << "Decimal: " << decimal << endl;

     if (decimal > 9)
          throw invalid_argument("Illegal decimal:\t" + to_string(decimal));
     return '0' + decimal;
}

string trim_leading_zeros(string num) {
     // Epic Debugging Lines
     // cout << flush;
     // cout << "Number: " << num << endl;

     bool is_neg = false;
     if (num.at(0) == '-') {
          is_neg = true;
          num.erase(0, 1);
          num.erase(0, min(num.find_first_not_of('0'), num.size() - 1));
     } else {
          num.erase(0, min(num.find_first_not_of('0'), num.size() - 1));
     }
     return is_neg ? (num.at(0) == '0' ? num : "-" + num) : num;
}

string add(string lhs, string rhs) {
     // Epic Debugging Lines
     // cout << flush;
     // cout << "LHS: " << lhs << endl;
     // cout << "RHS: " << rhs << endl;
     // cout << endl;

     // Remove Leading zeros
     lhs = trim_leading_zeros(lhs);
     rhs = trim_leading_zeros(rhs);

     // Determine if both numbers are negative.
     bool is_l_neg = lhs.at(0) == '-';
     bool is_r_neg = rhs.at(0) == '-';

     if (is_l_neg && is_r_neg) {
          lhs.erase(0, 1);
          rhs.erase(0, 1);
     } else if (!is_l_neg && is_r_neg) {
          return subtract(lhs, rhs.substr(1));
     } else if (is_l_neg && !is_r_neg) {
          return subtract(rhs, lhs.substr(1));
     }

     // Swap if lhs is shorter than rhs
     // allow for any nessesary increase of length
     if (lhs.size() < rhs.size())
          swap(lhs, rhs);

     // loop over string and add
     int j = lhs.size() - 1;
     for (int i = rhs.size() - 1; i >= 0; i--, j--) {
          lhs[j] += digit_to_decimal(rhs[i]);
          // cout << "Added Digit: " << lhs[j] << endl;
     }

     // cout << "All Digits: " << lhs << endl;
     // cout << endl;

     // perform any carries
     for (int i = lhs.size() - 1; i > 0; i--) {
          if (lhs[i] > '9') {
               int d = lhs[i] - '0';
               lhs[i - 1] = (lhs[i - 1] - '0') + d / 10 + '0';
               lhs[i] = decimal_to_digit(d % 10);
          }
     }

     // cout << "Intermediate: " << lhs << endl;
     // cout << endl;

     // perform carry on left-most digit
     if (lhs[0] > '9') {
          string k;
          k += lhs[0];
          lhs[0] = decimal_to_digit((lhs[0] - '0') % 10);
          k[0] = decimal_to_digit((k[0] - '0') / 10);
          lhs = k + lhs;
     }

     // cout << "Result: " << (neg ? "-" + lhs : lhs) << endl;
     // cout << "-------------------------" << endl;
     return (is_l_neg && is_r_neg) ? "-" + lhs : lhs;
}

string subtract(string lhs, string rhs) {
     // Epic Debugging Lines
     // cout << std::flush;
     // cout << "LHS: " << lhs << "\n";
     // cout << "RHS: " << rhs << "\n";
     // cout << endl;

     // Trim leading zeros
     lhs = trim_leading_zeros(lhs);
     rhs = trim_leading_zeros(rhs);

     if (lhs == "0")
          return (rhs.at(0) == '-') ? rhs.substr(1) : "-" + rhs;
     if (rhs == "0")
          return lhs;

     bool is_l_neg = lhs.at(0) == '-', is_r_neg = rhs.at(0) == '-';
     if (is_l_neg && is_r_neg) {
          return add(rhs.substr(1), lhs);
     } else if (is_l_neg && !is_r_neg) {
          return "-" + add(lhs.substr(1), rhs);
     } else if (!is_l_neg && is_r_neg) {
          return add(lhs, rhs.substr(1));
     }

     int n = lhs.size(), m = rhs.size();

     // Determine if lhs is smaller than rhs
     bool swapped = false;

     if (n < m) {
          swap(lhs, rhs);
          swapped = true;
     } else if (n == m) {
          for (int i = 0; i < n; ++i) {
               if (lhs.at(i) < rhs.at(i)) {
                    swap(lhs, rhs);
                    swapped = true;
                    break;
               } else if (lhs.at(i) > rhs.at(i)) {
                    break;
               }
          }
     }

     n = lhs.size();
     m = rhs.size();

     // cout << "LHS: " << lhs << endl;
     // cout << "RHS: " << rhs << endl;
     // cout << endl;

     string result = "";

     // Loop over rhs backwards and subtract
     int carry = 0;
     for (int i = m - 1, j = n - 1; i > -1; --i, --j) {
          // compute difference of current digits
          int sub = lhs.at(j) - rhs.at(i) - carry;
          // cout << "Raw Calc:\t" << sub << "\n";

          // If subtraction is less then zero
          // we add then we add 10 into sub and
          // take carry as 1 for calculating next step
          if (sub < 0) {
               sub += 10;
               carry = 1;
          } else
               carry = 0;

          // cout << "Sub:\t" << sub << "\n";
          // cout << "Carry:\t" << carry << "\n";
          result.insert(0, 1, sub + '0');
     }

     // Subtract any remaining digits of the larger number.
     for (int i = n - m - 1; i > -1; --i) {
          int sub = digit_to_decimal(lhs.at(i)) - carry;

          // if the sub value is -ve, then make it positive
          if (sub < 0) {
               sub = sub + 10;
               carry = 1;
          } else
               carry = 0;

          result.insert(0, 1, decimal_to_digit(sub));
     }

     result = trim_leading_zeros(result);
     result = swapped ? "-" + result : result;
     // cout << "All Digits: " << result << endl;
     // cout << endl;

     return result;
}

string multiply(string lhs, string rhs) {
     // Epic Debugging Lines
     // cout << flush;
     // cout << "LHS: " << lhs << endl;
     // cout << "RHS: " << rhs << endl;

     // Trim strings of leading zeros
     lhs = trim_leading_zeros(lhs);
     rhs = trim_leading_zeros(rhs);

     // Determine if both lhs and rhs are negative.
     bool neg = false;
     if (lhs.at(0) == '-') {
          lhs.erase(0, 1);
          neg = !neg;
     }

     if (rhs.at(0) == '-') {
          rhs.erase(0, 1);
          neg = !neg;
     }

     int n = lhs.size(), m = rhs.size();

     // If either string is empty, return "0"
     if (n == 0 || m == 0)
          return "0";

     // Declare string for multiplication
     string result(n + m, '0');

     // Perform multiplication
     for (int i = n - 1; i >= 0; i--) {
          for (int j = m - 1; j >= 0; j--) {
               int d = (lhs[i] - '0') * (rhs[j] - '0') + (result[i + j + 1] - '0');
               // cout << "Digit: " << d << endl;
               result[i + j + 1] = decimal_to_digit(d % 10);
               result[i + j] += d / 10;
          }
     }

     result = neg ? "-" + result : result;

     // Remove Leading zeros
     // cout << result << endl;
     return trim_leading_zeros(result);
}
