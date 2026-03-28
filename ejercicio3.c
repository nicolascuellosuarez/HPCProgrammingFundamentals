#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32

static unsigned int rand_r(unsigned int *seed){
    *seed = (*seed * 1103515245u + 12345u);
    return (*seed >> 16) & 0x7FFF;
}

#endif

int* generarVectorInt(int n, int vmin, int vmax, unsigned int semilla) {
    int* vector = malloc(n * sizeof(int));
    int i = 0;

    if (vector == NULL) {
        printf("Fallo al intentar alojar el vector en memoria.");
        return NULL;
    }

    for (i = 0; i < n; i++) {
        *(vector + i) = rand_r(&semilla) % (vmax - vmin + 1) + vmin;
    }

    return vector;
}

int* copiarVector(const int *src, int n) {
    if (src == NULL) {
        printf("Fallo al intentar alojar el vector copia en memoria, el vector original es nulo..");
        return NULL;
    }

    if (n <= 0) {
        printf("El espacio y número de elementos del vector NO es válido.");
        return NULL;
    }

    int *vector_de_copia = malloc(n * sizeof(int));

    if (vector_de_copia == NULL) {
        printf("Fallo al intentar alojar la copia del vector");
        return NULL;
    }

    memcpy(vector_de_copia, src, n * sizeof(int));
    return vector_de_copia;
}

void merge(int *arr, const int *izq, int n_izq, const int *der, int n_der) {
    if (arr == NULL) {
        printf("EL arreglo original está vacío.");
    }

    int* arreglo_temporal = malloc((n_izq + n_der) * sizeof(int));
    if (arreglo_temporal == NULL) {
        printf("Los arreglos están vacíos.");
        return;
    }

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n_izq && j < n_der) {
        if (*(der + j) < *(izq + i)) {
            *(arreglo_temporal + k++) = *(der + j++);
        } else if (*(der + j) > *(izq + i)) {
            *(arreglo_temporal + k++) = *(izq + i++);
        } else {
            *(arreglo_temporal + k++) = *(izq + i++);
            *(arreglo_temporal + k++) = *(der + j++);
        }
    }

    while (i < n_izq) {
        *(arreglo_temporal + k++) = *(izq + i++);
    }
    while (j < n_der) {
        *(arreglo_temporal + k++) = *(der + j++);
    }

    memcpy(arr, arreglo_temporal, (n_izq + n_der) * sizeof(int));
    free(arreglo_temporal);
}

void mergeSort(int *arr, int n) {
    if (arr == NULL) {
        printf("El arreglo no está alojado en memoria");
        return;
    }

    if (n <= 1) {
        return;
    }

    int *izq = arr;
    int n_izq = n / 2;
    int *der = arr + (n / 2);
    int n_der = n - n_izq;

    mergeSort(izq, n_izq);
    mergeSort(der, n_der);
    merge(arr, izq, n_izq, der, n_der);
}

int* buscarBinario(const int *arr, int n, int objetivo) {
    int *inicio = (int*)arr;
    int *final = (int*)arr + n - 1;

    while (inicio <= final) {
        int *medio = (inicio + (final - inicio) / 2);

        if (objetivo == *medio) {
            return medio;
        } else if (objetivo < *medio) {
            final = (medio - 1);
        } else {
            inicio = (medio + 1);
        }
    }

    return NULL;
}

int verificarOrdenado(const int *arr, int n) {
    if (arr == NULL) {
        printf("El arreglo no está alojado en memoria");
        return 2;
    }
    int i = 0;
    const int *ptr = arr;

    while (i < n - 1) {
        if (*ptr > *(ptr + 1)) {
            return 0;
        }
        ptr++;
        i++;
    }

    return 1;
}

int main() {
    for (int t = 0; t < 4; t++) {
        unsigned int semilla = 2;
        int tamaños[4] = {1000, 10000, 100000, 1000000};
        int n = tamaños[t];
        printf("Tamaño del vector: %d", n);

        int* vector = generarVectorInt(n, 0, 100, semilla);
        int* copia = copiarVector(vector, n);

        clock_t inicio = clock();
        mergeSort(copia, n);
        clock_t fin = clock();
        double tiempo_ms = (double)(fin - inicio) * 1000.0 / CLOCKS_PER_SEC;

        printf("\n");
        printf("Tiempo de mergeSort: %.3f ms\n", tiempo_ms);
        printf("Verificación: %s\n", verificarOrdenado(copia, n) ? "Ordenado de forma correcta" : "No ordenado");

        int buscar[5] = {copia[0], copia[1], -1, -5, 200};
        for (int i = 0; i < 5; i++) {
            int* res = buscarBinario(copia, n, buscar[i]);
            if (res)
                printf("Busqueda de %d -> encontrado, ptr = %p\n", buscar[i], (void*)res);
            else
                printf("Busqueda de %d -> no encontrado (NULL)\n", buscar[i]);
        }

        free(vector);
        free(copia);
    }
    return 0;
}