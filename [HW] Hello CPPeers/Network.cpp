#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
#include <stdexcept>

#include "Network.h"

using std::cout;
using std::exception, std::invalid_argument, std::runtime_error;
using std::ifstream, std::stringstream;
using std::string, std::vector;

/**
 * @brief Construct a new Network:: Network object
 *
 * Empty containers of vectors already created
 * no implementation is needed here
 */
Network::Network() : users{ vector<User*>() }, posts{ vector<Post*>() }, tags{ vector<Tag*>() } {}

/**
 * @brief loads Network from a file
 *
 * @param fileName  file to load from
 * @throws std::invalid_argument if file cannot be opened
 * @throws std::runtime_error if User or Post does not follow the specified format.
 */
void Network::loadFromFile(string fileName) {
     ifstream fin(fileName);
     if (!fin.is_open())
          throw invalid_argument("File " + fileName + " cannot be opened");

     string line;
     vector<string> split;
     stringstream ss;

     while (!fin.eof()) {
          split.clear();
          ss.clear();

          getline(fin, line);

          if (line == "")
               return;

          ss << line;
          string word = "";

          while (!ss.eof()) {
               ss >> word;
               split.push_back(word);
          }

          string operation = split.at(0);
          if (operation == "User") {
               try {
                    this->addUser(split.at(1));
               } catch (const exception& err) {
                    throw runtime_error(err.what());
               }
          } else if (operation == "Post") {
               size_t sz = split.size();
               if (sz < 4)
                    throw runtime_error("invalid post format");

               unsigned int id = 0;

               try {
                    id = (unsigned int)stoi(split.at(1));
               } catch (const exception& err) {
                    throw runtime_error(err.what());
               }

               string name = split.at(2);

               string post = "";

               for (size_t i = 3; i < sz; ++i)
                    post += split.at(i) + (i != sz - 1 ? " " : "");

               try {
                    this->addPost(id, name, post);
               } catch (const exception& err) {
                    throw runtime_error(err.what());
               }
          } else
               throw runtime_error("Unknown entry:\t" + line);
     }
}

/**
 * @brief create user and add it to Network
 *
 * @param userName std::string holding the username
 * @throws std::invalid_argument if the user is already in the Network
 */
void Network::addUser(string userName) {
     // cout << "Adding user " << userName << "\n";
     for (size_t i = 0; i < userName.size(); ++i)
          userName.at(i) = tolower(userName.at(i));

     for (User* user : this->users) {
          if (user->getUserName() == userName)
               throw invalid_argument(userName + " is already in the network.");
     }

     this->users.push_back(new User(userName));
     cout << "Added User " << userName << "\n";
}

/**
 * @brief create post and add it to Network
 *
 * @param postId    unsigned int unique
 * @param userName  std::string holding the username
 * @param postText  std::string holding the text of the post
 */
void Network::addPost(unsigned int postId, string userName, string postText) {
     // cout << "Checking if posts already exists\n";
     for (Post* post : this->posts) {
          if (post->getPostId() == postId)
               throw invalid_argument("Post with id " + std::to_string(postId) + " is already in the network.");
     }

     // cout << "Checking if user does not exist\n";
     User* user = this->userExists(userName);
     if (user == nullptr)
          throw invalid_argument("User " + userName + " is not in the network.");

     // cout << "Creating post\n";
     Post* post = new Post(postId, userName, postText);

     // Find the tags for the post created
     // There is probably a better way to do this but I'm too lazy to optimize
     bool exists = false;
     for (string tag_name : post->findTags()) {
          exists = false;
          for (Tag* tag : this->tags) {
               if (tag->getTagName() == tag_name) {
                    tag->addTagPost(post);
                    exists = true;
                    break;
               }
          }

          // If tag found is currently not in the Network
          if (!exists) {
               try {
                    Tag* new_tag = new Tag(tag_name);
                    new_tag->addTagPost(post);
                    this->tags.push_back(new_tag);
               } catch (const exception& err) {
                    continue;
               }
          }
     }

     user->addUserPost(post);      // Add post to user
     this->posts.push_back(post);  // Add post to Network
     cout << "Added Post " << std::to_string(postId) << " by " << userName << "\n";
     return;
}

/**
 * @brief Determins is a User is already in the Network
 *
 * @param userName const std::string& user to find
 * @return User*   a pointer to the user found. If user is not found, nullptr is returned
 */
User* Network::userExists(const string& userName) {
     for (User* user : this->users)
          if (user->getUserName() == userName)
               return user;

     return nullptr;
}

/**
 * @brief get all the posts made by a user
 *
 * @param userName            std::string user to find
 * @return vector<Post *>     a vector of pointers to Posts made by a user
 */
vector<Post*> Network::getPostsByUser(string userName) {
     if (userName.empty())
          throw invalid_argument("User name cannot be empty");

     for (User* user : this->users)
          if (user->getUserName() == userName)
               return user->getUserPosts();

     throw invalid_argument("User " + userName + " does not exist in the network.");
}

/**
 * @brief get all the posts with a given Tag
 *
 * @param tagName             std::string tag to find.
 * @return vector<Post *>     a vector of pointers to Posts with the given tag.
 */
vector<Post*> Network::getPostsWithTag(string tagName) {
     if (tagName.empty())
          throw invalid_argument("Tag name cannot be empty");

     for (Tag* tag : this->tags)
          if (tag->getTagName() == tagName)
               return tag->getTagPosts();

     throw invalid_argument("Tag " + tagName + " does not exist in the network");
}

/**
 * @brief finds the Tag(s) that occur in the most number of posts.
 *
 * @return vector<string> a vector of the tag names that occur in the most posts.
 */
vector<string> Network::getMostPopularHashtag() {

     size_t max = 0;
     for (Tag* tag : this->tags) {
          size_t s = tag->getTagPosts().size();
          if (s > max)
               max = s;
     }

     vector<string> temp = vector<string>();
     for (Tag* tag : this->tags)
          if (tag->getTagPosts().size() == max)
               temp.push_back(tag->getTagName());

     return temp;
}

/**
 * @brief Destructor
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
