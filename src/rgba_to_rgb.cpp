#include "rgba_to_rgb.h"

void rgba_to_rgb(
  const std::vector<unsigned char> & rgba,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  // Resize the output vector to the correct size (prevent resizing during loop)
  rgb.resize(height*width*3);
  // Relinquish any memory not needed
  rgb.shrink_to_fit();
  
  for(int row = 0; row < height; row++)
  {
    for( int col = 0; col < width; col++)
    {
      // Find the pixel in the 4-channel rgba image
      int pixel_idx = (row * width + col) * 4;
      int red = rgba[pixel_idx];
      int green = rgba[pixel_idx + 1];
      int blue = rgba[pixel_idx + 2];

      // Store the pixel in the 3-channel rgb image
      int rgb_idx = (row * width + col) * 3;
      rgb.at(rgb_idx) = red;
      rgb.at(rgb_idx + 1) = green;
      rgb.at(rgb_idx + 2) = blue;
    }
  }
}
