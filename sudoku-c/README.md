# Juego de Sudoku en C

Este proyecto implementa un juego de Sudoku en lenguaje C utilizando estructuras dinámicas y manejo de archivos.

## Características

- Verificación de reglas del juego (filas, columnas y bloques).
- Carga y guardado de tablero desde archivo.
- Documentación de funciones en formato estandarizado.

## Archivos

- `main.c`: lógica principal
- `funciones.c`: funciones auxiliares
- `funciones.h`: prototipos y estructuras
- `<nivel>.txt`: contiene el tablero de juego de ese nivel
- `full_<nivel>.h`: contiene el tablero con la respuesta de ese nivel

## Compilación

gcc -o sudoku main.c funciones.c

