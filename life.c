#include <stdio.h>
#include <stdlib.h>
#include "life.h"

void create_universe(int boardwidth, int boardheight){
    boardw = boardwidth;
    boardh = boardheight;
	world = malloc((boardwidth*boardheight)*sizeof(char));
    srand(time(null));
    
    for (i = 0; i < (boardwidth*boardheight);i++){
        world[i] = '-';
        random = rand() % (boardwicth*boardheight);
        world[random] = '*';
    }
    print_world();
}

void next_gen(int gencount){
    print_world();
}

void print_world(){
    for (i = 0; i < (boardw*boardh); i ++){
        if (i % board = 0) {
            printf(%c, world[i]);
        } else {
            printf(%c\n, world[i]);
        }
    }
    next_action();
}

void next_action(){
	char option[10];
	printf("Next Move? Options:\n save,\n quit,\n continue one generation (continue),\n or continue 'insert number' generations (more)?";
	scanf(%s, &option);
	switch(option){
		case 'continue':
			next_gen(1);
		case 'more':
			int option2;
			printf("How many generations do you want to skip?\n Insert Number:"
			scanf(%d, &option2);
			next_gen(option2);
		case 'save':
		case 'load':
		case 'quit':
		default :
			printf("I'm sorry, that's not an option");
			next_action();
	}
}
