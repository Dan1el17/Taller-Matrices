#include <stdio.h>

#define tamano_matriz 3  // Tamaño de la matriz (matriz 3x3 en este ejemplo)

// Función para imprimir una matriz de tamaño tamano_matriz x tamano_matriz
void imprimirMatriz(float matriz[][tamano_matriz], int filas) {
    for (int fila = 0; fila < filas; fila++) {
        printf("|");
        for (int columna = 0; columna < tamano_matriz; columna++) {
            printf("%.2f\t", matriz[fila][columna]);  // Imprime cada elemento de la matriz con dos decimales
        }
        printf("|\n");  // Nueva línea al final de cada fila para formato
    }
}

// Función para calcular la determinante de una matriz cuadrada de tamaño tamano_matriz x tamano_matriz
float calcularDeterminante(float matriz[][tamano_matriz]) {
    float det = 0;  // Inicializamos el determinante a cero
    
    // Calcular la determinante utilizando la fórmula para matrices 3x3
    det = matriz[0][0] * (matriz[1][1] * matriz[2][2] - matriz[1][2] * matriz[2][1])
        - matriz[0][1] * (matriz[1][0] * matriz[2][2] - matriz[1][2] * matriz[2][0])
        + matriz[0][2] * (matriz[1][0] * matriz[2][1] - matriz[1][1] * matriz[2][0]);
    
    return det;  // Retornar el valor calculado de la determinante
}

// Función para obtener la matriz inversa de una matriz cuadrada de tamaño tamano_matriz x tamano_matriz
void obtenerMatrizInversa(float matriz[][tamano_matriz], float inversa[][tamano_matriz]) {
    // Calculamos la determinante de la matriz original
    float det = calcularDeterminante(matriz);
    
    // Verificar si la determinante es cero para determinar si la matriz tiene inversa
    if (det == 0) {
        printf("La matriz no tiene inversa porque su determinante es cero.\n");
        return;  // Salir de la función si la determinante es cero
    }
    
    // Calculamos la matriz de cofactores
    float cofactores[tamano_matriz][tamano_matriz];
    cofactores[0][0] = matriz[1][1] * matriz[2][2] - matriz[1][2] * matriz[2][1];
    cofactores[0][1] = -(matriz[1][0] * matriz[2][2] - matriz[1][2] * matriz[2][0]);
    cofactores[0][2] = matriz[1][0] * matriz[2][1] - matriz[1][1] * matriz[2][0];
    
    cofactores[1][0] = -(matriz[0][1] * matriz[2][2] - matriz[0][2] * matriz[2][1]);
    cofactores[1][1] = matriz[0][0] * matriz[2][2] - matriz[0][2] * matriz[2][0];
    cofactores[1][2] = -(matriz[0][0] * matriz[2][1] - matriz[0][1] * matriz[2][0]);
    
    cofactores[2][0] = matriz[0][1] * matriz[1][2] - matriz[0][2] * matriz[1][1];
    cofactores[2][1] = -(matriz[0][0] * matriz[1][2] - matriz[0][2] * matriz[1][0]);
    cofactores[2][2] = matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
    
    // Transponemos la matriz de cofactores para obtener la adjunta
    for (int i = 0; i < tamano_matriz; i++) {
        for (int j = 0; j < tamano_matriz; j++) {
            inversa[i][j] = cofactores[j][i] / det;
        }
    }
}

int main() {
    int filas1, columnas1;
    int filas2, columnas2;
    
    // Mensaje de bienvenida
    printf(" ----BIENVENIDO----\n");
    
    // Ingresar número de filas y columnas para la primera matriz
    printf("Ingrese el numero de filas de la primera matriz: ");
    while (scanf("%d", &filas1) != 1 || filas1 <= 0) {
        printf("ERROR. Por favor, ingrese un numero valido para las filas (> 0): ");
        while (getchar() != '\n'); // Descartar los caracteres adicionales en la entrada estándar
    }
    
    printf("Ingrese el numero de columnas de la primera matriz: ");
    while (scanf("%d", &columnas1) != 1 || columnas1 <= 0) {
        printf("ERROR. Por favor, ingrese un numero valido para las columnas (> 0): ");
        while (getchar() != '\n'); // Descartar los caracteres adicionales en la entrada estándar
    }
    printf("\n");

    // Ingresar número de filas y columnas para la segunda matriz
    printf("Ingrese el numero de filas de la segunda matriz: ");
    while (scanf("%d", &filas2) != 1 || filas2 <= 0) {
        printf("ERROR. Por favor, ingrese un numero valido para las filas (> 0): ");
        while (getchar() != '\n'); // Descartar los caracteres adicionales en la entrada estándar
    }
    
    printf("Ingrese el numero de columnas de la segunda matriz: ");
    while (scanf("%d", &columnas2) != 1 || columnas2 <= 0) {
        printf("ERROR. Por favor, ingrese un numero valido para las columnas (> 0): ");
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
    float matriz1[filas1][columnas1], matriz2[filas2][columnas2], producto[filas1][columnas2];    
    
    // Ingreso de la primera matriz
    printf("Ingrese la primera matriz:\n");
    for (int i = 0; i < filas1; ++i) {
        for (int j = 0; j < columnas1; ++j) {
            printf("Ingrese un numero para la primera matriz (%d,%d): ", i+1, j+1);
            while (scanf("%f", &matriz1[i][j]) != 1) {
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
            while (scanf("%f", &matriz2[i][j]) != 1) {
                printf("ERROR. Por favor, ingrese un numero valido para la segunda matriz (%d,%d): ", i+1, j+1);
                while (getchar() != '\n'); // Descartar los caracteres adicionales en la entrada estándar
            }
        }
    }
    printf("\n");

    // Imprimir las matrices ingresadas
    printf("La matriz 1 ingresada es:\n");
    imprimirMatriz(matriz1, filas1);
    
    printf("La matriz 2 ingresada es:\n");
    imprimirMatriz(matriz2, filas2);
    printf("\n");

    // Multiplicación de matrices
    if (columnas1 == filas2) {
        // Calcular la inversa de la segunda matriz
        float matriz2_inversa[tamano_matriz][tamano_matriz];
        obtenerMatrizInversa(matriz2, matriz2_inversa);

        // Multiplicar la primera matriz por la inversa de la segunda matriz
        printf("Resultado de la division de matrices (multiplicacion por la inversa de la segunda matriz):\n");
        for (int i = 0; i < filas1; ++i) {
            for (int j = 0; j < columnas2; ++j) {
                producto[i][j] = 0;
                for (int k = 0; k < columnas1; ++k) {
                    producto[i][j] += matriz1[i][k] * matriz2_inversa[k][j];
                }
            }
        }

        // Imprimir la matriz resultado
        printf("El resultado de la division de las dos matrices es:\n");
        imprimirMatriz(producto, filas1);
    } else {
        printf("No se pueden dividir las matrices porque no son compatibles.\n");
    }

    return 0;
}
