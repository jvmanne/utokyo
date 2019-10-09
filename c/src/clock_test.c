#include "clock_test.h"
#include <stdio.h>
#include <time.h>

void small_time_test(void) {
    int number_of_tests = 100000;

    printf("Empty code - five calculations:\n");
    for (int i=0; i<5; i++) {
        struct timespec start, end;
        clock_gettime(CLOCK_REALTIME, &start);
        clock_gettime(CLOCK_REALTIME, &end);
        double time_spent = (end.tv_nsec - start.tv_nsec);
        printf("Time elapsed is %f nanoseconds\n", time_spent);
    }

    printf("\nEmpty code - %d calculations:\n", number_of_tests);

    double total_time = 0.0;
    double shortest_time = 1000000.0;
    double longest_time = 0.0;
    for (int i=0; i<number_of_tests; i++) {
        struct timespec start, end;
        clock_gettime(CLOCK_REALTIME, &start);
        clock_gettime(CLOCK_REALTIME, &end);
        double current_time = (end.tv_nsec - start.tv_nsec);
        shortest_time = current_time < shortest_time ? current_time : shortest_time;
        longest_time = current_time > longest_time ? current_time : longest_time;
        total_time += current_time;
    }
    printf("Time average is %f nanoseconds\n", total_time / number_of_tests);
    printf("Shortest time is %f nanoseconds\n", shortest_time);
    printf("Longest time is %f nanoseconds\n", longest_time);
}
