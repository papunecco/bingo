#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "jugador.h"
#include "carton.h"
#include "bolillas.h"
#include "bucle.h"
#define COLUMNAS 5
#define FILAS 3
#define MAX_CARTONES 3

//--------------------------------------MAIN-------------------------------------------

int main(){

srand (time(NULL));
int opcion;
do {
printf ("\n----- BIENVENIDOS AL BINGO -----\n\n1-Para comenzar a jugar\n2-Para ver historial de puntajes\n0-Para salir del juego\n\nIngrese opcion: ");
scanf ("%d", &opcion);
switch (opcion) {
case 1:
system("CLS");
printf("\nAntes de comenzar a jugar debe cargar sus datos...\n\n");
Jugador jugador;
Jugador PC;
jugador=cargarDatosDelJugadorPorTeclado();
PC=cargarDatosPC();
system("CLS");
mostrarJugador(jugador);
int cartones=cuantosCartones();
menu(jugador, PC, cartones);
system("CLS");
printf ("\n\n-----Cartones del jugador-----\n\n");
imprimirCarton(getMatriz(getCarton(jugador)), cartones);
printf ("\n\n-----Cartones de la maquina-----\n\n");
imprimirCarton(getMatriz(getCarton(PC)), cartones);
int sorteo[90];
cargarVectorConAleatoriosSinRepetir(sorteo,90);
bucleDeJuego(getMatriz(getCarton(jugador)), getMatriz(getCarton(PC)), sorteo, cartones, jugador, PC);
printf ("\n--------------------------------\n");
printf ("\n\nEL PUNTAJE DEL JUGADOR FUE %.2f\nEL PUNTAJE DE LA PC FUE %.2f\n\n", getPuntaje(jugador), getPuntaje(PC));
printf ("\n--------------------------------\n");
printf ("\nPresiona ENTER para volver al menu...");
getch();
system("CLS");break;

case 2: imprimirArchivo();
printf ("\nPresiona ENTER para volver al menu...");
getch();
system("CLS");break;

case 0:system("cls");
printf ("\nGracias por jugar, hasta luego!!\n");break;

default: system("CLS");
printf ("La opcion ingresada no es correcta\n"); break;}}while(opcion!=0);

return (0);

}
