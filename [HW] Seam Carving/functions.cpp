#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

using namespace std;
using std::cout;

// TODO Write this function
int energy(const Pixel *const *image, int col, int row, int width, int height)
{
     /**
     // Epic Debug Lines
     cout << "col:\t" << col << "\n";
     cout << "row:\t" << row << "\n";
     cout << "width:\t" << width << "\n";
     cout << "height:\t" << height << "\n";
     cout << "\n";
     */

     // Declare Pixels that directly surround center Pixel
     Pixel left, right, up, down;

     // Initialize with sick math
     left = image[col == width - 1 ? col + 1 - width : col + 1][row];
     right = image[col == 0 ? col - 1 + width : col - 1][row];
     up = image[col][row == 0 ? row - 1 + height : row - 1];
     down = image[col][row == height - 1 ? row + 1 - height : row + 1];

     /*
     // More Debug Lines
     cout << "Left:\t" << left << "\n";
     cout << "Right:\t" << right << "\n";
     cout << "Up:\t" << up << "\n";
     cout << "Down:\t" << down << "\n";
     cout << "\n";
     */

     // calculate horizontal differences of each color variable
     int Rx = right.r - left.r;
     int Gx = right.g - left.g;
     int Bx = right.b - left.b;

     // calculate horizontal gradient
     int delx = Rx * Rx + Gx * Gx + Bx * Bx;

     // calculate vertical difference of each color variable
     int Ry = up.r - down.r;
     int Gy = up.g - down.g;
     int By = up.b - down.b;

     // calculate vertical gradient
     int dely = Ry * Ry + Gy * Gy + By * By;

     // return energy
     return delx + dely;
}

// TODO Write this function
int getVerticalSeam(const Pixel *const *image, int start_col, int width, int height, int *seam)
{
     /*
     // Epic debug lines :)
     cout << "Col:\t" << start_col << "\n";
     cout << "Width:\t" << width << "\n";
     cout << "Height:\t" << height << "\n";
     cout << "\n";

     cout << "\nimage:\n";

     for (int row = 0; row < height; ++row) {
          for (int col = 0; col < width; ++col) {
               cout << image[col][row] << "\t";
          }
          cout << "\n";
     }

     cout << "\n";
     */

     // Initialize total to be energy of starting pixel
     int total = energy(image, start_col, 0, width, height);

     // initialize starting column for loop
     int col = start_col;

     // initialize first element of seam
     seam[0] = start_col;

     // Declare left, forward, and right
     unsigned int left, forward, right;

     // loop through image
     for (int row = 1; row < height; ++row)
     {
          // initilize forward, left, and right energy levels.
          forward = energy(image, col, row, width, height);
          left = UINT32_MAX;
          right = UINT32_MAX;

          if (col <= 0)
          { // in first column
               left = energy(image, col + 1, row, width, height);
          }
          else if (col >= width - 1)
          { // in last column
               right = energy(image, col - 1, row, width, height);
          }
          else
          { // somewhere in the middle
               left = energy(image, col + 1, row, width, height);
               right = energy(image, col - 1, row, width, height);
          }

          /**
          cout << "Left:\t" << left << "\n";
          cout << "Frwd:\t" << forward << "\n";
          cout << "Right:\t" << right << "\n";
          cout << "\n";
          */

          // Tie breaker -------------------------------------------------------
          if (forward <= left && forward <= right)
          {
               // cout << "Going frwd.\n";
               seam[row] = col;
               total += forward;
          }
          else if (left <= right)
          {
               // cout << "Going left.\n";
               seam[row] = ++col;
               total += left;
          }
          else
          {
               // cout << "Going right.\n";
               seam[row] = --col;
               total += right;
          }

          // cout << "\nCol:\t" << col << "\n";
     }

     return total;
}

// TODO Write this function
void removeVerticalSeam(Pixel **image, int &width, int height, int *verticalSeam)
{
     //cout << "Width:\t" << width << "\n";
     //cout << "Height:\t" << height << "\n";

     for (int row = 0; row < height; ++row)
     {
          //cout << "seam[" << row << "]:\t" << verticalSeam[row] << "\n";
          for (int col = 0; col < width - 1; ++col)
          {
               if (col >= verticalSeam[row])
                    image[col][row] = image[col + 1][row];
          }
     }
     --width;
}

