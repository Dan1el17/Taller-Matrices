#include<stdio.h>

int main() {
    int filas1, columnas1;
    int filas2, columnas2;
    
    // Mensaje de bienvenida
    printf(" ----BIENVENIDO----\n");
    
    // Ingresar número de filas y columnas para la primera matriz
    printf("Ingrese el numero de filas de la primera matriz: ");
    while (scanf("%d", &filas1) != 1) {
        printf("ERROR. Por favor, ingrese un numero valido para las filas: ");
        while (getchar() != '\n'); // Descartar los caracteres adicionales en la entrada estándar
    }
    
    printf("Ingrese el numero de columnas de la primera matriz: ");
    while (scanf("%d", &columnas1) != 1) {
        printf("ERROR. Por favor, ingrese un numero valido para las columnas: ");
        while (getchar() != '\n'); // Descartar los caracteres adicionales en la entrada estándar
    }
    printf("\n");

    // Ingresar número de filas y columnas para la segunda matriz
    printf("Ingrese el numero de filas de la segunda matriz: ");
    while (scanf("%d", &filas2) != 1) {
        printf("ERROR. Por favor, ingrese un numero valido para las filas: ");
        while (getchar() != '\n'); // Descartar los caracteres adicionales en la entrada estándar
    }
    
    printf("Ingrese el numero de columnas de la segunda matriz: ");
    while (scanf("%d", &columnas2) != 1) {
        printf("ERROR. Por favor, ingrese un numero valido para las columnas: ");
        while (getchar() != '\n'); // Descartar los caracteres adicionales en la entrada estándar
    }
    printf("\n");

    // Verificar que las matrices sean compatibles para la multiplicación
    if (columnas1 != filas2) {
        printf("ERROR: No se pueden multiplicar las matrices. El numero de columnas de la primera matriz no coincide con el numero de filas de la segunda matriz.\n");
        return 1; // Terminar el programa
    }

    // Instrucción para ingresar las matrices
    printf("A continuacion ingrese las matrices para realizar las siguientes operaciones\n");
    int matriz1[filas1][columnas1], matriz2[filas2][columnas2], producto[filas1][columnas2];    
    
    // Ingreso de la primera matriz
    printf("Ingrese la primera matriz:\n");
    for (int i = 0; i < filas1; ++i) {
        for (int j = 0; j < columnas1; ++j) {
            printf("Ingrese un numero para la primera matriz (%d,%d): ", i+1, j+1);
            while (scanf("%d", &matriz1[i][j]) != 1) {
                printf("ERROR. Por favor, ingrese un numero valido para la primera matriz (%d,%d): ", i+1, j+1);
                while (getchar() != '\n'); // Descartar los caracteres adicionales en la entrada estándar
            }
        }
    }
    
    printf("\n");

    // Ingreso de la segunda matriz
    printf("Ingrese la segunda matriz:\n");
    for (int i = 0; i < filas2; ++i) {
        for (int j = 0; j < columnas2; ++j) {
            printf("Ingrese un numero para la segunda matriz (%d,%d): ", i+1, j+1);
            while (scanf("%d", &matriz2[i][j]) != 1) {
                printf("ERROR. Por favor, ingrese un numero valido para la segunda matriz (%d,%d): ", i+1, j+1);
                while (getchar() != '\n'); // Descartar los caracteres adicionales en la entrada estándar
            }
        }
    }
    printf("\n");
    printf("La matriz 1 ingresada es:\n"); // Imprime un encabezado antes de mostrar la matriz
    for (int i = 0; i < filas1; ++i) { // Recorre sobre cada fila de la matriz
        printf("|"); // Imprime un separador de cada fila
        for (int j = 0; j < columnas1; ++j) { // Recorre sobre cada columna de la fila actual
            printf(" %d ", matriz1[i][j]); // Imprime el elemento actual de la matriz
        }
        printf("|\n"); // Imprime un separador al final de cada fila y pasa a la siguiente línea
    }
    
    printf("La matriz 2 ingresada es:\n"); // Imprime un encabezado antes de mostrar la matriz
    for (int i = 0; i < filas2; ++i) { // Recorre sobre cada fila de la matriz
        printf("|"); // Imprime un separador de cada fila
        for (int j = 0; j < columnas2; ++j) { // Recorre sobre cada columna de la fila actual
            printf(" %d ", matriz2[i][j]); // Imprime el elemento actual de la matriz
        }
        printf("|\n"); // Imprime un separador al final de cada fila y pasa a la siguiente línea
    }
    printf("\n");


    // Multiplicación de matrices
    printf("Multiplicacion de matrices:\n");
    for (int i = 0; i < filas1; ++i) {
        for (int j = 0; j < columnas2; ++j) {
            producto[i][j] = 0;
            // Multiplicar filas de la primera matriz por columnas de la segunda matriz
            for (int k = 0; k < columnas1; ++k) {
                producto[i][j] += matriz1[i][k] * matriz2[k][j];
                // Imprimir cada multiplicación parcial
                printf("%d * %d = %d\n", matriz1[i][k], matriz2[k][j], matriz1[i][k] * matriz2[k][j]);
            }
            // Imprimir la suma parcial en la posición [i][j] del producto final
            printf("La suma es [%d][%d]: %d\n", i+1, j+1, producto[i][j]);
        }
    }

    // Imprimir la matriz producto
    printf("\nEl resultado de la multiplicacion de las dos matrices es:\n");
    for (int i = 0; i < filas1; ++i) {
        printf("| ");
        for (int j = 0; j < columnas2; ++j) {
            printf("%d ", producto[i][j]);
        }
        printf("|\n");
    }        
    
    return 0;
}
