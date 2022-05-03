#ifndef LIN_I32_H
#define LIN_I32_H

#include "../matrix/matrix_i32.h"
#include "stack_vec_i32.h"

struct lin_i32 {
    struct matrix_i32 weights;
    struct stack_vec_i32* buffer;
};

void forward_lin_i32(struct lin_i32 l,
                     struct vec_i32 v,
                     struct vec_i32* result);

#endif
