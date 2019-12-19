#ifndef MATRICES_H
    #define MATRICES_H
    void generate_matrices(int size);
    void free_matrices(void);
    void clear_result(void);
    void print_result(void);
    void print_A(void);
    void print_B(void);
    float **A;
    float **B;
    float **C;
    int a_row;
    int b_col;
    int b_row;
#endif
