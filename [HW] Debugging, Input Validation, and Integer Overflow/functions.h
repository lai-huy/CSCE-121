#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/**
 * @brief return the largest of the arguments
 * 
 * @param a int 0
 * @param b int 1
 * @param c int 2
 * @return int largest of th earguments
 */
int Largest(int a, int b, int c);

/**
 * @brief determine if the sum of the two arguments is even
 * 
 * @param a int 0
 * @param b int 1
 * @return true     if the sum of a and b is even
 * @return false    if the sum of a and b is not even
 */
bool SumIsEven(int a, int b);

/// return the number of boxes needed to store the given number of apples
int BoxesNeeded(int apples);

// return true if section A performs better than section B
// throws std::invalid_argument if the arguments are invalid
bool SmarterSection(int A_correct, int A_total, int B_correct, int B_total);

// return true if you had a good dinner
bool GoodDinner(int pizzas, bool is_weekend);

// return the sum of all integers from low to high (inclusive)
// throw std::invalid_argument if low and high are out of order
// throw std::overflow_error if the sum exceeds the maximum/minimum value of a signed 32-bit integer.
int SumBetween(int low, int high);

// return the product of a and b
// throw std::overflow_error if the product exceeds the maximum/minimum value of a signed 32-bit integer.
int Product(int a, int b);

#endif  // FUNCTIONS_H