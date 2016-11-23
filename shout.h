#ifndef shout_h
#define shout_h

#include <stdio.h>
#include <ncurses.h>
void shout(){
	
	initscr();
	printw("I LIKE SHORTS!\nThey're comfy and easy to wear!");
	endwin();
	
	
	};
#endif
