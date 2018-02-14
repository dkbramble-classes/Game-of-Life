#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "life.h"

/*****************************************************************
Prints grid layout of input text, applies Game of Life Rules to the 
input and allows saving/loading of states

Sources: 
	geeksforgeeks.org for how to malloc 2D array
	stackoverflow.com for how to use strcmp()


@author Dane Bramble
@version February 2018
*****************************************************************/


/*****************************************************************
Takes the file inputs and creates a 2D array for the grid
*****************************************************************/
void create_universe(){
 	int i, j, count;
	world = (char **)malloc(boardw*sizeof(char *));

	for (i = 0; i < boardw; i++){ //allocates an array of memory for each memory location in world
         world[i] = (char *)malloc(boardh * sizeof(char));
    }
   	count = 0;
    for (i = 0; i < boardw; i++){ //sets world array equal to the input array
    	for (j = 0; j < boardh; j++){
    			if(filearr[count] == '-'){ 
    				world[i][j] = ' '; //converts '-' characters in array to ' ' to read the grid more easily
    			}
    			else{
    				world[i][j] = filearr[count];
    			}
        		count ++;
      	}
    }	
    free(filearr); //free the input array memory
    print_world();
}

/*****************************************************************
Applies the rules of the Game of Life onto the current board,
then prints the changed board.
@param the number of generations moved forward
*****************************************************************/
void next_gen(int gencount){
	int i, j;
	char **worldtwo = (char **)malloc(boardw*sizeof(char *));

	for (i = 0; i < boardw; i++){
         worldtwo[i] = (char *)malloc(boardh * sizeof(char)); //creates copy of the array to get new values
    }

	while (gencount > 0){ //for however many generations you want
		for (i = 0; i < boardw; i++){
			for (j = 0; j < boardh; j++){
				int neighbor = 0;
				//counts all alive neighbors in all directions, ignores the boundaries
				if (i < (boardw - 1)){
					if(world[i + 1][j] == '*'){
						neighbor++;
					}
					if (j < (boardh - 1)){
						if(world[i + 1][j + 1] == '*'){
							neighbor++;
						}
					}
					if(j > 0){
						if(world[i + 1][j - 1] == '*'){
							neighbor++;
						}
					}
				}
				if (i > 0){
					if(world[i - 1][j] == '*'){
						neighbor++;
					}
					if(j > 0){
						if(world[i - 1][j - 1] == '*'){
							neighbor++;
						}
					}
					if (j < (boardh - 1)){
						if(world[i - 1][j + 1] == '*'){
							neighbor++;
						}
					}
				}

				if(j > 0){
					if(world[i][j - 1] == '*'){
						neighbor++;
					}
				}
				if (j < (boardh - 1)){
					if(world[i][j + 1] == '*'){
						neighbor++;
					}
				}
				

				if((neighbor > 3 || neighbor < 2) && world[i][j] == '*' ){
					worldtwo[i][j] = 'O'; //cell dies if it has too many or too few neighbors
				}
				else if(neighbor == 3 && (world[i][j] == 'O' || world[i][j] == ' ')){
					worldtwo[i][j] = '*'; //cell comes back to life if it has 3 neighbors
				}
				else{
					worldtwo[i][j] = world[i][j]; //cell stays the same otherwise
				}
			}
		}

		for (i = 0; i < boardw; i++){
			for (j = 0; j < boardh; j++){
				world[i][j] = worldtwo[i][j]; //set the original world equal to the copy
			}
		}
		gencount --;
	}

	for (i = 0; i < boardw; i++){
         free(worldtwo[i]); //free worldtwo memory
    }

    free(worldtwo);
    print_world();
}

/*****************************************************************
Prints the current state of the board
*****************************************************************/
void print_world(){
	int i,j;
	printf("\n\nCell Key:\n   Alive: *\n   Dead: O\n\n"); //Legend of cell values
    for (i = 0; i < boardw; i++){
    	for (j = 1; j <= boardh; j++){
    		if (j % boardh == 0){
    			printf("%c\n", world[i][j - 1]); //create newlines for grid in relation to the width
    			printf("%c\n", ' '); 
    		}
    		else{
        		printf("%c", world[i][j - 1]); 
        		printf("%c", ' '); 
        	} 
      	}
    }

    next_action();
    
}
/*****************************************************************
Asks for an input to decide what to do next (save, load, etc.)
*****************************************************************/
void next_action(){ 
	int i,j;
	char option[50];
	printf("\nNext Move?\nOptions:\n   save,\n   load,\n   quit,\n   continue one generation (one),\n   continue many generations (more)\n");
	scanf("%s", option); //requests input
	if (strcmp(option, "one") == 0 || strcmp(option, "One") == 0){ //looks at what you entered, first letter can be lower or uppercase
		next_gen(1); //move forward one generation
	}
	else if (strcmp(option, "more") == 0 || strcmp(option, "More") == 0){
		int option2 = 0;
		printf("How many generations do you want to skip?\nInsert Number:");
		scanf("%d", &option2);
		next_gen(option2); //move forward any number of generations
	}
	else if (strcmp(option, "save") == 0 || strcmp(option, "Save") == 0){
		printf("Are you sure? This will overwrite the previous save.\nAnswer(yes/no):\n");
		char option2[50];
		scanf("%s", option2); //makes sure you are cool with overwriting input file
		if(strcmp(option2, "yes") == 0 || strcmp(option2, "Yes") == 0){
			char *newworld; //changes 2D array back to single array to be put into text file
			newworld = (char*) malloc((boardw * boardh)*sizeof(char)); 
			int count = 0;
		    for (i = 0; i < boardw; i++){
		    	for (j = 0; j < boardh; j++){
		    		if(world[i][j] == ' '){ //replaces spaces in world with '-', easier to read this way
		    			newworld[count] = '-';
		    		}
		    		else{
		    			newworld[count] = world[i][j];
		    		}
	        		count ++;
		      	}
		    }	
			write_file(filename, newworld, &boardw, &boardh);
			free(newworld);
			printf("File saved!");
			print_world(); //prints again, just for convenience
		}
		else if (strcmp(option2, "no") == 0 || strcmp(option2, "No") == 0){
			next_action(); //if unsure, give another option
		}
		else{
			printf("Please enter a valid option");
			next_action(); //option entered was not valid, asks again
		}
	}
	else if (strcmp(option, "load") == 0 || strcmp(option, "Load") == 0){
		if (read_file(filename, &filearr, &boardw, &boardh) == 0){ //read again from input file, reacreates world
			create_universe();
		}
	}
	else if (strcmp(option, "quit") == 0 || strcmp(option, "Quit") == 0){
	 	for (i = 0; i < boardw; i++){
	         free(world[i]); //frees all 2D array memory, not just world
	    }
	    free(world);
	}
	else{
		printf("Please enter a valid option");
		next_action(); //not a valid option, asks again
	}
}

int main( int argc, char* argv[]){
	filename = "/Users/Dane/Documents/input.txt"; //local filepath for input
	if (read_file(filename, &filearr, &boardw, &boardh) == 0){ //returns one if the file is not found
		create_universe();
	}
} 	
