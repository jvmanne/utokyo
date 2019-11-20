#include "multiplication_basic_test.h"
#include "matrices.h"
#include "multiplication_basic.h"
#include <stdio.h>
#include <time.h>


// bigger matrices
// flops
// random matrices

void multiplication_basic_test(void) {
    printf("**************************************\n");
    printf("MULTIPLICATION BASIC TEST\n");
    printf("**************************************\n\n");


    int number_of_tests = 10;
    double billion = 1000000000.0;
    double million = 1000000.0;
    generate_matrices();

    multiplication_basic_1();

    printf("Multiplication basic 1 - five calculations:\n");
    for (int i = 0; i<5; i++) {
        struct timespec start, end;
        clock_gettime(CLOCK_REALTIME, &start);
        multiplication_basic_1();
        clock_gettime(CLOCK_REALTIME, &end);
        double time_spent = ((end.tv_sec - start.tv_sec)*billion + (end.tv_nsec - start.tv_nsec))/million;
        printf("Time elapsed is %f milliseconds\n", time_spent);
    }


    printf("\nMultiplication basic 1-6 - %d calculations:\n", number_of_tests);

    struct timespec start1, end1;
    clock_gettime(CLOCK_REALTIME, &start1);
    for (int i=0; i<number_of_tests; i++) {
        multiplication_basic_1();
    }
    clock_gettime(CLOCK_REALTIME, &end1);
    double time_avr_1 = ((end1.tv_sec - start1.tv_sec)*billion + (end1.tv_nsec - start1.tv_nsec))/million / number_of_tests;
    printf("Basic 1 - Time average is %f milliseconds\n", time_avr_1);

    struct timespec start2, end2;
    clock_gettime(CLOCK_REALTIME, &start2);
    for (int i=0; i<number_of_tests; i++) {
        multiplication_basic_2();
    }
    clock_gettime(CLOCK_REALTIME, &end2);
    double time_avr_2 = ((end2.tv_sec - start2.tv_sec)*billion + (end2.tv_nsec - start2.tv_nsec))/million / number_of_tests;
    printf("Basic 2 - Time average is %f milliseconds\n", time_avr_2);

    struct timespec start3, end3;
    clock_gettime(CLOCK_REALTIME, &start3);
    for (int i=0; i<number_of_tests; i++) {
        multiplication_basic_3();
    }
    clock_gettime(CLOCK_REALTIME, &end3);
    double time_avr_3 = ((end3.tv_sec - start3.tv_sec)*billion + (end3.tv_nsec - start3.tv_nsec))/million / number_of_tests;
    printf("Basic 3 - Time average is %f milliseconds\n", time_avr_3);

    struct timespec start4, end4;
    clock_gettime(CLOCK_REALTIME, &start4);
    for (int i=0; i<number_of_tests; i++) {
        multiplication_basic_4();
    }
    clock_gettime(CLOCK_REALTIME, &end4);
    double time_avr_4 = ((end4.tv_sec - start4.tv_sec)*billion + (end4.tv_nsec - start4.tv_nsec))/million / number_of_tests;
    printf("Basic 4 - Time average is %f milliseconds\n", time_avr_4);

    struct timespec start5, end5;
    clock_gettime(CLOCK_REALTIME, &start5);
    for (int i=0; i<number_of_tests; i++) {
        multiplication_basic_5();
    }
    clock_gettime(CLOCK_REALTIME, &end5);
    double time_avr_5 = ((end5.tv_sec - start5.tv_sec)*billion + (end5.tv_nsec - start5.tv_nsec))/million / number_of_tests;
    printf("Basic 5 - Time average is %f milliseconds\n", time_avr_5);

    struct timespec start6, end6;
    clock_gettime(CLOCK_REALTIME, &start6);
    for (int i=0; i<number_of_tests; i++) {
        multiplication_basic_6();
    }
    clock_gettime(CLOCK_REALTIME, &end6);
    double time_avr_6 = ((end6.tv_sec - start6.tv_sec)*billion + (end6.tv_nsec - start6.tv_nsec))/million / number_of_tests;
    printf("Basic 6 - Time average is %f milliseconds\n", time_avr_6);


    printf("\n\n");
}
