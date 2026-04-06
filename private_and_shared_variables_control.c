#include <stdio.h>
#include <omp.h>

int main() {
    omp_set_num_threads(4);
    int suma = 0;
    int sumaind = 0;

    #pragma omp parallel shared(suma) private(sumaind)
    {
        sumaind = omp_get_thread_num() + 1;
        #pragma omp atomic
        suma += sumaind;
        printf("Se sumó %d a la suma total que va en %d\n", sumaind, suma);
    }

    printf("La suma total es: %d\n", suma);
    return 0;
}