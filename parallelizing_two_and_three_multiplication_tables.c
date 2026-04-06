#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

int main() {
    #pragma omp sections
    {
        #pragma omp section
        {
            int i = 0;
            for (i = 0; i <= 10; i++) {
                int multiplicacion = 2 * i;
                printf("2 * %d = %d\n", i, multiplicacion);
            }
        }
        #pragma omp section
        {
            printf("\n");
            int i = 0;
            for (i = 0; i <= 10; i++) {
                int multiplicacion = 3 * i;
                printf("3 * %d = %d\n", i, multiplicacion);
            }
        }
    }

    return 0;
}