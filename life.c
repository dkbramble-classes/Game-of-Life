#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "life.h"

void create_universe(int boardwidth, int boardheight){
    boardw = boardwidth;
    boardh = boardheight;
	world = malloc((boardwidth*boardheight)*sizeof(char));
    
    for (int i = 0; i < (boardwidth*boardheight);i++){
        world[i] = '-';
        if (i % 2 == 0){
        	world[i] = '*';
        }
    }
    print_world();
}

void next_gen(int gencount){
    print_world();
}

void print_world(){
	printf("\n\nCell Key:\n   Alive: *\n   Dead: O\n   Empty: -\n\n");
    for (int i = 1; i <= (boardw*boardh); i ++){
        if ((i % boardw == 0)) {
            printf("%c\n",world[i - 1]);
        } else {
            printf("%c",world[i - 1]);
        }
    }
    next_action();
}

void next_action(){
	char option[50];
	printf("\nNext Move?\nOptions:\n   save,\n   quit,\n   continue one generation (continue),\n   continue many generations (more)\n");
	scanf("%s", option);
	if (strcmp(option, "continue") == 0){
		next_gen(1);
	}
	else if (strcmp(option, "more") == 0){
		int option2 = 0;
		printf("How many generations do you want to skip?\nInsert Number:");
		scanf("%d", &option2);
		next_gen(option2);
	}
	else if (strcmp(option, "save") == 0){
	
	}
	else if (strcmp(option, "load") == 0){

	}
	else if (strcmp(option, "quit") == 0){
		free(world);
	}
	else{
		printf("Please enter a valid option");
		next_action();
	}
}


int main( int argc, char* argv[]){
	create_universe(25,25);
} 	
