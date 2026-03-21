#include <stdio.h>

int main() {
    long long N = 100000000;
    double pi = 0.0;
    double delta_x = 1.0 / (double)N;

    for (long long i = 0; i < N; i++) {
        double x_i = (i + 0.5) * delta_x;
        pi += 4.0 / (1.0 + x_i * x_i);
    }

    pi *= delta_x;

    printf("El valor apróximado de pi: %.15f\n", pi);
    return 0;
}