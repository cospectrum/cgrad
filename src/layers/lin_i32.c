#include "lin_i32.h"

void forward_lin_i32(struct lin_i32 l,
                     struct vec_i32 v,
                     struct vec_i32* result)
{
    matmul_vec_i32(l.weights, v, result);
    push_vec_i32(l.buffer, v);
}

