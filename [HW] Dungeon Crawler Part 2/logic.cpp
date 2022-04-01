#include <iostream>
#include <fstream>
#include <string>
#include "logic.h"

using std::cout, std::endl, std::ifstream, std::string;

/**
 * TODO: Student implement this function
 * Load representation of the dungeon level from file into the 2D map.
 * Calls createMap to allocate the 2D array.
 * @param   fileName    File name of dungeon level.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference to set starting position.
 * @return  pointer to 2D dynamic array representation of dungeon map with player's location., or nullptr if loading fails for any reason
 * @updates  maxRow, maxCol, player
 */
char **loadLevel(const string &fileName, int &maxRow, int &maxCol, Player &player)
{
     ifstream fin(fileName);

     if (!fin.is_open())
     {
          // cout << fileName << " cannot be opened.\n";
          return nullptr;
     }
     // cout << fileName << " is opened.\n";

     fin >> maxRow;
     if (fin.fail())
     {
          // cout << "maxRow is non-numeric.\n";
          return nullptr;
     }
     // cout << "maxRow is numeric\n";

     if (maxRow < 1)
     {
          // cout << "maxRow < 1\n";
          return nullptr;
     }
     // cout << "maxRow is >= 1\n";

     fin >> maxCol;
     if (fin.fail())
     {
          // cout << "maxCol is non-numeric.\n";
          return nullptr;
     }

     if (maxCol < 1)
     {
          // cout << "maxCol < 1\n";
          return nullptr;
     }
     // cout << "maxCol is >= 1\n";

     if (maxRow > INT32_MAX / maxCol)
     {
          // cout << "number of tiles is > 2147483647.\n";
          return nullptr;
     }
     // cout << "number of tiles is <= 2147483647.\n";

     fin >> player.row;
     if (fin.fail())
     {
          // cout << "player row is non-numeric.\n";
          return nullptr;
     }

     if (player.row < 0)
     {
          // cout << "player row is < 0\n";
          return nullptr;
     }
     // cout << "player row is >= 0\n";

     if (player.row >= maxRow)
     {
          // cout << "player row is >= maxRow\n";
          return nullptr;
     }
     // cout << "player row < maxRow\n";

     fin >> player.col;
     if (fin.fail())
     {
          // cout << "player col is non-numeric\n";
          return nullptr;
     }

     if (player.col < 0)
     {
          // cout << "player col is < 0\n";
          return nullptr;
     }

     if (player.col >= maxCol)
     {
          // cout << "player col >= maxCol\n";
          return nullptr;
     }
     // cout << "player col < maxCol\n";

     char **map = createMap(maxRow, maxCol);
     char tile = '\0';
     bool exit_exists = false;
     int count = 0, total = maxRow * maxCol;
     for (int i = 0; i < maxRow; ++i)
     {
          for (int j = 0; j < maxCol; ++j)
          {
               fin >> tile;
               // printf("%c", tile);

               if (fin.eof())
               {
                    if (count < total)
                    {
                         // cout << "not enough tiles in map.\n";
                         // cout << "bailing out\n";
                         deleteMap(map, maxRow);
                         return nullptr;
                    }
               }
               ++count;

               switch (tile)
               {
               case TILE_DOOR:
                    map[i][j] = tile;
                    exit_exists = true;
                    break;
               case TILE_EXIT:
                    map[i][j] = tile;
                    exit_exists = true;
                    break;
               case TILE_OPEN:
                    map[i][j] = tile;
                    break;
               case TILE_PLAYER:
                    map[i][j] = tile;
                    break;
               case TILE_TREASURE:
                    map[i][j] = tile;
                    break;
               case TILE_AMULET:
                    map[i][j] = tile;
                    break;
               case TILE_MONSTER:
                    map[i][j] = tile;
                    break;
               case TILE_PILLAR:
                    map[i][j] = tile;
                    break;
               default:
                    // cout << "invalid symbol in map.\n";
                    // cout << "bailing out\n";
                    deleteMap(map, maxRow);
                    return nullptr;
               }
          }
          // cout << "\n";
     }

     if (fin.peek() != EOF) {
          // cout << "too many tiles in map\n";
          deleteMap(map, maxRow);
          return nullptr;
     }

     if (!exit_exists)
     {
          // cout << "no way out\n";
          // cout << "bailing out\n";
          deleteMap(map, maxRow);
          return nullptr;
     }

     map[player.row][player.col] = TILE_PLAYER;

     return map;
}

/**
 * TODO: Student implement this function
 * Translate the character direction input by the user into row or column change.
 * That is, updates the nextRow or nextCol according to the player's movement direction.
 * @param   input       Character input by the user which translates to a direction.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @updates  nextRow, nextCol
 */
void getDirection(char input, int &nextRow, int &nextCol)
{
     // printf("%c\n", input);
     switch (tolower(input))
     {
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
          return;
     }
}

