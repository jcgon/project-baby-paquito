#ifndef cervatillo_h
#define cervatillo_h
#include "global.h"
#include <ncurses.h>
#include <stdlib.h>
int cervatillo(int c, int turn){
switch(c){
case 1:
	if(hit[turn]){
		mvprintw(0,20,"Atakas sin pena contra la arena, inflinges %d de dano\n",dano[turn]);
		getch();
		dt[!turn]+=dano[turn];
	if(dt[!turn]>=4){
		mvprintw(0,20,"Felicidades, Has derrotado a tu Rival\n");
		getch();
		return 0;
	}else{
		hit[turn]=rand()%2;
		return 1;}return 1;}
	else{
		mvprintw(0,20,"Fallaste \n");
		getch();
		return 1;
	}mvprintw(20,20,"\n %d - %d",hit[turn],dano[turn]);
	
break;

case 2:
	if(hit[turn]){
		mvprintw(20,0,"Logras escapar por ahora, +1 HP");
		dt[turn]--;
		return 1;
	}else{
		mvprintw(0,20,"Solo lo haces peor si corres!");
		dt[turn]++;
		if(dt[turn]>=4)
			return 0;}
break;

case 3:
	if(hit[turn]){
		mvprintw(20,0,"Te gustan los caballitos?");
		return 1;}
	else{	
		mvprintw(0,20,"Saves que no me venceras por aburrimiento cierto?");
		return 1;}
break;
case 4:
	if(hit[turn]){
		mvprintw(20,0,"ZZZ...");
		dt[turn]=0;
		return 1;
	}else{
		mvprintw(20,0,"... Sabia que no debia haberle dado cafe :c");
		return 1;}
break;}}
#endif
