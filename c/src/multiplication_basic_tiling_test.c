#include "multiplication_basic_tiling_test.h"
#include "matrices.h"
#include "multiplication_basic.h"
#include "multiplication_tiling.h"
#include <stdio.h>
#include <time.h>

void multiplication_basic_tiling_test(void) {
    printf("**************************************\n");
    printf("BASIC AND LOOP TILING TEST\n");
    printf("**************************************\n\n");


    int matrix_size = 1408;
    double billion = 1000000000.0;
    double million = 1000000.0;
    generate_matrices(matrix_size);
    printf("Comparing basic and loop tiling multiplication for matrix with size %d:\n\n", matrix_size);


    int number_of_tests_basic = 10;
    printf("Multiplication basic - %d calculations:\n", number_of_tests_basic);
    struct timespec start_basic, end_basic;
    clock_gettime(CLOCK_REALTIME, &start_basic);
    for (int i=0; i<number_of_tests_basic; i++) {
        multiplication_basic_2();
    }
    clock_gettime(CLOCK_REALTIME, &end_basic);
    double time_avr_basic = ((end_basic.tv_sec - start_basic.tv_sec)*billion + (end_basic.tv_nsec - start_basic.tv_nsec))/million / number_of_tests_basic;
    printf("Basic 2 - Time average is %f milliseconds\n\n", time_avr_basic);


    int number_of_tests_tiling = 2;
    int block_start = matrix_size / 4;
    int block_end = matrix_size / 2;
    int block_increase = 16;
    int optimal_block_size = 0;
    double shortest_time = 1000000.0;
    printf("Multiplication loop tiling - find optimal block size with %d calculations for each test:\n", number_of_tests_tiling);
    for (int current_block_size=block_start; current_block_size<=block_end; current_block_size+=block_increase) {
        for (int i=0; i<number_of_tests_tiling; i++) {
            struct timespec start, end;
            clock_gettime(CLOCK_REALTIME, &start);
            multiplication_tiling_1_2(current_block_size);
            clock_gettime(CLOCK_REALTIME, &end);
            double current_time = ((end.tv_sec - start.tv_sec)*billion + (end.tv_nsec - start.tv_nsec))/million;
            if (current_time < shortest_time) {
                shortest_time = current_time;
                optimal_block_size = current_block_size;
            }
            // printf("Loop tiling 1-2 with block size %d - Time is %f milliseconds\n", current_block_size, current_time);
        }
    }
    printf("Loop tiling 1-2 - Optimal block size %d - Shortest time is %f milliseconds\n", optimal_block_size, shortest_time);

    free_matrices();


    printf("\n\n");
}