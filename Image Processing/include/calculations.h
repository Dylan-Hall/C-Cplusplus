#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdint.h>
#include <math.h>

#ifndef CALC
#define CALC

//struct for centroid usage
typedef struct placeholder {
	uint16_t cx;
	uint16_t cy;
	uint16_t cx2;
	uint16_t cy2;
} Centroid;

//struct for sizes of arrays and images
typedef struct array_size {
	uint16_t height;
	uint16_t width;
} Area;

//allocate memory for arrays
uint8_t **allocate_memory(uint16_t width, uint16_t height);

//read image and kernel files
float **read_file(Area*kSize, char *kernelFile);

//creates a temp kernel for editing (flipping)
float **copy_kernel(int kernelSize);

//flips kernel mask
float **flip_mask(float **kernel, Area *size);

//normalize by dividing by sum
float **divide_by_kernel_sum(float **kernel, Area *size);

//finds the centroid of the image
Centroid *find_centroid(uint8_t **image, uint16_t width, uint16_t height);

//smooths image (applys kernels) trims (makes sure data is in range)
uint8_t **smooth_trim_image(uint8_t **origImage, uint8_t **modImage,
		Area *imageSize, float **kernel, Area *kernelSize);

//make the new image files
void make_new_image(uint8_t **image, Area *size, char *fileName);

//read the image files
uint8_t **readImage(char *fileName, uint8_t **image, uint16_t width,
		uint16_t height);

//find total distance
int distance_between_centroid(Centroid *c1, Centroid *c2);

//difference detection for motion
uint8_t difference(uint8_t **image1, uint8_t **image2, Area *size);

#endif

