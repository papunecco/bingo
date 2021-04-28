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

struct CartonE {

int matriz[MAX_CARTONES][FILAS][COLUMNAS];

};

//-----INICIAR EN 0 CARTONES-----

Carton iniciarCarton () {

Carton c=malloc(sizeof(struct CartonE));

int matriz[MAX_CARTONES][FILAS][COLUMNAS];

for (int i=0; i<MAX_CARTONES; i++) {

    for (int j=0; j<FILAS; j++) {

        for (int k=0; k>COLUMNAS; k++) {

            matriz[i][j][k]=-1;

        }

    }

}

return c;

}

//-----DESTRUCTOR-----

Carton destruirCarton (Carton c) {

free(c);

}

//-----BUSQUEDA EN MATRIZ-----

int busquedaEnMatriz(int m[][FILAS][COLUMNAS], int buscar, int cartones) { //funcion para chequear que no se repitan los numeros

    int pos= -1;

    for (int i=0; i<cartones; i++) {

            for (int j=0; j<FILAS; j++) {

            for (int k=0; k<COLUMNAS; k++) {

                if (m[i][j][k]==buscar) {
                pos=m[i][j][k];
                } //cierra el if
            }
        }}
return pos;
}

//-----CARGAR CARTON ALEATORIO-----

void cargarCartonAleatorio (int m[][FILAS][COLUMNAS], int cartones) {

    int resultado;
    int numeroAleatorio;

        for (int i=0; i<cartones; i++) {
            for (int j=0; j<FILAS; j++) {
                for (int k=0; k<COLUMNAS; k++) {
                numeroAleatorio= rand()%90+1;
                resultado=busquedaEnMatriz(m, numeroAleatorio, cartones);
                while (resultado!=-1) {
                    numeroAleatorio= rand()%90+1;
                    resultado=busquedaEnMatriz(m, numeroAleatorio, cartones);
                }

                    m[i][j][k]=numeroAleatorio;

            }
        }
    }

}

//-----CARGAR CARTON POR TECLADO-----

void cargarCartonPorTeclado (int m[][FILAS][COLUMNAS], int cartones) {

int resultado;
int numeroIngresado;

    for (int i=0; i<cartones; i++) {

    for (int j=0; j<FILAS; j++) {

        for (int k=0; k<COLUMNAS; k++) {

            printf ("\nIngrese numero menor a 90: \n");
            scanf ("%d", &numeroIngresado);

            resultado=busquedaEnMatriz(m, numeroIngresado, cartones); //se guarda una variable el resultado de la busqueda


            while (resultado!=-1 || numeroIngresado>90) { //mientras el resultado de la busqueda sea distinto de -1 (eso indicaria que el numero esta repetido) o mayor a 90
            //se pide que ingrese de nuevo el numero

                printf ("El numero ingresado es mayor a 90 o esta repetido, vuelve a ingresar:\n");
                scanf ("%d", &numeroIngresado); //se ingresa nuevamente el numero

                resultado=busquedaEnMatriz(m, numeroIngresado, cartones); //la variable toma el resultado de la busqueda del nuevo numero //la i es el indice del for, para chequear el carton i

                //se repite el proceso hasta que el numero resultado sea -1 (es decir, no se repita) y sea menor o igual que 90

            } //cierra el while


            m[i][j][k]=numeroIngresado;

        } //cierra el for
    }
    }

}

//-----IMPRIMIR CARTONES-----

void imprimirCarton (int m[][FILAS][COLUMNAS], int cartones) { //funcion para imprimir la matriz

    for (int i=0; i<cartones; i++) {

    for (int j=0; j<FILAS; j++) {

            printf ("\n");

            for (int k=0; k<COLUMNAS; k++) {

                printf (" - %d - ", m[i][j][k]);
            } //cierra for
        }//cierra el for

        printf ("\n");
}
}

//-----CARGA CANTIDAD DE CARTONES-----

int cuantosCartones (){

    int cartones;

    printf("\n-Ingresar cuantos cartones desea jugar (De 1 a 3): ");
    scanf ("%d", &cartones);

    while (cartones<1 || cartones>3) { //vuelve a pedir si la cantidad es menor a 0 y mayor a 3

        printf("La cantidad ingresada es incorrecta, vuelve a ingresar cantidad de cartones: ");
        scanf ("%d", &cartones);

    } //cierra el while

return cartones;
}

//-----GET-----

int getMatriz(Carton c) {

return c->matriz;

}
