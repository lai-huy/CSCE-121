#include <iostream>

bool f(bool x, bool y, bool z) {
  // write your code to compute f(x,y,z) here
  return (!x & (y || z)) || (x && !(y ^ z)); // TODO: change this line
}