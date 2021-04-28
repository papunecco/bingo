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

//-----CARGAR VECTOR DE SORTEO DE NUMEROS-----

void cargarVectorConAleatoriosSinRepetir(int v[], int tam){

    int numeroNuevo = 0;
    int resultadoBusqueda = 0 ;

    for ( int i = 0; i<tam; i++){

        do{
        numeroNuevo = 1+ rand() % 90;
        resultadoBusqueda = busquedaSecuencialVector(v, tam, numeroNuevo); //nos da la posicion ---> -1
        }while(resultadoBusqueda!=-1);

        v[i]= numeroNuevo;
    } //cierra for
}

//-----MOSTRAR EL VECTOR DE BOLILLAS-----

void mostrarVector(int v[], int tam){

    printf("\n\n---------------\n\n");

    for (int  i = 0; i <tam; i++){

        printf(" %d ", v[i]);

    } //cierra for
}


//-----BUSQUEDA SECUENCIAL EN VECTOR-----

int busquedaSecuencialVector(int v[], int tam, int buscar){

      int pos = -1;

      for ( int i = 0; i<tam; i++){

          if ( v[i]==buscar){ //Lo encontre

              pos = i;
          } //cierra if
        }//cierra for

return pos;
}

