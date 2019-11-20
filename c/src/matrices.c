#include "matrices.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// different size of the matrices
// flops per size of the matrices
// find the right matrix size by basic multiplication
// try float or double values
int A[256][256];
int B[256][256];
int C[256][256];
int a_row = 256;
int b_col = 256;
int b_row = 256;

void generate_matrices(void) {
    for (int i=0; i<a_row; i++) {
        for (int j=0; j<b_row; j++) {
            A[i][j] = rand()%100;
        }
    }
    for (int i=0; i<b_row; i++) {
        for (int j=0; j<b_col; j++) {
            B[i][j] = rand()%100;
        }
    }
}

void clear_result(void) {
    for (int i=0; i<a_row; i++) {
        for (int j=0; j<b_col; j++) {
            C[i][j] = 0;
        }
    }
}

void print_result(void) {
    printf("Result matrix:\n");
    for (int i=0; i<a_row; i++) {
        for(int j=0; j<b_col; j++) {
            printf("%d     ", C[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void print_A(void) {
    printf("Matrix A:\n");
    for (int i=0; i<a_row; i++) {
        for(int j=0; j<b_row; j++) {
            printf("%d     ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void print_B(void) {
    printf("Matrix B:\n");
    for (int i=0; i<b_row; i++) {
        for(int j=0; j<b_col; j++) {
            printf("%d     ", B[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
