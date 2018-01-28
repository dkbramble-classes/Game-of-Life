#include <stdio.h>
#include <stdlib.h>
#include "life.h"

void create_universe(int boardwidth, int boardheight){
	world = malloc((boardwidth*boardheight)*sizeof(char));
}

void next_gen(int gencount){

}

void print_world(){

}

void next_action(){
	char option[10];
	printf("Next Move? Options:\n save,\n quit,\n continue one generation (continue),\n or continue "insert number" generations (more)?";
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
