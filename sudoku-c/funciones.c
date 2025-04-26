#include "funciones.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 *  La función muestra al usuario las 2 opciones iniciales de juego.
 *  @return la opcion de elección.
 */
int menu() {
  int opcion;

  printf("BIENVENIDO A SUDOKU \n\n\n");
  printf(" 1: NUEVO JUEGO \n");
  printf(" 2: CONTINUAR JUGANDO \n -> ");
  scanf("%d", &opcion);

  return opcion;
}

/**
 *  La función muestra al usuario los niveles de juego.
 *  @return el nivel elegido.
 */
int niveles() {
  int nivel;

  printf(" 1: NIVEL FACIL\n");
  printf(" 2: NIVEL INTERMEDIO\n");
  printf(" 3: NIVEL DIFICIL\n");
  printf(" 4: NIVEL IMPOSIBLE\n -> ");
  scanf("%d", &nivel);

  return nivel;
}

/**
 * La funcion verifica que la fila o columna del tablero se encuentre dentro del
 * intervalo válido entre [0,8].
 * @param posicion es un entero positivo.
 * @pre fila o columna del tablero.
 * @return la posicion si es válida.
 */
int verificar_posicion(int posicion) {
  while (posicion < 0 || posicion > 8) {
    printf("Ingrese la coordenada: ");
    scanf("%d", &posicion);
    if (posicion == -1) {
      break;
    }
  }
  
  return posicion;
}

/**
 * La funcion verifica que el numero se encuentre dentro del
 * intervalo válido entre [1,9].
 * @param num es un entero positivo.
 * @return num si es válida.
 */
int verificar_numero(int num) {
  while (num < 1 || num > 9) {
    printf("Ingrese el numero : ");
    scanf("%d", &num);
  }

  return num;
}

/**
 *  La función reserva memoria dinamicamente para un arreglo de enteros.
 *  @param tamanio es un numero entero positivo, sin incluir el 0.
 *  @return si se reserva la memoria, devuelve el puntero a un arreglo de
 *  enteros. Retorna 0(=NULL) en caso contrario.
 */
int *reserva_arreglo_enteros(int tamanio) {

  int *arreglo = (int *)malloc(sizeof(int) * tamanio); /*con cast*/

  /* Comprueba que la memoria se asignó correctamente, en caso contrario se
   * gestiona el error. */
  if (arreglo == NULL) {
    printf("ERROR: No hay suficiente memoria");
    return NULL;
  } else
      return arreglo;
}

/**
 *  La función reserva memoria dinamicamente para una matriz de enteros.
 *  @param filas y @param columnas son numeros enteros positivos, entre 0 y 9
 *  (sin incluir los extremos).
 *  @return si se reserva la memoria, devuelve el puntero a un arreglo de
 *  enteros. Retorna 0(=NULL) en caso contrario.
 */
int **reserva_matriz_enteros(int filas, int columnas) {

  int **matriz;
  matriz = (int **)malloc(filas * sizeof(int));

  if (matriz == NULL) {
    printf(" No se ha podido reservar espacio de memoria. \n");
    return NULL;
  }

  for (int i = 0; i < filas; i++) {
    matriz[i] = (int *)malloc(columnas * sizeof(int));
    if (matriz == NULL) {
      printf(" No se ha podido reservar espacio de memoria. \n");
      return NULL;
    }
  }

  return matriz;
}

/**
 * La función libera la memoria reservada dinamicamente de un arreglo.
 */
void liberar_arreglo(int *arreglo) { free(arreglo); }

/**
 * La función libera la memoria reservada dinamicamente de una matriz.
 */
void liberar_matriz(int filas, int **tablero) {
  for (int i = 0; i < filas; i++) {
    free(tablero[i]);
  }
  free(tablero);
}

/**
 * La funcion libera la memoria reservada dinámicamente de un puntero tipo char.
 * @param cadena es un puntero que será liberado.
 */
void liberar_cadena(char *cadena) { free(cadena); }

