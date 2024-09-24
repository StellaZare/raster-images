#include "reflect.h"

/**
 * Horizontally reflect the input image (like a mirror)
 * 
 * @param input         image to reflect
 * @param width         image width (i.e., number of columns)
 * @param height        image height (i.e., number of rows)
 * @param num_channels  number of channels (e.g., for rgb 3, for grayscale 1)  
 * @param reflected     the reflected image
 * 
 * Logic:
 *      r = row, c = col, w = width
 *      pixel at (r, c) => (r, w - 1 - c)
 *      pixel at (0,0) => (0, w - 1)
 * 
 *      pixel at (r, c) starts at index (r * width + c) * num_channels
 */
void reflect(
    const std::vector<unsigned char> & input,
    const int width,
    const int height,
    const int num_channels,
    std::vector<unsigned char> & reflected)
{
    reflected.resize(width*height*num_channels);
    
    for ( int row = 0; row < height; row++ ) {
        for ( int col = 0; col < width; col++ ) {

            // Start index of pixel data in input
            int inputIdx = (row * width + col) * num_channels;
            // Start index of pixel data after reflection
            int reflectedIdx = (row * width + (width - 1 - col)) * num_channels;
            // Copy pixel data to reflected image
            for (int channel = 0; channel < num_channels; channel++) {
                reflected.at(reflectedIdx + channel) = input.at(inputIdx + channel);
            }
        }
    }
}
