#ifndef STACK_VEC_I32_H
#define STACK_VEC_I32_H

#ifndef STRING_H
#define STRING_h
#include <string.h>
#endif

#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif

#include "../vec/vec_i32.h"

struct stack_vec_i32 {
    int32_t* values_array;
    size_t* len_array;
    size_t max_stack_len;
    size_t max_vec_len;
    size_t top;
};

short new_stack_vec_i32(size_t max_stack_len,
                        size_t max_vec_len,
                        struct stack_vec_i32* result);

void free_stack_vec_i32(struct stack_vec_i32 stack);

short push_vec_i32(struct stack_vec_i32* stack, struct vec_i32 v);
void pop_vec_i32(struct stack_vec_i32* stack, struct vec_i32* result);

#endif
