#include "rgb_to_gray.h"

void rgb_to_gray(
    const std::vector<unsigned char> & rgb,
    const int width,
    const int height,
    std::vector<unsigned char> & gray)
{
    gray.resize(height*width);
    
    for( int row = 0; row < height; row++ ){
        for( int col = 0; col < width; col++ ){
            int pixelIdx = (row * width + col) * 3;
            int greyIdx = row * width + col;
            gray.at(greyIdx) = (0.2126 * rgb.at(pixelIdx)) + (0.7125 * rgb.at(pixelIdx + 1)) + (0.0722 * rgb.at(pixelIdx + 2));
        }
    }
}


