#include "boolean_functions.h"

#include <iostream>

using std::cin, std::cout;

void booleanLogic1() {
    cout << "--- Boolean Logic 1 ---" << "\n";

    cout << " x | NOT x" << "\n";
    cout << "---+-------" << "\n";
    cout << " 0 |   1" << "\n";
    cout << " 1 |   0" << "\n";

    cout << "\n";
}

void booleanLogic2() {
    cout << "--- Boolean Logic 2 ---" << "\n";

    cout << " x | y | x OR y" << "\n";
    cout << "---+---+--------" << "\n";
    cout << " 0 | 0 |   0" << "\n";
    cout << " 0 | 1 |   1" << "\n";
    cout << " 1 | 0 |   1" << "\n";
    cout << " 1 | 1 |   1" << "\n";

    cout << "\n";
}

void booleanLogic3() {
    cout << "--- Boolean Logic 3 ---" << "\n";

    cout << " x | y | x AND y" << "\n";
    cout << "---+---+---------" << "\n";
    cout << " 0 | 0 |    0" << "\n";
    cout << " 0 | 1 |    0" << "\n";
    cout << " 1 | 0 |    0" << "\n";
    cout << " 1 | 1 |    1" << "\n";

    cout << "\n";
}

void booleanLogic4() {
    cout << "--- Boolean Logic 4 ---" << "\n";

    cout << " x | y | x XOR y" << "\n";
    cout << "---+---+---------" << "\n";
    cout << " 0 | 0 |    0" << "\n";
    cout << " 0 | 1 |    1" << "\n";
    cout << " 1 | 0 |    1" << "\n";
    cout << " 1 | 1 |    0" << "\n";

    cout << "\n";
}

void booleanLogic5() {
    cout << "--- Boolean Logic 5 ---" << "\n";

    bool x, y, z;
    cout << "Enter 0 or 1 values for x, y, and z: ";
    cin >> x >> y >> z;
    bool value = x || y || z; // TODO: Fill this in
    cout << x << " OR " << y << " OR " << z << " = " << value << "\n";

    cout << "\n";
}

void booleanLogic6() {
    cout << "--- Boolean Logic 6 ---" << "\n";

    bool x, y, z;
    cout << "Enter 0 or 1 values for x, y, and z: ";
    cin >> x >> y >> z;
    bool value = x && y && z; // TODO: Fill this in
    cout << x << " AND " << y << " AND " << z << " = " << value << "\n";

    cout << "\n";
}

void booleanLogic7() {
    cout << "--- Boolean Logic 7 ---" << "\n";

    bool x, y, z;
    cout << "Enter 0 or 1 values for x, y, and z: ";
    cin >> x >> y >> z;
    bool value = x ^ y ^ z; // TODO: Fill this in
    cout << x << " XOR " << y << " XOR " << z << " = " << value << "\n";

    cout << "\n";
}
