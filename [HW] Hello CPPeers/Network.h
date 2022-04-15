#ifndef _NETWORK_H
#define _NETWORK_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
#include <stdexcept>

#include "User.h"
#include "Post.h"
#include "Tag.h"

using std::vector, std::string;

/**
 * @brief the cass definition for the social network
 * 
 */
class Network
{
private:
     vector<User *> users;
     vector<Post *> posts;
     vector<Tag *> tags;
     User* userExists(const string& userName);

public:
     Network();
     ~Network();
     void loadFromFile(string fileName);
     void addUser(string userName);
     void addPost(unsigned int postId, string userName, string postText);
     vector<Post *> getPostsByUser(string userName);
     vector<Post *> getPostsWithTag(string tagName);
     vector<string> getMostPopularHashtag();
};

#endif
