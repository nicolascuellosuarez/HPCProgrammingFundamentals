#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000
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
    Contenedor vector1;

    int i = 0;
    for (i = 0; i < N; i++) {
        vector1.data[i] = i + 2;
    }

    double inicio_suma_por_valor = omp_get_wtime();
    calcularSumaPorValor(vector1);
    double fin_suma_por_valor = omp_get_wtime();
    printf("Tiempo de cálculo de suma por valor: %.4f ms\n\n", (fin_suma_por_valor - inicio_suma_por_valor) * 1000);

    double inicio_suma_por_referencia = omp_get_wtime();
    calcularSumaPorReferencia(&vector1);
    double fin_suma_por_referencia = omp_get_wtime();
    printf("EL tiempo de cálculo de la suma por referencia: %.4f ms\n\n", (fin_suma_por_referencia - inicio_suma_por_referencia) * 1000);

    double inicio_minimo_por_valor = omp_get_wtime();
    calcularMinimoPorValor(vector1);
    double fin_minimo_por_valor = omp_get_wtime();
    printf("El tiempo de cálculo del mínimo por valor: %.4f ms\n\n", (fin_minimo_por_valor - inicio_minimo_por_valor) * 1000);

    double inicio_minimo_por_referencia = omp_get_wtime();
    calcularSumaPorReferencia(&vector1);
    double fin_minimo_por_referencia = omp_get_wtime();
    printf("El tiempo de cálculo del mínimo por referencia es: %.4f ms\n\n", (fin_minimo_por_referencia - inicio_minimo_por_referencia) * 1000);


}
