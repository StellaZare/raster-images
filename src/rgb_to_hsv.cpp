#include "rgb_to_hsv.h"
#include <algorithm>

/**
 * Convert RGB to HSV
 * 
 * Convert a color represented by red, green and blue intensities to its equivalent hue, saturation and value.
 * 
 * Logic:
 *      1. Normalize the RGB values by dividing by 255
 *      2. Find the min and max RGB values 
 *      3. Calculate the delta = abs(max, min)
 *      4. Calculate H
 *      5. Calculate S = delta / max
 *      6. Calcualte V = max
 */
void rgb_to_hsv(
    const double r,
    const double g,
    const double b,
    double & h,
    double & s,
    double & v)
{

    // Step 1
    double red = r / 255;
    double green = g / 255;
    double blue = b / 255;

    // Step 2
    double rgbMax = std::max({red, green, blue});
    double rgbMin = std::min({red, green,blue});

    // Step 3
    double delta = std::abs(rgbMax - rgbMin);

    // Step 4
    if (rgbMax == red)
    {
        h = 60 * ((green - blue) / delta);
    }
    else if (rgbMax == green)
    {
        h = 60 * ((blue - red) / delta) + 120;
    }
    else
    {
        h = 60 * ((red - green) / delta) + 240;
    }

    // Steps 5 & 6
    s = delta / rgbMax;
    v = rgbMax;
}
