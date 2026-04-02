#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32

static unsigned int rand_r(unsigned int *seed){
    *seed = (*seed * 1103515245u + 12345u);
    return (*seed >> 16) & 0x7FFF;
}

#endif

int* generarVector(int n, int vmin, int vmax, unsigned int semilla) {
    int* vector = malloc(n * sizeof(int));

    if (vector == NULL) {
        printf("Hubo un fallo al almacenar la data del vector");
        return NULL;
    }

    int i = 0;
    for (i = 0; i < n; i++) {
        *(vector + i) = rand_r(&semilla) % (vmax - vmin + 1) + vmin;
    }

    return vector;
}

void ordenamientoBurbuja(int *vector, int n) {
    if (vector == NULL) {
        printf("No es posible ordenar un vector vacío.");
        return;
    }

    int j = 0;
    bool cambio = true;
    while (cambio == true) {
        cambio = false;
        for (j = 0; j < n; j++) {
            if (*(vector + j) > *(vector + j + 1)) {
                int temp = *(vector + j);
                *(vector + j) = *(vector + j + 1);
                *(vector + j + 1) = temp;
                cambio = true;
            }
        }
    }

    int k = 0;
    for (k = 0; k < n; k++) {
        printf("%d  ", *(vector + k));
    }
}

void imprimirVector(const int *vector, int n) {
    int i = 0;

    if (vector == NULL) {
        printf("El vector es nulo y no puede imprimirse.");
        return;
    }

    for (i = 0; i < n; i++) {
        printf("%d  ", *(vector + i));
    }
}

int main() {
    int* primer_vector_generado = generarVector(10, 1, 15, 221234);
    imprimirVector(primer_vector_generado, 10);
    printf("\n");
    ordenamientoBurbuja(primer_vector_generado, 10);
    free(primer_vector_generado);
}