/**
 *  La función copia los valores de un archivo y lo guarda en una matríz
 *  tablero.
 *  @param archivo es un documento tipo '.txt'
 *  @param filas y @param columnas son numeros enteros positivos, entre 0 y 9
 *  (sin incluir los extremos).
 *  @param tablero es una matriz dinámica de enteros.
 *    @pos debe tener valores.
 */
void archivo_a_matriz(FILE *archivo, int filas, int columnas, int **tablero) {
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      fscanf(archivo, "%d", &tablero[i][j]);
    }
  }
}

/**
 *  La función abre un documento.txt y copia sus valores en una matriz tablero
 *  de enteros.
 *  @param tabla_nivel es un vector de carácteres con el nombre del documento.
 *        @pre cada documento se encuentra lleno con valores enteros.
 *  @param filas y @param columnas son numeros enteros positivos, entre 0 y 9
 *  (sin incluir los extremos).
 *  @param tablero es una matriz dinámica de enteros.
 *        @pre debe tener valores.
 */
void llenar_tablero(char *tabla_nivel, int fila, int columna, int **tablero) {

  FILE *archivo;
  archivo = fopen(tabla_nivel, "r");

  for (int f = 0; f < fila; f++) {
    for (int c = 0; c < columna; c++)
      fscanf(archivo, "%d", &tablero[f][c]);
  }

  fclose(archivo);
}

/**
 * La funcion copia en una matriz tablero los elementos de un archivo.
 * Funcionamiento: en cada nivel del juego existe un archivo con elementos
 * enteros positivos distintos entre [1,9]. Por eso antes de copiar los
 * elementos del archivo a la matriz, se pregunta en que nivel esta.
 * @param tablero es una matriz donde se copiaran los elementos del archivo,
 * elegido por nivel.
 *       @pos contiene numeros enteros.
 * @param nivel es el nivel de juego.
 *       @pre es un numero entero.
 * @param filas es la cantidad de filas que tiene el tablero.
 *       @pre numero entero positivo, sin incluir el 0.
 * @param columnas es la cantidad de columnas que tiene el tablero.
 *       @pre numero entero positivo, sin incluir el 0.
 */
void elige_tablero(int nivel, int fila, int columna, int **tablero) {
  if (nivel == 1) {
    llenar_tablero("beginner.txt", fila, columna, tablero);
  } else if (nivel == 2) {
    llenar_tablero("intermedia.txt", fila, columna, tablero);
  } else if (nivel == 3) {
    llenar_tablero("difficult.txt", fila, columna, tablero);
  } else {
    llenar_tablero("imposible.txt", fila, columna, tablero);
  }
}

/**
 * La funcion carga en el tablero la solucion del sudoku.
 * @param tablero es una matriz donde se guardaran los valores.
 *         @pos contiene numeros enteros.
 * @param filas es la cantidad de filas que tiene el tablero.
 *         @pre: numero entero positivo.
 * @param columnas es la cantidad de columnas que tiene el tablero.
 *         @pre: numero entero positivo.
 * @param nivel determinara que archivo se copiara en el tablero, ya que en
 * cada nivel hay distintos sudokus.
 *         @pre: numero entero positivo en el intervalo de [1,4]
 */
void tablero_completo(int nivel, int fila, int columna, int **tablero) {
  if (nivel == 1) {
    llenar_tablero("full_beginner.txt", fila, columna, tablero);
  } else if (nivel == 2) {
    llenar_tablero("full_intermedia.txt", fila, columna, tablero);
  } else if (nivel == 3) {
    llenar_tablero("full_difficult.txt", fila, columna, tablero);
  } else {
    llenar_tablero("full_imposible.txt", fila, columna, tablero);
  }
}

/**
 * La funcion verifica que haya lugar en el tablero, es decir que no existe un
 * numero antes en esa posicion (dado por fila y columna) en el tablero.
 * @param fila y @param columna son enteros mayores o iguales a 0 y menores a 9.
 * @return 1 si hay lugar. 0 si no hay lugar, significa que ya hay un numero
 * cargado en ese lugar.
 */
