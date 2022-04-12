#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
#include <stdexcept>

#include "Tag.h"

using std::string, std::vector, std::invalid_argument;

/**
 * @brief Construct a new Tag:: Tag object
 *
 * @param tagName std::string tag name
 * @throws std::invalid_argument if tag name is empty or does not start with #
 * @throws std::invalid_argument if tag name does not contain only lowercase letters.
 */
Tag::Tag(string tagName) : tagName{tagName}, tagPosts{vector<Post *>()}
{
     if (this->tagName.length() < 2)
          throw invalid_argument("Tag name is too short.");

     if (this->tagName.at(0) != '#')
          throw invalid_argument("Tag name must start with '#'.");

     for (size_t i = 1; i < this->tagName.size(); ++i)
     {
          char c = this->tagName.at(i);
          if (!isalpha(c))
               throw invalid_argument("Tag name must contain only lowercase letters.");
          if (!islower(c))
               throw invalid_argument("Tag name must container only lowercase letters.");
     }
}

string Tag::getTagName()
{
     return this->tagName;
}

vector<Post *> &Tag::getTagPosts()
{
     return this->tagPosts;
}

/**
 * @brief add post to tag posts
 *
 * @param post Post to add
 * @throws std::invalid_argument if post is nullptr
 */
void Tag::addTagPost(Post *post)
{
     if (post == nullptr)
          throw invalid_argument("post cannot be nullptr");
     this->tagPosts.push_back(post);
}
