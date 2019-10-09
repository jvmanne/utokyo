#include "multiplication_test.h"
#include "multiplication_basic.h"
#include <stdio.h>
#include <time.h>

int number_of_tests = 100000;

int A[4][3] = {
        {3, 6, 7},
        {5, -3, 0},
        {2, 7, 8},
        {1, 9, 2}
};
int B[3][2] = {
        {1, 1},
        {2, 1},
        {3, -3}
};
int C[4][2];
int a_row = sizeof(A)/ sizeof(A[0]);
int b_col = sizeof(B[0])/ sizeof(B[0][0]);
int b_row = sizeof(B)/ sizeof(B[0]);

void empty_result(void) {
    for (int i=0; i<a_row; i++) {
        for (int j=0; j<b_col; j++) {
            C[i][j] = 0;
        }
    }
}

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
    printf("Basic multiplication 1 - five calculations:\n");
    for (int i = 0; i<5; i++) {
        empty_result();
        struct timespec start, end;
        clock_gettime(CLOCK_REALTIME, &start);
        multiplication_basic_1();
        clock_gettime(CLOCK_REALTIME, &end);
        double time_spent = (end.tv_nsec - start.tv_nsec);
        printf("Time elapsed is %f nanoseconds\n", time_spent);
    }
    print_result();


    printf("\nBasic multiplication 1-6 - %d calculations:\n", number_of_tests);

    double total_time_1 = 0.0;
    for (int i=0; i<number_of_tests; i++) {
        empty_result();
        struct timespec start, end;
        clock_gettime(CLOCK_REALTIME, &start);
        multiplication_basic_1();
        clock_gettime(CLOCK_REALTIME, &end);
        total_time_1 += (end.tv_nsec - start.tv_nsec);
    }
    printf("Basic 1 - Time average is %f nanoseconds\n", total_time_1 / number_of_tests);

    double total_time_2 = 0.0;
    for (int i=0; i<number_of_tests; i++) {
        empty_result();
        struct timespec start, end;
        clock_gettime(CLOCK_REALTIME, &start);
        multiplication_basic_2();
        clock_gettime(CLOCK_REALTIME, &end);
        total_time_2 += (end.tv_nsec - start.tv_nsec);
    }
    printf("Basic 2 - Time average is %f nanoseconds\n", total_time_2 / number_of_tests);

    double total_time_3 = 0.0;
    for (int i=0; i<number_of_tests; i++) {
        empty_result();
        struct timespec start, end;
        clock_gettime(CLOCK_REALTIME, &start);
        multiplication_basic_3();
        clock_gettime(CLOCK_REALTIME, &end);
        total_time_3 += (end.tv_nsec - start.tv_nsec);
    }
    printf("Basic 3 - Time average is %f nanoseconds\n", total_time_3 / number_of_tests);

    double total_time_4 = 0.0;
    for (int i=0; i<number_of_tests; i++) {
        empty_result();
        struct timespec start, end;
        clock_gettime(CLOCK_REALTIME, &start);
        multiplication_basic_4();
        clock_gettime(CLOCK_REALTIME, &end);
        total_time_4 += (end.tv_nsec - start.tv_nsec);
    }
    printf("Basic 4 - Time average is %f nanoseconds\n", total_time_4 / number_of_tests);

    double total_time_5 = 0.0;
    for (int i=0; i<number_of_tests; i++) {
        empty_result();
        struct timespec start, end;
        clock_gettime(CLOCK_REALTIME, &start);
        multiplication_basic_5();
        clock_gettime(CLOCK_REALTIME, &end);
        total_time_5 += (end.tv_nsec - start.tv_nsec);
    }
    printf("Basic 5 - Time average is %f nanoseconds\n", total_time_5 / number_of_tests);

    double total_time_6 = 0.0;
    for (int i=0; i<number_of_tests; i++) {
        empty_result();
        struct timespec start, end;
        clock_gettime(CLOCK_REALTIME, &start);
        multiplication_basic_6();
        clock_gettime(CLOCK_REALTIME, &end);
        total_time_6 += (end.tv_nsec - start.tv_nsec);
    }
    printf("Basic 6 - Time average is %f nanoseconds\n", total_time_6 / number_of_tests);
}
