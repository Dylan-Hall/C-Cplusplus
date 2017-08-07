#include "sizes.h"
void get_image_names(FILE *fin, int *imageNum, char **imageNames) {
	char fileNaMe[128];
	int i = 0;

	while (!feof(fin)) {
		fscanf(fin, "%s", fileNaMe);
		imageNames[i] = (char*) malloc(sizeof(char) * (strlen(fileNaMe) + 1));
		strcpy(imageNames[i], fileNaMe);
		i++;
	}
}

//find width and height of images
void find_width_height(char *name, uint16_t *width, uint16_t *height) {
	//Image attempt
	FILE *fin;
	char line[256] = { 0x0 };
	char *tok;
	char imagefolder[25], imagename[25], finalname[25];

	strcpy(imagefolder, "images/");
	strcat(imagefolder, name);

	printf("Folder Name: %s\n", imagefolder);
	fin = fopen(imagefolder, "rb");

	if (fin == NULL) {
		puts("Cannot open PGM image");
	}

	fgets(line, 625, fin);
	fgets(line, 625, fin);
	tok = strtok(line, " ");
	*width = atoi(tok);
	tok = strtok(NULL, " ");
	*height = atoi(tok);
}

//get data size for kernels
void get_data_size(FILE *fin, int *rows, int *columns) {
	//File based variables
	char line[256] = { 0x0 };

	while (fgets(line, 1023, fin)) //rows
	{
		++(*rows);
	}
//--------------------------------------
	fseek(fin, 0, SEEK_SET);
	char *result = strtok(line, " ");
	while (result != NULL)  //columns
	{
		++(*columns);
		result = strtok( NULL, " ");
	}
}

//finds the number of images
void find_image_number(FILE *fp, int *imageNum) {
	char line[256] = { 0x0 };

	while (fgets(line, 1023, fp)) //rows
	{
		++*imageNum;
	}

	printf("Number of images is: %d\n", *imageNum);
}

//Free arrays function
void free_arrays(uint8_t **image, uint16_t height) {
	int i;
	for (i = 0; i < height; i++)
		free(image[i]);
	free(image);
}

void processString(char *str) {
	int i;
	for (i = 0; i < strlen(str); i++) {
		if (str[i] == '.') {
			str[i + 4] = '\0';
			break;
		}
	}
}
