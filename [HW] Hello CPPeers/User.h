#ifndef _USER_H
#define _USER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
#include <stdexcept>

#include "Post.h"

using std::string, std::vector;

// the class definition for the network user

class User
{
private:
     string userName;
     vector<Post *> userPosts;

public:
     User(string userName);
     string getUserName();
     vector<Post *> &getUserPosts();
     void addUserPost(Post *post);
};

#endif
