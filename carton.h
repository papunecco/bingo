#ifndef CARTON_H_INCLUDED
#define CARTON_H_INCLUDED
#define COLUMNAS 5
#define FILAS 3
#define MAX_CARTONES 3

struct Carton;

typedef struct CartonE * Carton;

//----------CARGA----------

//PRE: NINGUNO
//POST: DEVUELVE UNA ESTRUCTURA CARTON
Carton iniciarCarton ();

//----------DESTRUCTOR----------

//PRE: NINGUNO
//POST: LIBERA DE LA MEMORIA UNA ESTRUCTURA CARTON
Carton destruirCarton (Carton c);

//----------OTROS----------

//PRE: UNA MATRIZ DE ENTEROS DE TRES DIMENSIONES, UN ENTERO A BUSCAR, Y UN ENTERO DE 1 A 3
//POST: DEVUELVE -1 SI NO ENCUENTRA EL NUMERO BUSCADO, Y UN NUMERO!=-1 SI NO LO ENCUENTRA
int busquedaEnMatriz(int m[][FILAS][COLUMNAS], int buscar, int cartones);

//PRE: UNA MATRIZ DE ENTEROS DE TRES DIMENSIONES, Y UN ENTERO DE 1 A 3
//POST: CARGA LA MATRIZ CON NUMEROS ALEATORIOS SIN REPETIR
void cargarCartonAleatorio (int m[][FILAS][COLUMNAS], int cartones);

//PRE: UNA MATRIZ DE ENTEROS DE TRES DIMENSIONES, Y UN ENTERO DE 1 A 3
//POST: CARGA LA MATRIZ CON NUMEROS INGRESADOR POR TECLADO
void cargarCartonPorTeclado (int m[][FILAS][COLUMNAS], int cartones);

//PRE: NINGUNO
//POST: DEVUELVE UN ENTERO DE 1 A 3
int cuantosCartones();

//----------IMPRIMIR----------

//PRE: UNA MATRIZ DE ENTEROS DE TRES DIMENSIONES, Y UN ENTERO DE 1 A 3
//POST: IMPRIME LA MATRIZ
void imprimirCarton (int m[][FILAS][COLUMNAS], int cartones);

//----------GETS----------

//PRE: QUE LA MATRIZ ESTE CARGADA
//POST: DEVUELVE UNA MATRIZ DE ENTEROS
int getMatriz(Carton c);

#endif // CARTON_H_INCLUDED
