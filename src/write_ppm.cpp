#include "write_ppm.h"
#include <fstream>
#include <cassert>
#include <iostream>

/**
 * Write an rgb or grayscale image to an ASCII (P2/P3) .ppm file.
 * 
 * @param filename      path to .ppm file as string
 * @param data          vector of image channel data
 * @param width         image width (i.e., number of columns)
 * @param height        image height (i.e., number of rows)
 * @param num_channels  number of channels (e.g., for rgb 3, for grayscale 1)
 * 
 * .PPM Header Format:
 *      P3 or P2 (P3 for rgb, P2 for greyscale)
 *      width height
 *      max_value (255)
 *      data
 */
bool write_ppm( 
    const std::string & filename, 
    const std::vector<unsigned char> & data,
    const int width,
    const int height,
    const int num_channels)
{
    assert( (num_channels == 3 || num_channels ==1 ) && ".ppm only supports RGB or grayscale images" );

    // Open file to write into
    std::ofstream file {filename};
    if(!file.is_open()) 
    {
        std::cerr << "Error: could not open file " << filename << std::endl;
        return false;
    }

    // Write header
    file << (num_channels == 3 ? "P3" : "P2") << std::endl;
    file << width << " " << height << std::endl;
    file << "255" << std::endl;

    // Write data
    for ( int row = 0; row < height; row++ ) {
        for ( int col = 0; col < width; col++ ) {
            for ( int channel = 0; channel < num_channels; channel++ ) {
                file << (int) data.at( ((row * width + col) * num_channels) + channel ) << " ";
            }
        }
        file << std::endl;
    }

    // Close the file!
    file.close();
    return true;
}