#include <iostream>
#include "functions.h"

using std::cout;
using std::endl;

bool is_valid_range(int a, int b) {
	if (a < 10 || a >= 10000) {
		return false;
	}

	if (b < a || b >= 10000) {
		return false;
	}

	return true;
}

char classify_mv_range_type(int number) {
	// TODO(student): return 'M' if number has /\/\... pattern,
	// return 'V' if number has \/\/ pattern, and return 'N' otherwise

	char mode = 'N';
	int num = number;
	int prev_digit = num % 10;
	num /= 10;

	while (num != 0) {
		int digit = num % 10;
		if (prev_digit == digit) {
			return 'N';
		} else if (prev_digit > digit) {
			if (mode == 'M')
				return 'N';
			mode = 'M';
		} else {
			if (mode == 'V')
				return 'N';
			mode = 'V';
		}
		prev_digit = digit;
		num /= 10;
	}

	return mode;
}

void count_valid_mv_numbers(int a, int b) {
	int mr = 0, vr = 0;

	for (int i = a; i <= b; i++) {
		switch (classify_mv_range_type(i)) {
		case 'M':
			mr++;
			break;
		case 'V':
			vr++;
			break;
		default:
			continue;
		}
	}

	cout << "There are " << mr << " mountain ranges and " << vr << " valley ranges between " << a << " and " << b << "." << endl;
}