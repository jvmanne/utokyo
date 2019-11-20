#include "multiplication_tiling.h"
#include "matrices.h"

void multiplication_tiling_1_1(int block_size) {
    for (int ii=0; ii<a_row; ii+=block_size) {
        for (int jj=0; jj<b_col; jj+=block_size) {
            for (int kk=0; kk<b_row; kk+=block_size) {
                for (int i=ii; i<MIN(ii+block_size, a_row); i++) {
                    for (int j=jj; j<MIN(jj+block_size, b_col); j++) {
                        for (int k=kk; k<MIN(kk+block_size, b_row); k++) {
                            C[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }
            }
        }
    }
}

void multiplication_tiling_1_2(int block_size) {
    for (int ii=0; ii<a_row; ii+=block_size) {
        for (int jj=0; jj<b_col; jj+=block_size) {
            for (int kk=0; kk<b_row; kk+=block_size) {
                for (int i=ii; i<MIN(ii+block_size, a_row); i++) {
                    for (int k=kk; k<MIN(kk+block_size, b_row); k++) {
                        for (int j=jj; j<MIN(jj+block_size, b_col); j++) {
                            C[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }
            }
        }
    }
}

void multiplication_tiling_1_3(int block_size) {
    for (int ii=0; ii<a_row; ii+=block_size) {
        for (int jj=0; jj<b_col; jj+=block_size) {
            for (int kk=0; kk<b_row; kk+=block_size) {
                for (int j=jj; j<MIN(jj+block_size, b_col); j++) {
                    for (int i=ii; i<MIN(ii+block_size, a_row); i++) {
                        for (int k=kk; k<MIN(kk+block_size, b_row); k++) {
                            C[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }
            }
        }
    }
}

void multiplication_tiling_1_4(int block_size) {
    for (int ii=0; ii<a_row; ii+=block_size) {
        for (int jj=0; jj<b_col; jj+=block_size) {
            for (int kk=0; kk<b_row; kk+=block_size) {
                for (int j=jj; j<MIN(jj+block_size, b_col); j++) {
                    for (int k=kk; k<MIN(kk+block_size, b_row); k++) {
                        for (int i=ii; i<MIN(ii+block_size, a_row); i++) {
                            C[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }
            }
        }
    }
}

void multiplication_tiling_1_5(int block_size) {
    for (int ii=0; ii<a_row; ii+=block_size) {
        for (int jj=0; jj<b_col; jj+=block_size) {
            for (int kk=0; kk<b_row; kk+=block_size) {
                for (int k=kk; k<MIN(kk+block_size, b_row); k++) {
                    for (int i=ii; i<MIN(ii+block_size, a_row); i++) {
                        for (int j=jj; j<MIN(jj+block_size, b_col); j++) {
                            C[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }
            }
        }
    }
}

void multiplication_tiling_1_6(int block_size) {
    for (int ii=0; ii<a_row; ii+=block_size) {
        for (int jj=0; jj<b_col; jj+=block_size) {
            for (int kk=0; kk<b_row; kk+=block_size) {
                for (int k=kk; k<MIN(kk+block_size, b_row); k++) {
                    for (int j=jj; j<MIN(jj+block_size, b_col); j++) {
                        for (int i=ii; i<MIN(ii+block_size, a_row); i++) {
                            C[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }
            }
        }
    }
}


void multiplication_tiling_2_2(int block_size) {
    for (int ii=0; ii<a_row; ii+=block_size) {
        for (int kk=0; kk<b_row; kk+=block_size) {
            for (int jj=0; jj<b_col; jj+=block_size) {
                for (int i=ii; i<MIN(ii+block_size, a_row); i++) {
                    for (int k=kk; k<MIN(kk+block_size, b_row); k++) {
                        for (int j=jj; j<MIN(jj+block_size, b_col); j++) {
                            C[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }
            }
        }
    }
}

void multiplication_tiling_3_2(int block_size) {
    for (int jj=0; jj<b_col; jj+=block_size) {
        for (int ii=0; ii<a_row; ii+=block_size) {
            for (int kk=0; kk<b_row; kk+=block_size) {
                for (int i=ii; i<MIN(ii+block_size, a_row); i++) {
                    for (int k=kk; k<MIN(kk+block_size, b_row); k++) {
                        for (int j=jj; j<MIN(jj+block_size, b_col); j++) {
                            C[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }
            }
        }
    }
}

void multiplication_tiling_4_2(int block_size) {
    for (int jj=0; jj<b_col; jj+=block_size) {
        for (int kk=0; kk<b_row; kk+=block_size) {
            for (int ii=0; ii<a_row; ii+=block_size) {
                for (int i=ii; i<MIN(ii+block_size, a_row); i++) {
                    for (int k=kk; k<MIN(kk+block_size, b_row); k++) {
                        for (int j=jj; j<MIN(jj+block_size, b_col); j++) {
                            C[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }
            }
        }
    }
}

void multiplication_tiling_5_2(int block_size) {
    for (int kk=0; kk<b_row; kk+=block_size) {
        for (int ii=0; ii<a_row; ii+=block_size) {
            for (int jj=0; jj<b_col; jj+=block_size) {
                for (int i=ii; i<MIN(ii+block_size, a_row); i++) {
                    for (int k=kk; k<MIN(kk+block_size, b_row); k++) {
                        for (int j=jj; j<MIN(jj+block_size, b_col); j++) {
                            C[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }
            }
        }
    }
}

void multiplication_tiling_6_2(int block_size) {
    for (int kk=0; kk<b_row; kk+=block_size) {
        for (int jj=0; jj<b_col; jj+=block_size) {
            for (int ii=0; ii<a_row; ii+=block_size) {
                for (int i=ii; i<MIN(ii+block_size, a_row); i++) {
                    for (int k=kk; k<MIN(kk+block_size, b_row); k++) {
                        for (int j=jj; j<MIN(jj+block_size, b_col); j++) {
                            C[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }
            }
        }
    }
}
