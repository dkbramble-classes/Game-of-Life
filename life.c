#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "life.h"

void create_universe(int boardwidth, int boardheight){
    boardw = boardwidth;
    boardh = boardheight;

 	int i, j, count;
	world = (char **)malloc(boardwidth*sizeof(char *));

	for (i=0; i<boardwidth; i++){
         world[i] = (char *)malloc(boardheight * sizeof(char));
    }
   
    for (i = 0; i < boardwidth; i++){
    	for (j = 0; j < boardheight; j++){
        		world[i][j] = '*';

      	}
    }	

    print_world();
}

void next_gen(int gencount){
	int i, j;
	char **worldtwo = (char **)malloc(boardw*sizeof(char *));

	for (i=0; i<boardw; i++){
         worldtwo[i] = (char *)malloc(boardh * sizeof(char));
    }

	while (gencount > 0){
		for (i = 0; i < boardw; i++){
			for (j = 0; j < boardh; j++){
				int neighbor = 0;
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
					worldtwo[i][j] = 'O';
				}
				else if(neighbor == 3 && world[i][j] == 'O'){
					worldtwo[i][j] = '*';
				}
				else{
					worldtwo[i][j] = world[i][j];
				}
			}
		}
		for (i = 0; i < boardw; i++){
			for (j = 0; j < boardh; j++){
				world[i][j] = worldtwo[i][j];
			}
		}
		gencount --;
	}

	for (int i=0; i<boardw; i++){
         free(worldtwo[i]);
    }

    free(worldtwo);
    print_world();
}


void print_world(){
	
	printf("\n\nCell Key:\n   Alive: *\n   Dead: O\n\n");
    for (int i = 0; i < boardw; i++){
    	for (int j = 1; j <= boardh; j++){
    		if (j % boardh == 0){
    			printf("%c\n", world[i][j - 1]); 
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

void next_action(){
	char option[50];
	printf("\nNext Move?\nOptions:\n   save,\n   quit,\n   continue one generation (one),\n   continue many generations (more)\n");
	scanf("%s", option);
	if (strcmp(option, "one") == 0 || strcmp(option, "One") == 0){
		next_gen(1);
	}
	else if (strcmp(option, "more") == 0 || strcmp(option, "More") == 0){
		int option2 = 0;
		printf("How many generations do you want to skip?\nInsert Number:");
		scanf("%d", &option2);
		next_gen(option2);
	}
	else if (strcmp(option, "save") == 0 || strcmp(option, "Save") == 0){
	
	}
	else if (strcmp(option, "load") == 0 || strcmp(option, "Load") == 0){

	}
	else if (strcmp(option, "quit") == 0 || strcmp(option, "Quit") == 0){
	 	for (int i=0; i<boardw; i++){
	         free(world[i]);
	    }
	    free(world);
	}
	else{
		printf("Please enter a valid option");
		next_action();
	}
}


int main( int argc, char* argv[]){
	create_universe(5,5);
} 	
