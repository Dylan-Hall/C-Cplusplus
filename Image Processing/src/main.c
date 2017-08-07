/*
 Dylan Hall
 COP3014
 HWFINAL
 28 April 2016

 Pretty dang proud of this course overall. I've learned alot since the beginning and I've developed ALOT, let me stress ALOT
 of new methods and operations within C that will surely be expressed later on in my life, and future career.
 Thanks for all the assistance and aid you've given me, I've rated you course very well, I'll do the same on ratemyprofessor.
 Out of all the programming classes I've taken I've learned the most from your course, just want to say thanks again for a great term,
 and a great course! Good luck on your future classes and such.

 Alot of people complain about the difficulty of the course, and have asked me SO MANY times to help them, and have offered cash for teaching, or
 showing them how to do the assignments. What I noticed, if I attempted to aid any of my peers, is that they procrastinated until the second to last
 day and are scrambling to make the grade for an assignment they didn't even put the time into.

 Hopefully this code runs smoothly, and you are impressed by what I've done here. It took alot of time and trial and error, just as any
 expansive code should. I'll post a few cites I used for help and a guide.

 Here:
 http://www.programiz.com/c-programming/c-structure-function
 http://stackoverflow.com/questions/2690866/what-is-the-purpose-of-a-question-mark-after-a-type-for-example-int-myvariabl
 http://stackoverflow.com/questions/26689076/what-does-the-point-stand-for
 http://stackoverflow.com/questions/17096990/why-use-bzero-over-memset
 http://stackoverflow.com/questions/11772291/how-can-i-print-a-quotation-mark-in-c
 http://stackoverflow.com/questions/29561474/how-to-open-file-inside-folder-in-current-directory-using-fopen
 http://www.programiz.com/c-programming/c-structures-pointers
 http://timdettmers.com/2015/03/26/convolution-deep-learning/

 I use two .h files;
 calculations for basic image calculations, convolution, difference, hedges all that mess.
 sizes (couldn't think of a better name) this is just a few functions to determine sizes and getting data from files and images

 I use an enum which I learned earlier in the course just to keep things consistant across the board.
 As far as I'm aware all my code is variable, in that it is dependent purely apon the command line arguments needed in this order
 ***********IN THIS ORDER***********
 HERE: .exe creates is image_process.exe
 ./image_process.exe images.txt smooth1.txt(im sure it works with any) vkernel.txt hkernel.txt
 Only command prompts are when the code starts creating images, is displays the image used to find height and width, displays the folder
 the images are in, and the total number of images.

 */

//Standard Includes
#include <stdio.h>
#include <stdlib.h>
#include "calculations.h"
#include "sizes.h"

/**
 * Enum for max characters.
 */
enum {
	MAXC = 256
};

