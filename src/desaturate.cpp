#include "desaturate.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"
#include <iostream>

/**
 * Desaturate a given rgb color image by a given factor.
 * 
 * @param rgb       width*height*3 array containing rgb image color intensities
 * @param width     image width (i.e., number of columns)
 * @param height    image height (i.e., number of rows)
 * @param factor    factor  fractional amount of saturation to remove
 *                  1->fully grayscale, 0->retain input color.
 * @param shifted   width*height*3 array containing rgb image color intensities
 * 
 * Logic:
 *      1. Convert rgb to hsv
 *      2. Modify the saturation
 *      3. Convert back to rgb
 */
void desaturate(
    const std::vector<unsigned char> & rgb,
    const int width,
    const int height,
    const double factor,
    std::vector<unsigned char> & desaturated)
{
    desaturated.resize(rgb.size());
    for (int row = 0; row < height; row++)
    {
        for (int col = 0 ; col < width; col++)
        {
            int idx = (row * width + col) * 3;
            double r = rgb.at(idx), g = rgb.at(idx+1), b = rgb.at(idx+2);
            double h = 0, s = 0, v = 0;

            // Step 1
            rgb_to_hsv(r, g, b, h, s, v);

            // Step 2
            s *= (1 - factor);
            if (s < 0.10) {
                h = 0;
            }

            // Step 3
            hsv_to_rgb(h, s, v, r, g, b);

            desaturated.at(idx)   = (unsigned char) (r * 255);
            desaturated.at(idx+1) = (unsigned char) (g * 255);
            desaturated.at(idx+2) = (unsigned char) (b * 255);

            if ( desaturated.at(idx+2) < 0 || desaturated.at(idx+2) > 255 ){
                std::cout << "error: " << r << std::endl;
            }
        }
    }
}
