#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

int* crearVector(unsigned int semilla) {
    int* vector = malloc(1000000 * sizeof(int));

    if (vector == NULL) {
        printf("Error al intentar alojar el espacio en memoria para el vector.");
        return NULL;
    }

    int i = 0;
    for (i = 0; i < 1000000; i++) {
        *(vector + i) = (double)rand_r(&semilla) / RAND_MAX * 10;
    }

    return vector;
}

int main() {
    int* vector = crearVector(21233);
    int suma = 0;
    omp_set_num_threads(4);

    int i = 0;
    #pragma omp parallel for
    for (i = 0; i < 1000000; i++) {
        suma += *(vector + i);
    }

    printf("Suma con error: %d\n", suma);

    suma = 0;
    int j = 0;
    #pragma omp parallel for
    for (j = 0; j < 1000000; j++) {
        #pragma omp critical
        suma += *(vector + j);
    }

    printf("Suma correcta: %d\n", suma);
    free(vector);
    return 0;
}