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

//-----BUCLE DE JUEGO-----

void bucleDeJuego (int m[][FILAS][COLUMNAS], int mpc[][FILAS][COLUMNAS], int v[], int cartones, Jugador j, Jugador pc) {

int bolilla;
int contadorLinea=0;
int contadorColumna=0;
int contadorJugadas=0;
float puntajeJugador=0;
float puntajePC=0;
printf ("\n\n--------------------------------\n\n");
printf ("Cuando salga sorteado un numero de su carton, este sera marcado con un 0\n");
printf ("\nPresiona ENTER para comenzar el sorteo...");
getch();

for (int i=0; i<90; i++) {

        bolilla=v[i];
        system("CLS");
        contadorJugadas++;
        printf ("\nJUGADA NUMERO %d\n", contadorJugadas);
        printf ("\nSALIO LA BOLILLA NUMERO %d\n", bolilla);

    for (int j=0; j<cartones; j++) {

        for (int k=0; k<FILAS; k++) {

            for (int l=0; l<COLUMNAS; l++) {

                if (m[j][k][l]==bolilla){

                    m[j][k][l]=0;
                    printf ("\nSALIO UN NUMERO DEL JUGADOR!\n");
                    if(cantarLinea(m,cartones)==1  &&  contadorLinea==0){
                        printf("\n\t\t\t\t\tEL JUGADOR HIZO LINEA!!\n");
                        puntajeJugador+=20;
                        contadorLinea=1;
                    }
                    if(cantarColumna(m,cartones)==1 &&  contadorColumna==0){
                        printf("\n\t\t\t\t\tEL JUGADOR HIZO COLUMNA!!\n");
                        puntajeJugador+=10;
                        contadorColumna=1;
                    }
                }

                if (mpc[j][k][l]==bolilla) {

                    mpc[j][k][l]=0;
                    printf ("\nSALIO UN NUMERO DE LA MAQUINA!\n");
                    if(cantarLinea(mpc,cartones)==1  &&  contadorLinea==0){
                        printf("\n\t\t\t\t\tLA MAQUINA HIZO LINEA!!\n");
                        puntajePC+=20;
                        contadorLinea=1;
                    }
                    if(cantarColumna(mpc,cartones)==1  &&  contadorColumna==0){
                        printf("\n\t\t\t\t\tLA MAQUINA HIZO COLUMNA!!\n");
                        puntajePC+=10;
                        contadorColumna=1;
                    }
                }
                if(cantarBingo(m,cartones)==1  &&  i!=91){
                    printf("\n\t\t\t\t\tEL JUGADOR GANO!! HIZO BINGO\n");
                    puntajeJugador+=70;
                    if(i<30){
                        puntajeJugador=puntajeJugador*2;
                    }else{
                        if(i<50){
                            puntajeJugador=puntajeJugador*1.7;
                        }else{
                            if(i<70){
                                puntajeJugador=puntajeJugador*1.5;
                            }else{
                                puntajeJugador=puntajeJugador*1;
                            }
                        }
                    }
                    i=91;
                }
                if(cantarBingo(mpc,cartones)==1  &&  i!=91){
                    printf("\n\t\t\t\t\tLA MAQUINA GANO!! HIZO BINGO\n");
                    puntajePC+=70;
                    if(i<30){
                        puntajePC=puntajePC*2;
                    }else{
                        if(i<50){
                            puntajePC=puntajePC*1.7;
                        }else{
                            if(i<70){
                                puntajePC=puntajePC*1.5;
                            }else{
                                puntajePC=puntajePC*1;
                            }
                        }
                    }
                    i=91;
                }
            }

        }

    }

    printf ("\n\n-----Cartones del jugador-----\n\n");
    imprimirCarton(m, cartones);
    printf ("\n\n-----Cartones de la maquina-----\n\n");
    imprimirCarton(mpc, cartones);
    if (i<90) {
    printf ("\n\n--------------------------------\n\n");
    printf ("\nPresiona ENTER para sacar otra bolilla...");
    getch();
    }

    }

setPuntaje(j,puntajeJugador);
setPuntaje(pc,puntajePC);
guardarArchivo(j);
}

int cantarLinea(int m[][FILAS][COLUMNAS],int cartones){
    int resultado=0;
    int acum;
    for(int i=0;i<cartones;i++){
        for(int j=0;j<FILAS;j++){
            acum=0;
            for(int k=0;k<COLUMNAS;k++){
                acum=acum+m[i][j][k];
            }
            if(acum==0){
                resultado=1;
            }
        }
    }

    return resultado;
}
int cantarColumna(int m[][FILAS][COLUMNAS],int cartones){
    int resultado=0;
    int acum;
    for(int i=0;i<cartones;i++){
        for(int j=0;j<COLUMNAS;j++){
            acum=0;
            for(int k=0;k<FILAS;k++){
                acum=acum+m[i][k][j];
            }
            if(acum==0){
                resultado=1;
            }
        }
    }
    return resultado;
}
int cantarBingo(int m[][FILAS][COLUMNAS],int cartones){
    int resultado=0;
    int acum;
    for(int i=0;i<cartones;i++){
        int acum=0;
        for(int j=0;j<FILAS;j++){
            for(int k=0;k<COLUMNAS;k++){
                acum=acum+m[i][j][k];
            }
        }
        if(acum==0){
            resultado=1;
        }
    }
    return resultado;

}

