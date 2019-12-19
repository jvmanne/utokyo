#include "multiplication_tiling_outer_test.h"
#include "matrices.h"
#include "multiplication_tiling.h"
#include <stdio.h>
#include <time.h>
#include <math.h>

void multiplication_tiling_outer_test(void) {
    printf("**************************************\n");
    printf("MULTIPLICATION LOOP TILING OUTER TEST\n");
    printf("**************************************\n\n");

    int matrix_size = 256;
    int number_of_tests = 3;
    double billion = 1000000000.0;
    double million = 1000000.0;
    int block_start = 1;
    int block_end = matrix_size;
    int block_increase = 1;
    generate_matrices(matrix_size);


    printf("Multiplication loop tiling 1-2 to 6-2 - find optimal block size with %d calculations for each test:\n", number_of_tests);

    int optimal_block_size_1 = 0;
    double shortest_time_1 = 1000000.0;
    for (int current_block_size=block_start; current_block_size<=block_end; current_block_size+=block_increase) {
        for (int i=0; i<number_of_tests; i++) {
            struct timespec start, end;
            clock_gettime(CLOCK_REALTIME, &start);
            multiplication_tiling_1_2(current_block_size);
            clock_gettime(CLOCK_REALTIME, &end);
            double current_time = ((end.tv_sec - start.tv_sec)*billion + (end.tv_nsec - start.tv_nsec))/million;
            if (current_time < shortest_time_1) {
                shortest_time_1 = current_time;
                optimal_block_size_1 = current_block_size;
            }
            // printf("Loop tiling 1-2 with block size %d - Time is %f milliseconds\n", current_block_size, current_time);
        }
    }
    printf("Loop tiling 1-2 - Optimal block size %d - Shortest time is %f milliseconds\n", optimal_block_size_1, shortest_time_1);

    int optimal_block_size_2 = 0;
    double shortest_time_2 = 1000000.0;
    for (int current_block_size=block_start; current_block_size<=block_end; current_block_size+=block_increase) {
        for (int i=0; i<number_of_tests; i++) {
            struct timespec start, end;
            clock_gettime(CLOCK_REALTIME, &start);
            multiplication_tiling_2_2(current_block_size);
            clock_gettime(CLOCK_REALTIME, &end);
            double current_time = ((end.tv_sec - start.tv_sec)*billion + (end.tv_nsec - start.tv_nsec))/million;
            if (current_time < shortest_time_2) {
                shortest_time_2 = current_time;
                optimal_block_size_2 = current_block_size;
            }
            // printf("Loop tiling 2-2 with block size %d - Time is %f milliseconds\n", current_block_size, current_time);
        }
    }
    printf("Loop tiling 2-2 - Optimal block size %d - Shortest time is %f milliseconds\n", optimal_block_size_2, shortest_time_2);

    int optimal_block_size_3 = 0;
    double shortest_time_3 = 1000000.0;
    for (int current_block_size=block_start; current_block_size<=block_end; current_block_size+=block_increase) {
        for (int i=0; i<number_of_tests; i++) {
            struct timespec start, end;
            clock_gettime(CLOCK_REALTIME, &start);
            multiplication_tiling_3_2(current_block_size);
            clock_gettime(CLOCK_REALTIME, &end);
            double current_time = ((end.tv_sec - start.tv_sec)*billion + (end.tv_nsec - start.tv_nsec))/million;
            if (current_time < shortest_time_3) {
                shortest_time_3 = current_time;
                optimal_block_size_3 = current_block_size;
            }
            // printf("Loop tiling 3-2 with block size %d - Time is %f milliseconds\n", current_block_size, current_time);
        }
    }
    printf("Loop tiling 3-2 - Optimal block size %d - Shortest time is %f milliseconds\n", optimal_block_size_3, shortest_time_3);

    int optimal_block_size_4 = 0;
    double shortest_time_4 = 1000000.0;
    for (int current_block_size=block_start; current_block_size<=block_end; current_block_size+=block_increase) {
        for (int i=0; i<number_of_tests; i++) {
            struct timespec start, end;
            clock_gettime(CLOCK_REALTIME, &start);
            multiplication_tiling_4_2(current_block_size);
            clock_gettime(CLOCK_REALTIME, &end);
            double current_time = ((end.tv_sec - start.tv_sec)*billion + (end.tv_nsec - start.tv_nsec))/million;
            if (current_time < shortest_time_4) {
                shortest_time_4 = current_time;
                optimal_block_size_4 = current_block_size;
            }
            // printf("Loop tiling 4-2 with block size %d - Time is %f milliseconds\n", current_block_size, current_time);
        }
    }
    printf("Loop tiling 4-2 - Optimal block size %d - Shortest time is %f milliseconds\n", optimal_block_size_4, shortest_time_4);

    int optimal_block_size_5 = 0;
    double shortest_time_5 = 1000000.0;
    for (int current_block_size=block_start; current_block_size<=block_end; current_block_size+=block_increase) {
        for (int i=0; i<number_of_tests; i++) {
            struct timespec start, end;
            clock_gettime(CLOCK_REALTIME, &start);
            multiplication_tiling_5_2(current_block_size);
            clock_gettime(CLOCK_REALTIME, &end);
            double current_time = ((end.tv_sec - start.tv_sec)*billion + (end.tv_nsec - start.tv_nsec))/million;
            if (current_time < shortest_time_5) {
                shortest_time_5 = current_time;
                optimal_block_size_5 = current_block_size;
            }
            // printf("Loop tiling 5-2 with block size %d - Time is %f milliseconds\n", current_block_size, current_time);
        }
    }
    printf("Loop tiling 5-2 - Optimal block size %d - Shortest time is %f milliseconds\n", optimal_block_size_5, shortest_time_5);

    int optimal_block_size_6 = 0;
    double shortest_time_6 = 1000000.0;
    for (int current_block_size=block_start; current_block_size<=block_end; current_block_size+=block_increase) {
        for (int i=0; i<number_of_tests; i++) {
            struct timespec start, end;
            clock_gettime(CLOCK_REALTIME, &start);
            multiplication_tiling_6_2(current_block_size);
            clock_gettime(CLOCK_REALTIME, &end);
            double current_time = ((end.tv_sec - start.tv_sec)*billion + (end.tv_nsec - start.tv_nsec))/million;
            if (current_time < shortest_time_6) {
                shortest_time_6 = current_time;
                optimal_block_size_6 = current_block_size;
            }
            // printf("Loop tiling 6-2 with block size %d - Time is %f milliseconds\n", current_block_size, current_time);
        }
    }
    printf("Loop tiling 6-2 - Optimal block size %d - Shortest time is %f milliseconds\n", optimal_block_size_6, shortest_time_6);

    free_matrices();


    printf("\n\n");
}
