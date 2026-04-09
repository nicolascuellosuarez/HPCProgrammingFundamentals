#include <stdio.h>
#include <stdlib.h>

double* generarVector(int n, unsigned int semilla) {
    double* vector = malloc(n * sizeof(double));
    int i = 0;

    if (vector == NULL) {
        printf("No se pudo realizar el alojamiento del vector en memoria");
        return NULL;
    }

    for (i = 0; i < n; i++) {
        *(vector + i) = (double)rand_r(&semilla) / RAND_MAX * 100.0;
    }

    return vector;
}

int main() {
    double* v1 = generarVector(10000000, 12334242);
    double* v2 = generarVector(10000000, 756454);

    double suma = 0;
    int i = 0;

    #pragma omp simd reduction(+:suma)
        for (i = 0; i < 1000000; i++) {
            suma += *(v1 + i) * *(v2 + i);
        }

    free(v1);
    free(v2);
    printf("El producto punto entre los dos vectores anteriormente mencionados es: %f", suma);

}