/**
 * TODO: [suggested] Student implement this function
 * Allocate the 2D map array.
 * Initialize each cell to TILE_OPEN.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @return  2D map array for the dungeon level, holds char type.
 */
char **createMap(int maxRow, int maxCol)
{
     if (maxRow < 0)
          return nullptr;

     if (maxCol < 0)
          return nullptr;

     char **map = new char *[maxRow];
     for (int i = 0; i < maxRow; ++i)
     {
          map[i] = new char[maxCol];
          for (int j = 0; j < maxCol; ++j)
               map[i][j] = TILE_OPEN;
     }

     return map;
}

/**
 * TODO: Student implement this function
 * Deallocates the 2D map array.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @return None
 * @update map, maxRow
 */
void deleteMap(char **&map, int &maxRow)
{
     // cout << "Deleting map " << map << "\n";
     if (map)
     {
          for (int i = 0; i < maxRow; ++i)
               delete[] map[i];
          delete[] map;
     }

     map = nullptr;
     maxRow = 0;
}

/**
 * TODO: Student implement this function
 * Resize the 2D map by doubling both dimensions.
 * Copy the current map contents to the right, diagonal down, and below.
 * Do not duplicate the player, and remember to avoid memory leaks!
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height), to be doubled.
 * @param   maxCol      Number of columns in the dungeon table (aka width), to be doubled.
 * @return  pointer to a dynamically-allocated 2D array (map) that has twice as many columns and rows in size.
 * @update maxRow, maxCol
 */
char **resizeMap(char **map, int &maxRow, int &maxCol)
{
     if (map == nullptr)
     {
          // cout << "map is nullptr\n";
          return nullptr;
     }

     if (maxRow < 1)
     {
          // cout << "maxRow < 1\n";
          return nullptr;
     }

     if (maxRow > INT32_MAX / 2)
     {
          // cout << "2 * maxRow > 2147483647\n";
          return nullptr;
     }

     if (maxCol < 1)
     {
          // cout << "maxCol < 1\n";
          return nullptr;
     }

     if (maxCol > INT32_MAX / 2)
     {
          // cout << "2 * maxCol > 2147483647\n";
          return nullptr;
     }

     int og_row = maxRow, og_col = maxCol;

     char **temp = new char *[maxRow * 2];
     for (int i = 0; i < maxRow * 2; ++i)
          temp[i] = new char[maxCol * 2];

     for (int row = 0; row < og_row; ++row)
          for (int col = 0; col < og_col; ++col)
          {
               temp[row][col] = map[row][col];
               temp[row][col + og_col] = map[row][col] == TILE_PLAYER ? TILE_OPEN : map[row][col];
               temp[row + og_row][col + og_col] = map[row][col] == TILE_PLAYER ? TILE_OPEN : map[row][col];
               temp[row + og_row][col] = map[row][col] == TILE_PLAYER ? TILE_OPEN : map[row][col];
          }

     deleteMap(map, og_row);
     maxRow *= 2;
     maxCol *= 2;

     return temp;
}

/**
 * TODO: Student implement this function
 * Checks if the player can move in the specified direction and performs the move if so.
 * Cannot move out of bounds or onto TILE_PILLAR or TILE_MONSTER.
 * Cannot move onto TILE_EXIT without at least one treasure.
 * If TILE_TREASURE, increment treasure by 1.
 * Remember to update the map tile that the player moves onto and return the appropriate status.
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object to by reference to see current location.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @return  Player's movement status after updating player's position.
 * @update map contents, player
 */
