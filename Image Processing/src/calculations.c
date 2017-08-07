#include "calculations.h"

//allocates memeory for arrays
uint8_t **allocate_memory(uint16_t width, uint16_t height) {
	/*allocate memory for a 2d array */
	int i;
	uint8_t **image = (uint8_t **) malloc(height * sizeof(uint8_t *));
	for (i = 0; i < height; i++) {
		image[i] = (uint8_t *) malloc(width * sizeof(uint8_t));

		if (image[i] == NULL) {
			fprintf(stderr, "Not enough memory to allocate\n");
			exit(1);
		}
	}

	return image;
}

//read files functions
float **read_file(Area*kSize, char *kernelFile) {

	FILE *fKernel = fopen(kernelFile, "r");
	if (fKernel == NULL) {
		fprintf(stderr, "Can't open output file %s!\n", kernelFile);
		exit(1);
	}

	int kernelSize = kSize->width; //width = height

	float *kernelBuff = (float *) malloc(kernelSize * kernelSize * sizeof(int));

	int i, j;
	float **kernel = (float **) malloc(kernelSize * sizeof(float *));
	for (i = 0; i < kernelSize; i++) {
		kernel[i] = (float *) malloc(kernelSize * sizeof(float));

		if (kernel[i] == NULL) {
			fprintf(stderr, "Not enough memory to allocate\n");
			exit(1);
		}
	}

	for (i = 0; i < kernelSize; i++) {
		for (j = 0; j < kernelSize; j++) {
			float val;
			fscanf(fKernel, "%f", &val);
			kernel[i][j] = val;

		}
	}

	fclose(fKernel);
	return kernel;

}

//creates temp kernel
float **copy_kernel(int kernelSize) {
	int i;
	float **kernel = (float **) malloc(kernelSize * sizeof(float *));
	for (i = 0; i < kernelSize; i++) {
		kernel[i] = (float *) malloc(kernelSize * sizeof(float));

		if (kernel[i] == NULL) {
			fprintf(stderr, "Not enough memory to allocate\n");
			exit(1);
		}
	}
	return kernel;
}

//normalize data by dividing by the sum
float **divide_by_kernel_sum(float **kernel, Area *size) {
	float **newKernel = copy_kernel(size->width);
	int i, j;
	float sum = 0;
	for (i = 0; i < size->height; i++) {
		for (j = 0; j < size->width; j++) {
			//sum += kernel[i][j]*kernel[i][j];
			sum += kernel[i][j];
		}
	}

	double sumD = (double) sum;
	float sumRoot = sum;
	//float sumRoot = (float)sqrt(sumD);

	for (i = 0; i < size->height; i++) {
		for (j = 0; j < size->width; j++) {
			newKernel[i][j] = kernel[i][j] / sumRoot;
		}
	}
	return newKernel;
}

//finds centroid of images
Centroid *find_centroid(uint8_t **image, uint16_t width, uint16_t height) {
	/*Compte the sum I(x,y) */
	int sum = 0;
	int i, j = 0;
	for (i = 0; i < height; i++)
		for (j = 0; j < width; j++)
			sum += image[i][j];

	Centroid *centroid = (Centroid*) malloc(sizeof(Centroid));
	int xSum = 0;
	int ySum = 0;
	/*Compute x and y Value*/
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			xSum += (i * image[i][j]);
			ySum += (j * image[i][j]);
		}
	}

	centroid->cx = xSum / sum;
	centroid->cy = ySum / sum;

	return centroid;
}

//create the new image with the appropraite header
void make_new_image(uint8_t **image, Area *size, char *fileName) {
	uint8_t *buff = (uint8_t *) malloc(
			(size->width) * (size->height) * sizeof(uint8_t));

	//allocate array
	int j, i, count = 0;
	for (i = 0; i < size->height; i++)
		for (j = 0; j < size->width; j++)
			buff[count++] = image[i][j];

	FILE*fout = fopen(fileName, "wb");

	if (fout == NULL) {
		fprintf(stderr, "Can't open output file %s!\n", fileName);
		exit(1);
	}
	//header and data to file
	fprintf(fout, "P5\n%u %u\n255\n", size->width, size->height);
	fwrite(buff, sizeof(uint8_t), (size->width) * (size->height), fout);
	fclose(fout);

}

