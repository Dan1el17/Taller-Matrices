#include<stdio.h>

int main() {
    int filas, columnas;
    
    // Mensaje de bienvenida
    printf(" ----BIENVENIDO----\n");
    
    // Ingresar número de filas
    printf("Ingrese el numero de filas: ");
    while (scanf("%d", &filas) != 1) { // Bucle para comprobar que se ingreso un numero valido para las filas
        printf("ERROR. Por favor, ingrese el numero de filas: "); /*Si no se ingresó un número válido
        mostrar un mensaje de error y pedir otra vez*/ 
        while (getchar() != '\n'); // Descartar los caracteres adicionales en la entrada estandar
    }
    
    // Ingresar número de columnas
    printf("Ingrese el numero de columnas: ");
    while (scanf("%d", &columnas) != 1) { // Bucle para comprobar que se ingreso un numero valido para las columnas
        printf("ERROR. Por favor, ingrese el numero de columnas: "); /*Si no se ingresó un número válido
        mostrar un mensaje de error y pedir otra vez*/ 
        while (getchar() != '\n'); // Descartar los caracteres adicionales en la entrada estandar
    }
    printf("\n");

    // Instrucción para ingresar las matrices
    printf("A continuacion ingrese las matrices para realizar las siguientes operaciones\n");
    int matriz1[filas][columnas], matriz2[filas][columnas], resta[filas][columnas];    
    
    // Ingreso de la primera matriz
    printf("Ingrese la primera matriz:\n");
    for (int i = 0; i < filas; ++i) {
        for(int j = 0; j < columnas; ++j) {
            printf("Ingrese un numero (%d,%d): ", i+1, j+1);
            while (scanf("%d", &matriz1[i][j]) != 1) { // Bucle while para comprobar si es que el usuario ingreso correctamente un numero
                printf("ERROR. Por favor, ingrese un numero (%d,%d): ", i+1, j+1); /* Sumamos uno tanto para las
                filas y columnas para que al momento de presentr el mensaje nos indique la posicion del numero que va ingresar*/
                while (getchar() != '\n'); // Descartar los caracteres adicionales en la entrada estandar
            }
        }
    }
    
    printf("\n");

    // Ingreso de la segunda matriz
    printf("Ingrese la segunda matriz:\n");
     for (int i = 0; i < filas; ++i) {
        for(int j = 0; j < columnas; ++j) {
            printf("Ingrese un numero (%d,%d): ", i+1, j+1);
            while (scanf("%d", &matriz2[i][j]) != 1) { // Bucle while para comprobar si es que el usuario ingreso correctamente un numero
                printf("ERROR. Por favor, ingrese un numero (%d,%d): ", i+1, j+1); /* Sumamos uno tanto para las
                filas y columnas para que al momento de presentr el mensaje nos indique la posicion del numero que va ingresar*/
                while (getchar() != '\n'); // Descartar los caracteres adicionales en la entrada estandar
            }
        }
    }

    printf("La matriz 1 ingresada es:\n"); // Imprime un encabezado antes de mostrar la matriz
    for (int i = 0; i < filas; ++i) { // Recorre sobre cada fila de la matriz
        printf("|"); // Imprime un separador de cada fila
        for (int j = 0; j < columnas; ++j) { // Recorre sobre cada columna de la fila actual
            printf(" %d ", matriz1[i][j]); // Imprime el elemento actual de la matriz
        }
        printf("|\n"); // Imprime un separador al final de cada fila y pasa a la siguiente línea
    }
    
    printf("La matriz 2 ingresada es:\n"); // Imprime un encabezado antes de mostrar la matriz
    for (int i = 0; i < filas; ++i) { // Recorre sobre cada fila de la matriz
        printf("|"); // Imprime un separador de cada fila
        for (int j = 0; j < columnas; ++j) { // Recorre sobre cada columna de la fila actual
            printf(" %d ", matriz2[i][j]); // Imprime el elemento actual de la matriz
        }
        printf("|\n"); // Imprime un separador al final de cada fila y pasa a la siguiente línea
    }
    printf("\n");

    // Resta de matrices
    // Realiza la resta de matrices
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            resta[i][j] = matriz1[i][j] - matriz2[i][j];
        }
    }

    // Imprime la matriz resultante
    printf("La resta de las dos matrices es:\n");
    for (int i = 0; i < filas; ++i) {
        printf("| ");
        for (int j = 0; j < columnas; ++j) {
            printf("%d ", resta[i][j]);
        }
        printf("|\n");
    }    

    return 0;
}
