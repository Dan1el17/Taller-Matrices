#include <stdio.h>

int main() {
    int filas, columnas; // Definimos las variables filas columnas como numeros enteros
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
    
    int matriz[filas][columnas]; // DeclaraMOS la matriz con tamaño determinado por las variables filas y columnas que va a elegir el usuario
    printf("A continuacion ingrese los elementos de su matriz:\n");

    // Ingresar elementos de la matriz
    for (int i = 0; i < filas; ++i) {
        for(int j = 0; j < columnas; ++j) {
            printf("Ingrese un numero (%d,%d): ", i+1, j+1);
            while (scanf("%d", &matriz[i][j]) != 1) { // Bucle while para comprobar si es que el usuario ingreso correctamente un numero
                printf("ERROR. Por favor, ingrese un numero (%d,%d): ", i+1, j+1); /* Sumamos uno tanto para las
                filas y columnas para que al momento de presentr el mensaje nos indique la posicion del numero que va ingresar*/
                while (getchar() != '\n'); // Descartar los caracteres adicionales en la entrada estandar
            }
        }
    }
    printf("\n");

    printf("La matriz ingresada es:\n"); // Imprime un encabezado antes de mostrar la matriz
    for (int i = 0; i < filas; ++i) { // Recorre sobre cada fila de la matriz
        printf("|"); // Imprime un separador de cada fila
        for (int j = 0; j < columnas; ++j) { // Recorre sobre cada columna de la fila actual
            printf(" %d ", matriz[i][j]); // Imprime el elemento actual de la matriz
        }
        printf("|\n"); // Imprime un separador al final de cada fila y pasa a la siguiente línea
    }
    printf("\n");

    // Imprime un mensaje indicando que se mostrará la matriz transpuesta
    printf("\nLa matriz transpuesta es:\n");
    // Recorre sobre las columnas de la matriz original
    for (int j = 0; j < columnas; ++j) {
        // Imprime el símbolo de inicio de fila
        printf("|");
        // Recorre sobre las filas de la matriz original
        for (int i = 0; i < filas; ++i) {
        // Imprime el elemento correspondiente de la matriz transpuesta
        printf(" %d ", matriz[i][j]);
        }
        // Imprime el símbolo de fin de fila y pasa a la siguiente línea
        printf("|\n");
    }
    printf("\n");

    return 0;

}