#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double** crearMatriz(int filas, int cols) {
    double** matriz = malloc(filas * sizeof(double *));
    if (matriz == NULL) {
        printf("No se pudo realizar el alojamiento de la matriz en memoria");
        return NULL;
    }

    int i = 0;
    while (i != filas) {
        matriz[i] = malloc(cols * sizeof(double));
        if (matriz[i] == NULL) {
            int j = 0;
            printf("No se pudo realizar el alojamiento del elemento de la matriz en memoria");
            for (j = 0; j < i; j++) {
                free(matriz[j]);
            }
            free(matriz);
            return NULL;
        }
        i++;
    }

    return matriz;
}

void liberarMatriz(double **m, int filas) {
    if (m != NULL) {
        int j = 0;
        for (j = 0; j < filas; j++) {
            free(m[j]);
        }
        free(m);
    }
}

void inicializar(double **m, int filas, int cols, double valor_base) {
    if (m == NULL) {
        printf("La matriz es nula.");
        return;
    }

    int i = 0;
    int j = 0;

    for (i = 0; i < filas; i++) {
        for (j = 0; j < cols; j++) {
            *(*(m + i) + j) = (valor_base + i * cols + j);
        }
    }
}

void sumarMatrices(double **A, double **B, double **C, int filas, int cols) {
    if (A == NULL || B == NULL || C == NULL) {
        printf("La matriz es nula.");
        return;
    }

    int i = 0;
    int j = 0;

    for (i = 0; i < filas; i++) {
        for (j = 0; j < cols; j++) {
            *(*(C + i) + j) = *(*(A + i) + j) + *(*(B + i) + j);
        }
    }
}

void multiplicarMatrices(double **A, double **B, double **C, int n) {
    if (A == NULL || B == NULL || C == NULL) {
        printf("La matriz es nula.");
        return;
    }

    int i = 0;
    int j = 0;
    int k = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            double acumulador = 0;

             for (k = 0; k < n; k++) {
                acumulador += *(*(A + i) + k) * *(*(B + k) + j);
            }
            *(*(C + i) + j) = acumulador;
        }
    }
}

void imprimirMatriz(double **m, int filas, int cols, const char *nombre) {
    if (m == NULL) {
        printf("La matriz es nula.");
        return;
    }

    int i = 0;
    int j = 0;

    printf("La matriz de nombre: %s", nombre);
    printf("\n");

    for (i = 0; i < filas; i++) {
        for (j= 0; j < cols; j++) {
            printf("%8.2f ", *(*(m + i) + j));
        }
        printf("\n");
    }
}


int main() {
    int n;

    printf("Ingresa la dimensión n que quieres que tengan las matrices cuadradas: ");
    if (scanf("%d", &n) != 1) {
        printf("Entrada inválida\n");
        return 1;
    }

    double** A = crearMatriz(n, n);
    double** B = crearMatriz(n, n);
    double** C = crearMatriz(n, n);
    inicializar(A, n, n, 1);
    inicializar(B, n, n, 2);
    imprimirMatriz(A, n, n, "Matriz #1");
    printf("\n");
    imprimirMatriz(B, n, n, "Matriz #2");
    printf("\n");
    sumarMatrices(A, B, C, n,n);
    imprimirMatriz(C, n, n, "Matriz Sumada");
    printf("\n");
    multiplicarMatrices(A, B, C, n);
    imprimirMatriz(C, n, n, "Matriz Multiplicada");

    double** D = crearMatriz(100, 100);
    double** E = crearMatriz(100, 100);
    double** F = crearMatriz(100, 100);
    inicializar(D, 100, 100, 1);
    inicializar(E, 100, 100, 2);
    clock_t tiempo_de_inicio_para_100 = clock();
    multiplicarMatrices(D, E, F, 100);
    clock_t tiempo_de_final_para_100 = clock();
    double tiempo_transcurrido_para_100 = (double)(tiempo_de_final_para_100 - tiempo_de_inicio_para_100) / CLOCKS_PER_SEC;

    double** G = crearMatriz(200, 200);
    double** H = crearMatriz(200, 200);
    double** I = crearMatriz(200, 200);
    inicializar(G, 200, 200, 1);
    inicializar(H, 200, 200, 2);
    clock_t tiempo_de_inicio_para_200 = clock();
    multiplicarMatrices(G, H, I, 200);
    clock_t tiempo_de_final_para_200 = clock();
    double tiempo_transcurrido_para_200 = (double)(tiempo_de_final_para_200 - tiempo_de_inicio_para_200) / CLOCKS_PER_SEC;

    double** J = crearMatriz(500, 500);
    double** K = crearMatriz(500, 500);
    double** L = crearMatriz(500, 500);
    inicializar(J, 500, 500, 1);
    inicializar(K, 500, 500, 2);
    clock_t tiempo_de_inicio_para_500 = clock();
    multiplicarMatrices(J, K, L, 500);
    clock_t tiempo_de_final_para_500 = clock();
    double tiempo_transcurrido_para_500 = (double)(tiempo_de_final_para_500 - tiempo_de_inicio_para_500) / CLOCKS_PER_SEC;

    printf("\n");

    printf("Tiempo transcurrido para cada n: \n");
    printf("%-8s %8.5fs\n", "n = 100:", tiempo_transcurrido_para_100);
    printf("%-8s %8.5fs\n", "n = 200:", tiempo_transcurrido_para_200);
    printf("%-8s %8.5fs\n", "n = 500:", tiempo_transcurrido_para_500);

    liberarMatriz(A, n);
    liberarMatriz(B, n);
    liberarMatriz(C, n);
    liberarMatriz(D, 100);
    liberarMatriz(E, 100);
    liberarMatriz(F, 100);
    liberarMatriz(G, 200);
    liberarMatriz(H, 200);
    liberarMatriz(I, 200);
    liberarMatriz(J, 500);
    liberarMatriz(K, 500);
    liberarMatriz(L, 500);
}