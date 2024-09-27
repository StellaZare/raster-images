# Computer Graphics – Raster Images

**Source:** This repository is from @alecjacobson offering of csc317 Computer Graphics at the University of Toronto. 

>The original repository can be found:
> 
>     git clone  https://github.com/alecjacobson/computer-graphics-raster-images.git

## Compilation

To compile the project:

    mkdir build
    cd build
    cmake ..

If you are using Mac or Linux, then issue:

    make

## Execution

Once built, you can execute the assignment from inside the `build/` using 

    ./raster

### `src/rgba_to_rgb.cpp`

Extract the 3-channel rgb data from a 4-channel rgba image.

### `src/write_ppm.cpp`

Write an rgb or grayscale image to an ASCII (P2/P3) .ppm file.

    .PPM Header Format:
    P3 or P2 (P3 for rgb, P2 for greyscale)
    width height
    max_value (255)
    data

File: `rgb.ppm`

![If you've implemented `src/rgba_to_rgb.cpp` correctly then `./raster
../data/dog.png` should produce this image in
`rgb.ppm`.](images/rgb.png) 

### `src/reflect.cpp`

Horizontally reflect an image (like a mirror)

File: `reflected.ppm`

![If you've implemented `src/write_ppm.cpp` correctly then `./raster
../data/dog.png` should produce this image in
`reflected.ppm`.](images/reflected.png) 

### `src/rotate.cpp`

Rotate an image 90^\circ   counter-clockwise

File: `rotated.ppm`

![`./raster
../data/dog.png` should produce this image in
`rotated.ppm`.](images/rotated.png) 

### `src/rgb_to_gray.cpp`

Convert a 3-channel RGB image to a 1-channel grayscale image.

File: `gray.ppm`

![`./raster
../data/dog.png` should produce this image in
`gray.ppm`.](images/gray.png) 

### `src/simulate_bayer_mosaic.cpp`

Simulate an image acquired from the Bayer mosaic by taking a 3-channel rgb image
and creating a single channel grayscale image composed of interleaved
red/green/blue channels. The output image should be the same size as the input but only one
channel.

    Bayer Format: for a 4x4 block of pixels
        green   blue
        red    green    

File: `bayer.ppm`

![`./raster
../data/dog.png` should produce this image in
`bayer.ppm`. **Zoom in** to see interleaving.](images/bayer.png) 

### `src/demosaic.cpp`

Given a mosaiced image (interleaved GBRG colors in a single channel), created a
3-channel rgb image.

File: `demosaiceked.ppm`

![`./raster ../data/dog.png` should produce this image in
`demosaicked.ppm`.](images/demosaicked.png) 

### `src/rgb_to_hsv.cpp`

Convert a color represented by red, green and blue intensities to its
representation using hue, saturation and value.

### `src/hsv_to_rgb.cpp`

Convert a color represented by hue, saturation and value to its representation
using red, green and blue intensities.

### `src/hue_shift.cpp`

Shift the hue of a color rgb image. 

File: `shifted.ppm`

![`./raster
../data/dog.png` should produce this image in
`shifted.ppm`.](images/shifted.png) 

### `src/desaturate.cpp`

Desaturate a given rgb color image by a given factor.

File: `desaturated.ppm`

![`./raster
../data/dog.png` should produce this image in
`desaturated.ppm`.](images/desaturated.png) 