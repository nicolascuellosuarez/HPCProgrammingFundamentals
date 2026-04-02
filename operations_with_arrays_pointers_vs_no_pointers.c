#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000
typedef struct {
    int data[N];
} Contenedor;

int* crearVector(int n, int valor_inicial) {
    int* vector = malloc(n * sizeof(int));

    if (vector == NULL) {
        printf("Fallo al alojar el vector en memoria.");
        return NULL;
    }

    int i = 0;
    for (i = 0; i < n; i++) {
        *(vector + i) = valor_inicial * n + 2;
        valor_inicial += *(vector + i);
    }

    return vector;
}

int calcularSumaPorValor(Contenedor c) {
    int suma = 0;
    int i = 0;

    for (i = 0; i < N; i++) {
        suma += c.data[i];
    }

    return suma;
}

int calcularSumaPorReferencia(const Contenedor *c) {
    int suma = 0;
    int i = 0;

    for (i = 0; i < N; i++) {
        suma += c -> data[i];
    }

    return suma;
}

int calcularMinimoPorValor(Contenedor c) {
    int minimo = c.data[0];
    int i = 0;

    for (i = 0; i < N; i++) {
        if (c.data[i] < minimo) {
            minimo = c.data[i];
        }
    }

    return minimo;
}

int calcularMinimoPorReferencia(const Contenedor *c) {
    int minimo = c -> data[0];
    int i = 0;

    for (i = 0; i < N; i++) {
        if (c -> data[i] < minimo) {
            minimo = c -> data[i];
        }
    }

    return minimo;
}

int main() {

}
