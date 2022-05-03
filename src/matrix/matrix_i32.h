#ifndef MATRIX_I32_H
#define MATRIX_I32_H

#include "../vec/vec_i32.h"

struct matrix_i32 {
    struct vec_i32* rows;
    size_t shape[2];
};

void matmul_vec_i32(struct matrix_i32 m,
                    struct vec_i32 v,
                    struct vec_i32* result);

void print_matrix_i32(struct matrix_i32 m, const char* end);

#endif
