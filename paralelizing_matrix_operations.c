#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

int** crearMatriz(int filas, int cols) {
    int** matriz = malloc(filas * sizeof(int *));

    if (matriz == NULL) {
        printf("Fallo al alojar la matriz en memoria.");
        return NULL;
    }

    int i = 0;
    for (i = 0; i < filas; i++) {
        *(matriz + i) = malloc(cols * sizeof (int));
        if (*(matriz + i) == NULL) {
            int j = 0;
            printf("No se pudo hacer el alojamiento de memoria.");
            for (j = 0; j < i; j++) {
                free(*(matriz + j));
            }
            free(matriz);
            return NULL;
        }
    }
    return matriz;
}

void inicializarMatriz(int** m, int filas, int cols, int valor_base) {
    if (m == NULL) {
        printf("La matriz no existe en memoria.");
        return;
    }

    int i = 0;
    int j = 0;

    for (i = 0; i < filas; i++) {
        for (j = 0; j < cols; j++) {
            *(*(m + i) + j) = valor_base * filas + cols;
        }
    }
}

void liberarMatriz(int** m, int filas) {
    if (m == NULL) {
        printf("La matriz no existe en memoria.");
        return;
    }

    int j = 0;
    for (j = 0; j < filas; j++) {
        free(*(m + j));
    }
    free(m);
}

void sumarMatrices(int** A, int** B, int** C, int filas, int cols) {
    if (A == NULL || B == NULL || C == NULL) {
        printf("Alguna de las matrices no está alojada en memoria.");
        return;
    }

    int i = 0;
    int j = 0;

    #pragma omp parallel for
    for (i = 0; i < filas; i++) {
        for (j = 0; j < cols; j++) {
            *(*(C + i) + j) = *(*(A + i) + j) + *(*(B + i) + j);
        }
    }
}

void multiplicarMatrices(int** A, int** B, int** C, int n) {
    if (A == NULL || B == NULL || C == NULL) {
        printf("Alguna de las matrices no esta alojada en memoria.");
        return;
    }

    int i = 0;
    int j = 0;
    int k = 0;

    #pragma omp parallel for private(j, k)
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            int acumulador = 0;
            for (k = 0; k < n; k++) {
                acumulador += *(*(A + i) + k) * *(*(B + k) + j);
            }
            *(*(C + i) + j) = acumulador;
        }
    }
}

void escalarPorMatriz(int** A, int** B, int escalar, int filas, int cols) {
    if (A == NULL || B == NULL) {
        printf("Alguna de las matrices no fue almacenada en memoria.");
        return;
    }

    int i = 0;
    int j = 0;

    #pragma omp parallel for
    for (i = 0; i < filas; i++) {
        for (j = 0; j < cols; j++) {
            *(*(B + i) + j) = escalar * *(*(A + i) + j);
        }
    }
}

void imprimirMatriz(int **m, int filas, int cols) {
    if (m == NULL) {
        printf("La matriz es nula.");
        return;
    }

    int i = 0;
    int j = 0;

    for (i = 0; i < filas; i++) {
        for (j = 0; j < cols; j++) {
            printf("%i", *(*(m + i) + j));
        }
    }
}

int main() {
    for (int t = 0; t < 3; t++) {
        int tamanos[3] = {500, 1000, 2000};
        int N = tamanos[t];
        printf("\n Benchmark Matriz %d x %d \n", N, N);

        int** A = crearMatriz(N, N);
        int** B = crearMatriz(N, N);
        int** C = crearMatriz(N, N);

        inicializarMatriz(A, N, N, 2);
        inicializarMatriz(B, N, N, 4);

        double inicio = omp_get_wtime();
        escalarPorMatriz(A, C, 5, N, N);
        double fin = omp_get_wtime();
        printf("Escalar por Matriz: %.4f ms\n", (fin - inicio) * 1000);

        inicio = omp_get_wtime();
        sumarMatrices(A, B, C, N, N);
        fin = omp_get_wtime();
        printf("Suma de Matrices:   %.4f ms\n", (fin - inicio) * 1000);

        inicio = omp_get_wtime();
        multiplicarMatrices(A, B, C, N);
        fin = omp_get_wtime();
        printf("Multiplicación: %.4f ms\n", (fin - inicio) * 1000);

        liberarMatriz(A, N);
        liberarMatriz(B, N);
        liberarMatriz(C, N);
    }

    return 0;
}
