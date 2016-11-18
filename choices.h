#ifndef choices_h
#define choices_h
#include "global.h"
void choices(WINDOW *m, int hl){
	
	int a=2,b=2,x;
	box(m,0,0);
	
	for(x=0;x<n;x++){
		if(hl==x+1){
			wattron(m,A_REVERSE);
			mvwprintw(m,b,a,"%s",escoje[x]);
			wattroff(m,A_REVERSE);
			}
		else
			mvwprintw(m,b,a,"%s",escoje[x]);
		b++;}
	wrefresh(m);
	}
#endif
