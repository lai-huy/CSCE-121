
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

void deallocMap(char **map, int maxRow)
{
     if (map)
     {
          for (int i = 0; i < maxRow; ++i)
               delete[] map[i];
          delete[] map;
     }
}

template<int r, int c>
char **createMap(char _map[r][c])
{
     char** map = new char*[r];
     for (int i = 0; i < r; ++i)
     {
          map[i] = new char[c];
          for (int j = 0; j < c; ++j)
               map[i][j] = _map[i][j];
     }

     return map;
}

void test_loadLevel()
{
     cout << "\n\n---------------------------------------------\n";
     cout << "Test loadLevel\n";

     int maxRow;
     int maxCol;
     Player player;
     char ** level;

     cout << "Test loading valid map\n";
     level = loadLevel("example_valid.txt", maxRow, maxCol, player);
     deallocMap(level, maxRow);

     cout << "\nTest loading from a file that does not exist\n";
     level = loadLevel("example_file_dne.txt", maxRow, maxCol, player);
     deallocMap(level, maxRow);

     cout << "\nTest loading map with negative rows and columns\n";
     level = loadLevel("example_rc_neg.txt", maxRow, maxCol, player);
     deallocMap(level, maxRow);

     cout << "\nTest loading map with letter dimensions\n";
     level = loadLevel("example_rc_alph.txt", maxRow, maxCol, player);
     deallocMap(level, maxRow);
     
     cout << "\nTest loading map with player out of pounds negatively\n";
     level = loadLevel("example_player_oob_neg.txt", maxRow, maxCol, player);
     deallocMap(level, maxRow);

     cout << "\nTest loading map with player out of pounds positively\n";
     level = loadLevel("example_player_oob_pos.txt", maxRow, maxCol, player);
     deallocMap(level, maxRow);

     cout << "\nTest loading map with player at floating point coords\n";
     level = loadLevel("example_invalid_player_pos.txt", maxRow, maxCol, player);
     deallocMap(level, maxRow);

     cout << "\nTest loading the player on top of a Monster\n";
     level = loadLevel("example_player_monster.txt", maxRow, maxCol, player);
     deallocMap(level, maxRow);

     cout << "\nTest loading the player on top of Treasure\n";
     level = loadLevel("example_player_treasure.txt", maxRow, maxCol, player);
     deallocMap(level, maxRow);
     
     cout << "\nTest loading map with invalid tiles\n";;
     level = loadLevel("example_invalid_map.txt", maxRow, maxCol, player);
     deallocMap(level, maxRow);
     
     cout << "\nTest loading an empty file\n";
     level = loadLevel("example_empty_file.txt", maxRow, maxCol, player);
     deallocMap(level, maxRow);
     
     cout << "\nTest loading a 0 x 0 map\n";
     level = loadLevel("example_map_zero.txt", maxRow, maxCol, player);
     deallocMap(level, maxRow);
     
     cout << "\nTest loading an empty map with non-zero dimensions\n";
     level = loadLevel("example_map_empty.txt", maxRow, maxCol, player);
     deallocMap(level, maxRow);
     
     cout << "\nTest loading a map with more data than dimensions indicate\n";
     level = loadLevel("example_map_big.txt", maxRow, maxCol, player);
     deallocMap(level, maxRow);
     
     cout << "\nTest loading a map with no exit\n";
     level = loadLevel("example_map_no_exit.txt", maxRow, maxCol, player);
     deallocMap(level, maxRow);
     
     cout << "\nTest loading a map with no treasure\n";
     level = loadLevel("example_map_no_treasure.txt", maxRow, maxCol, player);
     deallocMap(level, maxRow);
     
     cout << "\nTest loading a map with multiple exits\n";
     level = loadLevel("example_map_multiple_exits.txt", maxRow, maxCol, player);
     deallocMap(level, maxRow);

     cout << "DONE \u0028\u256f\u00b0\u25a1\u00b0\uff09\u256f\ufe35 \u253b\u2501\u253b\n";
     cout << "---------------------------------------------\n\n";
}

void test_getDirection()
{
     cout << "\n\n---------------------------------------------\n";
     cout << "Test getDirection\n";

     int nextRow = 0, nextCol = 0;

     for (int i = 0; i < 128; ++i)
     {
          cout << "Testing input: " << (char)i << "\n";
          getDirection((char)i, nextRow, nextCol);
          cout << "\n";
     }

     cout << "DONE \u0028\u256f\u00b0\u25a1\u00b0\uff09\u256f\ufe35 \u253b\u2501\u253b\n";
     cout << "---------------------------------------------\n\n";
}

