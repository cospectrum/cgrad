#include "matrix_i32.h"

void matmul_vec_i32(struct matrix_i32 m, struct vec_i32 v, struct vec_i32* result)
{
	size_t dim0 = m.shape[0];
	for (size_t i = 0; i < dim0; ++i)
		result->values[i] = dot_vec_i32(m.rows[i], v);

	result->len = dim0;
}

void print_matrix_i32(struct matrix_i32 m, const char* end)
{
	size_t dim0 = m.shape[0];
	struct vec_i32 v;

	printf("[\n");
	for (size_t i = 0; i < dim0; ++i) {
		printf("\t");
		v = m.rows[i];
		print_vec_i32(v, ", \n");
	}
	printf("]%s", end);
}
