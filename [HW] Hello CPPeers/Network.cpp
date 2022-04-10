/*
 *
 * This code is copyrighted (c) 2021 by
 * Texas A&M Computer Science
 *
 *	There will be RIGOROUS cheat checking on your exams!!
 *	DON'T POST ANYWHERE!! such as CHEGG, public Github, etc
 *  You will be legally responsible.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Network.h"

using std::string;
using std::vector;

Network::Network() {
  // empty containers of vectors already created
  // no implementation is needed here
}

void Network::loadFromFile(string fileName) {
  // TODO(student): load user and post information from file
}

void Network::addUser(string userName) {
  // TODO(student): create user and add it to network
}

void Network::addPost(unsigned int postId, string userName, string postText) {
  // TODO(student): create post and add it to network
}

vector<Post*> Network::getPostsByUser(string userName) {
  // TODO(student): return posts created by the given user
}

vector<Post*> Network::getPostsWithTag(string tagName) {
  // TODO(student): return posts containing the given tag
}

vector<string> Network::getMostPopularHashtag() {
  // TODO(student): return the tag occurring in most posts
}

/**
  * Destructor
  * Do not change; already implemented.
  */
Network::~Network() {
  for (unsigned int i = 0; i < users.size(); ++i) {
    delete users.at(i);
  }
  for (unsigned int i = 0; i < tags.size(); ++i) {
    delete tags.at(i);
  }
  for (unsigned int i = 0; i < posts.size(); ++i) {
    delete posts.at(i);
  }
}
