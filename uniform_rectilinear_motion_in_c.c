#include <stdio.h>
#include <omp.h>

int main() {
    double aceleracion = 9.8;
    int T = 100000;
    double dt = 1.0;

    double v[11];
    double x[11];

    v[0] = 0.0;
    x[0] = 0.0;

    #pragma omp parallel
    {
        #pragma omp single
        {
            int t = 1;
            for (t = 1; t < T; t++) {
                #pragma omp task depend(in: x[t-1], v[t-1]) depend(out: x[t], v[t])
                {
                    v[t] = v[t-1] + aceleracion * dt;
                    x[t] = x[t-1] + v[t-1] * dt + 0.5 * aceleracion * dt * dt;

                    printf("Hilo %d calculó t=%d: Pos=%.2f, Vel=%.2f\n",
                           omp_get_thread_num(), t, x[t], v[t]);
                }
            }
        }
    }
}