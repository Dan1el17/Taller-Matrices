#include <stdio.h>
#include <stdbool.h> // Incluimos stdbool.h para poder usar el tipo de dato bool

// Prototipo de la función para comprobar si la matriz es simétrica
bool esSimetrica(int matriz[][100], int filas, int columnas);

int main() {
    int filas, columnas; // Definimos las variables filas columnas como números enteros
    printf(" ----BIENVENIDO----\n");
    
    // Ingresar número de filas
    printf("Ingrese el numero de filas: ");
    while (scanf("%d", &filas) != 1) { // Bucle para comprobar que se ingresó un número válido para las filas
        printf("ERROR. Por favor, ingrese el numero de filas: ");
        while (getchar() != '\n'); // Descartar los caracteres adicionales en la entrada estándar
    }

    // Ingresar número de columnas
    printf("Ingrese el numero de columnas: ");
    while (scanf("%d", &columnas) != 1) { // Bucle para comprobar que se ingresó un número válido para las columnas
        printf("ERROR. Por favor, ingrese el numero de columnas: ");
        while (getchar() != '\n'); // Descartar los caracteres adicionales en la entrada estándar
    }

    printf("\n");
    
    int matriz[filas][columnas]; // Declaramos la matriz con tamaño determinado por las variables filas y columnas
    printf("A continuacion ingrese los elementos de su matriz:\n");

    // Ingresar elementos de la matriz
    for (int i = 0; i < filas; ++i) {
        for(int j = 0; j < columnas; ++j) {
            printf("Ingrese un numero (%d,%d): ", i+1, j+1);
            while (scanf("%d", &matriz[i][j]) != 1) { // Bucle para comprobar si se ingresó correctamente un número
                printf("ERROR. Por favor, ingrese un numero (%d,%d): ", i+1, j+1);
                while (getchar() != '\n'); // Descartar los caracteres adicionales en la entrada estándar
            }
        }
    }
    printf("\n");

    printf("La matriz ingresada es:\n");
    for (int i = 0; i < filas; ++i) {
        printf("|");
        for (int j = 0; j < columnas; ++j) {
            printf(" %d ", matriz[i][j]);
        }
        printf("|\n");
    }
    printf("\n");

    // Comprobar si la matriz es simétrica
    if (esSimetrica(matriz, filas, columnas)) {
        printf("La matriz es simetrica.\n");
    } else {
        printf("La matriz no es simetrica.\n");
    }

    printf("\n");

    // Imprimir la matriz transpuesta
    printf("La matriz transpuesta es:\n");
    for (int j = 0; j < columnas; ++j) {
        printf("|");
        for (int i = 0; i < filas; ++i) {
            printf(" %d ", matriz[i][j]);
        }
        printf("|\n");
    }
    printf("\n");

    return 0;
}

// Definición de la función para comprobar si la matriz es simétrica
bool esSimetrica(int matriz[][100], int filas, int columnas) {
    // Una matriz es simétrica si es cuadrada y es igual a su matriz transpuesta
    if (filas != columnas) {
        return false; // No es cuadrada, por lo tanto no es simétrica
    }

    // Comparamos la matriz original con su transpuesta
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < i; ++j) { // Solo necesitamos verificar la mitad superior de la matriz
            if (matriz[i][j] != matriz[j][i]) {
                return false; // No son iguales, por lo tanto no es simétrica
            }
        }
    }

    // Si pasó todas las verificaciones, entonces es simétrica
    return true;
}
