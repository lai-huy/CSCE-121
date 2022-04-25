
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <limits>
#include <cstdlib>
#include <vector>
#include <ctime>
#include "TemperatureDatabase.h"

using std::string, std::to_string, std::cout;
using std::ifstream, std::ofstream;
using std::stringstream;
using std::tm, std::localtime, std::time, std::time_t;
using std::vector;

// Default constructor/destructor. Modify them if you need to.
TemperatureDatabase::TemperatureDatabase() : records{LinkedList()}, curr_year{0} {
     time_t t = time(0);
     tm* now = localtime(&t);
     this->curr_year = now->tm_year + 1900;
}

TemperatureDatabase::~TemperatureDatabase() {}

void TemperatureDatabase::loadData(const string& filename) {
     ifstream fin(filename);

     if (!fin.is_open()) {
          cout << "Error: Unable to open " << filename << "\n";
          exit(1);
     }

     string line = "";
     stringstream ss;

     string id = ""; int year = 0; int month = 0; double temperature = 0;

     while (true) {
          getline(fin, line);

          if (fin.eof())
               break;

          ss.clear();
          ss.str(string());
          ss << line;

          ss >> id;
          if (ss.fail()) {
               cout << "Error: Other invalid input\n";
               continue;
          }

          ss >> year;
          if (ss.fail()) {
               cout << "Error: Other invalid input\n";
               continue;
          }

          if (year < 1800 || year > this->curr_year) {
               cout << "Error: Invalid year " << to_string(year) << "\n";
               continue;
          }

          ss >> month;
          if (ss.fail()) {
               cout << "Error: Other invalid input\n";
               continue;
          }

          if (month < 1 || month > 12) {
               cout << "Error: Invalid month " << to_string(month) << "\n";
               continue;
          }

          ss >> temperature;
          if (ss.fail()) {
               cout << "Error: Other invalid input\n";
               continue;
          }

          if ((temperature < -50 && temperature != -99.99) || temperature > 50) {
               cout << "Error: Invalid temperature " << to_string(temperature) << "\n";
               continue;
          }

          this->records.insert(id, year, month, temperature);
     }
}

// Do not modify
void TemperatureDatabase::outputData(const string& filename) {
     ofstream dataout("sorted." + filename);

     if (!dataout.is_open()) {
          cout << "Error: Unable to open " << filename << "\n";
          exit(1);
     }
     dataout << records.print();
}

void TemperatureDatabase::performQuery(const string& filename) {
     ifstream fin(filename);
     if (!fin.is_open()) {
          cout << "Error: Unable to open " << filename << "\n";
          exit(1);
     }

     ofstream fout("results.dat");

     if (!fout.is_open()) {
          cout << "Error: Unable to open results.dat\n";
          exit(1);
     }

     string line = string();
     stringstream ss = stringstream();
     string id = string(), op = string();
     int start = 0, end = 0;
     while (true) {
          getline(fin, line);

          if (fin.eof())
               return;

          ss.clear();
          ss.str(line);

          ss >> id;
          if (ss.fail()) {
               cout << "Error: Other invalid input\n";
               continue;
          }

          ss >> op;
          if (ss.fail()) {
               cout << "Error: Other invalid input\n";
               continue;
          }

          if (op != "AVG" && op != "MODE") {
               cout << "Error: Invalid query " << op << "\n";
               continue;
          }

          ss >> start;
          if (ss.fail()) {
               cout << "Error: Other invalid input\n";
               continue;
          }

          ss >> end;
          if (ss.fail()) {
               cout << "Error: Other invalid input\n";
               continue;
          }

          if (start < 1800 || start > this->curr_year) {
               cout << "Error: Invalid range " << to_string(start) << "-" << to_string(end) << "\n";
               continue;
          }

          if (end < start) {
               cout << "Error: Invalid range " << to_string(start) << "-" << to_string(end) << "\n";
               continue;
          }

          if (op == "AVG") {
               fout << this->average(id, start, end);
          }

          if (op == "MODE") {
               fout << this->mode(id, start, end);
          }
     }
}

string TemperatureDatabase::average(string id, int start, int end) {
     cout << "AVERAGE\n";
     cout << "ID:\t" << id << "\n";
     cout << "Start:\t" << to_string(start) << "\n";
     cout << "End:\t" << to_string(end) << "\n\n\n";

     Node* node = this->records.getHead();
     double sum = 0; int count = 0;

     while (node->next != nullptr) {
          TemperatureData data = node->data;

          if (data.id == id) {
               if (start <= data.year && data.year <= end) {
                    cout << data << "\n";
                    sum += data.temperature;
                    ++count;
               }
          }

          node = node->next;
     }

     string avg = count == 0 ? "unknown" : to_string(sum / count);
     avg.erase(avg.find_last_not_of('0') + 1, string::npos);
     if (avg.back() == '.')
          avg = avg.substr(0, avg.size() - 1);

     cout << "Average:\t" << avg << "\n";

     return id + " " + to_string(start) + " " + to_string(end) + " AVG " + avg + "\n";
}

string TemperatureDatabase::mode(string id, int start, int end) {
     cout << "MODE\n";
     cout << "ID:\t" << id << "\n";
     cout << "Start:\t" << to_string(start) << "\n";
     cout << "End:\t" << to_string(end) << "\n\n\n";

     Node* node = this->records.getHead();
     vector<int> counts = vector(101, 0);

     while (node->next != nullptr) {
          TemperatureData data = node->data;

          if (data.id == id) {
               if (start <= data.year && data.year <= end) {
                    cout << data << "\n";
                    cout << "Temp:\t" << to_string(round(data.temperature)) << "\n";
                    ++counts.at(round(data.temperature) + 50);
               }
          }

          node = node->next;
     }

     int max = -1, index = 0;
     for (size_t i = 0; i < counts.size(); ++i) {
          if (counts.at(i) >= max) {
               max = counts.at(i);
               index = static_cast<int>(i) - 50;
          }
     }

     string mode = max == 0 ? "unknown" : to_string(index);
     cout << "Mode:\t" << mode << "\n";

     return id + " " + to_string(start) + " " + to_string(end) + " MODE " + mode + "\n";
}

int TemperatureDatabase::round(double num) {
     if (num < 0)
          return (num - (int)num) > -0.5 ? static_cast<int>(num) : static_cast<int>(num) - 1;
     return (num - (int)num) < 0.5 ? static_cast<int>(num) : static_cast<int>(num) + 1;
}
