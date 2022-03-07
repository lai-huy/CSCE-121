#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>

struct Pixel {
  int r; // red
  int g; // green
  int b; // blue
};

// TODO Implement

int energy(const Pixel*const* image, int col, int row, int width, int height);
int getVerticalSeam(const Pixel*const* image, int start_col, int width, int height, int* seam);
void removeVerticalSeam(Pixel** image, int& width, int height, int* verticalSeam);

// Implement for extra credit

int getHorizontalSeam(const Pixel*const* image, int start_row, int width, int height, int* seam);
void removeHorizontalSeam(Pixel** image, int width, int& height, int* horizontalSeam);

// Implemented for you ** DO NOT CHANGE **

int* findMinVerticalSeam(const Pixel*const* image, int width, int height);
int* findMinHorizontalSeam(const Pixel*const* image, int width, int height);
Pixel** createImage(int width, int height);
void deleteImage(Pixel** image, int width);
Pixel** loadImage(std::string filename, int& width, int& height);
void outputImage(std::string filename, const Pixel*const* image, int width, int height);

#endif