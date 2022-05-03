#include "test_lin_i32.h"

void test_lin_i32(void)
{
    const char* space = "------------";
	printf("%s TEST: lin_i32 %s \n", space, space);

    test_forward_lin_i32();
}

void test_forward_lin_i32(void)
{
    printf("START: forward_lin_i32\n");

    int32_t values[] = {1, 1};
    struct vec_i32 w = {
        .len = 2,
        .values = values,
    };

    struct vec_i32 rows[] = {w, w};
    struct matrix_i32 weights = {
        .shape = {2, 2},
        .rows = rows,
    };

    size_t maxvlen = 2;
    size_t maxstacklen = 5;
    struct stack_vec_i32 buffer;
    
    printf("RUN: new_stack_vec_i32(%d, %d, &buffer)\n", 5, 2); 
    short status_code = new_stack_vec_i32(maxstacklen, maxvlen, &buffer);

    if (status_code != 0) {
        printf("FAILED: new_stack_vec_i32(max_stack_len, max_vec_len, &buffer)\n");
        printf("returned status_code: %d\n", status_code);
        return;
    }
    printf("done\n");

    struct lin_i32 layer = {
        .weights = weights,
        .buffer = &buffer,
    };

    int32_t input_values[] = {2, 2};
    struct vec_i32 input = {
        .len = 2,
        .values = input_values,
    };
 
    int32_t buff[2];
    struct vec_i32 output = {
        .values = buff,
    };
    printf("RUN: forward_lin_i32(layer, input, &output)\n");
    forward_lin_i32(layer, input, &output);
    printf("done\n");

    printf("input == ");
    print_vec_i32(input, "\n");

    printf("weights == ");
    print_matrix_i32(layer.weights, "\n");

    printf("output == ");
    print_vec_i32(output, "\n");

    struct vec_i32 tmp;
    tmp.values = malloc(weights.shape[0] * sizeof(int32_t));
    matmul_vec_i32(weights, input, &tmp);

    if (!eq_vec_i32(output, tmp)) {
        printf("FAILED: output != ");
        print_vec_i32(tmp, "\n");
    } else {
        printf("SUCCESS\n");
    }

    free_stack_vec_i32(buffer);
    free(tmp.values);
}

