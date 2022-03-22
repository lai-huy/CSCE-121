#include <iostream>
#include <string>
#include "logic.h"

using std::cout, std::endl;
using std::to_string;

// TODO(student): Write unit tests for the functions in logic.h
//                You should end up with at least 500 lines of test code

char _map0[5][3] = {
    {'M', '+', '-'},
    {'-', '+', '-'},
    {'-', '+', '!'},
    {'o', '-', '-'},
    {'@', '-', '$'}};

char _map1[4][4] =
    {{'-', '!', '+', '+'},
     {'$', 'o', 'M', '+'},
     {'+', '@', '-', '-'},
     {'+', '?', '-', '+'}};

char _map3[5][5] =
    {{'-', '-', 'M', '-', '-'},
     {'-', '-', '+', '-', '-'},
     {'M', '+', 'o', '+', 'M'},
     {'-', '-', '+', '-', '-'},
     {'-', '-', 'M', '-', '-'}};

// Deallocates the Map
void deallocMap(char **&map, int maxRow)
{
     if (map)
     {
          for (int i = 0; i < maxRow; ++i)
          {
               delete[] map[i];
          }
          delete[] map;
          map = nullptr;
     }
}

// Converts a static array into a dynamic array
template <int r, int c>
char **static_to_dynamic(char arr[r][c])
{
     char **t = new char *[r];
     for (int i = 0; i < r; ++i)
     {
          t[i] = new char[c];
          for (int j = 0; j < c; ++j)
          {
               t[i][j] = arr[i][j];
          }
     }
     return t;
}

// Print the map to console
void printMap(char **map, const int maxRow) {
     cout << "-------------------------\n";
     for (int i = 0; i < maxRow; ++i)
          cout << map[i] << "\n";
     cout << "-------------------------\n";
}

void test_loadLevel()
{
     cout << "\n\n---------------------------------------------\n";
     cout << "Test loadLevel\n";

     int maxRow;
     int maxCol;
     Player player;
     char **level;

     cout << "Test loading valid map\n";
     level = loadLevel("map_valid.txt", maxRow, maxCol, player);
     deallocMap(level, maxRow);

     cout << "\nTest loading from a file that does not exist\n";
     level = loadLevel("file_dne.txt", maxRow, maxCol, player);
     deallocMap(level, maxRow);

     cout << "\nTest loading map with letter rows\n";
     level = loadLevel("rc_r_alph.txt", maxRow, maxCol, player);
     deallocMap(level, maxRow);

     cout << "\nTest loading map with letter columns\n";
     level = loadLevel("rc_c_alph.txt", maxRow, maxCol, player);
     deallocMap(level, maxRow);

     cout << "\nTest loading map with negative rows\n";
     level = loadLevel("rc_r_neg.txt", maxRow, maxCol, player);
     deallocMap(level, maxRow);

     cout << "\nTest loading map with negative columns\n";
     level = loadLevel("rc_c_neg.txt", maxRow, maxCol, player);
     deallocMap(level, maxRow);

     cout << "\nTest loading map with too many tiles\n";
     level = loadLevel("rc_large.txt", maxRow, maxCol, player);
     deallocMap(level, maxRow);

     cout << "\nTest loading map with player letter rows\n";
     level = loadLevel("player_pos_alph_r.txt", maxRow, maxCol, player);
     deallocMap(level, maxRow);

     cout << "\nTest loading map with player letter columns\n";
     level = loadLevel("player_pos_alph_c.txt", maxRow, maxCol, player);
     deallocMap(level, maxRow);

     cout << "\nTest loading map with player out of pounds vertically negative\n";
     level = loadLevel("player_oob_neg_r.txt", maxRow, maxCol, player);
     deallocMap(level, maxRow);

     cout << "\nTest loading map with player out of pounds horizontally negative\n";
     level = loadLevel("player_oob_neg_c.txt", maxRow, maxCol, player);
     deallocMap(level, maxRow);

     cout << "\nTest loading map with player out of pounds vertically positive\n";
     level = loadLevel("player_oob_pos_r.txt", maxRow, maxCol, player);
     deallocMap(level, maxRow);

     cout << "\nTest loading map with player out of pounds horizontally positive\n";
     level = loadLevel("player_oob_pos_c.txt", maxRow, maxCol, player);
     deallocMap(level, maxRow);

     cout << "\nTest loading map with invalid tiles\n";
     level = loadLevel("map_invalid.txt", maxRow, maxCol, player);
     deallocMap(level, maxRow);

     cout << "\nTest loading an empty file\n";
     level = loadLevel("empty_file.txt", maxRow, maxCol, player);
     deallocMap(level, maxRow);

     cout << "\nTest loading an empty map with non-zero dimensions\n";
     level = loadLevel("map_empty.txt", maxRow, maxCol, player);
     deallocMap(level, maxRow);

     cout << "\nTest loading a map with more tiles than indicated by dimensions\n";
     level = loadLevel("map_too_many_tiles.txt", maxRow, maxCol, player);
     deallocMap(level, maxRow);

     cout << "\nTest loading map with not enough tiles\n";
     level = loadLevel("map_too_few_tiles.txt", maxRow, maxCol, player);
     deallocMap(level, maxRow);

     cout << "\nTest loading a map with no exit\n";
     level = loadLevel("map_no_exit.txt", maxRow, maxCol, player);
     deallocMap(level, maxRow);

     cout << "DONE \u0028\u256f\u00b0\u25a1\u00b0\uff09\u256f\ufe35 \u253b\u2501\u253b\n";
     cout << "---------------------------------------------\n\n";
}

