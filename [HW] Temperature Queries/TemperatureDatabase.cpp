#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <limits>
#include <cstdlib>
#include <vector>
#include <ctime>
#include "TemperatureDatabase.h"

using std::string;
using std::to_string;
using std::cout;
using std::ifstream;
using std::ofstream;
using std::stringstream;
using std::tm;
using std::localtime;
using std::time;
using std::time_t;
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

     string line = string();
     stringstream ss;

     string id = string(); int year = 0; int month = 0; double temperature = 0;

     while (true) {
          line = string();
          getline(fin, line);

          if (fin.eof() && line.empty())
               break;

          ss.clear();
          ss.str(line);

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

     ofstream fout("result.dat");

     if (!fout.is_open()) {
          cout << "Error: Unable to open result.dat\n";
          exit(1);
     }

     string line = string();
     stringstream ss = stringstream();
     vector<string> split = vector<string>();
     int start = 0, end = 0;
     while (true) {
          split.clear();
          line = string();
          getline(fin, line);

          if (fin.eof() && line.empty())
               return;

          ss.clear();
          ss.str(line);
          while (!ss.eof()) {
               string word = string();
               ss >> word;
               split.push_back(word);
          }

          if (split.size() != 4) {
               cout << "Error: Other invalid query\n";
               continue;
          }

          if (split.at(1) != "AVG" && split.at(1) != "MODE") {
               cout << "Error: Unsupported query " << split.at(1) << "\n";
               continue;
          }

          try {
               start = stoi(split.at(2));
          } catch (const std::exception& err) {
               cout << "Error: Other invalid input\n";
               continue;
          }

          try {
               end = stoi(split.at(3));
          } catch (const std::exception& err) {
               cout << "Error: Other invalid input\n";
               continue;
          }

          if (end < start) {
               cout << "Error: Invalid range " << split.at(2) << "-" << split.at(3) << "\n";
               continue;
          }

          if (start < 1800 || start > curr_year) {
               cout << "Error: Invalid range " << split.at(2) << "-" << split.at(3) << "\n";
               continue;
          }

          if (end < 1800 || end > curr_year) {
               cout << "Error: Invalid range " << split.at(2) << "-" << split.at(3) << "\n";
               continue;
          }

          if (split.at(1) == "AVG") {
               fout << average(split.at(0), start, end);
          }

          if (split.at(1) == "MODE") {
               fout << mode(split.at(0), start, end);
          }
     }
}

string TemperatureDatabase::average(string id, int start, int end) {
     // cout << "\n\nAVERAGE\n";
     // cout << "ID:\t" << id << "\n";
     // cout << "Start:\t" << to_string(start) << "\n";
     // cout << "End:\t" << to_string(end) << "\n";

     Node* node = this->records.getHead();
     double sum = 0; int count = 0;

     while (node != nullptr) {
          TemperatureData data = node->data;

          if (data.id == id) {
               if (start <= data.year && data.year <= end) {
                    // cout << data << "\n";
                    sum += data.temperature;
                    ++count;
               }
          }

          node = node->next;
     }

     string avg = count ? to_string(this->round((sum / count) * 10000.0) / 10000.0) : "unknown";


     if (avg != "unknown") {
          avg.erase(avg.find_last_not_of('0') + 1, string::npos);
          if (avg.back() == '.')
               avg = avg.substr(0, avg.size() - 1);
     }

     // cout << "Average:\t" << avg << "\n";

     return id + " " + to_string(start) + " " + to_string(end) + " AVG " + avg + "\n";
}

string TemperatureDatabase::mode(string id, int start, int end) {
     // cout << "\n\nMODE\n";
     // cout << "ID:\t" << id << "\n";
     // cout << "Start:\t" << to_string(start) << "\n";
     // cout << "End:\t" << to_string(end) << "\n";

     Node* node = this->records.getHead();
     vector<int> counts = vector<int>(101, 0);

     while (node != nullptr) {
          TemperatureData data = node->data;

          if (data.id == id) {
               if (start <= data.year && data.year <= end) {
                    // cout << data << "\n";
                    // cout << "Temp:\t" << to_string(round(data.temperature)) << "\n";
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
     // cout << "Mode:\t" << mode << "\n";

     return id + " " + to_string(start) + " " + to_string(end) + " MODE " + mode + "\n";
}

int TemperatureDatabase::round(double num) {
     return num < 0 ? static_cast<int>(num - 0.5) : static_cast<int>(num + 0.5);
}
