#ifndef BOLILLAS_H_INCLUDED
#define BOLILLAS_H_INCLUDED
#define COLUMNAS 5
#define FILAS 3
#define MAX_CARTONES 3

//PRE: UN VECTOR DE ENTEROS, UN ENTERO DE 1 A 3, Y UN NUMERO PARA BUSCAR EN EL VECTOR
//POST: DEVUELVE -1 SI ENCUENTRA EL NUMERO, Y UN NUMERO !=-1 SI NO LO ENCUENTRA
int busquedaSecuencialVector(int v[], int tam, int buscar);

//PRE: UN VECTOR DE ENTEROS Y UN ENTERO DE 1 A 3
//POST: CARGA EL VECTOR CON NUMEROS ALEATORIOS SIN REPETIR DE 1 A 90
void cargarVectorConAleatoriosSinRepetir(int v[], int tam);

//PRE: UN VECTOR DE ENTEROS, UN ENTERO DE 1 A 3
//POST: IMPRIME EL VECTOR
void mostrarVector(int v[], int tam);

#endif // BOLILLAS_H_INCLUDED
