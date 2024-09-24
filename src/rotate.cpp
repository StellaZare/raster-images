#include "rotate.h"

/**
 * Rotate the image 90 degrees ccw
 * 
 * @param input         image to reflect
 * @param width         image width (i.e., number of columns)
 * @param height        image height (i.e., number of rows)
 * @param num_channels  number of channels (e.g., for rgb 3, for grayscale 1)  
 * @param rotated       the rotated image
 * 
 * Logic: 
 *      rotation can be achieved by applying 2 successive mirrorings
 *      1st mirror the image along the y-axis (r, c) => (r, w - 1)
 *      2nd mirror the resulting image along the diagonal-axis (r, c) => (c, r)
 * 
 * Note:
 *      when reflecting the image along the diagonal the 
 */
void rotate(
    const std::vector<unsigned char> & input,
    const int width,
    const int height,
    const int num_channels,
    std::vector<unsigned char> & rotated)
{
    rotated.resize(height*width*num_channels);

    for( int row = 0; row < height; row++ ){
        for( int col = 0; col < width; col++ ){
            int inputIdx = (row * width + col) * num_channels;
            int rotateIdx = ((width - 1 - col) * height + row) * num_channels;

            for( int channel = 0; channel < num_channels; channel++ ){
                rotated.at(rotateIdx + channel) = input.at(inputIdx + channel);
            }
        }
    }
}
