#include "matrices.h"

void multiplication_basic_1(void) {
    for (int i=0; i < a_row; i++) {
        for (int j=0; j < b_col; j++) {
            for (int k=0; k < b_row; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void multiplication_basic_2(void) {
    for (int i=0; i < a_row; i++) {
        for (int k=0; k < b_row; k++) {
            for (int j=0; j < b_col; j++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void multiplication_basic_3(void) {
    for (int j=0; j < b_col; j++) {
        for (int i=0; i < a_row; i++) {
            for (int k=0; k < b_row; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void multiplication_basic_4(void) {
    for (int j=0; j < b_col; j++) {
        for (int k=0; k < b_row; k++) {
            for (int i=0; i < a_row; i++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void multiplication_basic_5(void) {
    for (int k=0; k < b_row; k++) {
        for (int i=0; i < a_row; i++) {
            for (int j=0; j < b_col; j++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void multiplication_basic_6(void) {
    for (int k=0; k < b_row; k++) {
        for (int j=0; j < b_col; j++) {
            for (int i=0; i < a_row; i++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
