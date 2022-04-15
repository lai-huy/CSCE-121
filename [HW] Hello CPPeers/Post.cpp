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

Post::Post(unsigned int postId, string userName, string postText) : postId{postId}, userName{userName}, postText{postText}
{

     if (this->postId == 0)
          throw invalid_argument("Post cannot have an postId of 0.");
     
     if (this->userName.empty())
          throw invalid_argument("Post cannot have an empty user name.");
     
     if (this->postText.empty())
          throw invalid_argument("Post cannot have an empty postText");
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
     string word;

     while (!ss.eof())
     {
          ss >> word;
          if (word.at(0) == '#')
          {
               string tag = "";
               for (char c : word)
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