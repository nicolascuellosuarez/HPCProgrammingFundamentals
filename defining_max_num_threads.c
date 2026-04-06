#include <stdio.h>
#include <omp.h>

int main() {
    int max_num_threads = omp_get_num_procs();
    printf("En mi sistema hay %d procesadores.\n", max_num_threads);
    omp_set_num_threads(max_num_threads / 2);

    #pragma omp parallel
    {
        int id;
        id = omp_get_thread_num();
        printf("Hola mundo desde el hilo %d\n", id);
        int num_threads = omp_get_num_threads();
        printf("EL número total de hilos es %d\n", num_threads);
    }

    return 0;
}