/*
 *
 * Comp 411 Assignment 7
 * Convert Color Image (PPM) to GrayScale (PGM)
 * Fall 2013
 *
 * Author: Robert Stokes
 *
 */

#include <stdio.h>
#include <string.h>

main() {
//read in 3 numbers from keyboard -- magic number, number of columns, and number of rows.

//printf("Enter magic number, number of columns and number of rows: ");
//fflush(stdout);

	char magic_Number[2];
	int numColumns;
	int numRows;
	int maxValue;

//read in string (P2 or P3) and the numColumns and numRows from keyboard.

	scanf("%s%d%d", magic_Number, &numColumns, &numRows);
	//printf("%s %d %d\n", magic_Number, numColumns, numRows);
	//fflush(stdout);

	int true = 1;
	while (true) {
		//read in max value and check that it is at least 1.
		//printf("Enter a max value: \n");
		//fflush(stdout);
		scanf("%d", &maxValue);
		//printf("%s %d\n", "maxValue:", maxValue);
		if (maxValue >= 1 && maxValue <= 255) {
			break;
		}

		printf("Error. Max value must be between 1 and 255 (inclusive).");
		fflush(stdout);
	}	//end while loop
		//printf("%s %d\n", "maxValue:", maxValue);

	//now compute the gray value (PGM) using the formula provided.
	int total = numColumns * numRows; //this is the number of values which need to be read in and converted.


	int R; //red value
	int G; //green value
	int B; //blue value
	int gray_Value;

	int i = 0;
	int length = total/3;
	int holder[length];

	while (i < length) {
		int R; //red value
		int G; //green value
		int B; //blue value

		//this loop will read the data for calculation.
		scanf("%d%d%d", &R, &G, &B);

		//calculation of gray value.
		//print gray value to console.
		gray_Value = ((R + G + B) * 255) / (3 * maxValue);
		//printf("%d\n", gray_Value);
		holder[i] = gray_Value;
		i++;

	}

	//print out the heading and then all the gray values from holder[]
	printf("P2\n");
	printf("%d\n", numColumns);
	printf("%d\n", numRows);
	printf("%d\n", maxValue);
	for (i = 0; i < length; i++) {
		printf("%d\n", holder[i]);

	}


} //end main

