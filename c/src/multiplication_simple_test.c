#include "multiplication_simple_test.h"
#include "matrices.h"
#include "multiplication_basic.h"
#include "multiplication_tiling.h"
#include <stdio.h>

void multiplication_simple_test(void) {
    printf("**************************************\n");
    printf("MULTIPLICATION SIMPLE TEST\n");
    printf("**************************************\n\n");

    int matrix_size;
    int block_size;

    matrix_size = 5;
    block_size = 2;
    check_multiplication(matrix_size, block_size);

    matrix_size = 4;
    block_size = 3;
    check_multiplication(matrix_size, block_size);

    matrix_size = 6;
    block_size = 6;
    check_multiplication(matrix_size, block_size);


    printf("\n");
}

void check_multiplication(int matrix_size, int block_size) {
    printf("Checking multiplication with matrix size %d and block size %d:\n\n", matrix_size, block_size);

    generate_matrices(matrix_size);
    print_A();
    print_B();

    printf("Testing basic multiplication:\n");
    multiplication_basic_1();
    print_result();
    clear_result();

    printf("Testing loop tiling multiplication:\n");
    multiplication_tiling_1_1(block_size);
    print_result();
    clear_result();

    free_matrices();

    printf("\n");
}
