#include "hsv_to_rgb.h"
#include <cmath>

/**
 * Convert the color from HSV to RGB
 * 
 */
void hsv_to_rgb(
    const double h,
    const double s,
    const double v,
    double & r,
    double & g,
    double & b)
{
    int category = h / 60;
    double c = s * v;
    double x = c * (1 - std::abs(std::fmod(h / 60, 2) - 1));
    double m = v - c;

    switch (category)
    {   
        case 0:
            r = c;
            g = x;
            b = 0;
            break;
        case 1: 
            r = x;
            g = c;
            b = 0;
            break;
        case 2:
            r = 0;
            g = c;
            b = x;
            break;
        case 3:
            r = 0;
            g = x;
            b = c;
            break;
        case 4:
            r = x;
            g = 0;
            b = c;
            break;
        case 5:
            r = c;
            g = 0;
            b = x;
            break;
    }

    r += m; g += m; b += m;
}
