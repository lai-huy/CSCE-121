#ifndef TEMP_DB
#define TEMP_DB

#include <string>
#include "LinkedList.h"

class TemperatureDatabase {
public:
	TemperatureDatabase();
	~TemperatureDatabase();

	// The two functions below are required

	// Read the temperature records from the data file and populate the linked list
	// Implement for Part 1
	void loadData(const std::string& data_file);
		
	// Output the data as ordered in the linked list (useful for debugging part 1)
	void outputData(const std::string& out_file);

	// Read the queries from the query file and perform a series of queries
	// Implement for Part 2
	void performQuery(const std::string& query_filename);

private:
	// Linked list to store the temperature records. You need to properly populate
	// this link list.
	LinkedList records;

	// You can add any private member variables/functions you feel useful in this class.
     int curr_year;

     string average(string id, int start, int end);
     string mode(string id, int start, int end);
     int round(double num);
};

#endif  // TEMP_DB
