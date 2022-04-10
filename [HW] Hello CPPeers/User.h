/*
 *
 * This code is copyrighted (c) 2021 by
 * Texas A&M Computer Science
 *
 *	There will be RIGOROUS cheat checking on your exams!!
 *	DON'T POST ANYWHERE!! such as CHEGG, public Github, etc
 *  You will be legally responsible.
 */

#ifndef _USER_H
#define _USER_H

#include <string>
#include <vector>
#include "Post.h"

// the class definition for the network user

class User {
private:
  std::string userName;
  std::vector<Post*> userPosts;
public:
  User(std::string userName);
  std::string getUserName();
  std::vector<Post*>& getUserPosts();
  void addUserPost(Post* post);
};

#endif
