#include <iostream>
#include <string>
using std::cin, std::cout, std::string;
using std::flush;

int main() {
     string input = "";
     string deop = "";

     cout << "Please enter obfuscated sentence: " << flush;
     cin >> input;
     cout << "Please enter deobfuscation details: " << flush;
     cin >> deop;

     string result;
     int index = 0;

     for (char c : deop) {
          result += input.substr(index, (int)(c - '0')) + " ";
          index += (int)(c - '0');
     }

     cout << "Deobfuscated sentence: " << result << "\n";
     return 0;
}