// TODO Write this function for extra credit
int getHorizontalSeam(const Pixel *const *image, int start_row, int width, int height, int *seam)
{
     // Epic debug lines :)
     cout << "Row:\t" << start_row << "\n";
     cout << "Width:\t" << width << "\n";
     cout << "Height:\t" << height << "\n";
     cout << "\n";

     cout << "\nimage:\n";

     for (int row = 0; row < height; ++row) {
          for (int col = 0; col < width; ++col) {
               cout << image[col][row] << "\t";
          }
          cout << "\n";
     }

     cout << "\n";

     // Initialize total to be energy of starting pixel
     int total = energy(image, 0, start_row, width, height);

     // initialize starting column for loop
     int row = start_row;

     // initialize first element of seam
     seam[0] = start_row;

     unsigned int forward, left, right;

     // loop through image
     for (int col = 1; col < width; ++col)
     {
          // initilize forward, left, and right energy levels.
          forward = energy(image, col, row, width, height);
          left = UINT32_MAX;
          right = UINT32_MAX;
          
          if (row == 0)
          { // in first row
               right = energy(image, col, row + 1, width, height);
          }
          else if (row == height - 1)
          { // in last row
               left = energy(image, col, row - 1, width, height);
          }
          else
          { // somewhere in the middle
               right = energy(image, col, row + 1, width, height);
               left = energy(image, col, row - 1, width, height);
          }

          cout << "Left:\t" << left << "\n";
          cout << "Frwd:\t" << forward << "\n";
          cout << "Right:\t" << right << "\n";
          cout << "\n";

          // Tie breaker -------------------------------------------------------
          if (forward <= left && forward <= right)
          {
               cout << "Going frwd.\n";
               seam[col] = row;
               total += forward;
          }
          else if (left <= right)
          {
               cout << "Going left.\n";
               seam[col] = --row;
               total += left;
          }
          else
          {
               cout << "Going right.\n";
               seam[col] = ++row;
               total += right;
          }
          cout << "\n";
     }

     for (int col = 0; col < width; ++col) {
          cout << "seam[" << col << "]:\t" << seam[col] << "\n";
     }
     cout << "\n";

     return total;
}

// TODO Write this function for extra credit
void removeHorizontalSeam(Pixel **image, int width, int &height, int *horizontalSeam)
{
     cout << "Width:\t" << width << "\n";
     cout << "Height:\t" << height << "\n";

     for (int col = 0; col < width; ++col)
     {
          cout << "seam[" << col << "]:\t" << horizontalSeam[col] << "\n";
          for (int row = 0; row < height; ++row)
          {
               if (row >= horizontalSeam[col])
                    image[col][row] = image[col][row + 1];
          }
     }
     --height;
}

int *findMinVerticalSeam(const Pixel *const *image, int width, int height)
{
     // initialize minSeam and minDistance to seam starting at first col (index 0)
     int *minSeam = new int[height]{0};
     int minDist = getVerticalSeam(image, 0, width, height, minSeam);

     int *candidateSeam = new int[height]{0};
     int candidateDistance = -1; // invalid distance

     // start at second col (index 1) since we initialized with first col (index 0)
     for (int col = 1; col < width; ++col)
     {
          candidateDistance = getVerticalSeam(image, col, width, height, candidateSeam);

          if (candidateDistance < minDist)
          { // new min
               //  swap min & candidate
               minDist = candidateDistance;
               int *temp = candidateSeam;
               candidateSeam = minSeam;
               minSeam = temp;
          }
     }

     // clean up
     delete[] candidateSeam;

     return minSeam;
}

int *findMinHorizontalSeam(const Pixel *const *image, int width, int height)
{
     // initialize minSeam and minDistance to seam starting at first row (index 0)
     int *minSeam = new int[width]{0};
     int minDistance = getHorizontalSeam(image, 0, width, height, minSeam);

     int *candidateSeam = new int[width]{0};
     int candidateDistance = -1; // invalid distance

     // start at second row (index 1) since we initialized with first row (index 0)
     for (int row = 1; row < height; ++row)
     {
          candidateDistance = getHorizontalSeam(image, row, width, height, candidateSeam);

          if (candidateDistance < minDistance)
          { // new minimum
               //  swap min and candidate seams
               minDistance = candidateDistance;
               int *temp = candidateSeam;
               candidateSeam = minSeam;
               minSeam = temp;
          }
     }

     // clean up
     delete[] candidateSeam;

     return minSeam;
}

Pixel **createImage(int width, int height)
{
     cout << "Start createImage... " << endl;

     // Create a one dimensional array on the heap of pointers to Pixels
     //    that has width elements (i.e. the number of columns)
     Pixel **image = new Pixel *[width] {}; // initializes to nullptr

     for (int col = 0; col < width; ++col)
     { // loop through each column
          // assign that column to a one dimensional array on the heap of Pixels
          //  that has height elements (i.e. the number of rows)
          try
          {
               image[col] = new Pixel[height];
          }
          catch (std::bad_alloc &e)
          {
               // clean up already allocated arrays
               for (int i = 0; i < col; ++i)
               {
                    delete[] image[i];
               }
               delete[] image;
               // rethrow
               throw e;
          }
     }

     // initialize cells
     // cout << "Initializing cells..." << endl;
     for (int row = 0; row < height; ++row)
     {
          for (int col = 0; col < width; ++col)
          {
               // cout << "(" << col << ", " << row << ")" << endl;
               image[col][row] = {0, 0, 0};
          }
     }
     cout << "End createImage... " << endl;
     return image;
}

