#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "shout.h"
#include "choose.h"
#include "choices.h"
#include "global.h"
#include "cervatillo.h"



int main(){
//them good ol ints
int x,y=0,hl,c=0;
//sigue vivo?
bool vivo[2]={1,1},turn=1;
//para los jugadores y su token
char pk[50],* p;
p=&pk[0];
//para el menu
WINDOW *m;
hl=1;
//arroja resultados aletorios diferentes cada segundo paro

time_t t;
srand((unsigned) time(&t));


initscr();
printw("Un lindo dia cualquiera te encuentras caminando muy campante hacia el pueblo vecino. Cuando muy depronto...\n");
printw("Volteas a ver a un chavo medio raro directo a los ojos. Este muchacho parece tener solo una cosa en mente, lentamente se acerca hacia ti con una mirada intensa q trata de penetrar hasta tu alma. Sin dejar pasar un segundo exclama:\n");
getch();
shout();
getch();
clear();

printw("En el panico del momento logras recordar que un profesor solitario alguna vez te regalo una pequeña creatura muy poderosa tratando de quedar bn con tu madre\n");
choose(p);
clear();

initscr();
printw("Tan pronto recuerdas su nombre dejas escapar una sonrisa con aire de superioridad. Tan solo te toma un segundo alcanzar la pokebola de tu mochila, las palabras se escuren de de tu boca como si no fueran tuyas\n%s YO TE ELIJO!\n",pk);
getch();
clear();
endwin();



mvprintw(0,30,"Novato, crees poder vencerme con ese pequeño %s",pk);
getch();
clear();
mvprintw(0,30,"Arbok, yo te elijoooooooo!");
getch();
clear();


do{

	hit[turn]=rand()%2;
	dano[turn]=rand()%6;
	
	mvprintw(6,0,"Jugador %d, Es su turno",turn+1);
	getch();
	clear();

	mvprintw(1,60,"Arbok");
	for(x=4;x>=dt[0];x--)
		mvprintw(2,60+x,"=");
	mvprintw(2,57,"HP(");
	mvprintw(2,65,")");
	getch();
	
	mvprintw(20,5,"%s",pk);
	for(x=4;x>=dt[1];x--)
		mvprintw(21,5+x,"=");
	mvprintw(21,2,"HP(");
	mvprintw(21,10,")");
	getch();


clear();
noecho();
cbreak();
initx=(80-width)/2;
inity=(24-length)/2;
m=newwin(length,width,inity,initx);
keypad(m,1);
mvprintw(6,0,"Utilize las flechas para resaltar su eleccion, presione enter para escoger");
refresh();
choices(m,hl);
while(1){
	y=wgetch(m);
	switch(y){
		case KEY_UP:
			if(hl==1)
				hl=n;
			else
				hl--;
		break;
		case KEY_DOWN:
			if(hl==n)
				hl=1;
			else
				hl++;
		break;
		case 10:
			c=hl;
		break;
		default:
			mvprintw(17,0,"El caracter que uds presiono [%3d] no es valido",c);
			refresh();
		break;
		}
	choices(m,hl);
	if(c!=0)
		break;
	}
mvprintw(17,0,"Bn, uds opto por la opcion %d) %s",c,escoje[c-1]);
getch();
clrtoeol();
refresh();
vivo[turn]=cervatillo(c,turn);
turn=!turn;
clear();
}while(vivo[0]&&vivo[1]);

endwin();
return 0;
}
