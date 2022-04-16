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

/**
 * @brief determins the number of boxes needed to store the given number of apples
 *
 * @param apples the number of apples
 * @return int the number of boxes
 */
int BoxesNeeded(int apples);

/**
 * @brief determins if section A performs better than section b
 *
 * @param A_correct numer of correct answers in section A
 * @param A_total   total number of answers in section A
 * @param B_correct number of correct answers in section B
 * @param B_total   total number of answers in section B
 * @return true     if section A performs better than section B
 * @return false    if section B performs better than section A
 * @throws std::invalid_argument if the arguments are invalid
 */
bool SmarterSection(int A_correct, int A_total, int B_correct, int B_total);

// return true if you had a good dinner
/**
 * @brief determine if you had a good dinner
 *
 * @param pizzas         the number of pizzas eaten
 * @param is_weekend     if the pizzas were eaten on a weekend
 * @return true          if the meal was a good dinner
 * @return false         if the meal was not a good dinner
 */
bool GoodDinner(int pizzas, bool is_weekend);

/**
 * @brief determine the sum of all integers from low to high (inclusive)
 *
 * @param low  lower bound
 * @param high higher bound
 * @return int sum of all integers from low to high (inclusive)
 * @throw std::invalid_argument if low and high are out of order
 * @throw std::overflow_error if the sum exceeds the maximum/minimum valyd of a signed 32-bit integer.
 */
int SumBetween(int low, int high);

/**
 * @brief calculate the prodict of a and b
 *
 * @param a    int a
 * @param b    int b
 * @return int a * b;
 * @throws std::overflow_error if the product exceeds the maximum/minimum value of a signed 32-bit integer.
 */
int Product(int a, int b);

#endif  // FUNCTIONS_H