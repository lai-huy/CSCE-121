#include <iostream>
#include "mystery_formula.h"

using std::cout;

bool test(bool w, bool x, bool y, bool z) {
  cout << w << x << y << z << "\n";
  return x && (w || y) && (!w || !z) && (!y || z);
}

int main() {
  bool w = true;
  bool x = false;
  bool y = false;
  bool z = false;
  f(w, x, y, z);
}