int existe_lugar(int fila, int columna, int **tablero) {

  int bandera = 0;

  if (tablero[fila][columna] == 0) {
    bandera = 1;
  }
  return bandera;
}

/**
 * La funcion verifica si se repite el numero ingresado en la fila del tablero.
 * @param fila y @param columna son enteros mayores o iguales a 0 y menores a 9.
 * @return 1 si no se repite, 0 si se repite.
 */
int num_repetido_fila(int fila, int columna, int **tablero, int numero) {
  int retorno = 1;

  for (int i = 0; i < 9; i++) {
    if (tablero[fila][i] == numero) {
      retorno = 0;
    }
  }

  return retorno;
}

/**
  La funcion verifica si se repite el numero en la columna del tablero.
  @param fila y @param columna son enteros mayores o iguales a 0 y menores a 9.
  @return 1 si no se repite, 0 si se repite.
*/
int num_repetido_columna(int fila, int columna, int **tablero, int numero) {
  int retorno = 1;

  for (int i = 0; i < 9; i++) {
    if (tablero[i][columna] == numero) {
      retorno = 0;
    }
  }

  return retorno;
}

/**
 * La funcion encuentra en que cuadrante 3x3 esta la posicion ingresada.
 * @param posicion puede ser la coordenada de fila o columna del tablero.
 *       @pre posicion es un valor valido, se encuentra en el intervalo de
 *       [0,8].
 * @return el inicio del cuadrante correspondiente, puede ser una fila o
 * columna.
 */
int cual_cuadrante(int posicion) {

  int retorno;

  if (posicion < 3) {
    retorno = 0;
  } else if (posicion < 6) {
    retorno = 3;
  } else {
    retorno = 6;
  }

  return retorno;
}

/**
* La función verifica si en el cuadrante 3x3 se repite el número ingresado.
* @param fila y @param columna son enteros mayores o iguales a 0 y menores a 9.
* @param numero es el valor que se verificará si esta repetido en el cuadrante
  de 3x3.
* @return retorna un 0: si el numero esta repetido en el cuadrante.
          retorna un 1: si el numero no esta repetido en el cuadrante.
*/
int verificar_cuadrante(int fila, int columna, int **tablero, int numero) {
  int fila_n = cual_cuadrante(fila);
  int colum_n = cual_cuadrante(columna);
  int retorno = 1;

  for (int i = fila_n; i < fila_n + 3; i++) {
    for (int j = colum_n; j < colum_n + 3; j++) {
      if (tablero[i][j] == numero)
        retorno = 0;
    }
  }
  
  return retorno;
}

/**
 * La funcion imprime el tablero en pantalla.
 * @param tablero es una matriz de enteros.
 * @param filas es la cantidad de filas que tiene el tablero.
 *         @pre: numero entero positivo.
 * @param columnas es la cantidad de columnas que tiene el tablero.
 *         @pre: numero entero positivo.
 */
void imprimir_tablero(int fila, int columna, int **tablero) {

  for (int i = 0; i < fila; i++) {

    printf("\n");

    if (i % 3 == 0) {
      printf("------------------------------- \n");
    }

    for (int j = 0; j < columna; j++) {
      if (j % 3 == 0) {
        printf("|");
      }
      printf(" %d ", tablero[i][j]);
    }
    printf("|");
  }

  printf("\n------------------------------- \n");
  printf("\n\n");
}

/**
 * La funcion verifica que el tablero está lleno.
 * Funcionamiento: para eso se verifica que la matriz no contenga 0. Si la
 * matriz contiene un 0, significa que todavia no esta lleno/cargado de valores.
 *  @param tablero es el cual se verifique que este lleno de valores.
 *  PRE: contiene numeros enteros.
 *  @param filas es la cantidad de filas que tiene el tablero.
 *         PRE: numero entero positivo.
 *  @param columnas es la cantidad de columnas que tiene el tablero.
 *         PRE: numero entero positivo.
 *  @returns retorna un 0: tablero aun no esta lleno.
             retorna un 1: tablero esta lleno.
 */
