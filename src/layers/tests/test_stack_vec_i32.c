#include "test_stack_vec_i32.h"

void test_stack_vec_i32(void)
{
    const char* space = "------------";
	printf("\n %s TEST: stack_vec_i32 %s \n", space, space);
    
    test_init_stack_vec_i32();
    test_push_vec_i32();
}

void test_push_vec_i32(void) {
    printf("START: push_vec_i32\n");
 
    size_t vlen = 2;
    size_t stack_len = 10;
    struct stack_vec_i32 stack;
    new_stack_vec_i32(stack_len, vlen, &stack);
    
    int32_t values[] = {1, 1};
    struct vec_i32 v = {
        .len = vlen,
        .values = values,
    };

    int tries = 2;
    for (int i = 0; i < tries; ++i) {
        printf("push v\n");
        push_vec_i32(&stack, v);
    }

    int32_t buff[2];
    struct vec_i32 w;
    w.values = buff;

    for (int i = 0; i < tries; ++i) {
        printf("pop\n");
        pop_vec_i32(&stack, &w);
        if (!eq_vec_i32(w, v)) {
            printf("FAILED: push != pop\n");
            return;
        }
    }
    free_stack_vec_i32(stack);
    printf("SUCCESS\n\n");
}

void test_init_stack_vec_i32(void)
{
    printf("START: init_stack_vec_i32\n");
    size_t max_vec_len = 20;
    size_t max_stack_len = 100;
    struct stack_vec_i32 stack;
    
    short status_code;
    printf("RUN: new_stack_vec_i32(%d, %d, &stack)\n", max_stack_len, max_vec_len);
    status_code = new_stack_vec_i32(max_stack_len, max_vec_len, &stack);

    if (status_code != 0) {
        printf("FAILED: new_stack_vec_i32(max_stack_len, max_vec_len, &stack)\n");
        printf("max_stack_len == %d, max_vec_len == %d\n", max_stack_len, max_vec_len);
        printf("returned status_code: %d\n", status_code);
        return;
    }
    printf("done\n");

    printf("RUN: free_stack_vec_i32(stack)\n");
    free_stack_vec_i32(stack);
    printf("SUCCESS\n\n");
    return;
}

