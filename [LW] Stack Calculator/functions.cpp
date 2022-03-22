#include "functions.h"
using std::cin, std::cout, std::endl, std::ostream, std::string;

#define INFO(X) cout << "[INFO] (" << __FUNCTION__ << ":" << __LINE__ << ") " << #X << " = " << X << endl;
#define INFO_STRUCT(X) cout << "[INFO] (" << __FUNCTION__ << ":" << __LINE__ << ") " << #X << " count = " << X.count << endl;

/**
 * ----- REQUIRED -----
 * Pushes number to top of stack. If stack is full, then resize stack's array.
 * @param   stack   Target stack.
 * @param   number  Number to push to stack.
 */
void push(Stack &stack, int number)
{
     // TODO: implement push function for stack
     // INFO_STRUCT(stack);
     // INFO(number);

     if (++stack.count > stack.capacity) {
          stack.capacity *= 2;
          int* temp = new int[stack.capacity];
          std::copy(stack.numbers, stack.numbers + stack.count - 1, temp);

          delete[] stack.numbers;
          stack.numbers = temp;
     }

     stack.numbers[stack.count-1] = number;
}

/**
 * ----- REQUIRED -----
 * Pops number from top of stack. If stack is empty, return INT32_MAX.
 * @param   stack   Target stack.
 * @return          Value of popped number.
 */
int pop(Stack &stack)
{
     // TODO: implement pop function for stack
     // INFO_STRUCT(stack);

     if (stack.count == 0)
          return INT32_MAX;

     int* temp = new int[stack.capacity];
     int value = stack.numbers[--stack.count];

     // INFO(value);

     std::copy(stack.numbers, stack.numbers + stack.count, temp);

     delete[] stack.numbers;
     stack.numbers = temp;

     return value;
}

/**
 * ----- OPTIONAL -----
 * Returns the number at top of stack without popping it. If stack is empty, return INT32_MAX.
 * @param   stack   Target statck.
 * @return          Number at top of stack.
 */
int peek(const Stack &stack)
{
     // TODO (optional): implement peek function for stack
     // INFO_STRUCT(stack);
     return stack.count == 0 ? INT32_MAX : stack.numbers[stack.count - 1];
}