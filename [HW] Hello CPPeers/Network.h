/*
 *
 * This code is copyrighted (c) 2021 by
 * Texas A&M Computer Science
 *
 *	There will be RIGOROUS cheat checking on your exams!!
 *	DON'T POST ANYWHERE!! such as CHEGG, public Github, etc
 *  You will be legally responsible.
 */

#ifndef _NETWORK_H
#define _NETWORK_H

#include <string>
#include <vector>
#include "User.h"
#include "Post.h"
#include "Tag.h"

// the class definition for the social network

class Network {
private:
  std::vector<User*> users;
  std::vector<Post*> posts;
  std::vector<Tag*> tags;
public:
  Network();
  ~Network();
  void loadFromFile(std::string fileName);
  void addUser(std::string userName);
  void addPost(unsigned int postId, std::string userName, std::string postText);
  std::vector<Post*> getPostsByUser(std::string userName);
  std::vector<Post*> getPostsWithTag(std::string tagName);
  std::vector<std::string> getMostPopularHashtag();
};

#endif
