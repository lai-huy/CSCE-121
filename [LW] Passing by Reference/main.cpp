#include <iostream>
#include "fn.h"
using namespace std;
void printarr(int *arr, int size)
{
     cout << "[";
     for (int i = 0; i < size; i++)
     {
          cout << arr[i];
          if (i != size - 1)
               cout << ", ";
     }
     cout << "]";
}

int main()
{
     /*
      * Testing code is provided for your convenience.
      */

     // Function_one
     int i = 2;
     int j = 2;
     cout << endl;
     cout << "When I call function_one(2,2), the values of the variables are as follows " << endl
          << "i before execution: " << i << endl
          << "j before execution: " << j << endl;
     function_one(i, j);
     cout << "i after execution: " << i << endl
          << "j after execution: " << j << endl;

     // Function_two
     example foo;
     cout << endl;
     cout << "When I call function_two(foo), the values of the variables are as follows " << endl
          << "foo.value before execution: " << foo.value << endl;
     function_two(foo);
     cout << "foo.value after execution: " << foo.value << endl;

     // Function_three
     int a = INT32_MAX;
     int b = INT32_MAX;
     cout << endl;
     cout << "When I call function_three(" << a << ", " << b << "), the values of the variables are as follows " << endl
          << "a before execution: " << a << endl
          << "b before execution: " << b << endl;

     function_three(&a, b); //INSERT THE CORRECT FUNCTION ARGUMENTS HERE. PASS A and B INTO THE FUNCTION.
     cout << "a after execution: " << a << endl
          << "b after execution: " << b << endl;

     // Function_four
     int *bar = new int[5];
     bar[0] = 3;
     bar[1] = 6;
     bar[2] = 4;
     bar[3] = -5;
     bar[4] = 5;
     int lowest = 0;
     int highest = 0;

     cout << endl;
     cout << "When I call function_four(bar, 5,0,0) the values of the variables are as follows " << endl
          << "lowest before execution: " << lowest << endl
          << "highest before execution: " << highest << endl
          << "array before execution: ";
     printarr(bar, 5);
     cout << endl;
     function_four(bar, 5, lowest, highest);
     cout << "lowest after execution: " << lowest << endl
          << "highest after execution: " << highest << endl
          << "array after execution: ";
     printarr(bar, 5);
     cout << endl;

     cout << endl;
     delete[] bar;
}