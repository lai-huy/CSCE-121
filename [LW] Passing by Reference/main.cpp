#include <iostream>
#include "fn.h"

using std::cout;

void printarr(int* arr, int size) {
     cout << "[";
     for (int i = 0; i < size; i++) {
          cout << arr[i];
          if (i != size - 1)
               cout << ", ";
     }
     cout << "]";
}

int main() {
     /*
      * Testing code is provided for your convenience.
      */

      // Function_one
     int i = 2;
     int j = 2;
     cout << "\n";
     cout << "When I call function_one(2,2), the values of the variables are as follows " << "\n"
          << "i before execution: " << i << "\n"
          << "j before execution: " << j << "\n";
     function_one(i, j);
     cout << "i after execution: " << i << "\n"
          << "j after execution: " << j << "\n";

     // Function_two
     example foo;
     cout << "\n";
     cout << "When I call function_two(foo), the values of the variables are as follows " << "\n"
          << "foo.value before execution: " << foo.value << "\n";
     function_two(foo);
     cout << "foo.value after execution: " << foo.value << "\n";

     // Function_three
     int a = INT32_MAX;
     int b = INT32_MAX;
     cout << "\n";
     cout << "When I call function_three(" << a << ", " << b << "), the values of the variables are as follows " << "\n"
          << "a before execution: " << a << "\n"
          << "b before execution: " << b << "\n";

     function_three(&a, b); //INSERT THE CORRECT FUNCTION ARGUMENTS HERE. PASS A and B INTO THE FUNCTION.
     cout << "a after execution: " << a << "\n"
          << "b after execution: " << b << "\n";

     // Function_four
     int* bar = new int[5];
     bar[0] = 3;
     bar[1] = 6;
     bar[2] = 4;
     bar[3] = -5;
     bar[4] = 5;
     int lowest = 0;
     int highest = 0;

     cout << "\n";
     cout << "When I call function_four(bar, 5,0,0) the values of the variables are as follows " << "\n"
          << "lowest before execution: " << lowest << "\n"
          << "highest before execution: " << highest << "\n"
          << "array before execution: ";
     printarr(bar, 5);
     cout << "\n";
     function_four(bar, 5, lowest, highest);
     cout << "lowest after execution: " << lowest << "\n"
          << "highest after execution: " << highest << "\n"
          << "array after execution: ";
     printarr(bar, 5);
     cout << "\n";

     cout << "\n";
     delete[] bar;
}