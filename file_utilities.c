#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*****************************************************************
Provides functions to read or write an input text file
Sources: zentut.com for use on how to read/write files

Some function parameters were changed with Professor Woodring's Permission

@author Dane Bramble
@version February 2018
*****************************************************************/


/*****************************************************************
Reads in file, initializes parameters with the given input

@param filepath name
@param Array to be passed to grid array
@param grid width
@param grid height
*****************************************************************/
int read_file( char* filename, char **buffer, int* boardw, int* boardh){
	FILE *fp;
	fp = fopen(filename, "r");

	if (fp == NULL){ //if file could not be found, return an error
        printf("\nCould not open file, check filepath\n %s",filename);
        return 1;
    }

 	fscanf(fp, "%d %d", boardw, boardh); //find the correct size of the grid first
 	*buffer = (char*) malloc((*boardw * *boardh)*sizeof(char)); //then assign the correct size for the array and set its values
 	fscanf(fp, "%s", *buffer);
 
    fclose(fp);
    return 0;
}

/*****************************************************************
Rewrites text file with the given parameters, uses same format as 
read_file so it can be read again

@param filepath name
@param current grid array to be saved
@param grid width
@param grid height
*****************************************************************/
int write_file( char* filename, char *buffer, int* boardw, int* boardh){
	FILE *fp;
	fp = fopen(filename, "w");	
 	fprintf(fp, "%d %d %s", *boardw, *boardh, buffer); //sets the current text file with the given values
    fclose(fp);
    return 0;
}