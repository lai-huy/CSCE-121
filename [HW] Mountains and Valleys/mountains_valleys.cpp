#include <iostream>
#include "functions.h"

using std::cin;
using std::cout;
using std::endl;


int main() {
	// TODO(student): print prompt for input
	int a, b;

	cout << "Enter numbers 10 <= a <= b < 10000: ";

	// TODO(student): read the numbers from standard input
	cin >> a;
	cin >> b;

	// TODO(student): validate input (and reprompt on invalid input)
	while (cin.fail()) {
		cout << "Invalid Input" << endl;
		cout << "Enter numbers 10 <= a <= b < 10000: ";
		cin >> a;
		cin >> b;
	}

	while (!is_valid_range(a,b)) {
		cout << "Invalid Input" << endl;
		cout << "Enter numbers 10 <= a <= b < 10000: ";
		cin >> a;
		cin >> b;
	}

	// TODO(student): compute and display solution
	count_valid_mv_numbers(a, b);

	return 0;
}