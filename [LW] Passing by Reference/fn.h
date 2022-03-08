#ifndef PASSING_BY_REFERENCE
#define PASSING_BY_REFERENCE
struct example
{
     int value = 2;
};

void function_one(int i, int &j);
void function_two(example &ex);
void function_three(int *k, int &l);
void function_four(int *arr, int size, int &lowest, int &highest);
#endif