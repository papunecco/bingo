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

struct JugadorE {

char nombre[40];
char apellido[40];
int dni;
float puntaje;
Carton carton;

};

//-----CARGAR DATOS JUGADOR-----

Jugador cargarDatosDelJugadorPorTeclado(){
    Jugador j=malloc(sizeof(struct JugadorE));
    char auxNombre[40]= " ";
    char auxApellido[40]= " ";
    char auxDni[10]= " ";
    int tam=0;//variable para guardar el tamanio del dni.
    printf("Ingrese su nombre: ");
    fflush(stdin);
    gets(auxNombre);
    strcpy(j->nombre,auxNombre);
    printf("\nIngrese su apellido: ");
    fflush(stdin);
    gets(auxApellido);
    strcpy(j->apellido,auxApellido);
    printf("\nIngrese su numero de documento: ");
    scanf ("%d", &j->dni);
    j->carton=iniciarCarton();
    j->puntaje=0;



    return j;
}

//-----CARGA LA ESTRUCTURA DE LA PC CON DATOS VACIOS-----

Jugador cargarDatosPC() {

Jugador pc=malloc(sizeof(struct JugadorE));
strcpy(pc->nombre," ");
strcpy(pc->apellido," ");
pc->carton=iniciarCarton(); //lo mas importante de esta funcion es crearle la estructura carton a la estructura jugador
pc->dni=0;
pc->puntaje=0;
return pc;

}

//-----DESTRUCTOR-----

Jugador destruirJugador(Jugador j) {

free(j);

}

//-----MOSTRAR JUGADOR-----

void mostrarJugador(Jugador j){
    printf("\n-----DATOS DEL PARTICIPANTE-----\n\n");
    printf("Nombre y apellido: %s %s\n\nDNI: %d\n",j->nombre,j->apellido,j->dni);
}

//-----MENU DE CARGA DE CARTONES-----

void menu (Jugador j, Jugador pc, int cartones) {

    int opcion;
    printf ("\n1-Para ingresar numeros manualmente\n2-Para ingresar numeros de forma aleatoria\n\nIngrese opcion: ");
    scanf ("%d", &opcion);

    switch(opcion) {

    case 1:

        cargarCartonPorTeclado(getMatriz(j->carton), cartones);
        cargarCartonAleatorio(getMatriz(pc->carton), cartones);

    break;


    case 2:

        cargarCartonAleatorio(getMatriz(pc->carton), cartones);
        cargarCartonAleatorio(getMatriz(j->carton), cartones);

    break;

    default: printf ("\n\nLa opcion ingresada es incorrecta, vuelve a ingresar una opcion: ");
    scanf ("%d", &opcion); break;

    } //cierra switch
}

//-----GETS-----

int getDni(Jugador j){
    return j->dni;}

float getPuntaje(Jugador j){
    return j->puntaje;}

char* getNombre(Jugador j){
    return j->nombre;}

char* getApellido(Jugador j){
    return j->apellido;}

Jugador getCarton (Jugador j){
    return j->carton;
}


//-----SETS-----

void setDni (Jugador j, int doc){

j->dni=doc;

}

void setPuntaje(Jugador j, float punt) {

j->puntaje=punt;

}

void setNombre(Jugador j, char nom[40]){

strcpy (j->nombre, nom);

}

void setApellido (Jugador j, char apell[40]) {

strcpy (j->apellido, apell);

}

void imprimirArchivo (Jugador j) {

system("CLS");
printf ("\t\nHistorial de puntajes:\n\n");

FILE * puntero;
puntero=fopen("Historial.txt", "r");
while (!feof(puntero)) {

    char aux[40]=" ";
    fgets(aux, 40, puntero);
    printf ("\n%s", aux);

}

fclose(puntero);

}
void guardarArchivo (Jugador j) {

FILE * puntero;
puntero=fopen("Historial.txt", "a");
fprintf (puntero, "%s %s %f\n", j->nombre, j->apellido, j->puntaje);
fclose(puntero);

}

