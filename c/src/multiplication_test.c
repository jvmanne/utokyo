#include "multiplication_test.h"
#include "matrices.h"
#include "multiplication_basic.h"
#include <stdio.h>
#include <time.h>

int number_of_tests = 100000;
// bigger matrices
// flops
// random matrices

void print_result(void) {
    printf("Result matrix:\n");
    for (int i=0; i<a_row; i++)
    {
        for(int j=0; j<b_col; j++)
        {
            printf("%d     ", C[i][j]);
        }
        printf("\n");
    }
}

void multiplication_test(void) {
    multiplication_basic_1();
    print_result();

    printf("Basic multiplication 1 - five calculations:\n");
    for (int i = 0; i<5; i++) {
        struct timespec start, end;
        clock_gettime(CLOCK_REALTIME, &start);
        multiplication_basic_1();
        clock_gettime(CLOCK_REALTIME, &end);
        double time_spent = (end.tv_nsec - start.tv_nsec);
        printf("Time elapsed is %f nanoseconds\n", time_spent);
    }


    printf("\nBasic multiplication 1-6 - %d calculations:\n", number_of_tests);

    struct timespec start1, end1;
    clock_gettime(CLOCK_REALTIME, &start1);
    for (int i=0; i<number_of_tests; i++) {
        multiplication_basic_1();
    }
    clock_gettime(CLOCK_REALTIME, &end1);
    printf("Basic 1 - Time average is %ld nanoseconds\n", (end1.tv_nsec - start1.tv_nsec) / number_of_tests);

    struct timespec start2, end2;
    clock_gettime(CLOCK_REALTIME, &start2);
    for (int i=0; i<number_of_tests; i++) {
        multiplication_basic_2();
    }
    clock_gettime(CLOCK_REALTIME, &end2);
    printf("Basic 2 - Time average is %ld nanoseconds\n", (end2.tv_nsec - start2.tv_nsec) / number_of_tests);

    struct timespec start3, end3;
    clock_gettime(CLOCK_REALTIME, &start3);
    for (int i=0; i<number_of_tests; i++) {
        multiplication_basic_3();
    }
    clock_gettime(CLOCK_REALTIME, &end3);
    printf("Basic 3 - Time average is %ld nanoseconds\n", (end3.tv_nsec - start3.tv_nsec) / number_of_tests);

    struct timespec start4, end4;
    clock_gettime(CLOCK_REALTIME, &start4);
    for (int i=0; i<number_of_tests; i++) {
        multiplication_basic_4();
    }
    clock_gettime(CLOCK_REALTIME, &end4);
    printf("Basic 4 - Time average is %ld nanoseconds\n", (end4.tv_nsec - start4.tv_nsec) / number_of_tests);

    struct timespec start5, end5;
    clock_gettime(CLOCK_REALTIME, &start5);
    for (int i=0; i<number_of_tests; i++) {
        multiplication_basic_5();
    }
    clock_gettime(CLOCK_REALTIME, &end5);
    printf("Basic 5 - Time average is %ld nanoseconds\n", (end5.tv_nsec - start5.tv_nsec) / number_of_tests);

    struct timespec start6, end6;
    clock_gettime(CLOCK_REALTIME, &start6);
    for (int i=0; i<number_of_tests; i++) {
        multiplication_basic_6();
    }
    clock_gettime(CLOCK_REALTIME, &end6);
    printf("Basic 6 - Time average is %ld nanoseconds\n", (end6.tv_nsec - start6.tv_nsec) / number_of_tests);
}
