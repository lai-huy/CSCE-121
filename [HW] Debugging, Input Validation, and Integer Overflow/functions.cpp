#include <stdexcept>
#include <iostream>

using std::invalid_argument;
using std::overflow_error;

int Largest(int a, int b, int c)
{
     int d = INT32_MIN;
     if (a > d)
          d = a;
     if (b > d)
          d = b;
     if (c > d)
          d = c;
     return d;
}

bool SumIsEven(int a, int b)
{
     return (a + b) % 2 == 0;
}

int BoxesNeeded(int apples)
{
     if (apples < 1)
          return 0;
     return apples % 20 == 0 ? apples / 20 : apples / 20 + 1;
}

bool SmarterSection(int A_correct, int A_total, int B_correct, int B_total)
{
     if (A_correct < 0)
          throw invalid_argument("A correct must be non-negative");
     if (A_total < 1)
          throw invalid_argument("A total must be positive");
     if (B_correct < 0)
          throw invalid_argument("B correct must be non-negative");
     if (B_total < 1)
          throw invalid_argument("B total must be positive");
     if (A_correct > A_total)
          throw invalid_argument("A correct must be less than or equal to A total");
     if (B_correct > B_total)
          throw invalid_argument("B correct must be less than or equal to B total");
     return static_cast<double>(A_correct) / A_total > static_cast<double>(B_correct) / B_total;
}

bool GoodDinner(int pizzas, bool is_weekend)
{    
     if (pizzas < 10)
          return false;
     if (10 <= pizzas && pizzas <= 20)
          return true;

     return is_weekend;
}

int SumBetween(int low, int high)
{
     if (low > high)
          throw invalid_argument("Lower bound must be less than the higher bound");

     if (low == INT32_MIN && high == INT32_MAX)
          return INT32_MIN;

     if (low == high)
          return low;

     if (low == high * -1)
          return 0;

     if (low + high == 1)
          return high;

     if (low + high == -1)
          return low;

     if (low < 0 && high > 0) {
          low *= -1;
          if (low > high) {
               int temp = low;
               low = high;
               high = temp;
          }
          low++;
     }

     if (low == high)
          return low;

     if (low == high * -1)
          return 0;

     int value = 0;
     for (int n = low; n <= high; n++) {
          if (value > INT32_MAX - n && n > 0)
               throw overflow_error("Sum overflowed");
          if (value < INT32_MIN - n && n < 0)
               throw overflow_error("Sum underflowed");
          value += n;
     }
     return value;
}

int Product(int a, int b)
{
     if ((a == INT32_MIN && b == -1) || (a == -1 && b == INT32_MIN))
          throw overflow_error("Product overflowed");

     if (a < 0 && b < 0) {
          a *= -1;
          b *= -1;
     }

     if (b > 0) {
          if (a > INT32_MAX / b)
               throw overflow_error("Product overflowed");
          if (a < INT32_MIN / b)
               throw overflow_error("Product underflowed");
     } else if (b < 0) {
          if (a < INT32_MAX / b)
               throw overflow_error("Product overflowed");
          if (a > INT32_MIN / b)
               throw overflow_error("Product underflowed");
     }

     return a * b;
}