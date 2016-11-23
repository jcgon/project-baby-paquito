#include <ncurses.h>
#include <unistd.h>
#include <time.h>

#define delay 10000

int main(int argc, char *argv[]){

int initx=0,inity=1,xtops=0,ytops=0,xnext=0,flow=1,fl=0;
time_t t;
struct tm *now;
char formatime[80];
WINDOW *fancy, *records;

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
getmaxyx(stdscr,ytops,xtops);
records=subwin(stdscr,ytops-3,xtops-2,3,2);


while(1){
getmaxyx(stdscr,ytops,xtops);
clear();
touchwin(records);
mvwprintw(records,2, 2, "hola");


//obtenemos la hora actual en Milis
t=time(0);

//Seguido de un formato para q sea legible
//y familiar para el usr
now=localtime(&t);
strftime(formatime,sizeof(formatime),"%a %Y-%m-%d %H:%M:%S %Z", now);

//Reloj ya con formato
mvprintw(0,xtops/2-14,"%s\n",formatime);

mvprintw(inity,initx,"o");
mvprintw(ytops-1,initx,"o");


refresh();
wrefresh(records);
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