//distance between centroids for motion
int distance_between_centroid(Centroid *c1, Centroid *c2) {
	uint16_t x1 = c1->cx;
	uint16_t y1 = c1->cy;

	uint16_t x2 = c2->cx;
	uint16_t y2 = c2->cy;

	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

//difference function for motion
uint8_t difference(uint8_t **image1, uint8_t **image2, Area *size) {
	uint8_t maxDiff = 0;
	int i, j = 0;
	for (i = 0; i < size->height; i++) {
		for (j = 0; j < size->width; j++) {
			uint8_t diff = 0;
			if (image1[i][j] > image2[i][j])
				diff = image1[i][j] - image2[i][j];
			else
				diff = image2[i][j] - image1[i][j];
			if (diff > maxDiff)
				maxDiff = diff;
		}
	}

	return maxDiff;
}

//flips kernel mask function
float **flip_mask(float **kernel, Area *size) {
	float **newKernel = copy_kernel(size->width);
	int i, j;
	uint16_t mid = size->width / 2;
	//Flip Horizontally
	for (i = 0; i < size->height; i++) {
		newKernel[i][mid] = kernel[i][mid];
		for (j = 0; j < mid; j++) {
			float temp = kernel[i][j];
			newKernel[i][j] = kernel[i][size->width - 1 - j];
			newKernel[i][size->width - 1 - j] = temp;
		}
	}

	mid = size->height / 2;
	//Flip Vertically
	for (i = 0; i < mid; i++) {
		for (j = 0; j < size->width; j++) {
			float temp = newKernel[i][j];
			newKernel[i][j] = newKernel[size->height - 1 - i][j];
			newKernel[size->height - 1 - i][j] = temp;
		}
	}

	return newKernel;
}

//reads images
uint8_t **readImage(char *fileName, uint8_t **image, uint16_t width,
		uint16_t height) {
	int i;
	uint8_t *buff = (uint8_t *) malloc(width * height * sizeof(uint8_t));

	FILE *fin = fopen(fileName, "rb");
	if (fin == NULL) {
		fprintf(stderr, "Can't open output file %s!\n", fileName);
		exit(1);
	}

	char line[255] = { 0x0 };
	fgets(line, 255, fin);
	fgets(line, 255, fin);
	fgets(line, 255, fin);

	fread(buff, sizeof(uint8_t), width * height, fin);

	int j, count = 0;
	for (i = 0; i < height; i++)
		for (j = 0; j < width; j++)
			image[i][j] = buff[count++];

	fclose(fin);
	free(buff);
	return image;
}

// smooth and trim images to be within range
uint8_t **smooth_trim_image(uint8_t **origImage, uint8_t **modImage,
		Area *imageSize, float **kernel, Area *kernelSize) {
	int i, j, p, q;
	int count = -1;
	for (i = 0; i < imageSize->height; i++) {
		for (j = 0; j < imageSize->width; j++) {
			int xMin = (j - kernelSize->width / 2);
			int yMin = (i - kernelSize->height / 2);
			int sum = 0;

			//Iterate the kernel Array
			for (p = (i - kernelSize->height / 2);
					p <= (i + kernelSize->height / 2); p++) {
				for (q = (j - kernelSize->width / 2);
						q <= (j + kernelSize->width / 2); q++) {
					if (p < 0 || q < 0 || p >= imageSize->height
							|| q >= imageSize->width) {
						if (count >= 0)
							;

						continue;
					}
					float kernelVal = kernel[p - yMin][q - xMin];
					sum += kernelVal * origImage[p][q];
				}
			}
			count--;

			//smooth and trim, make sure all data is within range
			if (sum > 255) {
				sum = 255;
			}
			if (sum < 0) {
				sum = 0;
			}
			modImage[i][j] = sum;

		}
	}
	return modImage;
}