int tablero_lleno(int fila, int columna, int **tablero) {
  int bandera = 1;

  for (int i = 0; i < fila; i++) {
    for (int j = 0; j < columna; j++) {
      if (tablero[i][j] == 0) {
        bandera = 0;
      }
    }
  }

  return bandera;
}

/**
 * La funcion carga los valores de una matriz tablero a un archivo.
 * @param tablero es una matriz que contiene numeros enteros, que serán cargados
 * al archivo.
 * @param filas es la cantidad de filas que tiene el tablero.
 *         @pre: numero entero positivo.
 * @param columnas es la cantidad de columnas que tiene el tablero.
 *         @pre: numero entero positivo.
 * @param archivo debe estar creado.
           @pre: se debe encontrar abierto, vacio y en modo escritura "w".
 *         @pos: el archivo contendrá los valores de la matriz.
 */
void matriz_a_archivo(FILE *archivo, int FILAS, int COLUMNAS, int **tablero) {
  for (int i = 0; i < FILAS; i++) {
    for (int j = 0; j < COLUMNAS; j++) {
      fprintf(archivo, "%d  \n", tablero[i][j]);
    }
  }
}

/**
 * La funcion carga los valores de un archivo en un arreglo.
 * Funcionamiento: Se crea un arreglo y se le asigna memoria dinamica. Luego, se
 * le cargan los valores que contiene archivo.
 * @param archivo contiene una secuencia de numeros.
 *        @pre: El archivo debe estar abierto y en modo lectura "r".
 * @param capacidad es la cantidad de elementos que contiene archivo.
 * @returns el arreglo cargado con los valores de archivo.
 */
int *archivo_a_vector(FILE *archivo, int capacidad) {
  int i = 0;
  int aux; // variable auxiliar donde se guarda los valores del archivo

  // se le asignara memoria dinamica al arreglo.
  int *arreglo = reserva_arreglo_enteros(capacidad);

  while (i < capacidad) {
    fscanf(archivo, "%d", &aux);
    arreglo[i] = aux;
    i++;
  }

  return arreglo;
}

/**
 * La funcion encuentra el menor numero en un arreglo.
 * @param arreglo contiene numeros enteros positivos, contando el 0.
 * @param capacidad es la capacidad del arreglo.
 * @returns la posicion del menor numero del arreglo.
 */
int menor(int *arreglo, int capacidad) {
  int menor = arreglo[0];
  int posicion = 0;

  for (int i = 0; i < capacidad; i++) {
    
    // se busca la última ocurrencia del valor más pequeño
    if (arreglo[i] <= menor) { 
      posicion = i;
      menor = arreglo[i];
    }
  }

  return posicion;
}

/**
 * La funcion cuenta los elementos/datos que tiene el archivo.
 * @param archivo es un documento ".txt" que contiene números enteros positivos,
 * incluyendo el 0.
 *      @pre: el archivo debe estar abierto en modo lectura "r".
 * @returns la cantidad de datos que tiene el archivo.
            Si retorna un 0 : el archivo se encuentra vacio.
 */
int elementos_del_archivos(FILE *archivo) {
  int i = 0; // contador de elementos.
  int aux;   // variable auxiliar, que guarda los elementos del archivo.

  do {
    if (fscanf(archivo, "%d", &aux) == 1) {
      i++;
    }
    // el bucle se termina cuando se llega al final del archivo.
  } while (!feof(archivo));

  return i;
}

/**
 * La funcion busca la cadena en el archivo, que corresponda a la posicion que
 * se indica.
 * Funcionamiento : primero se reserva memoria dinamica para un puntero de tipo
 * char, que almacenará las cadenas que se vayan leyendo del archivo. Cuando
 * se encuentre la cadena en la posición dada, el puntero sera retornado con la
 * direccion de esa cadena dinámica.
 * @param posicion es la posición donde se encuentra la cadena en el archivo.
 *      @pre: numero entero positivo.
 * @param archivo contiene cadenas de nombres de usuarios.
 *      @pre: el archivo debe existir, estar abierto y en modo lectura "r".
 * @param capacidad es la capacidad de la cadena.
 *      @pre: capacidad es un numero entero positivo.
 * @return un puntero de tipo char, que contiene a la cadena que buscamos.
 */