void test_getDirection()
{
     cout << "\n\n---------------------------------------------\n";
     cout << "Test getDirection\n";

     int nextRow = 0, nextCol = 0;

     getDirection(MOVE_UP, nextRow, nextCol);
     getDirection(MOVE_DOWN, nextRow, nextCol);
     getDirection(MOVE_LEFT, nextRow, nextCol);
     getDirection(MOVE_RIGHT, nextRow, nextCol);
     getDirection('W', nextRow, nextCol);
     getDirection('S', nextRow, nextCol);
     getDirection('A', nextRow, nextCol);
     getDirection('D', nextRow, nextCol);
     getDirection('\u0020', nextRow, nextCol);
     getDirection('L', nextRow, nextCol);

     cout << "DONE \u0028\u256f\u00b0\u25a1\u00b0\uff09\u256f\ufe35 \u253b\u2501\u253b\n";
     cout << "---------------------------------------------\n\n";
}

void test_deleteMap()
{
     cout << "\n\n---------------------------------------------\n";
     cout << "Test deleteMap\n";
     cout << "Delete non-nullptr\n";
     int maxRow = 5;
     char **map = static_to_dynamic<5, 3>(_map0);

     deleteMap(map, maxRow);
     deallocMap(map, maxRow);

     cout << "\nDelete nullptr\n";
     map = nullptr;
     deleteMap(map, maxRow);

     cout << "DONE \u0028\u256f\u00b0\u25a1\u00b0\uff09\u256f\ufe35 \u253b\u2501\u253b\n";
     cout << "---------------------------------------------\n\n";
}

void test_resizeMap()
{
     cout << "\n\n---------------------------------------------\n";
     cout << "Test resizeMap\n";

     cout << "Test resize when row and col are both positive\n";
     int maxRow = 4, maxCol = 4;
     char **map1_ptr = static_to_dynamic<4, 4>(_map1);

     cout << "Before\n";
     INFO(map1_ptr);
     INFO(maxRow);
     INFO(maxCol);

     /**
      * why does gradescope not like me doing this?
      * It I keep it resized, gradescope tells me
      * "The autograder failed to execute correctly.
      * Contact your course staff for help in debugging this issue.
      * Make sure to include a link to this page so that they can help you most effectively."
      */
     map1_ptr = resizeMap(map1_ptr, maxRow, maxCol);

     deallocMap(map1_ptr, maxRow);

     cout << "After\n";
     INFO(map1_ptr);
     INFO(maxRow);
     INFO(maxCol);

     // Test if maxRow and maxCol are negative.
     cout << "\nTest resize when row and col are both negative\n";
     maxRow = -4, maxCol = -4;
     map1_ptr = static_to_dynamic<4, 4>(_map1);
     cout << "Before\n";
     INFO(map1_ptr);
     INFO(maxRow);
     INFO(maxCol);

     char** resized = resizeMap(map1_ptr, maxRow, maxCol);

     cout << "After\n";
     INFO(map1_ptr);
     INFO(resized);
     INFO(maxRow);
     INFO(maxCol);

     deallocMap(map1_ptr, 4);

     // Test if maxRow is positive and maxCol is negative.
     cout << "\nTest resize when row is positve and col is negative\n";

     cout << "DONE \u0028\u256f\u00b0\u25a1\u00b0\uff09\u256f\ufe35 \u253b\u2501\u253b\n";
     cout << "---------------------------------------------\n\n";
}

void test_doPlayerMove()
{
     cout << "\n\n---------------------------------------------\n";
     cout << "Test doPlayerMove\n";

     Player player;
     player.col = 0;
     player.row = 3;
     player.treasure = 0;

     int maxRow = 5, maxCol = 3;
     char **map = static_to_dynamic<5, 3>(_map0);

     cout << "Test momvement with no treasure\n";
     for (int i = -1; i <= maxRow; ++i)
          for (int j = -1; j <= maxCol; ++j)
          {
               cout << "Test move to (" << to_string(i) << ", " << to_string(j) << ")\n";
               doPlayerMove(map, maxRow, maxCol, player, i, j);
               cout << "\n";
          }

     cout << "Test momvement with treasure\n";
     player.treasure = 1;
     for (int i = -1; i <= maxRow; ++i)
          for (int j = -1; j <= maxCol; ++j)
          {
               cout << "Test move to (" << to_string(i) << ", " << to_string(j) << ")\n";
               doPlayerMove(map, maxRow, maxCol, player, i, j);
               cout << "\n";
          }

     for (int i = 0; i < maxRow; ++i)
          delete[] map[i];
     delete[] map;

     cout << "DONE \u0028\u256f\u00b0\u25a1\u00b0\uff09\u256f\ufe35 \u253b\u2501\u253b\n";
     cout << "---------------------------------------------\n\n";
}

void test_doMonsterAttack()
{
     cout << "\n\n---------------------------------------------\n";
     cout << "Test doMonsterAttack\n";

     Player player;
     player.row = 3;
     player.col = 0;
     player.treasure = 1;

     int maxRow = 5, maxCol = 5;
     char **monster_map = static_to_dynamic<5, 5>(_map3);
     printMap(monster_map, maxRow);

     INFO(maxCol);
     INFO_STRUCT(player);

     // bool result = doMonsterAttack(map, maxRow, maxCol, player);
     // INFO(result);

     deallocMap(monster_map, maxRow);
     INFO(monster_map);

     cout << "DONE \u0028\u256f\u00b0\u25a1\u00b0\uff09\u256f\ufe35 \u253b\u2501\u253b\n";
     cout << "---------------------------------------------\n\n";
}

int main()
{
     test_loadLevel();
     test_getDirection();
     test_resizeMap();
     test_doPlayerMove();
     // test_doMonsterAttack();
     test_deleteMap();

     return 0;
}