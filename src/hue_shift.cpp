#include "hue_shift.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"

#include <iostream>

/**
 * Shift the hue of a color rgb image.
 *
 * @param rgb       width*height*3 array containing rgb image color intensities
 * @param width     image width (i.e., number of columns)
 * @param height    image height (i.e., number of rows)
 * @param shift     hue shift given in degrees [-180,180)
 * @param shifted   width*height*3 array containing rgb image color intensities
 *
 * Logic:
 *    1. Convert the RGB image to HSV
 *    2. Shift the hue by the given amount. Ensure the hue stays in the range [0,360)
 *    3. Convert the shifted HSV image back to RGB
 */
void hue_shift(
    const std::vector<unsigned char> &rgb,
    const int width,
    const int height,
    const double shift,
    std::vector<unsigned char> &shifted)
{
    shifted.resize(rgb.size());

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
            h += shift;
            while (h >= 360) h -= 360.0;
            while (h < 0) h += 360.0;

            // Step 3
            hsv_to_rgb(h, s, v, r, g, b);

            shifted.at(idx)   = (unsigned char) (r * 255);
            shifted.at(idx+1) = (unsigned char) (g * 255);
            shifted.at(idx+2) = (unsigned char) (b * 255);
        }
    }
}
