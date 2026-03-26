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
        *(vector + i) = ((double)rand_r(&semilla) / RAND_MAX) * 100.0;
    }

    return vector;
}

double calcularMin(const double *vector, int n) {
    int i = 0;
    double min = *(vector + i);

    for (i = 0; i < n; i++) {
        if (*(vector + i) < min) {
            min = *(vector + i);
        }
    }

    return min;
}

double calcularMax(const double *vector, int n) {
    int i = 0;
    double max = *(vector + i);

    for (i = 0; i < n; i++) {
        if (*(vector + i) > max) {
            max = *(vector + i);
        }
    }

    return max;
}

double calcularSuma(const double *vector, int n) {
    int i = 0;
    double sum = 0;

    for (i = 0; i < n; i++) {
        sum += *(vector + i);
    }

    return sum;
}

double calcularMedia(const double *vector, int n) {
    int i = 0;
    double suma = 0;
    double media;

    for (i = 0; i < n; i++) {
        suma += *(vector + i);
    }

    media = suma / n;
    return media;
}


int main() {

}