#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
#include <stdexcept>

#include "Network.h"

using std::cout;
using std::string, std::vector;
using std::ifstream, std::stringstream;
using std::exception, std::invalid_argument, std::runtime_error;

/**
 * @brief Construct a new Network:: Network object
 * 
 * Empty containers of vectors already created
 * no implementation is needed here
 */
Network::Network() : users{vector<User *>()}, posts{vector<Post *>()}, tags{vector<Tag *>()}
{
     return;
}

/**
 * @brief 
 * 
 * @param fileName 
 * @throws std::invalid_argument if file cannot be opened
 * @throws std::runtime_error if User or Post does not follow the specified format.
 */
void Network::loadFromFile(string fileName)
{
     ifstream fin(fileName);
     ifstream f(fileName);
     if (!fin.is_open())
          throw std::invalid_argument("File " + fileName + " cannot be opened");
     
     string line;
     vector<string> split;
     stringstream ss;

     // while (!f.eof()) {
     //      getline(f, line);
     //      cout << line << "\n";
     // }

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
               // cout << word << "\n";
          }
          // cout << "\n";

          string op = split.at(0);
          if (op == "User") {
               // cout << "Adding user\n";
               try {
                    this->addUser(split.at(1));
               } catch (const exception& err) {
                    throw runtime_error(err.what());
               }
          } else if (op == "Post") {
               // cout << "Adding post\n";
               size_t sz = split.size();
               if (sz < 4)
                    throw runtime_error("invalid post format");

               unsigned int id = 0;

               try {
                    id = (unsigned int) stoi(split.at(1));
               } catch (const exception& err) {
                    throw runtime_error(err.what());
               }

               string name = split.at(2);

               string post = "";

               for (size_t i = 3; i < sz; ++i) {
                    post += split.at(i);
                    if (i != sz - 1)
                         post += " ";
               }
               try {
                    this->addPost(id, name, post);
               } catch (const exception& err) {
                    throw runtime_error(err.what());
               }
          } else {
               throw runtime_error("Unknown entry:\t" + line);
          }
     }
}

/**
 * @brief create user and add it to Network
 * 
 * @param userName std::string holding the username
 * @throws std::invalid_argument if the user is already in the Network
 */
void Network::addUser(string userName)
{
     for (User * user : this->users) {
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
void Network::addPost(unsigned int postId, string userName, string postText)
{
     // cout << "Checking if posts already exists\n";
     for (Post * post : this->posts) {
          if (post->getPostId() == postId)
               throw invalid_argument("Post with id " + std::to_string(postId) + " is already in the network.");
     }

     // cout << "Checking if user does not exist\n";
     bool exists = false;
     User * u = nullptr;
     for (User * user : this->users) {
          if (user->getUserName() == userName) {
               exists = true;
               u = user;
               break;
          }
     }

     if (!exists)
          throw invalid_argument("User " + userName + " is not in the network.");

     // cout << "Creating post\n";
     Post * p = new Post(postId, userName, postText);

     // cout << "Finding tags\n";

     for (string tag : p->findTags()) {
          exists = false;
          for (Tag * t : this->tags) {
               if (t->getTagName() == tag) {
                    t->addTagPost(p);
                    exists = true;
                    break;
               }
          }

          if (!exists) {
               try {
                    Tag* new_tag = new Tag(tag);
                    new_tag->addTagPost(p);
                    this->tags.push_back(new_tag);
               } catch (std::exception& err) {
                    continue;
               }
          }
     }

     this->posts.push_back(p);
     u->addUserPost(p);
     cout << "Added Post " << std::to_string(postId) << " by " << userName << "\n";
}

/**
 * @brief 
 * 
 * @param userName 
 * @return vector<Post *> 
 */
vector<Post *> Network::getPostsByUser(string userName)
{
     vector<Post *> temp;

     for (Post *post : this->posts) {
          if (post->getPostUser() == userName)
               temp.push_back(post);
     }

     return temp;
}

vector<Post *> Network::getPostsWithTag(string tagName)
{
     vector<Post *> temp;

     for (Post *post : this->posts)
          for (string tag : post->findTags())
               if (tag == tagName)
                    temp.push_back(post);

     return temp;
}

vector<string> Network::getMostPopularHashtag()
{
     vector<int> counts = vector<int>(this->tags.size());

     for (size_t i = 0; i < this->tags.size(); ++i) {
          int count = 0;
          for (Tag * tag : this->tags) {
               if (tag->getTagName() == this->tags.at(i)->getTagName())
                    ++count;
          }
          counts.at(i) = count;
     }

     int max;
     for (int i : counts)
          if (i > max)
               max = i;

     vector<string> temp = vector<string>();
     for (size_t i = 0; i < this->tags.size(); ++i) {
          if (counts.at(i) == max) {
               bool exists = false;
               string tag_name = this->tags.at(i)->getTagName();
               for (string name : temp) {
                    if (name == tag_name) {
                         exists = true;
                         break;
                    }
               }

               if (!exists)
                    temp.push_back(tag_name);
          }
     }

     return temp;
}

/**
 * Destructor
 * Do not change; already implemented.
 */
Network::~Network()
{
     for (unsigned int i = 0; i < users.size(); ++i)
     {
          delete users.at(i);
     }
     for (unsigned int i = 0; i < tags.size(); ++i)
     {
          delete tags.at(i);
     }
     for (unsigned int i = 0; i < posts.size(); ++i)
     {
          delete posts.at(i);
     }
}
