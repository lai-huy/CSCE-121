#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <limits>
#include <cstdlib>
#include <vector>
#include <ctime>
#include "TemperatureDatabase.h"

using std::cout, std::endl;

int main(int argc, char** argv) {
     if (argc < 3) {
          cout << "Usage: " << argv[0] << " data_file query_file" << endl;
          return 1;
     } else {
          TemperatureDatabase database;
          database.loadData(argv[1]);
          database.outputData(argv[1]); // comment out before submitting Part 2
          database.performQuery(argv[2]); // Will be done in Part 2
     }
}
