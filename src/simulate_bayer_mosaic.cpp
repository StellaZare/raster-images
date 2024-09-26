#include "simulate_bayer_mosaic.h"

/**
 * Convert an RGB image to a 1-channel Bayer image
 * 
 * Bayer Format: for a 4x4 block of pixels
 *      green   blue
 *      red    green
 * 
 * Logic: 
 *      For each pixel in the RGB image only retain the information for 1 color channel
 *      determined by the Bayer formattng used
 * 
 *      On an even row (0, 2, 4, ...): if even column take the green, else take blue
 *      On an odd row: if even column take red, else take green
 */
void simulate_bayer_mosaic(
    const std::vector<unsigned char> & rgb,
    const int & width,
    const int & height,
    std::vector<unsigned char> & bayer)
{
    bayer.resize(width*height);

    for ( int row = 0; row < height; row++ )
    {
        for ( int col = 0; col < width; col++ )
        {
            int rgbIdx = (row * width + col) * 3;
            int bayerIdx = row * width + col;

            int channel;
            if ( row % 2 == 0 && col % 2 != 0 )
                channel = 2;
            else if ( row % 2 != 0 && col % 2 == 0 )
                channel = 0;
            else 
                channel = 1;

            bayer.at(bayerIdx) = rgb.at(rgbIdx + channel);
        }
    }
}
