#include <iostream>
#include <cmath>
#include "./nth_root.h"

using std::cout;
using std::domain_error;
using std::fabs;

void try_hard(int n, double x) {
     double actual = nth_root(n, x);
     std::cout << "nth_root(" << n << ", " << x << ") = " << actual << "\n";
}

void try_harder(int n, double x, double expected) {
     double actual = nth_root(n, x);
     if (fabs(actual - expected) > 0.00005) {
          cout << "[FAIL] (n=" << n << ", x=" << x << ")" << "\n";
          cout << "  expected nth_root(" << n << ", " << x << ") to be " << expected << "\n";
          cout << "  got " << actual << "\n";
     } else {
          cout << "[PASS] (" << n << ", " << x << ")" << "\n";
     }
}

int main() {
     {   // MINIMUM REQUIREMENT (for this lab)
         // just call the function with various values of n and x
          for (int n = -6; n <= 6; n++) {
               for (double x = -6; x <= 6; x += 0.5) {
                    try {
                         nth_root(n, x);
                    } catch (const domain_error& err) {
                         cout << "Domain Error is HERE!" << "\n";
                    }
               }
          }
     }

     {   // TRY HARD
         // report the value
          double actual = nth_root(2, 1);
          std::cout << "nth_root(2, 1) = " << actual << "\n";

          for (int n = -6; n <= 6; n++) {
               for (double x = -6; x <= 6; x += 0.5) {
                    try {
                         try_hard(n, x);
                    } catch (const domain_error& err) {
                         cout << "Domain Error is HERE!" << "\n";
                    }
               }
          }
     }

     {   // TRY HARDER
         // compare the actual value to the expected value

          for (int n = -6; n <= 6; n++) {
               for (double x = -6; x <= 6; x += 0.5) {
                    try {
                         try_harder(n, x, 0);
                    } catch (const domain_error& err) {
                         cout << "Domain Error is HERE!" << "\n";
                    }
               }
          }
     }
}