void test_deleteMap()
{
     cout << "\n\n---------------------------------------------\n";
     cout << "Test deleteMap\n";
     cout << "Delete non-nullptr\n";
     int maxRow = 5;
     char **map = createMap<5, 3>(_map0);

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
     int maxRow = 5, maxCol = 3;
     char **map = createMap<5,3>(_map0);

     cout << "Before\n";
     INFO(maxRow);
     INFO(maxCol);
     
     char **resized = resizeMap(map, maxRow, maxCol);
     INFO(resized);
     
     cout << "After\n";
     INFO(maxRow);
     INFO(maxCol);

     deallocMap(resized, 10);

     /*
     cout << "\nTest resize when row and col are both negative\n";
     map = createMap<5, 3>(_map0);
     maxRow = -4;
     maxCol = -4;
     
     cout << "Before\n";
     INFO(maxRow);
     INFO(maxCol);
     resized = resizeMap(map, maxRow, maxCol);
     
     cout << "After\n";
     INFO(maxRow);
     INFO(maxCol);

     dealloc_map(map, 5);
     dealloc_map(resized, 10);

     cout << "\nTest resize when row is positive and col is negative\n";
     map = createMap<5, 3>(_map0);
     maxRow = 5;
     maxCol = -3;

     cout << "Before\n";
     INFO(maxRow);
     INFO(maxCol);
     resized = resizeMap(map, maxRow, maxCol);
     
     cout << "After\n";
     INFO(maxRow);
     INFO(maxCol);

     deallocMap(map, 5);
     deallocMap(resized, 10);
     */

     deallocMap(map, 5);

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
     char **map = createMap<5, 3>(_map0);

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

     int maxRow = 5, maxCol = 3;
     char **map = createMap<5, 3>(_map0);

     INFO(maxCol);
     INFO_STRUCT(player);

     // bool result = doMonsterAttack(map, maxRow, maxCol, player);
     // INFO(result);

     deallocMap(map, maxRow);

     cout << "DONE \u0028\u256f\u00b0\u25a1\u00b0\uff09\u256f\ufe35 \u253b\u2501\u253b\n";
     cout << "---------------------------------------------\n\n";
}

int main()
{
     /*
     ////////////////////
     // this is optional but STRONGLY recommended for preparing for part 2 (development)
     //   coverage -/-> correctness
     // note: there are _many_ ways to do this part, including ways that are more elegant and efficient than this way demonstrated here
     if (level == nullptr)
          cout << "FAIL: level is nullptr"
               << "\n";
     else
     {
          cout << " OK : level is not nullptr"
               << "\n";
          if (maxRow == 5)
               cout << " OK : maxRow is 5"
                    << "\n";
          else
               cout << "FAIL: expected maxRow to be 5, got " << maxRow << "\n";

          if (maxCol == 3)
               cout << " OK : maxCol is 3"
                    << "\n";
          else
               cout << "FAIL: expected maxCol to be 3, got " << maxCol << "\n";

          if (player.row == 3)
               cout << " OK : player.row is 3"
                    << "\n";
          else
               cout << "FAIL: expected player.row to be 3, got " << player.row << "\n";

          if (player.col == 0)
               cout << " OK : player.col is 0"
                    << "\n";
          else
               cout << "FAIL: expected player.col to be 0, got " << player.col << "\n";

          if (level[0][0] == 'M')
               cout << " OK : level[0][0] is M"
                    << "\n";
          else
               cout << "FAIL: expected level[0][0] to be M, got " << level[0][0] << "\n";

          if (level[0][1] == '+')
               cout << " OK : level[0][1] is +"
                    << "\n";
          else
               cout << "FAIL: expected level[0][1] to be +, got " << level[0][1] << "\n";

          if (level[0][2] == '-')
               cout << " OK : level[0][2] is -"
                    << "\n";
          else
               cout << "FAIL: expected level[0][2] to be -, got " << level[0][2] << "\n";

          if (level[1][0] == '-')
               cout << " OK : level[1][0] is -"
                    << "\n";
          else
               cout << "FAIL: expected level[1][0] to be -, got " << level[1][0] << "\n";

          if (level[1][1] == '+')
               cout << " OK : level[1][1] is +"
                    << "\n";
          else
               cout << "FAIL: expected level[1][1] to be +, got " << level[1][1] << "\n";
          if (level[1][2] == '-')
               cout << " OK : level[1][2] is -"
                    << "\n";
          else
               cout << "FAIL: expected level[1][2] to be -, got " << level[1][2] << "\n";
          if (level[2][0] == '-')
               cout << " OK : level[2][0] is -"
                    << "\n";
          else
               cout << "FAIL: expected level[2][0] to be -, got " << level[2][0] << "\n";
          if (level[2][1] == '+')
               cout << " OK : level[2][1] is +"
                    << "\n";
          else
               cout << "FAIL: expected level[2][1] to be +, got " << level[2][1] << "\n";
          if (level[2][2] == '!')
               cout << " OK : level[2][2] is !"
                    << "\n";
          else
               cout << "FAIL: expected level[2][2] to be !, got " << level[2][2] << "\n";
          if (level[3][0] == 'o')
               cout << " OK : level[3][0] is o"
                    << "\n";
          else
               cout << "FAIL: expected level[3][0] to be o, got " << level[3][0] << "\n";
          if (level[3][1] == '-')
               cout << " OK : level[3][1] is -"
                    << "\n";
          else
               cout << "FAIL: expected level[3][1] to be -, got " << level[3][1] << "\n";
          if (level[3][2] == '-')
               cout << " OK : level[3][2] is -"
                    << "\n";
          else
               cout << "FAIL: expected level[3][2] to be -, got " << level[3][2] << "\n";
          if (level[4][0] == '@')
               cout << " OK : level[4][0] is @"
                    << "\n";
          else
               cout << "FAIL: expected level[4][0] to be @, got " << level[4][0] << "\n";
          if (level[4][1] == '-')
               cout << " OK : level[4][1] is -"
                    << "\n";
          else
               cout << "FAIL: expected level[4][1] to be -, got " << level[4][1] << "\n";
          if (level[4][2] == '$')
               cout << " OK : level[4][2] is $"
                    << "\n";
          else
               cout << "FAIL: expected level[4][2] to be $, got " << level[4][2] << "\n";
     }
     ////////////////////
     */

     test_loadLevel();
     test_getDirection();
     test_resizeMap();
     //test_doPlayerMove();
     //test_doMonsterAttack();
     //test_deleteMap();

     return 0;
}