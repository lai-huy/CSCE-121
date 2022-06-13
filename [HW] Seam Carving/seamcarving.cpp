#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

using std::cout, std::string, std::ostringstream;

int main(int argc, char* argv[]) {
     if (argc != 4) { // check if there are enough arguments
          cout << "Usage: " << argv[0] << " <name> <target-width> <target-height>" << "\n";
          return 1;
     }

     string filename = argv[1];
     string targetWidthStr = argv[2];
     string targetHeightStr = argv[3];

     int width = 0;
     int height = 0;
     int targetWidth = 0;
     int targetHeight = 0;
     try {
          targetWidth = stoi(targetWidthStr);
          if (targetWidth <= 0) {
               throw std::out_of_range("Target width must be greater than 0. You entered " + targetWidthStr);
          }
     } catch (std::invalid_argument& e) {
          cout << e.what() << "\n";
     } catch (std::out_of_range& e) {
          cout << e.what() << "\n";
     }

     try {
          targetHeight = stoi(targetHeightStr);
          if (targetHeight <= 0) {
               throw std::out_of_range("Target height must be greater than 0. You entered " + targetHeightStr);
          }
     } catch (std::invalid_argument& e) {
          cout << e.what() << "\n";
     } catch (std::out_of_range& e) {
          cout << e.what() << "\n";
     }

     // Pixel** image = createImage(width, height);
     int originalWidth = 0; // need to delete image array at end of program
     Pixel** image = nullptr;
     bool hasError = false;
     try {
          image = loadImage(filename, width, height);
          originalWidth = width; // need to delete image array at end of program
     } catch (std::bad_alloc& e) {
          cout << e.what() << "\n";
          return 1;
     } catch (std::invalid_argument& e) {
          cout << e.what() << "\n";
          return 1;
     } catch (std::domain_error& e) {
          cout << e.what() << "\n";
          return 1;
     }

     // with these errors, don't exit immediately
     //  we need to deallocate the image array
     if (targetWidth > width) {
          hasError = true;
          cout << "Target width (" << targetWidth << ") must be less than or equal to image width (" << width << ")" << "\n";
     }
     if (targetHeight > height) {
          hasError = true;
          cout << "Target height (" << targetHeight << ") must be less than or equal to image height (" << height << ")" << "\n";
     }

     if (!hasError) {
          int* seam = new int[height]();
          cout << "Horizontal Seam:\n";
          cout << getHorizontalSeam(image, 0, width, height, seam) << "\n";
          delete[] seam;

          // find and remove seams
          while ((width - targetWidth > 0) || (height - targetHeight > 0)) {
               if (width - targetWidth > 0) {
                    int* verticalSeam = findMinVerticalSeam(image, width, height);
                    removeVerticalSeam(image, width, height, verticalSeam);
                    delete[] verticalSeam;
               }

               if (height - targetHeight > 0) {
                    int* horizontalSeam = findMinHorizontalSeam(image, width, height);
                    removeHorizontalSeam(image, width, height, horizontalSeam);
                    delete[] horizontalSeam;
               }
          }

          cout << "End carving ..." << "\n";

          ostringstream ss;
          ss << "carved" << width << "X" << height << "." << filename;
          outputImage(ss.str(), image, width, height);
     }

     // call last to remove the image memory from the heap
     deleteImage(image, originalWidth);
}