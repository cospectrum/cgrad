#ifndef STDDEF_H
#define STDDEF_H
#include <stddef.h>
#endif

#ifndef STDINT_H
#define STDINT_H
#include <stdint.h>
#endif

#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

#ifndef VEC_I32_H
#define VEC_I32_H

struct vec_i32 {
	int32_t* values;
	size_t len;
};

void add_vec_i32(struct vec_i32 lhs, struct vec_i32 rhs, struct vec_i32* result);
void sub_vec_i32(struct vec_i32 lhs, struct vec_i32 rhs, struct vec_i32* result);
void mult_vec_i32(int32_t scalar, struct vec_i32 v, struct vec_i32* result);
int32_t dot_vec_i32(struct vec_i32 lhs, struct vec_i32 rhs);

short eq_vec_i32(struct vec_i32 lhs, struct vec_i32 rhs);
void print_vec_i32(struct vec_i32 v, const char* end);

#endif
