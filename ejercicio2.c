#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

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
    if (n <= 0 || vector == NULL) {
        return 0;
    }

    int i = 0;
    double min = *(vector + i);

    for (i = 1; i < n; i++) {
        if (*(vector + i) < min) {
            min = *(vector + i);
        }
    }

    return min;
}

double calcularMax(const double *vector, int n) {
    if (n <= 0 || vector == NULL) {
        return 0;
    }

    int i = 0;
    double max = *(vector + i);

    for (i = 1; i < n; i++) {
        if (*(vector + i) > max) {
            max = *(vector + i);
        }
    }

    return max;
}

double calcularSuma(const double *vector, int n) {
    if (vector == NULL) {
        printf("El vector es nulo.");
        return 0.0;
    }

    int i = 0;
    double sum = 0.0;

    for (i = 0; i < n; i++) {
        sum += *(vector + i);
    }

    return sum;
}

double calcularMedia(const double *vector, int n) {
    int i = 0;
    double suma = 0.0;


    for (i = 0; i < n; i++) {
        suma += *(vector + i);
    }

    double media = suma / n;
    return media;
}

double calcularVarianza(const double *vector, int n, double media) {
    int i = 0;
    double suma_de_cuadrados = 0.0;


    for (i = 0; i < n; i++) {
        suma_de_cuadrados += (*(vector + i) - media) * (*(vector + i) - media);
    }

    double varianza = suma_de_cuadrados / n;
    return varianza;
}

double calcularDesviacion(double varianza) {
    double desviacion = sqrt(varianza);
    return desviacion;
}

void normalizarMinMax(double *vector, int n, double min, double max) {
    // Validación inicial; si son iguales, puede existir división entre 0.
    if (min == max) {
        return;
    }

    int i = 0;
    double *ptr = vector;

    // Uso de punteros para el recorrido, actualización del objeto
    // con la fórmula descrita.
    for (i = 0; i < n; i++, ptr++) {
        *ptr = (*ptr - min) / (max - min);
    }
}

void imprimirVector(const double *vector, int n, int por_linea) {
    int i = 0;
    int counter = 0;
    const double *ptr = vector;

    printf("\n");

    for (i = 0; i < n; i ++, ptr++) {
        printf("%8.4f", *ptr);
        counter++;

        if (counter == por_linea) {
            printf("\n");
            counter = 0;
        }
    }
    printf("\n");
}

void reporteEstadisticas(const double *vector, int n, const char *titulo) {
    if (vector == NULL) {
        printf("El vector es nulo, no tiene estadísticas.");
        return;
    }

    printf("\n");
    printf("Las estadísticas del vector: %s", titulo);
    printf("\n");
    printf("El valor mínimo hallado en el vector es %f", calcularMin(vector, n));
    printf("\n");
    printf("El valor máximo hallado en el vector es %f", calcularMax(vector, n));
    printf("\n");
    printf("La suma de todos los elementos del vector es: %f", calcularSuma(vector, n));
    printf("\n");
    double media = calcularMedia(vector, n);
    printf("El promedio de todos los elementos del vector es: %f", media);
    printf("\n");
    double varianza = calcularVarianza(vector, n, media);
    printf("La varianza de todos los elementos del vector es: %f", varianza);
    printf("\n");
    printf("La desviación estándar de los elementos del vector es: %f", calcularDesviacion(varianza));
    printf("\n");
}

double productoInterno(const double *vector_1, const double *vector_2, int n) {
    if (vector_1 == NULL || vector_2 == NULL) {
        return 0.0;
    }

    int i = 0;
    double producto_punto = 0.0;
    const double *ptr1 = vector_1;
    const double *ptr2 = vector_2;

    for (i = 0; i < n; i++, ptr1++, ptr2++) {
        producto_punto += *ptr1 * *ptr2;
    }

    return producto_punto;
}

