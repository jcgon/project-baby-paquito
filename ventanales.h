#ifndef ventanales_h
#define ventanales_h
#include <ncurses.h>

WINDOW *mkwin(int a, int b,int yinit,int xinit,int op)
{	WINDOW *current_win;
	
	if(op)
		current_win = newwin(a,b,yinit,xinit);
	else
		current_win = subwin(stdscr,a,b,yinit,xinit);
		
	box(current_win,0,0);
	wrefresh(current_win);
	
	return current_win;
};

void rmwin(WINDOW *w)
{
	
	wborder(w,' ',' ',' ',' ',' ',' ',' ',' ');
	wrefresh(w);
	delwin(w);
};

#endif
