#include <stdio.h>
#include <omp.h>

int main() {
    omp_set_num_threads(2);
    int sum = 0;
    int i = 0;

    #pragma omp parallel for reduction(+: sum)
    for (i = 0; i <= 100; i++) {
        sum += i;
    }

    printf("La suma de los numeros naturales del 1 al 100 es: %d\n", sum);
    return 0;
}