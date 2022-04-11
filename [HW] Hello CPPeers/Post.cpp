#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
#include <stdexcept>

#include "Post.h"

using std::cout;
using std::string, std::vector, std::stringstream, std::invalid_argument;

Post::Post(unsigned int postId, string userName, string postText)
    : postId(postId), userName(userName), postText(postText)
{
     if (postId == 0 || userName == "" || postText == "")
     {
          throw invalid_argument("post constructor: invalid parameter values");
     }
}

unsigned int Post::getPostId()
{
     return this->postId;
}

string Post::getPostUser()
{
     return this->userName;
}

string Post::getPostText()
{
     return this->postText;
}

vector<string> Post::findTags()
{
     vector<string> temp;
     stringstream ss(this->postText);
     string s;

     while (!ss.eof())
     {
          ss >> s;
          if (s.at(0) == '#')
          {
               string tag = "";
               for (char c : s)
               {
                    switch (c)
                    {
                    case '!':
                         continue;
                    case ',':
                         continue;
                    case '.':
                         continue;
                    case '?':
                         continue;
                    default:
                         tag += tolower(c);
                    }
               }
               temp.push_back(tag);
          }
     }

     return temp;
}