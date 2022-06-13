/*
This is an interface for invoking the functions, e.g. for testing.
You do not need to submit this file.
You may modify this file, e.g. to use unit tests.
*/

#include <iostream>
#include "functions.h"

using std::cout, std::cin;

enum Function : int {
     largest = 1,
     sum_is_even,
     boxes_needed,
     smarter_section,
     good_dinner,
     sum_between,
     product,
     exit_the_program
};

bool read_int(int* number) {
     cout << "Please enter an integer: ";
     cin >> *number;

     return !cin.fail();
}

void display_results(int function_id, const int* args, const char* function_names[], const int* num_args) {
     const char* function_name = function_names[function_id];
     int argc = num_args[function_id];
     cout << function_name << "(";
     if (argc > 0) {
          cout << args[0];
     }
     for (int i = 1; i < argc; i++) {
          cout << ", " << args[i];
     }
     cout << ") returned ";
     try {
          switch (function_id) {
          case largest:
               cout << Largest(args[0], args[1], args[2]) << "\n";
               break;
          case sum_is_even:
               cout << std::boolalpha << SumIsEven(args[0], args[1]) << "\n";
               break;
          case boxes_needed:
               cout << BoxesNeeded(args[0]) << "\n";
               break;
          case smarter_section:
               cout << std::boolalpha << SmarterSection(args[0], args[1], args[2], args[3]) << "\n";
               break;
          case good_dinner:
               cout << std::boolalpha << GoodDinner(args[0], static_cast<bool>(args[1])) << "\n";
               break;
          case sum_between:
               cout << SumBetween(args[0], args[1]) << "\n";
               break;
          case product:
               cout << Product(args[0], args[1]) << "\n";
               break;
          }
     } catch (const std::invalid_argument& err) {
          cout << "\b\b\b\b\b\b\b\b\bthrew an invalid_argument exception" << "\n";
     } catch (const std::overflow_error& err) {
          cout << "\b\b\b\b\b\b\b\b\bthrew an overflow_error exception" << "\n";
     } catch (...) {
          cout << "\b\b\b\b\b\b\b\b\bthrew an unknown thing" << "\n";
     }
}

void print_menu(const char* function_names[], int num_functions) {
     cout << "\n"
          << "=== Menu ===" << "\n";
     for (int id = 1; id < num_functions; id++) {
          cout << id << ") " << function_names[id] << "\n";
     }
     cout << ">> ";
}

int get_choice() {
     int choice;
     cin >> choice;
     if (cin.fail()) {
          std::cerr << "Input failed" << "\n";
          // exit
          choice = exit_the_program;
     }
     return choice;
}

bool get_args(int argc, int* argv) {
     for (int i = 0; i < argc; i++) {
          if (!read_int(&argv[i])) {
               return false;
          }
     }
     return true;
}

int main() {
     const char* function_names[] = {
         "",
         "Largest",
         "SumIsEven",
         "BoxesNeeded",
         "SmarterSection",
         "GoodDinner",
         "SumBetween",
         "Product",
         "Exit the program"};
     int num_args[] = {-1, 3, 2, 1, 4, 2, 2, 2, -1};
     int num_functions = sizeof(function_names) / sizeof(char*);
     int args[4]{0};
     int function_id;

     cout << "Welcome to the Debugging Homework for CS 12x!" << "\n";
     cout << "Please enter a number to run the function with the corresponding number: " << "\n";
     do {
          print_menu(function_names, num_functions);

          function_id = get_choice();
          if (function_id < 1 || function_id >= num_functions || function_id == exit_the_program) {
               // exit
               break;
          }

          bool is_valid = get_args(num_args[function_id], args);
          if (!is_valid) {
               cout << "Invalid input detected" << "\n";
               // exit
               break;
          }

          display_results(function_id, args, function_names, num_args);
     } while (function_id != 8 && !cin.fail());

     cout << "Exiting program." << "\n";

     return 0;
}