char *usuario_registro(int posicion, FILE *archivo, int capacidad) {

  int contador = 0; // Contador para llevar el seguimiento de las palabras
  int bandera = 1;

  // se asigna memoria dinamica a un arreglo de carácteres.
  char *tempUsuario = (char *)malloc(capacidad * sizeof(char));

  while (bandera == 1) {
    fscanf(archivo, "%s", tempUsuario);
    if (contador == posicion) {
      bandera = 0;
    }
    contador++;
  }

  return tempUsuario;
}

/**
 * La funcion verifica la jugada del usuario.
 * Funcionamiento: Para verificar se llama a funciones anteriores que retornaran
 * un 1, si: hay lugar, si no se repite en la fila, columna y en el cuadrante.
 * @param fila y @param columna son numeros positivos, son posiciones de la
 * matriz tablero.
 * @param numero es un numero positivos entre.
 * @param tablero es una matriz de enteros.
 * @returns retorna un 1 : si la jugada es válida.
            retorna un 0 : si la jugada no es válida.
 */
int verificar_jugada(int fila, int columna, int numero, int **tablero) {

  int lugar = existe_lugar(fila, columna, tablero);
  int rep_fila = num_repetido_fila(fila, columna, tablero, numero);
  int rep_columna = num_repetido_columna(fila, columna, tablero, numero);
  int rep_cuadrante = verificar_cuadrante(fila, columna, tablero, numero);

  return (lugar && rep_columna && rep_fila && rep_cuadrante);
}

/**
 * La funcion le pregunta al usuario: si quiere reiniciar el juego o continuar
 * la partida.
 * Funcionamiento: Si el usuario elije que quiere reiniciar el juego, el tablero
 * no conserva los movimientos hechos, se inicia con un tablero nuevo del mismo
 * nivel. Si el usuario elije continuar la partida, la funcion no realiza
 * ninguna modificacion.
 * @param nivel es el nivel de dificulad del juego.
 *      @pre es un numero entero, sin incluir el 0.
 * @param filas , @param columnas son las dimensiones de la matriz tablero.
 *      @pre son numeros enteros positivos.
 * @param tablero es una matriz de enteros.
 */
void jugada_invalida(int nivel, int FILAS, int COLUMNAS, int **tablero) {
  int reiniciar;

  printf("JUGADA INVALIDA \n");
  printf(" 1 : Quiere reiniciar el juego ? \n");
  printf(" 2 : continuar la partida \n -> ");
  scanf("%d", &reiniciar);

  if (reiniciar == 1) {
    elige_tablero(nivel, FILAS, COLUMNAS, tablero);
  }
}

/**
 * La funcion le pregunta al usuario: si quiere salir, rendirse o regresar al
 * juego.
 * Funcionamiento: Si el usuario quiere rendirse, la funcion mostrará la
 * solucion del sudoku.
 * @param nivel  enteros positivos
 * @param filas y @param columnas son enteros positivos, son el tamaño de la
 * matriz tablero.
 * @param tablero es una matriz de enteros.
 *      @pre debe tener elementos.
 * @returns retornara un 1 : si quiere salir.
            retornara un 2 : si quiere rendirse.
            retornara un 0 : si quiere regresar a la partida.
 */
int salir(int nivel, int FILAS, int COLUMNAS, int **tablero) {
  int salida;

  printf(" 1 : Quiere salir ? \n");
  printf(" 2 : Quiere rendirse ? (se le mostrara la solucion) \n");
  printf(" 0 : regresar \n -> ");
  scanf("%d", &salida);

  if (salida == 2) {
    tablero_completo(nivel, FILAS, COLUMNAS, tablero);
    imprimir_tablero(FILAS, COLUMNAS, tablero);
  }

  return salida;
}
