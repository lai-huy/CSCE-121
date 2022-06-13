#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <cctype>
#include "parallel_tracks.h"

using std::string, std::tolower;
using std::cout, std::ifstream, std::stringstream;
using std::invalid_argument, std::domain_error;
using std::begin, std::end;

//-------------------------------------------------------
// Name: get_runner_data
// PreCondition:  the prepped parallel arrays , and a legit filename is pass
// PostCondition: all arrays contain data from the text file given
//---------------------------------------------------------
void get_runner_data(const std::string& file, double timeArray[], std::string countryArray[],
                     unsigned int numberArray[], std::string lastnameArray[]) {
     if (file.empty())
          throw domain_error("File name cannot be empty");

     // cout << "File name:\t" << file << "\n";

     ifstream f;
     f.open(file.c_str());
     string l;

     while (getline(f, l)) {
          if (l.size() == 0)
               throw domain_error("File missing data");
     }

     ifstream fin;
     fin.open(file.c_str());

     if (!fin.is_open())
          throw invalid_argument("Cannot open file");

     string line, time, country, uin, name;
     int index = 0;
     stringstream ss;

     int lines = 0;

     while (getline(fin, line)) {
          ss << line;

          // Process time
          ss >> time;
          // cout << "Got Time:\t" << time << "\n";

          if (ss.fail())
               throw domain_error("File missing data");

          double t;
          try {
               t = stod(time);
          } catch (...) {
               throw domain_error("File contains invalid data (time)");
          }

          if (t <= 0)
               throw domain_error("File contains invalid data (time)");

          timeArray[index] = t;
          // cout << "Read Time:\t" << t << "\n";

          // Process Country
          ss >> country;
          // cout << "Got Country:\t" << country << "\n";

          if (ss.fail())
               throw domain_error("File missing data");

          if (country.size() != 3)
               throw domain_error("File contains invalid data (country)");

          for (char c : country)
               if (islower(c) || !isalpha(c))
                    throw domain_error("File contains invalid data (country)");

          countryArray[index] = country;
          // cout << "Read Country:\t" << country << "\n"; 

          // Process Uniform Number
          ss >> uin;
          // cout << "Got Number:\t" << uin << "\n";

          if (ss.fail())
               throw domain_error("File missing data");

          unsigned int un;
          try {
               un = stoi(uin);
          } catch (...) {
               throw domain_error("File contains invalid data (number)");
          }

          if (un > 99)
               throw domain_error("File contains invalid data (number)");

          numberArray[index] = un;
          // cout << "Read Number:\t" << un << "\n";

          // Process Last name
          ss >> name;
          // cout << "Got Name:\t" << name << "\n";

          if (name.size() < 2)
               throw domain_error("File contains invalid data (name)");

          name = trim(name);

          for (char c : name)
               if (!isalpha(c))
                    throw domain_error("File contains invalid data (name)");

          lastnameArray[index] = name;
          // cout << "Read Name:\t" << name << "\n";

          time = "";
          country = "";
          uin = "";
          name = "";

          ++index;
          ss.clear();

          ++lines;
          if (lines == SIZE)
               break;
     }

     /**
     // Outside wile loop just incase I forgot to incremenet index
     for (unsigned int i = 0; i < SIZE; ++i) {
          cout << "Time:\t" << timeArray[i] << "\n";
          cout << "Contry:\t" << countryArray[i] << "\n";
          cout << "Number:\t" << numberArray[i] << "\n";
          cout << "Name:\t" << lastnameArray[i] << "\n";
          cout << "-------------------------\n";
     }*/
}

//-------------------------------------------------------
// Name: prep_double_array
// PreCondition:  a double arrays is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_double_array(double ary[])
// making sure all values within the array are set to 0.0;
{
     for (long unsigned int i = 0; i < SIZE; ++i)
          ary[i] = 0;
}

//-------------------------------------------------------
// Name: prep_double_array
// PreCondition:  an unsigned int arrays is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_unsigned_int_array(unsigned int ary[])
// making sure all values within the array are set to 0;
{
     for (long unsigned int i = 0; i < SIZE; ++i)
          ary[i] = 0;
}

//-------------------------------------------------------
// Name: prep_string_array
// PreCondition:  a string arrays is pass in
// PostCondition: data in the array is "N/A" out to determine if
// a value has changed
//---------------------------------------------------------
void prep_string_array(std::string ary[])
// making sure all values within the array are set to "N/A";
{
     for (long unsigned int i = 0; i < SIZE; ++i)
          ary[i] = "N/A";
}

//-------------------------------------------------------
// Name: get_ranking
// PreCondition:  just the time array is passed in, and has valid data
// PostCondition: after a very inefficient nested loop to determine the placements
// and places the ranks in a new array. That new array is returned
//---------------------------------------------------------
void get_ranking(const double timeArray[], unsigned int rankArray[]) {
     for (unsigned int i = 0; i < SIZE; ++i)
          rankArray[i] = 0;

     int count;

     for (unsigned int i = 0; i < SIZE; ++i) {
          count = 0;
          for (unsigned int j = 0; j < SIZE; ++j)
               if (timeArray[j] > timeArray[i])
                    ++count;
          rankArray[i] = SIZE - count;
          // cout << "Count Larger than " << timeArray[i] << ":\t" << count << "\n";
          // cout << "Rank:\t" << rankArray[i] << "\n";
     }
}

//-------------------------------------------------------
// Name: print_results
// PreCondition:  almost all parallel arrays are passed in and have valid data
// PostCondition: after a very inefficient nested loop to determine the ranks
// it then displays then along with a delta in time from the start
//---------------------------------------------------------
void print_results(const double timeArray[], const std::string countryArray[],
                   const std::string lastnameArray[], const unsigned int rankArray[]) {

     std::cout << "Final results!!";
     std::cout << std::setprecision(2) << std::showpoint << std::fixed << "\n";
     double best_time = 0.0;

     // print the results, based on rank, but measure the time difference_type
     for (unsigned int j = 1; j <= SIZE; j++) {

          // go thru each array, find who places in "i" spot
          for (unsigned int i = 0; i < SIZE; i++) {
               if (rankArray[i] == 1) // has to be a better way, but need the starting time
               {
                    best_time = timeArray[i];
               }

               if (rankArray[i] == j) // then display this person's data
               {
                    // this needs precision display
                    std::cout << "[" << j << "]  " << timeArray[i] << " " << std::setw(15) << std::left << lastnameArray[i] << "\t"
                         << "(" << countryArray[i] << ")  +" << (timeArray[i] - best_time) << "\n";
               }
          }
     }
}

std::string trim(std::string ret) {
     // remove whitespace from the beginning
     while (!ret.empty() && isspace(ret.at(0))) {
          ret.erase(0, 1);
     }

     // remove whitespace from the end
     //  Note: last index is (.size() - 1) due to 0 based indexing
     while (!ret.empty() && isspace(ret.at(ret.size() - 1))) {
          ret.erase(ret.size() - 1, 1);
     }

     return ret;
}