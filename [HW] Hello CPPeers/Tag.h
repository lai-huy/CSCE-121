/*
 *
 * This code is copyrighted (c) 2021 by
 * Texas A&M Computer Science
 *
 *	There will be RIGOROUS cheat checking on your exams!!
 *	DON'T POST ANYWHERE!! such as CHEGG, public Github, etc
 *  You will be legally responsible.
 */

#ifndef _TAG_H
#define _TAG_H

#include <string>
#include <vector>
#include "Post.h"

// the class definition for the hashtags included within posts

class Tag {
private:
  std::string tagName;
  std::vector<Post*> tagPosts;
public:
  Tag(std::string tagName);
  std::string getTagName();
  std::vector<Post*>& getTagPosts();
  void addTagPost(Post* post);
};

#endif
