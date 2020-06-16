#include "flops_basic_test.h"
#include "matrices.h"
#include "multiplication_basic.h"
#include <stdio.h>
#include <time.h>
#include <math.h>

void flops_basic_test() {
    printf("**************************************\n");
    printf("FLOPS BASIC TEST\n");
    printf("**************************************\n\n");


    double billion = 1000000000.0;
    int matrix_size_start = 64;
    int matrix_size_end = 2048;
    int matrix_size_increase = 8;

    long double biggest_flops = 0.0;
    int optimal_matrix_size = 0;

    FILE *fp = fopen("out/flops_basic_test.txt", "w");
    fprintf(fp, "{");

    printf("Find FLOPS with different matrix sizes - Basic multiplication:\n");

    for (int matrix_size=matrix_size_start; matrix_size<=matrix_size_end; matrix_size+=matrix_size_increase) {
        generate_matrices(matrix_size);

        struct timespec start, end;
        clock_gettime(CLOCK_REALTIME, &start);
        multiplication_basic_2();
        clock_gettime(CLOCK_REALTIME, &end);
        double current_time = ((end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec)/billion);
        long double current_flops = 2 * pow(matrix_size, 3) / current_time / billion;
        if (current_flops > biggest_flops) {
            biggest_flops = current_flops;
            optimal_matrix_size = matrix_size;
        }
        fprintf(fp, "\"%d\":%Lf,", matrix_size, current_flops);
        printf("%Lf G FLOPS - Matrix size %d\n", current_flops, matrix_size);

        free_matrices();
    }
    printf("Best case: %Lf G FLOPS - Matrix size %d\n", biggest_flops, optimal_matrix_size);

    fprintf(fp, "\"end\":0}");
    fclose(fp);

    printf("\n\n");
}
