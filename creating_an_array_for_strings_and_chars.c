#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** crearArreglo(int n) {
    char** arreglo_strings = malloc(n * sizeof(char *));

    if (arreglo_strings == NULL) {
        printf("Error al alocar memoria");
        return NULL;
    }

    return arreglo_strings;
}

void inicializarArreglo(char **arreglo, int n) {
    if (arreglo == NULL) {
        printf("El arreglo no puede ser inicializado.");
        return;
    }

    int i = 0;
    for (i = 0; i < n; i++) {
        char temp[1000] = {};
        printf("Ingresa la cadena que quieres ingresar: \n");
        scanf("%s", temp);
        *(arreglo + i) = strdup(temp);
    }
}

void liberarArreglo(char **arreglo, int n) {
    while (arreglo != NULL) {
        int i = 0;
        for (i = 0; i < n; i++) {
            free(*(arreglo + i));
        }
    }
}

void imprimirArreglo(char **arreglo, int n) {
    if (arreglo == NULL) {
        printf("El arreglo es nulo, no puede ser impreso.");
        return;
    }

    int i = 0;

    for (i = 0; i < n; i++) {
        printf("%s  ", *(arreglo + i));
    }
}

int main() {
    int n;
    printf("¿Qué longitud quieres que tenga tu arreglo?: ");
    scanf("%d", &n);

    char** arreglo = crearArreglo(n);
    inicializarArreglo(arreglo, n);
    imprimirArreglo(arreglo, n);
    free(arreglo);
}