int main() {
    double* vector_1 = generarVector(10, 341234123);
    imprimirVector(vector_1, 10, 5);
    double* vector_1_para_producto_punto = generarVector(10, 34152123);
    imprimirVector(vector_1_para_producto_punto, 10, 5);

    reporteEstadisticas(vector_1, 10, "Vector #1");

    double min = calcularMin(vector_1, 10);
    double max = calcularMax(vector_1, 10);
    normalizarMinMax(vector_1, 10, min, max);
    imprimirVector(vector_1, 10, 5);

    double* vector_2 = generarVector(1000, 65754854);
    reporteEstadisticas(vector_2, 1000, "Vector #2");

    printf("\n");

    double producto_punto = productoInterno(vector_1, vector_1_para_producto_punto, 10);
    printf("El producto punto entre los dos vectores anteriores es: %f", producto_punto);

    int i = 0;

    printf("\n");

    for (i = 0; i < 2; i++) {
        int tamanos[2] = {100000, 10000000};
        int cantidad = tamanos[i];

        double* vector_i = generarVector(cantidad, 7654847);
        clock_t tiempo_de_inicio_1 = clock();
        calcularSuma(vector_i, cantidad);
        clock_t tiempo_de_salida_1 = clock();
        double tiempo_transcurrido_1 = (double)(tiempo_de_salida_1 - tiempo_de_inicio_1) / CLOCKS_PER_SEC;

        double min_val = calcularMin(vector_i, cantidad);
        double max_val = calcularMax(vector_i, cantidad);
        clock_t tiempo_de_inicio_2 = clock();
        normalizarMinMax(vector_i, cantidad, min_val, max_val);
        clock_t tiempo_de_salida_2 = clock();
        double tiempo_transcurrido_2 = (double)(tiempo_de_salida_2 - tiempo_de_inicio_2) / CLOCKS_PER_SEC;

        printf("\n");
        printf("Cantidad de tiempo para calcular la suma de el vector de %d: %.6fs\n", cantidad, tiempo_transcurrido_1);
        printf("Cantidad de tiempo para calcular la normalizacion de el vector de %d: %.6fs\n", cantidad, tiempo_transcurrido_2);

        free(vector_i);
    }

    // Próxima implementación para BenchMarking:

    FILE *benchmarking = fopen("tiempos.dat", "w");
    fprintf(benchmarking, "#n Suma Normalización\n");

    int t = 0;
    for (t = 0; t < 4; t++) {
        int benchmarking_tamanos[4] = {10, 1000, 100000, 10000000};
        int cantidad_benchmarking = benchmarking_tamanos[t];

        double* vector_prueba = generarVector(cantidad_benchmarking, 12345);
        clock_t tiempo_de_inicio_para_suma = clock();
        calcularSuma(vector_prueba, cantidad_benchmarking);
        clock_t tiempo_de_final_para_suma = clock();
        double tiempo_ms_para_suma = (double)(tiempo_de_final_para_suma - tiempo_de_inicio_para_suma) * 1000.0 / CLOCKS_PER_SEC;

        double min_val_para_normalizar = calcularMin(vector_prueba, cantidad_benchmarking);
        double max_val_para_normalizar = calcularMax(vector_prueba, cantidad_benchmarking);
        clock_t tiempo_de_inicio_para_normalizacion = clock();
        normalizarMinMax(vector_prueba, cantidad_benchmarking, min_val_para_normalizar, max_val_para_normalizar);
        clock_t tiempo_de_final_para_normalizacion = clock();
        double tiempo_ms_para_normalizacion = (double)(tiempo_de_final_para_normalizacion - tiempo_de_inicio_para_normalizacion) * 1000.0 / CLOCKS_PER_SEC;

        fprintf(benchmarking, "%d %f %f\n", cantidad_benchmarking, tiempo_ms_para_suma, tiempo_ms_para_normalizacion);
        free(vector_prueba);
    }

    free(vector_1);
    free(vector_2);
}