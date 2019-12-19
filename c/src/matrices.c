#include "matrices.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float **A;
float **B;
float **C;
int a_row;
int b_col;
int b_row;

void generate_matrices(int size) {
    a_row = size;
    b_col = size;
    b_row = size;

    A = malloc(a_row * sizeof(float *));
    for (int i=0; i<a_row; i++) {
        A[i] = malloc(b_row * sizeof(float *));
    }
    B = malloc(b_row * sizeof(float *));
    for (int i=0; i<b_row; i++) {
        B[i] = malloc(b_col * sizeof(float *));
    }
    C = malloc(a_row * sizeof(float *));
    for (int i=0; i<a_row; i++) {
        C[i] = malloc(b_col * sizeof(float *));
    }

    for (int i=0; i<a_row; i++) {
        for (int j=0; j<b_row; j++) {
            A[i][j] = ((float) rand()/(float) (RAND_MAX)) * 1;
        }
    }
    for (int i=0; i<b_row; i++) {
        for (int j=0; j<b_col; j++) {
            B[i][j] = ((float) rand()/(float) (RAND_MAX)) * 1;
        }
    }
    for (int i=0; i<a_row; i++) {
        for (int j=0; j<b_col; j++) {
            C[i][j] = 0.0;
        }
    }
}

void free_matrices() {
    for (int i=0; i<a_row; i++) {
        free(A[i]);
    }
    for (int i=0; i<b_row; i++) {
        free(B[i]);
    }
    for (int i=0; i<a_row; i++) {
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);
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
            printf("%f     ", C[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void print_A(void) {
    printf("Matrix A:\n");
    for (int i=0; i<a_row; i++) {
        for(int j=0; j<b_row; j++) {
            printf("%f     ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void print_B(void) {
    printf("Matrix B:\n");
    for (int i=0; i<b_row; i++) {
        for(int j=0; j<b_col; j++) {
            printf("%f     ", B[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
