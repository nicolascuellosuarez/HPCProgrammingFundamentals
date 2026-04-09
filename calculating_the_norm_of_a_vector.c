#include <stdio.h>
#include <omp.h>
#include <math.h>
#include <stdlib.h>

int* crearVector(int n, unsigned int semilla) {
    int* vector = malloc(n * sizeof(int));

    if (vector == NULL) {
        printf("Error al intentar alojar el espacio en memoria para el vector.");
        return NULL;
    }

    int i = 0;
    for (i = 0; i < n; i++) {
        *(vector + i) = rand_r(&semilla) % 11;
    }

    return vector;
}

int main() {
    int n;
    printf("Ingresa el número de posiciones que quieres que tenga el arreglo: ");
    if (scanf("%d", &n) != 1) {
        printf("Error al recolectar el dato.");
        return 1;
    }

    int* vector1 = crearVector(n, 13243);
    int suma_cuadrados = 0;
    omp_set_num_threads(4);

    int i = 0;
    #pragma omp parallel for simd reduction(+: suma_cuadrados)
    for (i = 0; i < n; i++) {
        suma_cuadrados += *(vector1 + i) * *(vector1 + i);
    }

    double norma = sqrt(suma_cuadrados);
    printf("La norma del vector creado es: %f\n", norma);
    free(vector1);
    return 0;
}