#ifndef H_FILE_UTIL
#define H_FILE_UTIL
#include <stdio.h>
/*****************************************************************
Provides functions to read or write an input text file
Some function parameters were changed with Professor Woodring's Permission

@author Dane Bramble
@version February 2018
*****************************************************************/

int read_file(char* filename, char **buffer, int* boardw, int* boardh);
int write_file( char *filename, char *buffer, int* boardw, int* boardh);

#endif