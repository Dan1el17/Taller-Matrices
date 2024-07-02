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
    float matriz[tamano_matriz][tamano_matriz];
    float matriz_inversa[tamano_matriz][tamano_matriz];

    // Ingresar elementos de la matriz
    printf("Ingrese los elementos de la matriz %dx%d:\n", tamano_matriz, tamano_matriz);
    for (int i = 0; i < tamano_matriz; ++i) {
        for(int j = 0; j < tamano_matriz; ++j) {
            printf("Ingrese un numero (%d,%d): ", i+1, j+1);
            while (scanf("%f", &matriz[i][j]) != 1) { // Bucle while para comprobar si es que el usuario ingreso correctamente un numero
                printf("ERROR. Por favor, ingrese un numero (%d,%d): ", i+1, j+1); /* Sumamos uno tanto para las
                filas y columnas para que al momento de presentr el mensaje nos indique la posicion del numero que va ingresar*/
                while (getchar() != '\n'); // Descartar los caracteres adicionales en la entrada estándar
            }
        }
    }

    // Calcular y mostrar la determinante de la matriz
    float determinante = calcularDeterminante(matriz);
    printf("La determinante de la matriz es: %.2f\n", determinante);

    // Obtener la matriz inversa si es posible
    if (determinante == 0) {
        printf("La matriz no tiene inversa porque su determinante es cero.\n");
    } else {
        obtenerMatrizInversa(matriz, matriz_inversa);

        // Imprimir la matriz inversa calculada
        printf("La matriz inversa es:\n");
        imprimirMatriz(matriz_inversa, tamano_matriz);
    }

    return 0;
}
