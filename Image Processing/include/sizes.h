#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdint.h>
#include <math.h>

#ifndef OUTPUT
#define OUTPUT
//image names
void get_image_names(FILE *fin, int *imageNum, char **imageNames);

//finds width and height
void find_width_height(char *name, uint16_t *width, uint16_t *height);

//get data size
void get_data_size(FILE *fin, int *rows, int *columns);

//find num of images
void find_image_number(FILE *fp, int *imageNum);

//free data
void free_arrays(uint8_t **image, uint16_t height);

//fill string of characters with null terminators
void processString(char *str);

#endif