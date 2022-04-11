#ifndef _TAG_H
#define _TAG_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
#include <stdexcept>

#include "Post.h"

using std::string, std::vector;

// the class definition for the hashtags included within posts

class Tag
{
private:
     string tagName;
     vector<Post *> tagPosts;

public:
     Tag(string tagName);
     string getTagName();
     vector<Post *> &getTagPosts();
     void addTagPost(Post *post);
};

#endif
