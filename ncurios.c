//demo.c
#include <ncurses.h>
#include <unistd.h>
#include <time.h>

#define delay 10000

int main(int argc, char *argv[]){

int initx=0,inity=1,xtops=0,ytops=0,xnext=0,flow=1;
time_t t;
struct tm *now;
char formatime[80];


initscr();
noecho();
curs_set(0);

/*  Averiguaremos el tamño estandar de una nueva ventana, si
 *  se usa dentro del cyclo, el contenido conservara sus 
 *  dimensiones aun al maximizar/minimizar la ventana.
 *
 *  Al usarlo fuera se ignora el maximizado/minimizado de la
 *  ventana y el contenido asume q la ventana sigue teniendo
 *  las dimensiones originales.
 *
 *  esta funcion crea una variable global tipo WINDOW * stdscr
 *
 *            getmaxyx(stdscr,ytops,xtops);
 */

while(1){
getmaxyx(stdscr,ytops,xtops);
clear();

//obtenemos la hora actual en Milis
t=time(0);

//Seguido de un formato para q sea legible
//y familiar para el usr
now=localtime(&t);
strftime(formatime,sizeof(formatime),"%a %Y-%m-%d %H:%M:%S %Z", now);

//Reloj ya con formato
mvprintw(0,xtops/2,"%s\n",formatime);

mvprintw(inity,initx,"°");
refresh();

//Demora $(delay) milisecs cada paso
usleep(delay);


//si llegaste a una pared, cambia de dirreccion
xnext=initx+flow;
if(xnext>=xtops||xnext<0){
  flow*= -1;
}else
  initx+=flow;
//si no a llegado, avanza otro lugar en la misma dirreccion
}

endwin();
return 0;
}