//main; this is the controller function and main processing function to run and make calls to functions
int main(int argc, char *argv[]) {
	FILE *fp, *fin;
	char *line = NULL;
	size_t tok;
	ssize_t readlines;
	uint8_t centroidFlag = 0, diffFlag = 0;
	Centroid *firstCentroid, *nextCentroid;
	int rows = 0, columns = 0, imageNum = 0, i;

	//char variables to hold strings that are used to concatenate at the end of each image
	char initImage[MAXC], vertImage[MAXC], horzImage[MAXC],
			correlationImage[MAXC], convolutionImage[MAXC];

	char basename[MAXC] = { 0x0 }, new_fname[MAXC] = { 0x0 };

	//tolerance for motion detection
	char motion1[MAXC], motion2[MAXC]; //motion tolerance
	int tol1 = 50, tol2 = 1; //centroid tolerance
	int init = 1; //first image (initial image)

	//Open first arg, (image.txt file)
	printf("Creating images... "); //Had to put this here or it wouldn't print to screen
	fin = fopen(argv[1], "r");
	find_image_number(fin, &imageNum); //gets the number of images to write
	fclose(fin);

	fin = fopen(argv[1], "r");
	char **imageNames = (char**) malloc(sizeof(char**) * imageNum);
	get_image_names(fin, &imageNum, imageNames);
	printf("Name of image used to find sizes: %s\n", imageNames[0]);
	char *name = imageNames[0];
	fclose(fin);

	//Opens second arg, (smooth kernel)
	fp = fopen(argv[2], "r");
	Area *sSize = (Area *) malloc(sizeof(Area)); //struct declaration of sSize, in struct Area
	get_data_size(fp, &rows, &columns); //previous assignment function, gets rows/columns
	fclose(fp);

	//initialize struct variables, width, height to rows and columns
	sSize->width = rows;
	sSize->height = columns;

	//create arrays for each opperation
	float **smooth = read_file(sSize, argv[2]);
	float **correlation = divide_by_kernel_sum(smooth, sSize);
	float **convolution = flip_mask(correlation, sSize); //uses the flipped kernel

	//reset rows and columns for v/h kernels now
	rows = 0, columns = 0;

	//opens third arg, (either v/h kernel)
	fp = fopen(argv[3], "r");
	Area *kSize = (Area *) malloc(sizeof(Area)); //Another variable name kSize (kernel size)
	get_data_size(fp, &rows, &columns); //again, finds rows, columns from the kernel file
	fclose(fp);

	//initalize strcut variables width, height for kSize
	kSize->width = rows;
	kSize->height = columns;

	//create the kernel arrays from their files. (Same area: rows/columns)
	float **vkernel = read_file(kSize, argv[3]);
	float **hkernel = read_file(kSize, argv[4]);

	//re-open first arg, to being image editing and writing
	fp = fopen(argv[1], "r");
	FILE *fout = fopen("NewImageCalc.txt", "w"); //creates new txt file for motion
	if (fp == NULL)
		exit(-1);

	//struct variables, --> iSize (image size)
	Area *iSize = (Area *) malloc(sizeof(Area));
	uint16_t width = 0, height = 0; //initialize to zero to remove junk, if any
	find_width_height(name, &width, &height); //finds width, height

	//sets iSize; struct variables to new width/height
	iSize->width = width;
	iSize->height = height;

	//create image arrays, same size as the rest.
	uint8_t **image1 = allocate_memory(iSize->width, iSize->height);
	uint8_t **image2 = allocate_memory(iSize->width, iSize->height);
	uint8_t **image3 = allocate_memory(iSize->width, iSize->height);

	//readlines stores values, getline stores the memory at location (&line), at the size (&tok), in the first arg file
	//continues as long as this argument is reached each time. or, end of file
	while ((readlines = getline(&line, &tok, fp)) != -1) {
		processString(line);

		bzero(initImage, 256);   //empty string
		strcat(initImage, "images/");   //create new name for image
		strcat(initImage, line);   //adds new name to end of previous image

		//so on, and repeat for each different image
		strncpy(basename, initImage, strlen(initImage) - 4);
		strcpy(vertImage, basename);
		strcat(vertImage, "_vedges.pgm");

		strncpy(basename, initImage, strlen(initImage) - 4);
		strcpy(horzImage, basename);
		strcat(horzImage, "_hedges.pgm");

		strncpy(basename, initImage, strlen(initImage) - 4);
		strcpy(correlationImage, basename);
		strcat(correlationImage, "_corr.pgm");

		strncpy(basename, initImage, strlen(initImage) - 4);
		strcpy(convolutionImage, basename);
		strcat(convolutionImage, "_conv.pgm");

		image1 = readImage(initImage, image1, width, height);

		//add the vert edges image
		image2 = smooth_trim_image(image1, image2, iSize, vkernel, kSize); //smooths image
		make_new_image(image2, iSize, vertImage); //makes the vert edges image

		//add horz edges image
		image2 = smooth_trim_image(image1, image2, iSize, hkernel, kSize); //smooths image
		make_new_image(image2, iSize, horzImage); //makes the horz edges image

		//adds correlation image
		image2 = smooth_trim_image(image1, image2, iSize, correlation, sSize); //smooths image
		make_new_image(image2, iSize, correlationImage); //makes correlation image

		//adds convolution image
		image2 = smooth_trim_image(image1, image2, iSize, convolution, sSize); //smooths image
		make_new_image(image2, iSize, convolutionImage); //makes convolution image

		//flagging motion detection, adds first row in txt file
		if (init == 1) {
			firstCentroid = (Centroid *) find_centroid(image1, width, height);
			init = 0;
			image3 = readImage(initImage, image3, width, height);
			fprintf(fout, "%s \t (%d , %d) \t %s \t %s \n", line,
					firstCentroid->cx, firstCentroid->cy, "No Motion Centroid",
					"No Motion Diff");
		}

		//Detecting Motion Using Centroid Method
		nextCentroid = find_centroid(image1, width, height);
		int centroid_distance = distance_between_centroid(firstCentroid,
				nextCentroid);
		if (centroid_distance >= tol2) {
			centroidFlag = 1;
			strcpy(motion1, "Motion Centroid"); //found
		} else {
			centroidFlag = 0;
			strcpy(motion1, "No Motion Centroid"); //no motion
		}

		//Find motion through distance between centroids
		uint8_t maxDiff = difference(image1, image3, iSize);
		if (maxDiff >= tol1) {
			diffFlag = 1; //difference flag found
			strcpy(motion2, "Motion Difference");
		} else {
			diffFlag = 0; //difference flag not found
			strcpy(motion2, "No Motion Difference");
		}

		fprintf(fout, "%s\t (%d,%d)\t %s\t %s\n", line, firstCentroid->cx,
				firstCentroid->cy, motion1, motion2);
		firstCentroid = nextCentroid; //allows function to "restart" on centroid calc for each image
		image3 = readImage(initImage, image3, width, height);

	}

	printf("Finished, images created.");
	fclose(fp);
	return 0;
}

