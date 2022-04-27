#ifndef TEMP_DB
#define TEMP_DB

#include <string>
#include "LinkedList.h"

using std::string;

class TemperatureDatabase {
public:
     /**
      * @brief Default constuctor
      */
     TemperatureDatabase();

     /**
      * @brief Destructor
      */
     ~TemperatureDatabase();

     // The two functions below are required

     // Read the temperature records from the data file and populate the linked list
     // Implement for Part 1
     void loadData(const string& data_file);

     // Output the data as ordered in the linked list (useful for debugging part 1)
     void outputData(const string& out_file);

     // Read the queries from the query file and perform a series of queries
     // Implement for Part 2
     void performQuery(const string& query_filename);

private:
     /**
      * @brief LinkedList to store the temperature records.
      */
     LinkedList records;

     // You can add any private member variables/functions you feel useful in this class.
     /**
      * @brief the year this program was ran
      */
     int curr_year;

     /**
      * @brief Determine the average temperature from the start to end year.
      * 
      * @param id        location to query
      * @param start     start year
      * @param end       end year
      * @return string   formated output
      */
     string average(string id, int start, int end);

     /**
      * @brief Determine the mode temperature from the start to end year.
      * 
      * @param id        location to query
      * @param start     start year
      * @param end       end year
      * @return string   formatted output
      */
     string mode(string id, int start, int end);

     /**
      * @brief round the input to the nearest int
      * 
      * @param num  double to round
      * @return int neared int
      */
     int round(double num);
};

#endif  // TEMP_DB
