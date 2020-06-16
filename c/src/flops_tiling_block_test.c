#include "flops_tiling_block_test.h"
#include "matrices.h"
#include "multiplication_tiling.h"
#include <stdio.h>
#include <time.h>
#include <math.h>

void flops_tiling_block_test() {
    printf("**************************************\n");
    printf("FLOPS TILING BLOCK TEST\n");
    printf("**************************************\n\n");


    double billion = 1000000000.0;
    int matrix_size = 2048;

    int block_size_start = 64;
    int block_size_end = matrix_size;
    int block_increase = 8;
    long double biggest_flops = 0.0;
    int optimal_block_size = 0;

    FILE *fp = fopen("out/flops_tiling_block_test.txt", "w");
    fprintf(fp, "{\"matrix_size\":%d,", matrix_size);

    printf("Find FLOPS with different block sizes with Matrix Size %d - Loop tiling:\n", matrix_size);

    generate_matrices(matrix_size);
    for (int block_size = block_size_start; block_size <= block_size_end; block_size += block_increase) {
        struct timespec start, end;
        clock_gettime(CLOCK_REALTIME, &start);
        multiplication_tiling_1_2(block_size);
        clock_gettime(CLOCK_REALTIME, &end);
        double current_time = ((end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec)/billion);
        long double current_flops = 2 * pow(matrix_size, 3) / current_time / billion;
        if (current_flops > biggest_flops) {
            biggest_flops = current_flops;
            optimal_block_size = block_size;
        }
        fprintf(fp, "\"%d\":%Lf,", block_size, current_flops);
        printf("Flops %Lf billion - Block size %d\n", current_flops, block_size);
    }
    free_matrices();

    printf("Best case: %Lf G FLOPS\n", biggest_flops);
    printf("Optimal block size: %d\n", optimal_block_size);

    fprintf(fp, "\"end\":0}");
    fclose(fp);

    printf("\n\n");
}
