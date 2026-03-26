#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

    if (n <= 0 || vector == NULL) {
        return 0;
    }

    for (i = 1; i < n; i++) {
        if (*(vector + i) < min) {
            min = *(vector + i);
        }
    }

    return min;
}

double calcularMax(const double *vector, int n) {
    int i = 0;
    double max = *(vector + i);

    if (n <= 0 || vector == NULL) {
        return 0;
    }

    for (i = 1; i < n; i++) {
        if (*(vector + i) > max) {
            max = *(vector + i);
        }
    }

    return max;
}

double calcularSuma(const double *vector, int n) {
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
    double media;

    for (i = 0; i < n; i++) {
        suma += *(vector + i);
    }

    media = suma / n;
    return media;
}

double calcularVarianza(const double *vector, int n, double media) {
    int i = 0;
    double suma_de_cuadrados = 0.0;
    double varianza;

    for (i = 0; i < n; i++) {
        suma_de_cuadrados += (*(vector + i) - media) * (*(vector + i) - media);
    }

    varianza = suma_de_cuadrados / n;
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
    double *ptr = vector;

    for (i = 0; i < n; i ++, ptr++) {
        printf("%8.4f", *ptr);
        counter++;

        if (counter == por_linea) {
            printf("\n");
            counter = 0;
        }
    }
}

void reporteEstadisticas(const double *vector, int n, const char *titulo) {
    printf("El mínimo es %d", calcularMin(vector, n));

}

int main() {

}