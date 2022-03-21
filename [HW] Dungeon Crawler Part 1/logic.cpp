#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>
#include "logic.h"

using std::string, std::cout, std::cin;
using std::ifstream, std::stringstream;
using std::invalid_argument;

char** loadLevel(const string& fileName, int& maxRow, int& maxCol, Player& player) {
     ifstream fin(fileName);
     if (!fin.is_open())
          throw invalid_argument("Cannot open file");
     
     fin >> maxRow >> maxCol;

     if (fin.fail())
          throw invalid_argument("Encountered non-integer for row and col");

     if (maxRow < 0)
          throw invalid_argument("maxRow must be positive");
     
     if (maxCol < 0)
          throw invalid_argument("maxCol must be positive");

     fin >> player.row >> player.col;
     player.treasure = 0;

     char **map = new char*[maxRow];
     for (int i = 0; i < maxRow; ++i)
          map[i] = new char[maxCol];

     stringstream ss;

     string line;
     getline(fin, line);

     for (int row = 0; row < maxRow; ++row) {
          getline(fin, line);
          ss << line;
          for (int col = 0; col < maxCol; ++col)
               ss >> map[row][col];
          ss.clear();
     }

     map[player.row][player.col] = TILE_PLAYER;

     return map;
}

void getDirection(char input, int& nextRow, int& nextCol) {
     //INFO(input);
     //INFO(nextRow);
     //INFO(nextCol);

     switch (input) {
     case INPUT_QUIT:
          return;
     case INPUT_STAY:
          break;
     case MOVE_UP:
          --nextRow;
          break;
     case MOVE_DOWN:
          ++nextRow;
          break;
     case MOVE_LEFT:
          --nextCol;
          break;
     case MOVE_RIGHT:
          ++nextCol;
          break;
     default:
          break;
     }

     return;
}

void deleteMap(char **&map, int &maxRow) {
     INFO(map);
     INFO(maxRow);
     return;
}

char** resizeMap(char** map, int& maxRow, int& maxCol) {
     if (map == nullptr)
          throw std::invalid_argument("map is nullptr");

     if (maxRow < 1)
          throw std::domain_error("maxRow is non-positive");
     if (maxCol < 1)
          throw std::domain_error("maxCol is non-positive");

     const int og_row = maxRow, og_col = maxCol;

     char** temp = new char*[maxRow * 2];
     for (int i = 0; i < maxRow * 2; ++i)
          temp[i] = new char[maxCol * 2];

     for (int row = 0; row < og_row; ++row)
          for (int col = 0; col < og_col; ++col) {
               temp[row][col] = map[row][col];
               temp[row][col + og_col] = map[row][col] == TILE_PLAYER ? TILE_OPEN : map[row][col];
               temp[row + og_row][col + og_col] = map[row][col] == TILE_PLAYER ? TILE_OPEN : map[row][col];
               temp[row + og_row][col] = map[row][col] == TILE_PLAYER ? TILE_OPEN : map[row][col];
          }

     //deleteMap(map, maxRow);
     maxRow *= 2;
     maxCol *= 2;

     return temp;
}

int doPlayerMove(char** map, int maxRow, int maxCol, Player& player, int nextRow, int nextCol) {
     //INFO(map);
     //INFO(maxRow);
     //INFO(maxCol);
     //INFO_STRUCT(player);
     //INFO(nextRow);
     //INFO(nextCol);

     if (nextRow < 0) {
          player.row = 0;
          return STATUS_STAY;
     } if (nextRow >= maxRow) {
          player.row = maxRow - 1;
          return STATUS_STAY;
     }
     if (nextCol < 0) {
          return STATUS_STAY;
     } if (nextCol >= maxCol) {
          return STATUS_STAY;
     }
     
     switch (map[nextRow][nextCol]) {
          case TILE_PILLAR:
          case TILE_MONSTER:
               return STATUS_STAY;
          case TILE_TREASURE:
               ++player.treasure;
               return STATUS_TREASURE;
          case TILE_AMULET:
               return STATUS_AMULET;
          case TILE_DOOR:
               return STATUS_LEAVE;
          case TILE_EXIT:
               if (player.treasure > 0)
                    return STATUS_ESCAPE;
               return STATUS_STAY;
          case TILE_OPEN:
               return STATUS_MOVE;
          default:
               return STATUS_STAY;
     }
}

bool doMonsterAttack(char** map, int maxRow, int maxCol, Player player) {
     INFO(map);
     INFO(maxRow);
     INFO(maxCol);
     INFO_STRUCT(player);
     return false;
}
