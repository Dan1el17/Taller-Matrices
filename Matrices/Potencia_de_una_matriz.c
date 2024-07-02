#include<stdio.h>

// Función para multiplicar dos matrices y almacenar el resultado en 'producto'
void multiplicar_matrices(int matriz1[][100], int filas1, int columnas1, int matriz2[][100], int filas2, int columnas2, int producto[][100]) {
    // Multiplicación de matrices
    for (int i = 0; i < filas1; ++i) { // Itera sobre las filas de la primera matriz
        for (int j = 0; j < columnas2; ++j) { // Itera sobre las columnas de la segunda matriz
            producto[i][j] = 0; // Inicializa el valor en producto[i][j]
            // Multiplica las filas de la primera matriz por las columnas de la segunda matriz
            for (int k = 0; k < columnas1; ++k) {
                producto[i][j] += matriz1[i][k] * matriz2[k][j]; // Calcula la multiplicación parcial y suma al producto
                // Imprime cada multiplicación parcial
                printf("%d * %d = %d\n", matriz1[i][k], matriz2[k][j], matriz1[i][k] * matriz2[k][j]);
            }
            // Imprime la suma parcial en la posición [i][j] del producto final
            printf("La suma es [%d][%d]: %d\n", i+1, j+1, producto[i][j]);
        }
    }
}

// Función para copiar el contenido de una matriz 'origen' a una matriz 'destino'
void copiar_matriz(int origen[][100], int destino[][100], int filas, int columnas) {
    // Copia el contenido de matriz origen a matriz destino
    for (int i = 0; i < filas; ++i) { // Itera sobre las filas
        for (int j = 0; j < columnas; ++j) { // Itera sobre las columnas
            destino[i][j] = origen[i][j]; // Copia cada elemento de origen a destino
        }
    }
}

// Función para imprimir una matriz
void imprimir_matriz(int matriz[][100], int filas, int columnas, const char* mensaje) {
    printf("%s:\n", mensaje); // Imprime el mensaje de encabezado
    for (int i = 0; i < filas; ++i) { // Itera sobre las filas de la matriz
        printf("|"); // Imprime el separador de inicio de fila
        for (int j = 0; j < columnas; ++j) { // Itera sobre las columnas de la fila actual
            printf(" %d ", matriz[i][j]); // Imprime cada elemento de la matriz
        }
        printf("|\n"); // Imprime el separador de fin de fila
    }
}

int main() {
    int filas, columnas;
    
    // Mensaje de bienvenida
    printf(" ----BIENVENIDO----\n");
    
    // Ingresar número de filas y columnas para la matriz
    printf("Ingrese el numero de filas de la matriz: ");
    while (scanf("%d", &filas) != 1 || filas <= 0) { // Verifica la entrada de filas válida
        printf("ERROR. Por favor, ingrese un numero valido para las filas (mayor que 0): ");
        while (getchar() != '\n'); // Descarta los caracteres adicionales en la entrada estándar
    }
    
    printf("Ingrese el numero de columnas de la matriz: ");
    while (scanf("%d", &columnas) != 1 || columnas <= 0) { // Verifica la entrada de columnas válida
        printf("ERROR. Por favor, ingrese un numero valido para las columnas (mayor que 0): ");
        while (getchar() != '\n'); // Descarta los caracteres adicionales en la entrada estándar
    }
    printf("\n");

    int matriz[100][100], producto[100][100];

    // Ingreso de la matriz
    printf("Ingrese la matriz:\n");
    for (int i = 0; i < filas; ++i) { // Itera sobre las filas de la matriz
        for (int j = 0; j < columnas; ++j) { // Itera sobre las columnas de la matriz
            printf("Ingrese un numero para la matriz (%d,%d): ", i+1, j+1);
            while (scanf("%d", &matriz[i][j]) != 1) { // Verifica la entrada válida para cada elemento
                printf("ERROR. Por favor, ingrese un numero valido para la matriz (%d,%d): ", i+1, j+1);
                while (getchar() != '\n'); // Descarta los caracteres adicionales en la entrada estándar
            }
        }
    }
    printf("\n");

    // Imprimir la matriz ingresada
    imprimir_matriz(matriz, filas, columnas, "La matriz ingresada es");

    // Calcular la potencia cuadrada de la matriz (matriz * matriz)
    int temp[100][100];
    copiar_matriz(matriz, temp, filas, columnas); // Copia la matriz original a temp

    multiplicar_matrices(matriz, filas, columnas, temp, filas, columnas, producto); // Calcula la multiplicación

    // Imprimir el resultado final (matriz producto)
    imprimir_matriz(producto, filas, columnas, "El resultado de la potencia de matrices es");

    return 0;
}
