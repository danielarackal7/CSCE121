#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

using std::cout, std::endl, std::runtime_error, std::ifstream, std::ofstream, std::istringstream, std::string;

void initializeImage(Pixel image[][MAX_HEIGHT]) {
  // iterate through columns
  for (unsigned int col = 0; col < MAX_WIDTH; col++) {
    // iterate through rows
    for (unsigned int row = 0; row < MAX_HEIGHT; row++) {
      // initialize pixel
      image[col][row] = {0, 0, 0};
    }
  }
} 


void loadImage(std::string filename, Pixel image[][MAX_HEIGHT], unsigned int& width, unsigned int& height) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Failed to open " + filename);
    }
    string type;
    getline(file, type);
    if (!(type == "P3" || type == "p3")) {
        throw runtime_error("Invalid image" + type);
    }
    string comment;
    while (getline(file, comment) && comment.substr(0, 2) == "//") {
    }
    istringstream dimensionsStream(comment);
    if (!(dimensionsStream >> width >> height)) {
        throw runtime_error("Invalid dimensions");
    }
    if (width <= 0 || width > MAX_WIDTH || height <= 0 || height > MAX_HEIGHT || floor(height) != height) {
        throw runtime_error("Invalid dimensions");
    }
    unsigned int maxValue;
    file >> maxValue;

    int red; 
    int green;
    int blue;
    unsigned int y;
    unsigned int x;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            if (!(file >> red >> green >> blue)) {
                throw runtime_error("Invalid color value");
            }
            if (red < 0 || red > 255) {
                throw std::runtime_error("Invalid color value");
            } else if (green < 0 || green > 255) {
                throw std::runtime_error("Invalid color value");
            } else if (blue < 0 || blue > 255) {
                throw std::runtime_error("Invalid color value");
            }
            // converts to unsigned char values
            image[x][y] = { static_cast<unsigned char>(red), static_cast<unsigned char>(green), static_cast<unsigned char>(blue) };
        }
    }
    string extraPixels;
    if (file >> extraPixels) {
        throw runtime_error("Too many values");
    }
}


void outputImage(string filename, Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int height) {
    ofstream file(filename);
    if (file.is_open()) {
        file << "P3\n" << width << " " << height << "\n255\n";
        for (unsigned int y = 0; y < height; ++y) {
            for (unsigned int x = 0; x < width; ++x) {
                file << +image[x][y].r << " "
                     << +image[x][y].g << " "
                     << +image[x][y].b;

                if (x < width - 1) {
                    file << " ";
                }
            }
            file << "\n";
        }
        file.close();
    } else {
        cout << "Failed to open " << filename;
        return;
    }
}




unsigned int energy(Pixel image[][MAX_HEIGHT], unsigned int x, unsigned int y, unsigned int width, unsigned int height) {
    unsigned int leftPos, rightPos, upPos, downPos;
    int redDiffX, greenDiffX, blueDiffX, redDiffY, greenDiffY, blueDiffY;
    unsigned int delX, delY;

    if (x == 0) {
        leftPos = width - 1;
    } else {
        leftPos = x - 1;
    }

    if (x == width - 1) {
        rightPos = 0;
    } else {
        rightPos = x + 1;
    }

    if (y == 0) {
        upPos = height - 1;
    } else {
        upPos = y - 1;
    }

    if (y == height - 1) {
        downPos = 0;
    } else {
        downPos = y + 1;
    }

    redDiffX = image[rightPos][y].r - image[leftPos][y].r;
    greenDiffX = image[rightPos][y].g - image[leftPos][y].g;
    blueDiffX = image[rightPos][y].b - image[leftPos][y].b;
    delX = redDiffX*redDiffX + greenDiffX*greenDiffX + blueDiffX*blueDiffX;

    redDiffY = image[x][downPos].r - image[x][upPos].r;
    greenDiffY = image[x][downPos].g - image[x][upPos].g;
    blueDiffY = image[x][downPos].b - image[x][upPos].b;
    delY = redDiffY*redDiffY + greenDiffY*greenDiffY + blueDiffY*blueDiffY;

    return delX + delY;
}

// uncomment functions as you implement them (part 2)

