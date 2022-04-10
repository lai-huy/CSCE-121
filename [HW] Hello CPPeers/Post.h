/*
 *
 * This code is copyrighted (c) 2021 by
 * Texas A&M Computer Science
 *
 *	There will be RIGOROUS cheat checking on your exams!!
 *	DON'T POST ANYWHERE!! such as CHEGG, public Github, etc
 *  You will be legally responsible.
 */

#ifndef _POST_H
#define _POST_H

#include <string>
#include <vector>

// the class definition for network post

class Post {
private:
  unsigned int postId;
  std::string userName;
  std::string postText;
public:
  Post(unsigned int postId, std::string userName, std::string postText);
  unsigned int getPostId();
  std::string getPostUser();
  std::string getPostText();
  std::vector<std::string> findTags();
};

#endif
