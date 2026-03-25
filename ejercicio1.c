#include <stdio.h>
#include <stdlib.h>

double** crearMatriz(int filas, int cols) {
    double** matriz = malloc(filas * cols * sizeof(double *));
    if (matriz == NULL) {
        printf("No se hizo el allocating. ");
        return NULL;
    }
}


int main() {

}