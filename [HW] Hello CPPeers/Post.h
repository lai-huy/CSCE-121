#ifndef _POST_H
#define _POST_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
#include <stdexcept>

using std::string, std::vector;

// the class definition for network post

class Post
{
private:
     unsigned int postId;
     string userName;
     string postText;

public:
     Post(unsigned int postId, string userName, string postText);
     unsigned int getPostId();
     string getPostUser();
     string getPostText();
     vector<std::string> findTags();
};

#endif
