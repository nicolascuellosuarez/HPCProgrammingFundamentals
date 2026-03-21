#include <omp.h>
#include <stdio.h>

int main() {
    long long N = 100000000;  // Número de intervalos (mayor N, más precisión)
    double pi = 0.0;
    double delta_x = 1.0 / (double)N;  // Ancho de cada rectángulo

    #pragma omp parallel
    {
        double sum_local = 0.0;  // Variable local para cada hilo
        #pragma omp for
        for (long long i = 0; i < N; i++) {
            double x_i = (i + 0.5) * delta_x;  // Punto medio del intervalo
            sum_local += 4.0 / (1.0 + x_i * x_i);
        }

        // Combinar resultados parciales en la variable global pi
    #pragma omp atomic
        pi += sum_local * delta_x;
    }

    printf("Valor aproximado de pi: %.15f\n", pi);
    return 0;
}