int doPlayerMove(char **map, int maxRow, int maxCol, Player &player, int nextRow, int nextCol)
{
     if (nextRow < 0)
     {
          // cout << "nextRow < 0\n";
          // cout << "next tile out of bounds\n";
          // cout << "don't move\n";
          return STATUS_STAY;
     }
     // cout << "nextRow >= 0\n";

     if (nextRow >= maxRow)
     {
          // cout << "nextRow >= maxRow\n";
          // cout << "next tile out of bounds\n";
          // cout << "don't move\n";
          return STATUS_STAY;
     }
     // cout << "nextRow < maxRow\n";

     if (nextCol < 0)
     {
          // cout << "nextCol < 0\n";
          // cout << "next tile out of bounds\n";
          // cout << "don't move\n";
          return STATUS_STAY;
     }

     if (nextCol >= maxCol)
     {
          // cout << "nextCol >= maxCol\n";
          // cout << "next tile out of bounds\n";
          // cout << "don't move\n";
          return STATUS_STAY;
     }
     // cout << "nextCol < maxCol\n";

     // Check what tile the player is moving to
     switch (map[nextRow][nextCol])
     {
     case TILE_MONSTER:
          // cout << "map[nextRow][nextCol] == TILE_MONSTER\n";
          // cout << "don't move\n";
          return STATUS_STAY;
     case TILE_PILLAR:
          // cout << "map[nextRow][nextCol] == TILE_PILLAR\n";
          // cout << "don't move\n";
          return STATUS_STAY;
     case TILE_AMULET:
          // cout << "found amulet\n";
          map[player.row][player.col] = TILE_OPEN;
          player.row = nextRow;
          player.col = nextCol;
          map[player.row][player.col] = TILE_PLAYER;
          // cout << "updated player location\n";
          return STATUS_AMULET;
     case TILE_TREASURE:
          // cout << "found treasure\n";
          map[player.row][player.col] = TILE_OPEN;
          player.row = nextRow;
          player.col = nextCol;
          map[player.row][player.col] = TILE_PLAYER;
          ++player.treasure;
          // cout << "updated player location\n";
          return STATUS_TREASURE;
     case TILE_DOOR:
          // cout << "found door\n";
          // cout << "updated player location\n";
          map[player.row][player.col] = TILE_OPEN;
          player.row = nextRow;
          player.col = nextCol;
          map[player.row][player.col] = TILE_PLAYER;
          return STATUS_LEAVE;
     case TILE_EXIT:
          if (player.treasure)
          {
               // cout << "found exit with treasure\n";
               // cout << "updated player location\n";
               map[player.row][player.col] = TILE_OPEN;
               player.row = nextRow;
               player.col = nextCol;
               map[player.row][player.col] = TILE_PLAYER;
               return STATUS_ESCAPE;
          }
          else
          {
               // cout << "found exit without treasure\n";
               // cout << "don't move\n";
               return STATUS_STAY;
          }
     case TILE_OPEN:
          map[player.row][player.col] = TILE_OPEN;
          player.row = nextRow;
          player.col = nextCol;
          map[player.row][player.col] = TILE_PLAYER;
          // cout << "updated player location\n";
          return STATUS_MOVE;
     default:
          // cout << "invalid character\n";
          // cout << "don't move\n";
          return STATUS_STAY;
     }
}

/**
 * TODO: Student implement this function
 * Update monster locations:
 * We check up, down, left, right from the current player position.
 * If we see an obstacle, there is no line of sight in that direction, and the monster does not move.
 * If we see a monster before an obstacle, the monster moves one tile toward the player.
 * We should update the map as the monster moves.
 * At the end, we check if a monster has moved onto the player's tile.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference for current location.
 * @return  Boolean value indicating player status: true if monster reaches the player, false if not.
 * @update map contents
 */
bool doMonsterAttack(char **map, int maxRow, int maxCol, const Player &player)
{
     char tile;
     bool eaten = false;
     // Check up
     for (int i = player.row - 1; i > -1; --i)
     {
          tile = map[i][player.col];
          if (tile == TILE_PILLAR)
          {
               // cout << "found pillar up\n";
               break;
          }
          else if (tile == TILE_MONSTER)
          {
               // cout << "found monster up\n";
               map[i][player.col] = TILE_OPEN;
               map[i + 1][player.col] = TILE_MONSTER;
               if (i + 1 == player.row)
               {
                    // cout << "eaten by monster\n";
                    eaten = true;
               }
          }
     }

     // Check down
     for (int i = player.row + 1; i < maxRow; ++i)
     {
          tile = map[i][player.col];
          if (tile == TILE_PILLAR)
          {
               // cout << "found pillar down\n";
               break;
          }
          else if (tile == TILE_MONSTER)
          {
               // cout << "found monster down\n";
               map[i][player.col] = TILE_OPEN;
               map[i - 1][player.col] = TILE_MONSTER;
               if (i - 1 == player.row)
               {
                    // cout << "eaten by monster\n";
                    eaten = true;
               }
          }
     }

     // Check left
     for (int j = player.col - 1; j > -1; --j)
     {
          tile = map[player.row][j];
          if (tile == TILE_PILLAR)
          {
               // cout << "found pillar left\n";
               break;
          }
          else if (tile == TILE_MONSTER)
          {
               // cout << "found monster left\n";
               map[player.row][j] = TILE_OPEN;
               map[player.row][j + 1] = TILE_MONSTER;
               if (j + 1 == player.col)
               {
                    // cout << "eaten by monster\n";
                    eaten = true;
               }
          }
     }

     // Check right
     for (int j = player.col + 1; j < maxCol; ++j)
     {
          tile = map[player.row][j];
          if (tile == TILE_PILLAR)
          {
               // cout << "found pillar right\n";
               break;
          }
          else if (tile == TILE_MONSTER)
          {
               // cout << "found monster right\n";
               map[player.row][j] = TILE_OPEN;
               map[player.row][j - 1] = TILE_MONSTER;
               if (j - 1 == player.col)
               {
                    // cout << "eaten by monster\n";
                    eaten = true;
               }
          }
     }

     return eaten;
}
