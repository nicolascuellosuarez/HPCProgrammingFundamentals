#include <stdio.h>
#include <omp.h>
#include <math.h>

double f(double x) {
    double e = exp(1.0);
    return pow(e,-(x*x));
}

double simpson_parallel(double a, double b, int n) {
    double h = (b - a) / n;
    double sum_odd = 0.0, sum_even = 0.0, result = 0.0;
    int i;

    #pragma omp parallel for reduction(+:sum_odd)
        for (i = 1; i <= n - 1; i += 2) {
            sum_odd += f(a + i * h);
        }

    #pragma omp parallel for reduction(+:sum_even)
        for (i = 2; i <= n - 2; i += 2) {
            sum_even += f(a + i * h);
        }

    result = (h / 3) * (f(a) + 4 * sum_odd + 2 * sum_even + f(b));

    return result;
}

int main() {
    double a = 1.0;
    double b = 8.0;
    int n = 1000000;

    double start_time = omp_get_wtime();
    double result = simpson_parallel(a, b, n);
    double end_time = omp_get_wtime();

    printf("Resultado de la integral: %.10f\n", result);
    printf("Tiempo de ejecución: %.6f segundos\n", end_time - start_time);

    return 0;
}