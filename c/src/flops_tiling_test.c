#include "flops_tiling_test.h"
#include "matrices.h"
#include "multiplication_tiling.h"
#include <stdio.h>
#include <time.h>
#include <math.h>

void flops_tiling_test() {
    printf("**************************************\n");
    printf("FLOPS TILING TEST\n");
    printf("**************************************\n\n");


    double billion = 1000000000.0;
    int matrix_size_start = 64;
    int matrix_size_end = 2048;
    int matrix_size_increase = 8;

    long double biggest_flops = 0.0;
    int optimal_matrix_size = 0;
    int optimal_block_size = 0;

    FILE *fp = fopen("out/flops_tiling_test.txt", "w");
    fprintf(fp, "{");

    printf("Find FLOPS with different matrix sizes and block sizes - Loop tiling:\n");

    for (int matrix_size=matrix_size_start; matrix_size<=matrix_size_end; matrix_size+=matrix_size_increase) {
        generate_matrices(matrix_size);

        int block_size_start = matrix_size_start / 2;
        int block_size_end = matrix_size / 2;
        int block_increase = 8;
        long double sub_biggest_flops = 0.0;
        int sub_optimal_block_size = 0;

        for (int block_size = block_size_start; block_size <= block_size_end; block_size += block_increase) {
            struct timespec start, end;
            clock_gettime(CLOCK_REALTIME, &start);
            multiplication_tiling_1_2(block_size);
            clock_gettime(CLOCK_REALTIME, &end);
            double current_time = ((end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec)/billion);
            long double current_flops = 2 * pow(matrix_size, 3) / current_time / billion;
            if (current_flops > biggest_flops) {
                biggest_flops = current_flops;
                optimal_matrix_size = matrix_size;
                optimal_block_size = block_size;
            }
            if (current_flops > sub_biggest_flops) {
                sub_biggest_flops = current_flops;
                sub_optimal_block_size = block_size;
            }
            // printf("Flops %Lf billion - Matrix size %d - Block size %d\n", current_flops, matrix_size, block_size);
        }
        fprintf(fp, "\"%d\":{\"flops\":%Lf,\"opt_block_size\":%d},", matrix_size, sub_biggest_flops, sub_optimal_block_size);
        printf("%Lf G FLOPS - Matrix size %d - Optimal block size %d\n", sub_biggest_flops, matrix_size, sub_optimal_block_size);

        free_matrices();
    }
    printf("Best case: %Lf G FLOPS - Matrix size %d - Optimal block size %d\n", biggest_flops, optimal_matrix_size, optimal_block_size);

    fprintf(fp, "\"end\":0}");
    fclose(fp);

    printf("\n\n");
}
