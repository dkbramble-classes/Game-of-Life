#ifndef H_LIFE
#define H_LIFE
#include <stdio.h>
#include "file_utilities.h"
/*****************************************************************
Prints grid layout of input text, applies Game of Life Rules to the 
input and allows saving/loading of states

@author Dane Bramble
@version February 2018
*****************************************************************/

int boardw; //width of grid
int boardh; //height of grid
char **world; //2D array that contains current 'universe'
char *filearr; //array to take the input from the text file
char *filename; //current filepath of the input file


void create_universe();
void next_gen(int gencount);
void print_world();
void next_action();

#endif
