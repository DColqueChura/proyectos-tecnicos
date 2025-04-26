/*****************************************/
/*
 *  Proyecto Integrador: SUDOKU
 *  Comision -3- Programación I
 *  Integrantes: Mancilla Dana / Colque Daniela 
 *  Fecha de realización: noviembre 2023
 */
/*****************************************/
#include "funciones.c"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define FILAS 9
#define COLUMNAS 9
#define USER 10

/*********************************************************************************/
/*Breve descripción del juego SUDOKU

 * El juego te preguntara si queres jugar una nueva partida o si anteriormente
 habias abandonado una partida, en ese caso te preguntará si queres continuar el
 juego desde donde lo dejaste.
 * Si eliges la opción "jugar una nueva partida", tendrás un menú de niveles, en
 el cual tendrás que elegir uno de los 4 niveles de dificultad disponibles en el
 juego.
 * Luego te pedirá las coordenadas de fila y columna del tablero, y el número
 que quieres ingresar.
 *****
 * Recordar que las filas y columnas válidas son entre [0 a 9) y el número
 * solo es válido entre [1 a 9].
 *****
 * Si la jugada que acabas de realizar es válida (significa que ingresaste la
 coordenada en un lugar que estaba vacio, es decir que habia un cero[0]. Además,
 el número no se repite ni en la fila, ni en la columna o en el cuadrante que
 pertenece), el juego cargará el numero que ingresaste en el tablero.
 * Si la jugada no es válida, el juego te avisará con un mensaje de "JUGADA
 INVALIDA", y te preguntará si quieres reiniciar el juego o si quieres continuar
 la partida.
 * Si eliges "reiniciar la jugada", el tablero será el mismo que del principio
 (es decir sin ningún movimiento).
 * Si quieres salir del juego antes de completar el tablero, solo debes ingresar
 [-1] en la coordenada fila o columna. Cuando lo hagas, aparecerán las
 siguiente opciones: rendirte, salir de la partida o regresar al juego.
 * Si elijes la opcion "rendirte", el juego te mostrará el sudoku con las
 soluciones y terminará la partida.
 * Si elijes la opcion "salir", el juego guardará tu avance y la práxima vez que
 entres podrás continuarlo.
 * Si terminas el sudoku con éxito, se mostrará un mensaje de felicitaciones y
 te preguntará tu nombre de usuario, y luego aparecerán todos tus movimientos
 que realizaste. Finalmente, te mostrará el jugador que tuvo el mejor
 rendimiento en ese nivel.
 */
/*********************************************************************************/

int main() {

  FILE *registro, *movimientos, *aux_movimientos, *archivo;
  int salida = 0;
  int nivel = 1;
  int opcion;
  int movimiento;
  char usuario[USER];
  int **tablero = reserva_matriz_enteros(FILAS, COLUMNAS);

  opcion = menu();

  if (opcion == 1) {
    movimiento = 0;
    archivo = fopen("archivo.txt", "w");
    nivel = niveles();
    elige_tablero(nivel, FILAS, COLUMNAS, tablero);
  }

  else if (opcion == 2) {

    archivo = fopen("archivo.txt", "a+");

    if (elementos_del_archivos(archivo) != 0) {
      aux_movimientos = fopen("mov_aux.txt", "a+");
      fscanf(aux_movimientos, " %d \n", &movimiento);
      fclose(aux_movimientos);
      rewind(archivo);
      archivo_a_matriz(archivo, FILAS, COLUMNAS, tablero);
    } else {
      printf("No tiene nada guardado \n");
      printf("Eliga un nuevo nivel \n");
      movimiento = 0;
      archivo = fopen("archivo.txt", "w+");
      nivel = niveles();
      elige_tablero(nivel, FILAS, COLUMNAS, tablero);
    }
  }
  printf("-> Para salir de la partida presione [-1], cuando se le pida la "
         "coordenada de la FILA/COLUMNA \n");

  while (!tablero_lleno(FILAS, COLUMNAS, tablero) && salida == 0) {

    int columna = -1;
    int fila = -1;
    int numero = -1;

    imprimir_tablero(FILAS, COLUMNAS, tablero);
    printf("FILA \n");
    fila = verificar_posicion(fila);

    if (fila == -1) {
      salida = salir(nivel, FILAS, COLUMNAS, tablero);
    } else {
      printf("COLUMNA \n");
      columna = verificar_posicion(columna);

      if (columna == -1) {
        salida = salir(nivel, FILAS, COLUMNAS, tablero);
      } else {

        numero = verificar_numero(numero);

        int verificar = verificar_jugada(fila, columna, numero, tablero);

        movimiento++; // cuenta movimientos válidos e inválidos

        if (verificar) {
          tablero[fila][columna] = numero;
        } else {
          jugada_invalida(nivel, FILAS, COLUMNAS, tablero);
        }
      }
    }
  }

  int ganador = tablero_lleno(FILAS, COLUMNAS, tablero);

  if (ganador && salida != 2) {
    printf(" FELICITACIONES \n");
    printf(" Usted ha ganado \n");

    if (nivel == 1) {
      registro = fopen("registro_name1.txt", "a+");
      movimientos = fopen("movimientos1.txt", "a+");
    } else if (nivel == 2) {
      registro = fopen("registro_name2.txt", "a+");
      movimientos = fopen("movimientos2.txt", "a+");
    } else if (nivel == 3) {
      registro = fopen("registro_name3.txt", "a+");
      movimientos = fopen("movimientos3.txt", "a+");
    } else if (nivel == 4) {
      registro = fopen("registro_name4.txt", "a+");
      movimientos = fopen("movimientos4.txt", "a+");
    }

    printf("usuario : ");
    scanf("%s", usuario);
    printf("movimientos : %d\n", movimiento);

    fprintf(registro, "%s \n", usuario);
    fprintf(movimientos, "%d \n", movimiento);

    rewind(registro);
    rewind(movimientos);

    int capacidad = elementos_del_archivos(movimientos);

    rewind(movimientos);

    // retorna el arreglo con los valores de los movimientos
    int *arreglo = archivo_a_vector(movimientos,capacidad); 

    // retorna la posicion del jugador con menor cantidad de movimientos
    int posicion = menor(arreglo, capacidad); 

    printf("\n--Usuario con mejor promedio en este nivel---\n");

    char *nombre_usuario = usuario_registro(posicion, registro, USER);

    printf("User: %s \n", nombre_usuario);
    printf("Movimientos: %d", arreglo[posicion]);

    // Liberar la memoria asignada por usuario_registro
    liberar_cadena(nombre_usuario); 
    
    liberar_arreglo(arreglo);
    fclose(registro);
    fclose(movimientos);
  } else {
    
    //se guardan los movimientos en un archivo temporal hasta que gane el juego
    aux_movimientos = fopen("mov_aux.txt", "w+");
    fprintf(aux_movimientos, " %d ", movimiento);
    fclose(aux_movimientos);
  }

  fclose(archivo);
  archivo = fopen("archivo.txt", "w");

  if (salida != 2 && ganador != 1) {
    matriz_a_archivo(archivo, FILAS, COLUMNAS, tablero);
  }

  fclose(archivo);
  liberar_matriz(FILAS, tablero);

  return 0;
}
