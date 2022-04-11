#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
#include <stdexcept>

#include "User.h"

using std::cout;
using std::string, std::vector, std::invalid_argument;

User::User(string userName) : userName{userName}, userPosts{vector<Post *>()}
{
     if (this->userName == "")
          throw invalid_argument("user name cannot be empty");

     for (char c : this->userName) {
          if (!isalpha(c))
               throw invalid_argument("user name must contain only lowercase letters");
          if (!islower(c))
               throw invalid_argument("user name must container only lowercase letters.");
     }
}

string User::getUserName()
{
     return this->userName;
}

vector<Post *> &User::getUserPosts()
{
     return this->userPosts;
}

void User::addUserPost(Post *post)
{
     if (post == nullptr)
          throw invalid_argument("post cannot be nullptr");
     this->userPosts.push_back(post);
}
