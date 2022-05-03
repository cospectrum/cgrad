#include "test_vec_i32.h"


void test_vec_i32(void)
{
	const char* space = "------------";
	printf("%s TEST: vec_i32 %s \n", space, space);
	test_add_vec_i32();
}

void test_add_vec_i32(void)
{
    printf("START: add_vec_i32\n");
	const size_t len = 3;

	int32_t lv[3] = {1, 2, 3};
	struct vec_i32 lhs = {
		.values = lv,
		.len = 3,
	};

	int32_t rv[3] = {-2, -4, -6};
	struct vec_i32 rhs = {
		.len = 3,
		.values = rv,
	};

	int32_t expect_values[3] = {-1, -2, -3};
	struct vec_i32 expect = {
		.len = 3,
		.values = expect_values,
	};

	int32_t actual_values[3];
	struct vec_i32 actual = {
		.values = actual_values,
	};

    printf("RUN: add_vec_i32(lhs, rhs, &actual)\n");
	add_vec_i32(lhs, rhs, &actual);

	if (!eq_vec_i32(expect, actual)) {
		printf("FAILED: add_vec_i32(lhs, rhs, &actual)\n");

        printf("lhs == ");
        print_vec_i32(lhs, "\n");

        printf("rhs == ");
        print_vec_i32(rhs, "\n");

		printf("\t expect == ");
		print_vec_i32(expect, "\n");

		printf("\t actual == ");
		print_vec_i32(actual, "\n");

	} else {
        printf("SUCCESS\n");
    }

    printf("\n");
}
