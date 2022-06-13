#include <iostream>
#include "helper.h"
using std::cout;

/**
 * @brief Print instructions to the console. DO NOT CHANGE
 *
 */
void printInstructions() {
     cout << "\n";
     cout << "---------------------------------------------------------" << "\n";
     cout << "Good day, adventurer!" << "\n";
     cout << "Your goal is to get the treasure and escape the dungeon!" << "\n";
     cout << " --- SYMBOLS ---" << "\n";
     cout << " o          : That is you, the adventurer!" << "\n";
     cout << " $          : These are treasures. Lots of money!" << "\n";
     cout << " @          : These magical amulets resize the level." << "\n";
     cout << " M          : These are monsters; avoid them!" << "\n";
     cout << " +, -, |    : These are unpassable obstacles." << "\n";
     cout << " ?          : A door to another level." << "\n";
     cout << " !          : A door to escape the dungeon." << "\n";
     cout << " --- CONTROLS ---" << "\n";
     cout << " w, a, s, d : Keys for moving up, left, down, and right." << "\n";
     cout << " e          : Key for staying still for a turn." << "\n";
     cout << " q          : Key for abandoning your quest." << "\n";
     cout << "---------------------------------------------------------" << "\n";
     cout << "\n";
}

/**
 * @brief Print the map to console. DO NOT CHANGE
 *
 * @param map       pointer to the map to print
 * @param maxRow    the number of rows in the map
 * @param maxCol    the number of columns in the map
 */
void outputMap(char** map, const int maxRow, const int maxCol) {
     // output top border
     cout << "+";
     for (int i = 0; i < maxCol * DISPLAY_WIDTH; ++i) {
          cout << "-";
     }
     cout << "+";
     cout << "\n";

     for (int i = 0; i < maxRow; ++i) {
          // output left border
          cout << "|";

          // output inner blocks
          for (int j = 0; j < maxCol; ++j) {
               // output current block
               cout << " ";
               if (map[i][j] == TILE_OPEN) {
                    cout << " ";
               } else {
                    cout << map[i][j];
               }
               cout << " ";
          }

          // output right border
          cout << "|";
          cout << "\n";
     }

     // output bottom border
     cout << "+";
     for (int i = 0; i < maxCol * DISPLAY_WIDTH; ++i) {
          cout << "-";
     }
     cout << "+";
     cout << "\n";
}

/**
 * @brief Output the status of player movement to the console. DO NOT CHANGE
 *
 * @param status    The status of player movement
 * @param player    the player
 * @param moves     the number of moves the player had made.
 */
void outputStatus(const int status, const Player& player, int moves) {
     if (status != STATUS_STAY) {
          cout << "You have moved to row " << player.row << " and column " << player.col << "\n";
     }
     switch (status) {
     case STATUS_STAY:
          cout << "You stayed at row " << player.row << " and column " << player.col << "\n";
          cout << "You didn't move. Are you lost?" << "\n";
          break;
     case STATUS_MOVE:
          break;
     case STATUS_TREASURE:
          cout << "Well done, adventurer! You found some treasure." << "\n";
          cout << "You now have " << player.treasure << (player.treasure > 1 ? " treasures." : " treasure.") << "\n";
          break;
     case STATUS_AMULET:
          cout << "The magic amulet sparkles and crumbles into dust." << "\n";
          cout << "The ground begins to rumble. Are the walls moving?" << "\n";
          break;
     case STATUS_LEAVE:
          cout << "You go through the doorway into the unknown beyond..." << "\n";
          break;
     case STATUS_ESCAPE:
          cout << "Congratulations, adventurer! You have escaped the dungeon!" << "\n";
          cout << "You escaped with " << player.treasure << (player.treasure > 1 ? " treasures " : " treasure ");
          cout << "and in " << moves << " total moves." << "\n";
          break;
     }
     cout << "\n";
}
