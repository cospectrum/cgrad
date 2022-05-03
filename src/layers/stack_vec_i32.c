#include "stack_vec_i32.h"

short push_vec_i32(struct stack_vec_i32* stack, struct vec_i32 v)
{
    /// Make a deep copy of the vector and put it on the stack
    
    size_t top = stack->top;
    if (top >= stack->max_stack_len)
        return -1;

    size_t size = v.len * sizeof(int32_t); 
    int32_t* dest = top + stack->values_array; 
    memcpy(dest, v.values, size);
 
    stack->len_array[top] = v.len;
    stack->top += 1;
    return 0;
}

void pop_vec_i32(struct stack_vec_i32* stack, struct vec_i32* result)
{
    /// Make a deep copy of vector from the top of the stack

    stack->top -= 1;
    size_t top = stack->top;
    size_t len = stack->len_array[top];
    size_t size = len * sizeof(int32_t);
 
    int32_t* src = top + stack->values_array;
    memcpy(result->values, src, size); 

    result->len = len;
}

short new_stack_vec_i32(size_t max_stack_len,
                        size_t max_vec_len,
                        struct stack_vec_i32* result) 
{
    size_t size = max_stack_len * sizeof(size_t);
    
    size_t* len_array = malloc(size);
    if (len_array == NULL)
        return -1;

    int32_t* values_array = malloc(max_vec_len * size);
    if (values_array == NULL) {
        free(len_array);
        return -2;
    }

    result->values_array = values_array;
    result->len_array = len_array;
    result->max_stack_len = max_stack_len;
    result->max_vec_len = max_vec_len;
    result->top = 0;
    return 0;
}

void free_stack_vec_i32(struct stack_vec_i32 stack)
{
    free(stack.values_array);
    free(stack.len_array);
}