unsigned int loadVerticalSeam(Pixel image[][MAX_HEIGHT], unsigned int start_col, unsigned int width, unsigned int height, unsigned int seam[]) {
    unsigned int energy_sum = 0;
    for (unsigned int y = 0; y < height; y++) {
        unsigned int min_col = start_col;
        unsigned int min_energy = energy(image, start_col, y, width, height);
        
        if (start_col > 0) {
            unsigned int left_energy = energy(image, start_col - 1, y, width, height);
            if (left_energy < min_energy) {
                min_energy = left_energy;
                min_col = start_col - 1;
            }
        }
        
        if (start_col < width - 1) {
            unsigned int right_energy = energy(image, start_col + 1, y, width, height);
            if (right_energy < min_energy) {
                min_energy = right_energy;
                min_col = start_col + 1;
            }
        }
        
        seam[y] = min_col;
        energy_sum += min_energy;
        start_col = min_col;
    }
    return energy_sum;
}

unsigned int loadHorizontalSeam(Pixel image[][MAX_HEIGHT], unsigned int start_row, unsigned int width, unsigned int height, unsigned int seam[]) {
   // TODO: implement (part 2)
    unsigned int energy_sum = 0;
    for (unsigned int x = 0; x < width; x++) {
        unsigned int min_row = start_row;
        unsigned int min_energy = energy(image, x, start_row, width, height);
        
        if (start_row > 0) {
            unsigned int top_energy = energy(image, x, start_row - 1, width, height);
            if (top_energy < min_energy) {
                min_energy = top_energy;
                min_row = start_row - 1;
            }
        }
        
        if (start_row < height - 1) {
            unsigned int bottom_energy = energy(image, x, start_row + 1, width, height);
            if (bottom_energy < min_energy) {
                min_energy = bottom_energy;
                min_row = start_row + 1;
            }
        }
        
        seam[x] = min_row;
        energy_sum += min_energy;
        start_row = min_row;
    }
    return energy_sum;
}

void findMinVerticalSeam(Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int height, unsigned int seam[]) {
   // TODO: implement (part 2)
    unsigned int min_energy = 0xFFFFFFFF;
    unsigned int start_col = 0;
    for (unsigned int x = 0; x < width; x++) {
        unsigned int temp_seam[MAX_HEIGHT];
        unsigned int seam_energy = loadVerticalSeam(image, x, width, height, temp_seam);
        if (seam_energy < min_energy) {
            min_energy = seam_energy;
            start_col = x;
            for (unsigned int y = 0; y < height; y++) {
                seam[y] = temp_seam[y];
            }
        }
    }
    loadVerticalSeam(image, start_col, width, height, seam);
}

void findMinHorizontalSeam(Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int height, unsigned int seam[]) {
   // TODO: implement (part 2)
    unsigned int min_energy = 0xFFFFFFFF;
    unsigned int start_row = 0;
    for (unsigned int y = 0; y < height; y++) {
        unsigned int temp_seam[MAX_WIDTH];
        unsigned int seam_energy = loadHorizontalSeam(image, y, width, height, temp_seam);
        if (seam_energy < min_energy) {
            min_energy = seam_energy;
            start_row = y;
            for (unsigned int x = 0; x < width; x++) {
                seam[x] = temp_seam[x];
            }
        }
    }
    loadHorizontalSeam(image, start_row, width, height, seam);
}

 void removeVerticalSeam(Pixel image[][MAX_HEIGHT], unsigned int& width, unsigned int height, unsigned int verticalSeam[]) {
   // TODO: implement (part 2)
    Pixel temp[MAX_WIDTH - 1][MAX_HEIGHT];
    unsigned int new_width = width - 1;
    
    for (unsigned int y = 0; y < height; y++) {
        unsigned int col = 0;
        for (unsigned int x = 0; x < width; x++) {
            if (x != verticalSeam[y]) {
                temp[col][y] = image[x][y];
                col++;
            }
        }
    }
    
    for (unsigned int y = 0; y < height; y++) {
        for (unsigned int x = 0; x < new_width; x++) {
            image[x][y] = temp[x][y];
        }
    }
    
    width = new_width;
}

void removeHorizontalSeam(Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int& height, unsigned int horizontalSeam[]) {
   // TODO: implement (part 2)
    Pixel temp[MAX_WIDTH][MAX_HEIGHT - 1];
    unsigned int new_height = height - 1;
    
    for (unsigned int x = 0; x < width; x++) {
        unsigned int row = 0;
        for (unsigned int y = 0; y < height; y++) {
            if (y != horizontalSeam[x]) {
                temp[x][row] = image[x][y];
                row++;
            }
        }
    }
    
    for (unsigned int y = 0; y < new_height; y++) {
        for (unsigned int x = 0; x < width; x++) {
            image[x][y] = temp[x][y];
        }
    }
    
    height = new_height;
}