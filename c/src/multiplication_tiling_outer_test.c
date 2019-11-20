#include "multiplication_tiling_outer_test.h"
#include "matrices.h"
#include "multiplication_tiling.h"
#include <stdio.h>
#include <time.h>
#include <math.h>

void multiplication_tiling_outer_test() {
    printf("**************************************\n");
    printf("MULTIPLICATION LOOP TILING OUTER TEST\n");
    printf("**************************************\n\n");

    int number_of_tests = 3;
    // take minimum of the three
    double billion = 1000000000.0;
    double million = 1000000.0;
    int block_start = 1;
    int block_end = 128;
    int block_increase = 2;
    generate_matrices();


    printf("Multiplication loop tiling 1-2 to 6-2 - find optimal block size with %d calculations for each test:\n", number_of_tests);

    int optimal_block_size_1 = 0;
    double shortest_time_avr_1 = 1000000.0;
    for (int current_block_size=block_start; current_block_size<=block_end; current_block_size+=block_increase) {
        struct timespec start1, end1;
        clock_gettime(CLOCK_REALTIME, &start1);
        for (int i=0; i<number_of_tests; i++) {
            multiplication_tiling_1_2(current_block_size);
        }
        clock_gettime(CLOCK_REALTIME, &end1);
        double current_time_avr = ((end1.tv_sec - start1.tv_sec)*billion + (end1.tv_nsec - start1.tv_nsec))/million / number_of_tests;
        if (current_time_avr < shortest_time_avr_1) {
            shortest_time_avr_1 = current_time_avr;
            optimal_block_size_1 = current_block_size;
        }
        // printf("Loop tiling 1-2 with block size %d - Time average is %f milliseconds\n", current_block_size, current_time_avr);
    }
    printf("Loop tiling 1-2 - Optimal block size %d - Shortest time average is %f milliseconds\n", optimal_block_size_1, shortest_time_avr_1);

    int optimal_block_size_2 = 0;
    double shortest_time_avr_2 = 1000000.0;
    for (int current_block_size=block_start; current_block_size<=block_end; current_block_size+=block_increase) {
        struct timespec start2, end2;
        clock_gettime(CLOCK_REALTIME, &start2);
        for (int i=0; i<number_of_tests; i++) {
            multiplication_tiling_2_2(current_block_size);
        }
        clock_gettime(CLOCK_REALTIME, &end2);
        double current_time_avr = ((end2.tv_sec - start2.tv_sec)*billion + (end2.tv_nsec - start2.tv_nsec))/million / number_of_tests;
        if (current_time_avr < shortest_time_avr_2) {
            shortest_time_avr_2 = current_time_avr;
            optimal_block_size_2 = current_block_size;
        }
        // printf("Loop tiling 2-2 with block size %d - Time average is %f milliseconds\n", current_block_size, current_time_avr);
    }
    printf("Loop tiling 2-2 - Optimal block size %d - Shortest time average is %f milliseconds\n", optimal_block_size_2, shortest_time_avr_2);

    int optimal_block_size_3 = 0;
    double shortest_time_avr_3 = 1000000.0;
    for (int current_block_size=block_start; current_block_size<=block_end; current_block_size+=block_increase) {
        struct timespec start3, end3;
        clock_gettime(CLOCK_REALTIME, &start3);
        for (int i=0; i<number_of_tests; i++) {
            multiplication_tiling_3_2(current_block_size);
        }
        clock_gettime(CLOCK_REALTIME, &end3);
        double current_time_avr = ((end3.tv_sec - start3.tv_sec)*billion + (end3.tv_nsec - start3.tv_nsec))/million / number_of_tests;
        if (current_time_avr < shortest_time_avr_3) {
            shortest_time_avr_3 = current_time_avr;
            optimal_block_size_3 = current_block_size;
        }
        // printf("Loop tiling 3-2 with block size %d - Time average is %f milliseconds\n", current_block_size, current_time_avr);
    }
    printf("Loop tiling 3-2 - Optimal block size %d - Shortest time average is %f milliseconds\n", optimal_block_size_3, shortest_time_avr_3);

    int optimal_block_size_4 = 0;
    double shortest_time_avr_4 = 1000000.0;
    for (int current_block_size=block_start; current_block_size<=block_end; current_block_size+=block_increase) {
        struct timespec start4, end4;
        clock_gettime(CLOCK_REALTIME, &start4);
        for (int i=0; i<number_of_tests; i++) {
            multiplication_tiling_4_2(current_block_size);
        }
        clock_gettime(CLOCK_REALTIME, &end4);
        double current_time_avr = ((end4.tv_sec - start4.tv_sec)*billion + (end4.tv_nsec - start4.tv_nsec))/million / number_of_tests;
        if (current_time_avr < shortest_time_avr_4) {
            shortest_time_avr_4 = current_time_avr;
            optimal_block_size_4 = current_block_size;
        }
        // printf("Loop tiling 4-2 with block size %d - Time average is %f milliseconds\n", current_block_size, current_time_avr);
    }
    printf("Loop tiling 4-2 - Optimal block size %d - Shortest time average is %f milliseconds\n", optimal_block_size_4, shortest_time_avr_4);

    int optimal_block_size_5 = 0;
    double shortest_time_avr_5 = 1000000.0;
    for (int current_block_size=block_start; current_block_size<=block_end; current_block_size+=block_increase) {
        struct timespec start5, end5;
        clock_gettime(CLOCK_REALTIME, &start5);
        for (int i=0; i<number_of_tests; i++) {
            multiplication_tiling_5_2(current_block_size);
        }
        clock_gettime(CLOCK_REALTIME, &end5);
        double current_time_avr = ((end5.tv_sec - start5.tv_sec)*billion + (end5.tv_nsec - start5.tv_nsec))/million / number_of_tests;
        if (current_time_avr < shortest_time_avr_5) {
            shortest_time_avr_5 = current_time_avr;
            optimal_block_size_5 = current_block_size;
        }
        // printf("Loop tiling 5-2 with block size %d - Time average is %f milliseconds\n", current_block_size, current_time_avr);
    }
    printf("Loop tiling 5-2 - Optimal block size %d - Shortest time average is %f milliseconds\n", optimal_block_size_5, shortest_time_avr_5);

    int optimal_block_size_6 = 0;
    double shortest_time_avr_6 = 1000000.0;
    for (int current_block_size=block_start; current_block_size<=block_end; current_block_size+=block_increase) {
        struct timespec start6, end6;
        clock_gettime(CLOCK_REALTIME, &start6);
        for (int i=0; i<number_of_tests; i++) {
            multiplication_tiling_6_2(current_block_size);
        }
        clock_gettime(CLOCK_REALTIME, &end6);
        double current_time_avr = ((end6.tv_sec - start6.tv_sec)*billion + (end6.tv_nsec - start6.tv_nsec))/million / number_of_tests;
        if (current_time_avr < shortest_time_avr_6) {
            shortest_time_avr_6 = current_time_avr;
            optimal_block_size_6 = current_block_size;
        }
        // printf("Loop tiling 5-2 with block size %d - Time average is %f milliseconds\n", current_block_size, current_time_avr);
    }
    printf("Loop tiling 5-2 - Optimal block size %d - Shortest time average is %f milliseconds\n", optimal_block_size_6, shortest_time_avr_6);


    printf("\n\n");
}
