#include "demosaic.h"

/**
 * Given a mosaiced image, created a 3-channel rgb image
 *
 * Bayer Format: for a 4x4 block of pixels
 *      green   blue
 *      red    green
 * 
 * Logic:
 *    For each pixel in the Bayer image, interpolate the missing color channels
 *    If red:   green = average of horizontal neighbors, blue = average of diagonal neighbors
 *    If green: red = average of horizontal neighbors, blue = average of vertical neighbors
 *    If blue:  red = average of diagonal neighbors, green = average of parallel neighbors
 */
void demosaic(
    const std::vector<unsigned char> &bayer,
    const int &width,
    const int &height,
    std::vector<unsigned char> &rgb)
{
    rgb.resize(width * height * 3);

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            int bayerIdx = row * width + col;
            int rgbIdx = bayerIdx * 3;

            int red, green, blue;

            if (row % 2 == 0 && col % 2 != 0)
            {
                // At a blue pixel
                red = getDiagonalAverage(bayer, width, height, row, col);
                green = getParallelAverage(bayer, width, height, row, col);
                blue = bayer.at(bayerIdx);
            }
            else if (row % 2 != 0 && col % 2 == 0)
            {
                // At a red pixel
                red = bayer.at(bayerIdx);
                green = getParallelAverage(bayer, width, height, row, col);
                blue = getDiagonalAverage(bayer, width, height, row, col);
            }
            else
            {
                // At green pixel
                red = getHorizontalAverage(bayer, width, height, row, col);
                green = bayer.at(bayerIdx);
                blue = getVerticalAverage(bayer, width, height, row, col);
            }

            rgb.at(rgbIdx) = red;
            rgb.at(rgbIdx + 1) = green;
            rgb.at(rgbIdx + 2) = blue;
        }
    }
}

double getDiagonalAverage(
    const std::vector<unsigned char> &bayer,
    const int &width,
    const int &height,
    const int &row,
    const int &col)
{
    int count = 0;
    double sum = 0;

    if (row > 0 && col > 0)
    {
        // Count top left
        sum += bayer.at((row - 1) * width + (col - 1));
        count++;
    }
    if (row > 0 && col < width - 1)
    {
        // Get top right
        sum += bayer.at((row - 1) * width + (col + 1));
        count++;
    }
    if (row < height - 1 && col > 0)
    {
        // Get bottom left
        sum += bayer.at((row + 1) * width + (col - 1));
        count++;
    }
    if (row < height - 1 && col < width - 1)
    {
        // Get bottom right
        sum += bayer.at((row + 1) * width + (col + 1));
        count++;
    }

    return (sum / count);
}

double getParallelAverage(
    const std::vector<unsigned char> &bayer,
    const int &width,
    const int &height,
    const int &row,
    const int &col)
{
    int count = 0;
    double sum = 0;

    if (row > 0)
    {
        // Get top
        sum += bayer.at((row - 1) * width + col);
        count++;
    }
    if (row < height - 1)
    {
        // Get bottom
        sum += bayer.at((row + 1) * width + col);
        count++;
    }
    if (col > 0)
    {
        // Get left
        sum += bayer.at(row * width + (col - 1));
        count++;
    }
    if (col < width - 1)
    {
        // Get right
        sum += bayer.at(row * width + (col + 1));
        count++;
    }

    return (int)sum / count;
}

double getHorizontalAverage(
    const std::vector<unsigned char> &bayer,
    const int &width,
    const int &height,
    const int &row,
    const int &col)
{
    int count = 0;
    double sum = 0;

    if (row > 0)
    {
        // Get top
        sum += bayer.at((row - 1) * width + col);
        count++;
    }
    if (row < height - 1)
    {
        // Get bottom
        sum += bayer.at((row + 1) * width + col);
        count++;
    }

    return sum / count;
}

double getVerticalAverage(
    const std::vector<unsigned char> &bayer,
    const int &width,
    const int &height,
    const int &row,
    const int &col)
{
    int count = 0;
    double sum = 0;

    if (col > 0)
    {
        // Get left
        sum += bayer.at(row * width + (col - 1));
        count++;
    }
    if (col < width - 1)
    {
        // Get right
        sum += bayer.at(row * width + (col + 1));
        count++;
    }

    return sum / count;
}