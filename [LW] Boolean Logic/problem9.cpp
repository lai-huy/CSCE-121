#include <iostream>
#include "mystery_formula.h"

using std::cout;
using std::endl;

bool test(bool w, bool x, bool y, bool z) {
  cout << w << x << y << z << endl;
  return x && (w || y) && (!w || !z) && (!y || z);
}

int main() {
  bool w = true;
  bool x = false;
  bool y = false;
  bool z = false;
  f(w,x,y,z);

  /**
  cout << test(false, false, false, false) << endl;
  cout << test(false, false, false, true) << endl;
  cout << test(false, false, true, false) << endl;
  cout << test(false, false, true, true) << endl;
  cout << test(false, true, false, false) << endl;
  cout << test(false, true, false, true) << endl;
  cout << test(false, true, true, false) << endl;
  cout << test(false, true, true, true) << endl;
  cout << test(true, false, false, false) << endl;
  cout << test(true, false, false, true) << endl;
  cout << test(true, false, true, false) << endl;
  cout << test(true, false, true, true) << endl;
  cout << test(true, true, false, false) << endl;
  cout << test(true, true, false, true) << endl;
  cout << test(true, true, true, false) << endl;
  cout << test(true, true, true, true) << endl;*/
}