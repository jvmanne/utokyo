#include "clock_test.h"
#include "multiplication_test.h"
#include <stdio.h>

int main(void) {
    printf("****************************\n");
    printf("EMPTY CODE TEST\n");
    printf("****************************\n\n");
    small_time_test();

    printf("\n\n****************************\n");
    printf("BASIC MULTIPLICATION TEST\n");
    printf("****************************\n\n");
    multiplication_test();

    return 0;
}