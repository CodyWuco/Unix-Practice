/* Cody Wuco                                       */
/* Lab 4                                           */
/* Figure the area of the top of a cylinder        */
/* and the volume of a cylinder                    */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define FILE_IN  "lab4.dat"
//#define FILE_IN  "lab4sample.dat"
#define FILE_OUT "lab4.out"

int main(void)
{
	int count;
	double radius, height, area, vol;
	FILE * input_file;
	FILE * output_file;

	input_file = fopen(FILE_IN, "r");
	if(input_file == NULL){
	    printf("Error on opening the input file \n");
	    exit(EXIT_FAILURE);
	}

	output_file = fopen(FILE_OUT, "w");
	if(output_file == NULL){
	    printf("Error on opening the output file \n");
	    exit(EXIT_FAILURE);
	}

	fprintf(output_file, "Cody Wuco. Lab 4.\n");

	count = 1;

	while ((fscanf(input_file,"%lf%lf", &radius, &height)) == 2){
	    fprintf(output_file, "\nCylinder %1d", count);
	    fprintf(output_file, "\nThe radius is:    %9.3f", radius);
	    fprintf(output_file, "\nThe height is:    %9.3f", height);
	    area = M_PI * radius * radius;
	    vol  = M_PI * radius * radius * height;
	    fprintf(output_file, "\nThe top area is:  %9.3f", area);
	    fprintf(output_file, "\nThe volume is:    %9.3f\n", vol);
	    count++;
	}
}
