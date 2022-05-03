#include "test_matrix_i32.h"

void test_matrix_i32(void)
{
	const char* space = "-----------";
	printf("%s TEST: matrix_i32 %s\n", space, space);
	test_matmul_vec_i32();
}

void test_matmul_vec_i32(void)
{
    printf("START: test_matmul_vec_i32\n");
	int32_t values[] = {1, 2, 3};
	
    printf("init vec_i32 v\n");
    struct vec_i32 v = {
		.len = 3,
		.values = values,
	};
    
    printf("init rows\n");
	struct vec_i32 rows[] = {v, v, v};
	
    printf("init matrix_i32 m\n");
    struct matrix_i32 m = {
		.shape = {3, 3},
		.rows = rows,
	};

	// 1*1 + 2*2 + 3*3 == 1 + 4 + 9 == 14
	int32_t expect_values[] = {14, 14, 14};
	struct vec_i32 expect = {
		.len = 3,
		.values = expect_values,
	};

    int32_t actual_values[3];
	struct vec_i32 actual = {
        .values = actual_values,
    };

    printf("RUN: matmul_vec_i32(m, v, &actual)\n");
	matmul_vec_i32(m, v, &actual);

	if (!eq_vec_i32(expect, actual)) {
		printf("FAILED: matmul_vec_i32(m, v, &actual)\n");
		printf("m == ");
		print_matrix_i32(m, "\n");

		printf("v == ");
		print_vec_i32(v, "\n");

		printf("actual == ");
		print_vec_i32(actual, "\n");

		printf("expect == ");
		print_vec_i32(expect, "\n");

	} else {
        printf("SUCCESS\n");
    }

    printf("\n");
}
