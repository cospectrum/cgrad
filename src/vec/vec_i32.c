#include "vec_i32.h"

void add_vec_i32(struct vec_i32 lhs, struct vec_i32 rhs, struct vec_i32* result)
{
	size_t len = lhs.len;
	for (size_t i = 0; i < len; ++i)
		result->values[i] = lhs.values[i] + rhs.values[i];
    result->len = len;
}

void sub_vec_i32(struct vec_i32 lhs, struct vec_i32 rhs, struct vec_i32* result)
{
	size_t len = lhs.len;
	for (size_t i = 0; i < len; ++i)
		result->values[i] = lhs.values[i] - rhs.values[i];
    result->len = len;
}

void mult_vec_i32(int32_t scalar, struct vec_i32 v, struct vec_i32* result)
{
	size_t len = v.len;
	for (size_t i = 0; i < len; ++i)
		result->values[i] = scalar*v.values[i];
    result->len = len;
}

int32_t dot_vec_i32(struct vec_i32 lhs, struct vec_i32 rhs)
{
	size_t len = lhs.len;
	int32_t result = 0;
	for (size_t i = 0; i < len; ++i)
		result += lhs.values[i]*rhs.values[i];
	return result;
}

short eq_vec_i32(struct vec_i32 lhs, struct vec_i32 rhs)
{
	if (lhs.len != rhs.len)
		return 0;

	size_t len = lhs.len;
    for (size_t i = 0; i < len; ++i) {
            if (lhs.values[i] != rhs.values[i])
                    return 0;
    }
    return 1;
}

void print_vec_i32(struct vec_i32 v, const char* end)
{
	size_t len = v.len;
	printf("[");
	for (size_t i = 0; i < len - 1; ++i)
		printf("%d, ", v.values[i]);
	printf("%d]%s", v.values[len - 1], end);
}