void deleteImage(Pixel **image, int width)
{
     cout << "Start deleteImage..." << endl;
     // avoid memory leak by deleting the array
     for (int i = 0; i < width; ++i)
     {
          delete[] image[i];
     }
     delete[] image;
     image = nullptr;
     cout << "End deleteImage..." << endl;
}

bool isValidColor(int colorVal)
{
     if (colorVal < 0 || colorVal > 255)
     {
          return false;
     }
     return true;
}

Pixel **loadImage(string filename, int &width, int &height)
{
     cout << "Start loadImage..." << endl;
     // remove
     ifstream ifs(filename);
     if (!ifs.is_open())
     {
          throw std::invalid_argument("Failed to open input file (" + filename + ")");
     }

     string type;
     ifs >> type; // should be P3
     if (toupper(type.at(0)) != 'P' || type.at(1) != '3')
     {
          throw std::domain_error("Not PPM type P3 (" + type + ")");
     }
     ifs >> width;
     // cout << "w and h: " << w << " " << h << endl;
     if (ifs.fail())
     {
          throw std::domain_error("Read non-integer value for width");
     }
     if (width <= 0)
     {
          ostringstream oss;
          oss << "Width in file must be greater than 0 (" << width << ")";
          throw std::domain_error(oss.str());
     }

     ifs >> height;
     if (ifs.fail())
     {
          cout << "Read non-integer value for height" << endl;
     }
     if (height <= 0)
     {
          ostringstream oss;
          oss << "Height in file must be greater than 0 (" << height << ")";
          throw std::domain_error(oss.str());
     }

     int colorMax = 0;
     ifs >> colorMax;
     if (ifs.fail())
     {
          throw std::domain_error("Read non-integer value for max color value");
     }
     if (colorMax != 255)
     {
          ostringstream oss;
          oss << "Max color value must be 255 (" << colorMax << ")";
          throw std::domain_error(oss.str());
     }

     // load image throws exceptions but we will let them pass through
     Pixel **image = createImage(width, height);

     for (int row = 0; row < height; ++row)
     {
          for (int col = 0; col < width; ++col)
          {
               // cout << "Pixel(" << col << ", " << row << ")" << endl;
               ifs >> image[col][row].r;
               if (ifs.fail() && !ifs.eof())
               { // bad input that is not caused by being at the end of the file
                    throw std::domain_error("Read non-integer value for red");
               }
               if (!isValidColor(image[col][row].r))
               {
                    ostringstream oss;
                    oss << "Invalid color value for red (" << image[col][row].r << ")";
                    throw std::domain_error(oss.str());
               }

               ifs >> image[col][row].g;
               if (ifs.fail() && !ifs.eof())
               { // bad input that is not caused by being at the end of the file
                    throw std::domain_error("Read non-integer value for green");
               }
               if (!isValidColor(image[col][row].r))
               {
                    ostringstream oss;
                    oss << "Invalid color value for green (" << image[col][row].r + ")";
                    throw std::domain_error(oss.str());
               }

               ifs >> image[col][row].b;
               if (ifs.fail() && !ifs.eof())
               { // bad input that is not caused by being at the end of the file
                    throw std::domain_error("Read non-integer value for blue");
               }
               if (!isValidColor(image[col][row].r))
               {
                    ostringstream oss;
                    oss << "Invalid color value for blue (" << image[col][row].r + ")";
                    throw std::domain_error(oss.str());
               }
          }
     }
     cout << "End loadImage..." << endl;
     return image;
}

void outputImage(string filename, const Pixel *const *image, int width, int height)
{
     cout << "Start outputImage..." << endl;
     // remove code
     // declare/define and open output file stream with filename
     ofstream ofs(filename);
     // ensure file is open
     if (!ofs.is_open())
     {
          throw std::invalid_argument("Error: failed to open output file - " + filename);
     }
     ofs << "P3" << endl;
     ofs << width << " " << height << endl;
     ofs << 255 << endl;
     for (int row = 0; row < height; ++row)
     {
          for (int col = 0; col < width; ++col)
          {
               ofs << image[col][row].r << " ";
               ofs << image[col][row].g << " ";
               ofs << image[col][row].b << " ";
          }
          ofs << endl;
     }
     cout << "End outputImage..." << endl;
}