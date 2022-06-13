/******************************************************************************

File: main.cpp
Author: Prof. Lupoli & Andrew Nemec
Date: 2/16/2021
Section:
E-mail: slupoli@tamu.edu
Description:
This file contains C++  code that will simulate data collected from a track
event with 9 lanes. The code will sort the order, then display the results

Updates
Author: J. Michael Moore & Paul Taele

Data File Information
name: data.text
content: The text file will contain data in the constant form of:
<Time (double)> <Abbreviated Country (String)> <Uniform number (int)> <Lastname (String)>
32.7 USA 12 Moore
36.5 RUS 35 Polsley
45.8 ENG 73 Teale
52.34 CHN 14 Nemec
76.45 ITY 23 Lupoli

*******************************************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <cctype>
#include "parallel_tracks.h"

using std::cin, std::cout;
using std::invalid_argument, std::domain_error;
using std::getline, std::ifstream;
using std::string;

int main() {
     // TODO: create arrays needed
     double times[SIZE];
     string countries[SIZE];
     unsigned int uniform_nums[SIZE];
     string names[SIZE];

     // TOTO: prep all arrays
     prep_double_array(times);
     prep_string_array(countries);
     prep_unsigned_int_array(uniform_nums);
     prep_string_array(names);

     // TODO: prompt until both the file and the contained data are valid
     string file_name = "";
     bool valid = false;
     cout << std::boolalpha;
     while (!valid) {
          cout << "Enter file name: " << std::flush;
          cin >> file_name;

          if (cin.fail() || cin.eof())
               return 0;

          if (file_name == "exit" || file_name == "quit")
               return 0;

          try {
               get_runner_data(file_name, times, countries, uniform_nums, names);
               valid = true;
          } catch (const invalid_argument& err) {
               cout << "Invalid File: " << err.what() << "\n";
               valid = false;
          } catch (const domain_error& err) {
               cout << "Invalid File: " << err.what() << "\n";
               valid = false;
          }
     }

     // TODO: determine ranking, notice the rank array receives the results
     unsigned int ranks[SIZE];
     get_ranking(times, ranks);

     // TODO: Output results
     print_results(times, countries, names, ranks);

     return 0;
}
