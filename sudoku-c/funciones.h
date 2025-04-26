#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int menu();
int niveles();

int verificar_posicion(int posicion);
int verificar_numero(int num);

int *reserva_arreglo_enteros(int tamanio);
int **reserva_matriz_enteros(int filas, int columnas);

void liberar_arreglo(int *arreglo);
void liberar_matriz(int filas, int **tablero);
void liberar_cadena(char *cadena);

void archivo_a_matriz(FILE *archivo, int filas, int columnas, int **tablero);

void llenar_tablero(char *tabla_nivel, int fila, int columna, int **tablero);
void elige_tablero(int nivel, int fila, int columna, int **tablero);
void tablero_completo(int nivel, int fila, int columna, int **tablero);

int existe_lugar(int fila, int columna, int **tablero);
int num_repetido_fila(int fila, int columna, int **tablero, int numero);
int num_repetido_columna(int fila, int columna, int **tablero, int numero);
int cual_cuadrante(int posicion);
int verificar_cuadrante(int fila, int columna, int **tablero, int numero);

void imprimir_tablero(int fila, int columna, int **tablero);
int tablero_lleno(int fila, int columna, int **tablero);

void matriz_a_archivo(FILE *archivo, int FILAS, int COLUMNAS, int **tablero);

int *archivo_a_vector(FILE *archivo, int capacidad);

int menor(int *arreglo, int capacidad);

int elementos_del_archivos(FILE *archivo);
int capacidad_elem_archivos(FILE *archivo);

char *usuario_registro(int posicion, FILE *archivo, int capacidad);

int verificar_jugada(int fila, int columna, int numero, int **tablero);
void jugada_invalida(int nivel, int FILAS, int COLUMNAS, int **tablero);

int salir(int nivel, int FILAS, int COLUMNAS, int **tablero);
