#ifndef choose_h
#define choose_h

#include <stdio.h>
#include <ncurses.h>
#include <string.h>
void choose(char *pk){
	int x;
	initscr();
	printw("Pero cual era...?\n\n\n\t1) Charmander\n\t2) Bulbasor\n\t3) Squirtle\n\n>>");
	scanw("%d",&x);
	switch(x){
		case 1:
			strcpy(pk,"Charmander");
			endwin();
		break;
		case 2:
			strcpy(pk,"Bulbasor");
			endwin();
		break;
		case 3:
			strcpy(pk,"Squirtle");
			endwin();
		break;
		default:
			strcpy(pk,"Psyduck");
			endwin();
		}
	}
#endif
