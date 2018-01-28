#ifndef H_LIFE
#define H_LIFE

int boardw;
int boardh;
char*  world;

void create_universe(int boardwidth, int boardheight);
void next_gen(int gencount);
void next_action();

#endif
