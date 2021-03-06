#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
#include <stdexcept>

#include "Network.h"

using std::cout, std::cin;
using std::string, std::vector, std::exception;

void printMenu() {
     cout << "Welcome to CPPeers" << "\n";
     cout << "The options are: " << "\n";
     cout << "1. load data file and add information" << "\n";
     cout << "2. show posts by user" << "\n";
     cout << "3. show posts with hashtag" << "\n";
     cout << "4. show most popular hashtag" << "\n";
     cout << "9. quit" << "\n";
     cout << "--------> Enter your option: ";
}

void processLoad(Network& cppeers) {
     string fileName = "";
     cout << "Enter filename: ";
     cin >> fileName;
     cppeers.loadFromFile(fileName);
}

void processPostsByUser(Network& cppeers) {
     string user = "";
     cout << "Enter username: ";
     cin >> user;
     for (Post* post : cppeers.getPostsByUser(user))
          cout << post->getPostText() << "\n";
}

void processPostsWithHashtags(Network& cppeers) {
     string tag = "";
     cout << "Enter tagname: ";
     cin >> tag;
     for (Post* post : cppeers.getPostsWithTag(tag))
          cout << post->getPostText() << "\n";
}

void processMostPopularHashtag(Network& cppeers) {
     for (string tag : cppeers.getMostPopularHashtag())
          cout << tag << "\n";
}

int main() {
     try {
          Network cppeers;

          int choice = 0;

          // present menu
          do {
               printMenu();
               cin >> choice;
               if (cin.fail())
                    choice = 9;

               switch (choice) {
               case 1:
               {
                    processLoad(cppeers);
                    break;
               }
               case 2:
               {
                    processPostsByUser(cppeers);
                    break;
               }
               case 3:
               {
                    processPostsWithHashtags(cppeers);
                    break;
               }
               case 4:
               {
                    processMostPopularHashtag(cppeers);
                    break;
               }
               }
          } while (choice != 9);
     } catch (const exception& exc) {
          cout << exc.what() << "\n";
     }

     return 0;
}
