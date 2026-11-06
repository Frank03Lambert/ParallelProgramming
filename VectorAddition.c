#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

int main()
{
    omp_set_num_threads(5);
    
    
    int size = 100;
    int a[size];
    int b[size];
    int c[size];

    for (int i = 0; i < size; i++) {
        a[i] = rand() % 100;
        b[i] = rand() % 100;
        c[i] = 0;
    }

    #pragma omp parallel
    {
        #pragma omp for
        for (int i = 0; i < size; i++) {
            c[i] = a[i] + b[i];

            printf("Thread %d | %d: %d + %d = %d\n",
                   omp_get_thread_num(),
                   i, a[i], b[i], c[i]);
        }

        #pragma omp single
        printf("Done!\n");
    }

    return 0;
}