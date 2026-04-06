#include <stdio.h>
#include <omp.h>

int main() {
    omp_set_num_threads(4);
    int id;

    #pragma omp parallel
    {
        id = omp_get_thread_num();
        printf("Hola desde el hilo %d\n", id);
    }
}